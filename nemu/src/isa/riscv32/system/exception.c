#include "../local-include/exception.h"
#include <cpu/cpu.h>

jmp_buf cpu_exception_env;

static bool cpu_exception_armed = false;
static cpu_exception_t cpu_exception = {};

void cpu_exception_begin(void) {
  cpu_exception_armed = true;
  cpu_exception = (cpu_exception_t){};
}

void cpu_exception_end(void) { cpu_exception_armed = false; }

bool cpu_exception_is_armed(void) { return cpu_exception_armed; }

const cpu_exception_t *cpu_exception_current(void) { return &cpu_exception; }

__attribute__((noreturn)) void cpu_throw_exception(word_t cause, word_t tval) {
  if (!cpu_exception_armed) {
    panic("synchronous exception outside isa_exec_once: cause=" FMT_WORD
          " tval=" FMT_WORD " pc=" FMT_WORD,
          cause, tval, cpu.pc);
  }

  cpu_exception.cause = cause;
  cpu_exception.epc = cpu.pc;
  cpu_exception.tval = tval;
  longjmp(cpu_exception_env, 1);
}
