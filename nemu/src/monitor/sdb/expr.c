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

#include "common.h"
#include "memory/paddr.h"
#include "sdb.h"
#include <isa.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
bool debug_eval = false;
typedef enum {
  TK_NOTYPE,
  TK_EQ,
  TK_ADD,
  TK_SUB,
  TK_NEG,
  TK_MUL,
  TK_DIV,
  TK_LP,
  TK_RP,
  TK_NUM,
  TK_HEX,
  TK_REG,
  TK_DEREF,
  TK_GE,
  TK_LE,
  TK_GT,
  TK_LT,
  /* TODO: Add more token types */

} TOKEN_TYPE;

static struct rule {
  const char *regex;
  TOKEN_TYPE token_type;
} rules[] = {
    {" +", TK_NOTYPE},                                           // spaces
    {"==", TK_EQ},                                               // equal
    {">=", TK_GE},                                               // greater or equal
    {"<=", TK_LE},                                               // less or equal
    {">", TK_GT},                                                // greater than
    {"<", TK_LT},                                                // less than
    {"\\+", TK_ADD},                                             // plus
    {"-", TK_SUB},                                               // minus
    {"\\*", TK_MUL},                                             // multiply
    {"/", TK_DIV},                                               // divide
    {"\\(", TK_LP},                                              // left parenthesis
    {"\\)", TK_RP},                                              // right parenthesis
    {"0[xX][0-9a-fA-F]+", TK_HEX},                               // hexadecimal numbers
    {"[0-9]+", TK_NUM},                                          // decimal number
    {"\\$(0|ra|sp|gp|tp|t[0-6]|s[0-9]|s1[0-1]|a[0-7])", TK_REG}, // register
};

int get_priority(TOKEN_TYPE token_type) {
  int priority = 0;
  switch (token_type) {
  case TK_RP:
  case TK_LP:
    priority++;
  case TK_HEX:
  case TK_REG:
  case TK_NUM:
    priority++;
  case TK_DEREF:
  case TK_NEG:
    priority++;
  case TK_MUL:
  case TK_DIV:
    priority++;
  case TK_SUB:
  case TK_ADD:
    priority++;
  case TK_GE:
  case TK_LE:
  case TK_GT:
  case TK_LT:
  case TK_EQ:
    priority++;
  default:
    break;
  }
  return priority;
}

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
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[1 << 20] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 &&
          pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s", i,
        //     rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;
        switch (rules[i].token_type) {
        case TK_NOTYPE:
          break;
        case TK_HEX:
        case TK_REG:
        case TK_NUM:
          tokens[nr_token].type = rules[i].token_type;
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].str[substr_len] = '\0';
          nr_token++;
          break;
        case TK_MUL:
          if (nr_token == 0 || (tokens[nr_token - 1].type != TK_NUM &&
                                tokens[nr_token - 1].type != TK_RP)) {
            tokens[nr_token].type = TK_DEREF;
          } else {
            tokens[nr_token].type = TK_MUL;
          }
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].str[substr_len] = '\0';
          nr_token++;
          break;
        case TK_SUB:
          if (nr_token == 0 || (tokens[nr_token - 1].type != TK_NUM &&
                                tokens[nr_token - 1].type != TK_RP)) {
            tokens[nr_token].type = TK_NEG;
          } else {
            tokens[nr_token].type = TK_SUB;
          }
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].str[substr_len] = '\0';
          nr_token++;
          break;
        default:
          tokens[nr_token].type = rules[i].token_type;
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].str[substr_len] = '\0';
          nr_token++;
          break;
        }
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

static void print_func_name_p_op_q(char *func_name, int p, int op, int q, word_t res) {
  printf("\e[0;34m%-20s|\e[0m ", func_name);
  for (int i = 0; i < p; i++) {
    printf("%s", tokens[i].str);
  }
  for (int i = p; i < op; i++) {
    printf("\e[0;32m%s\e[0m", tokens[i].str);
  }
  printf("\e[0;31m%s\e[0m", tokens[op].str);
  for (int i = op + 1; i <= q; i++) {
    printf("\e[0;32m%s\e[0m", tokens[i].str);
  }
  for (int i = q + 1; i < nr_token; i++) {
    printf("%s", tokens[i].str);
  }
  printf(" |%-20d|%-20u|%#08x", res, res, res);
  putchar('\n');
}

static void print_func_name_p_q(char *func_name, int p, int q, word_t res) {
  printf("\e[0;34m%-20s|\e[0m ", func_name);
  for (int i = 0; i < p; i++) {
    printf("%s", tokens[i].str);
  }
  printf("\e[0;31m%s\e[0m", tokens[p].str);
  for (int i = p + 1; i < q; i++) {
    printf("\e[0;32m%s\e[0m", tokens[i].str);
  }
  printf("\e[0;31m%s\e[0m", tokens[q].str);
  for (int i = q + 1; i < nr_token; i++) {
    printf("%s", tokens[i].str);
  }
  printf(" |%-20d|%-20u|%#08x", res, res, res);
  putchar('\n');
}

