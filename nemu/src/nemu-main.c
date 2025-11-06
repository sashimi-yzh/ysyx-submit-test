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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./monitor/sdb/sdb.h"

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

  /* Start engine. */
  engine_start();


  /**
   * 测试表达式求值
   */
  // FILE *file = fopen("/home/lq/ysyx-workbench/nemu/tools/gen-expr/input", "r");
  // if (!file) {
  //   panic("Failed to open file");
  //   return 1;
  // }

  // char line[65536];
  // int flag = 0;
  // while (fgets(line, sizeof(line), file)) {
  //   // 去掉换行符
  //   line[strcspn(line, "\n")] = 0;

  //   // 分割字符串并处理表达式
  //   char *result = strtok(line, " ");
  //   char *e = strtok(line,"\0");
  //   bool success;
  //   uint32_t eval_result = expr(e,&success);
  //   unsigned int re;
  //   sscanf(result, "%u", &re);
  //   if(re != eval_result){
  //     fclose(file);
  //     panic("Cal Error");
  //     flag = 1;
  //   }
  // }
  // if(flag == 0){
  //   printf("success\n");
  // }
  // fclose(file);

  /**
   * main返回值的情况：
   *    返回 0 表示程序已成功执行且没有遇到任何严重错误。
   *    返回非零值（即正整数或负整数）表示程序在执行过程中遇到了某种错误或异常情况。
   */
  return is_exit_status_bad();
}
