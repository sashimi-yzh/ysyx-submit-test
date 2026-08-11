#include <stdio.h>

#include <isa.h>
#include <npc/cpu.h>
#include <npc/runtime.h>
#include "../local-include/reg.h"

static bool check_word(
    const char *name, word_t reference, word_t actual, vaddr_t pc) {
  if (reference == actual) return true;
  printf("register mismatch at pc = " FMT_WORD
      ": %s mismatch, ref = " FMT_WORD ", dut = " FMT_WORD "\n",
      pc, name, reference, actual);
  return false;
}

static bool check_register_file(const CPU_state *reference, vaddr_t pc) {
  for (int index = 0; index < ARRLEN(cpu.gpr); index ++) {
    if (reference->gpr[index] == cpu.gpr[index]) continue;
    printf("register mismatch at pc = " FMT_WORD
        ": gpr[%d] mismatch, ref = " FMT_WORD ", dut = " FMT_WORD "\n",
        pc, index, reference->gpr[index], cpu.gpr[index]);
    return false;
  }
  return true;
}

static bool check_control_state(const CPU_state *reference, vaddr_t pc) {
  return check_word("pc", reference->pc, cpu.pc, pc)
      && check_word("mstatus", reference->mstatus, cpu.mstatus, pc)
      && check_word("mtvec", reference->mtvec, cpu.mtvec, pc)
      && check_word("mepc", reference->mepc, cpu.mepc, pc)
      && check_word("mcause", reference->mcause, cpu.mcause, pc)
      && check_word("satp", reference->satp, cpu.satp, pc);
}

bool isa_difftest_checkregs(CPU_state *reference, vaddr_t pc) {
  return check_register_file(reference, pc)
      && check_control_state(reference, pc);
}
