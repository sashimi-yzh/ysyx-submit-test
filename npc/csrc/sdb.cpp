#include "exec.h"
#include "expr.h"
#include "ftrace.h"
#include "isa.h"
#include "pmem.h"
#include "watchpoint.h"
#include <iostream>
#include <readline/history.h>
#include <readline/readline.h>

static int is_batch_mode = false;

static char *rl_gets() {
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

static int cmd_q(char *args) { return -1; }

static int cmd_si(char *args) {
  if (args == NULL) {
    cpu_exec(1);
  } else {
    cpu_exec(strtol(args, NULL, 10));
  }
  return 0;
}

static int cmd_info(char *args) {
  if (args == NULL) {
    return 0;
  }
  if (strcmp(args, "r") == 0) {
    isa_reg_display();
  } else if (strcmp(args, "w") == 0) {
    print_wp();
  } else if (strcmp(args, "i") == 0) {
    iringbuf_display();
    print_total_insts_num();
  } else if (strcmp(args, "b") == 0) {
    display_breakpoint();
  } else {
    printf("error '%s' option for 'info'\n", args);
  }
  return 0;
}

static int cmd_x(char *args) {
  char *base = NULL;
  uint64_t size = strtoul(args, &base, 10);
  word_t addr = strtoul(base, NULL, 16);
  for (uint64_t i = 0; i < size; ++i) {
    printf("0x%08x\n", (uint32_t)pmem_read(addr + 4 * i));
  }
  return 0;
}

static int cmd_p(char *args) {
  bool success = true;
  word_t result = expr(args, &success);
  if (!success) {
    printf("eval expr failed, please check the expr\n");
  } else {
    printf(FMT_WORD_D " or " FMT_WORD "\n", result, result);
  }
  return 0;
}

static int cmd_w(char *args) {
  if (args == NULL) {
    printf("w commond need args, add watchpoint failed\n");
    return 0;
  }
  bool success = true;
  word_t result = expr(args, &success);
  if (!success) {
    printf("eval expr failed, please check the expr\n");
  } else {
    WP *wp = new_wp();
    strcpy(wp->expr, args);
    wp->val = result;
  }
  return 0;
}

static int cmd_d(char *args) {
  uint64_t order = strtoul(args, NULL, 10);
  free_wp(order);
  return 0;
}

static int cmd_b(char *args) {
#ifdef FTRACE
  add_breakpoint(args);
#else
  printf("can't use break without ftrace\n");
#endif
  return 0;
}

static int cmd_db(char *args) {
  uint64_t order = strtoul(args, NULL, 10);
  delete_breakpoint(order);
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
    {"q", "Exit NPC", cmd_q},
    {"si", "Step forward n instructions", cmd_si},
    {"info", "Printf reg value or watchpoint or breakpoint", cmd_info},
    {"x", "Printf memory message, example: x 10 0x80000000", cmd_x},
    {"p", "Eval the expr", cmd_p},
    {"w", "Set the watchpoint", cmd_w},
    {"d", "Delete the watchpoint", cmd_d},
    {"b", "Add breakpoint", cmd_b},
    {"db", "Delete the breakpoint", cmd_db}};

#define NR_CMD sizeof(cmd_table) / sizeof(cmd_table[0])

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
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}