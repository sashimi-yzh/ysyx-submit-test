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

static char *buf_start = buf;
static char *buf_end = buf + sizeof(buf);



static int choose(int n){ 
	return rand() % n;
} //随机选取0,1 2中的一个


static void gen(char c){
	if( (buf_start + sizeof(c) +1) <= buf_end ){
		*buf_start = c;
		buf_start++;
		*buf_start = '\0';
	}else{
		return;
	}
}   //存入计算符号：+-*/()


static void gen_num(){ 
	int num = choose(INT8_MAX), len;
	char str[15];
	if((num == 0) && (buf_start > buf) ){
		if(*(buf_start-1) == '/') {num = 1;} //有除零的情况，改成除1.
	}
	len = snprintf(str, sizeof(str), "%du", num);
	//if(choose(2)&&(num != 0)){ len = snprintf(str, sizeof(str), "(-%du)", num);} //随机选择正负
	if( (buf_start + len +1) <= buf_end ){
		memcpy(buf_start, str, len + 1);
		buf_start += len;
	}else{
		return;
	}
	if(choose(3) == 0){
		int num_space = choose(3) + 1;
		for(int i = 0; i < num_space; i++){ gen(' ');}
	}
} //生成一个不大于INT8_MAX()的随机数


static char op[] = {'+','-','*','/'};
static void gen_rand_op(){ 
	int i = choose(sizeof(op));
	gen(op[i]);
}  //随机生成计算符号+-*/


static void gen_rand_expr() {
	 switch (choose(3)) {
		case 0: gen_num(); break;
		case 1: gen('('); gen_rand_expr(); gen(')'); break;
		default: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
	}
}


static void remove_u(char *c) {
	char *read_c =c;
	char *write_c =c;
	while(*read_c){
		if(*read_c != 'u'){
			*write_c = *read_c;
			write_c ++;
		}
		read_c++;
	}
	*write_c = '\0';
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
		//buf[0] = '\0';
		memset(buf, 0, sizeof(buf));//清零，方便下一次计算。
		buf_start = buf;
		gen_rand_expr();
		//check_zero(buf);
		sprintf(code_buf, code_format, buf);//导入表达式到code_but代码中

		FILE *fp = fopen("/tmp/.code.c", "w"); //定义临时文件并打开
		assert(fp != NULL);
		fputs(code_buf, fp); //将字符串写入文件
		fclose(fp); //关闭文件

		//int ret = system("gcc /tmp/.code.c -o /tmp/.expr");//执行系统命令
		int ret = system("gcc /tmp/.code.c -Wall -Werror -o /tmp/.expr");//执行系统命令
		if (ret != 0){
			i--; //
			continue;
		}//编译失败(包括除0)则跳过当前迭代的剩余部分，i--重复循环，确保最后有正确输出

		fp = popen("/tmp/.expr", "r"); //执行编译后的程序
		assert(fp != NULL);

		//uint64_t result;
		uint32_t result;
		ret = fscanf(fp, "%u", &result);//从文件读取数据存储到 result 变量中
		pclose(fp);

		//printf("uint32_t:%s\n", buf);
		remove_u(buf);

		printf("%u %s\n", result, buf);

	}
	return 0;
}
