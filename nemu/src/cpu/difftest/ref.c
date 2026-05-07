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

void diff_set_regs(CPU_state* dut){
  for (int i = 0; i < 32; i++) {
    cpu.gpr[i]= dut->gpr[i];
  }
  cpu.pc = dut->pc;
  cpu.csr_mepc = dut->csr_mepc;
  cpu.csr_mstatus = dut->csr_mstatus;
  cpu.csr_mcause = dut->csr_mcause;
  cpu.csr_mtvec = dut->csr_mtvec;

}

void diff_get_regs(CPU_state* dut){
  for (int i = 0; i < 32; i++) {
    dut->gpr[i] = cpu.gpr[i];
  }
  dut->pc = cpu.pc;
  dut->csr_mepc = cpu.csr_mepc;
  dut->csr_mstatus = cpu.csr_mstatus;
  dut->csr_mcause = cpu.csr_mcause;
  dut->csr_mtvec = cpu.csr_mtvec;

}

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  size_t i;
  if(direction == DIFFTEST_TO_REF) {
    for(i=0;i<n;i++) {
      paddr_write(addr+i,1,*((uint8_t*)buf+i));
    }
  }
  else {
    assert(0);
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  if (direction == DIFFTEST_TO_REF) {
    diff_set_regs(dut);
  } else {
    diff_get_regs(dut);
  }
  
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
  //assert(0);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
