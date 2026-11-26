#include "sdb.h"
#include "../core/npc.h"
#include "../utils/log.h"
#ifdef ENABLE_TRACE
#include "../trace/itrace.h"
#include "../trace/mtrace.h"
#include "../trace/ftrace.h"
#endif
#include <readline/readline.h>
#include <readline/history.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

// 简单 PC 断点
#define NR_BREAKPOINT 16
static uint32_t breakpoints[NR_BREAKPOINT];
static bool breakpoint_on[NR_BREAKPOINT];

bool check_breakpoints() {
  uint32_t pc = npc_get_pc();
  for (int i = 0; i < NR_BREAKPOINT; i++) {
    if (breakpoint_on[i] && breakpoints[i] == pc) return true;
  }
  return false;
}

/* 使用readline库提供更灵活的输入 */
static char* rl_gets() {
  static char *line_read = NULL;
  static char prompt[64];

  if (log_color_enabled()) {
    snprintf(prompt, sizeof(prompt),
             "\001" ANSI_FG_CYAN "\002(npc) \001" ANSI_NONE "\002");
  } else {
    snprintf(prompt, sizeof(prompt), "(npc) ");
  }

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline(prompt);

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

// c命令 - 继续执行
static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

// q命令 - 退出
static int cmd_q(char *args) {
  return -1;
}

// si命令 - 单步执行
static int cmd_si(char *args) {
  int n = 1;  // 默认执行1条指令
  
  if (args != NULL) {
    char *end = NULL;
    long value = strtol(args, &end, 0);
    if (end == args || *end != '\0' || value <= 0) {
      printf("Usage: si [positive N]\n");
      return 0;
    }
    n = (int)value;
  }
  
  cpu_exec(n);
  
  return 0;
}

// info命令 - 打印寄存器或监视点信息
static int cmd_info(char *args) {
  if (args == NULL) {
    printf("Usage: info r - print GPR/CSR info\n");
    printf("       info w - print watchpoint info\n");
    printf("       info b - print PC breakpoints\n");
    return 0;
  }
  
  if (strcmp(args, "r") == 0) {
    npc_reg_display();
  } 
  else if (strcmp(args, "w") == 0) {
    display_watchpoints();
  }
  else if (strcmp(args, "b") == 0) {
    for (int i = 0; i < NR_BREAKPOINT; i++) {
      if (breakpoint_on[i]) printf("%d: 0x%08x\n", i, breakpoints[i]);
    }
  }
  else {
    printf("Unknown subcommand: %s\n", args);
  }
  
  return 0;
}

// x命令 - 扫描内存
static int cmd_x(char *args) {
  if (args == NULL) {
    printf("Usage: x N EXPR\n");
    return 0;
  }
  
  int n;
  char expr_str[256];
  
  if (sscanf(args, "%d %255s", &n, expr_str) != 2 || n <= 0) {
    printf("Invalid format. Usage: x N EXPR (N > 0)\n");
    return 0;
  }
  
  // 求值表达式
  bool success = false;
  word_t addr = expr(expr_str, &success);
  
  if (!success) {
    printf("Invalid expression\n");
    return 0;
  }
  
  // 打印内存内容
  for (int i = 0; i < n; i++) {
    if (i % 4 == 0) {
      printf("0x%08x: ", addr + i * 4);
    }
    
    word_t data = 0;
    if (!npc_mem_read_word(addr + i * 4, &data)) {
      printf("??        ");
    } else {
      printf("0x%08x  ", data);
    }
    
    if (i % 4 == 3) printf("\n");
  }
  
  if (n % 4 != 0) printf("\n");
  
  return 0;
}

// p命令 - 表达式求值
static int cmd_p(char *args) {
  if (args == NULL) {
    printf("Usage: p EXPR\n");
    return 0;
  }
  
  bool success = false;
  word_t result = expr(args, &success);
  
  if (success) {
    printf("%u (0x%x)\n", result, result);
  } else {
    printf("Invalid expression\n");
  }
  
  return 0;
}

// w命令 - 设置监视点
static int cmd_w(char *args) {
  if (args == NULL) {
    printf("Usage: w EXPR\n");
    return 0;
  }
  
  create_watchpoint(args);
  
  return 0;
}

// d命令 - 删除监视点
static int cmd_d(char *args) {
  if (args == NULL) {
    printf("Usage: d N\n");
    return 0;
  }
  
  int no;
  sscanf(args, "%d", &no);
  
  if (delete_watchpoint(no)) {
    printf("Watchpoint %d deleted\n", no);
  } else {
    printf("Watchpoint %d not found\n", no);
  }
  
  return 0;
}

// b命令 - 添加 PC 断点
static int cmd_b(char *args) {
  if (args == NULL) {
    printf("Usage: b ADDR\n");
    return 0;
  }
  char *end = NULL;
  uint32_t addr = (uint32_t)strtoul(args, &end, 0);
  if (end == args || *end != '\0') {
    printf("Invalid address\n");
    return 0;
  }
  for (int i = 0; i < NR_BREAKPOINT; i++) {
    if (breakpoint_on[i] && breakpoints[i] == addr) {
      printf("Breakpoint already exists: %d\n", i);
      return 0;
    }
  }
  for (int i = 0; i < NR_BREAKPOINT; i++) {
    if (!breakpoint_on[i]) {
      breakpoint_on[i] = true;
      breakpoints[i] = addr;
      printf("Breakpoint %d at 0x%08x\n", i, addr);
      return 0;
    }
  }
  printf("No free breakpoint\n");
  return 0;
}

// db命令 - 删除断点
static int cmd_db(char *args) {
  if (args == NULL) {
    printf("Usage: db N\n");
    return 0;
  }
  int no = atoi(args);
  if (no < 0 || no >= NR_BREAKPOINT || !breakpoint_on[no]) {
    printf("Breakpoint %d not found\n", no);
    return 0;
  }
  breakpoint_on[no] = false;
  printf("Breakpoint %d deleted\n", no);
  return 0;
}

// snapshot命令 - 手动输出失败快照
static int cmd_snapshot(char *args) {
  (void)args;
  npc_dump_snapshot();
  return 0;
}

// trace命令 - 运行时开关 trace
static int cmd_trace(char *args) {
#ifdef ENABLE_TRACE
  char *action = NULL;
  char *what = NULL;
  if (args != NULL) {
    action = strtok(args, " ");
    what = strtok(NULL, " ");
  }

  if (action == NULL || strcmp(action, "status") == 0) {
    printf("itrace=%s mtrace=%s ftrace=%s\n",
           itrace_enabled() ? "on" : "off",
           mtrace_enabled() ? "on" : "off",
           ftrace_enabled() ? "on" : "off");
    return 0;
  }

  bool enable = (strcmp(action, "on") == 0);
  if (!enable && strcmp(action, "off") != 0) {
    printf("Usage: trace [on|off] [itrace|mtrace|ftrace]\n");
    return 0;
  }

  if (what == NULL) {
    set_itrace_enabled(enable);
    set_mtrace_enabled(enable);
    set_ftrace_enabled(enable);
  } else if (strcmp(what, "itrace") == 0) {
    set_itrace_enabled(enable);
  } else if (strcmp(what, "mtrace") == 0) {
    set_mtrace_enabled(enable);
  } else if (strcmp(what, "ftrace") == 0) {
    set_ftrace_enabled(enable);
  } else {
    printf("Unknown trace type: %s\n", what);
    return 0;
  }
  printf("trace %s %s\n", what ? what : "all", enable ? "on" : "off");
#else
  (void)args;
  printf("TRACE is disabled at compile time\n");
#endif
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
  { "si", "Step [N] instructions", cmd_si },
  { "info", "Print register or watchpoint info", cmd_info },
  { "x", "Examine memory: x N EXPR", cmd_x },
  { "p", "Evaluate expression: p EXPR", cmd_p },
  { "w", "Set watchpoint: w EXPR", cmd_w },
  { "d", "Delete watchpoint: d N", cmd_d },
  { "b", "Set PC breakpoint: b ADDR", cmd_b },
  { "db", "Delete PC breakpoint: db N", cmd_db },
  { "snapshot", "Dump GPR/CSR and recent trace", cmd_snapshot },
  { "trace", "Trace control: trace [on|off] [itrace|mtrace|ftrace]", cmd_trace },
};

#define NR_CMD (sizeof(cmd_table) / sizeof(cmd_table[0]))

static int cmd_help(char *args) {
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
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

    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

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
  init_regex();
  init_wp_pool();
}
