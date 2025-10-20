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

// this should be enough
static char buf[65536] = {};
static int position;
static char code_buf[65536+128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

int choose(int n) {		//三选一
  return rand()%n;
}

void buf_add(char adder) {
  if(choose(10) == 1)		//10%概率获得一个空格在任意位置
    buf[position++] = ' ';
  buf[position++] = adder;
}

void gen_num() {		//生成数字
  unsigned int a = (unsigned int)rand();
  char num[12];
  sprintf(num, "%u", a);
  buf_add(num[0]);
}

void gen(char n) {		//生成括号
  buf_add(n);
}

void gen_rand_op() {		//生成运算符
  int i = choose(4);
  char pos[] = {'+', '-', '*', '/'};
  buf_add(pos[i]);
}

static void gen_rand_expr(int de) {
  if (de > 10) {
    gen_num();
    return;
  }
  switch (choose(3)) {
    case 0: gen_num(); break;
    case 1: gen('('); gen_rand_expr(de+1); gen(')'); break;
    default: gen_rand_expr(de+1); gen_rand_op(); gen_rand_expr(de+1); break;
  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    position = 0;
    gen_rand_expr(0);
    buf[position] = '\0';
    sprintf(code_buf, code_format, buf);
    
    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -g -o /tmp/.expr");
    if (ret != 0) continue;
    
    FILE *fp_out = popen("gcc -c -Wall /tmp/.code.c 2>&1", "r");
    assert(fp_out!= NULL);
    char output[1024] = {};
    while (fgets(output, sizeof(output), fp_out)!= NULL) {
        // 检查是否包含除零警告
        if (strstr(output, "division by zero")!= NULL) {
            position = 1;
            break;
        }
    }
    pclose(fp_out);
    
    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    
    if(strstr(output, "division by zero") == NULL) {
      printf("%u %s\n", result, buf);
    }
  }
    
  return 0;
}
