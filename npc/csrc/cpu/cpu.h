#ifndef __CPU_H__
#define __CPU_H__
#include<verilated.h>
#include"verilated_vcd_c.h"
#include "include/macro.h"
#ifdef USE_NVBOARD
#include<nvboard.h>
#endif
#define _MKSTR(s) #s
#define MKSTR(s) _MKSTR(s)
#include MKSTR(TOP_NAME.h)
#include MKSTR(concat(TOP_NAME,___024root.h))
extern TOP_NAME* dut;
extern VerilatedContext*contextp; 
extern VerilatedVcdC* tfp;
#ifdef RISCV32E_NPC
#define cpu_gpr(i)     dut->rootp->ysyx_26040117_SIM__DOT__cpu__DOT__Register1__DOT__rf[i]
#define DIDU_EXU_fire  dut->rootp->ysyx_26040117_SIM__DOT__cpu__DOT__IDU1__DOT__IDU_EXU_fire
#define DIDU_INST      dut->rootp->ysyx_26040117_SIM__DOT__cpu__DOT__IDU1__DOT__inst_out
#define DIDU_PC        dut->rootp->ysyx_26040117_SIM__DOT__cpu__DOT__IDU1__DOT__pc_out
#define DEXU_LSU_fire  dut->rootp->ysyx_26040117_SIM__DOT__cpu__DOT__EXU1__DOT__EXU_LSU_fire
#define DEXU_REDIRECT  dut->rootp->ysyx_26040117_SIM__DOT__cpu__DOT__EXU1__DOT__actual_taken
#define DEXU_AUX       dut->rootp->ysyx_26040117_SIM__DOT__cpu__DOT__EXU1__DOT__aux
#define DLSU_WBU_fire  dut->rootp->ysyx_26040117_SIM__DOT__cpu__DOT__LSU1__DOT__LSU_WBU_fire
#define DLSU_ADDR      dut->rootp->ysyx_26040117_SIM__DOT__cpu__DOT__LSU1__DOT__result
#define DLSU_ISMEM     dut->rootp->ysyx_26040117_SIM__DOT__cpu__DOT__LSU1__DOT__is_mem
#define DWBU_IFU_fire  dut->rootp->ysyx_26040117_SIM__DOT__cpu__DOT__WBU1__DOT__WBU_IFU_fire
#define DWBU_TRAP_INFO dut->rootp->ysyx_26040117_SIM__DOT__cpu__DOT__WBU1__DOT__trap_info
#define DWBU_CSR_ADDR  dut->rootp->ysyx_26040117_SIM__DOT__cpu__DOT__WBU1__DOT__csr_addr
#define DWBU_TRAP_DNPC dut->rootp->ysyx_26040117_SIM__DOT__cpu__DOT__WBU1__DOT__trap_dnpc


#else
#define cpu_gpr(i)     dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__Register1__DOT__rf[i]
#define DIDU_EXU_fire  dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__IDU1__DOT__IDU_EXU_fire
#define DIDU_INST      dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__IDU1__DOT__inst_out
#define DIDU_PC        dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__IDU1__DOT__pc_out
#define DEXU_LSU_fire  dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__EXU1__DOT__EXU_LSU_fire
#define DEXU_REDIRECT  dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__EXU1__DOT__actual_taken
#define DEXU_AUX       dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__EXU1__DOT__aux
#define DLSU_WBU_fire  dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__LSU1__DOT__LSU_WBU_fire
#define DLSU_ADDR      dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__LSU1__DOT__result
#define DLSU_ISMEM     dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__LSU1__DOT__is_mem
#define DWBU_IFU_fire  dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__WBU1__DOT__WBU_IFU_fire
#define DWBU_TRAP_INFO dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__WBU1__DOT__trap_info
#define DWBU_CSR_ADDR  dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__WBU1__DOT__csr_addr
#define DWBU_TRAP_DNPC dut->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__WBU1__DOT__trap_dnpc
#endif
extern uint32_t cpu_pc,cpu_dnpc;
enum NPC_STATE{NPC_RUNNING,NPC_END,NPC_STOP,NPC_QUIT,NPC_ABORT};
typedef struct{
    enum NPC_STATE state;
    int halt_ret;
    uint32_t halt_pc;
}NPC_state;
extern NPC_state npc_state;

typedef struct {           
    uint32_t gpr[32];
    uint32_t pc;
}CPU_state;
extern CPU_state cpu_dut;
void get_cpu_state(CPU_state *cpu_dut);
//difftest
extern "C" void difftest_skip_ref();
void init_difftest(const char *ref_so_file, long img_size);
void difftest_step(uint32_t pc, uint32_t npc);
//ftrace
#define MAX_FUNC_CNT 1024
typedef struct{
    char name[32];
    uint32_t low;
    uint32_t high;
}Func_list;
extern Func_list func_list[MAX_FUNC_CNT];
extern int func_cnt;
void ftrace_print();
//
typedef struct{
    uint32_t pc,inst,dnpc;
    int skip_ref;
}Debug_info;

//
extern "C" void npc_trap();
int is_exit_status_bad();
void reset(int n);
void cpu_exec(uint64_t n); 
#endif
