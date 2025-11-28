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
#include <string.h>
enum {
  TK_NOTYPE = 256, TK_DEC,TK_HEX,TK_EQ,TK_NOTEQ,TK_DEREF,
  TK_NEG,TK_LEFTP,TK_RIGHTP,TK_ADD,TK_SUB,
  TK_MUL,TK_DIV,TK_LESSEQ,TK_GREATEREQ,
  TK_GREATER,TK_LESS,TK_OR,TK_AND,TK_REG,

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
  {"==", TK_EQ},        // equal
  {"!=", TK_NOTEQ},        // equal
  {"-",'-'},
  {"/",'/'},
  {"\\*",'*'},
  {"\\(",'('},
  {"\\)",')'},
  {"0x[0-9a-f]+",TK_HEX},
  {"[0-9]+",TK_DEC},
  {"<=",TK_LESSEQ},
  {">=",TK_GREATEREQ},
  {">",TK_GREATER},
  {"<",TK_LESS},
  {"\\|\\|",TK_OR},
  {"&&",TK_AND},
  {"\\$[a-z]*[0-9]*",TK_REG},
};

#define NR_REGEX ARRLEN(rules)
#define MAX_TOKEN 1024
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

static Token tokens[MAX_TOKEN] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

bool binary_op(int op){
  return (op==TK_MUL||op==TK_DIV||op==TK_ADD||op==TK_SUB||op==TK_EQ|| op==TK_NOTEQ||
          op==TK_LESSEQ||op==TK_GREATEREQ||op==TK_GREATER||op==TK_LESS||op==TK_OR||op==TK_AND)?true:false;
}

bool unary_op(int op){
  return (op==TK_DEREF||op==TK_NEG);
}

bool is_num_type(int typ){
  //TODO: support HEX num
  return (typ == TK_DEC||typ == TK_HEX);
}

int str2num(char* str,int typ){
  word_t res;
  int n;
  bool success;

  switch (typ)
  {
  case TK_DEC:
    n = sscanf(str,"%u",&res);
    Assert(n>=1,"%s is not a decimal num",str);
    break;
  case TK_HEX:
    n = sscanf(str,"%x",&res);
    Assert(n>=1,"%s is not a hex num",str);
    break;
  case TK_REG:
    res = isa_reg_str2val(str,&success);
    Assert(success,"%s is not a register name",str);
    break;
  default:
    Assert(0,"type %d is no a num type",typ);
    break;
  }
  return res;
}

