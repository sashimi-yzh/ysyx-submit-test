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
#include <memory/paddr.h>
#include <elf.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_disasm();
extern void init_dtrace();

static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("Etrace: %s", MUXDEF(CONFIG_E_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("Dtrace: %s", MUXDEF(CONFIG_DEVICR_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("Mtrace: %s", MUXDEF(CONFIG_MEMORY_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("Ftrace: %s", MUXDEF(CONFIG_FUNC_TRACEE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("Branch Predictor: %s", MUXDEF(CONFIG_BRANCH_Predictor, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
        "to record the trace. This may lead to a large log file. "
        "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NEMU!\n", ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
  // Log("Exercise: Please remove me in the source code and compile NEMU again.");
  //assert(0);
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>

void sdb_set_batch_mode();

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *elf_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;

static long load_img() {//加载程序镜像
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


typedef struct {
  uint32_t addr;  // 函数地址
  uint32_t size;  // 函数大小
  char name[64];  // 函数名
} func_symbol_t;

func_symbol_t func_table[4096]; //符号表
int func_count = 0;             //符号数量
#define CODE_BASE_ADDR 0x80000000;  

void load_func_table(const char *elf_file) {
  //打开ELF文件
  FILE* fp = fopen(elf_file, "rb");
  Assert(fp, "Can not open '%s'", elf_file);
  //获取ELF文件大小
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  Log("The ELF file is %s, size = %ld", elf_file, size);
  printf("[ftrace log] : The ELF file is %s, size = %ld\n", elf_file, size);//检查
  //读取ELF头部
  fseek(fp, 0, SEEK_SET);
  Elf32_Ehdr elf_header;
  assert(fread(&elf_header, sizeof(Elf32_Ehdr), 1, fp)==1);
  //读取节头表
  fseek(fp, elf_header.e_shoff, SEEK_SET);
  Elf32_Shdr sh_table[elf_header.e_shnum];
  assert(fread(sh_table, sizeof(Elf32_Shdr), elf_header.e_shnum, fp)==elf_header.e_shnum);
  //定位符号表和字符串表
  Elf32_Shdr *symtab = NULL;
  Elf32_Shdr *strtab = NULL;
  for (int i = 0; i < elf_header.e_shnum; i++) {
    if (sh_table[i].sh_type == SHT_SYMTAB) {
      symtab = &sh_table[i];
    }
    if (sh_table[i].sh_type == SHT_STRTAB && i != elf_header.e_shstrndx) {
      strtab = &sh_table[i];
    }
  }
  Assert(symtab && strtab, "Failed to locate symbol table or string table");
  //读取符号表数据
  Elf32_Sym symbols[symtab->sh_size / sizeof(Elf32_Sym)];//缓冲区设置
  fseek(fp, symtab->sh_offset, SEEK_SET);//定位到符号表偏移(后续或许名称偏移量)
  assert(fread(symbols, symtab->sh_size, 1, fp)==1);//读取符号表数据
  //读取字符串表数据
  char strtab_data[strtab->sh_size];
  fseek(fp, strtab->sh_offset, SEEK_SET);
  assert(fread(strtab_data, strtab->sh_size, 1, fp)==1);

  //解析函数符号
  func_count = 0;
  for (int i = 0; i < symtab->sh_size / sizeof(Elf32_Sym); i++) {
    if (ELF32_ST_TYPE(symbols[i].st_info) == STT_FUNC) {//如果是函数符号
      func_table[func_count].addr = symbols[i].st_value;
      func_table[func_count].size = symbols[i].st_size;
      strncpy(func_table[func_count].name, &strtab_data[symbols[i].st_name], sizeof(func_table[func_count].name) - 1);
      func_table[func_count].name[sizeof(func_table[func_count].name) - 1] = '\0';
      func_count++;
    }
  }

  fclose(fp);
  Log("Loaded %d function symbols from ELF file", func_count);
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"elf"      , required_argument, NULL, 'e'},//elf文件参数
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
      case 'e': elf_file = optarg; load_func_table(elf_file); break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\t-e,--elf=ELF_FILE       load ELF file for ftrace\n");
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

  IFDEF(CONFIG_ITRACE, init_disasm());
  IFDEF(CONFIG_MEMORY_TRACE,init_mtrace());
  IFDEF(CONFIG_DEVICE_TRACE,init_dtrace());
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
