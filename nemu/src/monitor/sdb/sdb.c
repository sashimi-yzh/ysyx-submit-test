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

#include "sdb.h"
#include "memory/paddr.h"
#include <cpu/cpu.h>
#include <isa.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <string.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char *rl_gets() {
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

static int cmd_si(char *args) {
  char *token = strtok(args, " ");
  int n = 1;
  if (token != NULL) {
    n = atoi(token);
  }
  if (n > 0) {
    cpu_exec(n);
  } else {
    puts("N is at least 1!");
  }
  return 0;
}

static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_info(char *args) {
  if (args == NULL) {
    puts("info r: Print register status.\ninfo w: Print monitoring point "
         "information");
    return 0;
  }
  if (strcmp(args, "r") == 0) {
    isa_reg_display(&cpu);
  } else if (strcmp(args, "w") == 0) {
    infoWatchPoint();
  } else {
    puts("info r: Print register status.\n"
         "info w: Print monitoring point information");
  }
  return 0;
}

static int cmd_x(char *args) {
  int pos, len;
  if (args == NULL) {
    puts("x N EXPR: Find the value of the expression EXPR, use the result as the starting memory address, and output N consecutive 4-byte values ​​in hexadecimal format");
    return 0;
  }
  sscanf(args, "%d%x", &len, &pos);
  for (int i = 0; i < len; i++, pos += 4) {
    printf("%08x: %08x\n", pos, paddr_read(pos, 4));
  }
  return 0;
}

static int cmd_p(char *args) {
  if (args == NULL) {
    puts("wrong expression");
    return 0;
  }
  bool success;
  int res = expr(args, &success);
  if (success) {
    printf("|%-20s|%-20s|%-20s\n", "signed", "unsigned", "hex");
    printf("|%-20d|%-20u|%#08x\n", res, res, res);
  } else {
    printf("err args: %s\n", args);
  }
  return 0;
}

static int cmd_config(char *args) {
  if (args == NULL) {
    printf("eval: %s\n", debug_eval ? "true" : "false");
    return 0;
  }
  char *key = strtok(args, " ");
  char *value = strtok(NULL, "");
  if (strcmp(key, "eval") == 0) {
    if (strcmp(value, "true") == 0) {
      debug_eval = true;
    } else if (strcmp(value, "false") == 0) {
      debug_eval = false;
    }
  }
  return 0;
}

static int cmd_w(char *args) {
  if (args == NULL) {
    puts("wrong expression");
    return 0;
  }
  bool success;
  int res = expr(args, &success);
  if (success == false) {
    puts("wrong expression");
    return 0;
  }
  WP *wp = new_wp();
  strcpy(wp->express, args);
  wp->oldValue = res;
  return 0;
}

static int cmd_d(char *args) {
  if (args == NULL) {
    puts("wrong expression");
    return 0;
  }
  bool success;
  int no = atoi(args);
  free_wpByNO(no, &success);
  if (success) {
    puts("Successfully released the monitoring point");
  } else {
    puts("Release failed");
  }
  return 0;
}

// cmd_table needs a function pointer to cmd_help, and the cmd_help function implementation needs to know the array length of cmd_table
static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},
    {"si", "Pause execution after single-stepping N instructions. When N is not given, the default is 1", cmd_si},
    {"info", "Print program status", cmd_info},
    {"x", "Scan memory", cmd_x},
    {"p", "Expression evaluation", cmd_p},
    {"w", "Add watchpoint", cmd_w},
    {"d", "Release monitoring points by number", cmd_d},
    {"config", "Configure NEMU", cmd_config},
};

#define NR_CMD ARRLEN(cmd_table)

static int
cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  } else {
    for (i = 0; i < NR_CMD; i++) {
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

  for (char *str; (str = rl_gets()) != NULL;) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) {
      continue;
    }

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
    for (i = 0; i < NR_CMD; i++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) {
          return;
        }
        break;
      }
    }

    if (i == NR_CMD) {
      printf("Unknown command '%s'\n", cmd);
    }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
