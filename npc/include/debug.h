#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <common.h>
#include <stdio.h>
#include <utils.h>

#ifdef __cplusplus
extern "C" {
#endif
void assert_fail_msg();
#ifdef __cplusplus
}
#endif

#define Log(format, ...) \
    _Log(ANSI_FMT("[%s:%d %s] " format, ANSI_FG_BLUE) "\n", \
        "npc/" __FILE__, __LINE__, __func__, ## __VA_ARGS__)

#define Assert(cond, format, ...) \
  do { \
    if (!(cond)) { \
      fflush(stdout); \
      fprintf(stderr, ANSI_FMT(format, ANSI_FG_RED) "\n", ##  __VA_ARGS__); \
      extern FILE* log_fp; \
      fflush(log_fp); \
      assert_fail_msg(); \
      assert(cond); \
    } \
  } while (0)

#define panic(format, ...) Assert(0, format, ## __VA_ARGS__)

#endif
