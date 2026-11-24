/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NPC is licensed under Mulan PSL v2.
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
#include <memory/paddr.h>
#include "sdb.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
typedef struct watchpoint WP;

WP* new_wp(void);
WP* free_wp(int num);
void wp_display(void);
void fill_wp(WP *wp, char* arg);

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

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
  deinit_verilator_env();
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
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NPC", cmd_q },
  { "si", "Step in N steps", cmd_si },
  { "info", "Show information of regs or monitors", cmd_info },
  { "x", "Show the information of specified memory, like x 10 0x80000000", cmd_x },
  { "p", "Calculate the value of expressions", cmd_p },
  { "w", "Set watchers of specifed value, w 0x80000058 or w $a1", cmd_w },
  { "d", "Delete Nth watcher", cmd_d },

  /* TODO: Add more commands */

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
    Log("Unknown command '%s'", arg);
  }
  return 0;
}

static int cmd_si(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int n;

  if (arg == NULL) {
    /* step into 1 step */
    cpu_exec(1);
  }
  else {
    n = atoi(arg);
    /* step into N step */
    cpu_exec(n);
  }
  return 0;
}

static int cmd_info(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");

  if (arg == NULL) {
    /* no argument given */
    Log("Needs 1 more arg, e.g. info r or info w");
    return 0;
  }

  if (strcmp(arg, "r") == 0)
  {
    isa_reg_display();
    return 0;
  }

  if (strcmp(arg, "w") == 0)
  {
    wp_display();
    return 0;
  }

  return 0;
}

static int cmd_x(char *args) {
  /* extract the first argument */
  char *arg;
  int len, i;
  unsigned int addr;
  unsigned char *byte;
  bool status;

  arg = strtok(NULL, " ");
  if (arg == NULL) {
    /* no argument given */
    Log("Needs 2 args, e.g. x 10 0x80000000");
    return 0;
  }
  len = atoi(arg);

  arg = strtok(NULL, " ");
  if (arg == NULL) {
    /* no argument given */
    Log("Needs 2 args, e.g. x 10 0x80000000");
    return 0;
  }
  //addr = strtol(arg, NULL, 0);
  addr = expr(arg, &status);
  if(!status)
    Log("Expression calculate failure");

  // mrom/sram/flash range check
  if (!((addr - CONFIG_MBASE < CONFIG_MSIZE) || (addr - MROM_BASE < 0x1000) ||
        (addr >= FLASH_BASE && addr < FLASH_BASE + FLASH_SIZE))) {
    Log("Incorrect addr 0x%x and len 0x%x", addr, len);
    return 0;
  }

  Log("memory dump: start addr 0x%x, len 0x%x", (addr), len);

  byte = (unsigned char *)guest_to_host(addr);
  for (i = 0; i < len; i++) {
    printf("%02X ", byte[i]);
    if ((i + 1) % 16 == 0) {
      printf("\n");
    }
  }
  printf("\n");

  return 0;
}

static int cmd_p(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  bool status;
  word_t res = 0;

  if (arg == NULL) {
    /* no argument given */
    Log("Needs 1 arg as an expression, e.g. 5 + 3 * 2");
    return 0;
  }

  res = expr(arg, &status);
  if(!status)
    Log("Expression calculate failure");
  printf("Result of expression: 0x%x\n", res);
 
  return 0;
}

static int cmd_w(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");

  if (arg == NULL) {
    /* no argument given */
    Log("Needs 1 arg as an expression, e.g. *0x80000000");
    return 0;
  }

  WP *wp = new_wp();

  if (!wp)
    Log("Failed to create wp");

  fill_wp(wp, arg);

  return 0;
}

static int cmd_d(char *args) {

  int num = 0;
  /* extract the first argument */
  char *arg = strtok(NULL, " ");

  if (arg == NULL) {
    /* no argument given */
    Log("Needs 1 arg as an arg, e.g. 1");
    return 0;
  }
  num = atoi(args);

  free_wp(num);

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

    if (i == NR_CMD) { Log("Unknown command '%s'", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
