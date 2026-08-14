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

#define MAX_DEPTH 20 // 表达式递归最大深度
#define MAX_CON_SPACE 3 // 最长连续空格 

char * space1 = " ";
char * space2 = "  ";
char * space3 = "   ";

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

void gen_space() {
  int ran_num = rand() % 4;
  switch (ran_num) {
    case 0: return ;
    case 1: snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "%s", space1); return ;
    case 2: snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "%s", space2); return ;
    case 3: snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "%s", space3); return ;
    default: return ;
  }
}

void gen_num() {
  gen_space();
  uint32_t ran_num = (uint32_t)rand();
  int sel_num = rand() % 2;
  if(sel_num == 1) snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "%uu", ran_num);
  else snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "0x%xu", ran_num);
}

void gen(char ch) {
  gen_space();
  snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "%c", ch);
}

void gen_rand_op(){
  gen_space();
  int ran_num = rand() % 7;
  switch (ran_num) {
    case 0: snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "%c", '+'); break;
    case 1: snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "%c", '-'); break;
    case 2: snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "%c", '*'); break;
    case 3: snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "%c", '/'); break;
    case 4: snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "%s", "=="); break;
    case 5: snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "%s", "!="); break;
    case 6: snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), "%s", "&&"); break;
    default: break;
  }
}

static void gen_rand_expr(int depth, int *overflag) {
  if(*overflag == 1) return ;
  if(sizeof(buf) - strlen(buf) < 50){
    *overflag = 1;
    return ;
  }

  if(depth == MAX_DEPTH) {
    gen_num();
    return ;
  }
  int ran_num = rand() % 3;
  
  switch (ran_num) {
    case 0: gen_num(); break;
    case 1: gen('('); gen_rand_expr(depth + 1, overflag); gen(')'); break;
    default: gen_rand_expr(depth + 1, overflag); gen_rand_op(); gen_rand_expr(depth + 1, overflag); break;
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
  int overflag = 0;
  for (i = 0; i < loop; i ++) {
    buf[0] = '\0';
    overflag = 0;
    gen_rand_expr(1, &overflag);
    if(overflag == 1) continue;
    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc -Werror /tmp/.code.c -o /tmp/.expr");
    // printf("ret: %d\n", ret);
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
