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
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_si(char *args) {
  int n = 1;
  
  if (args != NULL) {
    // 解析参数N
    sscanf(args, "%d", &n);
  }
  cpu_exec(n);
  
  return 0;
}

static int cmd_info(char *args) {
  if (args == NULL) {
    printf("Usage: info r - print register info\n");
    printf("       info w - print watchpoint info\n");
    return 0;
  }
  
  if (strcmp(args, "r") == 0) {
    isa_reg_display();
  } 
  else if (strcmp(args, "w") == 0) {
    display_watchpoints();
  }
  else {
    printf("Unknown subcommand: %s\n", args);
  }
  
  return 0;
}

static int cmd_x(char *args) {
  if (args == NULL) {
    printf("Usage: x N EXPR\n");
    return 0;
  }
  
  int n;
  char exp[256];
  
  // 解析参数: N和表达式
  if (sscanf(args, "%d %s", &n, exp) != 2) {
    printf("Invalid format. Usage: x N EXPR\n");
    return 0;
  }
  
  // 简化版本：EXPR是十六进制地址
  //paddr_t addr;
  //sscanf(expr, "%x", &addr);

  bool success;
  paddr_t addr = expr(exp, &success);
  
  if (!success) {
    printf("Invalid address expression: %s\n", exp);
    return 0;
  }
  
  // 打印内存内容
  for (int i = 0; i < n; i++) {
    if (i % 4 == 0) {
      printf("0x%08x: ", addr + i * 4);
    }
    
    // 读取内存
    word_t data = paddr_read(addr + i * 4, 4);
    printf("0x%08x  ", data);
    
    if (i % 4 == 3) printf("\n");
  }
  
  if (n % 4 != 0) printf("\n");
  
  return 0;
}

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

static int cmd_test_expr(char *args) {
  if (args == NULL) {
    printf("Usage: test-expr <filename>\n");
    printf("Example: test-expr /tmp/expr_test.txt\n");
    return 0;
  }
  
  FILE *fp = fopen(args, "r");
  if (fp == NULL) {
    printf("Cannot open file: %s\n", args);
    return 0;
  }
  
  int total = 0;
  int passed = 0;
  int failed = 0;
  
  char line[65536];
  while (fgets(line, sizeof(line), fp) != NULL) {
    // 移除换行符
    line[strcspn(line, "\n")] = 0;
    
    // 跳过空行
    if (strlen(line) == 0) continue;
    
    // 解析：期望结果 表达式
    char *space = strchr(line, ' ');
    if (space == NULL) continue;
    
    *space = '\0';
    unsigned int expected = atoi(line);
    char *expr_str = space + 1;
    
    total++;
    
    // 调用expr()求值
    bool success = false;
    word_t result = expr(expr_str, &success);
    
    if (!success) {
      failed++;
      printf("Test %d: FAIL (parse error)\n", total);
      printf("  Expression: %s\n", expr_str);
      continue;
    }
    
    // 比较结果
    if (result == expected) {
      passed++;
      printf("Test %d: PASS\n", total);
    } else {
      failed++;
      printf("Test %d: FAIL\n", total);
      printf("  Expression: %s\n", expr_str);
      printf("  Expected: %u (0x%x)\n", expected, expected);
      printf("  Got: %u (0x%x)\n", result, result);
    }
  }
  
  fclose(fp);
  
  printf("\n========================================\n");
  printf("Test Summary:\n");
  printf("  Total: %d\n", total);
  printf("  Passed: %d\n", passed);
  printf("  Failed: %d\n", failed);
  if (total > 0) {
    printf("  Pass Rate: %.2f%%\n", (double)passed / total * 100);
  }
  printf("========================================\n");
  
  return 0;
}

static int cmd_w(char *args) {
  if (args == NULL) {
    printf("Usage: w EXPR\n");
    return 0;
  }
  
  create_watchpoint(args);
  
  return 0;
}

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

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Step [N] instructions", cmd_si },
  { "info", "Print registers or watchpoint info", cmd_info },
  { "x", "Examine memory: x N EXPR", cmd_x },
  { "p", "Evaluate expression: p EXPR", cmd_p },
  { "w", "Set watchpoint: w EXPR", cmd_w },           
  { "d", "Delete watchpoint: d N", cmd_d },   
  { "test-expr", "Test expression evaluation: test-expr <file>", cmd_test_expr },

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
