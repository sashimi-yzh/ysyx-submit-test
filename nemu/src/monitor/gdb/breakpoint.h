#ifndef __BREAKPOINT_H__
#define __BREAKPOINT_H__

#include <common.h>

typedef struct breakpoint {
  int NO;
  struct breakpoint *next;
  word_t addr;
} BP;

void init_bp_pool(void);
bool new_bp(word_t addr);
void free_bp(word_t addr);
int find_bp(word_t addr);

#endif
