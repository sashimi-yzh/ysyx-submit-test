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
#include "sdb.h"
#include <memory/paddr.h>
#include <watchpoint.h>


static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

WP* new_wp();
void free_wp(WP *wp);


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
  if(args == NULL) {
    cpu_exec(1);
  }
  else {
    int num = atoi(args);
    if(num <= 0) {
      printf("Invalid number of instructions: %d\n", num);
    }
    else {
      cpu_exec(num);
    }
  }
  return 0;
}

static int cmd_p(char *args) {
  if (args == NULL) {
    printf("Hint: Try p <expression>\n");
  }
  else {
    bool success = false;
    uint32_t result = expr(args, &success);
    if(success) {
      printf("%d\n", result);
    }
    else {
      printf("Invalid expression.\n");
    }
  }
  return 0;
}

static int cmd_x(char *args);
static int cmd_w(char *args);
static int cmd_d(char *args);
static int cmd_help(char *args);
static int cmd_info(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Step in one instruction", cmd_si},
  { "info", "Print the info of reg or the watch point", cmd_info},
  { "x", "Scan the memory", cmd_x},
  { "p", "Print the value of an expression", cmd_p},
  { "w", "Set a watchpoint", cmd_w},
  { "d", "Delete a watchpoint", cmd_d},

  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)


static int cmd_d(char *args)
{
  if (args == NULL) {
    printf("Hint: Try d <watchpoint NO.>\n");
  }
  else {
    int wp_no = atoi(args);

    WP* wp = head;
    while(wp != NULL && wp->NO != wp_no)
    {
      wp = wp->next;
    }
    if(wp != NULL)
    {
      free_wp(wp);
      printf("Watchpoint %d deleted.\n", wp_no);
    }
    else
    {
      printf("No watchpoint number %d.\n", wp_no);
    }
  }
  return 0;
}

static int cmd_w(char *args)
{
  if (args == NULL) {
    printf("Hint: Try w <expression>\n");
  }
  else {
    WP* wp = new_wp();
    strcpy(wp->expr, args);
    bool success = false;
    wp->value = expr(args, &success);
    if(success) {
      printf("Watchpoint %d: %s = %d\n", wp->NO, wp->expr, wp->value);
    }
    else {
      printf("Invalid expression.\n");
      free_wp(wp);
    }
  }
  return 0;
}


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


static int cmd_info(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");

  if (arg == NULL) {
    printf("Hint: Try <info r> or <info w>\n");
  }

  else if(strcmp(arg, "r") == 0) {
    isa_reg_display();
  }

  else if(strcmp(arg, "w") == 0) {

    WP *wp = head;
    if(wp == NULL)
    {
      printf("No watchpoint.\n");
    }
    else {
      while(wp != NULL) {
        printf("Watchpoint %d: %s = %d\n", wp->NO, wp->expr, wp->value);
        wp = wp->next;  
      }
    }

  }
  else {
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

static int cmd_x(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");

  if (arg == NULL) {
    printf("Hint: Try x <num> <addr>\n");
  }

  else{
    int scannum = atoi(arg);

    arg = strtok(NULL, " ");
    if(arg == NULL) {
      printf("Hint: Try x <num> <addr>\n");
    }
    else {
      int startaddr = (int)strtol(arg, NULL, 0);
      for(int i=0; i<scannum; i++)
      {
        printf("0x%08x: 0x%08x\n", startaddr + i*4, paddr_read(startaddr + i*4, 4));
      }
    }
    
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
