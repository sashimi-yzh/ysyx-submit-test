#ifndef NPC_NPC
#define NPC_NPC

#include "tpdef.h"

// initialize npc resource
void npc_init(bool vcd, int argc, char** argv);

// execute npc steps
int cpu_exec(uint64_t steps);

// print regiestor
void reg_print();

// get regiestor value
word_t reg_get_value(char* s, bool* success);

// free npc resource
void npc_free();

// get reg values
void reg_value(word_t* regbuf);

// get reg 
const char* reg_name(int idx);

// runtime status
extern uint32_t npc_stat;

#define NPC_RUN     1
#define NPC_STOP    2
#define NPC_ABORT   3
#define NPC_END     4

#endif // NPC_NPC