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
int out_of_recursion_depth;
static char buf[65536] = {0};
static char buf_without_uint[65536] = {0};
static char code_buf[65536 + 1024] = {0}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"#include <stdint.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static int recursion_depth = 0;

uint32_t choose(uint32_t n) {
  if (n == 0) {
      return 0; 
  }
  return rand() % n;
}

static void gen_rand_op() {
  //buf[0] = '\0';
  switch (choose(9)) {
    case 0:  strncat(buf, "+", sizeof(buf) - strlen(buf)); strncat(buf_without_uint, "+", sizeof(buf_without_uint) - strlen(buf_without_uint)); break;
    case 1:  strncat(buf, "-", sizeof(buf) - strlen(buf)); strncat(buf_without_uint, "-", sizeof(buf_without_uint) - strlen(buf_without_uint)); break;
    case 2:  strncat(buf, "*", sizeof(buf) - strlen(buf)); strncat(buf_without_uint, "*", sizeof(buf_without_uint) - strlen(buf_without_uint)); break;
    case 3:  strncat(buf, "/", sizeof(buf) - strlen(buf)); strncat(buf_without_uint, "/", sizeof(buf_without_uint) - strlen(buf_without_uint)); break;
    case 4:  strncat(buf, "<=", sizeof(buf) - strlen(buf)); strncat(buf_without_uint, "<=", sizeof(buf_without_uint) - strlen(buf_without_uint)); break;
    case 5: strncat(buf, ">=", sizeof(buf) - strlen(buf)); strncat(buf_without_uint, ">=", sizeof(buf_without_uint) - strlen(buf_without_uint)); break;
    case 6:  strncat(buf, "==", sizeof(buf) - strlen(buf)); strncat(buf_without_uint, "==", sizeof(buf_without_uint) - strlen(buf_without_uint)); break;
    case 7:  strncat(buf, "!=", sizeof(buf) - strlen(buf)); strncat(buf_without_uint, "!=", sizeof(buf_without_uint) - strlen(buf_without_uint)); break;
    default:  strncat(buf, "&&", sizeof(buf) - strlen(buf)); strncat(buf_without_uint, "&&", sizeof(buf_without_uint) - strlen(buf_without_uint)); break;
  } 
}

static void gen_num() {
  char * before_str = "(uint32_t)";
  char str[32];
  sprintf(str, "%u", choose(-1));
  strncat(buf, before_str, sizeof(buf) - strlen(buf));
  strncat(buf, str, sizeof(buf) - strlen(buf));
  strncat(buf_without_uint, str, sizeof(buf_without_uint) - strlen(buf_without_uint));
}

static void gen_rand_blank() {
  uint32_t num_spaces = choose(2); 
  for (uint32_t i = 0; i < num_spaces; i++) {
        strncat(buf, " ", sizeof(buf) - strlen(buf)); 
        strncat(buf_without_uint, " ", sizeof(buf_without_uint) - strlen(buf_without_uint)); 
  }
}

static void gen_rand_expr() {
  if (recursion_depth > 50) {
    out_of_recursion_depth = 1;
    return;
  } 
  recursion_depth++;
  uint32_t n = 3;
  switch (choose(n)) {
    case 0: gen_num();
            break;
    case 1: strncat(buf, "(uint32_t)(", sizeof(buf) - strlen(buf)); 
            strncat(buf_without_uint, "(", sizeof(buf_without_uint) - strlen(buf_without_uint)); gen_rand_blank();
            gen_rand_expr();
            strncat(buf_without_uint, ")", sizeof(buf_without_uint) - strlen(buf_without_uint)); gen_rand_blank();
            strncat(buf, ")", sizeof(buf) - strlen(buf)); 
            break;
    default: 
             strncat(buf, "(uint32_t)(", sizeof(buf) - strlen(buf)); 
             strncat(buf_without_uint, "(", sizeof(buf_without_uint) - strlen(buf_without_uint)); gen_rand_blank();
             gen_rand_expr(); gen_rand_blank();
             gen_rand_op(); gen_rand_blank();
             gen_rand_expr(); gen_rand_blank();
             strncat(buf_without_uint, ")", sizeof(buf_without_uint) - strlen(buf_without_uint)); gen_rand_blank();
             strncat(buf, ")", sizeof(buf) - strlen(buf)); gen_rand_blank();
             break;
  }
  recursion_depth--;
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
    out_of_recursion_depth = 0;
    recursion_depth = 0;
    memset(buf, 0, sizeof(buf));
    memset(buf_without_uint, 0, sizeof(buf_without_uint));
    memset(code_buf, 0, sizeof(code_buf));
    gen_rand_expr();
    if(buf[65535] == '\0' && out_of_recursion_depth == 0){
      sprintf(code_buf, code_format, buf);

      FILE *fp = fopen("/tmp/.code.c", "w");
      assert(fp != NULL);
      fputs(code_buf, fp);
      fclose(fp);

      int ret = system("gcc -Werror /tmp/.code.c -o /tmp/.expr");
      if (ret != 0) continue;

      fp = popen("/tmp/.expr", "r");
      assert(fp != NULL);

      int result;
      ret = fscanf(fp, "%d", &result);
      pclose(fp);

      printf("%u %s\n", result, buf_without_uint);
    }
    else{
      i--;
    }
  }
  return 0;
}
