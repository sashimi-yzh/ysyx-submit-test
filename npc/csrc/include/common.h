#ifndef __COMMON_H__
#define __COMMON_H__
#include <cstdint>


#define CPUTop top->ysyxSoCFull->asic->cpu->cpu
#define CPUSRAMTop top->ysyxSoCFull->asic->axi4ram->mem_ext->Memory

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "debug.h"


#include "VysyxSoCFull.h"
#include "VysyxSoCFull_ysyxSoCFull.h"
#include "VysyxSoCFull_ysyxSoCASIC.h"
#include "VysyxSoCFull_AXI4RAM.h"
#include "VysyxSoCFull_mem_2048x32.h"
#include "VysyxSoCFull_APBUart16550.h"
#include "VysyxSoCFull_uart_top_apb.h"
#include "VysyxSoCFull_uart_regs.h"

#include "VysyxSoCFull_CPU.h"
#include "VysyxSoCFull_ysyx_26010011.h"
#include "VysyxSoCFull_ysyx_26010011_GPRs.h"
#include "VysyxSoCFull_ysyx_26010011_CSRs.h"
#include "VysyxSoCFull_ysyx_26010011_IF_ID_pipeline.h"
#include "VysyxSoCFull_ysyx_26010011_ID_EX_pipeline.h"
#include "VysyxSoCFull_ysyx_26010011_EX_LS_pipeline.h"
#include "VysyxSoCFull_ysyx_26010011_LS_WB_pipeline.h"
#include "VysyxSoCFull_ysyx_26010011_IFU.h"
#include "VysyxSoCFull_ysyx_26010011_IDU.h"
#include "VysyxSoCFull_ysyx_26010011_LSU.h"
#include "verilated_fst_c.h"




extern VerilatedContext* contextp;
extern VerilatedFstC* tfp;

extern VysyxSoCFull* top;
extern FILE* log_fp;

#define CONFIG_INST_LEN 4
#define CONFIG_LOG_PATH "./npc-log.txt"
#define CONFIG_GPR_NUM 16

#define CONFIG_SRAMBASE 0x0f000000
#define CONFIG_SRAMSIZE 0x00002000
#define SRAM_LEFT CONFIG_SRAMBASE

#define CONFIG_FLASHBASE 0x30000000
#define CONFIG_FLASHSIZE 0x01000000
#define FLASH_LEFT CONFIG_FLASHBASE

#define CONFIG_PSRAMBASE 0x80000000
#define CONFIG_PSRAMSIZE 0x00400000
#define PSRAM_LEFT CONFIG_PSRAMBASE

#define CONFIG_SDRAMBASE 0xA0000000
#define CONFIG_SDRAMSIZE 0x08000000
#define SDRAM_LEFT CONFIG_SDRAMBASE

// #define CONFIG_VMEMBASE 0x21000000
// #define CONFIG_VMEMSIZE 0x00000000
// #define VMEM_LEFT CONFIG_VMEMBASE

#define CONFIG_MROMBASE 0x20000000
#define CONFIG_MROMSIZE 0x00001000


#define CONFIG_PC_RESET_OFFSET 0x0
#define RESET_VECTOR (FLASH_LEFT + CONFIG_PC_RESET_OFFSET)

#define CONFIG_NVBOARD_ENABLE
#ifdef CONFIG_NVBOARD_ENABLE
    #include "nvboard.h"
#endif

// #define CONFIG_DIFFTEST_ENABLE
#ifdef CONFIG_DIFFTEST_ENABLE
    // #define CONFIG_DIFFTEST_MEM_ENABLE
#endif

// #define CONFIG_WATCHPOINT_ENABLE
// #define CONFIG_WAVE_ENABLE


// #define CONFIG_TRACE_ENABLE
#ifdef CONFIG_TRACE_ENABLE

    // #define CONFIG_ITRACE_ENABLE
    #ifdef CONFIG_ITRACE_ENABLE
        // #define CONFIG_ITRACE_PRINT
    #endif
    
    // #define CONFIG_MTRACE_ENABLE
    #ifdef CONFIG_MTRACE_ENABLE
        #define CONFIG_MTRACE_RANGE_LEFT 0x80008fc0
        #define CONFIG_MTRACE_RANGE_RIGHT 0x80008fcf
    #endif

    // #define CONFIG_FTRACE_ENABLE

    // #define CONFIG_DTRACE_ENABLE

#endif

#define _EBREAK 0b00000000000100000000000001110011
#define FMT_WORD "0x%08x"
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

#ifdef CONFIG_WAVE_ENABLE
    #define DUMP() do{tfp->dump(contextp->time());}while(0)
#else
    #define DUMP() do{}while(0)
#endif


#endif
