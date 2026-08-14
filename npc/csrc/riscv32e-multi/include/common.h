#ifndef __COMMON_H__
#define __COMMON_H__

#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"
#include "verilated.h"
#include "VysyxSoCFull__Dpi.h"

#define CSR_MCYCLE      0xb00
#define CSR_MCYCLEH     0xb80
#define CSR_MVENDORID   0xf11
#define CSR_MARCHID     0xf12
#define CSR_MSTATUS     0x300
#define CSR_MEPC        0x341
#define CSR_MCAUSE      0x342
#define CSR_MTVEC       0x305

#ifdef CONFIG_BOARD
#include <nvboard.h>
#endif
#ifdef CONFIG_WAVEFORM
#include "verilated_fst_c.h"
#endif

#define MROM_SIZE 0x1000
#define FLASH_SIZE 0x1000000
#define DRAM_SIZE 0x400000

#define SDRAM_BANK_WIDTH 4
#define SDRAM_ROW_WIDTH 8192
#define SDRAM_COL_WIDTH 512

extern uint8_t flash[FLASH_SIZE]; // 0x3000_0000~0x3fff_ffff
extern uint8_t dram[DRAM_SIZE]; // 0x8000_0000~0x9fff_ffff
extern uint16_t sdram[SDRAM_BANK_WIDTH][SDRAM_ROW_WIDTH][SDRAM_COL_WIDTH]; // 0xa000_0000~0xbfff_ffff
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
extern int npc_state;
extern long int start_time;
extern struct timeval tv;

extern long long ifu_counter;
extern long long load_counter;
extern long long store_counter;
extern long long exu_counter;
extern long long idu_load;
extern long long idu_store;
extern long long idu_jalr;
extern long long idu_jal;
extern long long idu_branch;
extern long long idu_csr;
extern long long idu_mret;
extern long long idu_ecall;
extern long long idu_alu;
extern long long lsu_load_delay;
extern long long lsu_store_delay;
extern long long ifu_fetch_delay;
extern long long ifu_wait_delay;

extern long long miss_penalty;
extern long long ifu_req;
extern long long icache_hit;

enum {NPC_STOP, NPC_ABORT, NPC_QUIT, NPC_BADTRAP, NPC_GOODTRAP, NPC_RUNNING};

#define BITMASK(bits) ((1ull << (bits)) - 1)
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1)) // similar to x[hi:lo] in verilog
#define SEXT(x, len) ({ struct { int64_t n : len; } __x = { .n = static_cast<int64_t>(x) }; (uint64_t)__x.n; })

typedef uint32_t word_t;
typedef uint32_t vaddr_t;
typedef uint32_t paddr_t;
#define FMT_WORD "0x%08x"
static inline word_t mem_read(void* addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default: assert(0);
  }
}

void ftrace_ret(int pc);
void ftrace_call(int pc, int dnpc);

// #define ITRACE_COND
// #define MTRACE_COND
#define FTRACE_COND
#define DIFFTEST_COND
extern bool difftest_skip_ref;
extern bool difftest_skip_next_ref;

void init_monitor(int argc, char *argv[]);
void init_disasm();
#define ITRACE_LOG_LEN 128
void inst_display(word_t pc, word_t inst);
void init_ftrace(const char *elf_file);
void cpu_exec(uint64_t n);
typedef struct {
  word_t gpr[16];
  vaddr_t pc;
  vaddr_t mepc;
  word_t mstatus;
  word_t mcause;
  word_t mtvec;
  word_t mvendorid;
  word_t marchid;
} CPU_state;
void init_difftest(char *ref_so_file, long img_size, int port);
enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };
void difftest_step(word_t pc, word_t cur_pc);

extern VerilatedContext* contextp;
extern VysyxSoCFull* top;
extern VerilatedFstC* tfp;

#define UART_ADDR     0x10000000
#define CLINT_ADDR    0x02000000

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
#endif
