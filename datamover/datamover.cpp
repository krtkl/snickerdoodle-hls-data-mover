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
 * @version 2018-08-29T16:21:47Z
 */

#include "datamover.h"

/* data flow subfunction implementing AXI port read bursts */
void read_burst (const axi_t tx_buffer[BUFFER_WORDS],
				 const ap_uint<LOOP_ITERATOR_BITS> n,
				 const ap_uint<LOOP_TRIP_COUNT_BITS> loop_count,
				 const ap_uint<CACHE_LENGTH_BITS> final_burst_length,
				 axi_t cache[CACHE_WORDS],
				 ap_uint<CACHE_LENGTH_BITS> &data_length)
{
  ap_uint<BUFFER_WORD_ADDRESS_BITS> buffer_offset = n;
  buffer_offset = buffer_offset * CACHE_WORDS;
  memcpy(cache, &tx_buffer[buffer_offset], CACHE_SIZE); /* burst read a block of data into the transmit cache */
  if (n==loop_count-1) data_length = final_burst_length;
  else data_length = CACHE_LENGTH;
}


/* data flow subfunction implementing AXIS port transmission */
void tx_axis_words (const axi_t cache[CACHE_WORDS],
			   const ap_uint<CACHE_LENGTH_BITS> data_length,
			   hls::stream<axis_t> &axis)
{
  for (int i=0;i<data_length;i++)
   {
#pragma HLS LOOP_TRIPCOUNT max=CACHE_LENGTH
#pragma HLS PIPELINE II=1
	 axi_t axi_word;
	 axis_t axis_word;

	 axi_word = cache[i*AXIS_WORD_SIZE/AXI_WORD_SIZE];
	 axis_word = (axis_t)(axi_word >>((i%(AXIS_WORDS_PER_AXI_WORD))*(BITS_PER_BYTE*AXIS_WORD_SIZE)));
	 axis << axis_word; /* transmit AXIS word */
   }
}


