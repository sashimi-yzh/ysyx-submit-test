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
#define GEN_EXPR_BUF_LEN 65536
static char buf[GEN_EXPR_BUF_LEN] = {};
static int buf_cur_idx = 0;
static char code_buf[GEN_EXPR_BUF_LEN + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";
char op[] = {'+', '-', '*', '/'};
int op_len = sizeof(op) / sizeof(op[0]);
int parentheses_cnt = 0;

static uint32_t choose(uint32_t max) {
  return rand() % max;
}

static void gen_num(void) {
  int max_len = GEN_EXPR_BUF_LEN - buf_cur_idx - 1 - parentheses_cnt;
  int ret = snprintf(buf + buf_cur_idx, 
                     max_len, 
                     "%u", choose(-1));  
  buf_cur_idx += ret > max_len - 1 ? max_len - 1 : ret;
  sprintf(buf + buf_cur_idx, "u");
  buf_cur_idx++;
}

static void gen(char c) {
  sprintf(buf + buf_cur_idx, "%c", c);
  buf_cur_idx++;
}

static void gen_rand_op(void) {
  sprintf(buf + buf_cur_idx, "%c", op[choose(op_len)]); 
  buf_cur_idx++;
}

static void gen_space(void) {
  int space_num = choose((GEN_EXPR_BUF_LEN - buf_cur_idx - 1 - parentheses_cnt) / 100 + 1);
  int i;
  for (i = 0; i < space_num; i++) {
    sprintf(buf + buf_cur_idx, " ");
    buf_cur_idx++;
  }
}

static void gen_rand_expr() {
  if (GEN_EXPR_BUF_LEN - buf_cur_idx - 1 - parentheses_cnt > 3) {
    switch (choose(4)) {
      case 0: gen_num(); break;
      case 1: {
        parentheses_cnt++;
        gen('('); 
        gen_rand_expr(); 
        parentheses_cnt--;
        gen(')'); 
        break;
      }
      case 2: gen_space(); gen_rand_expr(); break;
      default: {
        gen_rand_expr(); 
        if (GEN_EXPR_BUF_LEN - buf_cur_idx - 1 - parentheses_cnt > 4) {
          gen_rand_op(); 
          gen_rand_expr(); 
        }
        break;
      }
    }
  } else {
    gen_num();
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
  for (i = 0; i < loop;) {
    int j;
    for (j = 0; j < GEN_EXPR_BUF_LEN; j++) {
      buf[j] = 0;
    }
    buf_cur_idx = 0;
    gen_rand_expr();

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -Werror=div-by-zero -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    uint32_t result;
    ret = fscanf(fp, "%d", &result);
    int return_val = pclose(fp);

    if (return_val == 0) {
      printf("%u ", result);
      int k;
      for (k = 0; k < GEN_EXPR_BUF_LEN; k++) {
        if (buf[k] == '\0') {
          putchar('\n');
          break;
        }
        if (buf[k] != 'u') {
          putchar(buf[k]);
        } 
      }
      i++;
    }
  }
  return 0;
}
