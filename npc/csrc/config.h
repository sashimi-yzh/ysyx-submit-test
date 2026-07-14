#pragma once

// #define ENABLE_DIFFTEST
#define STEPS_AFTER_MISMATCH 10

#if USE_YSYXSOC
#define USE_NVBOARD
#endif

// #define ENABLE_ITRACE
// #define ENABLE_MTRACE
// #define MTRACE_ONLY
#define ITRACE_MAX_LINES 5000

// #define ENABLE_FTRACE
#define FTRACE_MAX_LINES 5000

// #define ENABLE_FST // 查看波形命令 gtkwave waveform.fst
#define MAX_SIM_TIME 40000
#define FST_TRACE_LATEST false
#define FST_START_TIME (0* 2)

// #define ENABLE_SDB

// #define RECORD_PCTRACE
// #define RECORD_BRTRACE

// #define RUN_CACHESIM 
#define DSE_MODE
#define PARA_R 9.9
#define TARGET_CACHE_SIZE_B 64
#define TARGET_BLOCK_SIZE_B 4
#define TARGET_ASSOC 8

// #define RUN_BRANCHSIM

#define MAX_SIM_TIME_MINUTES 60