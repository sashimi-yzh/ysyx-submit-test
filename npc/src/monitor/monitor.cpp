#include <isa.h>
#include <memory/paddr.h>
#include <monitor/monitor.h>
#include <platform/platform.h>
#include <sim_top.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

extern VerilatedContext *g_contextp;
extern VerilatedVcdC *g_tfp;
void npc_reset_commit_state(vaddr_t pc);

static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  printf("Welcome to %s-NPC!\n", ANSI_FMT("riscv32", ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
}

#include <getopt.h>

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static char *elf_file = NULL;
static char *ftrace_log_file = NULL;
static char *etrace_log_file = NULL;
static char *mtrace_log_file = NULL;
static char *dtrace_log_file = NULL;
static int difftest_port = 1234;

static long load_img() {
  if (img_file == NULL) {
    panic("No image is given");
  }
  return platform_load_image(img_file);
}

static VerilatedVcdC *init_wave() {
#ifdef CONFIG_WAVE
  Verilated::traceEverOn(true);
  VerilatedVcdC *tfp = new VerilatedVcdC;
  g_top->trace(tfp, 99);
  tfp->open("waveform.vcd");
  return tfp;
#else
  return NULL;
#endif
}

static void reset_dut() {
  g_top->clock = 0;
  g_top->reset = 1;
  platform_set_external_idle(g_top);
  g_top->eval();
  g_contextp->timeInc(1);

  for (int i = 0; i < 10; i ++) {
    g_top->clock = 1;
    g_top->eval();
    g_contextp->timeInc(1);
    g_top->clock = 0;
    g_top->eval();
    g_contextp->timeInc(1);
  }
  g_top->reset = 0;
}

void npc_cleanup() {
  platform_cleanup();
#ifdef CONFIG_WAVE
  if (g_tfp != NULL) {
    g_tfp->close();
    delete g_tfp;
    g_tfp = NULL;
  }
#endif
  if (g_top != NULL) {
    delete g_top;
    g_top = NULL;
  }
  if (g_contextp != NULL) {
    delete g_contextp;
    g_contextp = NULL;
  }
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"elf"      , required_argument, NULL, 'f'},
    {"ftrace-log", required_argument, NULL, 'F'},
    {"etrace-log", required_argument, NULL, 'E'},
    {"mtrace-log", required_argument, NULL, 'M'},
    {"dtrace-log", required_argument, NULL, 'D'},
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhf:F:E:M:D:l:d:p:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'f': elf_file = optarg; break;
      case 'F': ftrace_log_file = optarg; break;
      case 'E': etrace_log_file = optarg; break;
      case 'M': mtrace_log_file = optarg; break;
      case 'D': dtrace_log_file = optarg; break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-f,--elf=FILE            load ELF symbols for ftrace\n");
        printf("\t-F,--ftrace-log=FILE     output ftrace to FILE\n");
        printf("\t-E,--etrace-log=FILE     output etrace to FILE\n");
        printf("\t-M,--mtrace-log=FILE     output mtrace to FILE\n");
        printf("\t-D,--dtrace-log=FILE     output dtrace to FILE\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

void init_monitor(int argc, char *argv[]) {
  /* Perform some global initialization. */

  /* Parse arguments. */
  parse_args(argc, argv);
  g_contextp = new VerilatedContext;
  g_contextp->commandArgs(argc, argv);
  g_top = new SimTop{g_contextp};

  /* Set random seed. */
  init_rand();

  /* Open the log file. */
  init_log(log_file);

#ifdef CONFIG_FTRACE
  init_ftrace_log(ftrace_log_file);
#endif
#ifdef CONFIG_ETRACE
  init_etrace_log(etrace_log_file);
#endif
#ifdef CONFIG_MTRACE
  init_mtrace_log(mtrace_log_file);
#endif
#ifdef CONFIG_DTRACE
  init_dtrace_log(dtrace_log_file);
#endif
#ifdef CONFIG_FTRACE
  init_ftrace(elf_file);
#endif

  /* Initialize memory. */
  init_mem();

  /* Perform ISA dependent initialization. */
  init_isa();

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();
  g_tfp = init_wave();

  platform_init();
  reset_dut();
  npc_reset_commit_state(platform_reset_pc());

  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);

  /* Initialize the simple debugger. */
  init_sdb();

  IFDEF(CONFIG_ITRACE, init_disasm());

  /* Display welcome message. */
  welcome();
}
