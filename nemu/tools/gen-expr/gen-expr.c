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
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";
int buf_index=0;
void gen_num(){
    uint32_t num=rand()%10;//10
    int length=0;
    switch(rand()%2){
    case 0:length=sprintf(buf+buf_index,"%uu",num);break;
    case 1:length=sprintf(buf+buf_index,"0x%xu",num);break;
    }
    buf_index+=length;     
}
void gen(char *c){
    int i;
    int length;
    for(i=0;i<rand()%3;i++)
        buf[buf_index++]=' ';
    length=sprintf(buf+buf_index,"%s",c);
    buf_index+=length;
    for(i=0;i<rand()%3;i++)
        buf[buf_index++]=' ';
}
void gen_rand_op(){
    switch(rand()%7){
        case 0:gen("+");break;
        case 1:gen("-");break;
        case 2:gen("*");break;
        case 3:gen("/");break;
        case 4:gen("==");break;
        case 5:gen("!=");break;
        case 6:gen("&&");break;
    }
}
static void gen_rand_expr() {
    if(buf_index>10000){
        gen_num();
        return ;
    }
    switch(rand()%3){
        case 0:gen_num();break;
        case 1:gen("("); gen_rand_expr(); gen(")"); break;
        default:gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
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
    buf_index=0;
    gen_rand_expr();
    buf[buf_index]='\0';
    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc -O0 -Werror=div-by-zero /tmp/.code.c -o /tmp/.expr 2>/dev/null");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    //assert(fp != NULL);
    if(fp!=NULL){
        unsigned  result;
        ret = fscanf(fp, "%u", &result);
        int ret2=pclose(fp);
        if(ret==1&&ret2==0)
            printf("%u %s\n", result, buf);
    }
  }
  return 0;
}
