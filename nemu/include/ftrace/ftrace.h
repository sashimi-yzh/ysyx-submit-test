#ifndef __FTRACE_H__
#define __FTRACE_H__

#include <common.h>
#include <elf.h>
#define MAX_FUNC 40960

typedef struct tail_rec_node
{
	vaddr_t pc;
	int depth;
    char* name;
	struct tail_rec_node *next;
} TailRecNode;

void init_tail_rec_list();
void insert_tail_rec(vaddr_t pc, int depth);
void remove_tail_rec();
void init_ftrace(char* elf_file);
void free_func_name();
int find_symbol_func(vaddr_t target, bool is_call);
// void ftrace_function(char operate,vaddr_t addr_inv,vaddr_t addr_func);
void ftrace_function_call(vaddr_t addr_inv,vaddr_t addr_func,bool is_tail);
void ftrace_function_ret(vaddr_t pc);

#endif