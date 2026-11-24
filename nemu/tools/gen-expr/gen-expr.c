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

#define MAX_DEP 6

// this should be enough
static char buf[65536] = {};
static char buf_unsi[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static void gen_num() {
    unsigned int num = rand() % 100;
    char buffer[32];
    char buffer_unsi[64];

    sprintf(buffer, "%d", num);
    strcat(buf, buffer);

    sprintf(buffer_unsi, "(unsigned int)%d", num);
    strcat(buf_unsi, buffer_unsi);
}

static void gen(char c) {
    int len = strlen(buf);
    buf[len] = c;
    buf[len + 1] = '\0';

    int len_unsi = strlen(buf_unsi);
    buf_unsi[len_unsi] = c;
    buf_unsi[len_unsi + 1] = '\0';
}

static void gen_rand_op() {
    char ops[] = {'+', '-', '*', '/'};
    char op = ops[rand() % 4];
    gen(op);
}

static int choose(int n) {
    return rand() % n;
}

static void gen_rand_expr(int dep) {
  if (dep > MAX_DEP) {
    gen_num();
    return;
  }

  switch (choose(3)) {
    case 0:
      gen_num(); break;
    case 1:
      gen('('); gen_rand_expr(dep + 1); gen(')'); break;
    default:
      gen_rand_expr(dep + 1);
      gen_rand_op(); 
      gen_rand_expr(dep + 1); 
      break;
  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  int status = 0;

  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }

  int i;
  for (i = 0; i < loop; i ++) {
    buf[0] = '\0';
    buf_unsi[0] = '\0';
    gen_rand_expr(0);

    sprintf(code_buf, code_format, buf_unsi);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc -Werror /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) {
	  loop++;
      continue;
    }
    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    status = pclose(fp);
    if (status != 0) {
	    loop++;
	    continue;
    }

    printf("%u %s\n", result, buf);
  }
  return 0;
}
