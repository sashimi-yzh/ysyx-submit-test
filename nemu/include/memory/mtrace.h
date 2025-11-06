#ifndef __MTRACE_H__
#define __MTRACE_H__

#include <common.h>
#include <device/map.h>

void init_mtrace_log();
void mtrace_log_write(paddr_t addr, int len, char operate,word_t data);

void init_dtrace_log();
void dtrace_log_write(paddr_t addr, int len, char operate,IOMap *map,word_t data);

#endif