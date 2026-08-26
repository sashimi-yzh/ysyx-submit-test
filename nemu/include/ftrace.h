#ifndef __FTRACE__
#define __FTRACE__
#include <common.h>
#include <cpu/decode.h>
typedef struct {
  char name[128];
  vaddr_t start_add;
  vaddr_t size;
} symtab_t;

typedef struct {
    vaddr_t src_pc;
    vaddr_t dst_pc;
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
    vaddr_t pc;
    char name[128];
} ftracer_log_t;

typedef struct {
    int len;
    int alloc;
    char *buf;
} ftrace_log_t;

void func_trace(Decode *s);

#define IN_FUNCRANGE(add,symtab) ((add>=symtab.start_add && add<symtab.start_add+symtab.size)?1:0)

#endif