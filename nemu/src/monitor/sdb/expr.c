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
#include <regex.h>
#include <memory/vaddr.h>

enum
{
  TK_NOTYPE = 256,
  TK_EQ,

  /* TODO: Add more token types */
  TK_NUM,
  TK_HEX,
  TK_REG,
  TK_NEQ,
  TK_AND,
  TK_DEREF

};

static struct rule
{
  const char *regex;
  int token_type;
} rules[] = {

    /* TODO: Add more rules.
     * Pay attention to the precedence level of different rules.
     */

    {" +", TK_NOTYPE},                   // spaces
    {"\\+", '+'},                        // plus
    {"==", TK_EQ},                       // equal
    {"0[xX][0-9a-fA-F]+", TK_HEX},       // hexadecimal number

    {"[0-9]+", TK_NUM},                  // number
    {"\\-", '-'},                        // minus
    {"\\*", '*'},                        // multiply or dereference
    {"/", '/'},                          // divide
    {"\\(", '('},                        // left parenthesis
    {"\\)", ')'},                        // right parenthesis
    {"\\$[a-zA-Z][a-zA-Z0-9]*", TK_REG}, // register
    {"!=", TK_NEQ},                      // not equal
    {"&&", TK_AND}                      // logical and

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

static Token tokens[65536] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;

enum
{
  ERR_NONE = 0,
  ERR_REGEX_FAIL, // make_token 失败
  ERR_BAD_RANGE,  // p > q
  ERR_BAD_EXPR,   // op == -1 (无法找到主运算符，括号不匹配或语法错误)
  ERR_DIV_ZERO,   // 除以 0
  ERR_UNKNOWN_OP, // 未知运算符
  NR_ERRORS       // 错误类型总数
};

static int curr_error = ERR_NONE;
static int error_counts[NR_ERRORS] = {0};
const char *get_error_name(int err_type)
{
  switch (err_type)
  {
  case ERR_REGEX_FAIL:
    return "Tokenization Failed";
  case ERR_BAD_RANGE:
    return "Bad Range (p > q)";
  case ERR_BAD_EXPR:
    return "Bad Expression (No Main Op)";
  case ERR_DIV_ZERO:
    return "Division By Zero";
  case ERR_UNKNOWN_OP:
    return "Unknown Operator";
  default:
    return "Unknown Error";
  }
}

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

        // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //     i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        if (rules[i].token_type == TK_NOTYPE)
        {
          break;
        }

        tokens[nr_token].type = rules[i].token_type;

        switch (rules[i].token_type)
        {
        case TK_NUM:
        case TK_HEX:
        case TK_REG:
        {
          Assert(substr_len < sizeof(tokens[nr_token].str), "number too long");
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].str[substr_len] = '\0';
          break;
        }

        default: // TODO();
          break;
        }
        Assert(nr_token < ARRLEN(tokens), "too many tokens");
        nr_token++;

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

static bool check_parentheses(int p, int q)
{
  if (tokens[p].type != '(' || tokens[q].type != ')')
  {
    return false;
  }

  int cnt = 0;
  for (int i = p; i <= q; i++)
  {
    if (tokens[i].type == '(')
      cnt++;
    else if (tokens[i].type == ')')
      cnt--;
    if (cnt == 0 && i < q)
      return false;
  }
  return cnt == 0;
}

static int get_precedence(int type)
{
  switch (type)
  {
  case TK_AND:
    return 1;
  case TK_EQ:
  case TK_NEQ:
    return 2;
  case '+':
  case '-':
    return 3;
  case '*':
  case '/':
    return 4;
  case TK_DEREF:
    return 5;
  default:
    return 0;
  }
}

