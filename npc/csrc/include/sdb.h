#ifndef __SDB_H__
#define __SDB_H__
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define ARRLEN(array) (sizeof(array) / sizeof((array)[0]))
uint32_t expr(char *e, bool *success);
bool add_wp(char *expr_str);
bool remove_wp(uint32_t no);
bool check_wp();
void info_wp();
void init_regex();
void init_wp_pool();
uint32_t mem_read(uint32_t addr);
uint32_t read_rf_reg(int addr);
uint32_t read_fetch_pc();
uint32_t cur_pc();
bool check_commit();
uint32_t isa_reg_str2val(const char *s, bool *success);
void cpu_exec(int n);
void isa_reg_display();
void printNextInst();
void init_sdb();
void sdb_set_batch_mode();
#endif
