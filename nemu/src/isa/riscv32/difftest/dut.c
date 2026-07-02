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

#include <isa.h>
#include <cpu/difftest.h>
#include "../local-include/reg.h"

static bool check_reg(const char *name, word_t ref, word_t dut, vaddr_t pc) {
  if (ref == dut) return true;
  printf("difftest error at pc = " FMT_WORD ": %s mismatch, ref = " FMT_WORD ", dut = " FMT_WORD "\n",
      pc, name, ref, dut);
  return false;
}

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  for (int i = 0; i < ARRLEN(cpu.gpr); i++) {
    if (ref_r->gpr[i] != cpu.gpr[i]) {
      printf("difftest error at pc = " FMT_WORD ": gpr[%d] mismatch, ref = " FMT_WORD ", dut = " FMT_WORD "\n",
          pc, i, ref_r->gpr[i], cpu.gpr[i]);
      return false;
    }
  }

  return check_reg("pc", ref_r->pc, cpu.pc, pc)
      && check_reg("mstatus", ref_r->mstatus, cpu.mstatus, pc)
      && check_reg("mtvec", ref_r->mtvec, cpu.mtvec, pc)
      && check_reg("mepc", ref_r->mepc, cpu.mepc, pc)
      && check_reg("mcause", ref_r->mcause, cpu.mcause, pc);
}

void isa_difftest_attach() {
}
