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
#define ANSI_BG_MAGENTA "\33[1;35m"
#define ANSI_BG_CYAN    "\33[1;46m"
#define ANSI_BG_WHITE   "\33[1;47m"
#define ANSI_NONE       "\33[0m"

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

#define log_write(...) IFDEF(CONFIG_TARGET_NATIVE_ELF, \
  do { \
    extern FILE* log_fp; \
      fprintf(log_fp, __VA_ARGS__); \
      fflush(log_fp); \
  } while (0) \
)

#ifdef CONFIG_ITRACE_COMPRESS
void log_pc(vaddr_t pc_val);
void log_pc_flush(void);
#endif

#ifdef CONFIG_MTRACE_COMPRESS
void log_da(vaddr_t da_val);
void log_da_flush(void);
#endif

#define RING_SIZE 16
#define BUF_SIZE 256
struct inst_ringbuf {
  uint32_t head;
  uint32_t tail;
  char ringbuf[RING_SIZE][BUF_SIZE];
};
extern struct inst_ringbuf iringbuf;

#define log_wr_iringbuf(...) IFDEF(CONFIG_TARGET_NATIVE_ELF, \
  do { \
      snprintf(iringbuf.ringbuf[iringbuf.tail], BUF_SIZE, __VA_ARGS__); \
      iringbuf.tail = (iringbuf.tail + 1) % RING_SIZE; \
  } while (0) \
)

#define log_show_iringbuf(...) IFDEF(CONFIG_TARGET_NATIVE_ELF, \
  do { \
    uint32_t index = 0; \
    while (index != RING_SIZE - 1) { \
      if (index == iringbuf.tail - 1) { \
        printf("--> "); \
      } else { \
        printf("    "); \
      } \
      printf("%s\n", iringbuf.ringbuf[index]); \
      index++; \
    } \
  } while (0) \
)

#define log_mtrace(addr, len, type) IFDEF(CONFIG_TARGET_NATIVE_ELF, \
  do { \
    extern FILE* log_fp_mem; \
    if (! type) fprintf(log_fp_mem, "read mem 0x%x len %d\n", addr, len); \
    else fprintf(log_fp_mem, "write mem 0x%x len %d\n", addr, len); \
    fflush(log_fp_mem); \
  } while (0) \
)

#define log_ftrace(...) IFDEF(CONFIG_TARGET_NATIVE_ELF, \
  do { \
    extern FILE* log_fp_func; \
    fprintf(log_fp_func, __VA_ARGS__); \
    fflush(log_fp_func); \
  } while (0) \
)

#define log_btrace(...) IFDEF(CONFIG_TARGET_NATIVE_ELF, \
  do { \
    extern FILE* log_fp_branch; \
    if (log_fp_branch != NULL) { \
      fprintf(log_fp_branch, __VA_ARGS__); \
      fflush(log_fp_branch); \
    } \
  } while (0) \
)

#define log_dtrace(dev, addr, len, type) IFDEF(CONFIG_TARGET_NATIVE_ELF, \
  do { \
    extern FILE* log_fp_dev; \
      if (! type)  \
          fprintf(log_fp_dev, "read dev %s mem 0x%x len %d\n", dev, addr, len); \
      else  \
          fprintf(log_fp_dev, "write dev %s mem 0x%x len %d\n", dev, addr, len); \
      fflush(log_fp_dev); \
  } while (0) \
)

#define log_etrace(no, mepc, mtvec) IFDEF(CONFIG_TARGET_NATIVE_ELF, \
  do { \
    extern FILE* log_fp_except; \
          fprintf(log_fp_except, "except: NO 0x%x mepc 0x%x mtvec 0x%x\n", no, mepc, mtvec); \
      fflush(log_fp_except); \
  } while (0) \
)

#ifndef CONFIG_ITRACE_COMPRESS
#define _Log(...) \
  do { \
    printf(__VA_ARGS__); \
    log_write(__VA_ARGS__); \
  } while (0)
#else
#define _Log(...) \
  do { \
    printf(__VA_ARGS__); \
  } while (0)
#endif


#endif
