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
#include <sys/wait.h>  // for WIFEXITED, WEXITSTATUS

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

// 递归深度控制
static int recursion_depth = 0;
static const int MAX_DEPTH = 10;  // 最大递归深度

// 生成一个小于n的随机数
static uint32_t choose(uint32_t n) {
  return rand() % n;
}

// 生成单个字符
static void gen(char c) {
  int len = strlen(buf);
  if (len < 65535) {
    buf[len] = c;
    buf[len + 1] = '\0';
  }
}

// 生成随机数字
static void gen_num() {
  // 生成1-999的随机数（避免0，防止除零）
  uint32_t num = choose(999) + 1;
  char num_str[16];
  sprintf(num_str, "%u", num);
  
  // 确保不会溢出
  if (strlen(buf) + strlen(num_str) < 65535) {
    strcat(buf, num_str);
  }
}

// 生成随机运算符
static void gen_rand_op() {
  switch (choose(4)) {
    case 0: gen('+'); break;
    case 1: gen('-'); break;
    case 2: gen('*'); break;
    case 3: gen('/'); break;
  }
}

// 随机插入空格
static void gen_space() {
  // 50%的概率插入0-3个空格
  if (choose(2) == 0) {
    int spaces = choose(4);
    for (int i = 0; i < spaces; i++) {
      gen(' ');
    }
  }
}

// 递归生成随机表达式
static void gen_rand_expr() {
  // 方法1: 使用递归深度控制
  // 当递归深度过大时，只生成数字
  if (recursion_depth > MAX_DEPTH) {
    gen_num();
    return;
  }
  
  // 方法2: 使用buf长度控制
  // 当buf长度超过一定值时，只生成数字
  if (strlen(buf) > 4000) {  // 设置一个安全的阈值
    gen_num();
    return;
  }
  
  // 增加递归深度
  recursion_depth++;
  
  // 根据递归深度调整生成概率
  // 深度越大，越倾向于生成数字（终止递归）
  int num_prob = 33 + recursion_depth * 5;  // 深度越大，数字概率越高
  if (num_prob > 80) num_prob = 80;  // 最多80%概率生成数字
  
  int rand_val = choose(100);
  
  if (rand_val < num_prob) {
    // 生成数字
    gen_num(); 
  } else if (rand_val < num_prob + 10) {
    // 生成括号表达式（10%概率）
    gen('(');
    gen_space();
    gen_rand_expr();
    gen_space();
    gen(')');
  } else {
    // 生成二元运算表达式
    gen_rand_expr();
    gen_space();
    gen_rand_op();
    gen_space();
    gen_rand_expr();
  }
  
  // 减少递归深度
  recursion_depth--;
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
    // 初始化buf和递归深度
    buf[0] = '\0';
    recursion_depth = 0;
    
    gen_rand_expr();

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    // 编译表达式
    // 如果编译失败，说明表达式有语法错误，跳过
    int ret = system("gcc /tmp/.code.c -o /tmp/.expr 2>/dev/null");
    if (ret != 0) continue;

    // 执行表达式，获取结果
    // 如果执行失败（除零、浮点异常等），popen会返回错误
    fp = popen("/tmp/.expr 2>/dev/null", "r");
    if (fp == NULL) continue;

    unsigned result;
    ret = fscanf(fp, "%u", &result);
    int status = pclose(fp);

    // 检查执行状态
    // WIFEXITED: 正常退出
    // WEXITSTATUS: 退出状态码
    // 如果程序异常退出（如除零导致SIGFPE），跳过
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
      continue;
    }

    // 如果读取失败，跳过
    if (ret != 1) continue;

    printf("%u %s\n", result, buf);
  }
  return 0;
}
