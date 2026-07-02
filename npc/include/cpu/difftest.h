#ifndef __CPU_DIFFTEST_H__
#define __CPU_DIFFTEST_H__

#include <common.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_DIFFTEST
void difftest_step(vaddr_t pc, vaddr_t dnpc, uint32_t inst);
#else
static inline void difftest_step(vaddr_t pc, vaddr_t dnpc, uint32_t inst) {
  (void)pc;
  (void)dnpc;
  (void)inst;
}
#endif

#ifdef __cplusplus
}
#endif

#endif
