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

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  int reg_num = ARRLEN(cpu.gpr);
  // 对比寄存器
  for (int i = 0; i < reg_num; i++) {
    if (ref_r->gpr[i] != cpu.gpr[i]) {
      printf("Difftest Info: The %d index of reg is different\n", i);
      printf("Current PC = 0x%08x\n", cpu.pc);
      printf("nemu.gpr[%d] = 0x%08x\n", i, cpu.gpr[i]);
      printf("spike.gpr[%d] = 0x%08x\n", i, ref_r->gpr[i]);
      return false;
    }
  }
  // 对比PC
  if (ref_r->pc != cpu.pc) {
    printf("Difftest Info: The PC is different\n");
    printf("nemu.PC = 0x%08x\n", cpu.pc);
    printf("Should jump to 0x%08x\n", ref_r->pc);
    return false;
  }

  // if (ref_r->csr.mcause != cpu.csr.mcause) {
  //   printf("Difftest Info: The mcause is different\n");
  //   printf("nemu.mcause = 0x%08x\n", cpu.csr.mcause);
  //   printf("Spike.mcause 0x%08x\n", ref_r->csr.mcause);
  //   return false;
  // }

  // if (ref_r->csr.mepc != cpu.csr.mepc) {
  //   printf("Difftest Info: The mepc is different\n");
  //   printf("nemu.mepc = 0x%08x\n", cpu.csr.mepc);
  //   printf("Spike.mepc = 0x%08x\n", ref_r->csr.mepc);
  //   return false;
  // }

  // if (ref_r->csr.mstatus != cpu.csr.mstatus) {
  //   printf("Difftest Info: The mstatus is different\n");
  //   printf("nemu.mstatus = 0x%08x\n", cpu.csr.mstatus);
  //   printf("Spike.mstatus = 0x%08x\n", ref_r->csr.mstatus);
  //   return false;
  // }

  // if (ref_r->csr.mtvec != cpu.csr.mtvec) {
  //   printf("Difftest Info: The mtvec is different\n");
  //   printf("nemu.mtvec = 0x%08x\n", cpu.csr.mtvec);
  //   printf("Spike.mtvec = 0x%08x\n", ref_r->csr.mtvec);
  //   return false;
  // }
  return true;
}


void isa_difftest_attach() {
}
