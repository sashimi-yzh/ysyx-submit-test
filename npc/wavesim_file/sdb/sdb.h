#ifndef SDB_H
#define SDB_H

#include <iostream>
#include <stdint.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "VysyxSoCFull.h"

#include <engine/engine.h>
#include <register/register.h>
#include <include/auto.h>
#include <include/general.h>
#include <mrom/mrom.h>
#include <flash/flash.h>
#include <psram/psram.h>
#include <sdram/sdram.h>
//#include <memory/memory.h>


#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

typedef struct watchpoint {
  int NO;
  char expression[64];
  uint32_t result;
  struct watchpoint *next;
} WP;


void init_sdb();// in sdb.cpp
void sdb_mainloop(uint64_t *sim_time);// in sdb.cpp


void init_regex();// in expr.cpp
uint32_t expr(char *e, bool *success, bool *null);// in expr.cpp



void init_wp_pool();
WP* new_wp(void);// in watchpoint.cpp
void free_wp(int no);// in watchpoint.cpp
int check_usage(int wp_used[32], char expression_stored[32][32], uint32_t result[32]);
void update_wp_result(int no, uint32_t _result);
void scan_watchpoints();


#endif

