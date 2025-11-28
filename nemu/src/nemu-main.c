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
#include "monitor/sdb/sdb.h"
#include <stdlib.h>
void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

void test_expr(int argc,char* argv[]){
  if (argc<2){
    printf("need inputfile\n");
    return ;
  }
  char buf[65536];
  FILE *f = fopen(argv[1],"rb+");
  Assert(f!=NULL,"open file %s failed\n",argv[1]);

  while(fgets(buf,65536,f)!=NULL){
    
     char *result = strtok(buf," ");
     int len = strlen(result);
     char *expression = buf+len+1;
     expression = strtok(expression,"\n");
     printf("result %s, expr %s\n",result,expression);
     int res = expr(expression,NULL);
     printf("result:%s, expr result: %d\n",result,res);
  }
  fclose(f);
  exit(0);
  return ;
}

int main(int argc, char *argv[]) {


  /* Initialize the monitor. */
  #ifdef CONFIG_TARGET_AM
  am_init_monitor();
  #else
    init_monitor(argc, argv);
  #endif

  // test expr in debug phase
  #ifdef CONFIG_TEST_EXPR
  test_expr(argc,argv);
  #endif

  /* Start engine. */
  engine_start();
  return is_exit_status_bad();
}

