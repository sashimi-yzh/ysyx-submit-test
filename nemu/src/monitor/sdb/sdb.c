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
#include <memory/paddr.h>
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
  nemu_state.state = NEMU_QUIT;//优美地退出
  return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args) {
  int N;
  if (args == NULL){
    N = 1;
  }
  else{
    sscanf(args,"%d",&N);
    //printf("%d\n",N);
  }
  cpu_exec(N);
  return 0;
}

static int cmd_info(char *args) {
  char ARG;
  if (args == NULL){
    printf("args needed\n");
  }
  else{
    sscanf(args,"%c",&ARG);
    if (ARG == 'r'){
      isa_reg_display();
    }
    else if (ARG == 'w'){
      wp_display();
    }
    else{
      printf("not support yet\n");
    }
  }
  return 0;
}

static int cmd_x(char *args) {
  int ARG1;
  paddr_t ARG2;
  int ARGN;
  if (args == NULL){
    printf("args needed\n");
  }
  else{
    ARGN = sscanf(args,"%d %x",&ARG1,&ARG2);
    //printf("%d\n",ARGN);
    if (ARGN != 2){
      printf("wrong arg number\n");
    }
    else{
      //printf("%x\n",ARG2);
      for(int i = 0; i < ARG1; i++){
        printf("0x%x: 0x%08x\n",ARG2,paddr_read(ARG2,4));
        ARG2 += 4;
      }
      printf("\n");
    }
  }
  return 0;
}

static int cmd_p(char *args) {
  if (args == NULL){
    printf("args needed\n");
  }
  else{
    bool success = false;
    uint32_t result = expr(args,&success);
    if (success == false){
      printf("expr function false\n");
    }
    else{
      printf("result: %u(DEC) 0x%08x(HEX)\n",result,result);
    }
  }
  return 0;
}

static int cmd_test_expr(char *args) {
  FILE *file = fopen("/home/plutoisy/ysyx-workbench/nemu/tools/gen-expr/input", "r");
  if (file == NULL) {
      perror("无法打开文件");
      return 1;
  }
  
  char line[10001];
  char result[500];
  char expression[65536];
  int wrong_ans = 0;
  int test_time = 0;
  while (fgets(line, sizeof(line), file)) {
    if (sscanf(line, "%s %[^\n]", result, expression) == 2) {
        //printf("结果: %s, 表达式: %s\n", result, expression);
    } else {
        printf("行格式不正确: %s", line);
    }
    bool success = false;
    word_t except = 0;
    word_t actual = 0;
    
    sscanf(result,"%u",&except);
    actual = expr(expression,&success);
    if(except != actual){
      printf("WRONG !!! except: %u, actual: %u, expression: %s\n",except, actual, expression);
      wrong_ans++;
    }
    test_time++;
    //printf("except: %u, actual: %u, expression: %s\n",except, actual, expression);
    
  }
  
  fclose(file);
  printf("共完成%d次测试\n", test_time);
  if(wrong_ans != 0){
    printf("出现%d次错误\n", wrong_ans);
  }
  else{
    printf("测试全部通过\n");
  }
  return 0;
}

static int cmd_w(char* args){
  bool success = false;
  int value = expr(args,&success);
  if (success == false){
    printf("expr function false while creating wp\n");
  }
  else{
    WP* wp = new_wp();
    strcpy(wp -> expr, args);
    wp -> value = value;
    printf("create wp success, NO.%d, expr:%s, value: %u(DEC) 0x%08x(HEX)\n",wp->NO, wp->expr, wp->value, wp->value);
  }
  return 0;
}

static int cmd_d(char* args){
  int N;
  if (args == NULL){
    printf("arg is NULL\n");
  }
  else{
    sscanf(args,"%d",&N);
    delet_wp(N);
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
  { "si","Execute one time", cmd_si},
  { "info", "Show some info", cmd_info},
  { "x", "Scan ram", cmd_x},
  { "p", "Compute", cmd_p},
  { "test", "Test expr func", cmd_test_expr},
  { "w", "Set watchpoint", cmd_w},
  { "d", "Delete watchpoint", cmd_d},

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
