/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
***************************************************************************************/

#include <isa.h>
#include <memory/paddr.h>
#ifdef CONFIG_FTRACE
void ftrace_init(const char *elf_file);
static char *elf_file = NULL;
#endif
void init_rand(); //（./src/utils/timer.c） 初始化随机数种子
void init_log(const char *log_file);  //（./src/utils/log.c） 初始化日志系统
void init_mem();  //（./src/cpu/difftest/ref.c） 初始化 NEMU 的内存系统
void init_difftest(char *ref_so_file, long img_size, int port); //（./src/cpu/difftest/dut.c） 初始化 DiffTest（对比测试）框架
void init_device(); //（./src/device/device.c） 初始化外设/设备
void init_sdb();  // 这里面也就是我们主要设置的文件的内容（初始化正则表达式+监视点系统）
void init_disasm();//（./src/utils/disasm.c） 初始化反汇编器

static void welcome() {
  printf("%s",ANSI_FMT("==================== Welcome to NEMU ====================\n",ANSI_FG_WHITE));
  printf("The following content is about the initialization of the nemu:\n");
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated to record the trace."));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NEMU!\n", ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
  printf("%s",ANSI_FMT("=========================================================\n",ANSI_FG_WHITE));
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>
#include <stdlib.h>

void sdb_set_batch_mode();

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static char *mrom_img_file = NULL;
static char *flash_img_file = NULL;
static int difftest_port = 1234;

bool expr_test_mode = false;
char *expr_file = NULL;
char *res_file  = NULL;
bool expr_test_verbose = false;  // --test-verbose
int  expr_test_print_n = 0;      // --test-print=N, 0 means disabled
#ifdef CONFIG_YSYXSOC_FULL_BOOT
static long load_file_to_addr(const char *path, paddr_t addr, const char *name) {
  Assert(path != NULL, "%s image is not given", name);

  FILE *fp = fopen(path, "rb");
  Assert(fp, "Can not open %s image '%s'", name, path);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("Load %s image: %s, size = %ld, addr = " FMT_PADDR,
      name, path, size, addr);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(addr), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}
#endif
static long load_img() {
#ifdef CONFIG_YSYXSOC_FULL_BOOT
  const char *mrom_path = mrom_img_file;
  const char *flash_path = flash_img_file;

  if (mrom_path == NULL) {
    mrom_path = getenv("YSYX_MROM_IMG");
  }

  if (flash_path == NULL) {
    flash_path = getenv("YSYX_FLASH_IMG");
  }

  long mrom_size = load_file_to_addr(mrom_path, YSYXSOC_MROM_BASE, "MROM");
  load_file_to_addr(flash_path, YSYXSOC_FLASH_BASE, "FLASH");

  return mrom_size;
#else
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.");
    return 4096;
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
#endif
}
#ifdef CONFIG_FTRACE
static char *guess_elf_path(const char *img_path) {
  if (img_path == NULL) return NULL;

  size_t len = strlen(img_path);
  char *ret = NULL;

  if (len >= 4 && strcmp(img_path + len - 4, ".bin") == 0) {
    ret = (char *)malloc(len + 1);
    if (ret == NULL) return NULL;

    memcpy(ret, img_path, len - 4);
    memcpy(ret + len - 4, ".elf", 5);
  } else {
    ret = (char *)malloc(len + 1);
    if (ret == NULL) return NULL;

    memcpy(ret, img_path, len + 1);
  }

  return ret;
}
#endif
/*
 * 解析命令
 */
static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch",        no_argument,       NULL, 'b'},
    {"log",          required_argument, NULL, 'l'},
    {"diff",         required_argument, NULL, 'd'},
    {"elf",          required_argument, NULL, 'e'},
    {"port",         required_argument, NULL, 'p'},
    {"test",         no_argument,       NULL, 't'},
    {"test-verbose", no_argument,       NULL, 'v'},
    {"test-print",   required_argument, NULL, 'n'},
    {"mrom",         required_argument, NULL, 1000},
    {"flash",        required_argument, NULL, 1001},
    {"help",         no_argument,       NULL, 'h'},
    {0,              0,                 NULL,  0 },
  };

  int o;
  while ((o = getopt_long(argc, argv, "-bhtvl:e:d:p:n:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 'e':
      printf("[args] got -e %s\n", optarg);
      #ifdef CONFIG_FTRACE
        elf_file = optarg;
      #endif
        break;
      case 't': expr_test_mode = true; break;
      case 'v': expr_test_verbose = true; break;
      case 'n': expr_test_print_n = atoi(optarg); break;

      case 1:
        if (expr_test_mode) {
          if (expr_file == NULL) expr_file = optarg;
          else if (res_file == NULL) res_file = optarg;
          // extra args ignored in test mode
        } else {
          img_file = optarg;
          return 0;
        }
        break;
      case 1000:
        mrom_img_file = optarg;
        break;

      case 1001:
        flash_img_file = optarg;
        break;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n", argv[0]);
        printf("   or: %s --test [--test-verbose] [--test-print=N] EXPR_FILE RES_FILE\n\n", argv[0]);
        printf("\t-b, --batch              run with batch mode\n");
        printf("\t-l, --log=FILE           output log to FILE\n");
        printf("\t-d, --diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p, --port=PORT          run DiffTest with port PORT\n");
        printf("\t    --test               run expr test mode (needs 2 files)\n");
        printf("\t    --test-verbose        print every test case detail\n");
        printf("\t    --test-print=N        print first N cases detail\n");
        printf("\n");
        exit(0);
    }
  }

  if (expr_test_mode) {
    Assert(expr_file && res_file, "Usage: %s --test EXPR_FILE RES_FILE", argv[0]);
    if (expr_test_print_n < 0) expr_test_print_n = 0;
  }

  return 0;
}

