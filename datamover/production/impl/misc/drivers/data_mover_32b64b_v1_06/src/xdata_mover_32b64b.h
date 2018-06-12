// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.1
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef XDATA_MOVER_32B64B_H
#define XDATA_MOVER_32B64B_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xdata_mover_32b64b_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XData_mover_32b64b_Config;
#endif

typedef struct {
    u32 Control_BaseAddress;
    u32 IsReady;
} XData_mover_32b64b;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XData_mover_32b64b_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XData_mover_32b64b_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XData_mover_32b64b_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XData_mover_32b64b_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XData_mover_32b64b_Initialize(XData_mover_32b64b *InstancePtr, u16 DeviceId);
XData_mover_32b64b_Config* XData_mover_32b64b_LookupConfig(u16 DeviceId);
int XData_mover_32b64b_CfgInitialize(XData_mover_32b64b *InstancePtr, XData_mover_32b64b_Config *ConfigPtr);
#else
int XData_mover_32b64b_Initialize(XData_mover_32b64b *InstancePtr, const char* InstanceName);
int XData_mover_32b64b_Release(XData_mover_32b64b *InstancePtr);
#endif

void XData_mover_32b64b_Start(XData_mover_32b64b *InstancePtr);
u32 XData_mover_32b64b_IsDone(XData_mover_32b64b *InstancePtr);
u32 XData_mover_32b64b_IsIdle(XData_mover_32b64b *InstancePtr);
u32 XData_mover_32b64b_IsReady(XData_mover_32b64b *InstancePtr);
void XData_mover_32b64b_EnableAutoRestart(XData_mover_32b64b *InstancePtr);
void XData_mover_32b64b_DisableAutoRestart(XData_mover_32b64b *InstancePtr);

void XData_mover_32b64b_Set_tx_buffer_V(XData_mover_32b64b *InstancePtr, u32 Data);
u32 XData_mover_32b64b_Get_tx_buffer_V(XData_mover_32b64b *InstancePtr);
void XData_mover_32b64b_Set_tx_buffer_length_V(XData_mover_32b64b *InstancePtr, u32 Data);
u32 XData_mover_32b64b_Get_tx_buffer_length_V(XData_mover_32b64b *InstancePtr);
void XData_mover_32b64b_Set_rx_buffer_V(XData_mover_32b64b *InstancePtr, u32 Data);
u32 XData_mover_32b64b_Get_rx_buffer_V(XData_mover_32b64b *InstancePtr);
void XData_mover_32b64b_Set_rx_buffer_length_V(XData_mover_32b64b *InstancePtr, u32 Data);
u32 XData_mover_32b64b_Get_rx_buffer_length_V(XData_mover_32b64b *InstancePtr);

void XData_mover_32b64b_InterruptGlobalEnable(XData_mover_32b64b *InstancePtr);
void XData_mover_32b64b_InterruptGlobalDisable(XData_mover_32b64b *InstancePtr);
void XData_mover_32b64b_InterruptEnable(XData_mover_32b64b *InstancePtr, u32 Mask);
void XData_mover_32b64b_InterruptDisable(XData_mover_32b64b *InstancePtr, u32 Mask);
void XData_mover_32b64b_InterruptClear(XData_mover_32b64b *InstancePtr, u32 Mask);
u32 XData_mover_32b64b_InterruptGetEnabled(XData_mover_32b64b *InstancePtr);
u32 XData_mover_32b64b_InterruptGetStatus(XData_mover_32b64b *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
