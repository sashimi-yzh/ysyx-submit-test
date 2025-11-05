#ifndef __FTRACE_H_
#define __FTRACE_H_

#include <stdbool.h>
#include <stdint.h>
#include "elfread.h"

typedef uint32_t word_t;


void ftrace_init(const char* _img_file);
void ftrace_reset();
void ftrace_print_func_list();
void ftrace_get_func_name(char* buf, word_t pc);


#endif
