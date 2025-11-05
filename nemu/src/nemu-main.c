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

//#define TEST_EXPR   //测试expr（表达式求值）使用

#ifdef TEST_EXPR
#include <../src/monitor/sdb/sdb.h>
#endif // TEST_EXPR


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

  /* 如果测试表达式求值的话 */
#ifdef TEST_EXPR
  char line[65535];
  char *arg;
  uint32_t result, output;
  bool succ = true;
  FILE *fp = fopen("tools/gen-expr/build/input", "r");
  assert(fp != NULL);
  int i=1;
  while(fgets(line, 65535,fp) != NULL)
  {
    if(line[strlen(line)-1] == '\n')
       line[strlen(line)-1] = '\0'; //删除换行

    //puts(line);
    arg = strtok(line, " ");
    //puts(arg);
    result = atoi(arg);
    arg = strtok(NULL, "");
    //puts(arg);
    output = expr(arg,&succ);
    
    printf("%d > Result: %u, output: %u\n",i++, result, output);
    //assert(result == output);
    
    
  }
  
  exit(0);
#else
   /* Start engine. */
  engine_start();
#endif // TEST_EXPR
  

  return is_exit_status_bad();
}
