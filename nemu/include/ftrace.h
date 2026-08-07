#pragma once
#include <assert.h>
#include <elf.h>

typedef struct {
  uint32_t addr;
  uint32_t size;
  char name[128];
} FuncInfo;
void init_ftrace(const char *elf_path);
const char *find_func(uint32_t addr);
void ftrace_call(int call_depth, uint32_t addr, uint32_t pc);
void ftrace_return(int call_depth, uint32_t pc);