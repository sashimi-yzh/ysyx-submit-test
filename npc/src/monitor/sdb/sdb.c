#include <isa.h>
#include <cpu/cpu.h>
#include <memory/vaddr.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"

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
  npc_state.state = NPC_QUIT;
  return -1;
}

static int cmd_si(char *args) {
  uint64_t n = 1;
  if (args != NULL) {
    n = strtol(args, NULL, 0);
  }
  cpu_exec(n);
  return 0;
}

static int cmd_info(char *args) {
  if (args == NULL) {
    printf("Usage: info r (registers) or info w (watchpoints)\n");
  }
  else if (strcmp(args, "r") == 0) {
    isa_reg_display();
  }
  else if (strcmp(args, "w") == 0) {
    wp_display();
  }
  else {
    printf("Unknown info type '%s'\n", args);
  }
  return 0;
}

static int cmd_x(char *args) {
  char *n_str = args == NULL ? NULL : strtok(args, " ");
  char *expr_str = n_str == NULL ? NULL : strtok(NULL, "");
  if (expr_str == NULL) {
    printf("Usage: x <N> <EXPR>\n");
    return 0;
  }
  int num = strtol(n_str, NULL, 0);

  bool success = false;
  vaddr_t addr = expr(expr_str, &success);
  if (!success) {
    printf("Bad expression: %s\n", expr_str);
    return 0;
  }

  for (int i = 0; i < num; i ++) {
    printf(ANSI_FG_GREEN FMT_WORD ": " ANSI_FG_BLUE FMT_WORD "\n" ANSI_NONE, addr + i * 4, vaddr_read(addr + i * 4, 4));
  }
  return 0;
}

static int cmd_p(char* args) {
  bool success = false;
  if (args == NULL) {
      printf("Usage: p <EXPR>\n");
      return 0;
  }
  word_t ans = expr(args, &success);
  if (success)
    printf(ANSI_FG_GREEN"[DEC] %u\n[HEX] 0x%x\n"ANSI_NONE, ans, ans);
  else
    printf(ANSI_FG_RED"EXPR is illegal!\n"ANSI_NONE);
  return 0;
}

static int cmd_w(char *args) {
  if (args == NULL) {
    printf("Usage: w <EXPR>\n");
    return 0;
  }
  int NO = new_wp(args);
  if (NO == -1) {
    printf("Failed to create watchpoint\n");
  } else {
    printf("Watchpoint %d: %s\n", NO, args);
  }
  return 0;
}

static int cmd_d(char *args) {
  if (args == NULL) {
    printf("Usage: d <NO>\n");
    return 0;
  }
  int NO = strtol(args, NULL, 0);
  if (free_wp(NO)) {
    printf("Watchpoint %d deleted\n", NO);
  } else {
    printf("Watchpoint %d not found\n", NO);
  }
  return 0;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NPC", cmd_q },
  { "si", "Pause after executing [N] instructions", cmd_si },
  { "info", "r: Print register status, w: Print watchpoint information", cmd_info },
  { "x", "Scan <N> words starting from <EXPR>", cmd_x },
  { "p", "Find the value of <EXPR>", cmd_p },
  { "w", "Set watchpoint <EXPR>", cmd_w },
  { "d", "Delete watchpoint <NO>", cmd_d },
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
    printf("Unknown command '%s'\n", arg);
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
