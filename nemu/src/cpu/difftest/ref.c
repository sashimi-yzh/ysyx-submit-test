/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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

#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

#ifdef SHARE
void get_npc_gpr_regs(CPU_state *npc);
#endif

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
#ifdef SHARE
  if (direction == DIFFTEST_TO_REF) memcpy(guest_to_host(addr), buf, n);
  else memcpy(buf, guest_to_host(addr), n);
#endif
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {

#ifdef SHARE
  CPU_state* r_nemu = &cpu;
  CPU_state* r_npc = dut;

  uint8_t i = 0;
  if (direction == DIFFTEST_TO_REF) {
    // Get the value of the registers from the DUT
    //get_npc_gpr_regs(r_npc);
    for (i = 0; i < sizeof(r_nemu->gpr)/sizeof(r_nemu->gpr[0]); i++) {
      r_nemu->gpr[i] = r_npc->gpr[i];
    }
    r_nemu->pc = r_npc->pc;
  } else {
    // Set the value of the registers to the DUT
    for (i = 0; i < sizeof(r_nemu->gpr)/sizeof(r_nemu->gpr[0]); i++) {
      r_npc->gpr[i] = r_nemu->gpr[i];
    }
    r_npc->pc = r_nemu->pc;
  }
#endif
}

__EXPORT void difftest_exec(uint64_t n) {
#ifdef SHARE
  cpu_exec(n);
#endif
}

__EXPORT void difftest_raise_intr(word_t NO) {
}

__EXPORT void difftest_init(int port) {
#ifdef SHARE
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
#endif
}
