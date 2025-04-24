#ifndef ARCH_H__
#define ARCH_H__

struct Context {
#ifdef __ICS_EXPORT
  // TODO: fix the order of these members to match trap.S
  uintptr_t esi, ebx, eax, eip, edx, eflags, ecx, cs, esp, edi, ebp;
  void *cr3;
  int irq;
#else
  void     *cr3;
  uintptr_t edi, esi, ebp, esp;
  uintptr_t ebx, edx, ecx, eax;      // Register saved by pushal
  int       irq;                     // # of irq
  uintptr_t eip, cs, eflags;         // Execution state before trap
  uintptr_t esp3, ss3;               // only defined when trapping from user
#endif
};

#define GPR1 eax
#ifdef __ICS_EXPORT
#define GPR2 eip
#define GPR3 eip
#define GPR4 eip
#define GPRx eip
#else
#define GPR2 ebx
#define GPR3 ecx
#define GPR4 edx
#define GPRx eax
#endif

#endif
