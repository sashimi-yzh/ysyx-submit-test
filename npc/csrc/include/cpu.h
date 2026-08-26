#ifndef __CPU_H__
#define __CPU_H__
#include "common.h"
enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT } NPCState;

typedef struct{
    uint32_t pc;
    uint32_t dnpc;
    uint32_t halt_ret;
    uint64_t count;
    
    uint8_t ifu_state;
    uint8_t ifu_state_last;
    uint8_t lsu_state;
    uint8_t wbu_state;
    uint8_t wbu_final;
    uint8_t idu_state;
    uint32_t mem_access_addr;
    int state;
    uint32_t gpr[CONFIG_GPR_NUM];
    char logbuf[128];

    uint32_t inst;
    uint64_t counter_inst;
    uint64_t counter_cycle;
    uint64_t counter_flush;
    uint64_t counter_raw;


    uint64_t counter_IFU_ichache_hit;
    uint64_t counter_IFU_get_inst;
    uint64_t counter_IFU_get_inst_cyc;
    uint64_t counter_IFU_get_inst_miss_cyc;

    // uint64_t counter_EXU_calc;
    // uint64_t counter_EXU_calc_cyc;
    // uint64_t counter_EXU_csr;
    // uint64_t counter_EXU_csr_cyc;
    
    uint64_t counter_LSU_mem;
    // uint64_t counter_LSU_mem_cyc;
    uint64_t counter_LSU_load_cyc;
    uint64_t counter_LSU_store_cyc;
    uint64_t counter_LSU_get_data;
    uint64_t counter_LSU_put_data;
    
    uint32_t ifu_pc;bool ifu_valid;
    uint32_t idu_pc;bool idu_valid;
    uint32_t exu_pc;bool exu_valid;
    uint32_t lsu_pc;bool lsu_valid;
    uint32_t wbu_pc;bool wbu_valid;
    uint32_t isRAW,tb_isMEM;
    uint32_t tb_FINAL_pc;bool tb_isFINAL;
    uint32_t tb_FINAL_npc;bool tb_dnpc_valid;
    uint32_t tb_FINAL_inst;
    
}CPUState;
extern CPUState cpu;

uint32_t reg_str2val(const char *s, bool *success);
void reg_display(CPUState cpu);
void cpu_exec(uint64_t n);
#endif