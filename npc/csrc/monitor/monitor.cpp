#include <isa.h>
#include <npc/cpu.h>
#include <npc/diagnostics.h>
#include <npc/memory.h>
#include <npc/monitor.h>
#include <npc/platform.h>
#include <sim_top.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

#include <getopt.h>
#include <stdlib.h>

extern VerilatedContext *sim_ctx;
extern VerilatedVcdC *sim_trace;

static MonitorOptions options = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 1234};

static void print_usage(const char *program) {
  printf("Usage: %s [OPTION...] IMAGE\n\n", program);
  puts("  -b, --batch              run without the interactive prompt");
  puts("  -f, --elf=FILE           load symbols used by ftrace");
  puts("  -l, --log=FILE           write the NPC log to FILE");
  puts("  -d, --diff=REF_SO        enable DiffTest with REF_SO");
  puts("  -p, --port=PORT          DiffTest reference port");
  puts("  -F, --ftrace-log=FILE    write function trace to FILE");
  puts("  -E, --etrace-log=FILE    write exception trace to FILE");
  puts("  -M, --mtrace-log=FILE    write memory trace to FILE");
  puts("  -D, --dtrace-log=FILE    write device trace to FILE");
}
// init the param from the cmd
static void parse_args(int argc, char **argv) {
  static const struct option long_options[] = {
    {"batch",      no_argument,       NULL, 'b'},
    {"elf",        required_argument, NULL, 'f'},
    {"log",        required_argument, NULL, 'l'},
    {"diff",       required_argument, NULL, 'd'},
    {"port",       required_argument, NULL, 'p'},
    {"ftrace-log", required_argument, NULL, 'F'},
    {"etrace-log", required_argument, NULL, 'E'},
    {"mtrace-log", required_argument, NULL, 'M'},
    {"dtrace-log", required_argument, NULL, 'D'},
    {"help",       no_argument,       NULL, 'h'},
    {NULL,           0,                 NULL,  0 },
  };

  while (true) {
    int code = getopt_long(argc, argv, "-bf:l:d:p:F:E:M:D:h", long_options, NULL);
    if (code == -1) break;
    switch (code) {
      case 'b': sdb_set_batch_mode(); break;
      case 'f': options.elf = optarg; break;
      case 'l': options.log = optarg; break;
      case 'd': options.reference = optarg; break;
      case 'p': options.reference_port = (int)strtol(optarg, NULL, 0); break;
      case 'F': options.ftrace_log = optarg; break;
      case 'E': options.etrace_log = optarg; break;
      case 'M': options.mtrace_log = optarg; break;
      case 'D': options.dtrace_log = optarg; break;
      case 1: if (options.image == NULL) options.image = optarg; break;
      default: print_usage(argv[0]); exit(code == 'h' ? 0 : 1);
    }
  }

  if (options.image == NULL) {
    print_usage(argv[0]);
    panic("The image is null, guest image is required!");
  }
}
// Init the circuit top
static void init_sim(int argc, char **argv) {
  sim_ctx = new VerilatedContext;
  sim_ctx->commandArgs(argc, argv); 
  sim_top = new SimTop{sim_ctx};
}
// init the trace logs
static void init_tracing() {
  init_log(options.log);
  IFDEF(CONFIG_FTRACE, init_trace_log(TRACE_FTRACE, options.ftrace_log));
  IFDEF(CONFIG_ETRACE, init_trace_log(TRACE_ETRACE, options.etrace_log));
  IFDEF(CONFIG_MTRACE, init_trace_log(TRACE_MTRACE, options.mtrace_log));
  IFDEF(CONFIG_DTRACE, init_trace_log(TRACE_DTRACE, options.dtrace_log));
  IFDEF(CONFIG_FTRACE, init_ftrace(options.elf));
}
// init the wave function
static VerilatedVcdC *create_waveform() {
#ifdef CONFIG_WAVE
  Verilated::traceEverOn(true);
  VerilatedVcdC *waveform = new VerilatedVcdC;
  sim_top->trace(waveform, 99);
  waveform->open("waveform.vcd");
  return waveform;
#else
  return NULL;
#endif
}
// flip clock
static void evaluate_clock(bool level) {
  sim_top->clock = level;
  sim_top->eval();
  sim_ctx->timeInc(1);
}
// reset the simulator for 10 cycles
static void reset_simulator() {
  sim_top->reset = 1;
  platform_idle(sim_top);
  evaluate_clock(false);
  for (int cycle = 0; cycle < 10; cycle ++) {
    evaluate_clock(true);
    evaluate_clock(false);
  }
  sim_top->reset = 0;
}
// load the mem and isa
static long load_guest() {
  init_mem();
  init_isa();
  long image_size = load_image(options.image);
  sim_trace = create_waveform();
  init_platform();
  reset_simulator();
  cpu_reset(reset_pc());
  return image_size;
}
// for difftest itrace and sdb
static void init_debugger(long image_size) {
  init_difftest(options.reference, image_size, options.reference_port);
  init_sdb();
  IFDEF(CONFIG_ITRACE, init_disasm());
}
// show welcome info
static void show_welcome() {
  const char *platform     = MUXDEF(NPC_BUILD_PLATFORM_YSYXSOC, "ysyxSoC", "standalone");
  const char *trace_status = MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED));
  printf(ANSI_FMT("[npc] ready: isa=riscv32 platform=%s trace=%s\n", ANSI_FG_BLUE), platform, trace_status);
  printf(ANSI_FMT("[npc] enter 'help' to list debugger commands\n", ANSI_FG_BLUE));
  printf(ANSI_FMT("[npc] the parameters are showed below:\n", ANSI_FG_BLUE));
  show_files(options);
}
// release the space
void delete_workspace() {
  cleanup_platform();
#ifdef CONFIG_WAVE
  if (sim_trace != NULL) {
    sim_trace->close();
    delete sim_trace;
    sim_trace = NULL;
  }
#endif
  delete sim_top;
  sim_top = NULL;
  delete sim_ctx;
  sim_ctx = NULL;
}

void init_monitor(int argc, char *argv[]) {
  parse_args(argc, argv);
  init_sim(argc, argv);
  init_rand();
  init_tracing();
  long image_size = load_guest();
  init_debugger(image_size);
  show_welcome();
}
