/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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
#include <stdbool.h>
#include <watchpoint.h>
#include <ftrace.h>
#include <fmt-def.h>

int is_batch_mode = false;

void init_regex();
void init_wp_pool();
void init_bp_pool();

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



/*表达式求值*/
static int cmd_p(char *args){
  if(args == NULL){
    printf("No parameter!\n");
    return 1;
  }
  //puts(args);
  bool success=true;
  word_t result = expr(args, &success);
  printf(FMT_WORD_UINT"    0x" FMT_WORD_HEX "\n",result, result);
  return 0;
}

/*设置监视点*/
static int cmd_w(char* args){
  if(args == NULL){
    printf("No parameter!\n");
    return 1;
  }
  set_watchpoint(args);
  return 0; 
}

/*扫描内存*/
static int cmd_x(char *args){
  if(args == NULL){
    printf("No parameter!\n");
    return 1;
  }

  char *arg = strtok(args, " ");

  int size = atoi(arg);

  char *expr_str;
  expr_str = strtok(NULL, "");

  if(expr_str == NULL){
    printf("Too few parameters!\n");
    return 1;
  }

  //char *end;

  //vaddr_t addr = strtoull(expr_str, &end, 16);

  vaddr_t addr;
  //sscanf(expr_str, "" FMT_WORD_HEX "", &addr);
  bool success = false;
  addr = expr(expr_str, &success);
  assert(success == true);

  for(int i=0; i<size; i++){
    vaddr_t data = vaddr_read(addr + i * 4, 4);
    printf("0x" FMT_WORD_HEX_WIDTH "\t", addr + i * 4);
#ifdef CONFIG_RV64
    printf("0x%08lx\n",data);
#else
    printf("0x%08x\n",data);
#endif 
    //putchar('\n');
    
  }

  arg = strtok(arg, " ");


  return 0;
}

static int cmd_info(char *args);
/*单步执行*/
static int cmd_si(char * args){
  int step =  0;
  if(args == NULL)
    step = 1;
  else
    step = atoi(args);
  cpu_exec(step);
  //cmd_info("r");
  return 0;
}


/*打印程序状态*/
static int cmd_info(char *args){
  if(args == NULL){
    printf("No parameter!\n");
    return 1;
  }

  char *arg = strtok(args," ");
  if(!strcmp(arg,"r"))
  {
    //打印寄存器信息
    isa_reg_display();
  }
  else if (!strcmp(arg,"w"))
  {
    //打印监视点信息
    print_watchpoint();

  }
  else if(!strcmp(arg, "f"))
  {
    //打印ftrace信息
    ftrace_func_call_list_print();
  }
  else if(!strcmp(arg, "c"))
  {
    //打印csr信息
    isa_csr_display();
  }
  else{
    printf("Unrecognized option: %s\n", args);
  }
  
  return 0;
}

/*删除监视点*/
static int cmd_d(char *args){
  if(args == NULL){
    printf("No parameter!\n");
    return 1;
  }
  del_watchpoint(atoi(args));
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
  {"si", "Single step", cmd_si},
  {"info", "Print the status of program", cmd_info},
  {"x", "Scan the memory",cmd_x},
  {"p", "Get the value of an expression",cmd_p},
  {"w", "Set up monitoring point", cmd_w},
  {"d", "Deleting monitoring point", cmd_d},
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

  /* Initialize the breakpoint pool. */
  init_bp_pool();
}
