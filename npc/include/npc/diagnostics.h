#ifndef NPC_DIAGNOSTICS_H
#define NPC_DIAGNOSTICS_H

#include <assert.h>
#include <stdio.h>

#include <npc/runtime.h>

NPC_EXTERN_C_BEGIN
void assert_fail_msg(void);
NPC_EXTERN_C_END

#define Log(message, ...) \
  NPC_LOG_BOTH(ANSI_FMT("[%s:%d %s] " message, ANSI_FG_BLUE) "\n", \
      "npc/" __FILE__, __LINE__, __func__, ##__VA_ARGS__)

#define Assert(condition, message, ...) \
  do { \
    if (!(condition)) { \
      fflush(stdout); \
      fprintf(stderr, ANSI_FMT(message, ANSI_FG_RED) "\n", ##__VA_ARGS__); \
      if (log_fp != NULL) fflush(log_fp); \
      assert_fail_msg(); \
      assert(condition); \
    } \
  } while (0)

#define panic(message, ...) Assert(false, message, ##__VA_ARGS__)

#endif
