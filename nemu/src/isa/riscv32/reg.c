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

#include "local-include/reg.h"
#include "common.h"
#include <isa.h>

const char *regs[] = {
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
    "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
    "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};
void isa_reg_display(CPU_state *cpu) {
  static int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 8 * i; j < 8 * (i + 1); j++) {
      printf("|%-8s\t", regs[j]);
    }
    puts("");
    for (j = 8 * i; j < 8 * (i + 1); j++) {
      printf("|%08x\t", cpu->gpr[j]);
    }
    puts("");
  }
  printf("|%-8s\t|%-8s\t|%-8s\t|%-8s\t|%-8s\t", "pc", "mtvec", "mepc", "mstatus", "mcause");
  puts("");
  printf("|%08x\t|%08x\t|%08x\t|%08x\t|%08x\t", cpu->pc, cpu->csrs.mtvec, cpu->csrs.mepc, cpu->csrs.mstatus, cpu->csrs.mcause);
  puts("");
}

word_t isa_reg_str2val(const char *s, bool *success) {
  for (int i = 0; i < sizeof(regs) / sizeof(regs[0]); i++) {
    if (i == 0) {
      if (strcmp(regs[i], s) == 0) {
        *success = 1;
        return cpu.gpr[i];
      }
    } else if (strcmp(regs[i], s + 1) == 0) {
      *success = 1;
      return cpu.gpr[i];
    }
  }
  *success = 0;
  return 0;
}
