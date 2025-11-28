/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <memory/vaddr.h>
#include <stdlib.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

extern int new_wp(word_t addr, char* args,int type);
extern int delete_wp(int wp);
extern WP* get_head();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

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
  nemu_state.state = NEMU_QUIT;
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
  }else if(strcmp(ptr,"w")==0){
    WP* cur = get_head();
    while (cur != NULL){
        printf("Num: %d, Value: %08x, What: %s\n",cur->NO,cur->value,cur->args);
        cur = cur->next;
    }
  }else{
    printf("Usage: info r/w\n");
  }
  return 0;
}

static int cmd_x(char *args) {
  char *args_end = args + strlen(args);
  char *ptr = strtok(args," ");
  int n = atoi(ptr);
  char *expression = ptr + strlen(ptr) + 1;
  if (args >= args_end) {
      args = NULL;
  }
  bool success;
  word_t address = expr(expression,&success);
  for (int i=0;i<n;i=i+4){
    word_t res ;
    char log_buf[128];
    char *p = log_buf;
    if (n-i<4){
      switch (n-i){
        case 1: 
          res = vaddr_read(address+i,1);
          p+=snprintf(p, 4, "%02x", res);
        break;
        case 2: 
          res = vaddr_read(address+i,2);
          p+=snprintf(p, 8, "%04x", res);
          break;
        case 3: 
          res = vaddr_read(address+i+2,1);
          p+=snprintf(p, 4, "%02x", res);
          res = vaddr_read(address+i,2);
          p+=snprintf(p, 8, "%04x", res);  
 
          break; 
        default:
          break;
      }
      puts(log_buf);
      break;
    }
    res = vaddr_read(address+i,4);
    p+=snprintf(p, 16, "%08x", res);
    puts(log_buf);
  }
  return 0;
}

static int cmd_p(char *args) {
  bool success;
  word_t res = expr(args,&success);
  printf("%d\n",res);
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
  {"info","Display register(info r) or watchpoint(info w) states",cmd_info},
  {"x","Display n bytes from EXPR address(x N EXPR)",cmd_x},
  {"p","Display result of EXPR (p EXPR)",cmd_p},
  {"w","create a watchpoint (w EXPR)",cmd_w},
  {"d","delete watchpoint (d NO)",cmd_d},
  {"b","break point (b address)",cmd_b},
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
