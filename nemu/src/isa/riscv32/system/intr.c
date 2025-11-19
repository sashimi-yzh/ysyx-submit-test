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
#include "../local-include/reg.h"

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */
  /*i need to realize save the mepc mcause and mtvec*/
  // csr(MSTATUS) &= ~(1<<7);
  // csr(MSTATUS) |= ((csr(MSTATUS)&(1<<3))<<4);
  // csr(MSTATUS) &= ~(1<<3);
  // csr(MSTATUS) |= ((1<<11)+(1<<12));

  csr(MEPC) = epc;
  csr(MCAUSE) = NO;
  return csr(MTVEC);
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
