#ifdef __NPC__
#include "Vnpc.h"
#else
#include "VysyxSoCFull.h"
#endif

#include "map.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <getopt.h>
#include <string.h>

#ifdef __NVBOARD__
#include "nvboard.h"
#endif

#include "common.h"

#define RESET_TIME 15

void init_disasm(const char *triple);

uint32_t img[] = {0x00000413, 0x00009117, 0xffc10113, 0x00c000ef, 0x00000513,
                  0x00008067, 0xff410113, 0x00000517, 0x01450513, 0x00112423,
                  0xfe9ff0ef, 0x00050513, 0x00100073};

long init_default() {
  memcpy(guest_to_host(MBASE), img, sizeof(img));
  printf("\033[0m\033[1;32mfinish load memory\033[0m\n");
  return sizeof(img);
}

#ifdef __NPC__
unsigned int load_addr = PSBASE;
#else
unsigned int load_addr = FBASE;
#endif

long init_build(char *filepath) {
  FILE *fp = fopen(filepath, "r");
  if (fp == NULL) {
    printf("failed to read the file\n");
    exit(1);
  }
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(load_addr), size, 1, fp);

  fclose(fp);
  printf("\033[0m\033[1;32mfinish load file: %s\033[0m\n", filepath);
  return size;
}

extern Npc *npc;
extern Cpu *cpu;
#ifdef ITRACE
extern itrace_cfg_t *itrace_cfg;
#endif

#ifdef TRACE
bool fork_interval_on = false;
unsigned int fork_interval = 0;
bool record_enable = false;

unsigned long long record_after = -1;
extern Trace *trace;

char *triple = NULL;
bool record_enable_when_on = false;
#endif

bool perform_dump = false;

unsigned long long die_on_end = 0;
bool die_on_end_on = false;

char *filepath = NULL;
char *diff_ref = NULL;
char *itrace_out_file = NULL;
char *mtrace_out_file = NULL;
char *wave_out_file = NULL;
char *perf_output_file = NULL;
bool itrace_on = false;
bool mtrace_on = false;
bool perf_on = false;
int port = 0;
bool batch_mode_on = false;

#ifdef __NVBOARD__
extern void nvboard_bind_all_pins(VysyxSoCFull *top);
#endif

void parse_args(int argc, char *argv[]) {
  enum {
    OPT_DIFF = 256,
    OPT_ITRACE_LOG,
    OPT_MTRACE_LOG,
    OPT_WAVE,
    OPT_PERF_OUTPUT,
  };

  const struct option table[] = {
      {"port", required_argument, NULL, 'p'},
      {"file", required_argument, NULL, 'f'},
      {"batch", no_argument, NULL, 'b'},
      {"fork-interval", required_argument, NULL, 'i'},
      {"record-after", required_argument, NULL, 'r'},
      {"die-on-end", required_argument, NULL, 'd'},
      {"enable-record", no_argument, NULL, 'e'},
      {"enable-record-when", required_argument, NULL, 'w'},
      {"performance-dump", no_argument, NULL, 'm'},
      {"diff", required_argument, NULL, OPT_DIFF},
      {"itrace-log", required_argument, NULL, OPT_ITRACE_LOG},
      {"mtrace-log", required_argument, NULL, OPT_MTRACE_LOG},
      {"wave", required_argument, NULL, OPT_WAVE},
      {"perf-output", required_argument, NULL, OPT_PERF_OUTPUT},
      {0, 0, NULL, 0},
  };
  int o;
  bool su;
  int val;
  while ((o = getopt_long(argc, argv, "-d:p:f:i:r:bew:m", table, NULL)) != -1) {
    switch (o) {
    case 'b':
      batch_mode_on = true;
      break;
    case 'f':
      filepath = optarg;
      break;
    case 'd':
      die_on_end = std::stoull(optarg);
      die_on_end_on = true;
      break;
    case 'i':
#ifdef TRACE
      fork_interval = std::strtol(optarg, NULL, 10);
      fork_interval_on = true;
#else
      printf("fork-interval is only supported in trace mode\n");
#endif
      break;
    case 'r':
#ifdef TRACE
      record_after = std::stoul(optarg);
#else
      printf("record-after is only supported in trace mode\n");
#endif
      break;
    case 'e':
      record_enable = true;
      printf(COLOR_BLUE "enable trace record\n" COLOR_RESET);
      break;
    case 'w':
      printf("not support enable-record-when yet\n");
      break;
    case 'm':
      perform_dump = true;
      break;
    case 'p':
      break;
    case OPT_DIFF:
      diff_ref = optarg;
      break;
    case OPT_ITRACE_LOG:
      itrace_out_file = optarg;
      itrace_on = true;
      break;
    case OPT_MTRACE_LOG:
      mtrace_out_file = optarg;
      mtrace_on = true;
      break;
    case OPT_WAVE:
      wave_out_file = optarg;
      break;
    case OPT_PERF_OUTPUT:
      perf_output_file = optarg;
      perf_on = true;
      break;
    }
  }
}

