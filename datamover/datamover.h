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
 * @version 2018-06-09T17:51:33Z
 */

/* include data types needed */
#include <stdint.h>
#include <string.h>
#include <ap_int.h>
#include <hls_stream.h>

/* constant definitions */
const int BITS_PER_BYTE = 8; /* 8-bits per byte */
const int WORD_SIZE = sizeof(uint64_t); /* AXI ACP port word size is 64-bits = 8 bytes */
const int CACHE_WORDS = 512; /* cache blocks of 4 kilobytes when reading and writing AXI ACP port */
const int CACHE_SIZE = CACHE_WORDS*WORD_SIZE; /* size of cache buffer in bytes */
const int MAX_BUFFER_SIZE = 268435455; /* maximum size of read and write buffers */

/* global variables */
extern volatile bool stop; /* global stop flag for early exit from blocking transfers - not yet implemented */

/* type definitions */
typedef uint8_t axis_t;

/* function declarations */
void data_mover (hls::stream<axis_t> &data_rx, /* 8-bit wide AXIS slave interface */
				 hls::stream<axis_t> &data_tx, /* 8-bit wide AXIS master interface */
				 const uint64_t *tx_buffer, /* DDR buffer to read data to transmit from */
				 const ap_uint<28> *tx_buffer_size, /* number of bytes in the tx buffer */
				 ap_uint<28> *tx_byte_count, /* number of bytes received */
				 uint64_t *rx_buffer, /* DDR buffer to write received data to */
				 const ap_uint<28> *rx_buffer_size, /* byte capacity of the rx buffer */
				 ap_uint<28> *rx_byte_count); /* number of bytes received */
