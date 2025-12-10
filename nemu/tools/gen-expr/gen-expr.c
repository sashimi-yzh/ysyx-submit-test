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
#include <stdbool.h>
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

int position;

uint32_t choose(uint32_t max_value) {
  return (uint32_t)rand()%max_value;
}


void gen_num(bool exsit_zero) {
  if(exsit_zero)
    buf[position++] = '0' + rand()%10;
  else
    buf[position++] = '1' + rand()%9;
}

void gen_str()
{
  char *fuhao = "(unsigned)";
  sprintf(buf+position, "%s", fuhao);
  position = position + 10;
}

void gen(char value) {
  buf[position++] = value;
}

void gen_rand_op() {
  switch (choose(4))
  {
    case 0: buf[position++] = '+';break;
    case 1: buf[position++] = '-';break;
    case 2: buf[position++] = '*';break;
    case 3: buf[position++] = '/';break;
  }
}
static void gen_rand_expr() {
  if(position >= 1000) {
    gen_num(true);
    return;
  }
  if(choose(5) == 0) gen(' ');
  switch (choose(3)) {
    case 0: gen_num(true); break;
    case 1: gen('('); gen_rand_expr(); gen(')'); break;
    default: gen_rand_expr(); gen_rand_op(); 
            if(buf[position - 1] == '/') 
              gen_num(false);
            else if(buf[position - 1] == '-') {
                gen_str();
                gen_rand_expr();
              }
            else {
                gen_rand_expr();
            }
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
    position = 0;
    gen_rand_expr();
    buf[position] = '\0';

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
    pclose(fp);

    fp = fopen("data.txt", "a");
    assert(fp != NULL);
    fprintf(fp, "%u %s\n", result, buf);
    fclose(fp);
    // printf("%u %s\n", result, buf);
  }
  return 0;
}
