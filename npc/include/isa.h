#ifndef ISA_H
#define ISA_H

#include "common.h"

extern word_t *regs;
extern paddr_t *pc;
extern bool* write_back;
extern const char *regs_name[];

word_t isa_reg_str2val(const char *reg_name);

void isa_reg_display();

#endif