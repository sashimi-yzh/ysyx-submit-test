#ifndef __CPU_H__
#define __CPU_H__
#include "common.h"
enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT } NPCState;

typedef struct{
    uint32_t pc;
    uint32_t dnpc;
    uint32_t halt_ret;
    uint32_t count;
    uint32_t inst;
    int state;
    uint32_t gpr[CONFIG_GPR_NUM];
    char logbuf[128];
}CPUState;
extern CPUState cpu;

uint32_t reg_str2val(const char *s, bool *success);
void reg_display(CPUState cpu);
void cpu_exec(uint64_t n);
#endif