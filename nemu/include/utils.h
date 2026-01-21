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

#ifndef __UTILS_H__
#define __UTILS_H__

#include <common.h>

// ----------- state -----------

enum { NEMU_RUNNING, NEMU_STOP, NEMU_END, NEMU_ABORT, NEMU_QUIT };

typedef struct {
  int state;
  vaddr_t halt_pc;
  uint32_t halt_ret;
} NEMUState;

extern NEMUState nemu_state;

// ----------- timer -----------

uint64_t get_time();

// ----------- log -----------

#define ANSI_FG_BLACK   "\33[1;30m"
#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_FG_GREEN   "\33[1;32m"
#define ANSI_FG_YELLOW  "\33[1;33m"
#define ANSI_FG_BLUE    "\33[1;34m"
#define ANSI_FG_MAGENTA "\33[1;35m"
#define ANSI_FG_CYAN    "\33[1;36m"
#define ANSI_FG_WHITE   "\33[1;37m"
#define ANSI_BG_BLACK   "\33[1;40m"
#define ANSI_BG_RED     "\33[1;41m"
#define ANSI_BG_GREEN   "\33[1;42m"
#define ANSI_BG_YELLOW  "\33[1;43m"
#define ANSI_BG_BLUE    "\33[1;44m"
#define ANSI_BG_MAGENTA "\33[1;45m"
#define ANSI_BG_CYAN    "\33[1;46m"
#define ANSI_BG_WHITE   "\33[1;47m"
#define ANSI_NONE       "\33[0m"

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

#define log_write(...) IFDEF(CONFIG_TARGET_NATIVE_ELF, \
  do { \
    extern FILE* log_fp; \
    extern bool log_enable(); \
    if (log_enable() && log_fp != NULL) { \
      fprintf(log_fp, __VA_ARGS__); \
      fflush(log_fp); \
    } \
  } while (0) \
)

//=========================================
// ftracer 部分内容
//=========================================
#ifdef CONFIG_FTRACE
#define ftracer_write(...) IFDEF(CONFIG_FTRACE, \
  do { \
    extern FILE* ftracer_log_fp; \
    if(ftracer_log_fp != NULL) { \
      fprintf(ftracer_log_fp, __VA_ARGS__); \
      fflush(ftracer_log_fp); \
    } \
  } while(0) \
)
struct FUNC_FTRACE{
  word_t addr;
  char func_name[32];
};
extern struct FUNC_FTRACE *FUNC_FTRACER;
extern int FUNC_nums;
#endif

//=========================================
// dtracer 部分内容
//=========================================
#ifdef CONFIG_DTRACE
#define dtracer_write(...) IFDEF(CONFIG_DTRACE, \
  do { \
    extern FILE* dtracer_log_fp; \
    if(dtracer_log_fp != NULL) { \
      fprintf(dtracer_log_fp, __VA_ARGS__); \
      fflush(dtracer_log_fp); \
    } \
  } while(0) \
)
#endif

//=========================================
// btrace 部分内容
//=========================================
#ifdef CONFIG_BTRACE
#define btrace_write(...) do {extern FILE* tracebin_fp; \
    fwrite(__VA_ARGS__, 12, 1, tracebin_fp); \
    fflush(tracebin_fp); \
} while(0)
#endif

//=========================================
// Log 宏定义
//=========================================
#define _Log(...) \
  do { \
    printf(__VA_ARGS__); \
    log_write(__VA_ARGS__); \
  } while (0)
#endif
