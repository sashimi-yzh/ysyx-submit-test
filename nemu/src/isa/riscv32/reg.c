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
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

const int csrs[] = {
  MSTATUS, MTVEC, MEPC, MCAUSE
};

const char *csr_names[] = {
  "mstatus", "mtvec", "mepc", "mcause"
};

void isa_reg_display() {
  int i;
  for (i = 0; i < sizeof(regs)/sizeof(regs[0]); i++) {
    printf("Index.%d reg %-4s value 0x%08x\t", i, regs[i], gpr(i));
    if (i % 4 == 0)
      printf("\n");
  }
  printf("\n");

  for (i = 0; i < sizeof(csrs)/sizeof(csrs[0]); i++) {
    printf("CSR.%-6s value 0x%08x\t", csr_names[i], sr(csrs[i]));
  }
  printf("\n");

  printf("%-4s value 0x%08x\n", "PC", cpu.pc);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  int i;

  *success = false;

  // the 1st reg is $0, we handle it here
  if (!strcmp(s, "0")) {
    *success = true;
    return gpr(0);
  }

  if (!strcmp(s, "pc")) {
    *success = true;
    return cpu.pc;
  }


  for (i = 0; i < sizeof(regs)/sizeof(regs[0]); i++) {
   if (!strcmp(regs[i], s)) {
      *success = true;
      return gpr(i);
    }
  }

  for (i = 0; i < sizeof(csrs)/sizeof(csrs[0]); i++) {
    if (!strcmp(csr_names[i], s)) {
        *success = true;
        return sr(csrs[i]);
      }
  }

  Log("Not a valid reg name: %s\n", s);
  return 0;
}
