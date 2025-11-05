#ifndef __REG_H_
#define __REG_H_
#include <stdint.h>
#include <common.h>
// #include <string.h>
#include <verilator.h>

extern word_t reg0;


void isa_reg_display();

void print_regs_info();

static inline int check_reg_idx(int idx){
        if (idx < 0 || idx >= MUXDEF(CONFIG_RVE,16,32))
        {
                printf("Invalid register index %d\n", idx);
                assert(0);
        }
        return idx;
}
#ifdef DONT_USE_REG0
#define gpr(idx) (idx == 0 ? reg0 : REGS[check_reg_idx(idx) - 1])
#else
#define gpr(idx) REGS[check_reg_idx(idx)]
#endif

static inline const char* reg_name(int idx) {
  extern const char* regs[];
  return regs[check_reg_idx(idx)];
}

#endif 
