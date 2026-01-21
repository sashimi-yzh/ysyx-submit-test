#include <isa.h>
#include "local-include/csr.h"

riscv_csr csrs[6] = {
    {.addr = 0x341, .name = "mepc"},
    {.addr = 0x342, .name = "mcause"},
    {.addr = 0x305, .name = "mtvec"},
    {.addr = 0x300, .name = "mstatus", .wpri_mask = 0x7f800015},
    {.addr = 0xf11, .name = "mvendorid", .value = 0x79737978, .wpri_mask = 0xffffffff},
    {.addr = 0xf12, .name = "marchid", .value = 25050136, .wpri_mask = 0xffffffff	},
};
