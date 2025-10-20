#ifndef REG_H
#define REG_H

typedef struct diff_context_t {
  uint32_t gpr[32];
  uint32_t pc;
  uint32_t mtvec;
  uint32_t mepc;
  uint32_t mstatus;
  uint32_t mcause;
}diff_context_t;

void isa_reg_display();
bool isa_difftest_checkregs(diff_context_t *ref_r, vaddr_t pc);

#endif