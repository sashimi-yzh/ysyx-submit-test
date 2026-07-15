#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "cpu-exe.hpp"
#include "DPIC.hpp"
#include "reg.hpp"

static int is_batch_mode = false;

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(NPC) ");

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

static int cmd_info(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");

  if (arg == NULL) {
    printf("Hint: Try <info r>\n");
  }

  else if(strcmp(arg, "r") == 0) {
    isa_reg_display();
  }

  else {
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}


static int cmd_x(char *args);
static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NPC", cmd_q },
  { "si", "Step in one instruction", cmd_si},
  { "x", "Scan the memory", cmd_x},
  { "info", "Print the info of reg", cmd_info},
  /* TODO: Add more commands */
};

#define NR_CMD sizeof(cmd_table) / sizeof(cmd_table[0])


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

static int cmd_x(char *args) {
  // /* extract the first argument */
  // char *arg = strtok(NULL, " ");

  // if (arg == NULL) {
  //   printf("Hint: Try x <num> <addr>\n");
  // }

  // else{
  //   int scannum = atoi(arg);

  //   arg = strtok(NULL, " ");
  //   if(arg == NULL) {
  //     printf("Hint: Try x <num> <addr>\n");
  //   }
  //   else {
  //     int startaddr = (int)strtol(arg, NULL, 0);

  //     if(startaddr % 4 != 0) {
  //       printf("Address should be aligned to 4 bytes.\n");
  //       return 0;
  //     }
      
  //     for(int i=0; i<scannum; i++)
  //     {
  //       printf("0x%08x: 0x%08x\n", startaddr + i*4, pmem_read(startaddr + i*4));
  //     }
  //   }
    
  // }
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

