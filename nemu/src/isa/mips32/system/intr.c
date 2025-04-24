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

#ifndef __ICS_EXPORT
#include "../local-include/intr.h"
#include <isa.h>
#include <cpu/difftest.h>

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
#define EX_ENTRY 0x80000180
  vaddr_t target = (NO & TLB_REFILL) ? 0x80000000 : EX_ENTRY;
  NO &= ~TLB_REFILL;
  cpu.cause = NO << 2;
  cpu.epc = epc;
  cpu.status.exl = 1;

  difftest_skip_dut(1, 2);

  return target;
}

word_t isa_query_intr() {
  if (cpu.INTR && (cpu.status.ie) && !(cpu.status.exl)) {
    cpu.INTR = false;
    return 0;
  }
  return INTR_EMPTY;
}
#else
#include <isa.h>

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */

  return 0;
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
#endif
