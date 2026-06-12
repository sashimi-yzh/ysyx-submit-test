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

#include "local-include/reg.h"
#include "common.h"
#include "debug.h"
#include <errno.h>
#include <isa.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *regs[] = {"$0", "ra", "sp",  "gp",  "tp", "t0", "t1", "t2",
                      "s0", "s1", "a0",  "a1",  "a2", "a3", "a4", "a5",
                      "a6", "a7", "s2",  "s3",  "s4", "s5", "s6", "s7",
                      "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

const char *csrs_name[NR_CSR] = {"mstatus", "mtvec", "mepc", "mcause"};

#define safe_deref(ptr, ...) do { if (ptr) { *ptr = (__VA_ARGS__); } } while(0)

bool isa_try_find_reg(int regno, void **reg, size_t *len) {
  if (regno >=0 && regno < LENGTH(cpu.gpr)) {
    safe_deref(reg, cpu.gpr + regno);
    safe_deref(len, MUXDEF(CONFIG_ISA64, 8, 4));
    return true;
  }
  switch (regno) {
    case LENGTH(cpu.gpr):
      safe_deref(reg, &cpu.pc);
      safe_deref(len, MUXDEF(CONFIG_ISA64, 8, 4));
      return true;
  }
  return false;
}

bool isa_try_read_reg(int regno, void *dest) {
  if (!dest) {
    return false;
  }
  void *reg;
  size_t len;
  bool success = isa_try_find_reg(regno, &reg, &len);
  if (success) {
    memcpy(dest, reg, len);
  }
  return success;
}

bool isa_try_write_reg(int regno, const void *src) {
  if (!src) {
    return false;
  }
  void *reg;
  size_t len;
  bool success = isa_try_find_reg(regno, &reg, &len);
  if (success) {
    memcpy(reg, src, len);
  }
  return success;
}

void isa_reg_display() {
  int i;
  for (i = 0; i < LENGTH(cpu.gpr); i++) {
    if (gpr(i))
      printf("%2d (%3s)  " FMT_WORD "\n", i, regs[i], gpr(i));
    else
      printf("%2d (%3s)  " ANSI_FG_DARK FMT_WORD ANSI_NONE "\n", i, regs[i],
             gpr(i));
  }
  printf("\n");
  printf("pc: " FMT_WORD "\n", cpu.pc);
  printf("\n");
  for (i = 0; i < NR_CSR; i++) {
    printf("%s: " FMT_WORD "\n", csrs_name[i], cpu.csr[i]);
  }
}

word_t isa_reg_str2val(const char *s, bool *success) {
  // pc
  if (strcmp(s, "$pc") == 0) {
    return cpu.pc;
  }

  // gpr(abi)
  int gpr_max = LENGTH(cpu.gpr);
  int i;
  for (i = 0; i < gpr_max; i++) {
    if (strcmp(s + 1, regs[i]) == 0) {
      Log("read from name(%s): Reg %d", s + 1, i);
      return cpu.gpr[i];
    }
  }

  // csr
  for (i = 0; i < NR_CSR; i++) {
    if (strcmp(s + 1, csrs_name[i]) == 0) {
      Log("read from name(%s): CSR %d", s, i);
      return cpu.csr[i];
    }
  }

  // gpr(idx)
  char *endptr = NULL;
  errno = 0;
  word_t val = strtol(s + 1, &endptr, 10);
  Log("read from index(%s): Reg %d", s + 1, val);
  if (errno != 0) {
    perror("");
    Log("reg name parse error");
    *success = false;
    return 0;
  }
  if (*endptr != '\0') {
    Log("exist invalid str in reg name");
    *success = false;
    return 0;
  }
  if (val >= 0 && val < gpr_max) {
    return cpu.gpr[val];
  } else {
    *success = false;
    return 0;
  }
}
