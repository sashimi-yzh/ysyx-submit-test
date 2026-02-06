#include <dlfcn.h>
#include <getopt.h>
#include <common.h>
#include <paddr.h>
#include <time.h>
static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static int  difftest_port = 1234;
static char *elf_file = NULL;
void init_rand();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_disasm(const char *triple);
void init_log(const char *log_file);

void init_isa();
void sdb_set_batch_mode();
void init_mem();
void init_sdb();
void init_device();

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"elf"	, required_argument, NULL, 'e'},
    {"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:e:", table, NULL)) != -1) {
    switch (o) {
       
      case 'b': sdb_set_batch_mode(); break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'e':	elf_file = optarg;break;
      case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-e,--elf=FILE		  open the elf FILE\n");
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

static long long load_img() {
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.\n");
    return 4096;  //built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);
  fseek(fp, 0, SEEK_END);

  long long size = ftell(fp);
  Log("The image is %s, size = %ld\n", img_file, size);

  fseek(fp, 0, SEEK_SET);
  #ifdef YSYXSOC
  int ret = fread(guest_to_host(0x30000000), size, 1, fp);
  #else
  int ret = fread(guest_to_host(0x80000000), size, 1, fp);
  #endif
  assert(ret == 1);

  fclose(fp);
  return size;
}


static void welcome() {
  Log("Trace: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf(ANSI_FMT_GREEN "Welcome to riscv32 " ANSI_BG_RED ANSI_FMT_YELLOW "NPC" ANSI_FMT_NONE " !\n");
  printf("For help, type \"help\"\n");
  

}

void init_monitor(int argc, char** argv) {
  /* Perform some global initialization. */

  /* Parse arguments. */
  parse_args(argc, argv);
  //sdb_set_batch_mode();
  //parse_elf(elf_file);
  /* Set random seen. */
  init_rand();

  /* Open the log file. */
  init_log(log_file);

  /* Read the elf file. */
  

  /* Initial memory. */
  init_mem();

  /* Initialize device. */
 
  
  /* Perform ISA dependent initialization. */
  init_isa();

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();

#ifdef CONFIG_DIFFTEST
  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);
#endif

  /* Initialize the simple debugger. */
  init_sdb();
  //sdb_set_batch_mode();
  init_disasm("riscv32" "-pc-linux-gnu");
  /* Initialize the llvm */
  

  /* Display welcome message. */
  welcome();
}

static uint64_t boot_time = 0;

static uint64_t get_time_internal() {

    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC_COARSE, &now);
    uint64_t us = now.tv_sec * 1000000 + now.tv_nsec / 1000 ;

    return us;
}

uint64_t get_time() {
    if (boot_time == 0) boot_time = get_time_internal();
    uint64_t now = get_time_internal();
    return now - boot_time;
}

void init_rand() {
  srand(get_time_internal());
}

extern uint64_t g_nr_guest_inst;
FILE *log_fp = NULL;

void init_log(const char *log_file) {
  log_fp = stdout;
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "Can not open '%s'", log_file);
    log_fp = fp;
  }
  Log("Log is written to %s", log_file ? log_file : "stdout");
}

bool log_enable() {
  
    //return  (g_nr_guest_inst >= CONFIG_TRACE_START) && (g_nr_guest_inst <= CONFIG_TRACE_END);
    return  (g_nr_guest_inst >= 1) && (g_nr_guest_inst <= 10000);
  
}

