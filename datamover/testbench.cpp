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
 * @description AXIS data mover test bench
 * @author Jamil J. Weatherbee
 * @version 2018-06-11T21:40:26Z
 */

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "datamover.h"

/* constant definitions */
const uint32_t TX_PRBS_STATE = 0x15EC38A2;
const int TX_TRANSFER_LENGTH = 1048575;

const uint32_t RX_PRBS_STATE = 0x970AC5FD;
const int RX_TRANSFER_LENGTH = 1048577;

/* 32-bit CRC lookup table using polynomial x^32+x^26+x^23+x^22+x^16+x^12+x^11+x^10+x^8+x^7+x^5+x^4+x^2+x+1 */
static const int CRC_DATA_WORD_BITS = 8;
static const int CRC_TABLE_SIZE =(1<<CRC_DATA_WORD_BITS);
static const uint32_t crc32_table[CRC_TABLE_SIZE]=
{ 0x00000000,0x77073096,0xEE0E612C,0x990951BA,0x076DC419,0x706AF48F,0xE963A535,0x9E6495A3,0x0EDB8832,0x79DCB8A4,0xE0D5E91E,0x97D2D988,0x09B64C2B,0x7EB17CBD,0xE7B82D07,0x90BF1D91,
  0x1DB71064,0x6AB020F2,0xF3B97148,0x84BE41DE,0x1ADAD47D,0x6DDDE4EB,0xF4D4B551,0x83D385C7,0x136C9856,0x646BA8C0,0xFD62F97A,0x8A65C9EC,0x14015C4F,0x63066CD9,0xFA0F3D63,0x8D080DF5,
  0x3B6E20C8,0x4C69105E,0xD56041E4,0xA2677172,0x3C03E4D1,0x4B04D447,0xD20D85FD,0xA50AB56B,0x35B5A8FA,0x42B2986C,0xDBBBC9D6,0xACBCF940,0x32D86CE3,0x45DF5C75,0xDCD60DCF,0xABD13D59,
  0x26D930AC,0x51DE003A,0xC8D75180,0xBFD06116,0x21B4F4B5,0x56B3C423,0xCFBA9599,0xB8BDA50F,0x2802B89E,0x5F058808,0xC60CD9B2,0xB10BE924,0x2F6F7C87,0x58684C11,0xC1611DAB,0xB6662D3D,
  0x76DC4190,0x01DB7106,0x98D220BC,0xEFD5102A,0x71B18589,0x06B6B51F,0x9FBFE4A5,0xE8B8D433,0x7807C9A2,0x0F00F934,0x9609A88E,0xE10E9818,0x7F6A0DBB,0x086D3D2D,0x91646C97,0xE6635C01,
  0x6B6B51F4,0x1C6C6162,0x856530D8,0xF262004E,0x6C0695ED,0x1B01A57B,0x8208F4C1,0xF50FC457,0x65B0D9C6,0x12B7E950,0x8BBEB8EA,0xFCB9887C,0x62DD1DDF,0x15DA2D49,0x8CD37CF3,0xFBD44C65,
  0x4DB26158,0x3AB551CE,0xA3BC0074,0xD4BB30E2,0x4ADFA541,0x3DD895D7,0xA4D1C46D,0xD3D6F4FB,0x4369E96A,0x346ED9FC,0xAD678846,0xDA60B8D0,0x44042D73,0x33031DE5,0xAA0A4C5F,0xDD0D7CC9,
  0x5005713C,0x270241AA,0xBE0B1010,0xC90C2086,0x5768B525,0x206F85B3,0xB966D409,0xCE61E49F,0x5EDEF90E,0x29D9C998,0xB0D09822,0xC7D7A8B4,0x59B33D17,0x2EB40D81,0xB7BD5C3B,0xC0BA6CAD,
  0xEDB88320,0x9ABFB3B6,0x03B6E20C,0x74B1D29A,0xEAD54739,0x9DD277AF,0x04DB2615,0x73DC1683,0xE3630B12,0x94643B84,0x0D6D6A3E,0x7A6A5AA8,0xE40ECF0B,0x9309FF9D,0x0A00AE27,0x7D079EB1,
  0xF00F9344,0x8708A3D2,0x1E01F268,0x6906C2FE,0xF762575D,0x806567CB,0x196C3671,0x6E6B06E7,0xFED41B76,0x89D32BE0,0x10DA7A5A,0x67DD4ACC,0xF9B9DF6F,0x8EBEEFF9,0x17B7BE43,0x60B08ED5,
  0xD6D6A3E8,0xA1D1937E,0x38D8C2C4,0x4FDFF252,0xD1BB67F1,0xA6BC5767,0x3FB506DD,0x48B2364B,0xD80D2BDA,0xAF0A1B4C,0x36034AF6,0x41047A60,0xDF60EFC3,0xA867DF55,0x316E8EEF,0x4669BE79,
  0xCB61B38C,0xBC66831A,0x256FD2A0,0x5268E236,0xCC0C7795,0xBB0B4703,0x220216B9,0x5505262F,0xC5BA3BBE,0xB2BD0B28,0x2BB45A92,0x5CB36A04,0xC2D7FFA7,0xB5D0CF31,0x2CD99E8B,0x5BDEAE1D,
  0x9B64C2B0,0xEC63F226,0x756AA39C,0x026D930A,0x9C0906A9,0xEB0E363F,0x72076785,0x05005713,0x95BF4A82,0xE2B87A14,0x7BB12BAE,0x0CB61B38,0x92D28E9B,0xE5D5BE0D,0x7CDCEFB7,0x0BDBDF21,
  0x86D3D2D4,0xF1D4E242,0x68DDB3F8,0x1FDA836E,0x81BE16CD,0xF6B9265B,0x6FB077E1,0x18B74777,0x88085AE6,0xFF0F6A70,0x66063BCA,0x11010B5C,0x8F659EFF,0xF862AE69,0x616BFFD3,0x166CCF45,
  0xA00AE278,0xD70DD2EE,0x4E048354,0x3903B3C2,0xA7672661,0xD06016F7,0x4969474D,0x3E6E77DB,0xAED16A4A,0xD9D65ADC,0x40DF0B66,0x37D83BF0,0xA9BCAE53,0xDEBB9EC5,0x47B2CF7F,0x30B5FFE9,
  0xBDBDF21C,0xCABAC28A,0x53B39330,0x24B4A3A6,0xBAD03605,0xCDD70693,0x54DE5729,0x23D967BF,0xB3667A2E,0xC4614AB8,0x5D681B02,0x2A6F2B94,0xB40BBE37,0xC30C8EA1,0x5A05DF1B,0x2D02EF8D
};


