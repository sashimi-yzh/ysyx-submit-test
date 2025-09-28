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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#define MIN(a, b) ((a) > (b) ? (b) : (a))

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

static char *gen_num(char *buf, int len) {
  uint32_t val = rand();
  char str[12];
  sprintf(str, "%u", val);
  len = MIN(strlen(str), len);
  strncpy(buf, str, len);
  return buf + len;
}

static char *gen(char *buf, char c) {
  *buf = c;
  return buf + 1;
}

static char *gen_op(char *buf) {
  static const char ops[4] = {'+', '-', '*', '/'};
  return gen(buf, ops[rand() % 4]);
}

static char *gen_expr(char *buf, int len) {
  if (len <= 8) {
    buf = gen_num(buf, len - 1);
    return gen(buf, 'u');
  }
  switch (rand() % 6) {
    case 0:
      buf = gen_num(buf, len - 1);
      return gen(buf, 'u');
    case 1:
    case 2:
      buf = gen(buf, '(');
      buf = gen_expr(buf, len - 2);
      return gen(buf, ')');
    case 3:
    case 4:
    case 5:
      buf = gen_expr(buf, len / 2 - 1);
      buf = gen_op(buf);
      return gen_expr(buf, len / 2 - 1);
  }
  assert(0);
}

static void gen_rand_expr() {
  char *t = gen_expr(buf, 1024);
  *t = '\0';
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
    gen_rand_expr();

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    int status = pclose(fp);

    /* exit with err code -> divide 0 */
    if (WEXITSTATUS(status) == 0) {
      printf("%u %s\n", result, buf);
    }
  }
  printf("0 0\n");
  return 0;
}
