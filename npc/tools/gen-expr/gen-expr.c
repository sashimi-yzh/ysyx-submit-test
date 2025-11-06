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

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"unsigned main() { "
"  unsigned result = %s; "
"  printf(\"%%u\\n\", result); "
"  return 0; "
"}";

static int position = 0;
__uint32_t choose(int n){
  return rand() % n;
}
void gen_num(){
  __uint32_t num = choose(800);
  sprintf(buf + position, "%u", num);
  position += strlen(buf+position);
}

void gen_rand_op(){
    char *ops[] = {"+", "-", "*", "/"};
    char *op = ops[choose(4)];
    sprintf(buf + position, "%s", op);
    position += strlen(buf + position);
}

static void gen_rand_expr() {
  switch (choose(3)) {
    case 0: 
      gen_num();
      break;
    case 1: 
      sprintf(buf + position,"(");
      position++;
      gen_rand_expr();
      sprintf(buf + position,")");
      position++;
      break;
    default: 
      gen_rand_expr();
      gen_rand_op();
      gen_rand_expr();
      break;
  }
  buf[position] = '\0';
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
    // 每次的新的表达式都需要清空buf数组和将position置为0
    memset(buf,0,65536);
    position = 0;
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
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}
