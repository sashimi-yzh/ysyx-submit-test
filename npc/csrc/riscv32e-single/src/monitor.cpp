#include <common.h>
#include <getopt.h>
static char *img_file = NULL;
static char *elf_file = NULL;
static char *diff_so_file = NULL;
static int difftest_port = 1234;
bool sdb_set_batch_mode = false;
int npc_state = NPC_STOP;

void reset (int reset_cycle) {
  riscv32e_top->rst_n = 0;
  while(reset_cycle--) {
    riscv32e_top->clk = 1; riscv32e_top->eval();
    #ifdef CONFIG_WAVEFORM
    contextp->timeInc(1); tfp->dump(contextp->time());
    #endif
    riscv32e_top->clk = 0; riscv32e_top->eval();
    #ifdef CONFIG_WAVEFORM
    contextp->timeInc(1); tfp->dump(contextp->time());
    #endif
  }
  riscv32e_top->rst_n = 1;
}

static long load_img() {
  char filename[1024];
  strcpy(filename, img_file);
  FILE *fp = fopen(filename, "rb");
  if(fp == NULL) {
    printf("file not found\n");
    return 0;
  }
  size_t items = fread(mem, sizeof(uint8_t), CONFIG_MSIZE, fp);
  if(strcmp(filename, "resource/mem.bin") == 0){
      mem[0x1220] = 0x73;
      mem[1 + 0x1220] = 0;
      mem[2 + 0x1220] = 0x10;
      mem[3 + 0x1220] = 0;
  }
  else if(strcmp(filename, "resource/sum.bin") == 0){
      mem[0x228] = 0x73;
      mem[1 + 0x228] = 0;
      mem[2 + 0x228] = 0x10;
      mem[3 + 0x228] = 0;
  }
  printf("load file success, items: %lu\n", items);
  fclose(fp);
  return items;
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
  while ( (o = getopt_long(argc, argv, "-bhd:p:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode = true; break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'd': diff_so_file = optarg; break;
      case 'e': elf_file = optarg; break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\t-e,--elf=FILE           run DiffTest with port PORT\n");
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
  reset(10);
#ifdef ITRACE_COND
  init_disasm();
#endif
#ifdef FTRACE_COND
  init_ftrace(elf_file);
#endif
#ifdef DIFFTEST_COND
  printf("REF SO: %s\n", diff_so_file);
  init_difftest(diff_so_file, img_size, difftest_port);
#endif
}