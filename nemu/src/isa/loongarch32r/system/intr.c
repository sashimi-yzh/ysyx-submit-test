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

#ifndef __ICS_EXPORT
word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  cpu.estat.ecode = NO;
  cpu.era = epc;
  cpu.prmd.pplv = cpu.crmd.plv;
  cpu.crmd.plv  = 0;
  cpu.prmd.pie = cpu.crmd.ie;
  cpu.crmd.ie  = 0;
  if (NO == 0x3f) {
    cpu.crmd.pg = 0;
    return cpu.tlbrentry;
  }
  return cpu.eentry;
}

word_t isa_query_intr() {
  if (cpu.INTR && cpu.crmd.ie) {
    cpu.INTR = false;
    return 0x0;
  }
  return INTR_EMPTY;
}

#else
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
