#ifndef __BREAKPOINT_H_
#define __BREAKPOINT_H_
#include <common.h>
#include <utils.h>

void init_bp_pool();

bool add_breakpoint(vaddr_t addr);
bool del_breakpoint(vaddr_t addr);

void scan_breakpoint(vaddr_t addr);

#endif // !__BREAKPOINT_H_
