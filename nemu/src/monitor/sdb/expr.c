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

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <memory/vaddr.h>
#include <regex.h>

enum {
  TK_NOTYPE = 256,
  TK_EQ,

  /* TODO: Add more token types */
  TK_NUMBER,     // 十进制数
  TK_NEWLINE,    // 换行符
  TK_NUMBER_HEX, // 十六进制
  TK_DEREF,      // 指针解引用
  TK_AND,        // &&
  TK_NE,         // !=
  TK_REG_NAME    // reg_name
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

    /* TODO: Add more rules.
     * Pay attention to the precedence level of different rules.
     */

    {" +", TK_NOTYPE}, // spaces
    {"\\+", '+'},      // plus
    {"==", TK_EQ},     // equal

    {"&&", TK_AND},                       // and
    {"!=", TK_NE},                        // not eq
    {"0[xX][0-9a-fA-F]+", TK_NUMBER_HEX}, // hex number
    {"[0-9]+", TK_NUMBER},                // number
    {"-", '-'},                           // minus
    {"\\*", '*'},                         // mutiply
    {"/", '/'},                           // divide
    {"\\(", '('},                         // left bracket
    {"\\)", ')'},                         // right bracker
    {"\n", TK_NEWLINE},                   // newline
    {"\\$[\\$]?[a-z0-9]+", TK_REG_NAME}   // register
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
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

static Token tokens[65536] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool is_op(int pos) {
  switch (tokens[pos].type) {
  case '+':
  case '-':
  case '*':
  case '/':
  case TK_AND:
  case TK_EQ:
  case TK_NE:
    return true;
  default:
    return false;
  }
}

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        // extern bool test_expr;
        // if (!test_expr)
        //   Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s", i,
        //       rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
        case '+':
          tokens[nr_token++].type = '+';
          break;
        case '-':
          tokens[nr_token++].type = '-';
          break;
        case '*':
          if (nr_token == 0 || is_op(nr_token - 1)) {
            tokens[nr_token++].type = TK_DEREF;
          } else {
            tokens[nr_token++].type = '*';
          }
          break;
        case '/':
          tokens[nr_token++].type = '/';
          break;
        case '(':
          tokens[nr_token++].type = '(';
          break;
        case ')':
          tokens[nr_token++].type = ')';
          break;
        case TK_NUMBER:
          tokens[nr_token].type = TK_NUMBER;
          strncpy(tokens[nr_token].str, "", 32);
          strncpy(tokens[nr_token++].str, substr_start, substr_len);
          break;
        case TK_NUMBER_HEX:
          tokens[nr_token].type = TK_NUMBER_HEX;
          strncpy(tokens[nr_token].str, "", 32);
          strncpy(tokens[nr_token++].str, substr_start, substr_len);
          break;
        case TK_EQ:
          tokens[nr_token++].type = TK_EQ;
          break;
        case TK_AND:
          tokens[nr_token++].type = TK_AND;
          break;
        case TK_NE:
          tokens[nr_token++].type = TK_NE;
          break;
        case TK_REG_NAME:
          tokens[nr_token].type = TK_REG_NAME;
          strncpy(tokens[nr_token].str, "", 32);
          strncpy(tokens[nr_token++].str, substr_start + 1, substr_len - 1);
          break;
        default:
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

static bool check_parentheses(int left, int right) {
  int parenthese=0;
  for (int i = left + 1; i < right; i++) {
    if (tokens[i].type == '(') {
      parenthese += 1;
    } else if (tokens[i].type == ')') {
      if (parenthese > 0) {
        parenthese -= 1;
      } else {
        return false;
      }
    }
  }
  return tokens[left].type == '(' && tokens[right].type == ')';
}

static word_t eval(int left, int right, bool *success) {
  if (left > right) {
    *success = false;
    return 0;
  }
  if (left == right) {
    if (tokens[left].type == TK_REG_NAME) {
      return isa_reg_str2val(tokens[left].str,success);
    }
    return strtoull(tokens[left].str, NULL,
                    tokens[left].type == TK_NUMBER ? 10 : 16);
  } else if (check_parentheses(left, right) == true) {
    return eval(left + 1, right - 1, success);
  } else {
    int op = -1;
    int right_parenthese = 0;
    int priority[] = {
        TK_AND, TK_EQ, TK_NE, '+', '-', '*' << 16 | '/', TK_DEREF,
    };
    int order = 0;
    while (op == -1 && order < 7) {
      for (int i = right; i >= left; --i) {
        if (tokens[i].type == ')') {
          right_parenthese++;
        } else if (tokens[i].type == '(') {
          right_parenthese--;
        }
        if (right_parenthese != 0) {
          continue;
        }
        if (tokens[i].type == priority[order] ||
            tokens[i].type == priority[order] >> 16 ||   //'*'
            tokens[i].type == (priority[order] & 255)) { //'/'
          op = i;
          break;
        }
      }
      order++;
    }

    if (op == -1) {
      *success = false;
      return 0;
    }

    if (tokens[op].type == TK_DEREF) {
      return vaddr_read(eval(left + 1, right, success),
                        MUXDEF(CONFIG_ISA64, 8, 4));
    }

    word_t val1 = eval(left, op - 1, success);
    word_t val2 = eval(op + 1, right, success);

    switch (tokens[op].type) {
    case '+':
      return val1 + val2;
    case '-':
      return val1 - val2;
    case '*':
      return val1 * val2;
    case '/':
      return val1 / val2;
    case TK_EQ:
      return val1 == val2;
    case TK_AND:
      return val1 != 0 && val2 != 0;
    case TK_NE:
      return val1 != val2;
    default:
      *success = false;
      return 0;
    }
  }
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  return eval(0, nr_token - 1, success);
}
