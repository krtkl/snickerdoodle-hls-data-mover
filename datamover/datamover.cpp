/*
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 2018, krtkl inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @description AXIS data mover
 * @author Jamil J. Weatherbee
 * @version 2018-06-09T17:51:33Z
 */

#include "datamover.h"

volatile bool stop; /* global stop flag for early exit from blocking transfers - not yet implemented */

/* data flow subfunction implementing AXI port read bursts */
void read_burst (const uint64_t *buffer,
				 const ap_uint<16> n,
				 const ap_uint<17> loop_count,
				 const ap_uint<13> final_burst_length,
				 uint64_t cache[CACHE_WORDS],
				 ap_uint<13> &data_length)
{
  ap_uint<25> buffer_offset	= n;
  buffer_offset = buffer_offset * CACHE_WORDS;
  memcpy(cache, buffer+buffer_offset, CACHE_SIZE); /* burst read a block of data into the transmit cache */
  if (n==loop_count-1) data_length = final_burst_length;
  else data_length = CACHE_SIZE;
}


/* data flow subfunction implementing AXIS port transmission */
void tx_bytes (const uint64_t cache[CACHE_WORDS],
			   const ap_uint<13> data_length,
			   hls::stream<axis_t> &axis)
{
  for (int n=0;n<data_length;n++)
   {
#pragma HLS LOOP_TRIPCOUNT max=4096
#pragma HLS PIPELINE II=1
	 uint8_t data;
	 data = (uint8_t)(cache[n/WORD_SIZE] >> (BITS_PER_BYTE*(n%WORD_SIZE))); /* get data byte from cache */
	 axis << data; /* transmit AXIS byte */
   }
}


/* function containing main data flow loop for transmit */
void tx_loop (hls::stream<axis_t> &axis,
			  const uint64_t *buffer,
			  const ap_uint<17> loop_count,
			  const ap_uint<13> final_burst_length)
{
  for (int n=0;n<loop_count;n++)
   {
#pragma HLS LOOP_TRIPCOUNT max=65536
#pragma HLS DATAFLOW
	 uint64_t cache[CACHE_WORDS]; /* AXI read burst buffer for transmit */
	 ap_uint<13> data_length; /* length of axis transmit burst */

	 read_burst (buffer, n, loop_count, final_burst_length, cache, data_length);
     tx_bytes (cache, data_length, axis);
   }
}


/* data flow subfunction implementing AXIS port reception */
void rx_axis_words (hls::stream<axis_t> &axis,
			   const ap_uint<LOOP_TRIP_COUNT_BITS> loop_count,
			   const ap_uint<CACHE_LENGTH_BITS> final_burst_length,
			   const ap_uint<LOOP_ITERATOR_BITS> n,
			   axi_t cache[CACHE_WORDS],
			   ap_uint<BUFFER_WORD_ADDRESS_BITS> &buffer_offset)
{
  ap_uint<CACHE_LENGTH_BITS> data_length; /* how many AXIS words to suck in from the AXIS port and transfer to the cache */

  if (n==loop_count-1) data_length = final_burst_length;
  else data_length = CACHE_LENGTH;

  /* loop through every AXIS word in cache, any bytes not used in the block are zeroed */
  for (int i=0; i<CACHE_LENGTH; i++)
   {
#pragma HLS PIPELINE II
	 axis_t data = 0; /* zero word working register to load up with value from AXIS */
     if (data_length)
      {
    	axis >> data; /* receive AXIS byte */
    	data_length--; /*  one less word to suck in */
      }
     ((axis_t *)cache)[i] = data; /* load word to cache */
   }

  buffer_offset = (ap_uint<BUFFER_WORD_ADDRESS_BITS>)n*CACHE_WORDS; /* calculate buffer offset for write burst */
}


/* data flow subfunction implementing AXI port write bursts */
void write_burst (const axi_t cache[CACHE_WORDS],
				  const ap_uint<BUFFER_WORD_ADDRESS_BITS> buffer_offset,
				  axi_t rx_buffer[BUFFER_WORDS])
{
  memcpy(&rx_buffer[buffer_offset], cache, CACHE_SIZE); /* burst write a block of data from the receive cache */
}


