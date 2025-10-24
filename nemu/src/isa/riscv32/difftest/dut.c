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

const char *regs_sorted[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};
const char *csrs_sorted[] = {
  "mcause", "mepc", "mstatus", "mtvec" 
};
#define CHECKDIFF_CSR(p) if(ref_r->csr.p != cpu.csr.p){\
  printf(#p " mismatch: NEMU = 0x%x, REF = 0x%x\n", cpu.csr.p, ref_r->csr.p); \
  return false; \
}
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  if (cpu.pc != ref_r->pc) {
    printf("PC mismatch: NEMU = 0x%x, REF = 0x%x\n", cpu.pc, ref_r->pc);
    nemu_state.state = NEMU_ABORT;
    return false;
  }
  // 2. 检查通用寄存器 (x0-x31)
  for (int i = 0; i < 32; i++) {
    if (cpu.gpr[i] != ref_r->gpr[i]) {
      printf("%s mismatch: NEMU = 0x%x, REF = 0x%x\n", regs_sorted[i], cpu.gpr[i], ref_r->gpr[i]);
      nemu_state.state = NEMU_ABORT;
      return false;
    }
  }
  // CHECKDIFF_CSR(mstatus);
  // CHECKDIFF_CSR(mcause);
  // CHECKDIFF_CSR(mepc);
  // CHECKDIFF_CSR(mtvec);
  return true;
}

void isa_difftest_attach() {
}