/* get the next pseudo-random byte */
uint8_t get_PRBS_byte (uint32_t &PRBS_state)
{
  uint8_t b=0x00;

  for (int n=0;n<BITS_PER_BYTE;n++)
   {
	 b<<=1;
	 if (PRBS_state & 0x1)
	  {
		PRBS_state=(PRBS_state>>1)^0xA3000000;
		b |= 0x1;
	  }
	 else PRBS_state>>=1;
   }

  return b;
}


int main (void)
{
  hls::stream<axis_t> data_rx("data_rx");
  hls::stream<axis_t> data_tx("data_tx");
  ap_uint<BUFFER_LENGTH_BITS> tx_buffer_length;
  ap_uint<BUFFER_LENGTH_BITS> rx_buffer_length;
  uint32_t PRBS_state;
  int errors=0;

  uint32_t tx_buffer_crc;
  uint32_t rx_stream_crc;
  uint32_t crc;
  void *RAM;
  axi_t *tx_buffer;
  axi_t *rx_buffer;

  std::cout << "Test Parameters:" << std::endl;

  std::cout << "TX_PRBS_STATE=0x" << std::hex << std::uppercase << std::noshowbase << std::internal << std::setfill('0') << std::setw(8) << TX_PRBS_STATE << std::endl;
  std::cout << "TX_TRANSFER_LENGTH=" << std::dec << TX_TRANSFER_LENGTH << std::endl;

  std::cout << "RX_PRBS_STATE=0x" << std::hex << std::uppercase << std::noshowbase << std::internal << std::setfill('0') << std::setw(8) << RX_PRBS_STATE << std::endl;
  std::cout << "RX_TRANSFER_LENGTH=" << std::dec << RX_TRANSFER_LENGTH << std::endl;

  std::cout << "AXI_WORD_LOG2_BYTES=" << std::dec << AXI_WORD_LOG2_BYTES << std::endl;
  std::cout << "AXI_WORD_SIZE=" << std::dec << AXI_WORD_SIZE << std::endl;
  std::cout << "AXI_WORD_BITS=" << std::dec << AXI_WORD_BITS << std::endl;

  std::cout << "AXIS_WORD_LOG2_BYTES=" << std::dec << AXIS_WORD_LOG2_BYTES << std::endl;
  std::cout << "AXIS_WORD_SIZE=" << std::dec << AXIS_WORD_SIZE << std::endl;
  std::cout << "AXIS_WORD_BITS=" << std::dec << AXIS_WORD_BITS << std::endl;

  std::cout << "AXIS_WORDS_PER_AXI_WORD=" << std::dec << AXIS_WORDS_PER_AXI_WORD << std::endl;

  std::cout << "CACHE_WORD_ADDRESS_BITS=" << std::dec << CACHE_WORD_ADDRESS_BITS << std::endl;
  std::cout << "CACHE_WORDS=" << std::dec << CACHE_WORDS << std::endl;
  std::cout << "CACHE_SIZE=" << std::dec << CACHE_SIZE << std::endl;

  std::cout << "BUFFER_WORD_ADDRESS_BITS=" << std::dec << BUFFER_WORD_ADDRESS_BITS << std::endl;
  std::cout << "BUFFER_WORDS=" << std::dec << BUFFER_WORDS << std::endl;
  std::cout << "BUFFER_SIZE=" << std::dec << BUFFER_SIZE << std::endl;

  std::cout << "LOOP_ITERATOR_BITS=" << std::dec << LOOP_ITERATOR_BITS << std::endl;
  std::cout << "LOOP_MAX_TRIP_COUNT=" << std::dec << LOOP_MAX_TRIP_COUNT << std::endl;
  std::cout << "LOOP_TRIP_COUNT_BITS=" << std::dec << LOOP_TRIP_COUNT_BITS << std::endl;
  std::cout << "CACHE_LENGTH_BITS=" << std::dec << CACHE_LENGTH_BITS << std::endl;
  std::cout << "CACHE_LENGTH=" << std::dec << CACHE_LENGTH << std::endl;
  std::cout << "BUFFER_LENGTH_BITS=" << std::dec << BUFFER_LENGTH_BITS << std::endl;

  std::cout << "Allocating " << std::dec << BUFFER_SIZE  << " byte transmit buffer... ";
  tx_buffer = (axi_t *)malloc(BUFFER_SIZE);
  if (NULL==tx_buffer) { std::cout << "SUCCESS" << std::endl; return EXIT_FAILURE; }
  else std::cout << "SUCCESS" << std::endl;

  std::cout << "Allocating " << std::dec << BUFFER_SIZE << " byte receive buffer... ";
  rx_buffer = (axi_t *)malloc(BUFFER_SIZE);
  if (NULL==rx_buffer) { std::cout << "SUCCESS" << std::endl; return EXIT_FAILURE; }
  else std::cout << "SUCCESS" << std::endl;

  /* write bytes to transmit buffer */
  PRBS_state = TX_PRBS_STATE;
  tx_buffer_length = TX_TRANSFER_LENGTH;
  tx_buffer_crc = 0xFFFFFFFF;
  for (int n=0;n<TX_TRANSFER_LENGTH*AXIS_WORD_SIZE;n++)
  {
	uint8_t b;
	b = get_PRBS_byte(PRBS_state);
	((uint8_t *)tx_buffer)[n] = b;
	tx_buffer_crc = (tx_buffer_crc >> CRC_DATA_WORD_BITS) ^ crc32_table[(uint8_t)tx_buffer_crc ^ b];
  }
  tx_buffer_crc ^= 0xFFFFFFFF;
  std::cout << "tx_buffer crc=0x" << std::hex << std::uppercase << std::noshowbase << std::internal << std::setfill('0') << std::setw(8) << (unsigned)tx_buffer_crc << std::endl;

  /* send words to receiver */
  PRBS_state = RX_PRBS_STATE;
  rx_buffer_length = RX_TRANSFER_LENGTH;
  rx_stream_crc = 0xFFFFFFFF;
  for (int n=0; n<RX_TRANSFER_LENGTH; n++)
   {
	 axis_t data=0;
	 for (int i=0;i<sizeof(data);i++)
	  {
		uint8_t b;
	    b = get_PRBS_byte(PRBS_state);
	    data |= ((axis_t)b)<<(i*BITS_PER_BYTE);
	    rx_stream_crc = (rx_stream_crc >> CRC_DATA_WORD_BITS) ^ crc32_table[(uint8_t)rx_stream_crc ^ b];
	  }
	 data_rx << data;
   }
  rx_stream_crc^= 0xFFFFFFFF;
  std::cout << "rx_stream crc=0x" << std::hex << std::uppercase << std::noshowbase << std::internal << std::setfill('0') << std::setw(8) << (unsigned)rx_stream_crc << std::endl;

  std::cout << "Testing data_mover()..." << std::endl;
  data_mover_32b64b(data_rx, data_tx, tx_buffer, &tx_buffer_length, rx_buffer, &rx_buffer_length);

  /* check transmit stream */
  crc = 0xFFFFFFFF; /* setup CRC working register */
  for (int n=0; n<TX_TRANSFER_LENGTH; n++)
  {
	axis_t data;
	data_tx >> data;
	for (int i=0;i<sizeof(data);i++)
	 {
	   uint8_t b;
	   b = data >> (i*BITS_PER_BYTE);
	   crc = (crc >> CRC_DATA_WORD_BITS) ^ crc32_table[(uint8_t)crc ^ b]; /* update crc for data byte transmitted */
	 }
  }
  crc ^= 0xFFFFFFFF; /* return final CRC-32 value */

  std::cout << "data_tx crc=0x" << std::hex << std::uppercase << std::noshowbase << std::internal << std::setfill('0') << std::setw(8) << (unsigned)crc << std::endl;
  if (crc != tx_buffer_crc) errors++;

  /* check receive buffer */
  crc = 0xFFFFFFFF; /* setup CRC working register */
  for (int n=0; n<RX_TRANSFER_LENGTH*AXIS_WORD_SIZE; n++)
   {
	 crc = (crc >> CRC_DATA_WORD_BITS) ^ crc32_table[(uint8_t)crc ^ ((uint8_t *)rx_buffer)[n]]; /* update crc for data byte received */
   }
  crc ^= 0xFFFFFFFF; /* return final CRC-32 value */

  std::cout << "rx_buffer crc=0x" << std::hex << std::uppercase << std::noshowbase << std::internal << std::setfill('0') << std::setw(8) << (unsigned)crc << std::endl;
  if (crc != rx_stream_crc) errors++;

  if (errors) { std::cout << "FAILED! with " << std::dec << errors << " errors." << std::endl; return EXIT_FAILURE; }
  return EXIT_SUCCESS;
}
