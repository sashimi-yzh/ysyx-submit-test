#ifndef NPC_RUNTIME_H
#define NPC_RUNTIME_H

#include <stdio.h>

#include <npc/base.h>
#include <npc/monitor.h>
#include <npc/terminal.h>


typedef enum {
  NPC_RUNNING,
  NPC_STOP,
  NPC_END,
  NPC_ABORT,
  NPC_QUIT,
} NPCStateKind;

typedef struct {
  NPCStateKind state;
  vaddr_t halt_pc;
  uint32_t halt_ret;
} NPCState;

typedef enum {
  TRACE_ITRACE,
  TRACE_FTRACE,
  TRACE_ETRACE,
  TRACE_MTRACE,
  TRACE_DTRACE,
  TRACE_CHANNEL_COUNT,
} TraceKind;

NPC_EXTERN_C_BEGIN

extern FILE *log_fp;
extern NPCState npc_state;

bool log_enable(void);
void init_log(const char *path);

void init_trace_log(TraceKind kind, const char *path);
void trace_write(TraceKind kind, const char *format, ...);
void show_files(MonitorOptions options);

void init_rand(void);
uint64_t get_time(void);

NPC_EXTERN_C_END

#define NPC_LOG_TO_FILE(...) \
  do { \
    if (log_enable() && log_fp != NULL) { \
      fprintf(log_fp, __VA_ARGS__); \
      fflush(log_fp); \
    } \
  } while (0)

#define NPC_LOG_BOTH(...) \
  do { \
    printf(__VA_ARGS__); \
    NPC_LOG_TO_FILE(__VA_ARGS__); \
  } while (0)

#endif
