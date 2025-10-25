#pragma once
// #define MEMTRACE 1
// #define TRACE 1
// #define WAVE 1
#ifdef WAVE
// #define FST 1
#endif
#ifdef TRACE
#define FTRACE 1
#define ITRACE 1
#define DIFFTEST 1
#endif

#define MAX_SIZE 0x10000000
#define START_ADDR 0x20000000