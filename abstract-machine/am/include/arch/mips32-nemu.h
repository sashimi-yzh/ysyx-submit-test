#ifndef __ARCH_H__
#define __ARCH_H__

struct Context {
#ifdef __ICS_EXPORT
  // TODO: fix the order of these members to match trap.S
  uintptr_t hi, gpr[32], epc, cause, lo, status;
  void *pdir;
#else
  union {
    void *pdir;
    uint32_t gpr[32];
  };
  uint32_t lo, hi;
  uint32_t cause, status, epc;
#endif
};

#define GPR1 gpr[2] // v0
#ifdef __ICS_EXPORT
#define GPR2 gpr[0]
#define GPR3 gpr[0]
#define GPR4 gpr[0]
#define GPRx gpr[0]
#else
#define GPR2 gpr[4] // a0
#define GPR3 gpr[5] // a1
#define GPR4 gpr[6] // a2
#define GPRx gpr[2] // v0
#endif

#endif
