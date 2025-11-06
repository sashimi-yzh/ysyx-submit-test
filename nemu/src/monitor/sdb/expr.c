/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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

enum {
  TK_NOTYPE = 256, TK_EQ,

  /* TODO: Add more token types */
  TK_ADD,TK_SUB,TK_MUL,TK_DIV,TK_LEFT,TK_RIGHT,TK_DEC,
  TK_HEX,TK_REG,TK_NEQ,TK_AND,TK_LESS_EQ,TK_DEREF,TK_NEGATIVE,
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"==", TK_EQ},        // equal
  {"\\+", TK_ADD},         // plus
  {"-", TK_SUB},           // sub
  {"\\*", TK_MUL},         // mul
  {"/", TK_DIV},           // div
  {"\\(", TK_LEFT},           // (
  {"\\)", TK_RIGHT},           // )
  {"0x[0-9,a-f,A-F]+", TK_HEX},   // 0-f
  {"[0-9]+", TK_DEC},       // 0-9
  {"\\$[0-9,a-z]+", TK_REG},      // REG
  {"!=", TK_NEQ},            // not equal
  {"&&", TK_AND},            // AND
  {"<=", TK_LESS_EQ},           // less than   
  
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

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      // 1表示只存储一个匹配结果
      // rm_so表示匹配项在输入字符串中的起始偏移量
      // rm_eo表示匹配项在输入字符串中的结束偏移量
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case TK_NOTYPE: break;
          case TK_EQ:
          case TK_ADD:
          case TK_SUB:
          case TK_MUL:
          case TK_DIV:
          case TK_LEFT:
          case TK_RIGHT:
          case TK_NEQ:
          case TK_AND:
          case TK_LESS_EQ:
            tokens[nr_token].type = rules[i].token_type;
            nr_token++;
            break;
          case TK_REG:
            tokens[nr_token].type = rules[i].token_type;
            strncpy(tokens[nr_token].str, substr_start + 1, substr_len - 1);
            tokens[nr_token].str[substr_len - 1] = '\0'; // 确保字符串以空字符结尾
            if(strcmp(tokens[nr_token].str,"0") == 0){
              strncpy(tokens[nr_token].str, substr_start, substr_len);
              tokens[nr_token].str[substr_len] = '\0'; // 确保字符串以空字符结尾
            }
            nr_token++;
            break;
          case TK_DEC:
            tokens[nr_token].type = rules[i].token_type;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0'; // 确保字符串以空字符结尾
            nr_token++;
            break;
          case TK_HEX:
            tokens[nr_token].type = rules[i].token_type;
            strncpy(tokens[nr_token].str, substr_start+2, substr_len - 2);  // 去除0x
            tokens[nr_token].str[substr_len - 2] = '\0'; // 确保字符串以空字符结尾
            nr_token++;
            break;
          default: panic("cannot split token");
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

/**
 * 递归求值
 */
bool check_parentheses(int p,int q){
  if(tokens[p].type == TK_LEFT && tokens[q].type == TK_RIGHT){
    return true;
  }
  return false;
}

