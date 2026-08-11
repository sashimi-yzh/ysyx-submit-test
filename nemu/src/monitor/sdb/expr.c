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

#include <regex.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#ifndef ARRLEN
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof((arr)[0]))
#endif

#ifndef panic
#define panic(fmt, ...) do { \
  fprintf(stderr, "panic: " fmt "\n", ##__VA_ARGS__); \
  abort(); \
} while (0)
#endif

// ---- NEMU provided in real project ----
// In your real NEMU tree, these are provided by headers/other modules.
// In standalone tests, test_expr.c provides stubs.
typedef uint32_t word_t;
word_t isa_reg_str2val(const char *s, bool *success);
word_t vaddr_read(word_t addr, int len);

// Token types
enum {
  TK_NOTYPE = 256,

  TK_EQ,      // ==
  TK_NEQ,     // !=
  TK_AND,     // &&

  TK_NUM,     // decimal (supports optional u/U suffix)
  TK_HEX,     // 0x... (supports optional u/U suffix)
  TK_REG,     // $pc, $a0, $x1 ...

  TK_LPAREN,  // (
  TK_RPAREN,  // )

  TK_NEG,     // unary minus
  TK_DEREF,   // unary deref
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {"[[:space:]]+", TK_NOTYPE},                    // spaces

  {"==", TK_EQ},
  {"!=", TK_NEQ},
  {"&&", TK_AND},

  {"\\(", TK_LPAREN},
  {"\\)", TK_RPAREN},

  {"\\+", '+'},
  {"-", '-'},
  {"\\*", '*'},
  {"/", '/'},

  {"\\$[a-zA-Z][a-zA-Z0-9]*", TK_REG},  // $pc $a0 $x1 ...

  {"0[xX][0-9a-fA-F]+[uU]?", TK_HEX},   // hex with optional u/U
  {"[0-9]+[uU]?", TK_NUM},              // dec with optional u/U
};

#define NR_REGEX ARRLEN(rules)
static regex_t re[NR_REGEX] = {};

