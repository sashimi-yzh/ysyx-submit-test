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
#include <memory/vaddr.h>
#include <utils.h>

#include <readline/readline.h>
#include <readline/history.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sdb.h"

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
  // 让 make run 退出不报 Error 1
  //exit(0);
  //return 0;
  nemu_state.state = NEMU_QUIT;
  return -1;  
}

static int cmd_help(char *args);
static int cmd_si(char *args);
static int cmd_info(char *args);
static int cmd_x(char *args);
static int cmd_p(char *args);
static int cmd_w(char *args);
static int cmd_d(char *args);


static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c",    "Continue the execution of the program", cmd_c },
  { "q",    "Exit NEMU", cmd_q },
  { "si",   "Step instruction(s): si [N]", cmd_si },
  { "info", "Print register state (info r) (info x) (info $register)", cmd_info },
  { "x",    "Examine memory: x N EXPR", cmd_x },
  { "p",    "Evaluate expression: p EXPR", cmd_p },
  { "w",    "Set watchpoint: w EXPR", cmd_w },
  { "d",    "Delete watchpoint: d N", cmd_d },
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
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

// si [N]
static int cmd_si(char *args) {
  int n = 1;
  if (args != NULL) {
    while (*args == ' ') args++;
    if (*args != '\0') {
      if (sscanf(args, "%d", &n) != 1 || n <= 0) {
        printf("Usage: si [N]\n");
        return 0;
      }
    }
  }
  cpu_exec(n);
  return 0;
}

// info r
static int cmd_info(char *args) {
  if (args == NULL) {
    printf("Usage: info r | info w\n");
    return 0;
  }

  while (*args == ' ') args++;

  if (strcmp(args, "r") == 0) {
    printf(">>> entering isa_reg_display()\n");
    isa_reg_display();
    printf("<<< leaving isa_reg_display()\n");
    return 0;
  }

  if (strcmp(args, "w") == 0) {
    WP *wp = get_head_wp();
    if (wp == NULL) {
      printf("No watchpoints.\n");
      return 0;
    }

    printf("Num\tValue\t\tExpr\n");
    for (; wp != NULL; wp = wp->next) {
      printf("%d\t0x%08x\t%s\n",
             wp->NO, (uint32_t)wp->last_val, wp->expr);
    }
    return 0;
  }

  if (args[0] == '$') {
    bool ok = true;
    word_t val = isa_reg_str2val(args + 1, &ok); // 去掉 '$'
    if (!ok) {
      printf("Unknown register: %s\n", args);
      return 0;
    }
    printf("%s = %u (0x%08x)\n", args, (uint32_t)val, (uint32_t)val);
    return 0;
  }
  printf("Usage: info r | info w\n");
  return 0;
}


// p EXPR
static int cmd_p(char *args) {
  if (args == NULL) {
    printf("Usage: p EXPR\n");
    return 0;
  }
  while (*args == ' ') args++;
  if (*args == '\0') {
    printf("Usage: p EXPR\n");
    return 0;
  }

  bool success = true;
  word_t val = expr(args, &success);
  if (!success) {
    printf("Bad expression\n");
    return 0;
  }

  printf("%u (0x%08x)\n", (uint32_t)val, (uint32_t)val);
  return 0;
}

// x N EXPR   (EXPR 支持空格/括号/0x/四则运算等，因为用 expr() 求值)
static int cmd_x(char *args) {
  if (args == NULL) {
    printf("Usage: x N EXPR\n");
    return 0;
  }

  while (*args == ' ') args++;

  int n = 0;
  int consumed = 0;

  if (sscanf(args, "%d%n", &n, &consumed) != 1 || n <= 0) {
    printf("Usage: x N EXPR\n");
    return 0;
  }

  char *expr_str = args + consumed;
  while (*expr_str == ' ') expr_str++;

  if (*expr_str == '\0') {
    printf("Usage: x N EXPR\n");
    return 0;
  }

  bool success = true;
  word_t addr = expr(expr_str, &success);
  if (!success) {
    printf("Bad expression\n");
    return 0;
  }

  for (int i = 0; i < n; i++) {
    vaddr_t cur = (vaddr_t)(addr + (word_t)i * 4);
    word_t data = vaddr_read(cur, 4);
    printf("0x%08x: 0x%08x\n", (uint32_t)cur, (uint32_t)data);
  }

  return 0;
}

static int cmd_w(char *args) {
  if (args == NULL) {
    printf("Usage: w EXPR\n");
    return 0;
  }
  while (*args == ' ') args++;
  if (*args == '\0') {
    printf("Usage: w EXPR\n");
    return 0;
  }

  WP *wp = new_wp();

  strncpy(wp->expr, args, sizeof(wp->expr) - 1);
  wp->expr[sizeof(wp->expr) - 1] = '\0';

  bool success = true;
  word_t val = expr(wp->expr, &success);
  if (!success) {
    printf("Bad expression, watchpoint not set.\n");
    free_wp(wp);
    return 0;
  }

  wp->last_val = val;
  wp->inited = true;

  printf("Watchpoint %d: %s\n", wp->NO, wp->expr);
  return 0;
}

static int cmd_d(char *args) {
  if (args == NULL) {
    printf("Usage: d N\n");
    return 0;
  }
  while (*args == ' ') args++;
  if (*args == '\0') {
    printf("Usage: d N\n");
    return 0;
  }

  int n = -1;
  if (sscanf(args, "%d", &n) != 1 || n < 0) {
    printf("Usage: d N\n");
    return 0;
  }

  WP *wp = get_head_wp();
  while (wp != NULL && wp->NO != n) {
    wp = wp->next;
  }

  if (wp == NULL) {
    printf("No such watchpoint %d\n", n);
    return 0;
  }

  free_wp(wp);
  printf("Watchpoint %d deleted.\n", n);
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

    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

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
  init_regex();
  init_wp_pool();
}

