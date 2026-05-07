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

#define GEN_NUM_SIZE 10
#define GEN_EXPR_SIZE 5

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

static int pos=0;

int choose(int times) {
	return rand() % times;
}

void gen_num(int depth) {
	int num;
	depth++;
	num = rand() % 10;
	//num++;
	sprintf(&buf[pos],"%d",num);
	pos++;
	if(choose(2)==0 && num != 0) {
		if(depth < GEN_NUM_SIZE) gen_num(depth);

	}
	/*switch(choose(9)) {
		case 0: buf[pos]='1';break;
		case 1: buf[pos]='2';break;
		case 2: buf[pos]='3';break;
		case 3: buf[pos]='4';break;
		case 4: buf[pos]='5';break;
		case 5: buf[pos]='6';break;
		case 6: buf[pos]='7';break;
		case 7: buf[pos]='8';break;
		case 8: buf[pos]='9';break;
		default: assert(0);break;
	}
	pos++;*/
}

void gen(char signal) {
	buf[pos]=signal;
	pos++;
}

void gen_rand_op() {
	switch(choose(4)) {
		case 0: buf[pos]='+';
			break;
		case 1: buf[pos]='-';
                        break;
		case 2: buf[pos]='*';
                        break;
		case 3: buf[pos]='/';
                        break;
		default: assert(0);break;
	}
	pos++;
}

static void gen_rand_expr(int depth) {
  //buf[0] = '\0';
  if(depth < GEN_EXPR_SIZE) {
	  depth++;
    switch (choose(3)) {
      case 0: gen_num(0); break;
      case 1: gen('('); gen_rand_expr(depth); gen(')'); break;
      case 2: gen_rand_expr(depth); 
	      gen_rand_op(); 
	      gen_rand_expr(depth); 
	      break;
      //case 3: gen(' '); break;
      default: assert(0);break;
    }
    //buf[pos]= '\0';
  }
  else{
	  gen_num(0);
  }
  buf[pos]= '\0';
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
    pos=0;
    gen_rand_expr(0);
    
    sprintf(code_buf, code_format, buf); //将buf中的表达式以code_format格式输入到code_buf中

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc -Wall -Werror /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) {
      i = i-1;
      continue;//如果有错误，进入下一个循环
    }

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }

  return 0;
}
