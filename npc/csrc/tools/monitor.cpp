#include <getopt.h>
#include <cassert>
#include "../include/common.h"
#include "../include/monitor.h"
#include "../include/trace.h"
#include "../include/switch.h"
#include "../include/memory.h"
#include "../include/debug.h"
#include "../include/macro.h"

unsigned char npc_logo[] = "\n"
"     ██████╗ ██╗██████╗ ███████╗██╗     ██╗███╗   ██╗███████╗    ███╗   ██╗██████╗  ██████╗\n"
"     ██╔══██╗██║██╔══██╗██╔════╝██║     ██║████╗  ██║██╔════╝    ████╗  ██║██╔══██╗██╔════╝\n"
"     ██████╔╝██║██████╔╝█████╗  ██║     ██║██╔██╗ ██║█████╗█████╗██╔██╗ ██║██████╔╝██║     \n"
"     ██╔═══╝ ██║██╔═══╝ ██╔══╝  ██║     ██║██║╚██╗██║██╔══╝╚════╝██║╚██╗██║██╔═══╝ ██║     \n"
"     ██║     ██║██║     ███████╗███████╗██║██║ ╚████║███████╗    ██║ ╚████║██║     ╚██████╗\n"
"     ╚═╝     ╚═╝╚═╝     ╚══════╝╚══════╝╚═╝╚═╝  ╚═══╝╚══════╝    ╚═╝  ╚═══╝╚═╝      ╚═════╝\n";

void init_difftest(char *ref_so_file, long img_size, int port);


static void welcome() {
  Log("WaveTrace: %s", MUXDEF(CONFIG_WAVE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_YELLOW)));
  Log("NVBoard:   %s", MUXDEF(CONFIG_NVBOARD, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_YELLOW)));
  Log("ITrace:    %s", MUXDEF(CONFIG_ITRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_YELLOW)));
  Log("MTrace:    %s", MUXDEF(CONFIG_MTRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_YELLOW)));
  Log("FTrace:    %s", MUXDEF(CONFIG_FTRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_YELLOW)));
  Log("Difftest:  %s", MUXDEF(CONFIG_DIFFTEST, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_YELLOW)));
  Log("If trace is enabled, a log file will be generated "
        "to record the trace. This may lead to a large log file. "
        "If it is not necessary, you can disable it in menuconfig");
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NPC!\n", ANSI_FMT("ysyxSoC", ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
  printf(ANSI_FG_GREEN "%s\n" ANSI_NONE, npc_logo);
}

#define no_argument 0
#define required_argument 1

static char *elf_file = NULL;
static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;

static long load_img() {
  if (img_file == NULL) {
    init_isa();
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  if (fp == NULL) {
    printf("Can not open '%s'\n", img_file);
    exit(EXIT_FAILURE);
    }

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The image is \033[1;33m%s\033[0m, size = \033[1;37m%ld\033[0m",img_file, size);

  fseek(fp, 0, SEEK_SET);
#ifdef CONFIG_YSYXSOC
  int ret = fread(SoC_to_host(FLASH_RESET_VECTOR), size, 1, fp);
#else
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
#endif
  assert(ret == 1);

  fclose(fp);
  return size;
}


static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"elf"      , required_argument, NULL, 'e'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bl:d:e:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 'e': elf_file = optarg; break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-e,--elf=FILE           elf file to be parsed\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

void init_monitor(int argc, char *argv[]) {

  parse_args(argc, argv);

#ifdef CONFIG_FTRACE
  /* Parse elf file. */
  parse_elf(elf_file);
#endif

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();

  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);
  
  /* Initialize the device */
  init_device();

  welcome();
}
