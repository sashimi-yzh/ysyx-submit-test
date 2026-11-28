#include <readline/readline.h>
#include <readline/history.h>
#include <stdint.h>
#include <stdbool.h>
#include <sdb.h>
#include <autoconf.h>
#include <difftest.h>
#include <disasm.h>
#include <trace.h>
#include <utils.h>

static int is_batch_mode = false;

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
  printf("quit npc\n");
  exit(0);
}

static int cmd_help(char *args);

static int cmd_si(char *args){
  int n = 1;
  if (args != NULL && sscanf(args, "%d", &n) == 1) {
    cpu_exec(n);
  }else{
    cpu_exec(1);
  }
  return 0;
}

static int cmd_info(char *args){
  char c;
  if (args != NULL && sscanf(args, "%c", &c) == 1) {
    if(args[0]=='r'){
      isa_reg_display();
    }else if(args[0] == 'w'){
      info_wp();
    }
    return 0;
  }else{
    printf("error args\n");
    return 0;
  }

}

static int cmd_x(char *args) {
  if (args == NULL) {
    printf("Usage: x N EXPR\n");
    return 0;
  }

  char *arg1 = strtok(args, " ");
  if (arg1 == NULL) {
    printf("Usage: x N EXPR\n");
    return 0;
  }

  int n;
  if (sscanf(arg1, "%d", &n) != 1 || n <= 0) {
    printf("Invalid N: %s\n", arg1);
    return 0;
  }

  char *expr_str = strtok(NULL, "");  
  if (expr_str == NULL) {
    printf("Usage: x N EXPR\n");
    return 0;
  }

  bool success;
  uint32_t addr = expr(expr_str, &success);
  if (!success) {
    printf("Invalid expression: %s\n", expr_str);
    return 0;
  }

  for (int i = 0; i < n; i++) {
    uint32_t word = mem_read(addr + i * 4);
    printf("0x%08x\n", word); 
  }

  return 0;
}
static int cmd_p(char *args){
  bool success;
  uint32_t res = expr(args,&success);
  if(success)
    printf("0x%x\n",res);
  else printf("error expression\n");
  return 0;
}

static int cmd_w(char *args){
  add_wp(args);
  return 0;
}
static int cmd_d(char *args){
  int no;
  if (sscanf(args, "%u", &no) == 1) {
    remove_wp(no);
    return 0;
  } else {
    printf("error args\n");
    return 0;
  }
  return 0;
}
static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Single step the program by one instruction", cmd_si },
  { "info", "Print program status", cmd_info },
  { "x", "Scan memory content", cmd_x },
  { "p", "Expression calcluate",cmd_p},
  { "w", "Add a watchpoint", cmd_w},
  { "d", "Remove a watchpoint", cmd_d},

  /* TODO: Add more commands */

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
#ifndef CONFIG_ENABLE_SDB
  sdb_set_batch_mode();
#endif
  if (is_batch_mode) {
    printf("start batch mode\n");
    cmd_c(NULL);
    return;
  }
  printNextInst();

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
  printf("quit npc (EOF)\n");
  exit(0);
}


static uint32_t commit_pc;
static bool has_commit = false;
static bool ever_committed = false;
static uint32_t last_commit_pc = 0;

int commit_mem_valid = 0;
uint32_t commit_mem_addr = 0;
uint32_t commit_inst = 0;
uint32_t commit_dnpc = 0;

extern "C" void commit(int pc, int inst, int dnpc, int mem_commit, int mem_addr){
  commit_pc = pc;
  commit_inst = (uint32_t)inst;
  commit_dnpc = (uint32_t)dnpc;
  last_commit_pc = pc;
  ever_committed = true;
  has_commit = true;
  commit_mem_valid = mem_commit;
  commit_mem_addr = (uint32_t)mem_addr;
}

#define STUCK_THRESHOLD 50000
static uint32_t stuck_cycle = 0;
uint64_t inst_counter = 0; 
bool check_commit(){
  if(has_commit){
    stuck_cycle = 0;
    has_commit = false;
    check_difftest(commit_pc);
    trace_record(commit_pc,commit_inst,commit_dnpc);
    inst_counter ++;
    return true;
  }
  stuck_cycle++;
  if(stuck_cycle >= STUCK_THRESHOLD){
    printf("npc has not commited in %d cycle, maybe stuck\r",stuck_cycle);
  }
  return false;
}

void printInstRaw(uint32_t pc, uint32_t inst){
    uint8_t code[4] = {
        (uint8_t)(inst >> 0),
        (uint8_t)(inst >> 8),
        (uint8_t)(inst >> 16),
        (uint8_t)(inst >> 24)
    };
    char buf[128];
    disassemble(buf, sizeof(buf), pc, code, 4);
    printf("0x%08x: 0x%08x\t%s\n", pc, inst, buf);
}

void printInst(uint32_t pc){
    printInstRaw(pc, mem_read(pc));
}

uint32_t cur_pc(){
  return ever_committed ? commit_dnpc : read_fetch_pc();
}

void printNextInst(){
  if (ever_committed) {
    printf("commit:     ");
    printInstRaw(last_commit_pc, commit_inst);
  }
  printf("next:       ");
  printInst(ever_committed ? commit_dnpc : read_fetch_pc());
}

void init_sdb() {
  init_disasm();
  init_regex();
  init_wp_pool();
}
