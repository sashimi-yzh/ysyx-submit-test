#include <isa.h>

extern uint64_t cycle_value();

const char *regs[] = {"$0", "ra", "sp",  "gp",  "tp", "t0", "t1", "t2",
                      "s0", "s1", "a0",  "a1",  "a2", "a3", "a4", "a5",
                      "a6", "a7", "s2",  "s3",  "s4", "s5", "s6", "s7",
                      "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

void isa_reg_display() {
  int i;
  for (i = 0; i < NR_REG; i++) {
    printf("%-8s 0x%.8x       %u\n", regs[i], cpu.gpr[i], cpu.gpr[i]);
  }
}

word_t isa_reg_str2val(const char *s, bool *success) {

  word_t val = 1;
  int i;

  if (strcmp(s, "pc") == 0) {
    val = cpu.pc;
    *success = true;
  } else if (strcmp(s, "cycle") == 0) {
    val = cycle_value();
    *success = true;
  } else {
    for (i = 0; i < NR_REG; i++) {
      if (strcmp(s, regs[i]) == 0) {
        val = cpu.gpr[i];
        *success = true;
        break;
      }
    }
  }

  return val;
}

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  int eq = true;
  for (int i = 0; i < NR_REG; i++) {
    if (ref_r->gpr[i] != cpu.gpr[i]) {
      printf(ANSI_FMT("Difftest wrong: %s at 0x%.8x\n", ANSI_FG_RED), regs[i], pc);
      printf("ref = 0x%.8x   dut = 0x%.8x\n", ref_r->gpr[i], cpu.gpr[i]);
      eq = false;
      break;
    }
  }
  if (ref_r->csr[MSTATUS] != cpu.csr[MSTATUS]) {
    printf(ANSI_FMT("Difftest wrong: mstatus at 0x%.8x\n", ANSI_FG_RED), pc);
    printf("ref = 0x%.8x   dut = 0x%.8x\n", ref_r->csr[MSTATUS], cpu.csr[MSTATUS]);
    eq = false;
  }
  if (ref_r->csr[MTVEC] != cpu.csr[MTVEC]) {
    printf(ANSI_FMT("Difftest wrong: mtvec at 0x%.8x\n", ANSI_FG_RED), pc);
    printf("ref = 0x%.8x   dut = 0x%.8x\n", ref_r->csr[MTVEC], cpu.csr[MTVEC]);
    eq = false;
  }
  if (ref_r->csr[MEPC] != cpu.csr[MEPC]) {
    printf(ANSI_FMT("Difftest wrong: mepc at 0x%.8x\n", ANSI_FG_RED), pc);
    printf("ref = 0x%.8x   dut = 0x%.8x\n", ref_r->csr[MEPC], cpu.csr[MEPC]);
    eq = false;
  }
  if (ref_r->csr[MCAUSE] != cpu.csr[MCAUSE]) {
    printf(ANSI_FMT("Difftest wrong: mcause at 0x%.8x\n", ANSI_FG_RED), pc);
    printf("ref = 0x%.8x   dut = 0x%.8x\n", ref_r->csr[MCAUSE], cpu.csr[MCAUSE]);
    eq = false;
  }
  if (ref_r->pc != cpu.pc) {
    printf(ANSI_FMT("Difftest wrong: inst.pc = 0x%.8x\n", ANSI_FG_RED), pc);
    printf("ref.npc = 0x%.8x   dut.npc = 0x%.8x\n", ref_r->pc, cpu.pc);
    eq = false;
  }
  return eq;
}
