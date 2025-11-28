#ifndef __CPU_H__
#define __CPU_H__

#include <isa.h>
#include <common.h>

#define NPCTRAP(thispc, code) set_npc_state(NPC_END, thispc, code)

typedef struct Decode {
    vaddr_t pc;
    vaddr_t snpc; // static next pc
    vaddr_t dnpc; // dynamic next pc
    uint32_t inst; // instruction

} Decode;


void init_cpu(int argc ,char** argv);
int cpu_exec(uint64_t n);
void free_cpu();
void set_npc_state(int state, vaddr_t pc, int halt_ret);
void isa_reg_display();
void init_itrace();
#endif