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
extern CPU_state cpu;
void record_etrace(word_t NO, vaddr_t epc,word_t mtvec);
word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */
  cpu.mstatus = (cpu.mstatus & ~(0x8U | 0x80U)) | ((cpu.mstatus & 0x8U) << 4);
  cpu.mepc = epc;
  cpu.mcause = NO;
  record_etrace(NO,epc,cpu.mtvec);
  return cpu.mtvec;
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
