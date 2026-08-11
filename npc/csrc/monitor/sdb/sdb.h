#ifndef __SDB_H__
#define __SDB_H__

#include <npc/base.h>

word_t expr(char *e, bool *success);

int new_wp(char *e);
bool free_wp(int NO);
void display_watchpoints(void);
bool check_watchpoints(void);

#endif