void init_regex() {
  char error_msg[128];
  for (int i = 0; i < NR_REGEX; i++) {
    int ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, sizeof(error_msg));
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[256] = {};
static int nr_token = 0;

static bool make_token(char *e) {
  int position = 0;
  regmatch_t pmatch;
  nr_token = 0;

  while (e[position] != '\0') {
    int i;
    for (i = 0; i < NR_REGEX; i++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        position += substr_len;
        int t = rules[i].token_type;

        switch (t) {
          case TK_NOTYPE:
            break;

          case TK_NUM:
          case TK_HEX:
          case TK_REG: {
            if (nr_token >= (int)ARRLEN(tokens)) panic("Too many tokens");

            tokens[nr_token].type = t;
            if (substr_len >= (int)sizeof(tokens[nr_token].str)) {
              panic("Token string too long");
            }
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            break;
          }

          case TK_LPAREN:
          case TK_RPAREN:
          case TK_EQ:
          case TK_NEQ:
          case TK_AND:
          case '+':
          case '-':
          case '*':
          case '/': {
            if (nr_token >= (int)ARRLEN(tokens)) panic("Too many tokens");
            tokens[nr_token].type = t;
            tokens[nr_token].str[0] = '\0';
            nr_token++;
            break;
          }

          default:
            panic("Unknown token type: %d", t);
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

static bool is_value_token(int t) {
  return (t == TK_NUM || t == TK_HEX || t == TK_REG || t == TK_RPAREN);
}

// after tokenization, reclassify '-' and '*' that act as unary operators
static void reclassify_unary() {
  for (int i = 0; i < nr_token; i++) {
    if (tokens[i].type == '-') {
      if (i == 0 || !is_value_token(tokens[i - 1].type)) {
        tokens[i].type = TK_NEG;
      }
    }
    if (tokens[i].type == '*') {
      if (i == 0 || !is_value_token(tokens[i - 1].type)) {
        tokens[i].type = TK_DEREF;
      }
    }
  }
}

static bool check_parentheses(int p, int q) {
  if (tokens[p].type != TK_LPAREN || tokens[q].type != TK_RPAREN) return false;

  int bal = 0;
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == TK_LPAREN) bal++;
    else if (tokens[i].type == TK_RPAREN) bal--;

    if (bal == 0 && i < q) return false; // outer () closes before end
    if (bal < 0) return false;
  }
  return bal == 0;
}

// C-like precedence (among what we support):
// && (lowest), == !=, + -, * / (highest among binary)
static int op_prec(int type) {
  switch (type) {
    case TK_AND: return 0;
    case TK_EQ:
    case TK_NEQ: return 1;
    case '+':
    case '-':    return 2;
    case '*':
    case '/':    return 3;
    default:     return 100;
  }
}

static bool is_binary_op(int t) {
  return (t == '+' || t == '-' || t == '*' || t == '/' ||
          t == TK_EQ || t == TK_NEQ || t == TK_AND);
}

// Find the main operator in tokens[p..q] (lowest precedence at outermost level).
// For same precedence, choose the rightmost operator to enforce left-associativity.
static int find_main_op(int p, int q) {
  int main_op = -1;
  int main_prec = 100;
  int level = 0;

  for (int i = p; i <= q; i++) {
    int t = tokens[i].type;

    if (t == TK_LPAREN) { level++; continue; }
    if (t == TK_RPAREN) { level--; continue; }
    if (level != 0) continue;

    if (!is_binary_op(t)) continue;

    int prec = op_prec(t);
    if (prec < main_prec || (prec == main_prec && i > main_op)) {
      main_prec = prec;
      main_op = i;
    }
  }

  return main_op;
}

static word_t eval(int p, int q, bool *success) {
  if (p > q) {
    *success = false;
    return 0;
  }

  if (p == q) {
    if (tokens[p].type == TK_NUM) {
      return (word_t)strtoul(tokens[p].str, NULL, 10);
    }
    if (tokens[p].type == TK_HEX) {
      return (word_t)strtoul(tokens[p].str, NULL, 16);
    }
    if (tokens[p].type == TK_REG) {
      bool ok = true;
      const char *name = tokens[p].str;
      if (name[0] == '$') name++;
      word_t v = isa_reg_str2val(name, &ok);
      if (!ok) { *success = false; return 0; }
      return v;
    }
    *success = false;
    return 0;
  }

  if (check_parentheses(p, q)) {
    return eval(p + 1, q - 1, success);
  }

  // 先找主二元运算符
  int op = find_main_op(p, q);

  if (op >= 0) {
    word_t val1 = eval(p, op - 1, success);
    if (!*success) return 0;
    word_t val2 = eval(op + 1, q, success);
    if (!*success) return 0;

    switch (tokens[op].type) {
      case '+':   return val1 + val2;
      case '-':   return val1 - val2;
      case '*':   return val1 * val2;
      case '/':
        if (val2 == 0) { *success = false; return 0; }
        return val1 / val2;

      case TK_EQ:  return (word_t)(val1 == val2);
      case TK_NEQ: return (word_t)(val1 != val2);
      case TK_AND: return (word_t)((val1 != 0) && (val2 != 0));

      default:
        *success = false;
        return 0;
    }
  }

  // op < 0：说明区间内没有任何最外层二元运算符，尝试按一元表达式处理
  if (tokens[p].type == TK_NEG) {
    word_t v = eval(p + 1, q, success);
    if (!*success) return 0;
    return (word_t)(0u - v);
  }

  if (tokens[p].type == TK_DEREF) {
    word_t addr = eval(p + 1, q, success);
    if (!*success) return 0;
    return vaddr_read(addr, 4);
  }

  *success = false;
  return 0;
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  if (nr_token == 0) {
    *success = false;
    return 0;
  }

  reclassify_unary();

  *success = true;
  return eval(0, nr_token - 1, success);
}

