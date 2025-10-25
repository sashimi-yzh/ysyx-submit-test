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
int beg = 0;
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
	"#include <stdio.h>\n"
	"int main() { "
	"  unsigned result = %s; "
	"  printf(\"%%u\", result); "
	"  return 0; "
	"}";
static void gen_rand_expr(int depth);
int choose(int i)
{
	int space = rand() % 3;
	for (int i = 0; i < space; i++)
	{
		buf[beg++] = ' ';
	}
	return rand() % i;
}
void gen_whole()
{
	memset(buf, 0, sizeof(buf));
	memset(code_buf, 0, sizeof(code_buf));
	beg = 0;
	int depth = choose(15) + 1;
	gen_rand_expr(depth);
}
void gen_num()
{
	int num = choose(100);
	char temp[5];
	sprintf(temp, "%d", num);
	memcpy(buf + beg, temp, strlen(temp));
	beg += strlen(temp);
}
void gen(char ch)
{
	buf[beg++] = ch;
}
void gen_rand_op()
{
	int opn = choose(7);
	char op;
	switch (opn)
	{
	case 0:
		op = '+';
		break;
	case 1:
		op = '-';
		break;
	case 2:
		op = '*';
		break;
	case 3:
		op = '/';
		break;
	case 4:
		buf[beg++] = '=';
		op = '=';
		break;
	case 5:
		buf[beg++] = '!';
		op = '=';
		break;
	case 6:
		buf[beg++] = '&';
		op = '&';
		break;
	}
	buf[beg++] = op;
}
static void gen_rand_expr(int depth)
{
	if (depth == 0)
		return;
	depth--;
	switch (choose(3))
	{
	case 0:
		gen_num();
		break;
	case 1:
		gen('(');
		depth == 0 ? gen_num() : gen_rand_expr(depth);
		gen(')');
		break;
	default:
		depth == 0 ? gen_num() : gen_rand_expr(depth);
		gen_rand_op();
		depth == 0 ? gen_num() : gen_rand_expr(depth);
		break;
	}
}

int main(int argc, char *argv[])
{
	int seed = time(0);
	srand(seed);
	int loop = 1;
	if (argc > 1)
	{
		sscanf(argv[1], "%d", &loop);
	}
	int i;
	for (i = 0; i < loop; i++)
	{
		gen_whole();

		sprintf(code_buf, code_format, buf);

		FILE *fp = fopen("/tmp/.code.c", "w");
		assert(fp != NULL);
		fputs(code_buf, fp);
		fclose(fp);

		int ret = system("gcc -Werror /tmp/.code.c -o /tmp/.expr");
		if (ret != 0)
			continue;

		fp = popen("/tmp/.expr", "r");
		assert(fp != NULL);

		int result;
		ret = fscanf(fp, "%d", &result);
		pclose(fp);

		printf("%u %s\n", result, buf);
	}
	return 0;
}
