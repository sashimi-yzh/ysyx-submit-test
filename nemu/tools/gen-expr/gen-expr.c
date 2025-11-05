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
#define BUF_SIZE 65536
static char buf[BUF_SIZE] = {};
static char code_buf[BUF_SIZE + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";


int cursor = 0;

static inline void gen_num(){
  char num_str[32];
  sprintf(num_str, "%u",(uint32_t)(rand()%100));
  if(cursor + strlen(num_str) < BUF_SIZE-1){
    sprintf(buf+cursor,"%s",num_str);
    cursor+=strlen(buf+cursor);
  }
}

static inline void gen(char c){
  if(cursor+1 < BUF_SIZE-1)
    buf[cursor++] = c;
}

//随机生成运算符，不会生成除法
static inline void gen_rand_op(){
  switch (rand()%3)
  {
    case 0: gen('+'); break;
    case 1: gen('-'); break;
    case 2: gen('*'); break;
    //case 3: gen('/'); break;
    default: break;
  }
}

static inline void gen_rand_space(){
  if(!(rand()%4)){
    if(cursor + 1 < BUF_SIZE-1)
      gen(' ');
  }
}

static void gen_rand_expr_rec() {
  
  if(cursor+1 >= BUF_SIZE){  
    cursor = 0;   //超出缓冲区范围，重新生成
    gen_rand_expr_rec();  
    return;
  }


  switch (rand()%3){
    case 0: 
      gen_num(); 
      gen_rand_space(); break;
    case 1: 
      gen('('); 
      gen_rand_space();
      gen_rand_expr_rec(); 
      gen_rand_space();
      gen(')'); 
      gen_rand_space(); break;
    case 2: 
      gen_rand_expr_rec(); 
      gen_rand_space();
      if (rand() % 4 == 0) { // 如果随机选择了除法
        char num_str[32];
        uint32_t num;
        do{
          num = (uint32_t)(rand()%100); 
        }while(num == 0);    // 确保除法后面生成的数非0
        gen_rand_space();
        gen('/');
        sprintf(num_str, "%u",num);
        if(cursor + strlen(num_str) < BUF_SIZE-1){
          sprintf(buf+cursor,"%s",num_str);
          cursor+=strlen(buf+cursor);
        }
        gen_rand_space();
      }
      else{
        gen_rand_op(); 
        gen_rand_expr_rec(); 
      }
      gen_rand_space();
      break;
    default: break;
  }

  
}


static void gen_rand_expr()
{
  cursor = 0;
  gen_rand_expr_rec();
  buf[cursor++] = '\0';
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
