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
#include "debug.h"
#include <alloca.h>
#include <asm-generic/errno-base.h>
#include <errno.h>
#include <inttypes.h>
#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

word_t vaddr_read(vaddr_t, int);

enum {
  TK_IGNORE = 256, TK_NUM10, TK_NUM16, TK_OP,
  TK_REG, 
};

enum {
  NO_OP, OP_BIN, OP_PRE, OP_SUF
};

struct op {
  int op_type;
  int precedence; // The smaller the number, the higher the priority
  bool is_right_associative;
  uint32_t (*calc)(uint32_t, uint32_t, bool *);
};

static uint32_t calc_add(uint32_t val1, uint32_t val2, bool *success) {
  return val1 + val2;
}
static uint32_t calc_sub(uint32_t val1, uint32_t val2, bool *success) {
  return val1 - val2;
}
static uint32_t calc_mul(uint32_t val1, uint32_t val2, bool *success) {
  return val1 * val2;
}
static uint32_t calc_div(uint32_t val1, uint32_t val2, bool *success) {
  if (val2 == 0) {
    *success = false;
    return 0;
  }
  return val1 / val2;
}
static uint32_t calc_eq(uint32_t val1, uint32_t val2, bool *success) {
  return val1 == val2;
}
static uint32_t calc_ne(uint32_t val1, uint32_t val2, bool *success) {
  return val1 != val2;
}
static uint32_t calc_and_l(uint32_t val1, uint32_t val2, bool *success) {
  return val1 && val2;
}
static uint32_t calc_deref(uint32_t val1, uint32_t val2, bool *success) {
  return vaddr_read(val2, 4);
}
static uint32_t calc_neg(uint32_t val1, uint32_t val2, bool *success) {
  return -val2;
}

static struct rule {
  const char *regex;
  int group;
  int token_type;
  struct op op[3]; // 0: OP_BIN   1: OP_PRE   2: OP_SUF
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {"^0(x|X)[0-9a-fA-F]+", 0, TK_NUM16},
  {"^([0-9]+)([^xX0-9]|$)", 1, TK_NUM10},
  {"^\\$[0-9a-zA-Z]+", 0, TK_REG},
  {"^ +", 0, TK_IGNORE},    // spaces
  {"^\\(", 0, '('},
  {"^\\)", 0, ')'},

/*
  {"^$", 0, TK_OP, {{NO_OP},
                    {OP_PRE, 3, true, calc_reg},
                    {NO_OP}}},
*/

  {"^==", 0, TK_OP, {{OP_BIN, 8, false, calc_eq},
                     {NO_OP}, 
                     {NO_OP}}}, 
                                    
  {"^!=", 0, TK_OP, {{OP_BIN, 8, false, calc_ne},
                     {NO_OP},
                     {NO_OP}}},

  {"^&&", 0, TK_OP, {{OP_BIN, 12, false, calc_and_l}, 
                     {NO_OP}, 
                     {NO_OP}}},

  {"^\\+", 0, TK_OP, {{OP_BIN, 5, false, calc_add},
                      {NO_OP},
                      {NO_OP}}},        
                                      
  {"^\\-", 0, TK_OP, {{OP_BIN, 5, false, calc_sub},
                      {OP_PRE, 3, true, calc_neg},
                      {NO_OP}}},

  {"^\\*", 0, TK_OP, {{OP_BIN, 4, false, calc_mul},
                      {OP_PRE, 3, true, calc_deref},
                      {NO_OP}}},

  {"^\\/", 0, TK_OP, {{OP_BIN, 4, false, calc_div},
                      {NO_OP},
                      {NO_OP}}},
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};
static int nsub_max = 0;

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
    if (re[i].re_nsub > nsub_max)
      nsub_max = re[i].re_nsub;
  }
}


typedef struct token {
  int rule_idx;
  struct op op;
  char *str;
} Token;

