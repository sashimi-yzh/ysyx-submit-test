#include <common.h>
#include <getopt.h>
#ifdef CONFIG_BOARD
  void nvboard_bind_all_pins(TOP_NAME* dut);
#endif
static char *elf_file = NULL;
static char *diff_so_file = NULL;
static char *flash_file = NULL;
static int difftest_port = 1234;
bool sdb_set_batch_mode = false;
int npc_state = NPC_STOP;
extern void tick();
static inline void reset(int cycle) {
  top->clock = 0; 
  top->reset = 1; top->eval();
  while(cycle--) {
    tick(); 
  }
  top->reset = 0;
}

uint8_t flash[FLASH_SIZE] = {};
uint8_t dram[DRAM_SIZE] = {};
uint32_t sdram0[SDRAM_BANK_WIDTH][SDRAM_ROW_WIDTH][SDRAM_COL_WIDTH];
uint32_t sdram1[SDRAM_BANK_WIDTH][SDRAM_ROW_WIDTH][SDRAM_COL_WIDTH];
static long load_img() {
  char filename[1024];
  strcpy(filename, flash_file);
  FILE *fp = fopen(filename, "rb");
  if(fp == NULL) {
    printf("file not found\n");
    return 0;
  }
  size_t items_flash = fread(flash, sizeof(uint8_t), FLASH_SIZE, fp);
  printf("flash size: 0x%08lx\n", items_flash);
  fclose(fp);
  return items_flash;
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {"elf"      , required_argument, NULL, 'e'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhd:p:e:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode = true; break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'd': diff_so_file = optarg; break;
      case 'e': elf_file = optarg; break;
      case 1: flash_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\t-e,--elf=FILE           run Ftrace with file elf\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

void init_monitor(int argc, char *argv[]){
  gettimeofday(&tv, NULL);
  start_time = tv.tv_sec * 1000000 + tv.tv_usec;

  parse_args(argc, argv);
  long img_size = load_img();
#ifdef ITRACE_COND
  init_disasm();
#endif
#ifdef FTRACE_COND
  init_ftrace(elf_file);
#endif

#ifdef CONFIG_BOARD
  nvboard_bind_all_pins(top);
  nvboard_init();
#endif
  reset(10);
#ifdef DIFFTEST_COND
  printf("REF SO: %s\n", diff_so_file);
  init_difftest(diff_so_file, img_size, difftest_port);
#endif
}