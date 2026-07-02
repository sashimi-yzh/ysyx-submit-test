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
#include <string.h>

#if defined(CONFIG_ISA_riscv)
_Static_assert(DIFFTEST_REG_SIZE == sizeof(CPU_state),
    "RISC-V DiffTest register copy size must match CPU_state");
#endif

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  Assert(buf != NULL,
      "difftest_memcpy with null buffer: addr=" FMT_PADDR " n=%zu direction=%d",
      addr, n, direction);
  Assert(direction == DIFFTEST_TO_DUT || direction == DIFFTEST_TO_REF,
      "difftest_memcpy with bad direction: addr=" FMT_PADDR " n=%zu direction=%d",
      addr, n, direction);
  Assert(n == 0 || (uint64_t)addr + (uint64_t)n - 1 >= (uint64_t)addr,
      "difftest_memcpy address overflow: addr=" FMT_PADDR " n=%zu direction=%d",
      addr, n, direction);
  uint8_t *p = (uint8_t *)buf;
  if (direction == DIFFTEST_TO_REF) {
    for (size_t i = 0; i < n; i++) {
      paddr_write(addr + i, 1, p[i]);
    }
  } else {
    for (size_t i = 0; i < n; i++) {
      p[i] = (uint8_t)paddr_read(addr + i, 1);
    }
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  Assert(dut != NULL, "difftest_regcpy with null buffer: direction=%d", direction);
  Assert(direction == DIFFTEST_TO_DUT || direction == DIFFTEST_TO_REF,
      "difftest_regcpy with bad direction: direction=%d", direction);
  if (direction == DIFFTEST_TO_REF) {
    memcpy(&cpu, dut, DIFFTEST_REG_SIZE);
  } else {
    memcpy(dut, &cpu, DIFFTEST_REG_SIZE);
  }
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  panic("unexpected difftest_raise_intr: NO=" FMT_WORD " pc=" FMT_WORD, NO, cpu.pc);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
