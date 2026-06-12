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
#include <device/device.h>

void (*g_difftest_skip_ref)(void) = NULL;

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if (direction == DIFFTEST_TO_DUT) {
    memcpy(buf, guest_to_host(addr), n);
  } else {
    memcpy(guest_to_host(addr), buf, n);
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  CPU_state *d = (CPU_state *)dut;
  int i;
  if (direction == DIFFTEST_TO_DUT) {
    d->pc = cpu.pc;
    for (i = 0; i < LENGTH(cpu.gpr); i++) {
      d->gpr[i] = cpu.gpr[i];
    }
  } else {
    cpu.pc = d->pc;
    for (i = 0; i < LENGTH(cpu.gpr); i++) {
      cpu.gpr[i] = d->gpr[i];
    }
  }
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init(int port, void (*difftest_skip_ref)(void), device_init_param_t *dip) {
  g_difftest_skip_ref = difftest_skip_ref;
  void init_mem();
  void init_device(device_init_param_t *param);

  init_mem();
  IFDEF(CONFIG_DEVICE, init_device(dip));
  /* Perform ISA dependent initialization. */
  init_isa();
}
