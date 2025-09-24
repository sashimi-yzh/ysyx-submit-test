#include <common.h>
#include <getopt.h>
#include <isa.h>
#include <memory/paddr.h>
#include <perf_counter.h>

void init_rand();
void init_log(const char *log_file);
void init_trace(const char *trace_file);
void init_ftrace(const char *elf_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_sdb();
void init_disasm(const char *triple);
void sdb_set_batch_mode();
extern PerfCounter pf;

static void welcome() {
  IFDEF(CONFIG_FAST_SIM, Log("FAST SIM: %s", ANSI_FMT("ON", ANSI_FG_GREEN)));
  IFDEF(CONFIG_TRACE, Log("Trace: %s", ANSI_FMT("ON", ANSI_FG_GREEN)));
  IFDEF(CONFIG_WAVE, Log("Waveform: %s", ANSI_FMT("ON", ANSI_FG_GREEN)));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-%s!\n",
         ANSI_FMT("riscv32e", ANSI_FG_YELLOW ANSI_BG_RED),
         ANSI_FG_GREEN MUXDEF(ysyx_23060170_NPC, "npc", "ysyxSoC") ANSI_NONE);
  printf("For help, type \"help\"\n");
}

static char *log_file = NULL;
static char *trace_file = NULL;
static char *elf_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;

static long load_img() {
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

static long load_flash() {
  const char *flash_file = "/home/xhf/ysyx-workbench/npc/test/char-test.bin";
  FILE *fp = fopen(flash_file, "rb");
  Assert(fp, "Can not open '%s'", flash_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The flash is %s, size = %ld", flash_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(FLASH_LEFT), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
      {"batch", no_argument, NULL, 'b'},
      {"log", required_argument, NULL, 'l'},
      {"perfcounter", required_argument, NULL, 'c'},
      {"trace", required_argument, NULL, 't'},
      {"elf", required_argument, NULL, 'e'},
      {"diff", required_argument, NULL, 'd'},
      {"port", required_argument, NULL, 'p'},
      {"help", no_argument, NULL, 'h'},
      {0, 0, NULL, 0},
  };
  int o;
  while ((o = getopt_long(argc, argv, "-bhl:c:t:e:d:p:", table, NULL)) != -1) {
    switch (o) {
    case 'b':
      sdb_set_batch_mode();
      break;
    case 'p':
      sscanf(optarg, "%d", &difftest_port);
      break;
    case 'l':
      log_file = optarg;
      break;
    case 'c':
      pf.setFileName(optarg);
      break;
    case 't':
      trace_file = optarg;
      break;
    case 'e':
      elf_file = optarg;
      break;
    case 'd':
      diff_so_file = optarg;
      break;
    case 1:
      img_file = optarg;
      return 0;
    default:
      printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
      printf("\t-b,--batch              run with batch mode\n");
      printf("\t-l,--log=FILE           output log to FILE\n");
      printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
      printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
      printf("\n");
      exit(0);
    }
  }
  return 0;
}

static const uint32_t img[] = {
    0x00400293, // addi t0, $0, #4
    0x00500293, // addi t0, $0, #5
    0x00600293, // addi t0, $0, #6
    0x00700293, // addi t0, $0, #7
    0x00800293, // addi t0, $0, #8
    0x00900293, // addi t0, $0, #9
    0x00a00293, // addi t0, $0, #10
    0x100007b7, // lui a5,0xa0000
    0x05800513, // addi a0, $0, 'X'
    0x00a78023, // sb a0,0(a5)
    0x04800513, // addi a0, $0, 'H'
    0x00a78023, // sb a0,0(a5)
    0x04600513, // addi a0, $0, 'F'
    0x00a78023, // sb a0,0(a5)
    0x00a00513, // addi a0, $0, '\n'
    0x00a78023, // sb a0,0(a5)
    0x00000513, // addi a0, $0, #0
    0x00100073, // ebreak (used as npc_trap)
    0xdeadbeef, // some data
};

static void restart() {
  cpu.pc = RESET_VECTOR;
  cpu.csr[MSTATUS] = 0x1800;
  cpu.csr[MCAUSE] = 0xb;
}

void init_isa() {
  /* Load built-in image. */
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));

  /* Initialize this virtual computer system. */
  restart();
}

void init_monitor(int argc, char *argv[]) {

  parse_args(argc, argv);

  IFNDEF(CONFIG_SDB, sdb_set_batch_mode());

  init_rand();

  init_log(log_file);

  init_trace(trace_file);

  IFDEF(CONFIG_FTRACE, init_ftrace(elf_file));

  init_mem();

  init_isa();

  long img_size = load_img();

  // load_flash();

  init_difftest(diff_so_file, img_size, difftest_port);

  init_sdb();

  init_disasm("riscv32-pc-linux-gnu");

  welcome();

  sim_init();
}
