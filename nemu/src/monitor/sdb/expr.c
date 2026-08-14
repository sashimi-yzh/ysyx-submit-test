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

enum {
  TK_NOTYPE = 256, TK_EQ, TK_DEC, TK_NEG, TK_NEQ, TK_AND, TK_DER, TK_HEX, TK_REG,

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"-", '-'},           // sub
  {"\\*", '*'},         // mul
  {"/", '/'},           // div
  {"\\(", '('},           // left
  {"\\)", ')'},           // right
  {"0x[a-f0-9]+u?", TK_HEX},      // hex
  {"[1-9][0-9]+u?|[0-9]u?", TK_DEC}, // num - dec
  {"==", TK_EQ},        // equal
  {"!=", TK_NEQ},       // not equal
  {"&&", TK_AND},       // and
  {"\\$0|\\$[a-z][a-z0-9]{1,2}", TK_REG}, // reg
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

static Token tokens[66536] __attribute__((used)) = {};
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
        tokens[nr_token].type = rules[i].token_type;
        
        if(tokens[nr_token].type != TK_NOTYPE) {
          // 跳过空格
          Assert(substr_len <= 32, "token is too long");
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].str[substr_len] = '\0'; // 这样不必每次调用 make tokens 时都初始化 tokens.str
          if(tokens[nr_token].type == '-' && (nr_token == 0 || (tokens[nr_token - 1].type != TK_REG && tokens[nr_token - 1].type != TK_HEX && tokens[nr_token - 1].type != TK_DEC && tokens[nr_token - 1].type != ')'))) {
            tokens[nr_token].type = TK_NEG;
          } // TODO
          if(tokens[nr_token].type == '*' && (nr_token == 0 || (tokens[nr_token - 1].type != TK_REG && tokens[nr_token - 1].type != TK_HEX && tokens[nr_token - 1].type != TK_DEC && tokens[nr_token - 1].type != ')'))) {
            tokens[nr_token].type = TK_DER;
          }
          nr_token++;
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

bool check_parentheses(int p, int q, bool *success) {
  if(tokens[p].type != '(' || tokens[q].type != ')') {
    return false;
  }
  int i = p;
  int cnt = 0;
  int first_flag = -1;
  for(;i <= q && cnt >= 0; i++){
    if(tokens[i].type == '('){
      cnt++;
    }
    else if(tokens[i].type == ')'){
      cnt--;
    }
    if(first_flag == -1 && cnt == 0) {
      first_flag = i;
    }
  }
  if(cnt != 0) {
    *success = false;
    Log("bad expr");
  }
  return first_flag == q;
}

enum {
  neg_der = 0, mul_div, add_sub, eq_neq, l_and
};

int main_op(int p, int q, bool *success) {
  int weight = 0;
  int cur_pos = -1;
  int i = p;
  for(;i <= q; i++){
    if(tokens[i].type == TK_DEC) continue;
    else if(tokens[i].type == '(') {
      int cnt = 0;
      while(i <= q){
        if(tokens[i].type == '(') {
          cnt++;
        }
        if(tokens[i].type == ')'){
          cnt--;
        }
        if(cnt == 0) break;
        i++;
      }
    }
    else if(tokens[i].type == TK_AND) {
      if(weight <= l_and) {
        weight = l_and;
        cur_pos = i;
      }
    }
    else if(tokens[i].type == TK_EQ || tokens[i].type == TK_NEQ) {
      if(weight <= eq_neq) {
        weight = eq_neq;
        cur_pos = i;
      }
    }
    else if(tokens[i].type == '+' || tokens[i].type == '-') {
      if(weight <= add_sub) {
        weight = add_sub;
        cur_pos = i;
        // Log("+-: %d", cur_pos);
      }
    }
    else if(tokens[i].type == '*' || tokens[i].type == '/') {
      // Log("*/");
      if(weight <= mul_div) {
        weight = mul_div;
        cur_pos = i;
      }
    }
    else if(tokens[i].type == TK_NEG || tokens[i].type == TK_DER) {
      // Log("neg");
      if(weight <= neg_der) {
        weight = neg_der + 1;
        cur_pos = i;
      }
    }
  }

  if(cur_pos == -1) {
    *success = false;
    Log("bad expr");
    return 0;
  }
  return cur_pos;
}

extern word_t vaddr_read(vaddr_t addr, int len);

word_t eval(int p, int q, bool *success) {
  if(p > q){
    // *success = false;
    return 0;
  }
  else if(p == q) {
    word_t val = 0;
    switch(tokens[p].type) {
      case TK_DEC: if(sscanf(tokens[p].str, "%u", &val) == 0) *success = false; break;
      case TK_REG: {
        // Log("%s", tokens[p].str);
        if(strcmp(tokens[p].str, "$0") == 0){
          // Log("TK_REG");
          val = isa_reg_str2val("$0", success);
        }
        else val = isa_reg_str2val(tokens[p].str + 1, success);
        // Log(FMT_WORD "\n", val);
        break;
      }
      case TK_HEX: if(sscanf(tokens[p].str, "%x", &val) == 0) *success = false; break;
      default: *success = false; Log("bad expr");
    }
    return val;
  }
  else if(check_parentheses(p, q, success) == true) {
    if(*success == false) return 0;
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1, success);
  }
  else {
    if(*success == false) return 0;
    int op = main_op(p, q, success);
    if(*success == false) return 0;
    word_t val1 = eval(p, op - 1, success);
    word_t val2 = eval(op + 1, q, success);
    
    switch (tokens[op].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': return val1 / val2;
      case TK_NEG: return -val2;
      case TK_AND: return val1 && val2;
      case TK_EQ: return val1 == val2;
      case TK_NEQ: return val1 != val2;
      case TK_DER: return vaddr_read(val2, 4);
      default: panic("%s not implement", tokens[op].str);
    }
  }
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    Log("make token failed");
    *success = false;
    return 0;
  }

  /* TODO: Insert cod  es to evaluate the expression. */
  // TODO();
  // Log("nr_tokens: %d", nr_token);
  return eval(0, nr_token - 1, success);
}
