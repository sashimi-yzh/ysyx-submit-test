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
#include <elf.h>
#include <stdio.h>
#include <stdarg.h>
#include <isa.h>


// ----------- state -----------

enum
{
  NEMU_RUNNING,
  NEMU_STOP,
  NEMU_END,
  NEMU_ABORT,
  NEMU_QUIT
};

typedef struct
{
  int state;
  vaddr_t halt_pc;
  uint32_t halt_ret;
} NEMUState;

extern NEMUState nemu_state;

// ----------- timer -----------

uint64_t get_time();

// ----------- log -----------

#define ANSI_FG_BLACK "\33[1;30m"
#define ANSI_FG_RED "\33[1;31m"
#define ANSI_FG_GREEN "\33[1;32m"
#define ANSI_FG_YELLOW "\33[1;33m"
#define ANSI_FG_BLUE "\33[1;34m"
#define ANSI_FG_MAGENTA "\33[1;35m"
#define ANSI_FG_CYAN "\33[1;36m"
#define ANSI_FG_WHITE "\33[1;37m"
#define ANSI_BG_BLACK "\33[1;40m"
#define ANSI_BG_RED "\33[1;41m"
#define ANSI_BG_GREEN "\33[1;42m"
#define ANSI_BG_YELLOW "\33[1;43m"
#define ANSI_BG_BLUE "\33[1;44m"
#define ANSI_BG_MAGENTA "\33[1;45m"
#define ANSI_BG_CYAN "\33[1;46m"
#define ANSI_BG_WHITE "\33[1;47m"
#define ANSI_NONE "\33[0m"

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

#define log_write(...) IFDEF(CONFIG_TARGET_NATIVE_ELF, do { \
    extern FILE* log_fp; \
    extern bool log_enable(); \
    if (log_enable() && log_fp != NULL) { \
      fprintf(log_fp, __VA_ARGS__); \
      fflush(log_fp); \
    } } while (0))

#define _Log(...)           \
  do                        \
  {                         \
    printf(__VA_ARGS__);    \
    log_write(__VA_ARGS__); \
  } while (0)


  
//----------- iringbuf-----------

#define IRINGBUF_SIZE 16

typedef struct
{
  word_t pc;
  word_t inst;
  int ilen;
  bool valid;
} IringbufEntry;

extern IringbufEntry iringbuf[IRINGBUF_SIZE];
extern int iringbuf_index;

void iringbuf_push(word_t pc, word_t inst, int ilen);

void iringbuf_display();

// ----------- mtrace -----------
extern char mtrace_buf[256];
void mtrace_buf_write(bool is_write, word_t addr, int len, word_t data);
void dtrace_buf_write(bool is_write, vaddr_t addr, int len, word_t data, const char *name);
void mtrace_buf_clear();

// ----------- ftrace -----------
bool init_ftrace(char *elf_path);
void init_ftrace_log(char *log_file);
char* get_elf_path(const char* bin_path);
void ftrace_record(word_t pc,word_t dnpc, int rd,int rs1,bool is_jal);
extern bool ftrace_enabled;

typedef struct
{
  char *name;
  word_t addr_begin;
  word_t addr_end;

} FuncSymbol;

#endif
