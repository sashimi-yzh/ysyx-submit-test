/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <common.h>
#include <stdarg.h>

extern uint64_t g_nr_guest_inst;

#ifndef CONFIG_TARGET_AM
FILE *log_fp = NULL;
static FILE *ftrace_fp = NULL;
static FILE *etrace_fp = NULL;
static FILE *mtrace_fp = NULL;
static FILE *dtrace_fp = NULL;

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

static FILE *open_trace_log(const char *name, const char *log_file) {
  if (log_file == NULL) return NULL;

  FILE *fp = fopen(log_file, "w");
  Assert(fp, "Can not open '%s'", log_file);
  Log("%s trace is written to %s", name, log_file);
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

  if (log_fp != NULL) {
    va_list log_ap;
    va_copy(log_ap, ap);
    fputs(prefix, log_fp);
    vfprintf(log_fp, fmt, log_ap);
    fflush(log_fp);
    va_end(log_ap);
  }

  if (trace_fp != NULL) {
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
#endif
