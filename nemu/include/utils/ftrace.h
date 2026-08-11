#ifndef __FTRACE_H__
#define __FTRACE_H__

#include <stdint.h>
#include <stdbool.h>

void ftrace_init(const char *elf_file);
void ftrace_trace(uint32_t pc, uint32_t inst, uint32_t dnpc);

#endif