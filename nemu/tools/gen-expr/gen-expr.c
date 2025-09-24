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
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static uint32_t choose(uint32_t n) {
	uint32_t x = rand() % n;
	return x;
}

static void gen_num(uint32_t *n) {
	uint32_t num  = choose(4294967295);
	sprintf(buf+*n, "%u", num);

	int len = 1;
	while (num >= 10) {
		num /= 10;
		len++;
	}
	
	*n += len;
	buf[(*n)++] = 'u';

}

static void gen_rand_op(int n) {
	switch (choose(4)) {
		case 0: buf[n] = '+'; break;
		case 1: buf[n] = '-'; break;
		case 2: buf[n] = '*'; break;
		case 3: buf[n] = '/'; break;
	}
}

static void gen_rand_expr(uint32_t *n, int *of) {
	//prevent overflow
	if (*n >= 4095) {
		//printf("buffer overflowed.");
		*of = 1;
		return;
	}

	//random space
	if (choose(2)) {
		buf[(*n)++] = ' ';
	}

	switch (choose(3)) {
  case 0: gen_num(n); break;
  case 1: buf[(*n)++] = '('; gen_rand_expr(n, of); buf[(*n)++] = ')'; break;
  case 2: gen_rand_expr(n, of); gen_rand_op((*n)++); gen_rand_expr(n, of); break;
  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);

	uint32_t n;
	int of;

  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
		memset(buf, 0, sizeof(buf));
		
		of = 0;
		n = 0;
    gen_rand_expr(&n, &of);
		if (of) {
			continue;
		}

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr -Werror");
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
