#include <isa.h>
#include <getopt.h>
#include <memory/paddr.h>

static char *log_file = NULL;
static char *log_file_m = NULL;
static char *log_file_f = NULL;
static char *log_file_d = NULL;
static char *elf_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;
static char *diff_so_file = NULL;

void init_rand();
void init_log(const char *log_file);
void init_log_mem(const char *log_file);
void init_log_func(const char *log_file);
void init_log_dev(const char *log_file);
void init_elf(const char* elf_file);
void init_mem();
void init_sdb();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_verilator_env(int argc, char *argv[]);
void init_device();
void init_disasm(const char *triple);
void sdb_set_batch_mode();

static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
        "to record the trace. This may lead to a large log file. "
        "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NPC!\n", ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
}

static long load_img() {
  if (img_file == NULL) {
    printf("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  printf("The image is %s, size = %ld\n", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"log"      , required_argument, NULL, 'l'},
    {"log_m"    , required_argument, NULL, 'm'},
    {"log_f"    , required_argument, NULL, 'f'},
    {"log_d"    , required_argument, NULL, 'x'},
    {"ld_elf"   , required_argument, NULL, 'e'},
    {"diff"     , required_argument, NULL, 'd'},
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bl:m:e:f:d:x:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'l': log_file = optarg; break;
      case 'm': log_file_m = optarg; break;
      case 'f': log_file_f = optarg; break;
      case 'x': log_file_d = optarg; break;
      case 'e': elf_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 1: img_file = optarg; break;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-m,--log_m=FILE         output mtrace log to FILE\n");
        printf("\t-f,--log_f=FILE         output ftrace log to FILE\n");
        printf("\t-x,--log_d=FILE         output dtrace log to FILE\n");
        printf("\t-e,--ld_elf=FILE        load elf FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
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

  /* Set random seed. */
  init_rand();

  /* Open the log file. */
  init_log(log_file);
  init_log_mem(log_file_m);
  init_log_func(log_file_f);
  init_log_dev(log_file_d);

  /* Load elf symbols. */
  init_elf(elf_file);

  /* Initialize memory. */
  init_mem();

  /* Initialize devices. */
  IFDEF(CONFIG_DEVICE, init_device());

  /* Init verilator env */
  init_verilator_env(argc, argv);

  /* Perform ISA dependent initialization. */
  init_isa();

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();

  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);

  /* Initialize the simple debugger. */
  init_sdb();

#ifndef CONFIG_ISA_loongarch32r
  IFDEF(CONFIG_ITRACE, init_disasm(
    MUXDEF(CONFIG_ISA_x86,     "i686",
    MUXDEF(CONFIG_ISA_mips32,  "mipsel",
    MUXDEF(CONFIG_ISA_riscv,
      MUXDEF(CONFIG_RV64,      "riscv64",
                               "riscv32"),
                               "bad"))) "-pc-linux-gnu"
  ));
#endif

  /* Display welcome message. */
  welcome();
}