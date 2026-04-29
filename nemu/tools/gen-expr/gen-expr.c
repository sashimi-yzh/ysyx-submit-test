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
static char buf[65536+100] = {};
static char code_buf[65536+100 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

uint32_t choose(uint32_t x) {
  return rand() % x;
}

#define MAX_LEN 3000
char left[MAX_LEN], right[MAX_LEN];
char inner[MAX_LEN];
static size_t gen_rand_expr() {
  buf[0] = '\0';
	switch(choose(4)) {
		case 0: {
			int num = choose(1000);
			return snprintf(buf,MAX_LEN, "%du", num);
			break;
		}
		case 1: {
			char op = "+-*/"[choose(4)];
			size_t nleft = gen_rand_expr();
			strcpy(left, buf);
			size_t nright = gen_rand_expr();
			strcpy(right, buf);

			if(nleft + nright + 3 < MAX_LEN){
				return snprintf(buf, MAX_LEN, "(%s%c%s)", left, op, right);
			}
			if(nleft + 3 >= MAX_LEN){
				strcpy(buf, left);
			   	return nleft;
			}
			if(nright + 3 >= MAX_LEN) return nright;
			return snprintf(buf, MAX_LEN,"(%s%c1)", nleft>nright?left:right, op);
			break;
		}
		case 2: {
			size_t nin= gen_rand_expr();
			if(nin + 2 >= MAX_LEN) return nin;
			strcpy(inner, buf);
			return snprintf(buf,MAX_LEN, "(%s)", inner);
			break;
		}
		case 3: {
			uint32_t nspace = choose(3);
			size_t nin= gen_rand_expr();
			if(nin + 2*nspace >= MAX_LEN) return nin;
			strcpy(inner, buf);
			return snprintf(buf, MAX_LEN,"%*s%s%*s", nspace, " ", inner, nspace, " ");
			break;
		}
		default: assert(0);
	}  
	assert(0); // should never reach here
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

    printf("%u\n%s\n", result, buf);
  }
  return 0;
}
