/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
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
                           "  unsigned  result = %s; "
                           "  printf(\"%%u\", result); "
                           "  return 0; "
                           "}";

static int pos = 0;
static int is_lu = 0;

void gen_num() {
  uint32_t num = rand();
  int size = 0;
  char tmp[10];
  while (num > 0) {
    tmp[size++] = num % 10 + '0';
    num /= 10;
  }
  for (int i = size - 1; i >= 0; --i) {
    if (pos < 65536)
      buf[pos++] = tmp[i];
  }
  //保证表达式进行无符号运算
  if (is_lu && pos < 65536) {
    buf[pos++] = 'l';
  }
  if (pos < 65536)
    buf[pos++] = 'u';
}

void gen(char c) {
  if (pos < 65536)
    buf[pos++] = c;
}

void gen_rand_op() {
  if (pos < 65536) {
    int op = rand() % 4;
    switch (op) {
    case 0:
      buf[pos++] = '+';
      break;
    case 1:
      buf[pos++] = '-';
      break;
    case 2:
      buf[pos++] = '*';
      break;
    default:
      buf[pos++] = '/';
      break;
    }
  }
}

static void gen_rand_expr() {
  switch (rand() % 3) {
  case 0:
    gen_num();
    break;
  case 1:
    gen('(');
    gen_rand_expr();
    gen(')');
    break;
  default:
    gen_rand_expr();
    gen_rand_op();
    gen_rand_expr();
    break;
  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);

  sscanf(argv[1], "%d", &is_lu);
  if (is_lu) {
    code_format = "#include <stdio.h>\n"
                  "int main() { "
                  "  unsigned long result = %s; "
                  "  printf(\"%%lu\", result); "
                  "  return 0; "
                  "}";
  }

  int loop = 1;
  if (argc > 2) {
    sscanf(argv[2], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i++) {
    pos = 0;
    gen_rand_expr();
    if (pos < 65536) {
      buf[pos] = '\0';
    } else {
      //超出buf范围丢弃
      continue;
    }
    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret =
        system("gcc -O2 -Wall -Werror /tmp/.code.c -o /tmp/.expr 2>/dev/null");
    if (ret != 0)
      continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);
    if (is_lu) {
      uint64_t result;
      int success = fscanf(fp, "%lu", &result);
      pclose(fp);
      if (success == 1) {
        //将用于表示无符号的数字后缀u替换为空格
        for (int i = 0; buf[i] != '\0'; i++) {
          if (buf[i] == 'l') {
            buf[i++] = ' ';
            buf[i] = ' ';
          }
        }
        printf("%lu %s\n", result, buf);
      }
    } else {
      uint32_t result;
      int success = fscanf(fp, "%u", &result);
      pclose(fp);
      if (success == 1) {
        //将用于表示无符号的数字后缀u替换为空格
        for (int i = 0; buf[i] != '\0'; i++) {
          if (buf[i] == 'u') {
            buf[i] = ' ';
          }
        }
        printf("%u %s\n", result, buf);
      }
    }
  }
  return 0;
}
