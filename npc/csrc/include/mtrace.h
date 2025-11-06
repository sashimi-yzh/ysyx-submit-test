#ifndef __MTRACE_H__
#define __MTRACE_H__

#include <common.h>

void init_mtrace_log();
void mtrace_log_write(paddr_t addr, int len, char operate,word_t data);

#endif