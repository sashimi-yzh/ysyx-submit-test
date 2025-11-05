#ifndef __WATCHPOINT_H_
#define __WATCHPOINT_H_

#include <common.h>
#include <utils.h>

#define NR_WP 32



typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  char expr[256];
  word_t value;
  word_t value_old;
} WP;


void set_watchpoint(char *e);
void del_watchpoint(int NO);
void print_watchpoint();
void scan_watchpoint();

#endif // !__WATCHPOINT_H_


