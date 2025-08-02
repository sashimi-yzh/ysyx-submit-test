/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER is_used OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <isa.h>
#include <stdlib.h>
/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include "sdb.h"
#include "memory/vaddr.h"

enum
{
  TK_NOTYPE = 256,
  TK_EQ,
  TK_NUM,
  TK_HEX,
  TK_REG,
  TK_NEQ,
  TK_AND

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
    {"0[xX][0-9a-fA-F]+", TK_HEX},
    {" +", TK_NOTYPE},  // spaces
    {"\\+", '+'},       // plus
    {"\\-", '-'},       // sub
    {"\\*", '*'},       // mul
    {"\\/", '/'},       // div
    {"\\=\\=", TK_EQ},  // equal
    {"\\(", '('},       // left bracket
    {"\\)", ')'},       // right bracket
    {"[0-9]+", TK_NUM}, // number
    {"\\!\\=", TK_NEQ},
    {"\\&\\&", TK_AND},
    {"\\$[a-zA-Z]*[0-9]*", TK_REG}
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

static Token tokens[TOKEN_LEN] __attribute__((used)) = {};
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
        // char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //     i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type)
        {
        case ('+'):
          tokens[nr_token].type = '+';
          nr_token++;
          break;
        case ('-'):
          tokens[nr_token].type = '-';
          nr_token++;
          break;
        case ('*'):
          tokens[nr_token].type = '*';
          nr_token++;
          break;
        case ('/'):
          tokens[nr_token].type = '/';
          nr_token++;
          break;
        case ('('):
          tokens[nr_token].type = '(';
          nr_token++;
          break;
        case (')'):
          tokens[nr_token].type = ')';
          nr_token++;
          break;
        case (TK_NUM):
          tokens[nr_token].type = TK_NUM;
          memset(tokens[nr_token].str, '\0', sizeof(tokens[nr_token].str));
          strncpy(tokens[nr_token].str, &e[position - substr_len], substr_len);
          nr_token++;
          break;
        case (TK_EQ):
          tokens[nr_token].type = TK_EQ;
          memset(tokens[nr_token].str, '\0', sizeof(tokens[nr_token].str));
          strcpy(tokens[nr_token].str, "==");
          nr_token++;
          break;
        case (TK_NEQ):
          tokens[nr_token].type = TK_NEQ;
          memset(tokens[nr_token].str, '\0', sizeof(tokens[nr_token].str));
          strcpy(tokens[nr_token].str, "!=");
          nr_token++;
          break;
        case (TK_AND):
          tokens[nr_token].type = TK_AND;
          memset(tokens[nr_token].str, '\0', sizeof(tokens[nr_token].str));
          strcpy(tokens[nr_token].str, "&&");
          nr_token++;
          break;
        case (TK_REG):
          tokens[nr_token].type = TK_REG;
          memset(tokens[nr_token].str, '\0', sizeof(tokens[nr_token].str));
          strncpy(tokens[nr_token].str, &e[position - substr_len], substr_len);
          nr_token++;
          break;
        case (TK_HEX):
          tokens[nr_token].type = TK_HEX;
          memset(tokens[nr_token].str, '\0', sizeof(tokens[nr_token].str));
          strncpy(tokens[nr_token].str, &e[position - substr_len], substr_len);
          nr_token++;
          break;
        case (TK_NOTYPE):
          break;
        default:
          printf("please create new rules for %d\n", i);
          break;
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

int max(int a, int b)
{
  return (a > b) ? a : b;
}

bool check_parentheses(int p, int q)
{
  if(tokens[p].type != '(')
    return false;
  int left_parentheses_cnt = 0;
  for (int i = p; i <= q; i++)
  {
    if(tokens[i].type == '(')
      left_parentheses_cnt++;
    else if(tokens[i].type == ')')
      left_parentheses_cnt--;

    if(left_parentheses_cnt < 0)
      return false;
    if(left_parentheses_cnt == 0 && i != q)
      return false;
  }

  if(left_parentheses_cnt == 0)
    return true;

  return false;
  
}

uint32_t deref(char *s) {
  if(s == NULL) {
    printf("DEREF nothing!!\n");
    assert(0);
  }
  vaddr_t addr;
  word_t value;
  if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    // s = s + 2;
    sscanf(s, "%x", &addr);
  else 
    sscanf(s, "%d", &addr);
  value = vaddr_read(addr, 4);
  return value;
}

uint32_t eval(int p, int q)
{
  if (p > q)
  {
    /* Bad expression */
    printf("Bad expression\n");
    assert(0);
    return -1;
  }
  else if (p == q)
  {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
    if (tokens[p].type == TK_REG)
      return isa_reg_str2val(tokens[p].str);
    else {
      if(tokens[p].str[0] == '*')
        return deref(tokens[p].str + 1);
      else {
        if(tokens[p].type == TK_HEX) {
          uint32_t res;
          sscanf(tokens[p].str, "%x", &res);
          return res;
        }
        else
          return atoi(tokens[p].str);
      }
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
    uint8_t op = 0;
    uint8_t parentheses_cnt = 0;
    uint8_t alu_priority = 0;

    for (uint8_t i = p; i <= q; i++)
    {
      if (tokens[i].type == '(')
      {
        while (tokens[i].type != ')' || parentheses_cnt != 0)
        {
          if(tokens[i].type == '(')
            parentheses_cnt++;
          if(tokens[i].type == ')')
          {
            if(parentheses_cnt == 1)
            {
              if(i < q)
                i++;
              parentheses_cnt--;
              break;
            }
            parentheses_cnt--;
          }
          i++;
        }
      }

      if (alu_priority <= 11 && (tokens[i].type == TK_AND))
      {
        alu_priority = 11;
        op = max(op, i);
      }
      if (alu_priority <= 7 && (tokens[i].type == TK_EQ))
      {
        alu_priority = 7;
        op = max(op, i);
      }
      if (alu_priority <= 7 && (tokens[i].type == TK_NEQ))
      {
        alu_priority = 7;
        op = max(op, i);
      }
      if (alu_priority <= 4 && (tokens[i].type == '+' || tokens[i].type == '-'))
      {
        alu_priority = 4;
        op = max(op, i);
      }
      if (alu_priority <= 3 && (tokens[i].type == '*' || tokens[i].type == '/'))
      {
        alu_priority = 3;
        op = max(op, i);
      }
    }

    uint32_t op_type = tokens[op].type;
    uint32_t val1 = eval(p, op - 1);
    uint32_t val2 = eval(op + 1, q);

    // printf("val1 = %d, val2 = %d, op_type = %c\n", val1, val2, op_type);

    switch (op_type)
    {
    case '+':
      return val1 + val2;
    case '-':
      return val1 - val2;
    case '*':
      return val1 * val2;
    case '/':
      return (int)val1 / (int)val2;
    case TK_EQ:
      return val1 == val2;
    case TK_NEQ:
      return val1 != val2;
    case TK_AND:
      return val1 && val2;
    default:
      printf("Unknown Op Type\n");
      assert(0);
    }
  }
}

word_t expr(char *e, bool *success)
{
  // printf("exp is %s, len = %ld\n", e, strlen(e));
  // reset tokens
  for (int i = 0; i < TOKEN_LEN; i++)
  {
    tokens[i].type = 0;
  }
  

  if (!make_token(e))
  {
    *success = false;
    return 0;
  }

  *success = true;

  // eval the length
  int tokens_len = 0;
  for (int i = 0; i < TOKEN_LEN; i++)
  {
    if (tokens[i].type == 0)
      break;
    tokens_len++;
  }

  for (int i = 0; i < tokens_len; i++)
  {
    if (    (tokens[i].type == '-' && i > 0 && tokens[i - 1].type != TK_NUM && tokens[i + 1].type == TK_NUM && tokens[i - 1].type != ')')
        ||  (tokens[i].type == '-' && i == 0))
    {
      printf("%s\n", tokens[i+1].str);
      tokens[i].type = TK_NOTYPE;
      // tokens[i].str = tmp;
      for (int j = 31; j >= 1; j--)
      {
        tokens[i + 1].str[j] = tokens[i + 1].str[j - 1];
      }
      tokens[i + 1].str[0] = '-';
      printf("%s\n", tokens[i+1].str);
      for (int j = 0; j < tokens_len; j++)
      {
        if (tokens[j].type == TK_NOTYPE)
        {
          for (int k = j + 1; k < tokens_len; k++)
          {
            tokens[k - 1] = tokens[k];
          }
          tokens_len--;
        }
      }
    }
  }

  for (int i = 0; i < tokens_len; i++)
  {
    if (    (tokens[i].type == '*' && i > 0 && (tokens[i - 1].type != TK_NUM && tokens[i - 1].type != TK_HEX) && (tokens[i + 1].type == TK_NUM || tokens[i + 1].type == TK_HEX) && tokens[i - 1].type != ')')
        ||  (tokens[i].type == '*' && i == 0))
    {
      printf("%s\n", tokens[i+1].str);
      tokens[i].type = TK_NOTYPE;
      // tokens[i].str = tmp;
      for (int j = 31; j >= 1; j--)
      {
        tokens[i + 1].str[j] = tokens[i + 1].str[j - 1];
      }
      tokens[i + 1].str[0] = '*';
      printf("%s\n", tokens[i+1].str);
      for (int j = 0; j < tokens_len; j++)
      {
        if (tokens[j].type == TK_NOTYPE)
        {
          for (int k = j + 1; k < tokens_len; k++)
          {
            tokens[k - 1] = tokens[k];
          }
          tokens_len--;
        }
      }
    }
  }

  /* TODO: Insert codes to evaluate the expression. */
  uint32_t res = eval(0, tokens_len - 1);
  printf("value is 0x%08x\n", res);
  // printf("$%d = %d\n", watch_index, res);

  return res;
}
