#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "debug.h"
#include "Vtop.h"
#include "Vtop___024root.h"
#include "Vtop_top.h"
#include "Vtop_GPR.h"

extern VerilatedContext* contextp;
extern Vtop* top;
extern FILE* log_fp;

#define CONFIG_INST_LEN 4
#define CONFIG_LOG_PATH "./npc-log.txt"
#define CONFIG_GPR_NUM 16
#define CONFIG_MBASE 0x80000000
#define CONFIG_PC_RESET_OFFSET 0x0
#define PMEM_LEFT CONFIG_MBASE
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)
#define CONFIG_MSIZE 0x8000000

#define CONFIG_DIFFTEST_ENABLE
#define CONFIG_WATCHPOINT_ENABLE
#define CONFIG_TRACE_ENABLE
#ifdef CONFIG_TRACE_ENABLE

    #define CONFIG_ITRACE_ENABLE
    #ifdef CONFIG_ITRACE_ENABLE
        //#define CONFIG_ITRACE_PRINT
    #endif
    
    //#define CONFIG_MTRACE_ENABLE
    #ifdef CONFIG_MTRACE_ENABLE
        #define CONFIG_MTRACE_RANGE_LEFT 0x800a0000
        #define CONFIG_MTRACE_RANGE_RIGHT 0x800f0000
    #endif

    //#define CONFIG_FTRACE_ENABLE

    //#define CONFIG_DTRACE_ENABLE

#endif

#define _EBREAK 0b00000000000100000000000001110011
#define FMT_WORD "0x%08x"
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
#endif