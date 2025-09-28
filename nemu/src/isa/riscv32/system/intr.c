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

#define IRQ_TIMER 0x80000007

extern word_t csr_mstatus, csr_mtvec, csr_mepc, csr_mcause;

#define MSTATUS_MIE ((csr_mstatus >> 3) & 1) // is interrupt enabled

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
#ifdef CONFIG_ETRACE
  Log("[ETRACE] exception triggered at pc = " FMT_PADDR, epc);
#endif
  csr_mepc = epc;
  csr_mcause = NO;

  // save mstatus.MIE to mstatus.MPIE
  csr_mstatus = (csr_mstatus & ~(1 << 7)) | (MSTATUS_MIE << 7);
  // set mstatus.MIE 0
  csr_mstatus = csr_mstatus & ~(1 << 3);

  return csr_mtvec;
}

word_t isa_query_intr() {
  if (cpu.intr && MSTATUS_MIE) {
    cpu.intr = false;
    return IRQ_TIMER;
  }
  return INTR_EMPTY;
}
