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
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
  for (int i = 0; i < 32; i++) {
    printf("%d\t%s\t" FMT_WORD_D "\t" FMT_WORD "\n", i, regs[i], gpr(i),
           gpr(i));
  }
  printf("\tmstatus\t" FMT_WORD_D "\t" FMT_WORD "\n", cpu.mstatus, cpu.mstatus);
  printf("\tmtvec\t" FMT_WORD_D "\t" FMT_WORD "\n", cpu.mtvec, cpu.mtvec);
  printf("\tmepc\t" FMT_WORD_D "\t" FMT_WORD "\n", cpu.mepc, cpu.mepc);
  printf("\tmcause\t" FMT_WORD_D "\t" FMT_WORD "\n", cpu.mcause, cpu.mcause);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  if (strcmp(s, "pc") == 0) {
    return cpu.pc;
  }
  if (strcmp(s, "mstatus") == 0) {
    return cpu.mstatus;
  }
  if (strcmp(s, "mtvec") == 0) {
    return cpu.mtvec;
  }
  if (strcmp(s, "mepc") == 0) {
    return cpu.mepc;
  }
  if (strcmp(s, "mcause") == 0) {
    return cpu.mcause;
  }
  for (int i = 0; i < 32; i++) {
    if (strcmp(regs[i], s) == 0) {
      return gpr(i);
    }
  }
  *success = false;
  return 0;
}
