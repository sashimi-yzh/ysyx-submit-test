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

// this should be enough
int buf_index=0,unsignedbuf_index=0;
static char buf[32768] = {'\0'};
static char unsignedbuf[65536] = {'\0'};
static char code_buf[65536 + 1280] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"#include <stdlib.h>\n"
"#include <signal.h>\n"
"#include <setjmp.h>\n"
"static jmp_buf env;\n"
"void handle_div_zero(int sig) {\n"
"    longjmp(env, 1);\n"
"}\n"
"__attribute__((constructor)) void init() {\n"
"    signal(SIGFPE, handle_div_zero);\n"
"}\n"
"int main() {\n"
"    if (setjmp(env) == 0) {\n"
"        unsigned result = %s;\n"
"        printf(\"%%u\", result);\n"
"    } else {\n"
"        printf(\"xxxxxxxxxx\");\n"
"    }\n"
"    return 0;\n"
"}";

uint32_t choose(uint32_t n){
  return rand()%n;
}
void gen_num(){
  int n=choose(7);
  for(int i=0;i<=n;i++){
    int k;
    if(i==0)
      k=1+choose(9);
    else
      k=choose(10);
    buf[buf_index]=(char)(k+'0');
    buf_index++;
  }
}
void gen(char c){
  buf[buf_index]=c;
  buf_index++;
}
void gen_rand_op(){
  switch (choose(4))
  {
  case 0:buf[buf_index]='+';break;
  case 1:buf[buf_index]='-';break;
  case 2:buf[buf_index]='*';break;
  default:buf[buf_index]='/';break;
  }
  buf_index++;
}

static void gen_rand_expr(int depth){
  if(depth>100){
    gen_num();
  }else{
    if(choose(2)) gen(' ');
    switch (choose(3)) {
      case 0: gen_num(); break;
      case 1: gen('('); gen_rand_expr(depth+1); gen(')'); break;
      default: gen_rand_expr(depth+1); gen_rand_op(depth+1); gen_rand_expr(depth+1); break;
    }
  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  
  for (int i = 0; i < loop; i ++) {
    memset(buf, 0, sizeof(buf));
    memset(unsignedbuf, 0, sizeof(unsignedbuf));
    buf_index=0,unsignedbuf_index=0;
    gen_rand_expr(0);
    for(int i=0;i<buf_index;i++){
      if(!(buf[i]>='0'&&buf[i]<='9')&&(buf[i+1]>='0'&&buf[i+1]<='9')){
        unsignedbuf[unsignedbuf_index]=buf[i];
        memcpy(unsignedbuf+unsignedbuf_index+1,"(unsigned)",10);
        unsignedbuf_index+=11;
      }else{
        unsignedbuf[unsignedbuf_index++]=buf[i];
      }
    }
    sprintf(code_buf, code_format, unsignedbuf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);
    int ret=system("rm -f /tmp/.expr");
    ret = system("gcc -Werror /tmp/.code.c -o /tmp/.expr");
    if (ret != 0){
      i--;
      continue;
    }

    fp = popen("/tmp/.expr", "r");
    if(fp == NULL){
      i--;
      fprintf(stderr,"No file(/0)\n");
      continue;
    }
    int result;
    ret = fscanf(fp, "%d", &result);
    fprintf(stderr,"%d=",ret);
    if(ret<=0){
      fprintf(stderr,"XXXXX\n");
      i--;
      pclose(fp);
      continue;
    }else{
      printf("%u %s\n", result, buf);
    }   
    pclose(fp);
  }

  return 0;
}
//(0)  -  (5/((2-5)-(7)/(5)/(6)))