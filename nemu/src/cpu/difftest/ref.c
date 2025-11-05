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
#include <memory/socmem.h>
#include <stdlib.h>

#define DIFFTEST_GUEST_TO MUXDEF(CONFIG_SOC_DIFFTEST, socmem_guest_to_host, guest_to_host)


__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  //assert(0);
  if(direction == DIFFTEST_TO_REF) {
    memcpy(DIFFTEST_GUEST_TO(addr), buf, n);
  } else {
    memcpy(buf, DIFFTEST_GUEST_TO(addr), n);
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  //assert(0);
  if(direction == DIFFTEST_TO_REF) {
    memcpy(&cpu, dut , DIFFTEST_REG_SIZE);
  } else {
    memcpy(dut, &cpu, DIFFTEST_REG_SIZE);
  }

}

__EXPORT void difftest_exec(uint64_t n) {
  //assert(0);
  cpu_exec(n);
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
