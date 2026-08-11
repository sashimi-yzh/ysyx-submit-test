/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
***************************************************************************************/

#include <common.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

// expr() 在 sdb/expr.c 里实现
word_t expr(char *e, bool *success);

// from monitor.c
extern bool expr_test_mode;
extern char *expr_file;
extern char *res_file;
extern bool expr_test_verbose;
extern int  expr_test_print_n;
/*
static void run_expr_test_mode(const char *expr_path, const char *res_path) {
  FILE *fexpr = fopen(expr_path, "r");
  FILE *fres  = fopen(res_path, "r");

  Assert(fexpr, "Can not open expr file: %s", expr_path);
  Assert(fres,  "Can not open result file: %s", res_path);

  char expr_line[65536];
  char res_line[256];

  int total = 0, pass = 0, fail = 0;

  // 表头
  printf("------------------------------------------------\n");
  printf("| %-5s | %-6s | %-12s | %-12s |\n", "Case", "Status", "NEMU_OUTPUT", "GOLDEN_OUTPUT");
  printf("------------------------------------------------\n");

  while (1) {
    char *pe = fgets(expr_line, sizeof(expr_line), fexpr);
    char *pr = fgets(res_line, sizeof(res_line), fres);
    // 判断是否同时结束
    if (!pe || !pr) {
      Assert(pe == pr, "expr file and result file line count mismatch!");
      break;
    }
    // 删除结尾的换行符
    expr_line[strcspn(expr_line, "\n")] = '\0';
    res_line[strcspn(res_line, "\n")] = '\0';

    if (expr_line[0] == '\0') continue;

    uint32_t expect = 0;
    int ret = sscanf(res_line, "%u", &expect);
    Assert(ret == 1, "Bad result line: %s", res_line);

    bool success = true;
    uint32_t got = (uint32_t)expr(expr_line, &success);

    total++;

    bool ok = (success && got == expect);

    bool need_print = false;
    // 如果不是正确结果的情况下，默认必须打印
    if (!ok) need_print = true;
    // 全部观看模式
    if (expr_test_verbose) need_print = true;
    // 只打印前 N 条
    if (expr_test_print_n > 0 && total <= expr_test_print_n) need_print = true;
    // 预防表达是出现故障
    if (need_print) {
      if (!success) {
        printf("| %5d | %-6s | %12s | %12u |\n", total, "P_ERR", "N/A", expect);
      } else {
        printf("| %5d | %-6s | %12u | %12u |\n",
               total, ok ? "PASS" : "FAIL", got, expect);
      }
    }

    if (ok) pass++;
    else fail++;
  }

  fclose(fexpr);
  fclose(fres);

  printf("------------------------------------------------\n");

  printf("=====================================\n");
  printf("Expr Test Mode Finished\n");
  printf("PASS %d / %d\n", pass, total);
  printf("FAIL %d / %d\n", fail, total);
  printf("=====================================\n");
}
*/

int main(int argc, char *argv[]) {
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
/*
#ifndef CONFIG_TARGET_AM
  if (expr_test_mode) {
    run_expr_test_mode(expr_file, res_file); // ./src/utils/state.c
    return 0;
  }
#endif
*/
  engine_start();
  return is_exit_status_bad();
}
