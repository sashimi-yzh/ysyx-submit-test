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
#include <errno.h>
#include <limits.h>
#include <memory/vaddr.h>
#include "sdb.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
extern void test_expr(bool *success);
extern void wp_display();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char *rl_gets()
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

static int cmd_c(char *args)
{
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args)
{
  return -1;
}

static int cmd_si(char *args)
{
  char *steps_str = strtok(NULL, " ");
  int steps = 0;
  if (steps_str == NULL)
  {
    steps = 1;
  }
  else
  {
    steps = atoi(steps_str);
  }
  cpu_exec(steps);
  return 0;
}

static int cmd_info(char *args)
{
  char *subcmd = strtok(NULL, " ");
  if (subcmd == NULL)
  {
    printf("Please provide a subcommand: r for registers, w for watchpoints\n");
    return 0;
  }
  if (strcmp(subcmd, "r") == 0)
  {
    isa_reg_display();
  }
  else if (strcmp(subcmd, "w") == 0)
  {
    wp_display();
  }
  else
  {
    printf("Unknown subcommand '%s'\n", subcmd);
  }
  return 0;
}

static int cmd_x(char *args)
{
  char *n_str = strtok(NULL, " ");
  char *expr_str = strtok(NULL, " ");
  if (n_str == NULL || expr_str == NULL)
  {
    printf("Usage: x N EXPR\n");
    return 0;
  }
  int n = atoi(n_str);

  int vaddr_bits = sizeof(vaddr_t) * CHAR_BIT;
  if (strlen(expr_str) > vaddr_bits / 4 + 2)
  {
    printf("Expression too long: %s\n", expr_str);
    return 0;
  }
  char *end;
  errno = 0;
  vaddr_t expr = strtoul(expr_str, &end, 0);
  if (errno != 0 || *end != '\0')
  {
    printf("Invalid expression: %s\n", expr_str);
    return 0;
  }

  for (int i = 0; i < n; i++)
  {
    vaddr_t addr = expr + i * 4;
    word_t data = vaddr_read(addr, 4);
    printf(FMT_WORD ": " FMT_WORD "\n", addr, data);
  }

  return 0;
}

static int cmd_p(char *args)
{
  if (args == NULL)
  {
    printf("Usage: p EXPR\n");
    return 0;
  }
  bool success = true;

  // 测试
   test_expr(&success);

  word_t result = expr(args, &success);
  if (success)
  {
    printf(FMT_WORD "\n", result);
  }
  else
  {
    printf("Failed to evaluate expression: %s\n", args);
  }
  return 0;
}

// ./watchpoint.c
extern int cmd_w(char *args);
extern int cmd_d(char *args);

static int cmd_help(char *args);

static struct
{
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},

    /* TODO: Add more commands */
    {"si", "Step N instructions exactly", cmd_si},
    {"info", "Print program status", cmd_info},
    {"x", "Scan Memory", cmd_x},
    {"p", "Evaluate expression", cmd_p},
    {"w", "Watchpoint operations", cmd_w},
    {"d", "Delete watchpoint", cmd_d}

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args)
{
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL)
  {
    /* no argument given */
    for (i = 0; i < NR_CMD; i++)
    {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else
  {
    for (i = 0; i < NR_CMD; i++)
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

void sdb_set_batch_mode()
{
  is_batch_mode = true;
}

void sdb_mainloop()
{
  if (is_batch_mode)
  {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL;)
  {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL)
    {
      continue;
    }

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
    for (i = 0; i < NR_CMD; i++)
    {
      if (strcmp(cmd, cmd_table[i].name) == 0)
      {
        if (cmd_table[i].handler(args) < 0)
        {
          nemu_state.state = NEMU_QUIT;
          return;
        }
        break;
      }
    }

    if (i == NR_CMD)
    {
      printf("Unknown command '%s'\n", cmd);
    }
  }
}

void init_sdb()
{
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
