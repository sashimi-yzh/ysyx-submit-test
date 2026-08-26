
#ifndef __SDB_H__
#define __SDB_H__
#include "common.h"
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  char expr[65600];
  uint32_t val;
} WP;

uint32_t expr(char *e, bool *success);
int new_wp(char *arg,uint32_t val);
void free_wp(WP *wp);
WP *find_wp(int n);
void print_wp();
int diff_wp(int n);

#endif
