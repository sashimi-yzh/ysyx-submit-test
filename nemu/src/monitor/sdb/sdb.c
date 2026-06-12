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
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sdb.h"
#include "debug.h"

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
/*
static int get_arg(char *args, char *arg_buf[], int n) {
  if (args == NULL)
    return 0;
  char *save_ptr = NULL;
  int i;
  for (i = 0; i < n; i++) {
    arg_buf[i] = strtok_r(i == 0 ? args : NULL, " ", &save_ptr);
    if (arg_buf[i] == NULL)
      break; 
  }
  return i;
}
*/
static int cmd_c(char *args, char *str_end) {
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args, char *str_end) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_help(char *args, char *str_end);

static int cmd_si(char *args, char *str_end) {
  if (args == NULL) {
    printf("si [N]\nNeed 1 arg\n");
    return 0;
  }
  cpu_exec(atoi(args));
  return 0;
}  

static int cmd_info(char *args, char *str_end) {
  if (args == NULL) {
    printf("info <r | w>\nNeed 1 arg\n");
    return 0;
  }
  switch (args[0]) {
    case 'r': {
      isa_reg_display();
      break;            
    }
    case 'w': {
      print_wp();  
      break;
    }
    default: printf("info <r | w>\nUnknown arg\n");
  }
  return 0;
}

static int cmd_x(char *args, char *str_end) {
  if (args == NULL) {
    printf("x <N> <EXPR>\nNeed 2 args\n");
    return 0;
  }
  char *tok_saveptr;
  char *ret = strtok_r(args, " ", &tok_saveptr);
  char *expr_str = args + strlen(args) + 1;
  if (ret == NULL || expr_str >= str_end) {
    printf("x <N> <EXPR>\nNeed 2 args\n");
    return 0;
  }

  int num_4byte = atoi(args);
  bool success = true;
  vaddr_t addr = expr(expr_str, &success);
  if (success) {
    Log("%u\n", addr);
  } else {
    printf("invalid EXPR\n");
    return 0;
  }
 
  int i;
  for (i = 0; i < num_4byte; i++) {
    if (i % 4 == 0) {
      printf("\n");
      printf("\033[0;32m0x%.8x\033[0m:  ", addr + i * 4);
    }
    printf("0x%.8x ", vaddr_read(addr + i * 4, 4));
  }
  printf("\n\n");
  
  return 0;
}

static int cmd_w(char *args, char *str_end) {
  if (args == NULL) {
    printf("w <EXPR>\nNeed 1 arg\n");
    return 0;
  }
  bool success = true;
  uint32_t val = expr(args, &success);
  if (!success) {
    printf("invalid EXPR\n");
    return 0;
  }
  WP *wp = new_wp(args);
  wp->val = val;
  return 0;
}

static int cmd_d(char *args, char *str_len) {
  if (args == NULL) {
    printf("d <NO>\nNeed 1 arg\n");
  }
  int no = atoi(args);
  free_wp_by_no(no);

  return 0;
}

static int cmd_p(char *args, char *str_len) {
  if (args == NULL) {
    printf("p <EXPR>\nNeed 1 arg\n");
  }
  bool success = true;
  uint32_t val = expr(args, &success);
  printf("%u\n", val);
  return 0;
}

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *, char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Execute N instructions", cmd_si },
  { "info", "Print info of registers or whatch points", cmd_info },
  { "x", "Print 4N byte from memory that beginning address is Expr", cmd_x },
  { "w", "New a watchpoint", cmd_w },
  { "d", "Delete a watchpoint through NO", cmd_d },
  { "p", "Expression evaluation", cmd_p }
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args, char *str_end) {
  /* extract the first argument */
  int i;

  if (args == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    char *save_ptr = NULL;
    char *arg = strtok_r(args, " ", &save_ptr);
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
    cmd_c(NULL, NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
	char *tok_saveptr = NULL;
    char *cmd = strtok_r(str, " ", &tok_saveptr);
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
        if (cmd_table[i].handler(args, str_end) < 0) { return; }
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
