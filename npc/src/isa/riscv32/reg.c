#include <isa.h>
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

#define NR_GPR ARRLEN(regs)

void isa_reg_display() {
  for (int i = 0; i < NR_GPR; i ++) {
    printf(ANSI_FG_RED"(x%02d) "ANSI_FG_GREEN"%-4s "ANSI_FG_BLUE"0x%08x\t"ANSI_NONE, i, regs[i], cpu.gpr[i]);
    if (i % 4 == 3) {
      printf("\n");
    }
  }
  printf("      "ANSI_FG_GREEN"PC   "ANSI_FG_BLUE"0x%08x\n"ANSI_NONE, cpu.pc);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  *success = true;
  if (strcmp(s, "$pc") == 0 || strcmp(s, "$PC") == 0) {
    return cpu.pc;
  }

  if (s[0] == '$' && s[1] == 'x') {
    int reg_idx = -1;
    if (sscanf(s + 2, "%d", &reg_idx) == 1) {
      if (reg_idx >= 0 && reg_idx < NR_GPR) {
        return cpu.gpr[reg_idx];
      }
    }
  }

  for (int i = 0; i < NR_GPR; i++) {
    if (s[0] == '$' && strcmp(s + 1, regs[i]) == 0) {
      return cpu.gpr[i];
    }
  }

  *success = false;
  return 0;
}
