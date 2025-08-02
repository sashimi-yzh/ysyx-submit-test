#ifndef __ITRACE_H__
#define __ITRACE_H__

#include <common.h>

void trace_inst(word_t pc, uint32_t inst);
IFDEF(CONFIG_ITRACE, void display_inst(););
void trace_func_call(paddr_t pc, paddr_t target);
void trace_func_ret(paddr_t pc);

#endif