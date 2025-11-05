#ifndef __CPU_H_
#define __CPU_H_


#include <common.h>


void cpu_exec(uint64_t n);
void print_iringbuf();
void set_npc_state(int state, vaddr_t pc, int halt_ret);
void invalid_inst(vaddr_t thispc);


void cpu_eval_dump();
void cpu_single_cycle();
void cpu_reset(int n);

#define NPCTRAP(thispc, code) set_npc_state(NPC_END, thispc, code)


#endif 