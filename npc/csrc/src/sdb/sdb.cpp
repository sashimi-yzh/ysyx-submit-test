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

// #include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <paddr.h>
// #include <reg.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
void reg_display();

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
  // printf("%d\n",npc_state.state);//STOP
  npc_exec(-1);
  // printf("%d\n",npc_state.state);//NEMU_END
  return 0;
}


static int cmd_q(char *args) {
  npc_state.state = NPC_QUIT;
  // printf("%d\n",npc_state.state);
  return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args);

static int cmd_info(char *args);

static int cmd_x(char *args);

static int cmd_p(char *args);

static int cmd_w(char *args);

static int cmd_d(char *args);

static int cmd_test(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);  //函数指针
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Execute N steps of the program", cmd_si },
  { "info", "Print the situation of the program, r/w", cmd_info },
  { "x", "Scan ddr", cmd_x },
  { "p", "Mathematical expression evaluation", cmd_p },
  { "w", "Set your watchponits", cmd_w },
  { "d", "Delete watchponits", cmd_d },
  { "test", "Test expression", cmd_test }

};

#define NR_CMD ARRLEN(cmd_table)


static int cmd_test(char *args){
#if CONFIG_SINGLETEST
  char* e = get_expr();
  printf("%s\n",e);
  bool a = false;
  bool is_division0 = false;
  word_t result = expr(e,&a);
  is_division0 = division();
  clean();
    if (is_division0 == true){
      printf("-1\n");
    }
    else{
      printf("%d\n", result);
    }
  // return 0;
#else
  FILE *fp = fopen("test_expr3.txt", "a");
  if (fp == NULL) {
    printf("can't open file\n");
    return -1;
  }

  for (int i = 0; i < 10000; i++) {
    char* e = get_expr();
    if (e == NULL) {
        printf("get_expr() 返回 NULL\n");
        continue;
    }

    // bool is_division0 = false;
    bool a = false;
    word_t result = expr(e, &a);
    // is_division0 = division();1
    

    // if (is_division0) {
        // fprintf(fp, "%s -1\n", e);
    // }
    // else{
        fprintf(fp, "%s %d\n", e, result);
    // }
    clean();
  }

  fclose(fp);
#endif
  return 0;
}

static int cmd_si(char *args){
  int step = 0;
  if(args == NULL)
    step = 1;
  else
    sscanf(args,"%d",&step);// 读入 Step
  // printf("%08x\n",cpu_state());
  npc_exec(step);
  return 0;
}

static int cmd_p(char *args){

    if(args == NULL){
        printf("No args\n");
        return 0;
    }

    char* arr = strtok(args," ");
    char* mode = strtok(NULL," ");
    const char* h = "h";

    bool is_division0 = false;
    bool a = false;
    word_t result = expr(arr,&a);
    is_division0 = division();
    if (is_division0 == true){
      printf("-1\n");
    }
    else{
      if(mode == NULL){
        printf("%d\n", result);
      }
      else if(strcmp(mode,h) == 0){
        printf("%x\n", result);
      }
    }
    return 0;
}

static int cmd_x(char *args){
    char* n = strtok(args," ");
    char* baseaddr = strtok(NULL," "); //后续的调用需传入NULL，提示从上一次分割结束开始
    int len = 0;
    paddr_t addr = 0;
    sscanf(n, "%d", &len);
    sscanf(baseaddr,"%x", &addr);
    for(int i = 0 ; i < len ; i ++)
    {
      printf("%08x\n", 0x80000000);//addr len
      addr = addr + 4;
    }
    return 0;
}

static int cmd_d(char* args){
  if(args == NULL){
    printf("No args.\n");
  }   
  else{
    delete_watchpoint(atoi(args));
  }
  return 0;
}

static int cmd_w(char* args){
  create_watchpoint(args);
  return 0;
}

static int cmd_info(char *args){
    if(args == NULL)
        printf("No args.\n");
    else if(strcmp(args, "r") == 0)
        reg_display();//寄存器
    else if(strcmp(args, "w") == 0)
        sdb_watchpoint_display();//监视点
    return 0;
}

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