void init_trace() {
#ifdef TRACE
  if (wave_out_file == NULL) {
    return;
  }
  Verilated::traceEverOn(true);
  trace = new Trace;
  trace->tfp = new VerilatedVcdC;
  trace->context = new VerilatedContext;
  trace->context->traceEverOn(true);
  npc->top->trace(trace->tfp, 0);
  trace->tfp->open(wave_out_file);
#endif
  return;
}

void init(int argc, char *argv[]) {
  long img_size = 0;
  parse_args(argc, argv);

  if (filepath == NULL) {
    img_size = init_default();
  } else {
    img_size = init_build(filepath);
  }
#ifdef ITRACE
  if (itrace_on) {
    init_disasm("riscv32-pc-linux-gnu");
    itrace_cfg = new (std::nothrow) itrace_cfg_t;
    if (itrace_cfg == nullptr) {
      printf(COLOR_RED
             "[ERROR] Failed to allocate memory for itrace_cfg\n" COLOR_RESET);
      exit(1);
    }

    itrace_cfg->itrace_out = fopen(itrace_out_file, "w");
    if (itrace_cfg->itrace_out == nullptr) {
      printf(COLOR_RED
             "[ERROR] Failed to open itrace output file: %s\n" COLOR_RESET,
             itrace_out_file);
      printf(COLOR_YELLOW "[WARNING] Itrace will be disabled due to file open "
                          "failure\n" COLOR_RESET);
      delete itrace_cfg;
      itrace_cfg = nullptr;
      itrace_on = false;
    } else {
      printf(COLOR_GREEN "[INFO] Itrace output file opened: %s\n" COLOR_RESET,
             itrace_out_file);
    }
  }
#endif
  init_regex();
  init_wp_pool();
  device_init();
  init_mem();

  npc = new Npc;
  cpu = new Cpu;
  cpu->con.pc = MBASE - 8;
#ifdef __NPC__
  npc->top = new Vnpc;
#else
  npc->top = new VysyxSoCFull;
#endif
  npc->cycs = 0;
  npc->timer = 0;

  npc->state = STOP;
  npc->top->reset = 1;
  init_trace();
  for (int i = 0; i < RESET_TIME - 1; i++) {
    npc->top->clock = 1;
    npc->top->eval();
    demp_wave();
    npc->top->clock = 0;
    npc->top->eval();
    demp_wave();
    npc->timer += 2;
  }

#ifdef DIFFTEST
  init_difftest(diff_ref, img_size, port);
#endif

#ifdef __NVBOARD__
  nvboard_bind_all_pins(npc->top);
  nvboard_init();
#endif

  npc->top->reset = 0;
  npc->top->eval();
  demp_wave();
}

bool batch_mode() { return batch_mode_on; }
bool need_dump_perform() { return perform_dump && perf_on; }
#ifdef TRACE
bool fork_interval_is_on() { return fork_interval_on; }
int fork_interval_val() { return fork_interval; }
bool record_isenable() { return record_enable; }
void set_record_enable() { record_enable = true; }
void set_record_disenable() { record_enable = false; }
unsigned int record_after_val() { return record_after; }
bool die_on_end_is_on() { return die_on_end_on; }
unsigned long long die_on_end_val() { return die_on_end; }
bool record_enable_when_on_val() { return record_enable_when_on; }
void check_record_enable_when() { return; }
#endif
