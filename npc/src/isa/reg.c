#include <npc.h>
#include <common.h>

uint32_t R[31] = {};

extern "C" void get_reg(int waddr, int data) {
  R[waddr] = data;
  cpu_n.gpr[waddr] = data;
}

extern "C" void get_csr(int csr, int data) {
  switch (csr) {
    case 0xF11: return;  // mvendorid
    case 0xF12: return;  // marchid
    case 0x300: cpu_n.mstatus = data; return;
    case 0x305: cpu_n.mtvec = data; return;
    case 0x341: cpu_n.mepc = data; return;
    case 0x342:
      cpu_n.mcause = data;
      IFDEF(CONFIG_ETRACE,
        if (data == 11) log_write("[etrace] ecall at pc = 0x%08x, mepc = 0x%08x\n", CPU_PC(), cpu_n.mepc);
      );
      return;
    default: { Log("write unsupported csr addr = 0x%03x", csr); assert(0); }
  }
}

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
  printf("pc: 0x%08X\n", CPU_PC());
  for (int i = 0; i <= 31; i += 8) {
    printf("%s: 0x%08X  ", regs[i], R[i]);
    if (i == 31) { printf("\n"); break; }
    if (i > 23)  { i -= 31; printf("\n"); }
  }
}

word_t isa_reg_str2val(const char *s, bool *success) {
  *success = false;
  for (int i = 0; i < 32; i ++) {
    if (strcmp(regs[i], s) == 0) {
      *success = true;
      return R[i];
    }
    else if (strcmp("pc", s) == 0) {
      *success = true;
      return CPU_PC();
    }
  }
  printf("no this reg!\n");
  return 0;
}

