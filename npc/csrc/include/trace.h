#pragma once

#include "include/common.h"

void itrace_write(word_t pc, word_t inst);
void itrace_log_init(std::string build_dir);
void mtrace_record(const char *msg);

void trace_log();

typedef struct
{
    char *name;
    word_t addr_begin;
    word_t addr_end;

} FuncSymbol;

extern bool ftrace_enabled;

bool init_ftrace(const char *bin_path);
void ftrace_log_init(std::string build_dir);
void get_init_func_symbols(int pc);
void ftrace_record(word_t curr_pc, bool is_jal);
void save_prev_state(word_t pc, word_t inst, int rd, int rs1);
bool was_jal();
bool was_jalr();

void fst_init(VysyxSoCFull *top);
void fst_dump_once();
void fst_close();

// pctrace
bool pctrace_write_init();
void pctrace_write_record(uint32_t pc);
bool pctrace_write_close();

bool pctrace_read_init();
bool pctrace_read_next(uint32_t *pc);
bool pctrace_read_close();

// branchtrace
bool branchtrace_write_init();
void branchtrace_write_record(uint32_t pc, uint32_t inst);
bool branchtrace_write_close();

bool branchtrace_read_init();
bool branchtrace_read_next(uint32_t *pc, bool *is_backward, bool *is_taken);
bool branchtrace_read_close();