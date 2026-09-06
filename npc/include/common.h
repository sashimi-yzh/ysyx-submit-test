#ifdef __NPC__
#include "Vnpc.h"
#else
#include "VysyxSoCFull.h"
#endif

#include "verilated.h"
#include "verilated_vcd_c.h"

#include <cstdint>
#include <cstdio>

#ifndef COMMON_H
#define COMMON_H
// config
#include "selfconfig.h"

#define MBASE 0x20000000
#define FBASE 0x30000000
#define PSBASE 0x80000000
#define SDBASE 0xa0000000

enum npcstate { STOP, RUNNING, END, ABORT, QUIT };

typedef struct {
  #ifdef __NPC__
    Vnpc *top;
  #else
    VysyxSoCFull *top;
  #endif
  enum npcstate state;

  // statistic data
  unsigned long long cycs;
  unsigned long long timer;

  unsigned int icache_miss_time;
  unsigned int predict_miss_time;
  unsigned int npc_commit_time;
  unsigned long long npc_io_timer;
  unsigned int npc_io_counter;
  unsigned long long ifu_work_cycle;
  unsigned long long ifu_non_work_cycle;
  unsigned long long ifu_mem_access_timer;
  unsigned int ifu_giveup_bus_counter;
  unsigned int ifu_inst_count;
  unsigned long long idu_work_cycle;
  unsigned long long idu_non_work_cycle;
  unsigned long long exu_work_cycle;
  unsigned long long exu_non_work_cycle;
  unsigned long long wbu_mem_access_timer;
  unsigned int wbu_mem_access_counter;
} Npc;

typedef struct {
  uint32_t mstatus;
  uint32_t mtvec;
  uint32_t mepc;
  uint32_t mcause;
} Csr;

typedef struct {
  uint32_t gpr[32];
  uint32_t pc;
  Csr csr;
} context;

typedef struct {
  uint32_t inst;
  uint32_t pc;
  context con;
  context commit;
  char logbuf[128];
  int valid;
} Cpu;

#ifdef ITRACE
typedef struct {
  FILE* itrace_out;
} itrace_cfg_t;
#endif

#ifdef TRACE
typedef struct {
  VerilatedContext *context;
  VerilatedVcdC *tfp;
} Trace;
#endif

#endif

// memory.cpp
bool in_pmem(uint32_t addr);
uint8_t *guest_to_host(uint32_t addr);
uint32_t paddr_read(uint32_t address, uint32_t len);
void paddr_write(uint32_t address, uint32_t len, uint32_t data);
void pmem_write(uint8_t *addr, uint32_t len, uint32_t data);
uint32_t pmem_read(uint8_t *addr, uint32_t len);
void init_mem();

// init.cpp
void init(int argc, char *argv[]);
bool batch_mode();
bool need_dump_perform();
#ifdef TRACE
bool fork_interval_is_on();
int fork_interval_val();
bool record_isenable();
void set_record_enable();
void set_record_disenable();
unsigned int record_after_val();
bool die_on_end_is_on();
unsigned long long die_on_end_val();
bool record_enable_when_on_val();
void check_record_enable_when();
#endif

// cpu.cpp
void cpu_exec(uint64_t n);
void set_npc_end();
void set_npc_quit();
void set_npc_stop();
void set_diff_pass();
#ifdef DIFFTEST
void npc_diff_quit();
#endif
void demp_wave();
void tfpclose();
void echo_status();
unsigned long long get_loadfinish_time();

// sdb.cpp
void sdb_main();

// reg.cpp
void display_reg();
uint32_t npc_reg_str2val(char *regname, bool *success);

// expr.cpp
uint32_t expr(char *e, bool *success);
void init_regex();

// watchpoint.cpp
void init_wp_pool();
void exe_wp();
void new_wp(char *exp);
void free_wp(int wp_num);
void info_wp();

// memcheck.cpp
int add_mem_guard(uint32_t paddr, size_t size);
int check_mem_guard();

// disasm.cpp
extern "C" void init_disasm(const char *triple);
extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code,
                            int nbyte);

// difftest.cpp
#ifdef DIFFTEST
void init_difftest(char *ref_so_file, long img_size, int port);
void diff_step();
void set_ref_skip();
void set_diff_pass();
void difftest_check_mem(uint32_t addr, uint32_t expect, size_t size);
#endif

// perform.cpp
void deal_statistic();

/* 重置所有属性 */
#define COLOR_RESET       "\033[0m"

/* 前景色（字体颜色） */
#define COLOR_BLACK       "\033[30m"
#define COLOR_RED         "\033[31m"
#define COLOR_GREEN       "\033[32m"
#define COLOR_YELLOW      "\033[33m"
#define COLOR_BLUE        "\033[34m"
#define COLOR_MAGENTA     "\033[35m"
#define COLOR_CYAN        "\033[36m"
#define COLOR_WHITE       "\033[37m"