/* function containing main data flow loop for transmit */
bool tx_loop (hls::stream<axis_t> &axis,
			  const axi_t tx_buffer[BUFFER_WORDS],
			  const ap_uint<LOOP_TRIP_COUNT_BITS> loop_count,
			  const ap_uint<CACHE_LENGTH_BITS> final_burst_length)
{
  for (int n=0;n<loop_count;n++)
   {
#pragma HLS LOOP_TRIPCOUNT max=LOOP_MAX_TRIP_COUNT
#pragma HLS DATAFLOW
	 axi_t cache[CACHE_WORDS]; /* AXI read burst buffer for transmit */
	 ap_uint<CACHE_LENGTH_BITS> data_length; /* length of axis transmit burst */

	 read_burst (tx_buffer, n, loop_count, final_burst_length, cache, data_length);
     tx_axis_words (cache, data_length, axis);
   }
  return true;
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

  /* loop through every AXI word in cache, any words not used in the block are zeroed */
  for (int i=0; i<CACHE_WORDS; i++)
   {
#pragma HLS PIPELINE II=AXIS_WORDS_PER_AXI_WORD
	 axi_t axi_word = 0; /* zero the axi word */

	 if (data_length)
	  for (int j=0; j<AXIS_WORDS_PER_AXI_WORD; j++)
	   {
		 axis_t axis_word = 0; /* zero the axis word */
		 if (data_length)
          {
	     	axis >> axis_word; /* receive AXIS word */
	     	data_length--; /*  one less word to suck in */
	      }
		 axi_word |= ((axi_t)axis_word) << ((j%AXIS_WORDS_PER_AXI_WORD)*BITS_PER_BYTE*AXIS_WORD_SIZE);
	   }

	 cache[i] = axi_word; /* load AXIS word to cache */
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
bool rx_loop (hls::stream<axis_t> &axis,
			  const ap_uint<LOOP_TRIP_COUNT_BITS> loop_count,
			  const ap_uint<CACHE_LENGTH_BITS> final_burst_length,
			  axi_t rx_buffer[BUFFER_WORDS])
{
  for (int n=0;n<loop_count;n++)
   {
#pragma HLS LOOP_TRIPCOUNT max=LOOP_MAX_TRIP_COUNT
#pragma HLS DATAFLOW
	 axi_t cache[CACHE_WORDS]; /* AXI write burst buffer for receive */
	 ap_uint<BUFFER_WORD_ADDRESS_BITS> buffer_offset; /* word offset into AXI buffer to write cache out to */

	 rx_axis_words (axis, loop_count, final_burst_length, n, cache, buffer_offset);
	 write_burst (cache, buffer_offset, rx_buffer);
   }
  return true;
}


/* given the data length calculates the number of cache block size loop iterations needed and the length of the data in the last cache block */
void get_loop_parameters (const ap_uint<BUFFER_LENGTH_BITS> data_length,
		  	 	 	 	  ap_uint<LOOP_TRIP_COUNT_BITS> &loop_count,
						  ap_uint<CACHE_LENGTH_BITS> &final_burst_length)
{
  if (data_length % CACHE_LENGTH)
   {
	 final_burst_length = data_length % CACHE_LENGTH;
	 loop_count = data_length/CACHE_LENGTH + 1;
   }
  else
   {
	 final_burst_length = CACHE_LENGTH;
	 loop_count = data_length/CACHE_LENGTH;
   }
}


/* main body of the data mover implementation */
void data_mover_16b64b (hls::stream<axis_t> &data_rx, /* AXIS slave interface */
				 	   hls::stream<axis_t> &data_tx, /* AXIS master interface */
					   const axi_t tx_buffer[BUFFER_COUNT][BUFFER_WORDS], /* AXI memory mapped DDR buffer to read data to transmit from */
					   const ap_uint<BUFFER_LENGTH_BITS> *tx_buffer_length, /* number of AXIS words to read from the tx buffer */
					   axi_t rx_buffer[BUFFER_COUNT][BUFFER_WORDS], /* AXI memory mapped DDR buffer to write received data to */
					   const ap_uint<BUFFER_LENGTH_BITS> *rx_buffer_length, /* number of AXIS words to write to the rx buffer */
					   ap_uint<BUFFER_COUNT_BITS> *last_buffer, /* returns buffer number last used */
					   const ap_uint<BITS_PER_BOOL> *increment_buffer) /* if set target buffer is post-incremented, if clear buffer 0 always used */
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

#pragma HLS INTERFACE s_axilite port=last_buffer bundle=control
#pragma HLS INTERFACE s_axilite port=increment_buffer bundle=control

  /* persistent state variables */
  static ap_uint<BUFFER_COUNT_BITS> current_buffer = 0; /* buffer number to use */
#pragma HLS RESET variable=current_buffer

  /* local variables */
  ap_uint<LOOP_TRIP_COUNT_BITS> tx_loop_count; /* iterator for tx loop data flow process */
  ap_uint<CACHE_LENGTH_BITS> tx_final_burst_length; /* length of the final block of tx data loaded into the cache */
  ap_uint<LOOP_TRIP_COUNT_BITS> rx_loop_count; /* iterator for rx loop data flow process */
  ap_uint<CACHE_LENGTH_BITS> rx_final_burst_length; /* length of the final block of rx data loaded into the cache */
  bool tx_done = false;
  bool rx_done = false;

  if (BOOL_FALSE == *increment_buffer) current_buffer = 0; /* if buffer is not set to increment then always use first buffer */

  /* setup tx and rx loop parameters */
  get_loop_parameters (*tx_buffer_length, tx_loop_count, tx_final_burst_length);
  get_loop_parameters (*rx_buffer_length, rx_loop_count, rx_final_burst_length);

  /* Transmit Section */
  tx_done = tx_loop (data_tx, tx_buffer[current_buffer], tx_loop_count, tx_final_burst_length);

  /* Receive Section */
  rx_done = rx_loop (data_rx, rx_loop_count, rx_final_burst_length, rx_buffer[current_buffer]);

  if (tx_done && rx_done) /* this condition blocks writes to the last_buffer until the transfers are complete */
   {
     *last_buffer = current_buffer; /* return the buffer just used for transmit and receive */
     if (BOOL_TRUE == *increment_buffer) current_buffer++; /* increment buffer to use (rolls over to zero) */
   }
}
