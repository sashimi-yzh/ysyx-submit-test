#include <common.h>
#include <readline/readline.h>
#include <readline/history.h>

extern void cpu_exec(uint64_t n);
/* We use the `readline' library to provide more flexibility to read from stdin. */

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

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
  npc_state = NPC_QUIT;
  return -1;
}

static int cmd_si(char *args) {
  char *arg = strtok(NULL, " ");
  if(arg == NULL) {
    // 缺省值为1
    cpu_exec(1);
  }
  else {
    uint64_t n = 0;
    sscanf(arg, "%lu", &n);
    cpu_exec(n);
  }
  arg = strtok(NULL, " ");
  return 0;
}

static int cmd_info(char *args) {
  char *arg = strtok(NULL, "");
  if(arg == NULL || strcmp(arg, "r") == 0) {
    // 默认输出寄存器
    // isa_reg_display();
    int i = 0;
    for(;i<16;i++) {
      printf("%s\t" FMT_WORD "\t%u\n", regs[i], (word_t)regs(i), (word_t)regs(i));
    }
    printf("pc\t" FMT_WORD "\t%u\n", (word_t)npc_pc, (word_t)npc_pc);
    printf("mcycle\t" FMT_WORD "\t%u\n", (word_t)npc_mcycle, (word_t)npc_mcycle);
    printf("mcycleh\t" FMT_WORD "\t%u\n", (word_t)npc_mcycleh, (word_t)npc_mcycleh);
    printf("mvendorid\t" FMT_WORD "\t%u\n", (word_t)npc_mvendorid, (word_t)npc_mvendorid);
    printf("marchid\t" FMT_WORD "\t%u\n", (word_t)npc_marchid, (word_t)npc_marchid);
    printf("mstatus\t" FMT_WORD "\t%u\n", (word_t)npc_mstatus, (word_t)npc_mstatus);
    printf("mcause\t" FMT_WORD "\t%u\n", (word_t)npc_mcause, (word_t)npc_mcause);
    printf("mtvec\t" FMT_WORD "\t%u\n", (word_t)npc_mtvec, (word_t)npc_mtvec);
    printf("mepc\t" FMT_WORD "\t%u\n", (word_t)npc_mepc, (word_t)npc_mepc);
  }
  else {
    printf("%s is not supported\n", arg);
  }
  arg = strtok(NULL, " ");
  return 0;
}

static int cmd_x(char *args) {
  char *arg1 = strtok(NULL, " ");
  if(arg1 == NULL) {
    return 0;
  }
  char *arg2 = strtok(NULL, " ");
  if(arg2 == NULL) {
    return 0;
  }
  word_t scan_len = 0, scan_base_addr = 0;
  // 简化版
  sscanf(arg1, "%x", &scan_len);
  sscanf(arg2, FMT_WORD, &scan_base_addr);
  int i = 0;
  scan_base_addr &= 0x7ffffff;
  for(;i<scan_len;i++){
    printf(FMT_WORD ":" FMT_WORD"\n", scan_base_addr, mem_read(mem + scan_base_addr, 4));
    scan_base_addr += 4;
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
  { "q", "Exit NEMU", cmd_q },
  /* TODO: Add more commands */
  { "si", "单步执行", cmd_si},
  { "info", "打印（寄存器）信息", cmd_info},
  { "x", "扫描内存", cmd_x},

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

void sdb_mainloop() {
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
  npc_state = NPC_QUIT;
}
