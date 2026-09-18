#ifndef __NPC_H__
#define __NPC_H__

#include <common.h>
#include <arpa/inet.h> 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <nvboard.h>
#include "verilated.h"

#ifdef CONFIG_SOC
#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"
#define CPU_PC()    (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_wbu_pc) // commit pc
#define CPU_DNPC()  (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_wbu_dnpc) // dnpc
#define CPU_INST()  (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_wbu_inst)
#define CPU_REG_W() (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_wbu_reg_w)
#define CPU_VALID() (exu_valid)  // = lsu_wbu_valid (提交有效), 由 get_cpu_state 每拍更新
#else
#include "Vtop.h"
#include "Vtop___024root.h"
#define CPU_PC()    (top->rootp->top__DOT__my_cpu__DOT__lsu_wbu_pc) // commit pc
#define CPU_DNPC()  (top->rootp->top__DOT__my_cpu__DOT__lsu_wbu_dnpc) // dnpc
#define CPU_INST()  (top->rootp->top__DOT__my_cpu__DOT__lsu_wbu_inst)
#define CPU_REG_W() (top->rootp->top__DOT__my_cpu__DOT__lsu_wbu_reg_w)
#define CPU_VALID() (exu_valid)  // = lsu_wbu_valid (提交有效), 由 get_cpu_state 每拍更新
#endif

#include "verilated_fst_c.h"

#define PC_START MUXDEF(CONFIG_SOC, 0x30000000, 0x80000000)

//state
enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT , NPC_QUIT };

typedef struct {
  int state;
  uint32_t halt_pc;
} NPCState;

typedef struct {
  uint32_t gpr[32];
  uint32_t pc;

  //CSRs
  uint32_t mstatus;
  uint32_t mtvec;
  uint32_t mepc;
  uint32_t mcause;
} CPU_state;

extern uint32_t mvendorid;
extern uint32_t marchid;

extern NPCState npc_state;
extern CPU_state cpu_n;
extern int exu_valid;
extern uint32_t total_inst;

//log
void init_log(const char *log_file);

int is_exit_status_bad();

//verilator
extern VerilatedFstC* tfp;

#ifdef CONFIG_SOC
extern VysyxSoCFull* top;
#else
extern Vtop* top;
#endif

void itrace_record(int pc, int inst);
void itrace_dump(int n);
void init_disasm();

//exec
void sim_init(int argc, char *argv[]);
void sim_exit();
void init_sdb();

void sdb_mainloop();
void cpu_exec(uint64_t n);
 

//reg
void isa_reg_display();
word_t isa_reg_str2val(const char *s, bool *success);

static inline const char* reg_name(int idx) {
  extern const char* regs[];
  return regs[idx];
}

//difftest
void init_difftest(const char *ref_so_file, long img_size);
void check_difftest();
void difftest_skip_ref();
bool in_soc_device (uint32_t addr);
void check_device();
// void difftest_skip_dut(int nr_ref, int nr_dut);

#endif
