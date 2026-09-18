#ifndef __COMMON_H__
#define __COMMON_H__

#include <macro.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <generated/autoconf.h>
#include <paddr.h>

// ---------------- log ---------------

#define ANSI_FG_BLACK   "\33[1;30m"
#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_FG_GREEN   "\33[1;32m"
#define ANSI_FG_YELLOW  "\33[1;33m"
#define ANSI_FG_BLUE    "\33[1;34m"
#define ANSI_FG_MAGENTA "\33[1;35m"
#define ANSI_FG_CYAN    "\33[1;36m"
#define ANSI_FG_WHITE   "\33[1;37m"
#define ANSI_BG_BLACK   "\33[1;40m"
#define ANSI_BG_RED     "\33[1;41m"
#define ANSI_BG_GREEN   "\33[1;42m"
#define ANSI_BG_YELLOW  "\33[1;43m"
#define ANSI_BG_BLUE    "\33[1;44m"
#define ANSI_BG_MAGENTA "\33[1;45m"
#define ANSI_BG_CYAN    "\33[1;46m"
#define ANSI_BG_WHITE   "\33[1;47m"
#define ANSI_NONE       "\33[0m"

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE


#define Log(format, ...) \
    do { \
      printf(ANSI_FG_BLUE "[ysyxSoC] " format ANSI_NONE "\n", ## __VA_ARGS__); \
      log_write(format "\n", ## __VA_ARGS__); \
    } while (0)

#ifdef __cplusplus
extern "C" {
#endif
bool log_enable();
#ifdef __cplusplus
}
#endif

#define log_write(...) IFDEF(CONFIG_TRACE, \
  do { \
    extern FILE* log_fp; \
    if (log_enable() && log_fp != NULL) { \
      fprintf(log_fp, __VA_ARGS__); \
      fflush(log_fp); \
    } \
  } while (0) \
)

#define Assert(cond, format, ...) \
  do { \
    if (!(cond)) { \
      fflush(stdout); \
      fprintf(stderr, "\33[1;31m" format "\33[0m\n", ## __VA_ARGS__); \
      extern void sim_exit(); \
      sim_exit(); \
      assert(cond); \
    } \
  } while (0)

#endif

extern uint32_t R[31];

#define DIFFTEST_TO_REF 1
#define DIFFTEST_FROM_REF 0

typedef MUXDEF(CONFIG_ISA64, uint64_t, uint32_t) word_t;
typedef word_t vaddr_t;
typedef MUXDEF(PMEM64, uint64_t, uint32_t) paddr_t;

