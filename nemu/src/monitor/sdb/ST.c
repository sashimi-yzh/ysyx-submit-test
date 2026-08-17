#include "ST.h"
#include "sdb.h"
#include <stdlib.h>

int ST_Log2[TOKEN_MAX_COUNT];

static int cmp(int a, int b, const Token *ref) {
  if (a == -1)
    return b;
  if (b == -1)
    return a;
  if (ref[a].layer < ref[b].layer)
    return a;
  if (ref[a].layer > ref[b].layer)
    return b;
  if (ref[a].priority < ref[b].priority)
    return a;
  return b;
}

void init_ST(TokenST *st, int n, const Token *ref) {
  st->ref = ref;
  st->n = n;

  for (int i = 0; i < TOKEN_MAX_COUNT_LOG; i++)
    if (n - (1 << i) + 1 > 0)
      st->table[i] = malloc(sizeof(int) * (n - (1 << i) + 1));

  for (int i = 0; i < n; i++) {
    if (ref[i].catagry == TK_CATAGORY_OPERATOR)
      st->table[0][i] = i;
    else
      st->table[0][i] = -1;
  }

  for (int i = 1; (1 << i) <= n; i++) {
    int bulk_sz = (1 << i);
    for (int j = 0; j + bulk_sz <= n; j++) {
      st->table[i][j] =
          cmp(st->table[i - 1][j], st->table[i - 1][j + bulk_sz / 2], ref);
    }
  }
}

int query_ST(TokenST *st, int from, int to) {

  int layer =
      31 - __builtin_clz(to - from + 1); // layer = max n that 2**n <= len

  // compare [from, 2**layer + from -1] and [to - (1 << layer) + 1, to]
  return cmp(st->table[layer][from], st->table[layer][to - (1 << layer) + 1],
             st->ref);
}

void clear_ST(TokenST *st) {
  for (int i = 0; i < TOKEN_MAX_COUNT_LOG; i++)
    if (st->n - (1 << i) + 1 > 0)
      free(st->table[i]);
}