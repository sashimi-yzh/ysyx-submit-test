
// #include <isa.h>
#include "../include/paddr.h"
#include "../include/common.h"
#include "../include/debug.h"
#include "../include/utils.h"
#include "../include/difftest.h"
#include <elf.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


void init_log(const char *log_file);
void init_mem();
void init_sdb();
void init_device();
extern uint8_t* soc_flash_guest_to_host(paddr_t paddr);
extern uint8_t* soc_mrom_guest_to_host(paddr_t paddr);

unsigned char npc_logo[] = {
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5f, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5f, 0x20, 0x5f,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x5f,
  0x20, 0x5f, 0x5f, 0x20, 0x28, 0x5f, 0x29, 0x5f, 0x20, 0x5f, 0x5f, 0x20,
  0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x7c, 0x20, 0x28, 0x5f, 0x29, 0x5f, 0x20,
  0x5f, 0x5f, 0x20, 0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x20,
  0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x20, 0x0a, 0x7c, 0x20, 0x27, 0x5f, 0x20,
  0x5c, 0x7c, 0x20, 0x7c, 0x20, 0x27, 0x5f, 0x20, 0x5c, 0x20, 0x2f, 0x20,
  0x5f, 0x20, 0x5c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x27, 0x5f, 0x20, 0x5c,
  0x20, 0x2f, 0x20, 0x5f, 0x20, 0x5c, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x2f,
  0x20, 0x5f, 0x5f, 0x7c, 0x2f, 0x20, 0x5f, 0x20, 0x5c, 0x20, 0x2f, 0x20,
  0x5f, 0x5f, 0x7c, 0x0a, 0x7c, 0x20, 0x7c, 0x5f, 0x29, 0x20, 0x7c, 0x20,
  0x7c, 0x20, 0x7c, 0x5f, 0x29, 0x20, 0x7c, 0x20, 0x20, 0x5f, 0x5f, 0x2f,
  0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x20,
  0x5f, 0x5f, 0x2f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5c, 0x5f, 0x5f, 0x20,
  0x5c, 0x20, 0x28, 0x5f, 0x29, 0x20, 0x7c, 0x20, 0x28, 0x5f, 0x5f, 0x20,
  0x0a, 0x7c, 0x20, 0x2e, 0x5f, 0x5f, 0x2f, 0x7c, 0x5f, 0x7c, 0x20, 0x2e,
  0x5f, 0x5f, 0x2f, 0x20, 0x5c, 0x5f, 0x5f, 0x5f, 0x7c, 0x5f, 0x7c, 0x5f,
  0x7c, 0x5f, 0x7c, 0x20, 0x7c, 0x5f, 0x7c, 0x5c, 0x5f, 0x5f, 0x5f, 0x7c,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x7c, 0x5f, 0x5f, 0x5f, 0x2f, 0x5c, 0x5f,
  0x5f, 0x5f, 0x2f, 0x20, 0x5c, 0x5f, 0x5f, 0x5f, 0x7c, 0x0a, 0x7c, 0x5f,
  0x7c, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7c, 0x5f, 0x7c, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0a, '\0'
};

unsigned char fpu_logo[] = {
  0x0a, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x5f,
  0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x5f, 0x5f, 0x5f,
  0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x7c,
  0x5c, 0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5c, 0x5c, 0x20, 0x20,
  0x20, 0x5f, 0x5f, 0x20, 0x20, 0x5c, 0x7c, 0x5c, 0x20, 0x20, 0x5c, 0x7c,
  0x5c, 0x20, 0x20, 0x5c, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x5c, 0x20, 0x5c,
  0x20, 0x20, 0x5c, 0x5f, 0x5f, 0x2f, 0x5c, 0x20, 0x5c, 0x20, 0x20, 0x5c,
  0x7c, 0x5c, 0x20, 0x20, 0x5c, 0x20, 0x5c, 0x20, 0x20, 0x5c, 0x5c, 0x5c,
  0x20, 0x20, 0x5c, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x5c, 0x20, 0x5c, 0x20,
  0x20, 0x20, 0x5f, 0x5f, 0x5c, 0x5c, 0x20, 0x5c, 0x20, 0x20, 0x20, 0x5f,
  0x5f, 0x5f, 0x5f, 0x5c, 0x20, 0x5c, 0x20, 0x20, 0x5c, 0x5c, 0x5c, 0x20,
  0x20, 0x5c, 0x20, 0x20, 0x0a, 0x20, 0x20, 0x5c, 0x20, 0x5c, 0x20, 0x20,
  0x5c, 0x5f, 0x7c, 0x20, 0x5c, 0x20, 0x5c, 0x20, 0x20, 0x5c, 0x5f, 0x5f,
  0x5f, 0x7c, 0x5c, 0x20, 0x5c, 0x20, 0x20, 0x5c, 0x5c, 0x5c, 0x20, 0x20,
  0x5c, 0x20, 0x0a, 0x20, 0x20, 0x20, 0x5c, 0x20, 0x5c, 0x5f, 0x5f, 0x5c,
  0x20, 0x20, 0x20, 0x5c, 0x20, 0x5c, 0x5f, 0x5f, 0x5c, 0x20, 0x20, 0x20,
  0x20, 0x5c, 0x20, 0x5c, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5c,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x7c, 0x5f, 0x5f, 0x7c, 0x20, 0x20,
  0x20, 0x20, 0x5c, 0x7c, 0x5f, 0x5f, 0x7c, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x5c, 0x7c, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x7c, 0x20, 0x0a,
  '\0'
};

