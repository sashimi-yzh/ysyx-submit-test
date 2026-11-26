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

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */
  cpu.mepc = epc;
  cpu.mcause = NO;
  
  #ifdef CONFIG_ETRACE
  const char *exception_name = "Unknown";
  switch (NO) {
    case 0: exception_name = "Instruction address misaligned"; break;
    case 1: exception_name = "Instruction access fault"; break;
    case 2: exception_name = "Illegal instruction"; break;
    case 3: exception_name = "Breakpoint"; break;
    case 4: exception_name = "Load address misaligned"; break;
    case 5: exception_name = "Load access fault"; break;
    case 6: exception_name = "Store/AMO address misaligned"; break;
    case 7: exception_name = "Store/AMO access fault"; break;
    case 8: exception_name = "Environment call from U-mode"; break;
    case 9: exception_name = "Environment call from S-mode"; break;
    case 11: exception_name = "Environment call from M-mode"; break;
    case 12: exception_name = "Instruction page fault"; break;
    case 13: exception_name = "Load page fault"; break;
    case 15: exception_name = "Store/AMO page fault"; break;
  }
  Log(ANSI_FMT("[ETRACE] Exception", ANSI_FG_YELLOW) " #%d (%s): mepc=" FMT_WORD " -> mtvec=" FMT_WORD, 
      NO, exception_name, epc, cpu.mtvec);
  #endif
  
  return cpu.mtvec;
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
