#include <common.h>

extern uint64_t g_nr_guest_inst;

FILE *log_fp = NULL;

void init_log(const char *log_file) {
  log_fp = stdout;
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "Can not open '%s'", log_file);
    log_fp = fp;
  }
  Log("Log is written to %s", log_file ? log_file : "stdout");
}

bool log_enable() {
  return MUXDEF(CONFIG_TRACE, (g_nr_guest_inst >= CONFIG_TRACE_START) &&
         (g_nr_guest_inst <= CONFIG_TRACE_END), false);
}

FILE *trace_fp = NULL;

void init_trace(const char *trace_file) {
  trace_fp = stdout;
  if (trace_file != NULL) {
    FILE *fp = fopen(trace_file, "w");
    Assert(fp, "Can not open '%s'", trace_file);
    trace_fp = fp;
  }
}
