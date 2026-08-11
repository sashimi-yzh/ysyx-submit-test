#ifndef NPC_CPU_INTERFACE_H
#define NPC_CPU_INTERFACE_H

#include <isa.h>
#include <npc/base.h>

#define NPC_TRACE_BUFFER_SIZE 128

typedef struct {
  vaddr_t pc;
  ISADecodeInfo isa;
  IFDEF(CONFIG_ITRACE, char logbuf[NPC_TRACE_BUFFER_SIZE]);
} Decode;

NPC_EXTERN_C_BEGIN

void cpu_exec(uint64_t instruction_count);
bool cpu_take_commit(vaddr_t *pc, uint32_t *instruction);
void cpu_reset(vaddr_t reset_pc);

#if defined(CONFIG_DIFFTEST)
void difftest_step(vaddr_t pc, vaddr_t next_pc, uint32_t instruction);
#else
static inline void difftest_step(
    vaddr_t pc, vaddr_t next_pc, uint32_t instruction) {
  (void)pc;
  (void)next_pc;
  (void)instruction;
}
#endif

NPC_EXTERN_C_END

#endif
