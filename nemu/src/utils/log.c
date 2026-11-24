/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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
FILE *log_fp_mem = NULL;
FILE *log_fp_func = NULL;
FILE *log_fp_branch = NULL;
FILE *log_fp_dev = NULL;
FILE *log_fp_except = NULL;

struct inst_ringbuf iringbuf;

bool log_enable(void);

#ifdef CONFIG_ITRACE_COMPRESS
typedef struct {
  bool     valid;
  uint32_t start;
  uint32_t last;
  uint32_t len;
} PcLogState;

static PcLogState pc_log = {0};

static void flush_pc_log(void) {
  if (!pc_log.valid || log_fp == NULL) {
    return;
  }

  // Stream format: base PC (even token), then optional odd token ((run_len - 1)
  // << 1) | 1.
  fwrite(&pc_log.start, sizeof(pc_log.start), 1, log_fp);
  if (pc_log.len > 1) {
    uint32_t marker = ((pc_log.len - 1) << 1) | 1u;
    fwrite(&marker, sizeof(marker), 1, log_fp);
  }

  pc_log.valid = false;
  pc_log.len   = 0;
}

void log_pc(vaddr_t pc_val) {
  if (!log_enable()) {
    return;
  }

  uint32_t pc = (uint32_t)pc_val;
  Assert((pc & 1u) == 0, "pc token format requires bit0 = 0, got 0x%x", pc);

  if (!pc_log.valid) {
    pc_log.valid = true;
    pc_log.start = pc;
    pc_log.last  = pc;
    pc_log.len   = 1;
    return;
  }

  if (pc == pc_log.last + 4) {
    pc_log.last = pc;
    pc_log.len++;
    return;
  }

  flush_pc_log();
  pc_log.valid = true;
  pc_log.start = pc;
  pc_log.last  = pc;
  pc_log.len   = 1;
}

void log_pc_flush(void) {
  flush_pc_log();
  if (log_fp != NULL) {
    fflush(log_fp);
  }
}
#endif

#ifdef CONFIG_MTRACE_COMPRESS
typedef struct {
  bool     valid;
  uint32_t start;
  uint32_t last;
  uint32_t len;
} DaLogState;

static DaLogState da_log = {false, 0, 0, 0};

static void flush_da_log(void) {
  if (!da_log.valid || log_fp == NULL) {
    return;
  }

  // Stream format: base da (even token), then optional odd token ((run_len - 1)
  // << 1) | 1.
  fwrite(&da_log.start, sizeof(da_log.start), 1, log_fp_mem);
  if (da_log.len > 1) {
    uint32_t marker = ((da_log.len - 1) << 1) | 1u;
    fwrite(&marker, sizeof(marker), 1, log_fp_mem);
  }

  da_log.valid = false;
  da_log.len   = 0;
}

void log_da(vaddr_t da_val) {

  uint32_t da = (uint32_t)da_val;

  if ((da & 1u) != 0) {
    printf("da token format assumes bit0 = 0 for memory access, got 0x%x, "
           "align it\n",
           da);
    da &= ~3u;
  }

  if (!da_log.valid) {
    da_log.valid = true;
    da_log.start = da;
    da_log.last  = da;
    da_log.len   = 1;
    return;
  }

  if (da == da_log.last + 4) {
    da_log.last = da;
    da_log.len++;
    return;
  }

  flush_da_log();
  da_log.valid = true;
  da_log.start = da;
  da_log.last  = da;
  da_log.len   = 1;
}

void log_da_flush(void) {
  flush_da_log();
  if (log_fp_mem != NULL) {
    fflush(log_fp_mem);
  }
}
#endif

void init_log(const char *log_file) {
  log_fp = stdout;
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, MUXDEF(CONFIG_ITRACE_COMPRESS, "wb", "w"));
    Assert(fp, "Can not open '%s'", log_file);
    log_fp = fp;
  }
  iringbuf.head = 0;
  iringbuf.tail = 0;
  Log("Log is written to %s%s", log_file ? log_file : "stdout",
      MUXDEF(CONFIG_ITRACE_COMPRESS, " (binary pc trace)", "normal pc trace"));
}

void init_log_mem(const char *log_file) {
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, MUXDEF(CONFIG_MTRACE_COMPRESS, "wb", "w"));
    Assert(fp, "Can not open '%s'", log_file);
    log_fp_mem = fp;
  }
  Log("Mem Log is written to %s%s", log_file ? log_file : "stdout",
      MUXDEF(CONFIG_MTRACE_COMPRESS, " (binary mem trace)",
             "normal mem trace"));
}

void init_log_func(const char *log_file) {
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "Can not open '%s'", log_file);
    log_fp_func = fp;
  }
  Log("Func Log is written to %s", log_file? log_file : "stdout");
}

void init_log_branch(const char *log_file) {
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "Can not open '%s'", log_file);
    log_fp_branch = fp;
    fprintf(log_fp_branch, "pc,inst,type,target,taken,dnpc\n");
    fflush(log_fp_branch);
  }
  Log("Branch Log is written to %s", log_file ? log_file : "disabled");
}

void init_log_dev(const char *log_file) {
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "Can not open '%s'", log_file);
    log_fp_dev = fp;
  }
  Log("Dev Log is written to %s", log_file? log_file : "stdout");
}

void init_log_except(const char *log_file) {
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "Can not open '%s'", log_file);
    log_fp_except = fp;
  }
  Log("Exception Log is written to %s", log_file? log_file : "stdout");
}

bool log_enable() {
  return MUXDEF(CONFIG_TRACE, (g_nr_guest_inst >= CONFIG_TRACE_START) &&
         (g_nr_guest_inst <= CONFIG_TRACE_END), false);
}
#endif
