/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 * PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include "common.h"
#include <isa.h>
IFDEF(CONFIG_ETRACE, static char logBuf[128]);
word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  IFDEF(CONFIG_ETRACE,
        sprintf(logBuf, "ETrace: raise intr NO:%d epc:%x", NO, epc));
  IFDEF(CONFIG_ETRACE, _Log("%s\n", logBuf));
  cpu.csrs.mstatus &= ~(1 << 7);
  cpu.csrs.mstatus |= ((cpu.csrs.mstatus & (1 << 3)) << 4);
  cpu.csrs.mstatus &= ~(1 << 3);
  cpu.csrs.mstatus |= (0b11 << 11);
  cpu.csrs.mepc = epc;
  cpu.csrs.mcause = NO;
  return cpu.csrs.mtvec;
}
word_t mret() {
  IFDEF(CONFIG_ETRACE, sprintf(logBuf, "ETrace: mret NO:%d", cpu.csrs.mcause));
  IFDEF(CONFIG_ETRACE, _Log("%s\n", logBuf));
  cpu.csrs.mstatus &= ~(1 << 3);
  cpu.csrs.mstatus |= ((cpu.csrs.mstatus & (1 << 7)) >> 4);
  cpu.csrs.mstatus |= (1 << 7);
  cpu.csrs.mstatus &= ~(0b11 << 11);
  return cpu.csrs.mepc;
}
word_t isa_query_intr() { return INTR_EMPTY; }
