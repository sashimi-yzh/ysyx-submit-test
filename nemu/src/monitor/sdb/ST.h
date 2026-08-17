#ifndef __ST_H__
#define __ST_H__
#include "debug.h"
#include "sdb.h"

typedef struct {
  const Token *ref;
  int *table[TOKEN_MAX_COUNT_LOG];
  int n;
} TokenST;

extern int ST_Log2[TOKEN_MAX_COUNT];

void init_ST(TokenST *st, int n, const Token *ref);
int query_ST(TokenST *st, int from, int to);
void clear_ST(TokenST *st);
#endif