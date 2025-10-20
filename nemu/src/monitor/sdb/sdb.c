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
#include "memory/vaddr.h"

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

static int cmd_d(char *args) {			//删除监视点
  int NO;
  sscanf(args, "%d", &NO);
  free_wp(NO);
  return 0;
}

bool success1 = true;

static int cmd_w(char *args) {			//添加监视点
  size_t len = strlen(args);
  char *e = (char *)malloc(len+1); 
    if (e == NULL) {
      perror("malloc failed");
      return 1;
    }
  strcpy(e, args);
  //printf("success1:%d\n", success1);
  new_wp(e, &success1);
  //printf("success1:%d\n", success1);
  free(e);
  return 0;
}

static int cmd_ext(char *args) {
  FILE *file = fopen("/home/tanghongwei/ysyx-workbench/nemu/tools/gen-expr/build/input", "r");
  if(file == NULL) {
    perror("Error opening file");
    return -1;
  }
  int goalresult;
  char e[2048];
  char line[2058];
  int pass = 0, all = 0;
  while (fgets(line, 2058, file)!= NULL) {
    char *token = strtok(line, " ");
    if (token!= NULL) {
      goalresult = atoi(token);
      token = strtok(NULL, "\n");
      if (token!= NULL) {
        strcpy(e, token);
        bool s = true;
        int result = expr(e, &s);
        all++;
        if(result == goalresult)
          pass++;
      }
      else
        printf("Invalid line format: %s", line);
    }
    else
      printf("Invalid line format: %s", line);
  }
  printf("pass:%d all:%d\n",pass,all);
  fclose(file);
  return 0;
}

static int cmd_p(char *args) {			//表达式求值
  size_t len = strlen(args);
  char *e = (char *)malloc(len+1); 
    if (e == NULL) {
      perror("malloc failed");
      return 1;
    }
  bool success = true;
  int result;
  strcpy(e, args);
  //printf("%s\n", e);
  result = expr(e, &success);
  if (success){
    printf("%d\n", result);			//两种输出进制
    //printf("0x%08x\n", result);
  }
  else
    printf("Bad expression\n");
  free(e);
  return 0;
}

static int cmd_x(char *args) {			//扫描内存
  size_t len = strlen(args);
  char *e = (char *)malloc(len+1); 
    if (e == NULL) {
      perror("malloc failed");
      return 1;
    }
  bool success = true;
  int result;
  char *arg1 = strtok(NULL, " ");
  int k;	
  sscanf(arg1, "%d", &k);
  strcpy(e, args+2);
  result = expr(e, &success);			//添加表达式求值功能
  vaddr_t data = result;			//使用 vaddr中对传入参数的定义
  for (int i = 0; i < k; i++){
    printf("0x%08x\t", data+4*i);
    uint32_t temp = vaddr_read(data+i*4,4);
    for(int j = 0; j < 4; j++){
      printf("0x%02x ", temp >> (8*(3-j)) & 0xff);
    }
    printf("\n");
  }
  free(e);
  return 0;
}

static int cmd_info(char *args) {		//打印寄存器，监视点
  if (args[0] == 'r')
    isa_reg_display();
  else if (args[0] == 'w')
    watchpoint_printf();
  else
    printf("输入有误，需要帮助可以键入‘help’");
  return 0;
}

static int cmd_si(char *args) {			//单步执行
  int step;
  if (args == NULL)
    step = 1;
  else
    sscanf(args, "%d", &step);
  if (step < 10)
    cpu_exec(step);
  else
    printf("每次单步执行最大步数不超过10");
  return 0;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "显示有关所有支持的命令的信息。", cmd_help },
  { "c", "继续执行程序", cmd_c },
  { "q", "退出 NEMU", cmd_q },
  { "si", "让程序单步执行[N]条指令后暂停执行,N缺省为1",cmd_si },
  { "info", "打印寄存器状态[r]打印监视点信息[w]", cmd_info },
  { "x", "求出表达式EXPR的值, 将结果作为起始内存地址, 以十六进制形式输出连续的N个4字节", cmd_x },
  { "p", "求出表达式EXPR的值", cmd_p },
  { "w", "当表达式EXPR的值发生变化时, 暂停程序执行", cmd_w },
  { "d", "删除序号为[N]的监视点", cmd_d },
  { "ext", "测试expr的功能", cmd_ext}
  /*
  */
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
