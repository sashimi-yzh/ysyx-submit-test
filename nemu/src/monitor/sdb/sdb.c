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
#include <cpu/decode.h>
#include <readline/chardefs.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include "common.h"
#include "macro.h"
#include "memory/paddr.h"
#include "sdb.h"
#include "utils.h"

static int is_batch_mode = false;
void sdb_set_batch_mode() { is_batch_mode = true; }


// initialize
void init_regex();
void init_wp_pool();

void init_sdb() 
{
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}


// command read
static char* rl_gets();

// express to cmd_p
word_t expr(char *e, bool *success);

// command function define
static int cmd_c(char *args);
static int cmd_q(char *args);
static int cmd_help(char *args);
static int cmd_si(char* args);
static int cmd_info(char* args);
static int cmd_x(char* args);
static int cmd_p(char* args);
static int cmd_w(char* args);
static int cmd_d(char* args);

// command table <name describe fuction> 
static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Single or N step execution", cmd_si },
  { "info", "Print status of program", cmd_info },
  { "x", "Four bytes of memory after scanning", cmd_x},
  { "p", "Find the value of the provided expression", cmd_p},
  { "w", "Stop program when ${EXPR} change", cmd_w},
  { "d", "Delete watch point with wp NO", cmd_d}
  /* TODO: Add more commands */
};

#define NR_CMD ARRLEN(cmd_table)


// continue
static int cmd_c(char *args) 
{
  cpu_exec(-1);
  return 0;
}


// quit
static int cmd_q(char *args) 
{
  nemu_state.state = NEMU_QUIT;
  return -1;
}


// display help
static int cmd_help(char *args)
{
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) 
  {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++)
      printf("%s\t- %s\n", cmd_table[i].name, cmd_table[i].description);
  }
  else 
  {
    for (i = 0; i < NR_CMD; i ++) 
    {
      if (strcmp(arg, cmd_table[i].name) == 0)
      {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}


// Single step execution
static int cmd_si(char* args)
{
  if (args == NULL)
    cpu_exec(1);
  else
  {
    int si_num = 0;
    if (sscanf(args, "%d", &si_num) == 1)
      cpu_exec((uint64_t)si_num);
    else
      printf("Please use \"si [N]\" to execute, N > 0.\n");
  }

  return 0;
}


// print infomation
static int cmd_info(char* args)
{
  void print_wp();

  bool exey = true;
  if (args == NULL || strlen(args) != 1)
  {
    exey = false;
    goto info_end;
  }

  if (*args == 'r')
    isa_reg_display();
  else if (*args == 'w')
    print_wp();
  else
    exey = false;

info_end:
  if (!exey) 
  {
    printf("Please use command: \"info r\" or \"info w\".\n");
  }
  
  return 0;
}


// scan memory
static int cmd_x(char* args)
{
  bool exey = true;
  char *str_end = args + strlen(args);
  char* arg_num = strtok(NULL, " ");
  char *arg_expr = arg_num + strlen(arg_num) + 1;
  if (arg_expr >= str_end) 
  {
    arg_expr = NULL;
  }

  if (arg_num == NULL || arg_expr == NULL) 
  {
    exey = false;
    goto x_end;
  }

  // 4 byte's num
  int x_num = 0;
  if (sscanf(arg_num, "%d", &x_num) == 0)
  {
    exey = false;
    goto x_end;
  }
  
  // address  num
  bool success = false;
  paddr_t x_addr = expr(arg_expr, &success);
  if (!success)
  {
    printf("your expression have some error.\n");
    goto x_end;
  }

  if (likely(in_pmem(x_addr)))
  {
    while (x_num--) 
    {
      word_t tmp = paddr_read(x_addr, 4);
      printf("0x%08x\t0x%08x\n", x_addr, tmp);
      x_addr += 4;
    }  
  }
  else 
  {
    printf("Memory access out of bounds.\n");
    return 0;
  }
  

x_end:
  if (!exey)
  {
    printf("Please use command: \"x [num] [expr]\".\n");
  }

  return 0;
}


// expression
static int cmd_p(char* args)
{
  bool success = false;
  word_t ret = expr(args, &success);
  if (success)
    printf("answer: 0x%08x\n", ret);
  else
    printf("your expression have some error.\n");

  return 0;
}


// create watch point
static int cmd_w(char* args)
{
  bool new_wp(const char* what, uint32_t value);
  
  bool success = false;
  word_t ret = expr(args, &success);

  if (success)
  {
    if (!new_wp(args, ret))
      printf("No more watchpoints available.\n");
  }
  else printf("your expression have some error.\n");

  return 0;
}


// delete watch point
static int cmd_d(char* args)
{
  void free_wp(int num);

  int si_num = 0;
  if (sscanf(args, "%d", &si_num) == 1)
    free_wp(si_num);
  else
    printf("Please use \"d [N]\" to execute, N is the number of wp.\n");

  return 0;
}


// expr test
void expr_test()
{
  FILE *file = fopen("/home/dallous/Documents/ysyx-workbench/nemu/input", "r");
  if (file == NULL) {
      perror("open file error");
      return;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, file)) != -1) 
  {
      char *str_end = line + strlen(line);

      char *cmd = strtok(line, " ");
      if (cmd == NULL) continue;

      word_t res = 0;
      if (sscanf(cmd, "%u", &res) != 1)
      {
        perror("get answer failed.\n");
        continue;
      }

      char *args = cmd + strlen(cmd) + 1;
      if (args >= str_end) 
      {
        perror("get expr failed.\n");
        continue;
      }

      bool success = false;
      word_t ret = expr(args, &success);
      if (success && ret != res)
      {
        printf("error: %u %u\t", ret, res);
        printf("%s\n", args);
      }
      else if (!success)
      {
        // printf("%s\n", args);
      }
  }

  free(line);
  fclose(file);
}


// main loop 
void sdb_mainloop() 
{
  // expr_test();

  if (is_batch_mode) 
  {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) 
  {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) 
    {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) 
    {
      if (strcmp(cmd, cmd_table[i].name) == 0) 
      {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}


/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() 
{
  static char *line_read = NULL;

  if (line_read)
  {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) 
  {
    add_history(line_read);
  }

  return line_read;
}