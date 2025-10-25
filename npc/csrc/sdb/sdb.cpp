#include "tpdef.h"

#include <cstdio>
#include <iostream>
#include <readline/readline.h>
#include <readline/history.h>

static char* rl_gets();

// command function define
static int cmd_help(char *args);
int cmd_c(char *args);
int cmd_q(char *args);
int cmd_si(char* args);
int cmd_info(char* args);
int cmd_x(char* args);
int cmd_p(char* args);
int cmd_w(char* args);
int cmd_d(char* args);
int cmd_v(char* args);
int cmd_n(char* args);
int cmd_csim(char* args);


// command table <name describe fuction> 
static struct 
{
    const char *name;
    const char *description;
    int (*handler) (char *);
    
} cmd_table [] = {
    { "help", "Display information about all supported commands", cmd_help },
    { "c", "Continue the execution of the program", cmd_c },
    { "q", "Exit NPC TEST", cmd_q },
    { "si", "Single or N step execution", cmd_si },
    { "info", "Print status of program", cmd_info },
    { "x", "Four bytes of memory after scanning", cmd_x},
    { "p", "Find the value of the provided expression", cmd_p},
    { "w", "Stop program when ${EXPR} change", cmd_w},
    { "d", "Delete watch point with wp NO", cmd_d},
    { "v", "Start vcd trace create.", cmd_v},
    { "n", "Start vcd trace create.", cmd_n},
    { "csim", "run cachesim.", cmd_csim}
    /* TODO: Add more commands */
};

#define CMD_LEN ARRLEN(cmd_table)

static bool is_batch_mode = false;
void set_batch_mode() { is_batch_mode = true; }


// display help
static int cmd_help(char *args)
{
  // extract the first argument
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) 
  {
    // no argument given
    for (i = 0; i < CMD_LEN; i++)
      printf("%s\t- %s\n", cmd_table[i].name, cmd_table[i].description);
  }
  else 
  {
    for (i = 0; i < CMD_LEN; i++) 
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


// main loop 
void sdb_mainloop() 
{
  void init_regex();
  init_regex();

  if (is_batch_mode)
  {
    cmd_c(nullptr);
    return;
  }

  int previous = -1;

  for (char *str; (str = rl_gets()) != nullptr; ) 
  {
    char *str_end = str + strlen(str);

    // extract the first token as the command
    char *cmd = strtok(str, " ");
    if (cmd == nullptr) 
    { 
      if (previous == 1 || previous == 3 || previous == 10) {
        cmd_table[previous].handler(NULL);
      }      
      continue; 
    }

    // get args of cmd
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) 
      args = nullptr;

    int i = 0;
    for (; i < CMD_LEN; i ++) 
    {
      if (strcmp(cmd, cmd_table[i].name) == 0) 
      {
        if (cmd_table[i].handler(args) < 0) { return; }
        previous = i;
        break;
      }
    }

    if (i == CMD_LEN) { printf("Unknown command '%s'\n", cmd); }
  }
}


// use readline lib
static char* rl_gets() 
{
  static char *line_read = nullptr;

  if (line_read)
  {
    free(line_read);
    line_read = nullptr;
  }

  line_read = readline(ANSI_FMT("(npc) ", ANSI_FG_CYAN));

  if (line_read && *line_read)
    add_history(line_read);

  return line_read;
}