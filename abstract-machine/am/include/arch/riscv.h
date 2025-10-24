#ifndef ARCH_H__
#define ARCH_H__

#ifdef __riscv_e
#define NR_REGS 16
#else
#define NR_REGS 32
#endif

struct Context {
  // TODO: fix the order of these members to match trap.S
  //通过观察trap.S文件中的__am_asm_trap函数，上下文先存储32位通用寄存器再存储CSR寄存器
  // uintptr_t mepc, mcause, gpr[NR_REGS], mstatus;
  // void *pdir;

  uintptr_t gpr[NR_REGS]; // general purpose registers
  uintptr_t mcause,mstatus,mepc;
  void *pdir; // page directory
};

#ifdef __riscv_e
#define GPR1 gpr[15] // a5
#else
#define GPR1 gpr[17] // a7
#endif

#define GPR2 gpr[0]
#define GPR3 gpr[0]
#define GPR4 gpr[0]
#define GPRx gpr[0]

#endif
