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
#include <cpu/difftest.h>
#include "../local-include/reg.h"
#include "utils.h"

extern const char *regs[];

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  int eq = true;
  for (int i = 0; i < 32; i++) {
    if (ref_r->gpr[i] != cpu.gpr[i]) {
      printf(ANSI_FMT("Difftest wrong: %s at 0x%.8x\n", ANSI_FG_RED), regs[i], pc);
      printf("ref = 0x%.8x   dut = 0x%.8x\n", ref_r->gpr[i], cpu.gpr[i]);
      eq = false;
      break;
    }
  }
  if (ref_r->pc != cpu.pc) {
    printf(ANSI_FMT("Difftest wrong: pc at 0x%.8x\n", ANSI_FG_RED), pc);
    printf("ref = 0x%.8x   dut = 0x%.8x\n", ref_r->pc, cpu.pc);
    eq = false;
  }
  return eq;
}

void isa_difftest_attach() {
}
