#ifndef __SDB_H__
#define __SDB_H__
#include <common.h>

void sdb_mainloop();
void sdb_set_batch_mode();
enum {
  WP_RAW=0,
  WP_BREAK=1,
};

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  char args[32];
  word_t value;
  int wp_type; 
} WP;
void init_sdb();

#endif