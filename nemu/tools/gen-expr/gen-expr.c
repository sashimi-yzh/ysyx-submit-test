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

#define MAX_EXPR_LENGTH 512
#define MAX_TOKENS 100

// this should be enough
static char buf[65536] = {};

static char code_buf[65536 + 128] = {}; // a little larger than `buf`

static char *code_format =
"#include <stdio.h>\n"
//"#include <stdint.h>\n"
"int main() { "
"  unsigned result = %s; "
//"  uint32_t result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

uint32_t choose (uint32_t n) {
	return rand() % n;
}
// 待完成
void gen_num(int* signal, int allow_zero) {
    if (*signal == 1) {
        return;
    }
    uint32_t num;
    if (allow_zero) {
        num = rand() % 100;
    } else {
        num = rand() % 99 + 1; // Generate 1-99 for non-zero
    }
    char str[3];
    snprintf(str, sizeof(str), "%u", num);
   // strncat(buf, "(uint32_t)", sizeof(buf) - strlen(buf));
    strncat(buf, str, sizeof(buf) - strlen(buf));
    *signal = 0;
}


void gen(char* str, int* signal){
	if(strcmp(str , ")") == 0){
		*signal = 1;
	}
	strncat(buf, str, sizeof(buf) - strlen(buf));
}

char* gen_rand_op() {
    char *op;
    switch (choose(4)) {
        case 0: op = "+"; break;
        case 1: op = "-"; break;
        case 2: op = "*"; break;
        case 3: op = "/"; break;
        default: op = "+"; break;
    }
    strncat(buf, op, sizeof(buf) - strlen(buf));
    return op;
}



static void gen_rand_expr(int* token_count) {
    int signal = 0;
    switch (choose(3)) {
        case 0:
            gen_num(&signal, 1); // Allow zero for general numbers
            (*token_count)++;
            break;
        case 1:
            gen("(", &signal);
            (*token_count)++;
            gen_rand_expr(token_count);
            gen(")", &signal);
            (*token_count)++;
            break;
        default:
            gen_rand_expr(token_count);
            const char *op = gen_rand_op();
            (*token_count)++;
            if (strcmp(op, "/") == 0) {
                // Generate non-zero right operand for division
                int right_signal = 0;
                gen_num(&right_signal, 0);
                (*token_count)++;
            } else {
                gen_rand_expr(token_count);
            }
            break;
    }
}
/*
static void gen_rand_expr(int* token_count) {
	int signal = 0;
	switch (choose(3)) {
		case 0: 
						gen_num(&signal, 1);
						(*token_count)++;
						break;
		case 1: 
						gen("(", &signal);
						(*token_count)++;
						gen_rand_expr(token_count);
						gen(")", &signal);
						(*token_count)++;
						break;
		default: 
						 gen_rand_expr(token_count);
						 gen_rand_op();
						(*token_count)++;
						 gen_rand_expr(token_count);
						 break;
	}
  //buf[0] = '\0';
}
*/
int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
		buf[0] = '\0'; // 清除buf内容
		int token_count = 0;
    gen_rand_expr(&token_count);

		if (token_count > MAX_TOKENS) {
			continue;
		}
    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr -Wno-overflow -Werror -Wall 2> null");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);


    int result;
    //uint32_t result;
    ret = fscanf(fp, "%u", &result);
    pclose(fp);
		//if (result >= 0){
			printf("%u %s\n", result, buf);
		//}
  }
  return 0;
}