#define TOKENS_MAX_LENGTH 65536
static Token tokens[TOKENS_MAX_LENGTH] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static struct token *get_token_ptr(void) {
  Assert(nr_token < TOKENS_MAX_LENGTH, "tokens is full");
  struct token *tok_ptr = tokens + nr_token;
  nr_token++; 
  return tok_ptr;
}

static int parse_op_type(void) {
  int i;
  for (i = 0; i < nr_token; i++) {
    struct rule *ru_cur = &rules[tokens[i].rule_idx];
    if (ru_cur->token_type == TK_OP) {
      if (i == 0) {
        if (ru_cur->op[1].op_type != OP_PRE) {
          Log("expect a prefix operation at %d", i);
          return -1;
        }
        tokens[i].op = ru_cur->op[1];
        continue;
      } else if (i == nr_token - 1) {
        if (ru_cur->op[2].op_type != OP_SUF) {
          Log("expect a suffix operation at %d", i);
          return -1;
        }
        tokens[i].op = ru_cur->op[2];
        continue;
      }
      struct rule *ru_prev = &rules[tokens[i - 1].rule_idx];
      struct rule *ru_next = &rules[tokens[i + 1].rule_idx];
      if ((ru_prev->token_type == TK_OP || ru_prev->token_type == '(') && 
          ru_cur->op[1].op_type == OP_PRE) {
        tokens[i].op = ru_cur->op[1];
      } else if ((ru_next->token_type == TK_OP || ru_next->token_type == ')') && 
                 ru_cur->op[2].op_type == OP_SUF) {
        tokens[i].op = ru_cur->op[2];
      } else if (ru_cur->op[0].op_type == OP_BIN) {
        tokens[i].op = ru_cur->op[0];
      } else {
        Log("parse operation fail");
        return -1;
      }
    } else {
      tokens[i].op = ru_cur->op[0];
    }
  }
  return 0;
}

static void set_token(struct token *tok_ptr, int rule_idx, char *str, int str_len) {
  int tok_type = rules[rule_idx].token_type;
  Assert(tok_type != TK_IGNORE, "TK_IGNORE shouldn't add to tokens");
  tok_ptr->rule_idx = rule_idx;
  switch (tok_type) {
    case TK_REG:
    case TK_NUM16:
    case TK_NUM10: {
      char *str_ptr = malloc(str_len + 1);
      Assert(str_ptr, "malloc return NULL");
      strncpy(str_ptr, str, str_len);
      str_ptr[str_len] = '\0';
      tok_ptr->str = str_ptr;
      break;
    }
  }
}

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t *pmatch = malloc((nsub_max + 1) * sizeof(regmatch_t));
  Assert(pmatch, "malloc return NULL");

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, re[i].re_nsub + 1, pmatch, 0) == 0 && pmatch[rules[i].group].rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch[rules[i].group].rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        Assert(substr_len > 0, "substr's length is 0");
        if (rules[i].token_type != TK_IGNORE) {
          struct token *tok_ptr = get_token_ptr();
          set_token(tok_ptr, i, substr_start, substr_len);
        }
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      free(pmatch);
      pmatch = NULL;
      return false;
    }
  }
  free(pmatch);
  pmatch = NULL;
  if (parse_op_type() != 0) {
    return false;
  }
  return true;
}

static void free_tokens(void) {
  int i;
  for (i = 0; i < nr_token; i++) {
    char *str_ptr = tokens[i].str;
    if (str_ptr) {
      free(str_ptr);
      tokens[i].str = NULL;
    }
  }
}

// RETURN: -1: invalid token
//          0: no outer parentheses
//          1: exist outer parenthese
static int check_parentheses(Token *start, Token *end) {
  if (start > end)
    return -1;
  int cnt = 0;
  bool is_outer_pair = true;
  Token *p = start;
  while(p <= end) {
    int tok_type = rules[p->rule_idx].token_type;
    if (tok_type == '(') {
      cnt++;
    } else if (tok_type == ')') {
      cnt--;
    }
    if (cnt == 0 && p != end)
      is_outer_pair = false;
    if (cnt < 0)
      return -1;
    p++;
  }
  if (cnt != 0) {
    return -1;
  } else if (is_outer_pair) {
    return 1;
  } else {
    return 0;
  }
}

