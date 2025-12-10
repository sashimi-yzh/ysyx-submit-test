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
#include "../../include/common.h"
#include <regex.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
enum {
  TK_NOTYPE = 256, TK_EQ, TK_DECIMAL, TK_HEXADECIMAL, TK_REG,
  TK_NEQ, TK_LOGICAND, TK_POINT,TK_UNSIGNED,

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
  
  {"\\+", '+'},                             // 加号
  {"-", '-'},                               // 减号或者负号
  {"\\*", '*'},                             // 乘号或者指针
  {"/", '/'},                               // 除号
  {"\\(unsigned\\)", TK_UNSIGNED},          // 无符号标识
  {"\\(", '('},                             // 左括号
  {"\\)", ')'},                             // 右括号
  {" +", TK_NOTYPE},                        // spaces
  {"==", TK_EQ},                            // equal
  {"0[xX][0-9a-fA-F]+", TK_HEXADECIMAL},    // 十六进制数字
  {"[0-9]+", TK_DECIMAL},                   // 十进制数字
  {"\\$[0-9a-z\\$]+", TK_REG},              // 寄存器名字
  {"!=", TK_NEQ},                           // 不相等
  {"&&", TK_LOGICAND},                      // 逻辑与
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
      Assert(0, "regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

#define NUM_TOKENS 1100
#define TOKEN_STR 32

typedef struct token {
  int type;
  char str[TOKEN_STR];
} Token;

static Token tokens[NUM_TOKENS] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

void init_tokens(){
  for (int i = 0; i < NUM_TOKENS; i++)
  {
    tokens[i].type = 0;
    memset(tokens[i].str, 0, TOKEN_STR);
  }
}

static bool make_token(char *e, int *valid_tokens) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;
  int tokens_position = 0;
  init_tokens();
  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {

        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //     i, rules[i].regex, position, substr_len, substr_len, substr_start);

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        if(tokens_position == NUM_TOKENS - 1) Assert(0, "The expression is too long\n");
        switch (rules[i].token_type) {
          case '+':
          case '-':
          case '*':
          case '/':
          case '(':
          case ')':
          case TK_EQ:
          case TK_NEQ:
          case TK_LOGICAND:
            tokens[tokens_position].type = rules[i].token_type;
            tokens_position++;
            break;
          case TK_DECIMAL:
            if(substr_len > NUM_TOKENS - 1) Assert(0, "The number is too long\n");
            strncpy(tokens[tokens_position].str,substr_start, substr_len);
            tokens[tokens_position].type = TK_DECIMAL;
            tokens_position++;
            break;
          case TK_HEXADECIMAL:
            if(substr_len > NUM_TOKENS -1) Assert(0, "The number is too long\n");
            strncpy(tokens[tokens_position].str,substr_start, substr_len);
            tokens[tokens_position].type = TK_HEXADECIMAL;
            tokens_position++;
            break;
          case TK_REG:
            if(substr_len > NUM_TOKENS -1) Assert(0, "The reg name is too long, 你估计打错了\n");
            strncpy(tokens[tokens_position].str,substr_start, substr_len);
            tokens[tokens_position].type = TK_REG;
            tokens_position++;
            break;
          default:
            break;  
        }
        // printf("position = %d, substr_len = %d, tokens_position = %d\n", position, substr_len, tokens_position);
        position += substr_len;
        break;
      }
    }
    
    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  // for (int i = 0; i < 32; i++)
  // {
  //   printf("tokens.type = %d, tokens.str = %s\t", tokens[i].type, tokens[i].str);
  // }

  *valid_tokens = tokens_position;
  return true;
}

int find_main_op(int p, int q) {
  int op = -1;
  int backet_in = 0;
  for (int i = p; i <= q; i++)
  {
    if(tokens[i].type != TK_DECIMAL && tokens[i].type != TK_HEXADECIMAL && tokens[i].type != TK_REG){
      if(tokens[i].type == '(') backet_in++;
      if(tokens[i].type == ')') backet_in--;
      Assert(backet_in >= 0, "表达式不合规");
      if(!backet_in && tokens[i].type != ')') {
        if(op == -1){
          op = i;
          continue;
        }
        if(tokens[i].type == TK_LOGICAND){
          op = i;
        }
        else if((tokens[i].type == TK_EQ || tokens[i].type == TK_NEQ) && tokens[op].type != TK_LOGICAND) {
          op = i;
        }
        else if(tokens[i].type == '+' || tokens[i].type == '-'){
          if(tokens[op].type != TK_EQ || tokens[op].type != TK_NEQ || tokens[op].type != TK_LOGICAND)
            op = i;
        }
        else if(tokens[i].type == '*' || tokens[i].type == '/') {
          if(tokens[op].type == TK_POINT || tokens[op].type == '*' || tokens[op].type == '/')
            op = i;
        }
      }
    }
  }
  return op;
}

