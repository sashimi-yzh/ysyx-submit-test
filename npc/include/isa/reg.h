#ifndef __RISCV_REG_H__
#define __RISCV_REG_H__

#include <common.h>

// extern VerilatedContext* contextp;
// extern VerilatedVcdC* tfp;
// extern Vysyx_25020042* top;

static inline int check_reg_idx(int idx) {
  assert(idx >= 0 && idx < 16);
  return idx;
}

static inline uint32_t get_register_value (int idx) {
  #ifdef PLATFORM_YSYXSOC
  switch (idx) {
    case 0: return 0;
    // case 0: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__zero;
    case 1: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__ra;
    case 2: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__sp;
    case 3: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__gp;
    case 4: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__tp;
    case 5: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__t0;
    case 6: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__t1; 
    case 7: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__t2;
    case 8: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__s0;
    case 9: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__s1;
    case 10: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__a0;
    case 11: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__a1;
    case 12: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__a2;
    case 13: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__a3;
    case 14: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__a4;
    case 15: return top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr_u__DOT__a5;
    default: return 0;
  }

  #else
  switch (idx) {
    case 0: return 0;
    // case 0: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__zero;
    case 1: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__ra;
    case 2: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__sp;
    case 3: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__gp;
    case 4: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__tp;
    case 5: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__t0;
    case 6: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__t1;
    case 7: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__t2;
    case 8: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__s0;
    case 9: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__s1;
    case 10: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__a0;
    case 11: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__a1;
    case 12: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__a2;
    case 13: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__a3;
    case 14: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__a4;
    case 15: return top->rootp->ysyx_25020042__DOT__gpr_u__DOT__a5;
    default: return 0;
  }
  #endif
}

#ifdef PLATFORM_YSYXSOC
#define _mstatus_data_ 0x1800
// #define _mstatus_data_ top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr_u__DOT__mstatus
#define _mtvec_data_ top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr_u__DOT__mtvec
#define _mepc_data_ top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr_u__DOT__mepc
#define _mcause_data_ top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr_u__DOT__mcause

#else
#define _mstatus_data_ 0x1800
// #define _mstatus_data_ top->rootp->ysyx_25020042__DOT__csr_u__DOT__mstatus
#define _mtvec_data_ top->rootp->ysyx_25020042__DOT__csr_u__DOT__mtvec
#define _mepc_data_ top->rootp->ysyx_25020042__DOT__csr_u__DOT__mepc
#define _mcause_data_ top->rootp->ysyx_25020042__DOT__csr_u__DOT__mcause
#endif


#define gpr(idx) (get_register_value(check_reg_idx(idx)))


static inline const char* reg_name(int idx) {
  extern const char* regs[];
  return regs[check_reg_idx(idx)];
}

#endif