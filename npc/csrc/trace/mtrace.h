#ifndef __MTRACE_H__
#define __MTRACE_H__

#include <stdint.h>
#include <stdbool.h>

void init_mtrace();
void set_mtrace_enabled(bool enable);
bool mtrace_enabled();

// RTL 在 commit 时上报一次数据访存（不包含取指）
extern "C" void mtrace_event(int pc, int addr, int data, int len, int is_store);

void mtrace_flush(bool print_to_console);
void mtrace_dump_recent();

#endif
