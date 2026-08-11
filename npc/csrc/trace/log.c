#include <stdarg.h>
#include <npc/monitor.h>
#include <npc/diagnostics.h>

extern uint64_t guest_insts;
uint64_t get_sim_time();

FILE *log_fp = NULL;
static FILE *trace_streams[TRACE_CHANNEL_COUNT] = {};
static const char *trace_tags[TRACE_CHANNEL_COUNT] = { "[ITRACE] ", "[FTRACE] ", "[ETRACE] ", "[MTRACE] ", "[DTRACE] ",};

void init_log(const char *log_file) {
  log_fp = NULL;
  if (log_file != NULL) {
    log_fp = fopen(log_file, "w");
    Assert(log_fp != NULL, "Can not open '%s'", log_file);
  }
}
// judge the log start (attention to the inst number)
bool log_enable() {
  return MUXDEF(CONFIG_TRACE, (guest_insts >= CONFIG_TRACE_START) && (guest_insts <= CONFIG_TRACE_END), false);
}

void init_trace_log(TraceKind kind, const char *log_file) {
  Assert(kind < TRACE_CHANNEL_COUNT, "The trace channel is out of bound, the trace may have some error!");
  trace_streams[kind] = fopen(log_file, "w");
  Assert(trace_streams[kind] != NULL, "Can not open '%s'", log_file);
}

static void write_record(FILE *stream, TraceKind kind, uint64_t time,
    const char *format, va_list args) {
  if (stream == NULL) return;
  fprintf(stream, "[%9" PRIu64 "] %s", time, trace_tags[kind]);
  vfprintf(stream, format, args);
  fflush(stream);
}

void trace_write(TraceKind kind, const char *format, ...) {
  if (!log_enable() || kind >= TRACE_CHANNEL_COUNT) return;

  va_list args;
  va_start(args, format);
  uint64_t time = get_sim_time();
  // write to main log
  if (log_fp != NULL) {
    va_list copy;
    va_copy(copy, args);
    write_record(log_fp, kind, time, format, copy);
    va_end(copy);
  }
  // write to trace log
  if (trace_streams[kind] != NULL) {
    va_list copy;
    va_copy(copy, args);
    write_record(trace_streams[kind], kind, time, format, copy);
    va_end(copy);
  }
  va_end(args);
}

void show_files(MonitorOptions options) {
  const char *image = (options.image == NULL) ? "NULL" : options.image;
  printf(ANSI_FMT("[npc] the image file is: %s\n", ANSI_FG_BLUE), image);

  const char *elf = (options.elf == NULL) ? "NULL" : options.elf;
  printf(ANSI_FMT("[npc] the elf file is: %s\n", ANSI_FG_BLUE), elf);

  const char *reference = (options.reference == NULL) ? "NULL" : options.reference;
  printf(ANSI_FMT("[npc] the reference file is: %s\n", ANSI_FG_BLUE), reference);

  const char *log = (options.log == NULL) ? "NULL" : options.log;
  printf(ANSI_FMT("[npc] the log file is: %s\n", ANSI_FG_BLUE), log);

  const char *ftrace_log = (options.ftrace_log == NULL) ? "NULL" : options.ftrace_log;
  printf(ANSI_FMT("[npc] the ftrace log file is: %s\n", ANSI_FG_BLUE), ftrace_log);

  const char *etrace_log = (options.etrace_log == NULL) ? "NULL" : options.etrace_log;
  printf(ANSI_FMT("[npc] the etrace log file is: %s\n", ANSI_FG_BLUE), etrace_log);

  const char *mtrace_log = (options.mtrace_log == NULL) ? "NULL" : options.mtrace_log;
  printf(ANSI_FMT("[npc] the mtrace log file is: %s\n", ANSI_FG_BLUE), mtrace_log);

  const char *dtrace_log = (options.dtrace_log == NULL) ? "NULL" : options.dtrace_log;
  printf(ANSI_FMT("[npc] the dtrace log file is: %s\n", ANSI_FG_BLUE), dtrace_log);

  printf(ANSI_FMT("[npc] the reference port is: %d\n", ANSI_FG_BLUE), options.reference_port);
}
