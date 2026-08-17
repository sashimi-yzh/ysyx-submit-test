/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include "memory/symbols.h"
#include "sdb/ST.h"
#include "sdb/sdb.h"
#include "sdb/watcher.h"
#include <bits/getopt_core.h>
#include <debug.h>
#include <isa.h>
#include <memory/paddr.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>

void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_disasm();

static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN),
                          ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE,
        Log("If trace is enabled, a log file will be generated "
            "to record the trace. This may lead to a large log file. "
            "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NEMU!\n",
         ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
  // Log("Exercise: Please remove me in the source code and compile NEMU
  // again."); assert(0);
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>

void sdb_set_batch_mode();

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *elf_file = NULL;
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
#ifdef CONFIG_FTRACER
#define LOAD_ELF(E) load_symbols(E)
#else
#define LOAD_ELF(E)                                                            \
  fprintf(stderr, "Function tracer is disabled. Ignoring elf option.")
#endif

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
      {"batch", no_argument, NULL, 'b'},
      {"log", required_argument, NULL, 'l'},
      {"diff", required_argument, NULL, 'd'},
      {"port", required_argument, NULL, 'p'},
      {"elf", required_argument, NULL, 'e'},
      {"help", no_argument, NULL, 'h'},
      {0, 0, NULL, 0},
  };
  int o;
  while ((o = getopt_long(argc, argv, "-bhl:d:p:e:t", table, NULL)) != -1) {
    switch (o) {
    case 'b':
      sdb_set_batch_mode();
      break;
    case 'p':
      sscanf(optarg, "%d", &difftest_port);
      break;
    case 'l':
      log_file = optarg;
      break;
    case 'e':
      elf_file = optarg;
      break;
    case 'd':
      diff_so_file = optarg;
      break;
    case 1:
      img_file = optarg;
      return 0;
    default:
      printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
      printf("\t-b,--batch              run with batch mode\n");
      printf("\t-l,--log=FILE           output log to FILE\n");
      printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
      printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
      printf("\t-e,--elf=ELF            load elf file\n");
      printf("\n");
      exit(0);
    }
  }
  return 0;
}

void test_eval() {

  struct {
    char input[128];
    long long result;
  } testcases[] = {{"1 +    2 *  3", 7},
                   {"(1 +    2 ) *  (3+4)", 21},
                   {"  -1+-  2--3+-4*(-5--9)  ", -16},
                   {"  -----------114514", -114514},
                   {"(9--10+-11-+12+(+13--14++15--(16++17--18++19)))  "
                    "*(1--2++3--4++5--6++7--8)",
                    3888},
                   {"(9--10+-11*-+12+(+13--14++15--(16++17*--18++19)))  "
                    "*(1--2++3--4++5--6++7--8)",
                    19224},
                   {"(9*--10+-11*-+12+(+13--14*++15--(16++17*--18++19)))  "
                    "/    (1--2++3--4++5--6++7--8)",
                    21},
                   {"(((123 | 234 - ~123 & ~234) ^ 42 * 3 )% 29)", 25}};
  bool success = true;
  for (int i = 0; i < sizeof(testcases) / sizeof(testcases[0]); i++) {

    long long result = expr(testcases[i].input, &success);
    if (!success || result != testcases[i].result) {
      printf("expr(\"%s\") = %lld, should be %lld\n", testcases[i].input,
             result, testcases[i].result);
      puts("eval() unit test failed, quiting...");
      exit(-1);
    }
  }

  FILE *fp = fopen("test.txt", "r");
  clock_t begin = clock();

  if (fp != NULL) {
    while (!feof(fp)) {
      long long result;
      char *expression = NULL;
      size_t length;
      int scanret = fscanf(fp, "%lld", &result);
      Assert(scanret == 1, "Failed to load standard result");
      ssize_t read_sz = getline(&expression, &length, fp);

      Assert(read_sz != -1, "Failed to load testcases");

      if (read_sz > 0 && expression[read_sz - 1] == '\n') {
        expression[read_sz - 1] = '\0';
      }
      long long ret = expr(expression, &success);

      if (!success || result != ret) {
        printf("expr(\"%s\") = %lld, should be %lld\n", expression, ret,
               result);
        free(expression);
        puts("eval() unit test failed, quiting...");
        exit(-1);
      }
      free(expression);
    }

  } else {
    puts("Failed to open test.txt");
  }
  double time_cost = (double)(clock() - begin) / (CLOCKS_PER_SEC);
  printf("Test expr() finished, time : %fms\n", time_cost * 1000.0);
}

void unit_tests() {
  puts("---------------- Unit tests begin ----------------");
  test_eval();
  puts("---------------- Unit tests finished ----------------");
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

  unit_tests();

  if (elf_file != NULL)
    LOAD_ELF(elf_file);

#if defined(CONFIG_ITRACE) || defined(CONFIG_INST_RINGBUFFER)
  init_disasm();
#endif
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
