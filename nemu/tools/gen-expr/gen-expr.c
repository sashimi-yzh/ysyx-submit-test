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

#define BUF_SIZE 65536

// this should be enough
static char buf[BUF_SIZE] = {};
static char code_buf[BUF_SIZE + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static int pos=0;

static uint32_t choose(uint32_t n) {
  return rand() % n;
}
static void gen(char c){
  if(pos <BUF_SIZE -1){
    buf[pos++]=c;
  }
}
static void gen_num() {
  pos += sprintf(buf + pos, "%uu", rand() % 100); 
}
static void gen_rand_op() {
  switch (choose(4)) {
    case 0: gen('+'); break;
    case 1: gen('-'); break;
    case 2: gen('*'); break;
    case 3: gen('/'); break;
  }
}

static void gen_rand_expr() {
  if(pos >= BUF_SIZE - BUF_SIZE/4){
    gen_num();
    return;
  }
  switch (choose(3)) {
    case 0: gen_num(); break;
    case 1: {
      gen('(');
      gen_rand_expr();
      gen(')');
      break;
    }
    default: {
      gen_rand_expr();
      gen_rand_op();
      gen_rand_expr();
    }
  }
}


void remove_u(char *str) {
    char *src = str; 
    char *dst = str; 
    while (*src) {
        if (*src != 'u') {
            *dst = *src;
            dst++;
        }
        src++;
    }
    *dst = '\0'; 
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
    buf[0] = '\0';
    gen_rand_expr();
    buf[pos] = '\0';

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
    int status=pclose(fp);
    if (ret != 1 || status != 0) continue;

    remove_u(buf);

    printf("%u %s\n", result, buf);
  }
  return 0;
}
