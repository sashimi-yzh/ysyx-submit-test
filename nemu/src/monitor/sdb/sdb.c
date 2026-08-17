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

#include "sdb.h"
#include "common.h"
#include "watcher.h"
#include <cpu/cpu.h>
#include <debug.h>
#include <errno.h>
#include <isa.h>
#include <limits.h>
#include <memory/vaddr.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <utils.h>

static int is_batch_mode = false;

void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin.
 */
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

static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_si(char *args) {
  char *parameter = strtok(NULL, " ");
  uint64_t n_steps = 1;
  if (parameter != NULL) {
    errno = 0;
    n_steps = strtoull(parameter, NULL, 10);
    if (errno != 0) {
      printf("Bad argument %s\n", parameter);
      return 0;
    }
  }

  cpu_exec(n_steps);
  return 0;
}

WP *watcher_table[NR_WP] = {};

static int cmd_info(char *args) {
  char *parameter = strtok(NULL, " ");
  if (parameter == NULL) {
    printf("Expecting argument :\n'r' for registers\n'w' for watcher\n");
    return 0;
  }

  if (strcmp(parameter, "r") == 0) {
    isa_reg_display();
  } else if (strcmp(parameter, "w") == 0) {

    list_watchers();
  } else {
    printf("Expecting 'r' for registers or 'w' for watcher\n");
    return 0;
  }
  return 0;
}
static int cmd_x(char *args) {

  char *parameter = strtok(NULL, " ");
  if (parameter == NULL) {
    printf("Expecting 2 arguments : [scan length] [address]\n");
    return 0;
  }
  int scan_length = strtol(parameter, NULL, 10);

  parameter = strtok(NULL, "\0");

  if (parameter == NULL) {
    printf("Expecting 2 arguments : [scan length] [address]\n");
    return 0;
  }

  if (scan_length <= 0) {
    printf("scan_length must be positive\n");
    return 0;
  }
  bool success = true;
  long long value = expr(parameter, &success);
  if (!success)
    printf("Invalid expression %s\n", parameter);
  else if (value > (long long)UINT32_MAX || value < 0)
    printf("Invalid address %lld\n", value);
  else {
    word_t address = (word_t)value;

    for (int i = 0; i < scan_length; i++) {
      printf("%08x : %08x\n", address, vaddr_read(address, 4));
      address += 4;
    }
  }
  return 0;
}
static int cmd_p(char *args) {
  if (args == NULL) {
    printf("Expecting a expression\n");
    return 0;
  }
  bool success = true;

  long long result = expr(args, &success);
  if (success)
    printf("%lld\n", result);

  return 0;
}

static int cmd_ph(char *args) {
  if (args == NULL) {
    printf("Expecting a expression\n");
    return 0;
  }
  bool success = true;

  long long result = expr(args, &success);
  if (success)
    printf("0x%08x\n", (word_t)result);

  return 0;
}
#ifdef CONFIG_WATCHERS
static int cmd_w(char *args) {
  bool success = true;
  long long value = expr(args, &success);
  if (!success) {
    puts("This expression is invalid, did not setup any watcher.");
    return 0;
  }

  WP *wp = new_wp(args, value, false);

  if (wp) {
    printf("Setup a new watcher #%d\n", wp->NO);
    watcher_table[wp->NO] = wp;
  } else
    printf("Failed to allocate a new watcher : No more free watchers.\n");
  return 0;
}

static int cmd_wh(char *args) {
  bool success = true;
  long long value = expr(args, &success);
  if (!success) {
    puts("This expression is invalid, did not setup any watcher.");
    return 0;
  }

  WP *wp = new_wp(args, value, true);

  if (wp) {
    printf("Setup a new watcher #%d\n", wp->NO);
    watcher_table[wp->NO] = wp;
  } else
    printf("Failed to allocate a new watcher : No more free watchers.\n");

  return 0;
}
#endif
static int cmd_d(char *args) {
  char *parameter = strtok(NULL, " ");
  long id_watcher;
  if (parameter != NULL) {
    errno = 0;
    char *end = NULL;
    id_watcher = strtol(parameter, &end, 10);
    if (errno != 0 || id_watcher < 0 || id_watcher >= NR_WP || *end != '\0') {
      printf("Bad argument %s, need an integer >=0 and <= %d\n", parameter,
             NR_WP - 1);
      return 0;
    }
  } else {
    puts("Expecting an argument : watcher id to delete");
    return 0;
  }
  if (watcher_table[id_watcher] == NULL) {
    printf("Watcher #%ld is inactive.\n", id_watcher);
    return 0;
  }
  free_wp(watcher_table[id_watcher]);
  watcher_table[id_watcher] = NULL;
  printf("Removed watcher #%ld.\n", id_watcher);
  return 0;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},
    {"si", "Step into", cmd_si},
    {"info", "Show program status", cmd_info},
    {"x", "Scan memory", cmd_x},
    {"p", "Evaluate expression", cmd_p},
    {"ph", "Evaluate hexdecimal expression", cmd_ph},
#ifdef CONFIG_WATCHERS
    {"w", "Setup a watcher", cmd_w},
    {"wh", "Setup a hexdecimal watcher", cmd_wh},
#endif
    {"d", "Remove a watcher", cmd_d}

    /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
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

void sdb_set_batch_mode() { is_batch_mode = true; }

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
  void init_regex();
  init_regex();
  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
