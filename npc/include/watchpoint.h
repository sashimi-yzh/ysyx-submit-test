#ifndef __WATCHPOINT_H__
#define __WATCHPOINT_H__
#include "../include/common.h"
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  struct watchpoint *prev;//设置双向链表，更容易维护
  char *expr;
  word_t old_val;
} WP;
WP *get_wp_head();
WP *new_wp();
void free_wp(WP *wp);
void update_all_watchpoint_NOs();
void init_wp_pool();
#endif