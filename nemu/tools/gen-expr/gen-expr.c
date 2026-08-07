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

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static char buf[65536] = {};
static char code_buf[65536 + 128] = {};
static char *code_format =
    "#include <stdio.h>\n"
    "int main() { "
    "  unsigned result = %s; "
    "  printf(\"%%u\", result); "
    "  return 0; "
    "}";
static int idx = 0;

void gen_num() {
  int val = rand() % 1000;
  idx += sprintf(buf + idx, "%d", val);
}

void gen_rand_op() {
  const char ops[] = "+-*/";
  buf[idx++] = ops[rand() % 4];
}

void gen_rand_expr_internal(int depth) {
  if (depth > 10) {
    gen_num();
    return;
  }

  int type = rand() % 3;
  if (type == 0) {
    gen_num();
  } else if (type == 1) {
    buf[idx++] = '(';
    gen_rand_expr_internal(depth + 1);
    buf[idx++] = ')';
  } else {
    gen_rand_expr_internal(depth + 1);
    gen_rand_op();
    gen_rand_expr_internal(depth + 1);
  }
}

static void gen_rand_expr() {
  idx = 0;
  memset(buf, 0, sizeof(buf));
  gen_rand_expr_internal(0);
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i++) {
    gen_rand_expr();

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc -Werror /tmp/.code.c -o /tmp/.expr");
    if (ret != 0)
      continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}
