#include "device.h"
#include "util.h"
#include "memory.h"
#include "npc.h"

#include <bits/getopt_core.h>
#include <getopt.h>
#include <iostream>


static const char* binfile = NULL;
static const char* elf_file = NULL;
static bool use_vcd = false;

// parse arguments
static int parse_args(int argc, char *argv[])
{
  void set_batch_mode();

  const struct option table[] = {
    {"bin"    , required_argument, NULL, 'b'},
    {"vcd"    , no_argument      , NULL, 'v'},
    {"run"    , no_argument      , NULL, 'r'},
    {"elf"    , required_argument, NULL, 'e'},
    {0        , 0                , NULL,  0 }
  };

  int o;
  while ( (o = getopt_long(argc, argv, "-b:vre:", table, NULL)) != -1) 
  {
    switch (o) 
    {
      case 'b': binfile = optarg; break;
      case 'v': use_vcd = true; break;
      case 'r': set_batch_mode(); break;
      case 'e': elf_file = optarg; break;
      default:
        printf("Usage: \n");
        printf("\t-b,--bin              Set binary file.\n");
        printf("\t-v,--vcd              Generate VCD waveform files.\n");
        printf("\t-r,--run              Run it directly without debugging.\n");
        printf("\t-e,--elf              Set elf file.\n");
        printf("\n");
        exit(0);
    }
  }

  return 0;
}  


// initialize all
bool initialize(int argc, char** argv)
{
  parse_args(argc, argv);

  if (!pmem_init(binfile)) return false;

  if (!init_elf(elf_file)) return false;
  
  init_disasm();

  void init_wp_pool();
  init_wp_pool();

  init_difftest(get_img_size(), 0);

  device_init();

  npc_init(use_vcd, argc, argv);

  return true;
}


// exit
void finalize(int code)
{
  void free_wp_pool();
  free_wp_pool();
  
  npc_free();
  
  exit(code);
}