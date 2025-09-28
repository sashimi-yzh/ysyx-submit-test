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

#include <common.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

  /* test expr
  #include "monitor/sdb/sdb.h"
  static char buf[65536] = {};
  unsigned val, res;
  bool success;
  int wrong_cnt = 0;
  while (~scanf("%u %s", &val, buf)) {
    res = expr(buf, &success);
    if (!success || res != val) {
      printf("std:%u res:%u\n", val, res);
      printf("expr: %s\n", buf);
      ++wrong_cnt;
    }
  }
  printf("wrong count: %d\n", wrong_cnt);
  return 0; */

  /* Start engine. */
  engine_start();

#ifdef CONFIG_PCTRACE
  void finalize_pctrace();
  finalize_pctrace();
#endif
#ifdef CONFIG_LSTRACE
  void finalize_lstrace();
  finalize_lstrace();
#endif
#ifdef CONFIG_BRTRACE
  void finalize_brtrace();
  finalize_brtrace();
#endif

  return is_exit_status_bad();
}
