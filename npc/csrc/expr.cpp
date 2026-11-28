#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "sdb.h"
enum {
  TK_NOTYPE = 256, TK_EQ,
  TK_NUM_DEC, TK_NUM_HEX,
  TK_L,TK_R,TK_NEG,TK_POINT,
  TK_REG,TK_NEQ,TK_AND,
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {


  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"\\-", '-'}, 
  {"\\*", '*'}, 
  {"/", '/'}, 
  {"0[xX][0-9a-fA-F]+",TK_NUM_HEX},
  {"[0-9]+",TK_NUM_DEC},
  {"\\(",TK_L},
  {"\\)",TK_R},
  {"==", TK_EQ},        // equal
  {"\\$[0-9a-zA-Z]+", TK_REG},
  {"!=", TK_NEQ},
  {"&&",TK_AND},
};

static struct{
  int token_type;
  int priority;
} priority_table[] = {
  {TK_POINT, 50},
  {TK_NEG, 50},
  {'*' , 40},
  {'/' , 40},
  {'+' , 30},
  {'-' , 30},
  {TK_EQ, 20},
  {TK_NEQ, 20},
  {TK_AND, 10},
};

static inline bool isOP(int type){
  for(int i = 0;i<9;i++){
    if(type == priority_table[i].token_type) return true;
  }
  return false;
}
static inline int getPriority(int type){
  for(int i = 0;i<9;i++){
    if(type == priority_table[i].token_type) return priority_table[i].priority;
  }
  return 0;
}

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      printf("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
      assert(0);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[256] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;
static void get_substr(char * str,int len,char* src){
  for(int i = 0;i<len;i++){
    src[i] = str[i];
  }
  src[len] = '\0';
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

        // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //     i, rules[i].regex, position, substr_len, substr_len, substr_start);

        if(rules[i].token_type != TK_NOTYPE){
          get_substr(substr_start,substr_len,tokens[nr_token].str);
          tokens[nr_token].type = rules[i].token_type;
          nr_token++;
        }
        position += substr_len;
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }
  //处理负数和指针操作
  for(int i = 0;i<nr_token;i++){
    if(tokens[i].type == '-'){
      if(i == 0 || (tokens[i-1].type!=TK_NUM_DEC &&
         tokens[i-1].type!=TK_NUM_HEX && tokens[i-1].type!=TK_R)){// check '-'
        tokens[i].type = TK_NEG;
        // printf("- %d\n",i);
      }
    }else if(tokens[i].type == '*'){
      if(i == 0 || (tokens[i-1].type!=TK_NUM_DEC &&
         tokens[i-1].type!=TK_NUM_HEX && tokens[i-1].type!=TK_R)){// check '*'
        tokens[i].type = TK_POINT;
        // printf("* %d\n",i);
      }
    }
  }
  //检查括号是否匹配
  int cnt = 0;
  for(int i = 0;i<nr_token;i++){
    if(tokens[i].type == TK_L){
      cnt++;
    }else if(tokens[i].type == TK_R){
      cnt--;
    }
    if(cnt < 0) return false;
  }
  if ( cnt == 0) return true;
  else return false;
}

static bool check_parentheses(int p,int q){
  int cnt = 0;
  if(tokens[p].type != TK_L || tokens[q].type != TK_R) return false; 
  while(p <= q){
    if(tokens[p].type == TK_L){
      cnt++;
    }else if(tokens[p].type == TK_R){
      cnt--;
    }
    if(cnt < 0) return false;
    if(p < q && cnt == 0) return false;
    p++;
  }
  if ( cnt == 0) return true;
  else return false;
}

static int get_main_op(int p,int q){
  int idx = p;
  int res = p;
  int cnt = 0;
  int main_op = 0;
  
  while(idx <= q){
    if(isOP(tokens[idx].type)){
        if( cnt == 0 ){
          int priority = getPriority(tokens[idx].type);
          if(main_op == 0 || getPriority(main_op) >= priority){
            res = idx;
            main_op = tokens[idx].type;

          }
        }
    }else if(tokens[idx].type == TK_L) cnt++;
    else if(tokens[idx].type == TK_R) cnt--;
    idx++;
  }
  return res;
}

static void get_expr_val(int p,int q,uint32_t* val,bool*success){
  if(p > q){
    *success=false;
    return;
  }
  else if (p == q) {
    if(tokens[p].type == TK_NUM_DEC || tokens[p].type == TK_NUM_HEX 
      || tokens[p].type == TK_REG){
      uint32_t num;
      if(tokens[p].type == TK_NUM_DEC){
        num = atoi(tokens[p].str);
        *val = num;
        *success=true;
      }
      else if(tokens[p].type == TK_NUM_HEX){
        sscanf(tokens[p].str,"%x",&num);
        *val = num;
        *success=true;
      }
      else {
        num = isa_reg_str2val(tokens[p].str+1,success);
        *val = num;
      }
      return;
    }else return;
  }
  else if (check_parentheses(p, q) == true) {
    bool su;
    get_expr_val(p + 1, q - 1,val,&su);
    *success=su;
    return;
  }
  else {
    int main_op = get_main_op(p,q);
    // printf("p %d q %d main_op %d\n",p,q,main_op);
    uint32_t val1,val2;
    bool su1,su2;
    if(tokens[main_op].type==TK_NEG || tokens[main_op].type==TK_POINT){
      get_expr_val(main_op+1,q, &val1,&su1);
      if(!(*success=su1)) return;
      if(tokens[main_op].type==TK_NEG) *val = -val1;
      else *val = mem_read(val1);
    }else{
      get_expr_val(p,main_op-1, &val1,&su1);
      if(!(*success=su1)) return;
      get_expr_val(main_op+1,q, &val2,&su2);
      if(!(*success=su2)) return;
      switch (tokens[main_op].type)
      {
        case '+': *val = val1 + val2; break;
        case '-': *val = val1 - val2; break;
        case '*': *val = val1 * val2; break;
        case '/': 
          if(val2 == 0){
            printf("Division by zero\n");
            *success=false;
          }else *val = val1 / val2; 
          break;
        case TK_AND: *val = (val1 && val2); break;
        case TK_EQ: *val = (val1 == val2); break;
        case TK_NEQ: *val = (val1 != val2); break;
        default: assert(0);
      }
    }
    return;
  }
}

uint32_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  /* TODO: Insert codes to evaluate the expression. */
  uint32_t res;
  get_expr_val(0,nr_token-1,&res,success);
  return res;
}
