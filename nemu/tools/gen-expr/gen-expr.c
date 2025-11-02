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
#include "expr.c"


// this should be enough
// parallel buf,to ensure the unsigned calculation in .code.c
static char buf1[65536] = {};//buf1 is for .code.c
static char buf2[65536] = {};//buf2 is for expr()
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static int len1 = 0;
static int len2 = 0;


static void gen(char c){
	buf1[len1++] = c;
	buf2[len2++] = c;
}

static void gen_num(){
	char tmp = rand()%10 + '0';
	buf1[len1++] = tmp;
	buf1[len1++] = 'u';
	buf2[len2++] = tmp;
}


static void gen_rand_op(){
	switch(rand()%4){
		case 0: buf1[len1++] = '+';buf2[len2++] = '+'; break;
		case 1: buf1[len1++] = '-';buf2[len2++] = '-'; break;
		case 2: buf1[len1++] = '*';buf2[len2++] = '*'; break;
		default: buf1[len1++] = '/';buf2[len2++] = '/'; break;
	}
}


static void gen_rand_expr() {
  if(len2 >= 31)
	return;
  switch (rand()%5) {
	case 0:case 1: gen_num(); break;
    case 2: gen('('); gen_rand_expr(); gen(')'); break;
    default: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
  }
}





int main(int argc, char *argv[]) {
  
  init_regex();//this is a must
	
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  int num_test = 0;
  for (i = 0; i < loop; i ++) {
	len1 = 0; len2 = 0;
    

   	gen_rand_expr();
	buf1[len1] = '\0'; buf2[len2] = '\0';
	
	//the length of expression won't be too long
    if(len2 >= 31){
		//printf("expression too long!\n\n");
		continue;
	}

    sprintf(code_buf, code_format, buf1);

    FILE *fp = fopen("./tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

	
	//rule out the circumstance where 0 is divided
	//with the option -Werror, ret != 0 when 0 is divided
    int ret = system("gcc ./tmp/.code.c -o ./tmp/.expr -Werror");
    if (ret != 0) continue;

    fp = popen("./tmp/.expr", "r");
    assert(fp != NULL);

    int result1;
    ret = fscanf(fp, "%d", &result1);
    pclose(fp);

	//printf("expression: %s\n",buf1);
	printf("expression: %s\n",buf2);
	printf("result 1: %u\n",result1);

	
	int result2;
	bool success,null;
	result2 = expr(buf2,&success,&null);

    printf("result 2: %u\n",result2);

	if(result1 == result2){
		num_test++;
		printf("test no. %d passed\n\n", num_test);
	}
	else{
		num_test++;
		printf("test no. %d failed... Abort\n\n", num_test);
		assert(0);
	}
	//result == result_test ? printf("test pass\n\n") : assert(0);
	
  }
  return 0;
}
