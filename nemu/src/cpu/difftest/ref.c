#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>
#include <string.h>
#include <assert.h>

typedef struct {
  word_t gpr[32];
  vaddr_t pc;
  word_t mstatus;
  word_t mtvec;
  word_t mepc;
  word_t mcause;
  word_t satp;
} difftest_regs_t;

#define DIFFTEST_CSR_SATP 0x180

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if (direction == DIFFTEST_TO_REF) {
    memcpy(guest_to_host(addr), buf, n);
  } else {
    memcpy(buf, guest_to_host(addr), n);
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  difftest_regs_t *r = (difftest_regs_t *)dut;

  if (direction == DIFFTEST_TO_REF) {
    for (int i = 0; i < 32; i++) {
      cpu.gpr[i] = r->gpr[i];
    }
    cpu.pc = r->pc;
    cpu.csr[CSR_MSTATUS] = r->mstatus;
    cpu.csr[CSR_MTVEC] = r->mtvec;
    cpu.csr[CSR_MEPC] = r->mepc;
    cpu.csr[CSR_MCAUSE] = r->mcause;
    cpu.csr[DIFFTEST_CSR_SATP] = r->satp;
  } else {
    for (int i = 0; i < 32; i++) {
      r->gpr[i] = cpu.gpr[i];
    }
    r->pc = cpu.pc;
    r->mstatus = cpu.csr[CSR_MSTATUS];
    r->mtvec = cpu.csr[CSR_MTVEC];
    r->mepc = cpu.csr[CSR_MEPC];
    r->mcause = cpu.csr[CSR_MCAUSE];
    r->satp = cpu.csr[DIFFTEST_CSR_SATP];
  }
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  cpu.pc = isa_raise_intr(NO, cpu.pc);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  init_isa();
}
/*
 * NPC uses this exported hook to confirm that the reference model was
 * built with the ysyxSoC physical address map.  The map is selected at
 * compile time by CONFIG_YSYXSOC_DIFFTEST/CONFIG_YSYXSOC_ADDRSPACE, so
 * enabling the hook itself does not change normal NEMU execution.
 */
#if defined(CONFIG_TARGET_SHARE) && defined(CONFIG_YSYXSOC_DIFFTEST)
__EXPORT void difftest_enable_ysyxsoc_paddr(void) {}
#endif