static void welcome() {
  Log("Wave: %s", MUXDEF(CONFIG_WAVE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("MTrace: %s", MUXDEF(CONFIG_MTRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("ITrace: %s", MUXDEF(CONFIG_ITRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("FTrace: %s", MUXDEF(CONFIG_FTRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("NVBOARD: %s", MUXDEF(NVBOARD, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("Difftest: %s", MUXDEF(CONFIG_DIFFTEST, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
        "to record the trace. This may lead to a large log file. "
        "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NPC!\n", ANSI_FMT("RISCV32e", ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
  printf("\n\33[35m%s\33[0m\n", npc_logo);
  IFDEF(FPU, printf("\n\33[34m%s\33[0m\n", fpu_logo));
}

// #ifndef CONFIG_TARGET_AM
#include <getopt.h>

void sdb_set_batch_mode();

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *elf_file = NULL;
static char *img_file = NULL;
// static char *dram_file = NULL;
static int difftest_port = 1234;

// static long load_dram() {//用于加载数据文件(用于竞业达比赛测试)
//   if (dram_file == NULL) {
//     Log("No dram is given.");
//     return 4096; // built-in image size
//   }

//   FILE *fp = fopen(dram_file, "rb");
//   Assert(fp, "Can not open '%s'", dram_file);

//   fseek(fp, 0, SEEK_END);
//   long size = ftell(fp);

//   Log("The dram is %s, size = %ld", dram_file, size);

//   fseek(fp, 0, SEEK_SET);
//   int ret = fread(guest_to_host(RESET_VECTOR + 0x100000), size, 1, fp);
//   assert(ret == 1);

//   fclose(fp);
//   return size;
// }

static long load_img() {//load_img函数用于加载镜像文件
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  // Log("The image is %s, size = %ld", img_file, size);
  printf("The image is \033[33m%s\033[0m, size = \033[33m%ld\033[0m\n", img_file, size);

  fseek(fp, 0, SEEK_SET);
  
  #ifdef YSYXSOC
  int ret = fread(soc_flash_guest_to_host(CONFIG_SOC_FLASH_BASE), size, 1, fp);
  #else
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  #endif

  assert(ret == 1);

  fclose(fp);
  return size;
}

typedef struct {
  uint32_t addr;  // 函数地址
  uint32_t size;  // 函数大小
  char name[64];  // 函数名
} func_symbol_t;

func_symbol_t func_table[4096]; // 符号表
int func_count = 0;             // 符号数量
// #define CODE_BASE_ADDR 0x80000000;  

void load_func_table(const char *elf_file) {
  // 打开ELF文件
  FILE* fp = fopen(elf_file, "rb");
  Assert(fp, "Can not open '%s'", elf_file);
  
  // 获取文件大小
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  Log("The ELF file is %s, size = %ld", elf_file, size);
  printf("[ftrace log] : The ELF file is %s, size = %ld\n", elf_file, size);

  /*=== 读取ELF头 ===*/
  fseek(fp, 0, SEEK_SET);  // 回到文件起始位置
  Elf32_Ehdr elf_header;   // ELF文件头结构
  assert(fread(&elf_header, sizeof(Elf32_Ehdr), 1, fp)==1);  // 读取文件头

  /*=== 读取节头表 ===*/
  fseek(fp, elf_header.e_shoff, SEEK_SET);  // 定位到节头表起始位置
  Elf32_Shdr sh_table[elf_header.e_shnum];  // 创建节头表数组
  // 读取所有节头表条目
  assert(fread(sh_table, sizeof(Elf32_Shdr), elf_header.e_shnum, fp)==elf_header.e_shnum);

  /*=== 定位符号表和字符串表 ===*/
  Elf32_Shdr *symtab = NULL;  // 符号表指针
  Elf32_Shdr *strtab = NULL;  // 字符串表指针
  for (int i = 0; i < elf_header.e_shnum; i++) {
    // 查找符号表(SHT_SYMTAB类型)
    if (sh_table[i].sh_type == SHT_SYMTAB) {
      symtab = &sh_table[i];
    }
    // 查找字符串表(排除节名字符串表)
    if (sh_table[i].sh_type == SHT_STRTAB && i != elf_header.e_shstrndx) {
      strtab = &sh_table[i];
    }
  }
  Assert(symtab && strtab, "Failed to locate symbol table or string table");

  /*=== 读取符号表数据 ===*/
  // 计算符号数量并创建缓冲区
  Elf32_Sym symbols[symtab->sh_size / sizeof(Elf32_Sym)];
  fseek(fp, symtab->sh_offset, SEEK_SET);  // 定位符号表数据起始位置
  assert(fread(symbols, symtab->sh_size, 1, fp)==1);  // 读取整个符号表

  /*=== 读取字符串表数据 ===*/
  char strtab_data[strtab->sh_size];  // 创建字符串表缓冲区
  fseek(fp, strtab->sh_offset, SEEK_SET);  // 定位字符串表起始位置
  assert(fread(strtab_data, strtab->sh_size, 1, fp)==1);  // 读取整个字符串表

  /*=== 解析函数符号 ===*/
  func_count = 0; 
  for (int i = 0; i < symtab->sh_size / sizeof(Elf32_Sym); i++) {
    // 只处理函数类型符号(STT_FUNC)
    if (ELF32_ST_TYPE(symbols[i].st_info) == STT_FUNC) {
      // 填充符号表条目
      func_table[func_count].addr = symbols[i].st_value;  // 函数地址
      func_table[func_count].size = symbols[i].st_size;   // 函数大小
      
      // 从字符串表复制函数名称
      strncpy(func_table[func_count].name, 
             &strtab_data[symbols[i].st_name], 
             sizeof(func_table[func_count].name) - 1);
      func_table[func_count].name[sizeof(func_table[func_count].name) - 1] = '\0';
      func_count++;  // 递增有效符号计数
    }
  }
  fclose(fp);
  Log("Loaded %d function symbols from ELF file", func_count);
}

//init_log函数用于初始化日志文件
// extern uint64_t g_nr_guest_inst;

// #ifndef CONFIG_TARGET_AM
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

// bool log_enable() {
//   return MUXDEF(CONFIG_TRACE, (g_nr_guest_inst >= CONFIG_TRACE_START) &&
//          (g_nr_guest_inst <= CONFIG_TRACE_END), false);
// }
// #endif



static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"elf"      , required_argument, NULL, 'e'},
    // {"target"   , required_argument, NULL, 't'},
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:e:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 'e': elf_file = optarg;  break;
      // case 't': dram_file = optarg;   "-bhl:d:p:e:t:"
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\t-e,--elf=ELF_FILE       load ELF file for ftrace\n");
        // printf("\t-t,--target=DRAM_FILE   load DRAM file\n");
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
  // init_rand();

  /* Open the log file. */
  init_log(log_file);
  
  /* Load ELF file */
#ifdef CONFIG_FTRACE
    if (elf_file != NULL) {
        load_func_table(elf_file);
    }
#endif
  /* Initialize memory. */
  init_mem();

  /* Initialize devices. */
  IFDEF(CONFIG_DEVICE, init_device());
  IFDEF(CONFIG_MTRACE,init_mtrace());
  /* Perform ISA dependent initialization. */

  // long dram_size = load_dram();

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();

  /* Initialize differential testing. */
#ifdef CONFIG_DIFFTEST
  if(diff_so_file!=NULL){
    printf("Get difftest file : %s\n",diff_so_file);
    init_difftest(diff_so_file, img_size, difftest_port);
  }
#endif
  /* Initialize the simple debugger. */
  init_sdb();

  // IFDEF(CONFIG_ITRACE, init_disasm());

  /* Display welcome message. */
  welcome();
}