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

#include <debug.h>
#include <isa.h>

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
#ifdef CONFIG_ETRACER
  Log("Raising interruption : cause = %d, @0x%08x", NO, epc);
#endif
  cpu.csr_mepc = epc;
  cpu.csr_mcause = NO;

  return cpu.csr_mtvec;
}

word_t isa_query_intr() { return INTR_EMPTY; }
