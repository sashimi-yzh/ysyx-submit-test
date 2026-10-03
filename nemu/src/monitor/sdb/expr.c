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
#include <isa.h>
#include <math.h>
#include <memory/vaddr.h>
/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, TK_EQ,TK_NOTEQ,TK_LOGIC_AND,
  TK_DIGIT,  TK_HEX_DIGIT,TK_REG_NAME,TK_DEREF,TK_NEGTIVE,

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
    {"0x[0-9a-fA-F]+u?",TK_HEX_DIGIT},
    {"(\\$){1,2}[a-zA-Z0-9_]+",TK_REG_NAME},
  {"==", TK_EQ},        // equal
    {"!=",TK_NOTEQ},
    {"&&",TK_LOGIC_AND},
  {"\\+", '+'},         // plus
    {"\\-",'-'},
    {"\\*",'*'},
    {"/",'/'},
    {"\\(",'('},
    {"\\)",')'},
    {"[0-9]+u?",TK_DIGIT},
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
static bool express_error_flag=0;
static Token tokens[65536] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;
int check_parentheses(int p, int q);
word_t eval(int p, int q);

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

        //Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //   i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        if(rules[i].token_type==TK_NOTYPE)
            break;
        if(nr_token>=65536){
            printf("Error expression: too many tokens\n");
            return false;
        }
        tokens[nr_token].type=rules[i].token_type;
        switch (rules[i].token_type) {
            case TK_REG_NAME:
            case TK_HEX_DIGIT:
            case TK_DIGIT:  if(substr_len>=32){
                                printf("Error expression: substr too long\n");
                                return false;
                            }
                            strncpy(tokens[nr_token].str,substr_start,substr_len);
                            tokens[nr_token].str[substr_len]='\0';
                            break;

            default: ;
        }
        nr_token++;
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
int is_op(int type){
    return (type!=TK_DIGIT)&&(type!=TK_HEX_DIGIT)&&(type!=TK_REG_NAME)&&(type!=')');
}
int main_operator(int p,int q){
    int ptype;
    int right=0;
    int flag=-1;int op_rank=12;
    for(;p<=q;p++){
        ptype=tokens[p].type;
        if(ptype=='('){
            right++;
        }else if(ptype==')'){
            right--;
        }else if(right==0){
            if(ptype=='*'||ptype=='/'){
                if(op_rank>=9){
                    flag=p;
                    op_rank=9;
                }
            }else if(ptype=='+'||ptype=='-'){
                if(op_rank>=8){
                    op_rank=8;
                    flag=p;
                }
            }else if(ptype==TK_EQ||ptype==TK_NOTEQ){
                if(op_rank>=5){
                    flag=p;
                    op_rank=5;
                }
            }else if(ptype==TK_LOGIC_AND){
                if(op_rank>=1){
                    flag=p;
                    op_rank=1;
                }
            }else if(ptype==TK_DEREF||ptype==TK_NEGTIVE){
                if(op_rank>11){//从右到左
                    flag=p;
                    op_rank=11;
                }
            }   
        }
    }

    return flag;
}
word_t eval(int p, int q) {
    if(express_error_flag){
        return 0;
    }
    if (p > q) {
        express_error_flag=1;
        return 0;
    /* Bad expression */
    }
    else if (p == q) {
        int ptype=tokens[p].type;
        if(ptype==TK_DIGIT){
            return strtoul(tokens[p].str,NULL,10);
        }else if(ptype==TK_HEX_DIGIT){
            return strtoul(tokens[p].str,NULL,16);
        }else if(ptype==TK_REG_NAME){
            bool success;
            word_t ret=isa_reg_str2val(tokens[p].str+1,&success);
            if(success==true)
                return ret;
        }
        express_error_flag=1;
        return 0;
        
    }
    else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
        return eval(p + 1, q - 1);
    }
    else {
        if(express_error_flag){
            return 0;
        }
        int op = main_operator(p,q);
        if(tokens[op].type==TK_DEREF){
            return vaddr_read(eval(p+1,q),4);
        }else if(tokens[op].type==TK_NEGTIVE){
            return -eval(p+1,q);
        }
        if(op==p||op==q){
            express_error_flag=1;
            return 0;
        }
        word_t val1 = eval(p, op - 1);
        word_t val2;
        if(tokens[op].type==TK_LOGIC_AND){
            if(val1==0)
                return 0;
        }
        val2 = eval(op + 1, q);
        switch (tokens[op].type) {
        case '+': return val1+val2;
        case '-': return val1-val2;
        case '*': return val1*val2;
        case '/':   if(val2==0){
                        express_error_flag=1;
                        return 0;
                    }else 
                    return val1/val2;
        case TK_EQ:return val1==val2;
        case TK_NOTEQ:return val1!=val2;
        case TK_LOGIC_AND:return val1&&val2;
        default: assert(0);
    }
  }

}
int check_parentheses(int p, int q){
    int right=0;
    int notflag=0;
    while(p<=q){
        if(tokens[p].type=='('){
            right++;
        }else if(tokens[p].type==')'){
            right--;
            if(right<0){
                express_error_flag=1;
                return false;
            }
        }
        if(right==0&&p!=q){
            notflag=1;
        }
        p++;
    }
    if(right!=0){
        express_error_flag=1;
        return false;
    }
    if(notflag)
        return false;
    return true;
}
word_t expr(char *e, bool *success) {
    if (!make_token(e)) {
        *success = false;
        return 0;
    }

  /* TODO: Insert codes to evaluate the expression. */
    int i;
    for (i = 0; i < nr_token; i ++) {
        if (i == 0 || is_op(tokens[i - 1].type) ) {
            if(tokens[i].type == '*')
                tokens[i].type = TK_DEREF;
            else if(tokens[i].type=='-')
                tokens[i].type = TK_NEGTIVE;
        }
    }
    express_error_flag=0;
    word_t t=eval(0,nr_token-1);
    if(express_error_flag==1){
        *success=false;
    }else{
        *success=true;
    }
    return t;
}
