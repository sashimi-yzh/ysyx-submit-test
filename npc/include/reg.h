#ifndef __RISCV_REG_H__
#define __RISCV_REG_H__

#include "common.h"

void regs_display();
word_t single_reg_display(char *reg_name);
word_t reg_str2val(const char *s, bool *success); 
word_t isa_reg_str2val(const char *s);
#endif