uint32_t eval(int p,int q){
  if(p > q){
    return 0;
  }else if(p == q){
    uint32_t result;
    bool success;
    switch (tokens[p].type)
    {
      case TK_DEC:
        sscanf(tokens[p].str, "%u", &result);
        return result;
        //return atoi(tokens[p].str);
      case TK_HEX:
        char *hex_number = tokens[p].str;  // 去除0x的长度
        uint32_t decimal_number = 0;
        sscanf(hex_number, "%x", &decimal_number);
        
        return decimal_number;  // 返回一个16进制的数
      case TK_REG:
        result = isa_reg_str2val(tokens[p].str,&success);
        if(success){
          return result;
        }else{
          panic("cannot read Reg %s",tokens[p].str);
          return 0;
        }
      default: return 0;
    }
    
  }else if(check_parentheses(p,q)){
    return eval(p+1, q-1);
  }else{
    int op = p;
    char op_type = ' ';
    int flag = 0; // 判断是否遇到了括号，遇到左括号加1，遇到右括号减1
    // find the position of 主运算符 in the token expression
    for(int i = p;i <= q;i++){
      if(tokens[i].type == TK_LEFT){
        flag ++;
        continue;
      }
      else if(tokens[i].type == TK_RIGHT){
        flag --;
        continue;
      }
      if(flag == 0){
        switch(tokens[i].type){
          case TK_DEREF:
            if(op_type == ' ' || op_type == 'f' || op_type == 'n'){
              op = i;
              op_type = 'f';
            }
            break;
          case TK_NEGATIVE:
            if(op_type == ' ' || op_type == 'f' || op_type == 'n'){
              op = i;
              op_type = 'n';
            }
            break;
          case TK_MUL:
            if(op_type == ' ' || op_type == '*' || op_type == '/' || op_type == 'f' || op_type == 'n'){
              op = i;
              op_type = '*';
            }
            break;
          case TK_DIV:
            if(op_type == ' ' || op_type == '*' || op_type == '/' || op_type == 'f' || op_type == 'n'){
              op = i;
              op_type = '/';
            }
            break;
          case TK_ADD:
            if(op_type == ' ' || (op_type != '=' && op_type != '!' && op_type != '&' && op_type != '<')){
              op = i;
              op_type = '+';
            }
            break;
          case TK_SUB:
            if(op_type == ' ' || (op_type != '=' && op_type != '!' && op_type != '&' && op_type != '<')){
              op = i;
              op_type = '-';
            }
            break;
          case TK_LESS_EQ:
            if(op_type == ' ' || (op_type != '=' && op_type != '!' && op_type != '&')){
              op = i;
              op_type = '<';
            }
            break;
          case TK_EQ:
            if(op_type == ' ' || op_type != '&'){
              op = i;
              op_type = '=';
            }
            break;
          case TK_NEQ:
            if(op_type == ' ' || op_type != '&'){
              op = i;
              op_type = '!';
            }
            break;
          case TK_AND:
            op = i;
            op_type = '&';
            break;
          default: continue;
        }
      }
    }
    if(flag != 0){
      panic("输入表达式错误，请检查\n");
    }
    uint32_t val1 = eval(p,op - 1);
    uint32_t val2 = eval(op + 1,q);
    switch (op_type)
    {
      // f 表示解引用，因为解引用是针对后面的表达式，所以解的地址是val2存储
      case 'f': return vaddr_read(val2,4);
      case 'n': return 0 - val2;
      case '*': return val1 * val2;
      case '/': 
        if(val2 == 0){
          panic("val2 == 0\n");
        }
        return val1 / val2;

      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '<': return val1 <= val2;
      case '=': return val1 == val2;
      case '!': return val1 != val2;
      case '&': return val1 && val2;
      case ' ': return val2;
      default: panic("cal failure\n");
    }
  }
  return 0;
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  /* TODO: Insert codes to evaluate the expression. */
  // TODO();
  // 识别指针解引用
  // 如果是指针解引用，前面不能是右括号、读寄存器、16进制和10进制的数
  for (int i = 0; i < nr_token; i ++) {
    if (tokens[i].type == TK_MUL && 
      (i == 0 || (tokens[i - 1].type != TK_RIGHT && tokens[i-1].type != TK_REG 
                  && tokens[i-1].type != TK_HEX && tokens[i-1].type != TK_DEC)) ) {
      tokens[i].type = TK_DEREF;
    }
  }
  // 识别负号
  // 如果是负号，前面不能是右括号、读寄存器、16进制和10进制的数
  for (int i = 0; i < nr_token; i ++) {
    if (tokens[i].type == TK_SUB && 
      (i == 0 || (tokens[i - 1].type != TK_RIGHT && tokens[i-1].type != TK_REG 
                  && tokens[i-1].type != TK_HEX && tokens[i-1].type != TK_DEC)) ) {
      tokens[i].type = TK_NEGATIVE;
    }
  }
  uint32_t val = eval(0,nr_token-1);
  *success = true;
  //printf("%u\n",val);
  return val;
}
