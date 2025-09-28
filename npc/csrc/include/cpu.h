#ifndef __CPU_H__
#define __CPU_H__

#include "common.h"

#include "driver.h"
#ifdef YSYXSOC
#include "VysyxSoCFull_ysyx_23060203_GPR.h"
#else
#include "Vysyx_23060203_ysyx_23060203_GPR.h"
#endif

void cpu_init();
void cpu_exec(uint64_t n);

static inline int check_reg_idx(int idx) {
  Assert(idx >= 0 && idx < MUXDEF(RVE, 16, 32), "Accessing invalid register: x%d", idx);
  return idx;
}

#define gpr(idx) (idx ? cpu_module->GPR->r[check_reg_idx(idx) - 1] : 0)
extern addr_t cpu_pc;

static inline const char *reg_name(int idx) {
  extern const char* regs[];
  return regs[check_reg_idx(idx)];
}

void reg_display();
word_t reg_str2val(const char *s, bool *success);

#endif
