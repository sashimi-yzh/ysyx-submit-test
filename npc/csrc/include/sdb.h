#ifndef __SDB_H__
#define __SDB_H__

#include "common.h"

word_t expr(char *e, bool *success);

struct WP {
  int NO;
  struct WP *next;

  word_t val;
  char *expr;
};

void init_wp_pool();
void print_wp(WP *p);
void wps_display();
WP *new_wp(char *str, word_t val);

#endif
