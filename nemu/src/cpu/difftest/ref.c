/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <assert.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <isa.h>
#include <memory/paddr.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n,
                              bool direction) {
  if (direction == DIFFTEST_TO_REF) {
    uint8_t *pos = guest_to_host(addr);
    uint8_t *src = buf;
    for (int i = 0; i < n; i++) {
      // printf("%d\n", i);
      *(pos + i) = *(src + i);
    }
  } else {
    assert(0);
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  if (direction == DIFFTEST_TO_REF) {
    memcpy(&cpu, dut, sizeof(uint32_t) * (MUXDEF(CONFIG_RVE, 16, 32) + 1));
  } else {
    memcpy(dut, &cpu, sizeof(uint32_t) * (MUXDEF(CONFIG_RVE, 16, 32) + 1));
  }
}

__EXPORT void difftest_exec(uint64_t n) { cpu_exec(n); }

__EXPORT void difftest_raise_intr(word_t NO) { assert(0); }

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
