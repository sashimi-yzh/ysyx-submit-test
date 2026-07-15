#ifndef __FTRACE_H__
#define __FTRACE_H__

#include <common.h>
#include <elf.h>

typedef struct {
  Elf32_Sym *symtab;   // 符号表
  char      *strtab;   // 字符串表
  size_t     symtab_size; // 符号表条目数
} ftrace_t;

extern ftrace_t ftrace_info;

/* 根据地址查找所属函数，返回函数名指针，并通过 func_start 返回函数起始地址 */
const char *ftrace_find_func(vaddr_t addr, vaddr_t *func_start);

#endif
