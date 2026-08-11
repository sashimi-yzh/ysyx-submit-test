#ifndef NPC_ISA_H
#define NPC_ISA_H

#include <isa-def.h>

typedef riscv32_CPU_state CPU_state;
typedef riscv32_ISADecodeInfo ISADecodeInfo;

NPC_EXTERN_C_BEGIN

extern CPU_state cpu;

bool isa_difftest_checkregs(CPU_state *reference, vaddr_t pc);

word_t isa_reg_str2val(const char *name, bool *success);
void isa_reg_display();

void ftrace_trace(vaddr_t pc, uint32_t instruction, vaddr_t next_pc);
void init_ftrace(const char *elf_path);
void init_isa();

NPC_EXTERN_C_END

#endif