static word_t eval(int p, int q, bool *success)
{
  if (p > q)
  {
    curr_error = ERR_BAD_RANGE;
    *success = false;
    return 0;
  }

  for (int i = p; i <= q; i++)
  {
    if (tokens[i].type == '*')
    {
      if (i == p || (tokens[i - 1].type != ')' &&
                     tokens[i - 1].type != TK_NUM &&
                     tokens[i - 1].type != TK_HEX&&
                    tokens[i - 1].type != TK_REG))
      {
        tokens[i].type = TK_DEREF;
      }
    }
  }

  if (p == q)
  {
    // return atoi(tokens[p].str);
    word_t val = 0;
    switch (tokens[p].type)
    {
    case TK_NUM:
      sscanf(tokens[p].str, "%u", &val);
      return val;
    case TK_HEX:
      sscanf(tokens[p].str, "%x", &val);
      return val;
    case TK_REG:
    {
      bool reg_success = true;
      val = isa_reg_str2val(tokens[p].str + 1, &reg_success);
      if (!reg_success)
      {
        curr_error = ERR_BAD_EXPR;
        *success = false;
        return 0;
      }
      return val;
    }
    default:
    {
      curr_error = ERR_BAD_EXPR;
      *success = false;
      return 0;
    }
    }
  }
  else if (check_parentheses(p, q))
  {
    return eval(p + 1, q - 1, success);
  }
  else
  {
    int op = -1;
    int cnt = 0;
    for (int i = p; i <= q; i++)
    {
      if (tokens[i].type == '(')
        cnt++;
      else if (tokens[i].type == ')')
        cnt--;
      else if (cnt == 0)
      {
        int curr_prec = get_precedence(tokens[i].type);
        if (curr_prec == 0)
        {
          continue;
        }
        if (op == -1)
        {
          op = i;
        }
        else
        {
          int op_prec = get_precedence(tokens[op].type);
          if (curr_prec <= op_prec)
          {
            op = i;
          }
        }
      }
    }
    if (op == -1)
    {
      curr_error = ERR_BAD_EXPR;
      *success = false;
      return 0;
    }

    int op_type = tokens[op].type;

    word_t val2 = eval(op + 1, q, success);

    if (op_type == TK_DEREF)
    {
      if (*success)
      {
        word_t addr = val2;
        return vaddr_read(addr, 4); // TODO
      }
      return 0;
    }
    
    word_t val1 = eval(p, op - 1, success);

    if (!*success)
      return 0;
    switch (op_type)
    {
    case '+':
      return val1 + val2;
    case '-':
      return val1 - val2;
    case '*':
      return val1 * val2;
    case '/':
      if (val2 == 0)
      {
        curr_error = ERR_DIV_ZERO;
        *success = false;
        return 0;
      }
      return val1 / val2;
    case TK_EQ:
      return val1 == val2;
    case TK_NEQ:
      return val1 != val2;
    case TK_AND:
      return val1 && val2;
    default:
      curr_error = ERR_UNKNOWN_OP;
      *success = false;
      return 0;
    }
  }

  return 0;
}

word_t expr(char *e, bool *success)
{
  if (!make_token(e))
  {
    curr_error = ERR_REGEX_FAIL;
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  return eval(0, nr_token - 1, success);
  // TODO();

  return 0;
}

void test_expr(bool *success)
{
  // int a =(72)+(40-(((37*58))))+((69/(((61)/(16)/(4)-74-41-((80)))*((63))))*87)*(((19))-(33*54+(57/(38)/(62))*(0)-(34+49-57)/93*(60)-38/(11/(25/67+26+31)-((((((((86))))))+(71/69*(53-(0/(3))))))+(39)+(69)/((72*(68)))-((33))-16/25/10+49/(93/(57)/(39))*98*13)))/29/((((0*(90)))-48+63-((79)*8)))-98*39;
  // printf("测试表达式：%d\n", a);
  // return;

  // test
  printf("开始从 input 文件加载测试用例...\n");

  FILE *fp = fopen("./tools/gen-expr/input", "r");

  if (fp == NULL)
  {
    printf("错误：无法打开 input 文件。请确保该文件位于 nemu/tools/gen-expr 目录下。\n");
    return;
  }

  char buf[65536];
  uint32_t ref_val;
  uint32_t count = 0;
  uint32_t fail_count = 0;

  memset(error_counts, 0, sizeof(error_counts));

  while (fscanf(fp, "%u %[^\n]", &ref_val, buf) == 2)
  {
    curr_error = ERR_NONE;

    uint32_t my_val = expr(buf, success);

    if (!*success)
    {
      printf("测试失败：expr 返回 false\n");
      printf("表达式: %s\n", buf);
      // assert(0);
      fail_count++;
      error_counts[curr_error]++;
      *success = true;
      continue;
      // return;
    }

    if (my_val != ref_val)
    {
      printf("测试失败：结果不匹配！\n");
      printf("表达式:   %s\n", buf);
      printf("预期结果: %u\n", ref_val);
      printf("实际结果: %u\n", my_val);
      // assert(0);
      fail_count++;
      continue;
      // return;
    }

    count++;
  }
  printf("已通过 %u 个测试用例\n失败 %u 个测试用例\n", count , fail_count);
  if (fail_count > 0)
  {
    printf("\n--- 错误原因统计 ---\n");
    for (int i = 1; i < NR_ERRORS; i++)
    {
      if (error_counts[i] > 0)
      {
        printf("%-25s: %d 个\n", get_error_name(i), error_counts[i]);
      }
    }
  }

  fclose(fp);
}