typedef struct stack
{
  int data[256];
  int top;
} Stack;

void push_stack(Stack *p_stack, int data) {
  Assert((p_stack->top < ARRLEN(p_stack->data)),"堆栈已满");
  p_stack->data[p_stack->top] = data;
  p_stack->top++;
}

int pop_stack(Stack *p_stack) {
  Assert(p_stack->top, "堆栈为空");
  int data = p_stack->data[--(p_stack->top)];
  return data;
}

int get_stack_top(Stack *p_stack) {
  Assert(p_stack->top, "堆栈为空");
  int data = p_stack->data[p_stack->top - 1];
  return data;
}

bool check_parentheses(int p, int q) {
  bool hit = false;
  Stack backet_stack = {.top = 0};
  for(int i = p; i <= q; i++) 
  {
    if(tokens[i].type == '(')
    {
      push_stack(&backet_stack, i);
    } 
    else if(tokens[i].type == ')') 
    {
      if(i == q && get_stack_top(&backet_stack) == p)  hit = true;
      pop_stack(&backet_stack);
    }
    else
      continue;
  }

  Assert(backet_stack.top == 0, "左括号太多了");
  return hit;
}

#define OP(i) tokens[i].type == '+' || tokens[i].type == '-' || tokens[i].type == '*' ||\
                      tokens[i].type == '/' || tokens[i].type == TK_EQ || tokens[i].type == TK_NEQ ||\
                      tokens[i].type == TK_LOGICAND

#define EXPRESSION(i) tokens[i].type == TK_HEXADECIMAL || tokens[i].type == TK_DECIMAL || tokens[i].type == TK_REG

void ckeck_expression(int p, int q) {
  // 已经确保了q>p
  // printf("p = %d, q =%d\n",p,q);
  for(int i = p; i <= q; i++)
  {
    if(OP(i))
      if(tokens[i].type == '*')
        if(i != q && (EXPRESSION(i+1) || tokens[i+1].type == '('))
          if(i == p || (i != p && (OP(i-1) || tokens[i-1].type == '(')))
            {
              tokens[i].type = TK_POINT;
            }
  }
  for(int i = p; i <= q; i++)
  {
    if(OP(i))
      if(tokens[i].type != TK_POINT) {
        if(i == p || i == q)
          Assert(0, "四则运算表达式写错了");
        else if(OP(i-1) || tokens[i-1].type == '(' || OP(i+1) || tokens[i+1].type == ')')
                Assert(0, "四则运算表达式子写错了");
      }
  }
}

// p: 表达式开始的位置指示
// q: 表达式结束的位置指示
// 例如:p = 0, q = 9, 表示由10个tokens组成的长表达式
uint32_t eval(int p, int q){
  if (p > q) {
    Assert(0, "输入表达式指示位置违规");
  }
  else if (p == q) {
    if(tokens[p].type == TK_DECIMAL){
      return (uint32_t)atoi(tokens[p].str);
    }
    else if(tokens[p].type == TK_HEXADECIMAL){
      uint32_t number;
      sscanf(tokens[p].str, "%i", &number);
      return number;
    }
    else if(tokens[p].type == TK_REG) {
      bool success;
      uint32_t value = reg_str2val(tokens[p].str, &success);
      Assert(success, "取寄存器的表示错误了");
      return value;
    }
    else{
      Assert(0, "表达式违规");
    }
  }
  else if (check_parentheses(p, q) == true) {
    return eval(p + 1, q - 1);
  }
  else {
    ckeck_expression(p, q);
    int op = find_main_op(p,q);
    // printf("op = %d\n",op);
    uint32_t val1 = 0,val2;
    if(tokens[op].type != TK_POINT) {
      val1 = eval(p, op - 1);
    }
    val2 = eval(op + 1, q);

    switch (tokens[op].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': 
        Assert(val2 != 0, "除数为0了");  
        return val1 / val2;
      case TK_EQ:
        return val1 == val2;
      case TK_NEQ:
        return val1 != val2;
      case TK_LOGICAND:
        return val1 && val2;
      case TK_POINT:
        return vaddr_read(val2); 
      default: assert(0);
    }
  }
}

uint32_t expr(char *e, bool *success) {
  int valid_tokens = 0;
  if (!make_token(e, &valid_tokens)) {
    *success = false;
    return 0;
  }
  *success = true;
  uint32_t result = eval(0, valid_tokens-1);
  return result;

}