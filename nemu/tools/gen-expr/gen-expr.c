/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format = "#include <stdio.h>\n"
                           "int main() { "
                           "  unsigned result = %s; "
                           "  printf(\"%%u\", result); "
                           "  return 0; "
                           "}";

int pos = 0;
void gen_num() {
  char buffer[4];
  int counts = rand() % 1000;
  int i = 0;
  while (counts > 0) {
    buffer[i] = counts % 10 + '0';
    i++;
    counts = counts / 10;
  }
  for (; i > 0; i--) {
    buf[pos] = buffer[i - 1];
    pos++;
  }
}

void gen_op() {
  int choose = rand() % 4;
  switch (choose) {
  case 0:
    buf[pos] = '+';
    break;
  case 1:
    buf[pos] = '-';
    break;
  case 2:
    buf[pos] = '*';
    break;
  case 3:
    buf[pos] = '/';
    break;
  }
  pos++;
}

void gen(char c) {
  buf[pos] = c;
  pos++;
}

static void gen_rand_expr(int time) {
  if (time <= 0) {
    gen_num();
    return;
  }
  switch (rand() % 3) {
  case 0:
    gen_num();
    break;
  case 1:
    gen('(');
    gen_rand_expr(time - 1);
    gen('+');
    gen('1');
    gen(')');
    break;
  case 2:
    gen_rand_expr(time - 2);
    gen_op();
    gen_rand_expr(time - 2);
    break;
  default:
    assert(0);
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
  for (i = 0; i < loop; i++) {
    pos = 0;
    gen_rand_expr(4);
    buf[pos] = '\0';

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
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
