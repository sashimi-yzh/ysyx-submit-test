#ifndef __ISA_H__
#define __ISA_H__

#include <isa-def.h>

typedef riscv32_CPU_state CPU_state;
typedef riscv32_ISADecodeInfo ISADecodeInfo;

#ifdef __cplusplus
extern "C" {
#endif

// monitor
void init_isa();
void init_ftrace(const char *elf_file);
void ftrace_call(vaddr_t pc, vaddr_t target);
void ftrace_ret(vaddr_t pc);

// reg
extern CPU_state cpu;
void isa_reg_display();
word_t isa_reg_str2val(const char *name, bool *success);

// difftest
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc);

#ifdef __cplusplus
}
#endif

#endif
