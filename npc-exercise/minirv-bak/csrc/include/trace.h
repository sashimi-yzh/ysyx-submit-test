#ifndef __TRACE_H__
#define __TRACE_H__
#include "common.h"
#include "mem.h"
#include "cpu.h"
#include "devices.h"
void mtrace(int addr, char wmask, int sdata);
void dtrace(int addr, bool isWrite, int data);
void itrace();
void trace_and_difftest();
void init_disasm();
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

#ifdef CONFIG_FTRACE_ENABLE
typedef struct {
  char name[64];
  uint32_t start_add;
  uint32_t size;
} symtab_t;

typedef struct {
    uint32_t src_pc;
    uint32_t dst_pc;
    symtab_t *dst_func;
} ftracer_t;

typedef struct {
    int depth;
    bool is_ftrace;
    int symtab_size;
    ftracer_t* stack;
} ftracer_stack_t;

int ftracer_push(ftracer_t stack);
void ftracer_pop();
void ftracer_write_log(char *s);

typedef struct {
    int depth;
    bool isCall;
    uint32_t pc;
    char name[64];
} ftracer_log_t;

typedef struct {
    int len;
    int alloc;
    char *buf;
} ftrace_log_t;
extern ftrace_log_t ftrace_log;
void func_trace(CPUState *s);

#define IN_FUNCRANGE(add,symtab) ((add>=symtab.start_add && add<symtab.start_add+symtab.size)?1:0)
#endif

#endif