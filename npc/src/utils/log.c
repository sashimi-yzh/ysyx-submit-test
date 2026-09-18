#include <common.h>
#include <npc.h>

FILE *log_fp = NULL;

extern "C" bool log_enable() {
  return MUXDEF(CONFIG_TRACE, (total_inst >= CONFIG_TRACE_START) &&
         (total_inst <= CONFIG_TRACE_END), false);
}

void init_log(const char *log_file) {
  log_fp = stdout;
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "Can not open '%s'", log_file);
    log_fp = fp;
  }
  Log("Log is written to %s", log_file ? log_file : "stdout");
}
