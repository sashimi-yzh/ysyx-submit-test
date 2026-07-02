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
#include <sys/wait.h>

#define MAX_DEPTH 10

static char buf[65536] = {};
static char ubuf[65536] = {};
static char code_buf[65536] = {};
static char *code_format =
"#include <stdio.h>\n"
"#include <stdint.h>\n"
"int main() { "
"  uint32_t result = (uint32_t)(%s); "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static void gen(char *s) {
  int len = strlen(buf);
  int ulen = strlen(ubuf);
  int slen = strlen(s);
  if (len + slen < 65535 && ulen + slen < 65535) {
    strcat(buf, s);
    strcat(ubuf, s);
  }
}

static void gen_num() {
  char num_buf[32];
  char unum_buf[32];
  unsigned n = (unsigned)(rand() % 100);
  sprintf(num_buf, "%u", n);
  sprintf(unum_buf, "%uu", n);
  int len = strlen(buf);
  int ulen = strlen(ubuf);
  if (len + (int)strlen(num_buf) < 65535 && ulen + (int)strlen(unum_buf) < 65535) {
    strcat(buf, num_buf);
    strcat(ubuf, unum_buf);
  }
}

static void gen_rand_op() {
  switch (rand() % 16) {
    case 0: gen("+"); break;
    case 1: gen("-"); break;
    case 2: gen("*"); break;
    case 3: gen("/"); break;
    case 4: gen("=="); break;
    case 5: gen("!="); break;
    case 6: gen("&&"); break;
    case 7: gen("||"); break;
    case 8: gen("&"); break;
    case 9: gen("|"); break;
    case 10: gen("^"); break;
    case 11: gen("<<"); break;
    case 12: gen(">>"); break;
    case 13: gen("<"); break;
    case 14: gen(">"); break;
    case 15: gen("%"); break;
  }
}

static inline void gen_rand_expr() {
  static int depth = 0;
  if (depth >= MAX_DEPTH) { 
      gen_num(); 
      return;
  }

  switch (rand() % 3) {
    case 0: 
      gen_num(); 
      break;
    case 1: 
      gen("("); 
      depth++;
      gen_rand_expr(); 
      depth--;
      gen(")"); 
      break;
    default: 
      depth++;
      gen_rand_expr(); 
      gen_rand_op(); 
      gen_rand_expr(); 
      depth--;
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
  int count = 0;
  while (count < loop) {
    buf[0] = '\0';
    ubuf[0] = '\0';
    gen_rand_expr();

    sprintf(code_buf, code_format, ubuf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr -Werror=shift-count-overflow -Werror=div-by-zero >/dev/null 2>&1");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr 2>/dev/null", "r");
    assert(fp != NULL);

    unsigned result;
    if (fscanf(fp, "%u", &result) == 1) {
        // Check if the program terminated abnormally (e.g., division by zero)
        int pclose_ret = pclose(fp);
        if (WIFEXITED(pclose_ret) && WEXITSTATUS(pclose_ret) == 0) {
            printf("%u %s\n", result, buf);
            count++;
        }
    } else {
        pclose(fp);
    }
  }
  return 0;
}
