#ifndef FTRACH_H
#define FTRACE_H

#include "common.h"
#include <vector>

void init_elf(const std::vector<std::string> &elf_files);
char *get_fun_name(word_t addr);
void ftrace(word_t pc, word_t addr, uint32_t inst);
paddr_t get_function_addr(char *fun_name);
void add_breakpoint(char *fun_name);
void delete_breakpoint(int index);
void display_breakpoint();
bool check_breakpoint(paddr_t function_addr);
#endif