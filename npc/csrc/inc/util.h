#ifndef NPC_DISASM
#define NPC_DISASM

#include "tpdef.h"

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

// initialize disassemble
void init_disasm();

// disassemble
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

// initialize ftrace elf struct
bool init_elf(const char* elf_file);

// initialize DiffTest
void init_difftest(long img_size, int port);

// difftest step
bool difftest_step(uint32_t pc);

// difftest nop
void difftest_nop(word_t pc);

// cachesim 
bool cachesim_run(int cache_ls, int block_ls);

#endif // NPC_DISASM