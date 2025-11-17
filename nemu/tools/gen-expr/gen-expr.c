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

#define NUM_OP 12
// this should be enough
static char buf[65536] = {};
int buf_end = 0;
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

void gen_num(){
  buf_end += sprintf(buf+buf_end,"%u", rand()%1000);
  // if (buf_end >= 100){
  //   //  assert(0);
  //   return;
  // }
  return;
}

// not confirm num of '(' and ')' is valid
void gen(char c){
  buf_end+= sprintf(buf+buf_end,"%c",c);
  // if (buf_end >= 100){
  //   //  assert(0);
  //   return;
  // }
  return;
}

void gen_rand_op(){
    int n = rand()%NUM_OP;
    switch(n){
      case 0: gen('+');break;
      case 1: gen('-');break;
      case 2: gen('/');break;
      case 3: gen('*');break;
      case 4: gen('&');gen('&');break;
      case 5: gen('|');gen('|');break;
      case 6: gen('=');gen('=');break;
      case 7: gen('!');gen('=');break;
      case 8: gen('<');gen('=');break;
      case 9: gen('>');gen('=');break;
      case 10: gen('<');break;
      default : gen('>');break;
    }
    return;
}

void gen_rand_expr() {
  if (buf_end >= 1000){
    gen_num();
    return;
  }
  switch (rand()%4) {
    case 0:
      gen_num(); break;
    case 1: gen('('); gen_rand_expr(); gen(')'); break;
    case 2: gen(' ');gen_rand_expr();break;
    default: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
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
    gen_rand_expr();

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -Werror='div-by-zero' -o /tmp/.expr");
    if (ret != 0) {
      memset(buf,0,buf_end+1);
      buf_end=0;
      continue;
    };

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
    memset(buf,0,buf_end+1);
    buf_end=0;
  }
  return 0;

}
