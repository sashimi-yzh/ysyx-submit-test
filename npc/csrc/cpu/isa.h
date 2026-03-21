#ifndef __ISA_H__
#define __ISA_H__

#include "common.h"

typedef struct {
    word_t mstatus;
    word_t mcause;
    word_t mepc;
    word_t mtvec;
} CSR_state;
typedef struct {
    word_t gpr[16];
    word_t pc;
    CSR_state csr;
} CPU_state;

typedef struct {
    word_t mcyclel;
    word_t mcycleh;
    word_t mvendorid;
    word_t marchid;
} Extra_CPU_state;

extern CPU_state cpu;
extern Extra_CPU_state extra_cpu;

typedef struct {
    // add ISA-specific state here
    word_t inst;
    word_t pc;
    IFDEF(CONFIG_ITRACE, char logbuf[128]);
} Decode;

extern Decode s;

extern int cpu_inst_valid;

// loop detect
typedef struct {
    word_t pc;
    word_t count;
} LoopHistory_t;

#define LOOP_HISTORY_SIZE 16
#define MAX_LOOP_COUNT 100000  // 最大循环次数阈值

#endif