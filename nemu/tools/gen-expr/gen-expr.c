/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format = "#include <stdio.h>\n"
                           "int main() { "
                           "  long long result = (long long)%s; "
                           "  printf(\"%%lld\", result); "
                           "  return 0; "
                           "}";

static void gen_rand_expr(int len) {
  const char choices[] = "nnnn++++----**//^^^&||nnnn++++----**//"
                         "^^^&||(())))r% "; // n代表数字，r代表<><=>===!=
  const char digits[] = "123456789ABCDEF";
  int cnt_choices = sizeof(choices) - 1;
  char last = '(';
  int cnt_brace = 0;
  int char_cnt = 0;
  for (int i = 0; i < len; i++) {

    char chooce = choices[rand() % cnt_choices];
    switch (chooce) {
    case '+':
      if (last == ')' || last == 'n') {
        buf[char_cnt++] = last = '+';
      } else
        i--;
      break;
    case '-':
      if (last == ')' || last == 'n') {
        buf[char_cnt++] = last = '-';
      } else
        i--;
      break;
    case '*':
      if (last == ')' || last == 'n') {
        buf[char_cnt++] = last = '*';
      } else
        i--;
      break;
    case '/':
      if (last == ')' || last == 'n') {
        buf[char_cnt++] = last = '/';
      } else
        i--;
      break;
    case '%':
      if (last == ')' || last == 'n') {
        buf[char_cnt++] = last = '%';
      } else
        i--;
      break;
    case '^':
      if (last == ')' || last == 'n') {
        buf[char_cnt++] = last = '^';
      } else
        i--;
      break;
    case '&':
      if (last == ')' || last == 'n') {
        buf[char_cnt++] = last = '&';
      } else
        i--;
      break;
    case '|':
      if (last == ')' || last == 'n') {
        buf[char_cnt++] = last = '|';
      } else
        i--;
      break;
    case 'n':
      if (last != ')' && last != 'n') {
        switch (rand() % 8) {
        case 0:
          buf[char_cnt++] = ' ';
          buf[char_cnt++] = '-';
          break;
        case 1:
          buf[char_cnt++] = ' ';
          buf[char_cnt++] = '+';
          break;
        case 2:
          buf[char_cnt++] = ' ';
          buf[char_cnt++] = '~';
          break;
        }
        switch (rand() % 8) {
        case 0:
          buf[char_cnt++] = ' ';
          buf[char_cnt++] = '-';
          break;
        case 1:
          buf[char_cnt++] = ' ';
          buf[char_cnt++] = '+';
          break;
        case 2:
          buf[char_cnt++] = ' ';
          buf[char_cnt++] = '~';
          break;
        }
        if (rand() % 9 < 4) { // hex
          buf[char_cnt++] = '0';
          buf[char_cnt++] = 'x';
          buf[char_cnt++] = digits[rand() % 15];
          if (rand() % 9 < 3)
            buf[char_cnt++] = digits[rand() % 15];
          buf[char_cnt++] = ' ';
        } else if (rand() % 9 < 7) { // decimal
          buf[char_cnt++] = digits[rand() % 9];
          if (rand() % 9 < 3)
            buf[char_cnt++] = digits[rand() % 9];
        } else { // oct
          buf[char_cnt++] = '0';
          buf[char_cnt++] = digits[rand() % 7];
          if (rand() % 9 < 3)
            buf[char_cnt++] = digits[rand() % 7];
        }
        last = 'n';
      } else
        i--;
      break;
    case '(':
      if (last != ')' && last != 'n') {
        switch (rand() % 8) {
        case 0:
          buf[char_cnt++] = ' ';
          buf[char_cnt++] = '-';
          break;
        case 1:
          buf[char_cnt++] = ' ';
          buf[char_cnt++] = '+';
          break;
        case 2:
          buf[char_cnt++] = ' ';
          buf[char_cnt++] = '~';
          break;
        }
        buf[char_cnt++] = last = '(';
        cnt_brace++;
      } else
        i--;
      break;
    case ')':
      if ((last == ')' || last == 'n') && cnt_brace > 0) {
        buf[char_cnt++] = last = ')';
        cnt_brace--;
      } else
        i--;
      break;
    case 'r':
      if (last == ')' || last == 'n') {
        switch (rand() % 6) {
        case 0:
          buf[char_cnt++] = '<';
          break;
        case 1:
          buf[char_cnt++] = '>';
          break;
        case 2:
          buf[char_cnt++] = '<';
          buf[char_cnt++] = '=';
          break;
        case 3:
          buf[char_cnt++] = '>';
          buf[char_cnt++] = '=';
          break;
        case 4:
          buf[char_cnt++] = '!';
          buf[char_cnt++] = '=';
          break;
        default:
          buf[char_cnt++] = '=';
          buf[char_cnt++] = '=';
          break;
        }
        last = 'r';
      } else
        i--;
      break;

    case ' ':
      buf[char_cnt++] = ' ';
      i--;
      break;

    default:
      printf("Got %c\n", chooce);
      assert(0);
    }
  }
  if (last != ')' && last != 'n') {
    buf[char_cnt++] = (rand() % 9 + '1');
  }
  while (cnt_brace--)
    buf[char_cnt++] = ')';
  buf[char_cnt] = '\0';
}

int main(int argc, char *argv[]) {
  if (argc < 4) {
    puts("Useage : gen-expr [random seed] [# of testcases] [char cnt]");
    return -1;
  }
  int seed = atoi(argv[1]);
  srand(seed);
  int loop = atoi(argv[2]);
  int i;
  int char_cnt = atoi(argv[3]);
  for (i = 0; i < loop; i++) {
    gen_rand_expr(char_cnt);

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system(
        "gcc -Werror=overflow -Werror=div-by-zero /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) {
      fputs("Skipping", stderr);
      i--;
      continue;
    } // ret = system("cat /tmp/.gcclog | grep \"div-by-zero\" > /dev/null");
    // if (ret == 0) {
    //   i--;
    //   continue;
    // }
    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    long long result;
    ret = fscanf(fp, "%lld", &result);
    pclose(fp);

    printf("%lld  %s", result, buf);
    if (loop != i + 1)
      putchar('\n');
  }
  return 0;
}
