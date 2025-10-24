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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
// #include "/home/furina/ysyx-workbench/nemu/include/generated/autoconf.h"
// #include <common.h>
// #include "/home/furina/ysyx-workbench/nemu/src/monitor/sdb/sdb.h"
// #include <sdb.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

#define MAX_DEPTH 6 // 定义最大递归深度以防止无限递归,防止溢出

static void gen(char const *c){
  strncat(buf,c,1);
}

static void gen_num(void){
  char num_str[50];
  int number=rand()%100;
  sprintf(num_str,"%d",number);
  strcat(buf,num_str);
}

static void gen_non_zero_num(void){
  char num_str[50];
  int number=rand()%100+1;
  sprintf(num_str, "%d", number);
  strcat(buf, num_str);
}

static void gen_rand_op(void){
  const char *ops[] = {"+","-","*","/"};
  int op_index = rand() % (sizeof(ops) / sizeof(ops[0]));
  gen(ops[op_index]);
  if(strcmp(ops[op_index], "/")==0){
    gen_non_zero_num(); //如果是除法，确保下一个数是非零
  }else{
    gen_num();
  }
}

static void gen_rand_expr(int depth){
  if(depth >= MAX_DEPTH){ // 达到最大深度时只生成操作数
    gen_num();
    return;
  }
  switch(rand()%3){
    case 0: 
      gen_num();
      break;
    case 1: 
      {
        size_t len=strlen(buf);
        if(len==0 || buf[len - 1]=='(' ||
            buf[len - 1]=='+' || buf[len - 1]=='-' ||
            buf[len - 1]=='*' || buf[len - 1]=='/'){
          if(rand()%2){
            gen("(");
            gen_rand_expr(depth+1);
            gen(")");
          }else{
            gen_rand_expr(depth+1); 
          }
        }else{//如果表达式出现右括号，则先生成运算符，再继续生成表达式
          gen_rand_op();
          gen_rand_expr(depth+1);
        }
      }
      break;
    default: 
      gen_rand_expr(depth+1);
      gen_rand_op();
      gen_rand_expr(depth+1);
      break;
  }
}


int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  //init_regex();//初始化正则表达式
  int i;
  for (i = 0; i < loop; i ++) {
    memset(buf,0,sizeof(buf));
    gen_rand_expr(0);

    sprintf(code_buf, code_format, buf);
    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    // fp=fopen("/home/furina/ysyx-workbench/nemu/expr-test","w");
    // assert(fp!=NULL);
    // fputs(buf,fp);
    // fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    uint32_t result;
    ret = fscanf(fp, "%u", &result);
    pclose(fp);
    // printf("my_expr:%u\n",expr(buf));
    printf("%u %s\n", result, buf);
  }
  return 0;
}
