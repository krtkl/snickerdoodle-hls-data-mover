// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.1
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

// control
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x10 : Data signal of tx_buffer_V
//        bit 31~0 - tx_buffer_V[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of tx_buffer_length_V
//        bit 23~0 - tx_buffer_length_V[23:0] (Read/Write)
//        others   - reserved
// 0x1c : reserved
// 0x20 : Data signal of rx_buffer_V
//        bit 31~0 - rx_buffer_V[31:0] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of rx_buffer_length_V
//        bit 23~0 - rx_buffer_length_V[23:0] (Read/Write)
//        others   - reserved
// 0x2c : reserved
// 0x30 : Data signal of current_buffer_V_i
//        bit 0  - current_buffer_V_i[0] (Read/Write)
//        others - reserved
// 0x34 : reserved
// 0x38 : Data signal of current_buffer_V_o
//        bit 0  - current_buffer_V_o[0] (Read)
//        others - reserved
// 0x3c : Control signal of current_buffer_V_o
//        bit 0  - current_buffer_V_o_ap_vld (Read/COR)
//        others - reserved
// 0x40 : Data signal of last_buffer_V
//        bit 0  - last_buffer_V[0] (Read)
//        others - reserved
// 0x44 : Control signal of last_buffer_V
//        bit 0  - last_buffer_V_ap_vld (Read/COR)
//        others - reserved
// 0x48 : Data signal of increment_buffer
//        bit 0  - increment_buffer[0] (Read/Write)
//        others - reserved
// 0x4c : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XDATA_MOVER_CONTROL_ADDR_AP_CTRL                 0x00
#define XDATA_MOVER_CONTROL_ADDR_GIE                     0x04
#define XDATA_MOVER_CONTROL_ADDR_IER                     0x08
#define XDATA_MOVER_CONTROL_ADDR_ISR                     0x0c
#define XDATA_MOVER_CONTROL_ADDR_TX_BUFFER_V_DATA        0x10
#define XDATA_MOVER_CONTROL_BITS_TX_BUFFER_V_DATA        32
#define XDATA_MOVER_CONTROL_ADDR_TX_BUFFER_LENGTH_V_DATA 0x18
#define XDATA_MOVER_CONTROL_BITS_TX_BUFFER_LENGTH_V_DATA 24
#define XDATA_MOVER_CONTROL_ADDR_RX_BUFFER_V_DATA        0x20
#define XDATA_MOVER_CONTROL_BITS_RX_BUFFER_V_DATA        32
#define XDATA_MOVER_CONTROL_ADDR_RX_BUFFER_LENGTH_V_DATA 0x28
#define XDATA_MOVER_CONTROL_BITS_RX_BUFFER_LENGTH_V_DATA 24
#define XDATA_MOVER_CONTROL_ADDR_CURRENT_BUFFER_V_I_DATA 0x30
#define XDATA_MOVER_CONTROL_BITS_CURRENT_BUFFER_V_I_DATA 1
#define XDATA_MOVER_CONTROL_ADDR_CURRENT_BUFFER_V_O_DATA 0x38
#define XDATA_MOVER_CONTROL_BITS_CURRENT_BUFFER_V_O_DATA 1
#define XDATA_MOVER_CONTROL_ADDR_CURRENT_BUFFER_V_O_CTRL 0x3c
#define XDATA_MOVER_CONTROL_ADDR_LAST_BUFFER_V_DATA      0x40
#define XDATA_MOVER_CONTROL_BITS_LAST_BUFFER_V_DATA      1
#define XDATA_MOVER_CONTROL_ADDR_LAST_BUFFER_V_CTRL      0x44
#define XDATA_MOVER_CONTROL_ADDR_INCREMENT_BUFFER_DATA   0x48
#define XDATA_MOVER_CONTROL_BITS_INCREMENT_BUFFER_DATA   1

