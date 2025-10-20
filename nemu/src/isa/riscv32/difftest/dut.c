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

word_t *check_csr_idx(word_t idx) {
  IFDEF(CONFIG_RT_CHECK, assert(idx == MSTATUS || idx == MTVEC || idx == MEPC || idx == MCAUSE));
  switch(idx) {
    case MTVEC   :  return &(cpu.csrs.mtvec);
    case MEPC    :  return &(cpu.csrs.mepc);
    case MSTATUS :  return &(cpu.csrs.mstatus);
    case MCAUSE  :  return &(cpu.csrs.mcause);
    default : printf("csr_idx error\n"); assert(0); break;
  }
}

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  for (int i = 0; i < 32; i++) {
    if (ref_r->gpr[i] != cpu.gpr[i]) {
      printf("dut->reg[%d]: 0x%08x != ref->gpr[%d]: 0x%08x\n", i, cpu.gpr[i], i, ref_r->gpr[i]);
      return false;
    }
  }
  if (ref_r->pc != cpu.pc) {
    printf("dut->pc: 0x%08x != ref->pc: 0x%08x\n", cpu.pc, ref_r->pc);
    return false;
  }
  if (ref_r->csrs.mstatus != cpu.csrs.mstatus) {
    printf("dut->mstatus: 0x%08x != ref->mstatus: 0x%08x\n", cpu.csrs.mstatus, ref_r->csrs.mstatus);
    return false;
  }
  if (ref_r->csrs.mcause != cpu.csrs.mcause) {
    printf("dut->mcause: 0x%08x != ref->mcause: 0x%08x\n", cpu.csrs.mcause, ref_r->csrs.mcause);
    return false;
  }
  if (ref_r->csrs.mepc != cpu.csrs.mepc) {
    printf("dut->mepc: 0x%08x != ref->mepc: 0x%08x\n", cpu.csrs.mepc, ref_r->csrs.mepc);
    return false;
  }
  if (ref_r->csrs.mtvec != cpu.csrs.mtvec) {
    printf("dut->mtvec: 0x%08x != ref->mtvec: 0x%08x\n", cpu.csrs.mtvec, ref_r->csrs.mtvec);
    return false;
  }
  return true;
}

void isa_difftest_attach() {
}
