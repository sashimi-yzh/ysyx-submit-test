#include <stdio.h>
#include <stdint.h>
#include <assert.h> 
#include <string.h>
#include <stdbool.h>

#ifndef __SDB_H__
#define __SDB_H__




uint32_t expr(char *e, int *success);

void init_regex();
void init_wp_pool();

void sdb_mainloop();

void sdb_set_batch_mode();

void isa_reg_display();

void isa_watchpoint_display();
void set_watchpoint(char *args, uint32_t result, int *success);
void remove_watchpoint(int NO_watchpoint);
bool scan_watchpoint();

uint32_t expr(char *e, int *success);
uint32_t isa_reg_str2val(const char *s, int *success);

extern const char *regs[32];

#endif
