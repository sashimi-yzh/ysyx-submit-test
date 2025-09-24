/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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

#include "../local-include/reg.h"
#include "utils.h"
#include <isa.h>

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */
  csr(MEPC) = epc;

  switch (NO) {

  case -1: csr(MCAUSE) = 11; break;
    default: panic("wrong mcause num: %x, pc = 0x%x", NO, cpu.pc);
  }

  IFDEF(CONFIG_ETRACE, trace_write("Exception Triggered: pc = 0x%.8x, NO = %u, mtvec = 0x%.8x\n",
              epc, NO, csr(MTVEC)));
  return csr(MTVEC);
}

word_t isa_query_intr() { return INTR_EMPTY; }
