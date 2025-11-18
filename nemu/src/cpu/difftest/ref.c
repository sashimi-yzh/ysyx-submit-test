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
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

// rv32e has 16 register instead of 32
__EXPORT int regs_num;

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if (direction == DIFFTEST_TO_REF) {
    memcpy(flash2host(addr), buf, n);
  } else {
    Assert(0, "memcpy to dut is not supported");
  }
}

__EXPORT void difftest_regcpy(void *dut, void*pc, bool direction) {
  word_t *reg = dut;
  if (direction == DIFFTEST_TO_REF) {
    for (int i = 0; i < regs_num; i++) {
      cpu.gpr[i] = *(reg + i);
    }
    cpu.pc = *(paddr_t *)pc;
  } else {
    for (int i = 0; i < regs_num; i++) {
      *(reg + i) = cpu.gpr[i];
    }
    *(paddr_t *)pc = cpu.pc;
  }
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init(int port) {
  /* Perform ISA dependent initialization. */
  init_isa();
}
