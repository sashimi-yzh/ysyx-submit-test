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

#include "debug.h"
#include <common.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

word_t expr(char *, bool *);
void test_expr(void) {
  bool success = true;
  FILE *f = fopen("tools/gen-expr/test.txt", "r");
  Assert(f, "file can't open");
  char buf[65537];
  int i = 1;
  while (fgets(buf, 65537, f)) {
    printf("%d start", i);
    buf[strlen(buf) - 1] = '\0';
    char *save_ptr = NULL;
    strtok_r(buf, " ", &save_ptr);
    uint32_t result = atoi(buf);
    char *ex = buf + strlen(buf) + 1;
    uint32_t ret = expr(ex, &success);
	Assert(success, "success is false");
	Assert(result == ret, "expr is wrong: file: %u  expr: %u", result, ret);
	Log("ok");
	i++;
  }	
  Log("PASS");
}

IFDEF(CONFIG_NPC, void sim_close(void));

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

  // test_expr();

  /* Start engine. */
  engine_start();

  IFDEF(CONFIG_NPC, sim_close());

  return is_exit_status_bad();
}
