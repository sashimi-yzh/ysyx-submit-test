#ifndef __FTRACE_H_
#define __FTRACE_H_

#include <stdbool.h>
#include <common.h>


void ftrace_init(const char* _img_file);
void ftrace_func_call(word_t pc, word_t dnpc, uint32_t inst);
void ftrace_func_ret(word_t pc, uint32_t inst);
void ftrace_func_call_list_print();




#endif
