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

#include "monitor/sdb/sdb.h"
#include <common.h>
#include <stddef.h>
#include <stdio.h>
void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

int test() {
  int pass = 0, fail = 0;
  int ref;
  char *expr_buf = malloc(sizeof(char) * (1 << 10));
  while (scanf("%u %[^\n]", &ref, expr_buf) == 2) {
    bool success = true;
    word_t result = expr(expr_buf, &success);
    if (!success) {
      printf("Failed to evaluate expression: %s\n", expr_buf);
      fail++;
      continue;
    }
    if (result == ref) {
      pass++;
    } else {
      printf("Mismatch: expected %u, got %u | expr: %s\n", ref, result, expr_buf);
      fail++;
    }
  }
  free(expr_buf);
  printf("Passed: %d, Failed: %d\n", pass, fail);
  return 0;
}
int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
  // return test();
  /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}
