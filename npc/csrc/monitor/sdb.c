#include <stdio.h>
#include <cpu/cpu.h>
#include <npc.h>
#ifdef CONFIG_TRACE 
#include <readline/readline.h>
#include <readline/history.h>
#endif
#include "sdb.h"

static int is_batch_mode = false;
#define NR_CMD sizeof(cmd_table)/sizeof(cmd_table[0])
void ref_reg_display();
void init_wp_pool();
void init_regex();

int new_wp(word_t addr, char* args,int type);
int delete_wp(int wp);
WP* get_head();
word_t expr(char *e, bool *success);

static char* rl_gets() {
  static char *line_read = NULL;
  #ifdef CONFIG_TRACE 

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }
  #endif
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
  char* ptr = strtok(args," ");
  if (ptr == NULL) {
    cpu_exec(1);
    return 0;
  }

  int n = atoi(ptr);
  cpu_exec(n);
  return 0;
}

static int cmd_info(char *args) {
  char* ptr = strtok(args," ");
  if (ptr == NULL) return -1;

  if (strcmp(ptr,"r")==0){
    isa_reg_display();
    IFDEF(CONFIG_DIFFTEST, ref_reg_display());
  }else{
    printf("Usage: info r\n");
  }
  return 0;
}

static int cmd_w(char *args) {
  bool success;
  word_t res = expr(args,&success);
  int no = new_wp(res,args,WP_RAW);
  printf("Watchpoint %d, What: %s\n",no,args);
  return 0;
}

static int cmd_d(char *args) {
  int no;
  int n = sscanf(args,"%d",&no);
  Assert(n>0,"Command invalid: %s\n",args);
  delete_wp(no);
  return 0;
}

static int cmd_b(char *args) {
  bool success;
  word_t res = expr(args,&success);
  int no = new_wp(res,args,WP_BREAK);
  printf("Breakpoint %d, What: %s\n",no,args);
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
  {"si","Exec n instruction then pause,default n = 1",cmd_si},
  {"info","Display register(info r)  states",cmd_info},
  {"w","create a watchpoint (w EXPR)",cmd_w},
  {"d","delete watchpoint (d NO)",cmd_d},
  {"b","break point (b address)",cmd_b},
  /* TODO: Add more commands */
};

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

void sdb_mainloop(){
  IFNDEF(CONFIG_TRACE, is_batch_mode=true);
  if (is_batch_mode) {
        cmd_c(NULL);
    return;
  }

  #ifdef CONFIG_TRACE 
  
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
  #endif
  return;
}

void init_sdb(){
  init_regex();
  init_wp_pool();
  return;
}