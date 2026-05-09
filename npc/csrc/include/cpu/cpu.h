/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#ifndef __CPU_CPU_H__
#define __CPU_CPU_H__

#include <common.h>

// extern "C" void flash_read(int32_t addr, int32_t *data) { assert(0); }
// extern "C" void mrom_read(int32_t addr, int32_t *data) { assert(0); }

void npc_exec(uint64_t n);

vaddr_t cpu_state();

void reg_display();

typedef struct {
    word_t reg[16]; // 寄存器
    vaddr_t pc;
  } NPC_state;

extern NPC_state cpu;

// void set_nemu_state(int state, vaddr_t pc, int halt_ret);
// void invalid_inst(vaddr_t thispc);

// #define NEMUTRAP(thispc, code) set_nemu_state(NEMU_END, thispc, code)
// #define INV(thispc) invalid_inst(thispc)

#endif
