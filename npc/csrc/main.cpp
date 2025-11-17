#include <nvboard.h>
#include <common.h>
#include <memory/memory.h>
#include <device/device.h>
#include <cpu/cpu.h>
#include <cpu/difftest.h>
#include <isa.h>
#include <getopt.h>
#include <utils.h>
#include "monitor/sdb.h"
#include "verilated.h"

char* img_file = NULL;
char* log_file = NULL;
char* flash_img_file = NULL;
char* diff_so_file = NULL;
char* perf_file = NULL;
static int difftest_port = 1234;

void sdb_set_batch_mode();
void init_log(const char*);
void init_device();
int is_exit_status_bad();

long load_prog() {
    if (!img_file){
        printf("Use default img\n");
        return sizeof(img);
    }
    printf("use image: %s \n",img_file);
    FILE *fp = fopen(img_file, "rb");
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    int ret;
    ret=fread(guest_to_host(MBASE), 1, size, fp);
    printf("load image size: %d bytes\n",ret);
    // IFDEF(CONFIG_SOC,ret=fread(guest_to_mrom(CONFIG_MROM_BASE), 1, size, fp));
    // IFNDEF(CONFIG_SOC,ret=fread(guest_to_host(MBASE), 1, size, fp));
    assert(ret == size);
    fclose(fp);
    
    return size;
}

long load_flash_prog() {
    if (!flash_img_file){
        return 0;
    }
    printf("flash use image: %s \n",flash_img_file);
    FILE *fp = fopen(flash_img_file, "rb");
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    int ret=fread(guest_to_host(MBASE), 1, size, fp);
    printf("load flash image size: %d bytes\n",ret);
    // IFDEF(CONFIG_SOC,ret=fread(guest_to_mrom(CONFIG_MROM_BASE), 1, size, fp));
    // IFNDEF(CONFIG_SOC,ret=fread(guest_to_host(MBASE), 1, size, fp));
    assert(ret == size);
    fclose(fp);
    
    return size;
}




static int parse_args(int argc, char **argv) {
  const struct option table[] = {
    {"batch"      , no_argument      , NULL, 'b'},
    {"perf"       , required_argument, NULL, 'P'},
    {"log"        , required_argument, NULL, 'l'},
    {"diff"       , required_argument, NULL, 'd'},
    {"port"       , required_argument, NULL, 'p'},
    {"flash_file" , required_argument, NULL, 'f'},
    // {"help"     , no_argument      , NULL, 'h'},
    // {"elf"      , required_argument, NULL, 'e'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:e:f:P:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
    //   case 'e': elf_file = optarg;break;
      case 'f': flash_img_file = optarg;break;
      case 'P': perf_file = optarg;break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\t-P,--perf=perf_file     enable record perf for commit\n");
        printf("\t-f,--flash_file=FLASH_FILE        run load FLASH_FILE into flash\n");
        printf("\n");
        exit(0);
    }
  }
  Verilated::commandArgs(argc, argv);
  return 0;
}

int main(int argc, char** argv) {
    parse_args(argc, argv);
    
    init_memory();
    init_sdb();
    IFDEF(CONFIG_DEVICE, init_device());

    init_isa();
    
    init_log(log_file);
    
    #ifdef CONFIG_ITRACE
    init_itrace();
    #endif
    
    long img_size = load_prog();
    long flash_img_size = load_flash_prog();
    init_cpu(argc,argv);
    #ifdef CONFIG_DIFFTEST
    init_difftest(diff_so_file, img_size, difftest_port);
    #endif
    sdb_mainloop();
    free_cpu();

    // Return good completion status
    return is_exit_status_bad();
}
