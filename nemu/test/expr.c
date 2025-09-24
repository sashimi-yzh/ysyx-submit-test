/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <assert.h>
#include <regex.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  TK_NOTYPE = 256,
  TK_EQ,
  TK_PLUS,
  TK_DASH,
  TK_MUL,
  TK_DIV,
  TK_PARENS_L,
  TK_PARENS_R,
  TK_NUM,
  TK_H_NUM,
  TK_U,

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

    /* TODO: Add more rules.
     * Pay attention to the precedence level of different rules.
     */
    {" +", TK_NOTYPE}, // spaces
    {"==", TK_EQ},     // equal
    {"\\+", TK_PLUS},  // plus
    {"-", TK_DASH},       {"\\*", TK_MUL},      {"/", TK_DIV},
    {"\\(", TK_PARENS_L}, {"\\)", TK_PARENS_R}, {"0x[0-9a-f]+", TK_H_NUM},
    {"[0-9]+", TK_NUM},   {"u", TK_U},
};

#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      printf("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
      assert(0);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[2500] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;

static bool make_token(char *e, uint32_t *q) {

  int position = 0;
  int i;
  int count = 0;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 &&
          pmatch.rm_so == 0) {
        int substr_len = pmatch.rm_eo;

        // char *substr_start = e + position;
        // printf("match rules[%d] =  %-7s at position %d with len %d: %.*s\n",
        //     i, rules[i].regex, position, substr_len, substr_len,
        //     substr_start);

        position += substr_len;
        // printf("substr_len = %d\n", substr_len);

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
        case TK_U:
        case TK_NOTYPE:
          break;
        default:
          if (substr_len >= 32) {
            printf("Token str buffer is overflowed.\n");
            assert(0);
          }
          tokens[count].type = rules[i].token_type;
          memcpy(tokens[count].str, &e[position - substr_len], substr_len);
          count++;
          break;
        }
        // printf("match token =  %-7s tokens[%d].type = \"%d\" tokens[%d].str =
        // \"%s\"\n", 				rules[i].regex, count-1 , tokens[count-1].type, i,
        //tokens[count-1].str);

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  // printf("position = %d\n", position);
  *q = count - 1;
  // printf("q = %d [make_token]\n", *q);

  return true;
}

static bool check_parentheses(int p, int q) {

  bool checkp = true;
  int countl = 0, countr = 0;

  if (tokens[p].type == rules[6].token_type &&
      tokens[q].type == rules[7].token_type) {
    for (int i = p + 1; i <= q - 1; i++) {
      if (tokens[i].type == rules[6].token_type) {
        countl++;
      }
      if (tokens[i].type == rules[7].token_type) {
        countr++;
      }
      if (countl < countr) {
        checkp = false;
      }
    }
    // printf("countl = %d, countr = %d\n", countl, countr);
    if (countl != countr) {
      printf("Invalid expression.\n");
      assert(0);
    }
  } else {
    // printf("else\n");
    checkp = false;
  }

  // printf("checkp = %s\n", checkp ? "true" : "false");
  return checkp;
}

static int check_op(uint32_t p, uint32_t q) {

  int op;
  int token_position[3000] = {};
  int count_p = 0;
  int count = 0;
  int count_as = 0;

  /* 思路：
   * 1、逐个token扫描，遇到 "(" 计数加一，遇到 ")" 计数减一，
   * 如果遇到运算符时，计数不等于0，则不可能是主运算符，
   * 等于0则把位置放到候补数组里。
   * 2、候补数组逐个扫描，按结合律，op总是等于同优先级的下一个运算符，
   * 用count_as表示是否有"+"或"-"，如果有，"*""/"舍弃，
   * 扫描结束，即得op
   */
  // printf("[check_op] no wrong before for");
  for (int i = p; i <= q; i++) {
    switch (tokens[i].type) {
    case TK_PARENS_L:
      count_p++;
      break;
    case TK_PARENS_R:
      count_p--;
      break;
    case TK_PLUS:
    case TK_DASH:
    case TK_MUL:
    case TK_DIV:
      // printf("tokens[%d].type = %d\n", i, tokens[i].type);
      if (count_p == 0) {
        token_position[count] = i;
        count++;
      }
      break;
    }
  }
  // printf("token_position[0] = %d\n", token_position[0]);
  // int i = 0;
  // while (token_position[i] != 0) {
  //	printf("%s ", tokens[token_position[i]].str);
  //	i++;
  // }

  for (int j = 0; j <= count - 1; j++) {
    switch (tokens[token_position[j]].type) {
    case TK_MUL:
    case TK_DIV:
      if (count_as == 0) {
        op = token_position[j];
      }
      break;
    case TK_PLUS:
    case TK_DASH:
      op = token_position[j];
      count_as++;
      break;
    }
  }

  return op;
}

static uint32_t eval(uint32_t p, uint32_t q) {

  uint32_t val;
  // printf("p = %u, q = %u\n", p, q);
  if (p > q) {
    printf("wrong position: p = %u, q = %u\n", p, q);
    assert(0);
  } else if (p == q) {

    switch (tokens[p].type) {
    case TK_NUM:
      val = strtoul(tokens[p].str, NULL, 0);
      break;
    case TK_H_NUM:
      val = strtoul(tokens[p].str, NULL, 0);
      break;
    }
    return val;
  } else if (check_parentheses(p, q) == true) {

    return eval(p + 1, q - 1);
  } else {
    uint32_t val1;
    uint32_t val2;
    int op;

    if (tokens[p].type == TK_DASH && (q - p) == 1) {
      val = strtoul(tokens[q].str, NULL, 10);
      return -val;
    }

    // printf("no wrong before op\n");
    op = check_op(p, q);
    // printf("position of op = %d\n", op);
    val1 = eval(p, op - 1);
    val2 = eval(op + 1, q);

    // printf("position of op = %d, val1 = %u, val2 = %u\n", op, val1, val2);

    switch (tokens[op].type) {
    case TK_PLUS:
      return val1 + val2;
    case TK_DASH:
      return val1 - val2;
    case TK_MUL:
      return val1 * val2;
    case TK_DIV:
      return val1 / val2;
    default: // panic("Operator symbol \"%s\"is correct.", tokens[op].str);
      assert(0);
    }
  }
}

uint32_t expr(char *e, bool *success) {

  uint32_t p = 0;
  uint32_t q = 0;
  uint32_t val;

  if (!make_token(e, &q)) {
    *success = false;
    return 1;
  }

  /* TODO: Insert codes to evaluate the expression. */
  printf("p = %d, q = %d\n", p, q);
  val = eval(p, q);
  // printf("val = %u", val);

  return val;
}

int main() {

  init_regex();

  char *e = malloc(4097 * sizeof(char));
  uint32_t val = 0;
  bool success;

  printf("请输入表达式：");
  scanf("%65535[^\n]", e);
  // printf("e = %s\n", e);
  // printf("length of e = %lu\n", strlen(e));
  // printf("e[4080] = %s\n", e + 4080);

  // printf("no wrong before val [main]\n");
  val = expr(e, &success);

  printf("表达式的值为：%u\n", val);
  free(e);

  return 0;
}
