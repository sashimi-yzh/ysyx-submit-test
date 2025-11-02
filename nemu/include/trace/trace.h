#ifndef TRACE_H
#define TRACE_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <generated/autoconf.h>

//in ftrace.c
typedef struct {
    uint32_t value;
    uint32_t size;
    char name[64];  // 存储完整的函数名
} FUNC;

int parse_symtab_entries(int symtab_size, char *symtab, int strtab_size, char *strtab, FUNC *funcs);
void init_ftrace(const char* file_path);
void check_pc(int32_t pc, bool *success, uint32_t *value, char **func_name);
void ftrace_record(int32_t pc);
void display_ftrace();


//in mtrace.c
void mtrace_record(int32_t pc, int32_t addr, int32_t inst);
void display_mtrace();

//in itrace.c
void itrace_record(int32_t pc, int32_t inst);
void display_itrace();

//in dtrace.c
typedef struct {
    uint32_t dtrace_pc;
	uint32_t dtrace_inst;
	uint32_t dtrace_addr;
    char dtrace_device[64];  // 存储完整的函数名
} dtrace;

void dtrace_record(int32_t pc, int32_t inst, int32_t addr, const char* name);
void display_dtrace();


//in etrace.cpp
void etrace_record(int32_t pc);
void display_etrace();


#endif