/* function containing main data flow loop for receive */
void rx_loop (hls::stream<axis_t> &axis,
			  const ap_uint<LOOP_TRIP_COUNT_BITS> loop_count,
			  const ap_uint<CACHE_LENGTH_BITS> final_burst_length,
			  axi_t rx_buffer[BUFFER_WORDS])
{
  for (int n=0;n<loop_count;n++)
   {
#pragma HLS DATAFLOW
	 axi_t cache[CACHE_WORDS]; /* AXI write burst buffer for receive */
	 ap_uint<BUFFER_WORD_ADDRESS_BITS> buffer_offset; /* word offset into AXI buffer to write cache out to */

	 rx_axis_words (axis, loop_count, final_burst_length, n, cache, buffer_offset);
	 write_burst (cache, buffer_offset, rx_buffer);
   }
}


/* given the data length calculates the number of cache block size loop iterations needed and the length of the data in the last cache block */
void get_loop_parameters (const ap_uint<CACHE_LENGTH_BITS> data_length,
		  	 	 	 	  ap_uint<LOOP_TRIP_COUNT_BITS> &loop_count,
						  ap_uint<CACHE_LENGTH_BITS> &final_burst_length)
{
  if (data_length % CACHE_SIZE)
   {
	 final_burst_length = data_length % CACHE_SIZE;
	 loop_count = data_length/CACHE_SIZE + 1;
   }
  else
   {
	 final_burst_length = CACHE_SIZE;
	 loop_count = data_length/CACHE_SIZE;
   }
}


/* main body of the data mover implementation */
void data_mover (hls::stream<axis_t> &data_rx, /* AXIS slave interface */
				 hls::stream<axis_t> &data_tx, /* AXIS master interface */
				 const axi_t tx_buffer[BUFFER_WORDS], /* AXI memory mapped DDR buffer to read data to transmit from */
				 const ap_uint<BUFFER_LENGTH_BITS> *tx_buffer_length, /* number of AXIS words to read from the tx buffer */
				 axi_t rx_buffer[BUFFER_WORDS], /* AXI memory mapped DDR buffer to write received data to */
				 const ap_uint<BUFFER_LENGTH_BITS> *rx_buffer_length) /* number of AXIS words to write to the rx buffer */
{
#pragma HLS INTERFACE s_axilite port=return bundle=control
#pragma HLS INTERFACE axis register both port=data_rx
#pragma HLS INTERFACE axis register both port=data_tx

#pragma HLS INTERFACE m_axi port=tx_buffer offset=slave bundle=DMA
#pragma HLS INTERFACE s_axilite port=tx_buffer bundle=control
#pragma HLS INTERFACE s_axilite port=tx_buffer_length bundle=control

#pragma HLS INTERFACE m_axi port=rx_buffer offset=slave bundle=DMA
#pragma HLS INTERFACE s_axilite port=rx_buffer bundle=control
#pragma HLS INTERFACE s_axilite port=rx_buffer_length bundle=control

  /* local variables */
  ap_uint<LOOP_TRIP_COUNT_BITS> tx_loop_count; /* iterator for tx loop data flow process */
  ap_uint<CACHE_LENGTH_BITS> tx_final_burst_length; /* length of the final block of tx data loaded into the cache */
  ap_uint<LOOP_TRIP_COUNT_BITS> rx_loop_count; /* iterator for rx loop data flow process */
  ap_uint<CACHE_LENGTH_BITS> rx_final_burst_length; /* length of the final block of rx data loaded into the cache */

  /* setup tx and rx loop parameters */
  get_loop_parameters (*tx_buffer_length, tx_loop_count, tx_final_burst_length);
  get_loop_parameters (*rx_buffer_length, rx_loop_count, rx_final_burst_length);

  /* Transmit Section */
  tx_loop (data_tx, tx_buffer, tx_loop_count, tx_final_burst_length);

  /* Receive Section */
  rx_loop (data_rx, rx_loop_count, rx_final_burst_length, rx_buffer);
}