static bool in_parentheses(Token *target, Token *end) {
  int cnt = 0;
  Token *p = target + 1;
  while (p <= end) {
    int tok_type = rules[p->rule_idx].token_type;
    if (tok_type == '(') {
      cnt++;
    } else if (tok_type == ')') {
      cnt--;
    }
    if (cnt < 0)
      return true;
    p++;
  }
  return false;
}

static Token *get_main_op(Token *start, Token *end) {
  Token *main_op = NULL;
  Token *p;
  for (p = start; p <= end; p++) {
    int tok_type = rules[p->rule_idx].token_type;
    if (tok_type != TK_OP) {
      continue;
    } else if (in_parentheses(p, end)) {
      continue;
    } else if (main_op == NULL) {
      main_op = p;
    } else if (p->op.precedence > main_op->op.precedence) {
      main_op = p;
    } else if ((p->op.precedence == main_op->op.precedence) && 
                !(p->op.is_right_associative)) {
      Assert(main_op->op.is_right_associative == p->op.is_right_associative, 
             "exist diffirent associative in the same precedence: %s %s", 
              rules[main_op->rule_idx].regex, rules[p->rule_idx].regex);
      main_op = p;
    }
  }
  return main_op;
}

static uint32_t parse_basic_token(Token *tok, bool *success) {
    char *endptr = NULL;
    int tok_type = rules[tok->rule_idx].token_type;
    uint32_t val;
    if (tok_type == TK_REG) {
      val = isa_reg_str2val(tok->str, success);
    } else {
      errno = 0;
      if (tok_type == TK_NUM16) {
        val = strtol(tok->str, &endptr, 16);
      } else {
        val = strtol(tok->str, &endptr, 10);
      }
      if (errno == ERANGE) {
        perror("");
        Log("number is out of range: %s", tok->str);
      } else if (errno == EINVAL) {
        perror("");
        Log("token is not a number: %s", tok->str);
        *success = false;
        return 0;
      } else if (errno != 0) {
        perror("");
        Log("basic token parse error: %s", tok->str);
      }
      if (*endptr != '\0') {
        Log("exist non-number token in a number string: %s", tok->str);
      }
    }
    return val;
}

static uint32_t eval(Token *start, Token *end, bool *success) {
  bool scs = true;
  if (start > end) {
    Log("invalid token");
    *success = false;
    return 0;
  } else if (start == end) {
    uint32_t val = parse_basic_token(start, &scs);
    if (scs) {
      return val;
    } else {
      *success = false;
      return 0;
    }
  } else {
    int pair_check_result = check_parentheses(start, end);
    if (pair_check_result < 0) {
      Log("exist unmatched parentheses");
      *success = false;
      return 0;
    } else if (pair_check_result) {
      uint32_t val = eval(start + 1, end - 1, &scs);
      if (scs) {
        return val;
      } else {
        *success = false;
        return 0;
      }
    } else {
      Token *op = get_main_op(start, end);
      Assert(op, "main op not found");
      uint32_t val1 = op == start ? 0 : eval(start, op - 1, &scs);
      uint32_t val2 = op == end ? 0 : eval(op + 1, end, &scs);
      uint32_t result = 0;
      if (scs) {
        result = op->op.calc(val1, val2, &scs);
      }
      if (scs) {
        return result;
      } else {
        *success = false;
        return 0;
      }
    }
  }
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    free_tokens();
    return 0;
  }
  
  bool scs = true;
  uint32_t val = eval(tokens, tokens + (nr_token - 1), &scs);

  free_tokens();

  if (!scs) {
    *success = false;
    return 0;
  }
  return val;
}