static int find_main_op(int p, int q, bool *success) {
  if (*success == 0)
    return 0;
  int op = -1;
  int min_pri = 10;
  int level = 0;

  for (int i = p; i <= q; i++) {
    int type = tokens[i].type;
    if (type == TK_LP)
      level++;
    else if (type == TK_RP)
      level--;
    else if (level == 0) {
      int pri = get_priority(type);
      switch (type) {
      case TK_NEG: {
        if (pri < min_pri) {
          min_pri = pri;
          op = i;
        }
        break;
      }
      default: {
        if (pri <= min_pri) {
          min_pri = pri;
          op = i;
        }
      }
      }
    }
  }
  if (op == -1) {
    *success = 0;
  }
  if (debug_eval) {
    if (*success) {
      print_func_name_p_op_q("find_main_op", p, op, q, 0);
    } else {
      puts("find_main_op false!");
    }
  }
  return op;
}
static bool check_parentheses(int p, int q) {
  if (tokens[p].type != TK_LP || tokens[q].type != TK_RP)
    return false;
  int cnt = 0;
  for (int i = p + 1; i <= q - 1; i++) {
    if (tokens[i].type == TK_LP)
      cnt++;
    else if (tokens[i].type == TK_RP)
      cnt--;
    if (cnt < 0)
      return false;
  }
  return cnt == 0;
}

static word_t eval(int p, int q, bool *success) {
  if (*success == 0)
    return 0;
  if (p > q) {
    *success = 0;
    return 0;
  } else if (p == q) {
    if (tokens[p].type == TK_NUM) {
      word_t val;
      sscanf(tokens[p].str, "%u", &val);
      return val;
    } else if (tokens[p].type == TK_HEX) {
      word_t val;
      sscanf(tokens[p].str, "%x", &val);
      return val;
    } else if (tokens[p].type == TK_REG) {
      word_t val = isa_reg_str2val(tokens[p].str, success);
      return val;
    } else {
      *success = 0;
      return 0;
    }
  } else if (check_parentheses(p, q)) {
    if (debug_eval) {
      print_func_name_p_q("into_parentheses", p, q, 0);
    }
    return eval(p + 1, q - 1, success);
  } else {
    word_t op = find_main_op(p, q, success);
    switch (tokens[op].type) {
    case TK_ADD: {
      word_t val1 = eval(p, op - 1, success);
      word_t val2 = eval(op + 1, q, success);
      word_t res = val1 + val2;
      if (debug_eval) {
        print_func_name_p_op_q("TK_ADD", p, op, q, res);
      }
      return res;
    }
    case TK_SUB: {
      word_t val1 = eval(p, op - 1, success);
      word_t val2 = eval(op + 1, q, success);
      word_t res = val1 - val2;
      if (debug_eval) {
        print_func_name_p_op_q("TK_SUB", p, op, q, res);
      }
      return res;
    }
    case TK_MUL: {
      word_t val1 = eval(p, op - 1, success);
      word_t val2 = eval(op + 1, q, success);
      word_t res = val1 * val2;
      if (debug_eval) {
        print_func_name_p_op_q("TK_MUL", p, op, q, res);
      }
      return res;
    }
    case TK_DIV: {
      int val1 = eval(p, op - 1, success);
      int val2 = eval(op + 1, q, success);
      if (val2 == 0) {
        if (debug_eval)
          print_func_name_p_op_q("\e[0;31mDivide by zero!\e[0m", p, op, q, 0);
        *success = 0;
        return 0;
      }
      word_t res = val1 / val2;
      if (debug_eval) {
        print_func_name_p_op_q("TK_DIV", p, op, q, res);
      }
      return res;
    }
    case TK_EQ: {
      word_t val1 = eval(p, op - 1, success);
      word_t val2 = eval(op + 1, q, success);
      word_t res = val1 == val2;
      if (debug_eval) {
        print_func_name_p_op_q("TK_EQ", p, op, q, res);
      }
      return res;
    }
    case TK_NEG: {
      word_t val = eval(op + 1, q, success);
      word_t res = -val;
      if (debug_eval) {
        print_func_name_p_op_q("TK_NEG", p, op, q, res);
      }
      return res;
    }
    case TK_DEREF: {
      paddr_t address = eval(op + 1, q, success);
      word_t res = paddr_read(address, 4);
      if (debug_eval) {
        print_func_name_p_op_q("TK_DEREF", p, op, q, res);
      }
      return res;
    }
    case TK_GE: {
      word_t val1 = eval(p, op - 1, success);
      word_t val2 = eval(op + 1, q, success);
      word_t res = val1 >= val2;
      if (debug_eval) {
        print_func_name_p_op_q("TK_GE", p, op, q, res);
      }
      return res;
    }
    case TK_LE: {
      word_t val1 = eval(p, op - 1, success);
      word_t val2 = eval(op + 1, q, success);
      word_t res = val1 <= val2;
      if (debug_eval) {
        print_func_name_p_op_q("TK_LE", p, op, q, res);
      }
      return res;
    }
    case TK_GT: {
      word_t val1 = eval(p, op - 1, success);
      word_t val2 = eval(op + 1, q, success);
      word_t res = val1 >= val2;
      if (debug_eval) {
        print_func_name_p_op_q("TK_GT", p, op, q, res);
      }
      return res;
    }
    case TK_LT: {
      word_t val1 = eval(p, op - 1, success);
      word_t val2 = eval(op + 1, q, success);
      word_t res = val1 <= val2;
      if (debug_eval) {
        print_func_name_p_op_q("TK_LT", p, op, q, res);
      }
      return res;
    }
    default:
      *success = 0;
      return 0;
    }
  }
}
word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  if (debug_eval) {
    printf("\e[0;31m%-20s| ", "func_name");
    for (int i = 0; i < nr_token; i++) {
      printf("%s", tokens[i].str);
    }
    printf(" |%-20s|%-20s|%-20s", "signed", "unsigned", "hex");
    puts("\e[0m");
  }
  *success = true;
  return eval(0, nr_token - 1, success);
}
