/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <elf.h>
#include <memory/paddr.h>

void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_disasm();

static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("ITrace: %s", MUXDEF(CONFIG_ITRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("BTrace: %s", MUXDEF(CONFIG_BTRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("MTrace: %s", MUXDEF(CONFIG_MTRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("FTrace: %s", MUXDEF(CONFIG_FTRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("DTrace: %s", MUXDEF(CONFIG_DTRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("ETrace: %s", MUXDEF(CONFIG_ETRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("Watchpoint: %s", MUXDEF(CONFIG_WATCHPOINT, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  // Log("DTrace: %s", MUXDEF(CONFIG_DTRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
        "to record the trace. This may lead to a large log file. "
        "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NEMU!\n", ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>

void sdb_set_batch_mode();

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;

static int difftest_port = 1234;

static long load_img() {
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

static char *trace_fie = NULL;
//==================================================
// branch trace bin内容
//==================================================
#ifdef CONFIG_BTRACE
FILE *tracebin_fp = NULL;
void init_tracebin() {
    Assert(trace_fie, "你需要给一个bin文件的地址,用于记录branch trace bin");
    tracebin_fp = fopen(trace_fie, "wb");
    Assert(tracebin_fp, "打不开文件 '%s'", trace_fie);
}
#endif
//==================================================
// 写入 DTACER 文件
//==================================================
static char *dtracer_log_file = NULL;
#ifdef CONFIG_DTRACE
void init_dtracer_log(const char *dtracer_log_file);
#endif
//==================================================
// 加载elf文件和写入ftracer
//==================================================
static char *elf_file = NULL;
static char *ftracer_log_file = NULL;
#ifdef CONFIG_FTRACE
struct FUNC_FTRACE ELF_FUNC_FTRACER[128] = {0};
struct FUNC_FTRACE USER_FUNC_FTRACER[16] = {
  {.addr = 0x800006a0, .func_name = "main"},
  {.addr = 0x80000474, .func_name = "video_init"},
  {.addr = 0x800000e4, .func_name = "game_logic_update"},
  {.addr = 0x80000010, .func_name = "new_char"},
  {.addr = 0x800001b0, .func_name = "render"},
  {.addr = 0x80000c9c, .func_name = "printf"},
  {.addr = 0x800003a8, .func_name = "check_hit"},
  {.addr = 0x800008b0, .func_name = "halt"},
};
struct FUNC_FTRACE *FUNC_FTRACER = ELF_FUNC_FTRACER;
int FUNC_nums = ARRLEN(ELF_FUNC_FTRACER);
bool use_user_func = false;

static void load_elf() {
  if (elf_file == NULL) {
    Log("没有elf文件输入\n");
    return; // built-in image size
  }
  FILE *file = fopen(elf_file, "rb");
  Assert(file, "无法打开elf文件");
  // 读取 ELF 文件头
  Elf32_Ehdr ehdr;
  if (fread(&ehdr, 1, sizeof(ehdr), file) != sizeof(ehdr)) {
    printf("Failed to read ELF header\n");
    fclose(file);
    return;
  }
  // 检查 ELF 魔数
  if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
      printf("Not a valid ELF file\n");
      fclose(file);
      return;
  }
  // 定位到节头表
  fseek(file, ehdr.e_shoff, SEEK_SET);
  // 读取节头表
  Elf32_Shdr *sh_table = malloc(ehdr.e_shentsize * ehdr.e_shnum);
  if (fread(sh_table, ehdr.e_shentsize, ehdr.e_shnum, file) != ehdr.e_shnum) {
    printf("Failed to read section header table\n");
    free(sh_table);
    fclose(file);
    return;
  }
  // 找到字符串表节（.strtab）
  const char *strtab = NULL;
  size_t strtab_size = 0;
  for (int i = 0; i < ehdr.e_shnum; i++) {
      if (sh_table[i].sh_type == SHT_STRTAB && i != ehdr.e_shstrndx) {
          strtab_size = sh_table[i].sh_size;
          strtab = malloc(strtab_size);
          fseek(file, sh_table[i].sh_offset, SEEK_SET);
          if (fread((void *)strtab, 1, strtab_size, file) != strtab_size) {
            printf("Failed to read string table\n");
            free((void *)strtab);
            free(sh_table);
            fclose(file);
            return;
          }
          break;
      }
  }
  // 找到符号表节（.symtab）
  for (int i = 0; i < ehdr.e_shnum; i++) {
      if (sh_table[i].sh_type == SHT_SYMTAB) {
          size_t symtab_size = sh_table[i].sh_size;
          size_t symtab_entry_count = symtab_size / sh_table[i].sh_entsize;
          Elf32_Sym *symtab = malloc(symtab_size);
          fseek(file, sh_table[i].sh_offset, SEEK_SET);
          if (fread(symtab, sh_table[i].sh_entsize, symtab_entry_count, file) != symtab_entry_count) {
            printf("Failed to read symbol table\n");
            free(symtab);
            free((void *)strtab);
            free(sh_table);
            fclose(file);
            return;
          }
          // 遍历符号表,筛选各个函数名的入口地址
          for (int j = 0, k = 0; j < symtab_entry_count; j++) {
              if (ELF32_ST_TYPE(symtab[j].st_info) == STT_FUNC) {
                  ELF_FUNC_FTRACER[k].addr = symtab[j].st_value;
                  strncpy(ELF_FUNC_FTRACER[k].func_name, &strtab[symtab[j].st_name], sizeof(ELF_FUNC_FTRACER[k].func_name) - 1);
                  ELF_FUNC_FTRACER[k].func_name[sizeof(ELF_FUNC_FTRACER[k].func_name) - 1] = '\0';
                  k++;
              }
          }
          free(symtab);
          break;
      }
  }
  // 清理资源
  free((void *)strtab);
  free(sh_table);
  fclose(file);
  // 检查是否需要指定追踪的函数
  if(use_user_func) {
    FUNC_FTRACER = USER_FUNC_FTRACER;
    FUNC_nums = ARRLEN(USER_FUNC_FTRACER);
  }
}

// 设置 ftracer 的输出

void init_ftracer_log(const char *ftracer_log_file);
#endif
//==================================================

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"      , no_argument      , NULL, 'b'},
    {"log"        , required_argument, NULL, 'l'},
    {"branchbin"  , required_argument, NULL, 'r'},
    {"diff"       , required_argument, NULL, 'd'},
    {"port"       , required_argument, NULL, 'p'},
    {"elf"        , required_argument, NULL, 'e'},  // 读取elf文件
    {"elf-log"    , required_argument, NULL, 'g'},  // 写入ftracer的内容
    {"dtrace-log" , required_argument, NULL, 'k'},  // 写入DTRACE的内容
    {"image"      , required_argument, NULL, 'i'},
    {"help"       , no_argument      , NULL, 'h'},
    {0            , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:r:d:p:e:g:k:i:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'l': log_file = optarg; break;
      case 'r': trace_fie = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'e': elf_file = optarg; break;
      case 'g': ftracer_log_file = optarg; break;
      case 'k': dtracer_log_file = optarg; break;
      case 'i': img_file = optarg; break;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-h,--help                      print this help message\n");
        printf("\t-b,--batch                     run with batch mode\n");
        printf("\t-l,--log=FILE                  output log to FILE\n");
        printf("\t-r,--tracebin=trace_fie        trace bin for branch/cache predictor\n");
        printf("\t-d,--diff=REF_SO               run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT                 run DiffTest with port PORT\n");
        printf("\t-e,--elf=ELF_FILE              load elf file for ftrace\n");
        printf("\t-g,--elf-log=FTRACER_FILE      ftracer output log to FTRACER_FILE\n");
        printf("\t-k,--dtrace-log=DTRACER_FILE   ftracer output log to DTRACER_FILE\n");
        printf("\t-i,--image=IMG_FILE            load program from IMG_FILE\n");
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

  /* Initialize memory. */
  init_mem();

  /* Initialize devices. */
  IFDEF(CONFIG_DEVICE, init_device());

  /* Perform ISA dependent initialization. */
  init_isa();

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();

  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);

  /* Initialize the simple debugger. */
  init_sdb();

  /* 初始化反汇编器 */
  IFDEF(CONFIG_ITRACE, init_disasm());

  /* 初始化 branch trace bin */
  IFDEF(CONFIG_BTRACE, init_tracebin());

  /* 初始化 ftracer */
  IFDEF(CONFIG_FTRACE, load_elf());

  /* 打开ftracer的输出日志 */
  IFDEF(CONFIG_FTRACE, init_ftracer_log(ftracer_log_file));

  /* 打开ftracer的输出日志 */
  IFDEF(CONFIG_DTRACE, init_dtracer_log(dtracer_log_file));

  /* Display welcome message. */
  welcome();
}
#else // CONFIG_TARGET_AM
static long load_img() {
  extern char bin_start, bin_end;
  size_t size = &bin_end - &bin_start;
  Log("img size = %ld", size);
  memcpy(guest_to_host(RESET_VECTOR), &bin_start, size);
  return size;
}

void am_init_monitor() {
  init_rand();
  init_mem();
  init_isa();
  load_img();
  IFDEF(CONFIG_DEVICE, init_device());
  welcome();
}
#endif
