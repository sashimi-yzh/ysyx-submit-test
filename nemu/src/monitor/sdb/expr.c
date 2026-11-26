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
#include <memory/paddr.h> 

enum {
  TK_NOTYPE = 256, 
  TK_EQ,
  TK_NUM, // 十进制数
  TK_HEX,            // 十六进制数 0x...
  TK_REG,            // 寄存器 $...
  TK_NE,             // != 不等于
  TK_AND,            // && 逻辑与
  TK_DEREF,          // * 指针解引用（单目运算符）
  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},           // 空格
  
  {"==", TK_EQ},              // 等于
  {"!=", TK_NE},              // 不等于
  {"&&", TK_AND},             // 逻辑与
  
  {"0[xX][0-9a-fA-F]+", TK_HEX},  // 十六进制：0x1234, 0XABCD
  {"[0-9]+", TK_NUM},              // 十进制：123, 456
  
  {"\\$[a-zA-Z0-9]+", TK_REG},    // $pc, $a0, $t1
  
  {"\\+", '+'},               // 加号
  {"-", '-'},                 // 减号
  {"\\*", '*'},               // 乘号/解引用
  {"/", '/'},                 // 除号
  {"\\(", '('},               // 左括号
  {"\\)", ')'},               // 右括号
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

        // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //     i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case TK_NOTYPE:
            // 空格，不记录
            break;

          // 需要保存字符串的token类型
          case TK_NUM:
          case TK_HEX:
          case TK_REG:
            tokens[nr_token].type = rules[i].token_type;
            if (substr_len >= 32) {
              printf("Token too long!\n");
              return false;
            }
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            break;

          // 不需要保存字符串的token类型
          case '+':
          case '-':
          case '*':
          case '/':
          case '(':
          case ')':
          case TK_EQ:
          case TK_NE:
          case TK_AND:
            tokens[nr_token].type = rules[i].token_type;
            nr_token++;
            break;

          default:
            assert(0);
        }

        // 检查token数量
        if (nr_token >= 65536) {
          printf("Too many tokens\n");
          return false;
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

// 检查表达式是否被一对匹配的括号包围
// 返回值：true表示被包围，false表示未被包围或括号不匹配
static bool check_parentheses(int p, int q) {
  if (tokens[p].type != '(' || tokens[q].type != ')') {
    return false;  // 首尾不是括号
  }
  
  int count = 0;
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(') count++;
    if (tokens[i].type == ')') count--;
    
    // 括号不匹配
    if (count < 0) return false;
    
    // 在中间某处括号就配平了，说明不是被一对括号包围
    if (count == 0 && i < q) return false;
  }
  
  // 最后括号数应该为0
  return count == 0;
}


// 找到主运算符的位置
static int find_main_op(int p, int q) {
  int main_op = -1;
  int min_priority = 100;  // 初始化为很大的值
  int paren_level = 0;     // 括号层级
  
  for (int i = p; i <= q; i++) {
    // 处理括号
    if (tokens[i].type == '(') {
      paren_level++;
      continue;
    }
    if (tokens[i].type == ')') {
      paren_level--;
      continue;
    }
    
    // 括号内的运算符不是主运算符
    if (paren_level > 0) continue;
    
    // 单目运算符不是主运算符（在这里跳过）
    if (tokens[i].type == TK_DEREF) continue;
    
    // 判断运算符优先级
    int priority = 100;  // 默认很高（不是运算符）
    
    if (tokens[i].type == TK_AND) {
      priority = 0;  // 逻辑与优先级最低
    }
    else if (tokens[i].type == TK_EQ || tokens[i].type == TK_NE) {
      priority = 1;  // 相等比较
    }
    else if (tokens[i].type == '+' || tokens[i].type == '-') {
      priority = 2;  // 加减
    }
    else if (tokens[i].type == '*' || tokens[i].type == '/') {
      priority = 3;  // 乘除
    }
    else {
      continue;  // 不是运算符
    }
    
    // 选择优先级最低的，相同优先级选最右边的（左结合）
    if (priority <= min_priority) {
      min_priority = priority;
      main_op = i;
    }
  }
  
  return main_op;
}


static word_t eval(int p, int q, bool *success) {
  if (p > q) {
    // 错误的表达式
    *success = false;
    return 0;
  }
  else if (p == q) {
    // 单个token
    switch (tokens[p].type) {
      case TK_NUM:
        // 十进制数
        return atoi(tokens[p].str);
        
      case TK_HEX:
        // 十六进制数
        return strtol(tokens[p].str, NULL, 16);
        
      case TK_REG: {
        // 寄存器（跳过开头的$）
        bool reg_success;
        word_t val = isa_reg_str2val(tokens[p].str + 1, &reg_success);
        if (!reg_success) {
          printf("Unknown register: %s\n", tokens[p].str);
          *success = false;
          return 0;
        }
        return val;
      }
      
      default:
        printf("Invalid single token type: %d\n", tokens[p].type);
        *success = false;
        return 0;
    }
  }
  else if (check_parentheses(p, q) == true) {
    // 整个表达式被括号包围，去掉括号
    return eval(p + 1, q - 1, success);
  }
  else {
    // 检查是否为单目运算符（解引用）
    if (tokens[p].type == TK_DEREF) {
      // 指针解引用：*expr
      word_t addr = eval(p + 1, q, success);
      if (!*success) return 0;
      
      // 检查地址是否有效
#ifdef YSYXSOC_REF
      if (!(in_flash(addr) || in_sram(addr) || in_sdram(addr))) {
#else
      if (!in_pmem(addr)) {
#endif
        printf("Invalid memory address: " FMT_WORD "\n", addr);
        *success = false;
        return 0;
      }
      
      // 读取4字节（word_t大小）
      return paddr_read(addr, sizeof(word_t));
    }
    
    // 双目运算符
    int op = find_main_op(p, q);
    if (op == -1) {
      printf("No main operator found\n");
      *success = false;
      return 0;
    }
    
    word_t val1 = eval(p, op - 1, success);
    if (!*success) return 0;
    
    word_t val2 = eval(op + 1, q, success);
    if (!*success) return 0;
    
    switch (tokens[op].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/':
        if (val2 == 0) {
          printf("Division by zero!\n");
          *success = false;
          return 0;
        }
        return val1 / val2;
        
      case TK_EQ:  return val1 == val2;
      case TK_NE:  return val1 != val2;
      case TK_AND: return val1 && val2;
      
      default:
        printf("Unknown operator: %d\n", tokens[op].type);
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

  /* 识别指针解引用 */
  for (int i = 0; i < nr_token; i++) {
    if (tokens[i].type == '*') {
      if (i == 0 || 
          tokens[i - 1].type == '(' ||
          tokens[i - 1].type == '+' ||
          tokens[i - 1].type == '-' ||
          tokens[i - 1].type == '*' ||
          tokens[i - 1].type == '/' ||
          tokens[i - 1].type == TK_EQ ||
          tokens[i - 1].type == TK_NE ||
          tokens[i - 1].type == TK_AND ||
          tokens[i - 1].type == TK_DEREF) {
        tokens[i].type = TK_DEREF;
      }
    }
  }

  *success = true;
  word_t result = eval(0, nr_token - 1, success);
  return result;
}



