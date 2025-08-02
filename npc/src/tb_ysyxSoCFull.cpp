#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <iostream>
#include <verilated.h>
#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"
#include <verilated_fst_c.h>

#ifdef nvboard
#include <nvboard.h>
#endif

#include "memory.h"
#include "trace.h"
#include "sdb.h"
#include "config.h"

vluint64_t 	sim_time 	  = 	0;
uint8_t     bash_mode   =   0;

VysyxSoCFull *top 				= new VysyxSoCFull;

#ifdef has_wave
VerilatedFstC *m_trace 	= new VerilatedFstC;
#endif

static char *log_file = NULL;
static char *elf_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;

static void reset_signal()	;
void init_disasm(const char *triple);
static int parse_args(int argc, char *argv[]);
void init_difftest(char *ref_so_file, long img_size, int port);
extern  void init_timer();
void parse_pc_trace_file(const char *log_file);
void close_pc_trace_file();

#ifdef nvboard
  void nvboard_bind_all_pins(VysyxSoCFull* top);
#endif

int main(int argc, char** argv, char** env) {

  #ifdef nvboard
    nvboard_bind_all_pins(top);
    nvboard_init();
  #endif

	Verilated::commandArgs(argc, argv);
	// for (uint8_t i = 0; i < argc; i++)
	// {
	// 	printf("argv%d = %s\n", i, argv[i]);
	// }

#ifdef has_wave
  Verilated::traceEverOn(true);
	top->trace(m_trace, 5);
	m_trace->open("waveform.fst");
#endif

	init_disasm("riscv32" "-pc-linux-gnu");

	/* Parse arguments. */
	parse_args(argc, argv);

  #ifdef BASH_MODE
    bash_mode = 1;
  #endif

	// initial mem
  long img_size = load_img(img_file); 

  #ifdef ftrace
	// parse_elf
	parse_elf(elf_file);
  #endif

  #ifdef pc_trace
  parse_pc_trace_file(log_file);
  #endif

  init_timer();

	// reset_signal
	reset_signal();

  #ifdef has_difftest
  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);
  #endif

	sdb_mainloop();

#ifdef has_wave
	m_trace->close();
#endif

  #ifdef pc_trace
  close_pc_trace_file();
  #endif

	delete top;
	exit(EXIT_SUCCESS);
}

static void reset_signal() {
	top->clock = 0;
	top->reset = 1;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 1;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 0;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 1;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif

  // reset test
	top->clock = 0;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 1;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 0;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 1;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 0;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 1;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 0;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 1;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 0;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 1;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 0;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 1;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 0;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 1;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 0;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 1;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 0;
  top->reset = 0;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
	top->clock = 1;
	top->eval();
  #ifdef has_wave
	m_trace->dump(sim_time++);
  #endif
  // test end 
  #ifdef nvboard
    nvboard_update();
  #endif
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"elf"      , required_argument, NULL, 'e'},
    {"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-hl:d:p:e:", table, NULL)) != -1) {
    printf("%s\n", optarg);
    switch (o) {
      case 'e': elf_file = optarg; break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-e,--elf=FILE           elf file to be parsed\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}
