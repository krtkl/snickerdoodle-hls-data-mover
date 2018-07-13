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
 * @description AXIS data mover header file
 * @author Jamil J. Weatherbee
<<<<<<< HEAD
 * @version 2018-06-11T18:42:45Z
=======
 * @version 2018-06-17T04:26:31Z
>>>>>>> master
 */

/* include data types needed */
#include <stdint.h>
#include <string.h>
#include <ap_int.h>
#include <hls_stream.h>

/* constant definitions */
const int BITS_PER_BYTE = 8; /* bits per byte */
const int BITS_PER_BOOL = 1;
const int BOOL_FALSE = 0;
const int BOOL_TRUE = 1;

const int BUFFER_COUNT_BITS = 1; /* number of bits needed to enumerate a read or write buffer */
const int BUFFER_COUNT = (1<<BUFFER_COUNT_BITS); /* number of transmit and receive buffer pairs (2) */

const int AXI_WORD_LOG2_BYTES = 3; /* AXI ACP port word size expressed as a power of 2 */
const int AXI_WORD_SIZE = (1<<AXI_WORD_LOG2_BYTES); /* AXI ACP port word size in bytes (8) */
const int AXI_WORD_BITS = AXI_WORD_SIZE*BITS_PER_BYTE; /* AXI ACP port word size in bits (64) */

const int AXIS_WORD_LOG2_BYTES = 0; /* AXIS ports word size expressed as a power of 2 */
const int AXIS_WORD_SIZE = (1<<AXIS_WORD_LOG2_BYTES); /* AXIS ports word size in bytes (1) */
const int AXIS_WORD_BITS = AXIS_WORD_SIZE*BITS_PER_BYTE; /* AXIS word size in bits (8) */

const int AXIS_WORDS_PER_AXI_WORD = AXI_WORD_SIZE/AXIS_WORD_SIZE; /* number of AXIS words in each AXI word (8) */

const int CACHE_WORD_ADDRESS_BITS = 9; /* AXI word address bits for cache buffer */
const int CACHE_WORDS = (1<<CACHE_WORD_ADDRESS_BITS); /* AXI words in cache buffer (512) */
const int CACHE_SIZE = CACHE_WORDS*AXI_WORD_SIZE; /* size of cache buffer in bytes (4096) */

const int BUFFER_WORD_ADDRESS_BITS = 20; /* AXI word address bits for read and write buffers */
const int BUFFER_WORDS = (1<<BUFFER_WORD_ADDRESS_BITS); /* AXI words in read and write buffers (1048576) */
const int BUFFER_SIZE = BUFFER_WORDS*AXI_WORD_SIZE; /* size of read and write buffers in bytes (8388608) */

const int LOOP_ITERATOR_BITS = BUFFER_WORD_ADDRESS_BITS-CACHE_WORD_ADDRESS_BITS; /* main read and write loop iterator bits (11) */
const int LOOP_MAX_TRIP_COUNT = (1<<LOOP_ITERATOR_BITS); /* maximum number of main read and write loop iterations (2048) */
const int LOOP_TRIP_COUNT_BITS = LOOP_ITERATOR_BITS+1; /* main read and write loop trip count bits (12) */
const int CACHE_LENGTH_BITS = CACHE_WORD_ADDRESS_BITS+AXI_WORD_LOG2_BYTES-AXIS_WORD_LOG2_BYTES+1; /* bits needed to size a cache read/write in AXIS words (13) */
const int CACHE_LENGTH = CACHE_SIZE/AXIS_WORD_SIZE; /* AXIS words in cache buffer (4096) */
const int BUFFER_LENGTH_BITS = BUFFER_WORD_ADDRESS_BITS+AXI_WORD_LOG2_BYTES-AXIS_WORD_LOG2_BYTES+1; /* bits needed to size a buffer in AXIS words (24) */

/* type definitions */
typedef ap_uint<AXI_WORD_BITS> axi_t;
typedef ap_uint<AXIS_WORD_BITS> axis_t;

/* function declarations */
<<<<<<< HEAD
void data_mover_8b64b (hls::stream<axis_t> &data_rx, /* AXIS slave interface */
				       hls::stream<axis_t> &data_tx, /* AXIS master interface */
				       const axi_t tx_buffer[BUFFER_WORDS], /* AXI memory mapped DDR buffer to read data to transmit from */
				       const ap_uint<BUFFER_LENGTH_BITS> *tx_buffer_length, /* number of AXIS words to read from the tx buffer */
				       axi_t rx_buffer[BUFFER_WORDS], /* AXI memory mapped DDR buffer to write received data to */
				       const ap_uint<BUFFER_LENGTH_BITS> *rx_buffer_length); /* number of AXIS words to write to the rx buffer */
=======
void data_mover (hls::stream<axis_t> &data_rx, /* AXIS slave interface */
				 hls::stream<axis_t> &data_tx, /* AXIS master interface */
				 const axi_t tx_buffer[BUFFER_COUNT][BUFFER_WORDS], /* AXI memory mapped DDR buffer to read data to transmit from */
				 const ap_uint<BUFFER_LENGTH_BITS> *tx_buffer_length, /* number of AXIS words to read from the tx buffer */
				 axi_t rx_buffer[BUFFER_COUNT][BUFFER_WORDS], /* AXI memory mapped DDR buffer to write received data to */
				 const ap_uint<BUFFER_LENGTH_BITS> *rx_buffer_length, /* number of AXIS words to write to the rx buffer */
				 ap_uint<BUFFER_COUNT_BITS> *last_buffer, /* returns buffer number last used */
				 const ap_uint<BITS_PER_BOOL> *increment_buffer); /* if set target buffer is post-incremented, if clear buffer 0 always used */
>>>>>>> master
