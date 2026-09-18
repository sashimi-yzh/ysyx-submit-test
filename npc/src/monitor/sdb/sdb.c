#include <npc.h>
#include <sdb.h>
#include <readline/readline.h>
#include <readline/history.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

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
  int n = 1;

  if (args != NULL) {
    char *a;
    n = strtol(args, &a, 10);
    if (a == args || *a != '\0' || n <= 0) {
        printf("Error: Unknown usage: '%s'\nUsage: si [N] -- N: positive integer --\n", a);
        return 0;
    }
  }
  if (npc_state.state != NPC_END) printf("Executing %d instructions...\n", n);
  cpu_exec(n);
  return 0;
}

static int cmd_info(char *args) {
  if (args == NULL) {
    printf("Error: Unknown usage: '%s'\nUsage: info r -- print registers\n       info w -- print watchpoints\n", args);
    return 0;
  }
  switch (args[0]) {
    case 'r': isa_reg_display(); return 0;
    case 'w': return c_print();
    default: printf("Unknown usage: '%s'\n", args); return 0;
  }
}

static int cmd_x(char *args) {
  int n = 0;
  uint32_t s;
  char *a0;
  char *arg = args;
  bool success;

  if (args == NULL) {
    printf("Now: 0x%08X: %08x\n", CPU_PC(), CPU_INST());
    return 0;
  }

  char *arg0 = strtok(NULL, " ");//arg0 is the frist argv
  char *arg1 = strtok(NULL, " ");//arg1 is the second argv

  if (arg0 != NULL) {
    n = strtol(arg0, &a0, 10);
    s = (arg1 == NULL) ? CPU_PC(): expr(arg1, &success);

    if (a0 == arg0 || *a0 != '\0' || n <= 0) printf("Error: Unknown usage: '%s'\n", arg);

    uint32_t start = 0x80000000;
    for (uint32_t i = start; i < 0X88000000 ; i += 4) {
      if (s == i) {
        for (int c = 0; c < n; c ++) {
          uint32_t current = i + c * 4;
          if (current >= 0X88000000) break;

          uint32_t value = pmem_read(current);
          printf("0x%08X: %08X\n", current, value);
        }
        return 0;
      }
    }
    for (int c = 0; c < n; c ++) {
      uint32_t current = s + c * 4;
      printf("0x%08X: NULL\n", current);
    }
  }

  return 0;
}

static int cmd_p(char *args) {
  bool success;
  uint32_t result = expr(args, &success);
  if (success) {
    printf("%d\n", result);
    return 0;
  }
  else assert(0);
}

static int cmd_w(char *args) {
  return c_w(args);
}

static int cmd_d(char *args) {
  return c_d(args);
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Single-step implementation", cmd_si },
  { "info", "Print program status", cmd_info },
  { "x", "Scanning memory", cmd_x },
  { "p", "Expression evaluation", cmd_p},
  { "w", "Set up a monitoring point", cmd_w},
  { "d", "Delete the monitoring point", cmd_d}

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
