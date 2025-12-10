#ifndef __COMMON_H__
#define __COMMON_H__
//=====================================================
// 头文件
//=====================================================
#include "VysyxSoCFull.h"  // 包含Verilog工程的C++模型
#include "VysyxSoCFull___024root.h"
#include <verilated.h>           // Verilator的库
#include "generated/autoconf.h"
#ifdef CONFIG_FST
#include "verilated_fst_c.h"     // fst波形文件所需要的库
#endif
#ifdef CONFIG_TARGET_NVBOARD
#include <nvboard.h>
#endif
#include "reg.h"
#include "sdb.h"
#include "cpu.h"
#include "expr.h"
#include "memory.h"
#include "debug.h"
#include "disasm.h"
#include "watchpoint.h"
#include "trace.h"
#include "dut.h"
#include "macro.h"
#include "timer.h"
#include "my_uart.h"
//=====================================================
// 状态
//=====================================================
enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT };

typedef struct {
  int state;
  uint32_t halt_pc;
  int halt_ret;
} NPCState;
extern NPCState npcstate;       

void set_nemu_state(int state, uint32_t pc, int halt_ret);
bool is_ebreak(uint32_t inst_i);
bool is_jal(uint32_t inst_i);
bool is_jalr(uint32_t inst_i);
bool is_ret(uint32_t inst_i);

#endif
