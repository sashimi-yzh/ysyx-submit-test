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
#ifdef CONFIG_MODE_SYSTEM
#include <memory/paddr.h>
#else
#include "../../user/user.h"
#define guest_to_host user_to_host
#endif

#ifndef __ICS_EXPORT
__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if (direction == DIFFTEST_TO_REF) {
    if (in_pmem(addr)) { memcpy(guest_to_host(addr), buf, n); }
    else {
      for (int i = 0; i < n; i ++) {
        paddr_write(addr + i, 1, ((uint8_t *)buf)[i]);
      }
    }
  }
  else {
    if (in_pmem(addr)) { memcpy(buf, guest_to_host(addr), n); }
    else {
      for (int i = 0; i < n; i ++) {
        ((uint8_t *)buf)[i] = paddr_read(addr + i, 1);
      }
    }
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  if (direction == DIFFTEST_TO_REF) memcpy(&cpu, dut, DIFFTEST_REG_SIZE);
  else memcpy(dut, &cpu, DIFFTEST_REG_SIZE);
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  cpu.pc = isa_raise_intr(NO, cpu.pc);
}
#else
__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  assert(0);
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  assert(0);
}

__EXPORT void difftest_exec(uint64_t n) {
  assert(0);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}
#endif

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
#ifndef __ICS_EXPORT
  void init_map();
  init_map();
#endif
  /* Perform ISA dependent initialization. */
  init_isa();
}
