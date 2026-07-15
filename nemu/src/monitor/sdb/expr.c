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
#include <memory/vaddr.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum
{
  TK_NOTYPE = 256,
  TK_EQ,
  TK_NUM,
  TK_HEX,
  TK_NEQ,
  TK_AND,
  TK_DEREF,
  TK_REG

  /* TODO: Add more token types */

};

static struct rule
{
  const char *regex;
  int token_type;
} rules[] = {

    /* TODO: Add more rules.
     * Pay attention to the precedence level of different rules.
     */
    {"0x[0-9a-fA-F]+", TK_HEX}, // hexadecimal number
    {" +", TK_NOTYPE},          // spaces
    {"[0-9]+", TK_NUM},         // decimal number
    {"\\+", '+'},               // plus
    {"\\-", '-'},               // minus
    {"\\*", '*'},               // multiply
    {"\\/", '/'},               // divide
    {"\\(", '('},               // left parenthesis
    {"\\)", ')'},               // right parenthesis
    {"==", TK_EQ},              // equal
    {"!=", TK_NEQ},             // not equal
    {"&&", TK_AND},              // logical and
    {"\\$[a-zA-Z0-9]+", TK_REG} // register
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex()
{
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i++)
  {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0)
    {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token
{
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;

static bool make_token(char *e)
{
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0')
  {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i++)
    {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0)
      {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type)
        {
        case TK_NOTYPE:
          break;

        case TK_NUM:
          assert(nr_token < 32);
          tokens[nr_token].type = TK_NUM;

          assert(substr_len < 32);
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].str[substr_len] = '\0';
          nr_token++;
          break;

        case TK_HEX:
          assert(nr_token < 32);
          tokens[nr_token].type = TK_HEX;

          assert(substr_len < 32);
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].str[substr_len] = '\0';
          nr_token++;
          break;

        case '+':
          assert(nr_token < 32);
          tokens[nr_token++].type = '+';
          break;
        case '-':
          assert(nr_token < 32);
          tokens[nr_token++].type = '-';
          break;
        case '*':
          assert(nr_token < 32);
          tokens[nr_token++].type = '*';
          break;
        case '/':
          assert(nr_token < 32);
          tokens[nr_token++].type = '/';
          break;
        case '(':
          assert(nr_token < 32);
          tokens[nr_token++].type = '(';
          break;
        case ')':
          assert(nr_token < 32);
          tokens[nr_token++].type = ')';
          break;
        case TK_EQ:
          assert(nr_token < 32);
          tokens[nr_token++].type = TK_EQ;
          break;

        case TK_NEQ:
          assert(nr_token < 32);
          tokens[nr_token++].type = TK_NEQ;
          break;

        case TK_AND:
          assert(nr_token < 32);
          tokens[nr_token++].type = TK_AND;
          break;

        case TK_REG:
          assert(nr_token < 32);
          tokens[nr_token].type = TK_REG;

          assert(substr_len < 32);
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].str[substr_len] = '\0';
          nr_token++;
          break;

        default:
          TODO();
        }

        break;
      }
    }

    if (i == NR_REGEX)
    {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

/* Check if tokens[p..q] is surrounded by a matched pair of parentheses. */
static bool check_parentheses(uint32_t p, uint32_t q)
{
  if (tokens[p].type != '(' || tokens[q].type != ')')
  {
    return false;
  }
  int level = 0;
  for (uint32_t i = p; i <= q; i++)
  {
    if (tokens[i].type == '(')
      level++;
    else if (tokens[i].type == ')')
    {
      level--;
      /* The '(' at p matched before reaching q, so they are not a wrapping pair. */
      if (level == 0 && i < q)
        return false;
    }
  }
  return true;
}

/* Return operator precedence (lower value = weaker binding = evaluated last). */
static int op_prec(int type)
{
  switch (type)
  {

  case TK_AND:
    return 0;
  case TK_EQ:
  case TK_NEQ:
    return 1;
  case '+':
  case '-':
    return 2;
  case '*':
  case '/':
    return 3;
  case TK_DEREF:
  case TK_REG:
    return 4;
  default:
    return -1; /* not an operator */
  }
}

uint32_t eval(uint32_t p, uint32_t q)
{
  if (p > q)
  {
    assert(0);
  }
  else if (p == q)
  {
    /* Single token: must be a number or a register. */
    assert(tokens[p].type == TK_NUM || tokens[p].type == TK_HEX || tokens[p].type == TK_REG);
    if (tokens[p].type == TK_NUM)
      return (uint32_t)atoi(tokens[p].str);
    else if (tokens[p].type == TK_HEX)
      return (uint32_t)strtoul(tokens[p].str, NULL, 16);
    else
    {
      bool success = false;
      uint32_t val = isa_reg_str2val(tokens[p].str, &success);
      assert(success);
      return val;
    }
  }
  else if (check_parentheses(p, q) == true)
  {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1);
  }
  else
  {
    /* Find the main operator: the operator with the lowest precedence
     * that is not inside any parentheses. Among ties, pick the rightmost
     * one to ensure left-associativity. */
    int main_op = -1;
    int min_prec = 100;
    int level = 0;
    for (uint32_t i = p; i <= q; i++)
    {
      if (tokens[i].type == '(')
      {
        level++;
        continue;
      }
      if (tokens[i].type == ')')
      {
        level--;
        continue;
      }
      if (level != 0)
        continue;
      int prec = op_prec(tokens[i].type);
      if (prec < 0)
        continue;
      if (prec <= min_prec)
      {
        main_op = (int)i;
        min_prec = prec;
      }
    }
    assert(main_op != -1);

    /* Handle unary prefix dereference operator. */
    if (tokens[main_op].type == TK_DEREF) {
      uint32_t addr = eval((uint32_t)main_op + 1, q);
      return (uint32_t)vaddr_read(addr, sizeof(word_t));
    }

    uint32_t val1 = eval(p, (uint32_t)main_op - 1);
    uint32_t val2 = eval((uint32_t)main_op + 1, q);

    switch (tokens[main_op].type)
    {
    case '+':
      return val1 + val2;
    case '-':
      return val1 - val2;
    case '*':
      return val1 * val2;
    case '/':
      assert(val2 != 0);
      return val1 / val2;
    case TK_EQ:
      return (uint32_t)(val1 == val2);
    case TK_NEQ:
      return (uint32_t)(val1 != val2);
    case TK_AND:
      return (uint32_t)(val1 && val2);
    default:
      assert(0);
    }
  }
  return 0; /* unreachable */
}

word_t expr(char *e, bool *success)
{
  if (!make_token(e))
  {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */

  for (uint32_t i = 0; i < nr_token; i++)
  {
    if (tokens[i].type == '*' && (i == 0 || (tokens[i - 1].type != TK_NUM && tokens[i - 1].type != TK_HEX && tokens[i - 1].type != ')')))  
    {
      tokens[i].type = TK_DEREF;
    }
  }

  uint32_t result = eval(0, nr_token - 1);
  *success = true;

  return result;
}
