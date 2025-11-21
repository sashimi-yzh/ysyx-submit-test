#ifndef __FTRACE_H__
#define __FTRACE_H__

void parse_elf(char *elf_file);
void call_func(word_t pc, word_t func_addr);
void ret_func(word_t pc);

#endif