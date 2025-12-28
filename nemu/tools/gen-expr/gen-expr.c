/***************************************************************************************
* Copyright (c) 2014-2021 Zihao Yu, Nanjing University
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


int index_buf  = 0;

int choose(int n){
    
	
    return rand()%3;
}
void gen_num() {    
    int num;  
    do {  
        num = rand() % 100; 
    } while (num == 0); 
  
    if (num >= 10) {   
        buf[index_buf++] = '0' + num / 10;   
        buf[index_buf++] = '0' + num % 10;   
    } else {    
        buf[index_buf++] = '0' + num;   
    }    
}
void gen(char c){
    buf[index_buf ++] = c;
}

char gen_rand_op() {
    char op[4] = {'+', '-', '*', '/'};
    int op_position = rand() % 4;
    char op_result = op[op_position];
    buf[index_buf++] = op_result; 
    return op_result; 
}

int need = 0;  
  
static void gen_rand_expr() {  
    if (index_buf > 10000) {  
        printf("overSize\n");  
        return;  
    }  
  
    switch (choose(3)) { 
        case 0:  
            gen_num();  
            break;  
        case 1:  
            
            if (need) {  
                gen('(');  
                need = 0; 
                gen_rand_expr();  
                gen(')');  
                
            } else {  
               
                gen_rand_expr();  
            }  
            break;  
        default:
            gen_rand_expr();
            char op = gen_rand_op();
            
         
            if (op == '/') {
                
                gen('('); 
                gen_num(); 
                gen(')'); 
            } else {
               
                need = 1; 
                gen_rand_expr();
            }
            break;
    

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
	gen_rand_expr();
	buf[index_buf] = '\0';
	sprintf(code_buf, code_format, buf);

	FILE *fp = fopen("/tmp/.code.c", "w");
	assert(fp != NULL);
	fputs(code_buf, fp);
	fclose(fp);

	int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
	if (ret != 0) continue;

	fp = popen("/tmp/.expr", "r");
	assert(fp != NULL);

	uint32_t result;
	
	ret = fscanf(fp, "%u", &result);
	pclose(fp);

	printf("%u %s\n", result, buf);
	index_buf = 0;
    }
    return 0;
}

