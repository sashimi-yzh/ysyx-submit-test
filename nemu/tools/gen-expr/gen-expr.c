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
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static int pos = 0;

static int choose(int n) {
  return rand() % n;
}

static void gen(char c) {
  buf[pos++] = c;
  buf[pos] = '\0';
}

static void gen_num() {
  // 加 u 后缀确保字面量为无符号类型，从而保证整个表达式在无符号域运算
  pos += sprintf(buf + pos, "%uu", (uint32_t)(rand() % 100 + 1));
}

static void gen_rand_spaces() {
  int n = choose(4); // 随机生成 0~3 个空格
  for (int i = 0; i < n; i++) gen(' ');
}

static void gen_rand_op() {
  char ops[] = "+-*/";
  gen_rand_spaces();
  gen(ops[choose(4)]);
  gen_rand_spaces();
}

static void gen_rand_expr(int depth) {
  // 限制递归深度并检查缓冲区剩余空间，防止 buf 溢出
  if (pos >= 65536 - 128 || depth >= 10) {
    gen_num();
    return;
  }
  switch (choose(3)) {
    case 0: gen_num(); break;
    case 1:
      gen('(');
      gen_rand_spaces();
      gen_rand_expr(depth + 1);
      gen_rand_spaces();
      gen(')');
      break;
    default:
      gen_rand_expr(depth + 1);
      gen_rand_op();
      gen_rand_expr(depth + 1);
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
  int i;
  for (i = 0; i < loop; i ++) {
    pos = 0;
    gen_rand_expr(0);

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    uint32_t result;
    ret = fscanf(fp, "%u", &result);
    int close_ret = pclose(fp);

    // 若子进程因除零（SIGFPE）崩溃，pclose 返回非零值；过滤此类表达式
    if (ret != 1 || close_ret != 0) continue;

    printf("%u %s\n", result, buf);
  }
  return 0;
}
