#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#define CONFIG_MSIZE            0x8000000  // 128MB
extern uint8_t mem[CONFIG_MSIZE];
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
extern int npc_state;
extern long int start_time;
extern struct timeval tv;
enum {NPC_STOP, NPC_ABORT, NPC_QUIT, NPC_BADTRAP, NPC_GOODTRAP, NPC_RUNNING};

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

// #define ITRACE_COND
// #define MTRACE_COND
// #define FTRACE_COND
// #define DIFFTEST_COND
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
#include "Vriscv32e_top.h"
#include "Vriscv32e_top___024root.h"
#include "verilated.h"
#include "verilated_fst_c.h"

extern VerilatedContext* contextp;
extern Vriscv32e_top* riscv32e_top;
extern VerilatedFstC* tfp;

#define SERIAL_ADDR     0x10000000
#define UPDATE_ADDR     0xa0000048

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

#define regs(i) riscv32e_top->rootp->riscv32e_top__DOT__RegisterFile0__DOT__rf[i]
#define npc_pc riscv32e_top->rootp->riscv32e_top__DOT__IFU0__DOT__pc
#define npc_inst riscv32e_top->rootp->riscv32e_top__DOT__inst
#define npc_mcycle    riscv32e_top->rootp->riscv32e_top__DOT__CSR0__DOT__mcycle
#define npc_mcycleh   riscv32e_top->rootp->riscv32e_top__DOT__CSR0__DOT__mcycleh
#define npc_mvendorid riscv32e_top->rootp->riscv32e_top__DOT__CSR0__DOT__mvendorid
#define npc_marchid   riscv32e_top->rootp->riscv32e_top__DOT__CSR0__DOT__marchid
#define npc_mtvec     riscv32e_top->rootp->riscv32e_top__DOT__CSR0__DOT__mtvec
#define npc_mcause    riscv32e_top->rootp->riscv32e_top__DOT__CSR0__DOT__mcause
#define npc_mepc      riscv32e_top->rootp->riscv32e_top__DOT__CSR0__DOT__mepc
#define npc_mstatus   riscv32e_top->rootp->riscv32e_top__DOT__CSR0__DOT__mstatus