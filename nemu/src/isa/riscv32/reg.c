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
#include <stdio.h>
#include <string.h>

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
  // PC
  printf("pc\t0x%08x\n", (uint32_t)cpu.pc);

  // GPRs: 32 regs, print 4 per line
  for (int i = 0; i < 32; i++) {
    // cpu.gpr[i] 的类型在 reg.h 里通常是 word_t 或含 _32 字段
    // NEMU riscv32 通常是 cpu.gpr[i]（word_t）
    printf("%s\t0x%08x", regs[i], (uint32_t)cpu.gpr[i]);

    if ((i + 1) % 4 == 0) printf("\n");
    else printf("\t");
  }
}

word_t isa_reg_str2val(const char *s, bool *success) {
  if (s == NULL) {
    *success = false;
    return 0;
  }

  // 支持 "pc"
  if (strcmp(s, "pc") == 0) {
    *success = true;
    return (word_t)cpu.pc;
  }

  // 支持 "$0" / "ra" / "sp" / ... / "t6"
  for (int i = 0; i < 32; i++) {
    if (strcmp(s, regs[i]) == 0) {
      *success = true;
      return (word_t)cpu.gpr[i];
    }
  }

  *success = false;
  return 0;
}
/*new functions*/
word_t csr_read(uint32_t addr) {
  addr &= 0xFFF;
  return cpu.csr[addr];
}

void csr_write(uint32_t addr, word_t data) {
  addr &= 0xFFF;
  cpu.csr[addr] = data;
}
