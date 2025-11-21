#include "../include/common.h"
#include "../include/reg.h"

#ifdef CONFIG_YSYXSOC
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull.h"
extern VysyxSoCFull *top;
#define dut_pc top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__diff_pc
#define dut_gpr top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu_cpu__DOT__regs
#define dut_mtvec top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu_cpu__DOT__mtvec
#define dut_mepc top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu_cpu__DOT__mepc
#define dut_mcause top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu_cpu__DOT__mcause
#define dut_mstatus top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu_cpu__DOT__mstatus
#else
#include "Vysyx_25020037_npc___024root.h"
#include "Vysyx_25020037_npc.h"
extern Vysyx_25020037_npc *top;
#define dut_pc top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__pc
#define dut_gpr top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__wbu_cpu__DOT__regs
#define dut_mtvec top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__wbu_cpu__DOT__mtvec
#define dut_mepc top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__wbu_cpu__DOT__mepc
#define dut_mcause top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__wbu_cpu__DOT__mcause
#define dut_mstatus top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__wbu_cpu__DOT__mstatus
#endif

bool isa_difftest_checkregs(diff_context_t *ref_r, vaddr_t pc) {

  for (int i = 1; i < 16; i++) {
    if (ref_r->gpr[i] != dut_gpr[i]) {
      printf("dut->reg[%d]: 0x%08x != ref->gpr[%d]: 0x%08x\n", i, dut_gpr[i], i, ref_r->gpr[i]);
      return false;
    }
  }
  // if (ref_r->pc != dut_pc+4) {
  //   printf("dut->pc: 0x%08x != ref->pc: 0x%08x\n", dut_pc+4, ref_r->pc);
  //   return false;
  // }
  if (ref_r->mtvec != dut_mtvec) {
    printf("dut->mtvec: 0x%08x != ref->mtvec: 0x%08x\n", dut_mtvec, ref_r->mtvec);
    return false;
  }
  if (ref_r->mepc != dut_mepc) {
    printf("dut->mepc: 0x%08x != ref->mepc: 0x%08x\n", dut_mepc, ref_r->mepc);
    return false;
  }
  if (ref_r->mcause != dut_mcause) {
    printf("dut->mepc: 0x%08x != ref->mepc: 0x%08x\n", dut_mcause, ref_r->mcause);
    return false;
  }
  if (ref_r->mstatus != dut_mstatus) {
    printf("dut->mstatus: 0x%08x != ref->mstatus: 0x%08x\n", dut_mstatus, ref_r->mstatus);
    return false;
  }
  return true;
}
