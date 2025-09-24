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

#include <common.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

bool test_expr = false;

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);

  if (test_expr) {
    word_t expr(char *e, bool *success);
    char *nemu_home = getenv("NEMU_HOME");
    char cmd[256];
    sprintf(cmd, "make -f %s/tools/gen-expr/Makefile run LU=%d", nemu_home,
            MUXDEF(CONFIG_ISA64, 1, 0));
    int ret = system(cmd);
    Assert(ret == 0, "genearte expr failed");
    char buff[65536];
    FILE *fp = fopen("/tmp/expr_result.txt", "r");
    Assert(fp != NULL, "open /tmp/expr_result.txt failed");
    int i = 1;
    while (fgets(buff, 65536, fp)) {
      char *result = strtok(buff, " ");
      char *expr_str = result + strlen(result) + 1;
      word_t ans = strtoul(result, NULL, 10);
      bool success = true;
      word_t calc = expr(expr_str, &success);
      Assert(success, "eval the expr failed %s index: %d", expr_str, i);
      Assert(ans == calc, "ans:" FMT_WORD_D " calc:" FMT_WORD_D " index:%d",
             ans, calc, i);
      i++;
    }
    fclose(fp);
    test_expr = false;
  }
#endif

  /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}
