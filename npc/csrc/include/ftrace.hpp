#ifndef __FTRACE_H__
#define __FTRACE_H__

#include <elf.h>
#include <stddef.h>

typedef struct {
  Elf32_Sym *symtab;   // 符号表
  char      *strtab;   // 字符串表
  size_t    symtab_size; // 符号表条目数
} ftrace_t;

extern ftrace_t ftrace_info;

const char *ftrace_find_func(uint32_t addr, uint32_t *func_start);
void init_elf();
void ftrace_detect(uint32_t inst, uint32_t pc, uint32_t npc);

#endif
