#include "common.h"
#include "cpu.h"
#include "mem.h"
#include "sdb.h"

#ifdef SDB
#include <readline/readline.h>
#include <readline/history.h>
#endif

static bool is_batch_mode = false;

#ifdef SDB
/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = nullptr;

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
#endif

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args) {
  npc_state.state = NPC_QUIT;
  return -1;
}

static int cmd_si(char *args) {
  char *arg = strtok(NULL, " ");
  int n = arg == NULL ? 1 : atoi(arg);

  if (n <= 0) printf("Invalid N value\n");
  else cpu_exec(n);
  return 0;
}

static int cmd_info(char *args) {
  char *arg = strtok(NULL, " ");
  if (arg == NULL) {
    printf("info r/w: Print register/watchpoint info\n");
    return 0;
  }
  switch (arg[0]) {
    case 'r': reg_display(); break;
    case 'w': wps_display(); break;
    default: printf("Unknown sub command '%s'\n", arg); break;
  }
  return 0;
}

static int cmd_x(char *args) {
  char *arg = strtok(NULL, " ");
  int n = arg == NULL ? 1 : atoi(arg);
  char *str = strtok(NULL, "\0");

  if (n <= 0) {
    printf("Invalid N value\n");
    return 0;
  }

  addr_t addr;
  bool success = true;
  if (str == NULL || (addr = expr(str, &success), !success)) {
    printf("Invalid EXPR\n");
    return 0;
  }

  for (unsigned int i = 0; i < n; ++i, addr += 4) {
    printf(
      MUXDEF(RV64,"0x%-16llx: 0x%-16llx\n", "0x%-8x: 0x%-8x\n"),
      addr, addr_read(addr, 4)
    );
  }
  return 0;
}

static int cmd_p(char *args) {
  char *str = strtok(NULL, "\0");
  bool success = true;
  word_t val = expr(str, &success);
  if (!success) {
    printf("Invalid EXPR\n");
    return 0;
  }
  printf(
    MUXDEF(RV64, "hex: 0x%llx\nunsigned dec: %llu\nsigned dec: %lld\n", \
                 "hex: 0x%x\nunsigned dec: %u\nsigned dec: %d\n"),
    val, val, val
  );
  return 0;
}

static int cmd_w(char *args) {
  char *str = strtok(NULL, "\0");
  bool success = true;
  
  word_t val;
  if (str == NULL || (val = expr(str, &success), !success)) {
    printf("Invalid EXPR\n");
    return 0;
  }
  WP *p = new_wp(str, val);
  if (p == NULL) {
    printf("Too many watchpoints\n");
    return 0;
  }
  print_wp(p);
  return 0;
}

static int cmd_d(char *args) {
  char *arg = strtok(NULL, " ");
  int n = arg == NULL ? 1 : atoi(arg);

  void free_wp(int no);
  free_wp(n);
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
  { "si", "si N: Execute N instructions and then pause, N = 1 if not given", cmd_si },
  { "info", "info r/w: Print register/watchpoint info", cmd_info },
  { "x", "x N EXPR: Evaluate EXPR, print N*4 bytes starting from the address", cmd_x },
  { "p", "p EXPR: Evaluate EXPR", cmd_p },
  { "w", "w EXPR: Stop when value of EXPR changes(watchpoint)", cmd_w },
  { "d", "d N: Delete watchpoint No.N", cmd_d },
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
    cmd_c(nullptr);
    return;
  }
#ifdef SDB
  for (char *str; (str = rl_gets()) != nullptr; ) {
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
#else
  Log("SDB is disabled, exiting.");
#endif // SDB
}

void init_sdb() {
  void init_regex();
  
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
