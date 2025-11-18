#ifndef EXEC_H
#define EXEC_H

#include "common.h"

void single_cycle();
void reset();
void iringbuf_display();
void cpu_exec(uint32_t num);

#endif