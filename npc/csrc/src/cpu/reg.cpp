#include "common.h"
#include "cpu.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void reg_display() {
  word_t val;
  printf(
    MUXDEF(RV64, "%-3s %-18s %-20s %-20s\n", "%-3s %-10s %-12s %-12s\n"),
    "Reg", "Hex", "Unsigned dec", "Signed dec"
  );
  for (int i = 0; i < MUXDEF(RVE, 16, 32); ++i) {
    val = gpr(i);
    printf(
      MUXDEF(RV64, "%-3s 0x%-16llx %-20llu %-20lld\n", "%-3s 0x%-8x %-12u %-12d\n"),
      reg_name(i), val, val, val
    );
  }
}

word_t reg_str2val(const char *s, bool *success) {
  if (strcmp(s, "pc") == 0) {
    *success = true;
    return cpu_pc;
  }
  for (int i = 0; i < MUXDEF(RVE, 16, 32); ++i) {
    if (strcmp(s, regs[i])) continue;
    *success = true;
    return gpr(i);
  }
  *success = false;
  return -1;
}
