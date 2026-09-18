#ifndef __SDB_H__
#define __SDB_H__

#include "common.h"
#include "paddr.h"

uint32_t expr(char *e, bool *success);

int c_print(void);
int c_w(char* args);
int c_d(char* args);

void check_watchpoints();

#endif
