#ifndef ARCH_H__
#define ARCH_H__

#ifdef __riscv_e
#define NR_REGS 16
#else
#define NR_REGS 32
#endif

struct Context {
#ifdef __ICS_EXPORT
  // TODO: fix the order of these members to match trap.S
  uintptr_t mepc, mcause, gpr[NR_REGS], mstatus;
  void *pdir;
#else
  union {
    void *pdir;
#ifdef __riscv_e
    uintptr_t gpr[16];
#else
    uintptr_t gpr[32];
#endif
  };
  uintptr_t mcause;
  uintptr_t mstatus;
  uintptr_t mepc;
  uintptr_t np;  // next privilege
#endif
};

#ifdef __riscv_e
#define GPR1 gpr[15] // a5
#else
#define GPR1 gpr[17] // a7
#endif

#ifdef __ICS_EXPORT
#define GPR2 gpr[0]
#define GPR3 gpr[0]
#define GPR4 gpr[0]
#define GPRx gpr[0]
#else
#define GPR2 gpr[10] // a0
#define GPR3 gpr[11] // a1
#define GPR4 gpr[12] // a2
#define GPRx gpr[10] // a0
#endif

#endif
