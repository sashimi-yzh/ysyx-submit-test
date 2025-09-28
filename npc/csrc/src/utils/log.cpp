#include "common.h"

FILE *log_fp = nullptr;

void init_log(const char *log_file) {
  log_fp = stdout;
  if (log_file) {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "Can not open log file '%s'", log_file);
    log_fp = fp;
    Log("Log is written to %s", log_file);
  }
}