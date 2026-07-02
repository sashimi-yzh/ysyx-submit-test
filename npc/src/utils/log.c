#include <common.h>
#include <stdarg.h>

extern uint64_t g_nr_guest_inst;
uint64_t npc_get_sim_time();

FILE *log_fp = NULL;
static FILE *ftrace_fp = NULL;
static FILE *etrace_fp = NULL;
static FILE *mtrace_fp = NULL;
static FILE *dtrace_fp = NULL;

void init_log(const char *log_file) {
  log_fp = NULL;
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "Can not open '%s'", log_file);
    log_fp = fp;
  }
  /*
  Log("Log is written to %s", log_file ? log_file : "stdout");
  */
}

bool log_enable() {
  return MUXDEF(CONFIG_TRACE, (g_nr_guest_inst >= CONFIG_TRACE_START) &&
         (g_nr_guest_inst <= CONFIG_TRACE_END), false);
}

static FILE *open_trace_log(const char *name, const char *log_file) {
  if (log_file == NULL) return NULL;

  FILE *fp = fopen(log_file, "w");
  Assert(fp, "Can not open '%s'", log_file);
  /*
  Log("%s trace is written to %s", name, log_file);
  */
  return fp;
}

void init_ftrace_log(const char *log_file) {
  ftrace_fp = open_trace_log("ftrace", log_file);
}

void init_etrace_log(const char *log_file) {
  etrace_fp = open_trace_log("etrace", log_file);
}

void init_mtrace_log(const char *log_file) {
  mtrace_fp = open_trace_log("mtrace", log_file);
}

void init_dtrace_log(const char *log_file) {
  dtrace_fp = open_trace_log("dtrace", log_file);
}

static void trace_vwrite(FILE *trace_fp, const char *prefix, const char *fmt, va_list ap) {
  if (!log_enable()) return;

  uint64_t sim_time = npc_get_sim_time();
  if (log_fp != NULL) {
    va_list log_ap;
    va_copy(log_ap, ap);
    fprintf(log_fp, "[%9" PRIu64 "] ", sim_time);
    fputs(prefix, log_fp);
    vfprintf(log_fp, fmt, log_ap);
    fflush(log_fp);
    va_end(log_ap);
  }

  if (trace_fp != NULL) {
    fprintf(trace_fp, "[%9" PRIu64 "] ", sim_time);
    fputs(prefix, trace_fp);
    vfprintf(trace_fp, fmt, ap);
    fflush(trace_fp);
  }
}

void ftrace_write(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  trace_vwrite(ftrace_fp, "[FTRACE] ", fmt, ap);
  va_end(ap);
}

void itrace_write(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  trace_vwrite(NULL, "[ITRACE] ", fmt, ap);
  va_end(ap);
}

void etrace_write(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  trace_vwrite(etrace_fp, "[ETRACE] ", fmt, ap);
  va_end(ap);
}

void mtrace_write(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  trace_vwrite(mtrace_fp, "[MTRACE] ", fmt, ap);
  va_end(ap);
}

void dtrace_write(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  trace_vwrite(dtrace_fp, "[DTRACE] ", fmt, ap);
  va_end(ap);
}
