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

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if (direction == DIFFTEST_TO_REF) {
    Log("Copying %zu bytes to reference memory at 0x%08x", n, addr);
#ifdef CONFIG_REF_SOC
    if (in_flash(addr)) {
      memcpy(guest_to_host_flash(addr), buf, n);
    } else if (in_mrom(addr)) {
      memcpy(guest_to_host_mrom(addr), buf, n);
    } else if (in_sram(addr)) {
      memcpy(guest_to_host_sram(addr), buf, n);
    } else if (in_sdram(addr)) {
      memcpy(guest_to_host_sdram(addr), buf, n);
    } else
#endif
    {
      memcpy(guest_to_host(addr), buf, n);
    }
  } else {
#ifdef CONFIG_REF_SOC
    if (in_flash(addr)) {
      memcpy(buf, guest_to_host_flash(addr), n);
    } else if (in_mrom(addr)) {
      memcpy(buf, guest_to_host_mrom(addr), n);
    } else if (in_sram(addr)) {
      memcpy(buf, guest_to_host_sram(addr), n);
    } else if (in_sdram(addr)) {
      memcpy(buf, guest_to_host_sdram(addr), n);
    } else
#endif
    {
      memcpy(buf, guest_to_host(addr), n);
    }
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
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
  assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  void init_device();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
  /* Initialize devices so that MMIO access from DUT can be handled. */
  IFDEF(CONFIG_DEVICE, init_device());
}