// void init_monitor(int argc, char *argv[]) {
//   /*参数解析函数，主要是把命令行输入转换成参数*/
//   parse_args(argc, argv);

//   /* 初始化随机种子（自带的） */
//   init_rand();

//   /* 载入log文件（自带的） */
//   init_log(log_file);

//   /* 初始化内存（自带的） */
//   init_mem();

//   /* 初始化外设（自带的） */
//   IFDEF(CONFIG_DEVICE, init_device());

//   /* 初始化指令集（调用系统自带的指令集） */
//   init_isa();
//   /* 覆盖之前的系统自带指令集，使用我生成的指令集 */
//   if (!expr_test_mode) {
//     long img_size = load_img();
//     init_difftest(diff_so_file, img_size, difftest_port);
//   } else {
//     Log("Expr test mode enabled: skip loading image & difftest");
//   }
//   #ifdef CONFIG_FTRACE
//   if (!expr_test_mode && elf_file) {
//     ftrace_init(elf_file);
//   }
//   #endif
//   /* 初始化wp池和正则表达式 */
//   init_sdb();

//   IFDEF(CONFIG_ITRACE, init_disasm());

//   /* 打印欢迎信息 */
//   welcome();
// }
void init_monitor(int argc, char *argv[]) {
  /* 参数解析：拿到 img_file / elf_file / log_file 等 */
  parse_args(argc, argv);

#ifdef CONFIG_FTRACE
  char *auto_elf = NULL;
  const char *final_elf = elf_file;
#endif

  /* 初始化随机种子（自带的） */
  init_rand();

  /* 载入 log 文件（自带的） */
  init_log(log_file);

  /* 初始化内存（自带的） */
  init_mem();

  /* 初始化外设（自带的） */
  IFDEF(CONFIG_DEVICE, init_device());

  /* 初始化指令集（调用系统自带的指令集） */
  init_isa();

  /* 覆盖之前的系统自带指令集，使用我生成的指令集 */
  if (!expr_test_mode) {
    long img_size = load_img();
    init_difftest(diff_so_file, img_size, difftest_port);
  } else {
    Log("Expr test mode enabled: skip loading image & difftest");
  }

#ifdef CONFIG_FTRACE
  if (!expr_test_mode) {
    /* 优先使用命令行 -e 传进来的 ELF */
    if (final_elf == NULL) {
      auto_elf = guess_elf_path(img_file);
      final_elf = auto_elf;
      if (final_elf != NULL) {
        printf("[ftrace] auto guessed elf file: %s\n", final_elf);
      }
    }

    if (final_elf != NULL) {
      ftrace_init(final_elf);
    } else {
      printf("[ftrace] no elf file provided and failed to guess from image\n");
      ftrace_init(NULL);
    }
  }
#endif

  /* 初始化 wp 池和正则表达式 */
  init_sdb();

  IFDEF(CONFIG_ITRACE, init_disasm());

  /* 打印欢迎信息 */
  welcome();

#ifdef CONFIG_FTRACE
  free(auto_elf);
#endif
}

#else // CONFIG_TARGET_AM

static long load_img() {
  extern char bin_start, bin_end;
  size_t size = &bin_end - &bin_start;
  Log("img size = %ld", size);
  memcpy(guest_to_host(RESET_VECTOR), &bin_start, size);// ./src/memory/paddr.c
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
