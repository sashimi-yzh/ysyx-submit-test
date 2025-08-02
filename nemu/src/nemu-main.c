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
#include "monitor/sdb/sdb.h"

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

void test_expr(void) {
  char buf[TOKEN_LEN];
  FILE* input;
  input = fopen("/home/ysyx/Desktop/ysyx/ics2023/nemu/tools/gen-expr/input", "r");
  if (input == NULL) perror ("Error opening file");
  else {
    while(fgets(buf,TOKEN_LEN,input) != NULL)
    {
      bool success = false;
      char *result = strtok(buf, " ");
      char *expression = strtok(NULL, "\n");
      uint32_t result_exp = atoi(result);
      uint32_t result_cur = expr(expression, &success);

      if(success == true)
        assert(result_exp == result_cur);
      else
      {
        printf("success is false\n");
        assert(0);
      }
    }    
  }
  printf("Congradulation!!! It 's a real hard way!\nThe Expr testing is passed !!!\n");
}

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

  IFDEF(CONFIG_TEST_EXPR, test_expr()); 

  /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}
