/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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
#include "memory/vaddr.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

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
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_si(char *args)
{
  int step = 2;
  if (args == NULL)
    step = 1;
  else
    sscanf(args, "%d", &step);
  cpu_exec(step);
  return 0;
}

static int cmd_info(char *args)
{
  if (args == NULL)
    printf("No args\n");
  else if (*args == 'r')
    isa_reg_display();
  else if (*args == 'w')
    sdb_watchpoint_display();
  else
    printf("Unknown Command... Please use 'r' or 'w' for the end\n");
  return 0;
}

static int cmd_x(char *args)
{
  char *n = strtok(args, " ");
  char *mem_addr = strtok(NULL, "");
  int len;
  vaddr_t addr;
  word_t value;
  sscanf(n, "%d", &len);
  sscanf(mem_addr, "%x", &addr);
  for (uint8_t i = 0; i < len; i++)
  {
    value = vaddr_read(addr, 4);
    printf("0x%08x:\t0x%08x\n", addr, value);
    addr = addr + 4;
  }
  return 0;
}

static int cmd_p(char *args)
{
  if (args == NULL)
  {
    printf("No args\n");
    return 0;
  }
  bool flag = false;
  expr(args, &flag);
  return 0;
}

static int cmd_d(char *args)
{
  if (args == NULL)
    printf("No args.\n");
  else
  {
    delete_watchpoint(atoi(args));
  }
  return 0;
}

static int cmd_w(char *args)
{
  if (args == NULL)
    printf("No args.\n");
  else
    create_watchpoint(args);
  return 0;
}

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
    {"si", "Step the program for N circles", cmd_si},
    {"info", "Display the general registers or watch point", cmd_info},
    {"x", "Scan the momory like 'x len addr'", cmd_x},
    {"p", "Type in the express like 'p express'", cmd_p},
    {"d", "Delete the index of the watchpoint", cmd_d},
    {"w", "Create a Watchpoint", cmd_w}

    /* TODO: Add more commands */

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

void watch_point()
{
  for (int i = 0; i < NR_WP; i++)
  {
    if (wp_pool[i].is_used)
    {
      bool success = false;
      int tmp = expr(wp_pool[i].expr, &success);

      // break point
      if((strcmp(wp_pool[i].op, "==") == 0) && (wp_pool[i].break_value == tmp) && success) {
        nemu_state.state = NEMU_STOP;
        printf("%s %s %x, program is stop due to break point\n", wp_pool[i].expr, wp_pool[i].op, wp_pool[i].break_value);
        wp_pool[i].old_value = tmp;
        continue;
      }

      if (success)
      {
        if (tmp != wp_pool[i].old_value)
        {
          nemu_state.state = NEMU_STOP;
          printf("the %s is changed\nold_value is 0x%x\nnew_valud is 0x%x\n", wp_pool[i].expr, wp_pool[i].old_value, tmp);
          wp_pool[i].old_value = tmp;
        }
      }
      else
      {
        printf("expr error.\n");
        assert(0);
      }
    }
    else
      break;
  }
}
