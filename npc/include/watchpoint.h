#ifndef WATCH_H
#define WATCH_H

#include "common.h"

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  char expr[256];
  word_t val;
  bool used;
} WP;

void init_wp_pool();
WP *new_wp();
void free_wp(uint64_t order);
bool check_wp();
void print_wp();

#endif