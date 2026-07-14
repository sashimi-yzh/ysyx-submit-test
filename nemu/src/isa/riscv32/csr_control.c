
#include <cpu/cpu.h>
#include <cpu/decode.h>
#include "local-include/reg.h"
void ecall(Decode *s,word_t mcause) {
    csr(MEPC)=s->pc;
    csr(MCAUSE)=mcause;
    s->dnpc=csr(MTVEC);
    //printf("ETRACE: exception at pc = " FMT_WORD ", dnpc = " FMT_WORD ", mcause = " FMT_WORD "\n", s->pc, s->dnpc, mcause);
}


uint32_t default_csr = 0;