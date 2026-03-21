#ifndef __SDB_H__
#define __SDB_H__


#include "common.h"
#include "utils.h"

#include <readline/readline.h>
#include <readline/history.h>

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  char expr[65536];
  uint32_t new_value;
  uint32_t old_value;
  int hit_count;
} WP;


#endif