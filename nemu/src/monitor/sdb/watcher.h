#ifndef __WATCHER_H__
#define __WATCHER_H__

#include "ST.h"
#include "sdb.h"

long long eval(int p, int q, TokenST *st, int *right_buffer);

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  Token *tokens;
  int *parentheses_buffer;

  TokenST st;
  long long old_value;

  bool is_hex;

} WP;
WP *new_wp(char *expression, long long value, bool is_hex);
void free_wp(WP *wp);
bool exam_watchers(void);
void list_watchers(void);
#endif