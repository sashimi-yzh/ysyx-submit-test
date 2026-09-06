#ifndef RISCV32_EXCEPTION_H__
#define RISCV32_EXCEPTION_H__

#include <common.h>
#include <setjmp.h>

typedef struct {
  word_t cause;
  vaddr_t epc;
  word_t tval;
} cpu_exception_t;

extern jmp_buf cpu_exception_env;

void cpu_exception_begin(void);
void cpu_exception_end(void);
bool cpu_exception_is_armed(void);
const cpu_exception_t *cpu_exception_current(void);
__attribute__((noreturn)) void cpu_throw_exception(word_t cause, word_t tval);

#endif
