#ifndef __CPU_FTRACE_H__
#define __CPU_FTRECE_H__


int init_ftrace(const char *path);
void ftrace_call(vaddr_t pc, vaddr_t dnpc, uint32_t inst);
void ftrace_ret(uint32_t inst, vaddr_t pc);


#endif