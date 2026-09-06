/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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
#include "debug.h"
#include "utils.h"
#include <cpu/cpu.h>
#include <isa.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

static int is_batch_mode = false;

void init_regex();
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
  set_state_quit();
  return -1;
}

static int cmd_si(char *args) {
  int times = 0;
  if (args == NULL)
    times = 1;
  else
    times = atoi(args);
  if (times <= 0)
    times = -1;
  for (unsigned int i = 0; i < times; i++) {
    cpu_exec(1);
    if (cmd_si_check(i) == -1)
      break;
    if (check_wp_hit() == 1)
      break;
  }
  return 0;
}

static int cmd_info(char *args) {
  if (strcmp("r", args) == 0)
    isa_reg_display(NULL);
  else if (strcmp("w", args) == 0)
    info_wp();
  else if (strcmp("g", args) == 0)
    info_memguard();
  else
    printf("[error] invlid args %s\n", args);
  return 0;
}

int strtox(char *arg) {
  if (arg[1] == 'x')
    arg = arg + 2;
  int ret;
  sscanf(arg, "%x", &ret);
  return ret;
}

static int cmd_x(char *args) {
  if (args == NULL) {
    printf("[error] missing count and address\n");
    return 0;
  }

  // arg1: count (按 4 字节 word 个数)
  char *arg1 = strtok(args, " ");
  if (arg1 == NULL) {
    printf("[error] missing count\n");
    return 0;
  }
  int times = atoi(arg1);
  if (times <= 0) {
    printf("[error] invalid count: %s\n", arg1);
    return 0;
  }

  // arg2: 起始地址
  char *arg2 = strtok(NULL, " ");
  if (arg2 == NULL) {
    printf("[error] missing address\n");
    return 0;
  }
  uint32_t addr = (uint32_t)strtox(arg2);

  for (int i = 0; i < times; i++) {
    uint32_t cur = addr + i * 4;
    uint32_t val = paddr_read(cur, 4);

    // 地址（4 字节对齐）、十六进制值、十进制值
    printf("0x%08x:  0x%08x  %10u\n", cur, val, val);
  }

  return 0;
}

static int cmd_p(char *args) {
  bool success = true;
  word_t res = expr(args, &success);
  if (success == true) {
    printf("%d\n", res);
  }
  return 0;
}

static int cmd_b(char *args) {
  new_wp(args);
  return 0;
}

static int cmd_d(char *args) {
  int no = atoi(args);
  free_wp(no);
  return 0;
}

static int cmd_attach(char *args) {
  isa_difftest_attach();
  return 0;
}

static int cmd_detach(char *args) {
  isa_difftest_detach();
  return 0;
}

static int cmd_save(char *args) { return snap_store(args); }

static int cmd_load(char *args) {
  int res = snap_load(args);
  if (res == 0 && isa_difftest_is_attach()) {
    isa_difftest_detach();
    isa_difftest_attach();
  }
  return res;
}

static int cmd_memguard(char *args) {
  if (!isa_difftest_is_attach()) {
    printf("[error] the memguard rely on the difftest\n");
    return 0;
  }
  uint32_t addr = (uint32_t)strtox(args);
  add_memguard(addr);
  return 0;
}

static int cmd_delguard(char *args) {
  if (!isa_difftest_is_attach()) {
    printf("[error] the memguard rely on the difftest\n");
    return 0;
  }

  int idx = atoi(args);
  del_memguard(idx);
  return 0;
}

static int test_p(char *args) {
  char *line = NULL;
  size_t len = 0;
  ssize_t c;
  if (args == NULL) {
    args = "./tools/gen-expr/build/input";
  }
  FILE *fp = fopen(args, "r");
  if (fp == NULL) {
    printf("[error] cant open file \"%s\"\n", args);
    return 0;
  }
  while ((c = getline(&line, &len, fp)) != -1) {
    line[strlen(line) - 1] = '\0';
    char *res_str = strtok(line, " ");
    char *exprees = res_str + strlen(res_str) + 1;
    word_t ans = (word_t)atoi(res_str);
    bool success = true;
    word_t res = expr(exprees, &success);
    if (success == false) {
      printf("something wrong encounter\n");
    } else if (res != ans) {
      printf("Failed!\n");
    } else if (res == ans) {
      printf("Pass!\n");
    }
  }
  return 0;
}

__attribute__((unused)) static int cmd_invalid(char *args) {
  assert(false && "call cmd_invalid");
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

    /* TODO: Add more commands */
    {"si", "run the program N steps, default is 1", cmd_si},
    {"info", "r:print reg  w:print watchpoint g:print memguard", cmd_info},
    {"x", "scan the memory", cmd_x},
    {"p", "evaluate the expr", cmd_p},
    {"test", "test expression evaluater", test_p},
    {"b", "create a watchpoint", cmd_b},
    {"d", "delete a watchpoint", cmd_d},
    {"attach", "attach the difftest", cmd_attach},
    {"detach", "detach the difftest", cmd_detach},
    {"save", "save the snapshot", cmd_save},
    {"load", "load the snapshot", cmd_load},
    {"memguard", "add a memguard", cmd_memguard},
    {"delguard", "delete a memguard", cmd_delguard},
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
    if(dbg_is_on()) {
      Log("dbg-server is not supported in batch mode, dbg-server will be ignored");
    }
    cmd_c(NULL);
    return;
  }

  while (1) {
    dbg_listen();

    if (get_nemu_state() == NEMU_QUIT) {
      return;
    }

    char *str;
    if ((str = rl_gets()) == NULL) {
      break;
    }
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

#include "signal.h"

void interrupt(int arg) { set_state_stop(); }

void init_sdb() {
  /* Register interrupt function */
  signal(SIGINT, interrupt);

  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();

  if (dbg_is_on() && !is_batch_mode) {
    dbg_init_and_wait_connection();
  }
}
