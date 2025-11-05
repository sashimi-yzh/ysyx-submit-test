#ifndef __INST_H_
#define __INST_H_

#include <verilator.h>
#include <common.h>

long load_img();
void print_inst(word_t pc);
void print_all_insts();
#endif // ! __INST_H_
