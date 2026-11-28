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
#include <sys/wait.h>   
#include <signal.h>     

// this should be enough
static char cbuf[65536] = {};
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";
size_t cnt1 = 0;
size_t cnt2 = 0;
uint32_t choose(uint32_t n){
  return rand() % n;
}
static void gen_space(){
  for(int i = 0;i<choose(3);i++){
    cbuf[cnt1++]=' ';
    buf[cnt2++]=' ';
  }
}
static void gen_num(){
  gen_space();
  uint32_t num = rand() % 1000;  
  char num_buf[32];
  int len = snprintf(num_buf, sizeof(num_buf), "%d", num);
  for (int i = 0; i < len; i++) {
    cbuf[cnt1++] = num_buf[i];
    buf[cnt2++] = num_buf[i];
  }
  cbuf[cnt1++] = 'U';
  gen_space();
}
static void gen(char c){
  gen_space();
  cbuf[cnt1++] = c;
  buf[cnt2++] = c;
  gen_space();
}

static void gen_rand_op(){
  gen_space();
  char c;
  switch (choose(4)){
    case 0: c = '+'; break;
    case 1: c = '-'; break;
    case 2: c = '*'; break;
    case 3: c = '/'; break;
  }
  cbuf[cnt1++] = c;
  buf[cnt2++] = c;
  gen_space();
}

static void gen_rand_expr(uint32_t depth) {
  if(depth == 1){
    gen_num();
  }
  else{
    switch (choose(6)) {
      case 0: gen_num(); break;
      case 1: gen('('); gen_rand_expr(depth-1); gen(')'); break;
      case 2: gen('('); gen_rand_expr(depth-1); gen(')'); break;
      case 3: gen_rand_expr(depth-1); gen_rand_op(); gen_rand_expr(depth-1); break;
      case 4: gen_rand_expr(depth-1); gen_rand_op(); gen_rand_expr(depth-1); break;
      case 5: gen_rand_expr(depth-1); gen_rand_op(); gen_rand_expr(depth-1); break;
      case 6: gen_rand_expr(depth-1); gen_rand_op(); gen_rand_expr(depth-1); break;
    }
  }
  cbuf[cnt1] = 0;
  buf[cnt2] = 0;
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }

  int generated = 0;  // 成功生成并输出的表达式计数
  while (generated < loop) {
    cnt1 = 0;
    cnt2 = 0;
    gen_rand_expr(5);

    sprintf(code_buf, code_format, cbuf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr 2>/dev/null");
    if (ret != 0) continue;  // 编译失败就跳过

    // 运行并捕获退出状态
    fp = popen("/tmp/.expr 2>/dev/null", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    int status = pclose(fp);  

    int is_sigfpe = 0;
    if (WIFEXITED(status)) {
        int exit_code = WEXITSTATUS(status);
        if (exit_code == 128 + SIGFPE) {
            is_sigfpe = 1;
        }
    } 
    else if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGFPE) {
            is_sigfpe = 1;
        }
    }
    if (is_sigfpe) {
        continue; 
    }


    printf("%u %s\n", (uint32_t)result, buf);
    generated++;

  }
  return 0;
}
