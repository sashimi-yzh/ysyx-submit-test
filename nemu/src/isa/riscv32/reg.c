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
  printf(ANSI_FMT("nemu的寄存器状态如下:\n", ANSI_FG_GREEN));
  for (int i = 0; i < MUXDEF(CONFIG_RVE, 16, 32); i++)
  {
    printf("x%2d/%3s : 0x%8x\n",i,regs[i],cpu.gpr[i]);
  }
  printf("PC      : 0x%8x\n",cpu.pc);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  *success = true;
  for(int i = 0; i < MUXDEF(CONFIG_RVE, 16, 32); i++) {
    char reg[5] = "$";
    strcat(reg,regs[i]);
    if(!strcmp(reg, s)) {
      return cpu.gpr[i];
    }
  }
  char* reg = "$pc";
  if(!strcmp(s, reg)) return cpu.pc;
  *success = false;
  return 0;
}
