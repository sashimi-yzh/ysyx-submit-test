#include <verilated.h>
#include "dpi_functions.h"
#include <cpu/cpu.h>

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

void ebreak_catch(int pc, int rdata_x) {
    NEMUTRAP(pc, rdata_x);
    Verilated::gotFinish(true);
}
