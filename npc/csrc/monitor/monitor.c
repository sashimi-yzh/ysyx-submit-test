#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <monitor.h>
#include <stdbool.h>
#include <stdint.h>
#include <inst.h>
#include <utils/utils.h>
#include <color.h>
#include <verilated.h>
#include <sys/time.h>

char* diff_so_file = NULL;
char* img_file  = NULL;


bool verbose = false;
void init_sim(int argc, char** argv);
void init_sdb();
void cpu_reset(int n);
void init_difftest(char *ref_so_file, long img_size, int port);
void init_mem();
void init_device();
void sdb_set_batch_mode();
void init_sig();
void init_pc_trace();
// uint64_t init_uptime(){
//   static uint64_t init_time = 0;

//   if(!init_time){
//       struct timeval tv;
//       gettimeofday(&tv, NULL);
//       init_time = tv.tv_sec * 1000000LL + tv.tv_usec - init_uptime();
//   }
//   return init_time;
// }
// uint64_t get_uptime(){
//   struct timeval tv;

//   gettimeofday(&tv, NULL);
//   return tv.tv_sec * 1000000LL + tv.tv_usec - init_uptime();
// }

static void welcome() {
  IFDEF(USE_NVBOARD, Log("USE Nvboard for Simulation."));
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  // IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
  //       "to record the trace. This may lead to a large log file. "
  //       "If it is not necessary, you can disable it in menuconfig"));
  Log("Dump Wave: %s", MUXDEF(CONFIG_WAVE_DUMP, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  MUXDEF(CONFIG_WAVE_DUMP, Log("Dump File Type: %s", MUXDEF(CONFIG_WAVE_VCD, "VCD", "FST")),);
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NPC!\n", ANSI_FG_YELLOW ANSI_BG_RED CONFIG_ISA COLOR_NONE);
  printf("For help, type \"help\"\n");
  //Log("Exercise: Please remove me in the source code and compile NEMU again.");
  //assert(0);
}




const char *get_img_file(){
        return img_file;
}




static int parse_args(int argc, char *argv[]) {
  for(int i=0; i<argc; i++){
      printf("argv[%d]: %s\n", i, argv[i]);
  }
  
  const struct option table[] = {
    {"help"     , no_argument      , NULL, 'h'},
    {"batch"    , no_argument      , NULL, 'b'},
    {"verbose"  , no_argument      , NULL, 'v'},
    {"diff"     , required_argument, NULL, 'd'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-hbvd:", table, NULL)) != -1) {
    switch (o) {
      case 'v': verbose = true; break; 
      case 'b': sdb_set_batch_mode(); break;
      case 'd': diff_so_file = optarg; break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-v,--verbose           print detail infomation of regs\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}



void init_monitor(int argc, char** argv){

  parse_args(argc, argv);
  init_sim(argc, argv);
  init_mem();
  init_sig();
#ifndef USE_SOC
  IFDEF(CONFIG_DEVICE, init_device());
#endif
  IFDEF(CONFIG_PC_TRACE, init_pc_trace());
  cpu_reset(13);
  long img_size = load_img();
  init_difftest(diff_so_file, img_size, 0);  //Do not need to use the  third parameter
  init_sdb();

  init_disasm(MUXDEF(CONFIG_RV32,"riscv32","riscv64"));
  welcome();
       
}

