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
#include <stdbool.h>
// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned int result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static uint32_t buf_pos = 0;
static bool buf_len_over = false;
static char op_div = 0;

uint32_t choose(uint32_t n);
void gen_num();
void gen_rand_op();
void gen_char(char c);

static void gen_rand_expr() {
    
    switch(choose(3)) {
        case 0: gen_num(); break;
        case 1: gen_char('('); gen_rand_expr(); gen_char(')'); break;
        default: gen_rand_expr(); gen_rand_op(); if(op_div == '/') break; gen_rand_expr(); break;
    }
}

void gen_expr() {
    buf_pos = 0;
    gen_rand_expr();
    buf[buf_pos] = '\0';
}

uint32_t choose(uint32_t n) {
    return rand()%n;
}

void gen_num() {
    unsigned int num = rand() % 100;
    if(buf_pos == 65535 || buf_len_over) {
        buf_len_over = true;
        return;
    }
    buf_pos += sprintf(buf+buf_pos, "%u", num);
    gen_char('u');
}

void gen_num_nonzero() {
    unsigned int num = rand() % 100 + 1;
    if(buf_pos == 65535 || buf_len_over) {
        buf_len_over = true;
        return;
    }
    buf_pos += sprintf(buf+buf_pos, "%u", num);
    gen_char('u');
}

void gen_rand_op() {
    const char ops[] = {'+', '-', '*', '/'};
    char op = ops[rand()%4];
    op_div = 0;
    if(buf_pos == 65536-3 || buf_len_over) {
        buf_len_over = true;
        return;
    }
    buf[buf_pos++] = ' ';
    buf[buf_pos++] = op;
    buf[buf_pos++] = ' ';
    if(op == '/') {
        op_div = op;
        gen_num_nonzero();
    }
}

void gen_char(char c) {
    if((buf_pos == 65536-2 && c != ')') || buf_len_over) {
        buf_len_over = true;
        return;
    }
    buf[buf_pos++] = c;
    if(c != '(' && c != ')' && c != 'u') buf[buf_pos++] = ' ';
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
    gen_expr();

    if(buf_len_over) {
        i--;
        continue;
    };

    sprintf(code_buf, code_format, buf);
    //printf("%d: buf = %s\n",i, buf);

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
