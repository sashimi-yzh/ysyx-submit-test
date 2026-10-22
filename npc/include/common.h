#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>

#ifdef PLATFORM_YSYXSOC
#include "verilated.h"
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull.h"
// #include "verilated_vcd_c.h"
#include "svdpi.h"
#include "VysyxSoCFull__Dpi.h"
#include "verilated_fst_c.h"
#include <nvboard.h> 
#else 
#include "verilated.h"
#include "Vysyx_25020042___024root.h"
#include "Vysyx_25020042.h"
// #include "verilated_vcd_c.h"
#include "svdpi.h"
#include "Vysyx_25020042__Dpi.h"
#include "verilated_fst_c.h"
#endif


typedef uint32_t word_t;
typedef uint32_t sword_t;

typedef uint32_t paddr_t;
typedef word_t vaddr_t;

#define FMT_WORD "0x%08" PRIx32

#include <generated/autoconf.h>
#include <macro.h>
#include <utils.h>

#include <assert.h>
#include <stdlib.h>


#define FMT_PADDR MUXDEF(PMEM64, "0x%016" PRIx64, "0x%08" PRIx32)
typedef uint16_t ioaddr_t;

#include <debug.h>

extern VerilatedContext* contextp;
#if CONFIG_WAVE
extern VerilatedFstC* tfp;
// extern VerilatedVcdC* tfp;
#endif
#ifdef PLATFORM_YSYXSOC
extern VysyxSoCFull* top;
#define _pc_data_ top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__WBU_u__DOT__pc 
#define _next_pc_data_ top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu_next_pc
#define _lsu_pc_data_ top->rootp->ysyxSoCFull__DOT__asic__DOT__lsu__DOT__lsu_to_wbu_pc_data
#define _instruction_data_ top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__WBU_u__DOT__instruction_data
#define _single_inst_done_ top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__WBU_u__DOT__instruction_done
#define _a0_data_ top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__a0
#else
extern Vysyx_25020042* top;
#define _pc_data_ top->rootp->ysyx_25020042__DOT__WBU_u__DOT__pc 
#define _next_pc_data_ top->rootp->ysyx_25020042__DOT__wbu_next_pc
#define _lsu_pc_data_ top->rootp->ysyx_25020042__DOT__lsu_to_wbu_pc_data
#define _instruction_data_ top->rootp->ysyx_25020042__DOT__WBU_u__DOT__instruction_data
#define _single_inst_done_ top->rootp->ysyx_25020042__DOT__WBU_u__DOT__instruction_done
#define _a0_data_ top->rootp->ysyx_25020042__DOT__gpr_u__DOT__a0
#endif

#endif