#ifdef NV_BOARD
#include <nvboard.h>
#endif

#include <circuit.h>
#include <getopt.h>
#include <mem.h>
#include <utils.h>

void init_log(const char *log_file);
void init_pmem();
void init_difftest(char *ref_so_file, long img_size);
void init_device();
void init_sdb();
extern "C" void init_disasm(const char *triple);
void sdb_set_batch_mode();

static char *elf_file = NULL;
static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;



static void welcome() {
#ifdef NPCCONFIG_TOP_IS_YSYXSOC
    printf("Welcome to %s-ysyxsoc!\n", ANSI_FMT("riscv32e", ANSI_FG_YELLOW ANSI_BG_RED));
#endif
#ifdef NPCCONFIG_TOP_IS_NPC
    printf("Welcome to %s-npc!\n", ANSI_FMT("riscv32e", ANSI_FG_YELLOW ANSI_BG_RED));
#endif
    printf("For help, type \"help\"\n");
}


static long load_img() {
    if (img_file == NULL) {
      printf("============请传入IMG文件!============\n");
      return 1024;
    }
    FILE *fp = fopen(img_file, "rb");
    if(!fp){
        printf("============打开不了IMG文件 %s============\n", img_file);
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    printf("============IMG文件是 %s, 大小是 %ld============\n", img_file, size);
    fflush(stdout);
    fseek(fp, 0, SEEK_SET);
#ifdef NPCCONFIG_TOP_IS_YSYXSOC
    printf("============正在加载IMG到FLASH中, 地址是 %x============\n", FLASH_BASE);
    int ret = fread(guest_to_host(FLASH_BASE), size, 1, fp);
#endif
#ifdef NPCCONFIG_TOP_IS_NPC
    printf("============正在加载IMG到PMEM中, 地址是 %x============\n", CONFIG_MBASE);
    int ret = fread(guest_to_host(CONFIG_MBASE), size, 1, fp);
#endif
    assert(ret == 1);
    fclose(fp);
    printf("============加载IMG完毕============\n");
    return size;
}

static int parse_args(int argc, char *argv[]) {
    const struct option table[] = {
      {"elf"      , required_argument, NULL, 'e'},
      {"batch"    , no_argument      , NULL, 'b'},
      {"log"      , required_argument, NULL, 'l'},
      {"diff"     , required_argument, NULL, 'd'},
      {"help"     , no_argument      , NULL, 'h'},
      {0          , 0                , NULL,  0 },
    };
    int o;
    while ( (o = getopt_long(argc, argv, "-bhl:d:e:", table, NULL)) != -1) {
        switch (o) {
          case 'e': elf_file = optarg; break;
          case 'b': sdb_set_batch_mode(); break;
          case 'l': log_file = optarg; break;
          case 'd': diff_so_file = optarg; break;
          case 1: img_file = optarg; return 0;
          default:
            printf("\t-e,--elf=FILE           elf file pointed\n");
            printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
            printf("\t-b,--batch              run with batch mode\n");
            printf("\t-l,--log=FILE           output log to FILE\n");
            printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
            printf("\n");
            exit(0);
        }
    }
    return 0;
}

void init_monitor(int argc, char *argv[]) {
    /*初始化某些东西, 包括IMG等*/
    parse_args(argc, argv);
    parse_elf(elf_file);

    /*初始化内存*/
#ifdef NPCCONFIG_TOP_IS_YSYXSOC
    /*对于ysyxosc 只需要malloc flash sdram 以及 sram(在rocket-chip中通过reg实现了)*/
    init_flash();
    init_sdram();
#endif
#ifdef NPCCONFIG_TOP_IS_NPC
    /*对于npc 只需要malloc pmem(地址0x80000000)*/
    init_pmem();
#endif
    /*加载img到对应的内存中*/
    long img_size = load_img();

    /*初始化difftest*/
#ifdef NPCCONFIG_DIFFTEST
    init_difftest(diff_so_file, img_size);
    printf("============DIFFTEST初始化成功!============\n");
#endif
#ifdef NPCCONFIG_LIGHTSSS
    printf("============LIGHTSSS初始化成功!============\n");
#endif
#ifdef NPCCONFIG_DUMPWAVE
    printf("============DUMPWAVE初始化成功!============\n");
#endif
    init_disasm("riscv32-pc-linux-gnu");

    /*初始化sdb*/
    init_sdb();

    /*初始化NVBOARD*/
    #ifdef NV_BOARD
    nvboard_bind_all_pins(top);
    nvboard_init();
    printf("============NVBOARD初始化成功!============\n");
    #endif

    welcome();
}