static bool make_token(char *e) {
  int position = 0;
  int i=0;
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
        
        if (substr_len>=32){
            printf("length of %s out of 32",substr_start);
            assert(0);
            return false;
        }
        if(rules[i].token_type == TK_NOTYPE) continue; 
        strncpy(tokens[nr_token].str,substr_start,substr_len);

        switch (rules[i].token_type) {
          case '+': tokens[nr_token].type = TK_ADD; break;
          case '/': tokens[nr_token].type = TK_DIV; break;
          case '(': tokens[nr_token].type = TK_LEFTP; break;
          case ')': tokens[nr_token].type = TK_RIGHTP; break;
          case '-': 
              if (nr_token == 0 || binary_op( tokens[nr_token-1].type)||tokens[nr_token-1].type==TK_LEFTP)
                  tokens[nr_token].type = TK_NEG; 
              else
                  tokens[nr_token].type = TK_SUB; 
              break;
          case '*':
              if (nr_token == 0 || binary_op( tokens[nr_token-1].type)||tokens[nr_token-1].type==TK_LEFTP)
                  tokens[nr_token].type = TK_DEREF; 
              else
                  tokens[nr_token].type = TK_MUL; 
              break;
          case TK_DEC: 
          case TK_HEX:
          case TK_EQ: 
          case TK_NOTEQ: 
          case TK_LESSEQ:
          case TK_GREATEREQ:
          case TK_LESS:
          case TK_GREATER:
          case TK_OR:
          case TK_AND:
          case TK_REG:
              tokens[nr_token].type = rules[i].token_type; break;
          default: 
            Log("invalid token type %d",rules[i].token_type);
            break;
        }
        nr_token++;
        break;
      }
    }
    if (nr_token>=MAX_TOKEN){
        Log("num of token is limit to %d. Please shrink the expression",MAX_TOKEN);
        return false;
    }

    if (i == NR_REGEX) {
      Log("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }
  return true;
}

int find_parentheses_match(int p,int q){
    int j=p;
    int count =1;
    for (; j<=q&&count!=0;j++){
      if (tokens[j].type == TK_LEFTP) {
        count++;
      } else if (tokens[j].type == TK_RIGHTP){
          count--;
      }
      if (count ==0){
        break;
      }
      if (count<0){
          Log("parentheses invalid in [%d,%d]",p,q);
      }
    }
    return j;
}


bool check_parentheses(int p,int q){
  int count = 0;
  for (int i=p;i<=q;i++){
     if (tokens[i].type == TK_LEFTP) {
        count++;
     } else if (tokens[i].type == TK_RIGHTP){
        count--;
     }
  }
  if (count!=0){
    Log("diff of parentheses invalid \"(\":%d,  between %d, %d",count,p,q);
    assert(0);
    return false;
  }
  bool res = false;
  if (tokens[p].type == TK_LEFTP && tokens[q].type == TK_RIGHTP){
      int j = find_parentheses_match(p+1,q);
      res = (j==q)?true:false;
  }
  return res;
}

enum{
  OP_LEVEL0=256, OP_LEVEL1, OP_LEVEL2, OP_LEVEL3, OP_LEVEL4, 
  OP_LEVEL5, OP_LEVEL6, OP_LEVEL7, OP_LEVEL8,OP_LEVEL9,
};
int op_priority (int op){
  int res = -1; 
  switch (op)
  {
  case TK_MUL:
  case TK_DIV:
    res = OP_LEVEL2;
    break;
  case TK_SUB:
  case TK_ADD:
    res = OP_LEVEL3;
    break;
  case TK_LESSEQ:
  case TK_GREATEREQ:
  case TK_LESS:
  case TK_GREATER:
    res = OP_LEVEL6;
    break;
  case TK_EQ: 
  case TK_NOTEQ: 
    res = OP_LEVEL7;
    break;
  case TK_AND:
    res = OP_LEVEL8;
    break;
  case TK_OR:
    res = OP_LEVEL9;
    break;
  default:
    Assert(0,"op %d invalid\n",op);
    // assert(0);
    return -1;
  }
  return res;
}

// if q>p and tokens[a].type== tokens[b].type return b
int op_order(int a,int b){
  int priority_a = op_priority(tokens[a].type);
  int priority_b =  op_priority(tokens[b].type);
  if (priority_a == priority_b) {
    return (a>b)?a:b;
  }  
  // NOTE: a*b-a ===> '*' priority < '+' priority, return '+'"
  return (priority_a < priority_b)?b:a;
}
int main_op_pos(int p,int q){
  int op_pos = -1;
  for (int i=p;i<=q;i++){
    if (is_num_type( tokens[i].type) ) {continue;}
    else if (tokens[i].type == TK_LEFTP){
        // num of parentheses must be equal
        i = find_parentheses_match(i+1,q);
    }else if (binary_op(tokens[i].type)){
       op_pos = (op_pos<0)?i:op_order(op_pos,i);
    }else{
      Log("tokens[i].type %d, tokens[op_pos].type %d, i %d, op_pos %d",tokens[i].type, tokens[op_pos].type, i, op_pos);
    }
  }
  assert(op_pos != -1);
  return op_pos;
}

int eval(int p,int q){
  if (p>q){
    Assert(p<=q,"exprssion eval %d>%d ",p,q);
  } else if(p==q){
    return str2num(tokens[p].str,tokens[p].type);
  } else if (check_parentheses(p,q)==true) {
    return eval(p+1,q-1);
  } else if (tokens[p].type == TK_NOTYPE){
      return eval(p+1,q);
  } else if (unary_op(tokens[p].type)){
    // unary operator
    word_t res=0;
    int expr_end = 0;
    if (tokens[p+1].type == TK_LEFTP){
        expr_end = find_parentheses_match(p+2,q);
        res = eval(p+1,expr_end);
    }else if (is_num_type( tokens[p+1].type)){
        res = str2num(tokens[p+1].str,tokens[p+1].type);
        expr_end = p+1;
    } else{
        Log("unary operator invalid %s, callee %s",tokens[p].str,tokens[p+1].str);
    }
    switch (tokens[p].type){
      case TK_DEREF : 
          res = vaddr_read(res,4);
          break; 
      case TK_NEG: 
          res = -res;
          break;
    }
    char str[32];
    int n = sprintf(str,"%u",res); 
    for (int i=p;i<=expr_end;i++){
        tokens[i].type = TK_NOTYPE;
        memset(tokens[i].str,0,32*sizeof(char));
    }
    strncpy(tokens[expr_end].str,str,n);
    tokens[expr_end].type = TK_DEC;
    // replace [p,expr) with TK_NOTYPE
    return (expr_end>q)?res:eval(expr_end,q);
  } else {
    // binary operator
    int op_pos = main_op_pos(p,q);
    int val1 = eval(p,op_pos-1);
    // shortcut if val1 is 1 for "||" and 0 for "&&"
    if ((val1&&tokens[op_pos].type==TK_OR) || 
          (!val1&&tokens[op_pos].type==TK_AND) )
          return val1;
    int val2 = eval(op_pos+1,q);
    word_t val = 0;
    switch (tokens[op_pos].type) {
          case TK_ADD: val = val1 + val2; break;
          case TK_SUB: val = val1-val2; break;
          case TK_MUL: val = val1*val2; break;
          case TK_DIV: 
              Assert(val2!=0,"divide by zero");
              val = val1/val2;
              break;
          case TK_EQ:         val = val1 == val2; break;
          case TK_NOTEQ:      val = val1 != val2; break; 
          case TK_LESSEQ:     val = val1 <= val2; break;
          case TK_GREATEREQ:  val = val1 >= val2; break;
          case TK_LESS:       val = val1 < val2; break;
          case TK_GREATER:    val = val1 > val2; break;
          case TK_OR:         val = val1 || val2; break;
          case TK_AND:        val = val1 && val2; break;
          default: assert(0) ; 
    }
    return val;
  }
  return -1; // unreachable
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    return 0;
  }
  word_t res = eval(0,nr_token-1);    //eval(p,q), p,q should valid.
  memset(tokens,0,32*sizeof(Token));
  nr_token = 0;
  return res;
}
