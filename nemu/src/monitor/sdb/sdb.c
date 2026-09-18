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
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <memory/vaddr.h>
#include "sdb.h"

static int is_batch_mode = true;

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
  cpu_exec(1);
  return -1;
}

static int cmd_si(char *args) {
  int n = 1;
  if (args != NULL) {
    char *a;
    n = strtol(args, &a, 10);
    if (a == args || *a != '\0' || n <= 0) {
	printf("Error: Unknown usage: '%s'\nUsage: si [N] -- N: positive integer --\n", a);
	return 0;
    }
  }
  printf("Executing %d instructions...\n", n);
  cpu_exec(n);
  return 0;
}

static int cmd_info(char *args) {
  switch (args[0]) {
    case 'r': isa_reg_display(); return 0;
    case 'w': return c_print();
  }

  printf("Unknown usage: '%s'\n", args);
  return 0;
}

static int cmd_x(char *args) {
  int n = 0;
  uint32_t s;
  char *a0;
  char *arg = args;
  bool success;

  if (args == NULL) {
    printf("Now: 0x%08X: %08x\n", cpu.pc, vaddr_read(cpu.pc, 4));
    return 0;
  }

  char *arg0 = strtok(NULL, " ");//arg0 is the frist argv
  char *arg1 = strtok(NULL, " ");//arg1 is the second argv

  if (arg0 != NULL) {
    n = strtol(arg0, &a0, 10);
    s = (arg1 == NULL) ? cpu.pc: expr(arg1, &success);

    if (a0 == arg0 || *a0 != '\0' || n <= 0) printf("Error: Unknown usage: '%s'\n", arg);
  
    vaddr_t start = 0x80000000;
    for (vaddr_t i = start; i < 0X88000000 ; i += 4) {
      if (s == i) {
	for (int c = 0; c < n; c ++) {
	  vaddr_t current = i + c * 4;
	  if (current >= 0X88000000) break;

	  uint32_t value = vaddr_read(current, 4);
	  printf("0x%08X: %08X\n", current, value);
	}
        return 0;
      }
    }
    for (int c = 0; c < n; c ++) {
      vaddr_t current = s + c * 4;
      printf("0x%08X: NULL\n", current);
    }
  }
  
  return 0;
}

static int cmd_p(char *args) {
  bool success;
  uint32_t result = expr(args, &success);
  if (success) {
    printf("%d\n", result);
    return 0;
  }
  else assert(0);
}


static int cmd_w(char *args) {
  return c_w(args);
}

static int cmd_d(char *args) {
  return c_d(args);
}

static int cmd_ext(char *args) {
  FILE *fp = fopen("input", "r");

  if (!fp) {
    perror("打开文件失败\n");
    return 1;
  }

  word_t all = (args != NULL) ? atoi(args) : 1000;
  word_t pass = all;
  int result = 0;
  char ep[128];
  bool success;

  for (uint32_t i = 0; i < all; i ++) {
    int k = fscanf(fp, "%u %s", &result, ep);
    uint32_t data = expr(ep, &success);

    assert(k == 2);
    if (result != data || !success) {
      pass--;
      printf("%s != %d\n", ep, data);
    }
  }

  printf("pass:%d all:%d\n", pass, all);
  return 0;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Single-step implementation", cmd_si },
  { "info", "Print program status", cmd_info },
  { "x", "Scanning memory", cmd_x },
  { "p", "Expression evaluation", cmd_p},
  { "w", "Set up a monitoring point", cmd_w},
  { "d", "Delete the monitoring point", cmd_d},
  { "ext", "Test the expression", cmd_ext}

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
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
