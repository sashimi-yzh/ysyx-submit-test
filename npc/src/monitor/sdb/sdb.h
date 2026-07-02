#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>

word_t expr(char *e, bool *success);

int new_wp(char *e);
bool free_wp(int NO);
void wp_display();

#endif
