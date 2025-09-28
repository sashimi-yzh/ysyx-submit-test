/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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
#include <cpu/cpu.h>
#include <cpu/difftest.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <memory/vaddr.h>
#include "sdb.h"
#include "memory/paddr.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_si(char *args) {
  char *arg = strtok(NULL, " ");
  int n = arg == NULL ? 1 : atoi(arg);

  if (n <= 0) printf("Invalid N value\n");
  else cpu_exec(n);
  return 0;
}

static int cmd_info(char *args) {
  char *arg = strtok(NULL, " ");
  if (arg == NULL) {
    printf("info r/w: Print register/watchpoint info\n");
    return 0;
  }
  void wps_display();
  switch (arg[0]) {
    case 'r': isa_reg_display(); break;
    case 'w': wps_display(); break;
    default: printf("Unknown sub command '%s'\n", arg); break;
  }
  return 0;
}

static int cmd_x(char *args) {
  char *arg = strtok(NULL, " ");
  int n = arg == NULL ? 1 : atoi(arg);
  char *str = strtok(NULL, "\0");

  if (n <= 0) {
    printf("Invalid N value\n");
    return 0;
  }

  vaddr_t addr;
  bool success = true;
  if (str == NULL || (addr = expr(str, &success), !success)) {
    printf("Invalid EXPR\n");
    return 0;
  }

  for (unsigned int i = 0; i < n; ++i, addr += 4) {
    printf(
      MUXDEF(CONFIG_ISA64,"0x%-16llx: 0x%-16llx\n", "0x%-8x: 0x%-8x\n"),
      addr, vaddr_read(addr, 4)
    );
  }
  return 0;
}

static int cmd_p(char *args) {
  char *str = strtok(NULL, "\0");
  bool success = true;
  word_t val = expr(str, &success);
  if (!success) {
    printf("Invalid EXPR\n");
    return 0;
  }
  printf(
    MUXDEF(CONFIG_ISA64, "hex: 0x%llx\nunsigned dec: %llu\nsigned dec: %lld\n", \
                         "hex: 0x%x\nunsigned dec: %u\nsigned dec: %d\n"),
    val, val, val
  );
  return 0;
}

static int cmd_w(char *args) {
  char *str = strtok(NULL, "\0");
  bool success = true;

  word_t val;
  if (str == NULL || (val = expr(str, &success), !success)) {
    printf("Invalid EXPR\n");
    return 0;
  }
  void *new_wp(char *str, word_t val);
  void *p = new_wp(str, val);
  if (p == NULL) {
    printf("Too many watchpoints\n");
    return 0;
  }
  void print_wp(void *p);
  print_wp(p);
  return 0;
}

static int cmd_d(char *args) {
  char *arg = strtok(NULL, " ");
  int n = arg == NULL ? 1 : atoi(arg);

  void free_wp(int no);
  free_wp(n);
  return 0;
}

static int cmd_help(char *args);

static int cmd_detach(char *args) {
  difftest_detach();
  return 0;
}

static int cmd_attach(char *args) {
  difftest_attach();
  return 0;
}

static int cmd_save(char *args) {
  FILE *f = fopen(args, "wb");
  assert(fwrite(&cpu, sizeof(CPU_state), 1, f) == 1);
  isa_snapshot_save(f);
  assert(fwrite(guest_to_host(RESET_VECTOR), 1, CONFIG_MSIZE, f) == CONFIG_MSIZE);
  fclose(f);
  return 0;
}

static int cmd_load(char *args) {
  FILE *f = fopen(args, "rb");
  assert(fread(&cpu, sizeof(CPU_state), 1, f) == 1);
  isa_snapshot_load(f);
  assert(fread(guest_to_host(RESET_VECTOR), 1, CONFIG_MSIZE, f) == CONFIG_MSIZE);
  fclose(f);
  return 0;
}

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "si N: Execute N instructions and then pause, N = 1 if not given", cmd_si },
  { "info", "info r/w: Print register/watchpoint info", cmd_info },
  { "x", "x N EXPR: Evaluate EXPR, print N*4 bytes starting from the address", cmd_x },
  { "p", "p EXPR: Evaluate EXPR", cmd_p },
  { "w", "w EXPR: Stop when value of EXPR changes(watchpoint)", cmd_w },
  { "d", "d N: Delete watchpoint No.N", cmd_d },
  {"detach", "Detach difftest", cmd_detach},
  {"attach", "Attach difftest", cmd_attach},
  {"save", "save [path]: Save snapshot", cmd_save},
  {"load", "load [path]: Load snapshot", cmd_load}
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  void init_regex();
  void init_wp_pool();

  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
