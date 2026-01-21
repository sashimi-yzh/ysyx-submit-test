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
#include "utils.h"
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

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args) {
  uint64_t num_inst;
  if(likely(!args)){
    num_inst = 1;
  }
  else{
    num_inst = (uint64_t)atoi(args);
  }
  cpu_exec(num_inst);
  return 0;
}

static int cmd_info(char *args) {
  if (!args) return 0;
  if (!strcmp(args, "r"))
  {
    isa_reg_display();
  }
  else if (!strcmp(args, "w"))
  {
    IFNDEF(CONFIG_WATCHPOINT, Log("你没有启动监视点的配置\n"));
    watchpoint_display();
  }
  
  return 0;
}

static int cmd_x(char *args){
  int num_word;
  char base_addr[1100] = {};
  sscanf(args, "%d %[^\n]", &num_word, base_addr);
  bool success = true;
  word_t result = 0;
  result = expr(base_addr, &success);
  if(!success) assert(0);
  printf("Address  Data\n");
  for (int i = 0; i < num_word; i++)
  {
    printf("%08x:0x%08x\n", result, vaddr_read(result, 4));
    result += 4;
  }
  return 0;
}

static int cmd_p(char *args){
  bool success = true;
  word_t result = 0;
  if(args) result = expr(args, &success);
  if(!success) assert(0);
  printf("有符号十进制数:%d\t无符号十进制:%u\t十六进制:%x\n",result, result, result);
  return 0;
}

static int cmd_w(char *args) {
  if (!args)
  {
    printf("请输入要监视的表达式\n");
    return 0;
  }
  IFNDEF(CONFIG_WATCHPOINT, Log("你没有启动监视点的配置\n"));
  add_watchpoint(args);
  return 0;
}

static int cmd_d(char *args) {
  if (!args)
  {
    printf("请输入要删除的监视点序号\n");
    return 0;
  }
  int number = 0;
  IFNDEF(CONFIG_WATCHPOINT, Log("你没有启动监视点的配置\n"));
  if(sscanf(args, "%d", &number) == 1)  delete_watchpoint(number);
  else  printf("你打的监视点序号表达式不对\n");
  return 0;
}

static int cmd_r(char *args) {
  printf("告诉你还没实现了\n");
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
  { "si", "格式为si [N],让程序单步执行N条指令后暂停执行,当N没有给出时,缺省为1", cmd_si},
  { "info", "格式为info SUBCMD, info r表示打印寄存器状态, info w表示打印监视点信息", cmd_info},
  { "x", "格式为x N EXPR, 表示以表达式EXPR为基地址, 以16进制的格式打印连续的N个4字节数据", cmd_x},
  { "p", "查看表达式的值, 格式为p EXPR, 将会打印表达式EXPR的十进制和十六进制表达", cmd_p},
  { "w", "设置监视点, 格式为w EXPR, 当EXPR的值发生改变时将会中断程序", cmd_w},
  { "d", "删除监视点, 格式为d N, 表示删除序号为N的监视点", cmd_d},
  { "r", "重新开始程序,还没实现", cmd_r},
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

  // FILE *fp = fopen("/home/yunhai/ysyx-workbench/nemu/tools/gen-expr/data.txt", "r");
  // if (fp == NULL) assert(0);
  // word_t theory_result;
  // char expression[1001]; // 假设表达式的长度不会超过 255
  // // 按照 "%u %s\n" 格式读取文件内容，直到文件结束
  // while (fscanf(fp, "%u %[^\n]", &theory_result, expression) != EOF) {
  //   printf("expression =%s\n",expression);
  //   bool success = true;
  //   int test_result = expr(expression, &success);  
  //   printf("test_result: %u, theory_result: %u\n\n", (word_t)test_result, theory_result);
  //   Assert((word_t)test_result == theory_result, "有问题");
  // }
  // fclose(fp);

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
        if (cmd_table[i].handler(args) < 0) return; 
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
