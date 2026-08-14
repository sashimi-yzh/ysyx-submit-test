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

extern uint64_t g_nr_guest_inst;

#ifndef CONFIG_TARGET_AM
FILE *log_fp = NULL;
FILE *pc_trace_fp = NULL;
FILE *mem_trace_fp = NULL;
FILE *branch_trace_fp = NULL;

void init_log(const char *log_file) {
  log_fp = stdout;
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "Can not open '%s'", log_file);
    log_fp = fp;
  }
  Log("Log is written to %s", log_file ? log_file : "stdout");
}

void init_pc_trace(const char *pc_trace_file) {
  pc_trace_fp = stdout;
  if (pc_trace_file != NULL) {
    FILE *fp = fopen(pc_trace_file, "wb");
    Assert(fp, "Can not open '%s'", pc_trace_file);
    pc_trace_fp = fp;
  }
  Log("pc_trace is written to %s", pc_trace_file ? pc_trace_file : "stdout");
}

void init_mem_trace(const char *mem_trace_file) {
  mem_trace_fp = stdout;
  if (mem_trace_file != NULL) {
    FILE *fp = fopen(mem_trace_file, "wb");
    Assert(fp, "Can not open '%s'", mem_trace_file);
    mem_trace_fp = fp;
  }
  Log("mem_trace is written to %s", mem_trace_file ? mem_trace_file : "stdout");
}

void init_branch_trace(const char *branch_trace_file) {
  branch_trace_fp = stdout;
  if (branch_trace_file != NULL) {
    FILE *fp = fopen(branch_trace_file, "wb");
    Assert(fp, "Can not open '%s'", branch_trace_file);
    branch_trace_fp = fp;
  }
  Log("branch_trace is written to %s", branch_trace_file ? branch_trace_file : "stdout");
}

bool log_enable() {
  return MUXDEF(CONFIG_TRACE, (g_nr_guest_inst >= CONFIG_TRACE_START) &&
         (g_nr_guest_inst <= CONFIG_TRACE_END), false);
}
#endif
