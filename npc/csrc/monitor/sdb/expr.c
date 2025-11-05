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


/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <fmt-def.h>
#include <common.h>
#include <isa.h>
#include <memory/vaddr.h>
//#define LOG 

enum {
  TK_NOTYPE = 256, TK_EQ,

  /* TODO: Add more token types */
  //TODO FINISHED
  TK_NUM,   //数字 
  TK_LP = '(',   //左括号
  TK_RP = ')',   //右括号
  TK_PLUS ='+',  //加
  TK_MINUS = '-',//减
  TK_MUL = '*',  //乘
  TK_DIV = '/',  //除

  TK_PNT,       //指针解引用
  TK_NEQ,       //不等于!=
  TK_AND,       //与&& 
  TK_OR,        //或||
  TK_NOT = '!', //非 !
  TK_REG,       //寄存器，以$开头
  TK_HEX,       //十六进制数
  TK_LE,        //小于等于 less equal
  TK_GE,        //大于等于 greater equal
  TK_GT = '>',  //大于
  TK_LT = '<',  //小于
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
  //TODO FINISHED
  {" +", TK_NOTYPE},       // spaces
  {"\\+", TK_PLUS},        // plus
  {"==", TK_EQ},           // equal

  {"-", TK_MINUS},      // 减
  {"\\*", TK_MUL},      // 乘
  {"/", TK_DIV},        // 除
  {"\\(", TK_LP},       //左括号
  {"\\)", TK_RP},       //右括号
  

  {"!=", TK_NEQ},       //不等于
  {"&&", TK_AND},       //与
  {"\\|\\|", TK_OR},    //或
  {"!", TK_NOT,},       //非
  {"0[xX][0-9a-fA-F]+", TK_HEX},  //十六进制

  // 数字必须放在十六进制后面，否则"0xa1"会被先识别为"0"" 
  {"[0-9]+", TK_NUM},   //数字
  {"\\$\\$?[a-zA-Z0-9]*", TK_REG}, //寄存器，以$开头, 两个$用于匹配$$0
  {"<=", TK_LE},        //小于等于
  {">=", TK_GE},        //大于等于

 // 大于和小于必须放在大于等于和小于等于后面，否则">="会被先识别为">"" 
  {">", TK_GT},         //大于   
  {"<", TK_LT},         //小于
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */ 
void init_regex() {   //在init_sdb中调用
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

static Token tokens[65535] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;



bool check_parentheses(int p, int q){
  //如果最左边和最右边不是完整的括号，返回false
  if(tokens[p].type != TK_LP || tokens[q].type != TK_RP)
    return false;

  //但是也有可能出现(1+2)(3+4)的情况，所以再做判断
  int LP_unpaired = 0; 
  for(int i = p+1; i<q; i++){
    switch(tokens[i].type){
      case TK_LP: LP_unpaired++; break;
      case TK_RP: LP_unpaired--; break;
      default: break;
    }
    if(LP_unpaired == -1) return false;
  }
  if(LP_unpaired != 0)
    return false;  
  
  return true;
}



static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i++) {
      //匹配成功 && 匹配的字符串正好是当前开始的位置
      //int  ret1 ;
      //ret1 = regexec(&re[i], e + position, 1, &pmatch, 0);
      //if(ret1 == 0 && pmatch.rm_so == 0);
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        
        int substr_len = pmatch.rm_eo;

        //printf("ENTER IF\n");

#ifdef LOG
        char *substr_start = e + position;
        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);
#endif
        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */ //TODO FINISHED 
        switch (rules[i].token_type) {
          case TK_NOTYPE: break; //tokens[nr_token++].type = TK_NOTYPE; break;
          case TK_EQ:    tokens[nr_token++].type = TK_EQ;    break;
          case TK_LP:    tokens[nr_token++].type = TK_LP;    break;
          case TK_RP:    tokens[nr_token++].type = TK_RP;    break;
          case TK_PLUS:  tokens[nr_token++].type = TK_PLUS;  break;
          case TK_MINUS: tokens[nr_token++].type = TK_MINUS; break;
          case TK_MUL:   tokens[nr_token++].type = TK_MUL;   break;
          case TK_DIV:   tokens[nr_token++].type = TK_DIV;   break;
          
          case TK_NEQ:   tokens[nr_token++].type = TK_NEQ;   break;
          case TK_AND:   tokens[nr_token++].type = TK_AND;   break;
          case TK_OR:    tokens[nr_token++].type = TK_OR;    break;
          case TK_NOT:   tokens[nr_token++].type = TK_NOT;   break;
          case TK_GT:   tokens[nr_token++].type = TK_GT;   break;
          case TK_LT:   tokens[nr_token++].type = TK_LT;   break;
          case TK_LE:    tokens[nr_token++].type = TK_LE;    break;
          case TK_GE:   tokens[nr_token++].type = TK_GE;   break;

          case TK_HEX: 
            tokens[nr_token].type = TK_HEX; 
            //把匹配到的十六进制字符串复制到到str中
            strncpy(tokens[nr_token].str, &e[position-substr_len], substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++; 
            break;
          case TK_REG: 
            tokens[nr_token].type = TK_REG; 
            //把匹配到的寄存器名称复制到到str中
            strncpy(tokens[nr_token].str, &e[position-substr_len], substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++; 
            break;

          case TK_NUM: 
            tokens[nr_token].type = TK_NUM; 
            //把匹配到的数字字符串复制到到str中
            strncpy(tokens[nr_token].str, &e[position-substr_len], substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++; 
            break;
          default: printf("Un recognized rules: %d", rules[i].token_type);
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }
  //printf("nr_token= %d \n",nr_token);
  return true;
}

void print_tokens()
{
  for(int i=0; i<nr_token; i++)
  {
    printf("%d: type: %d ( '%c' ),\t str: %s\n", i, tokens[i].type, (char)tokens[i].type, tokens[i].str);
  }
}

//运算符优先级到整数的映射，优先级越高，映射得到的数值越小
static inline int order_map(int type)
{
  //返回数值依照：https://blog.csdn.net/DZRYWYBL/article/details/90679557 
  switch (type)
  {
    case TK_NOT:   case TK_PNT:  return 2;
    case TK_MUL:   case TK_DIV:  return 3;
    case TK_MINUS: case TK_PLUS: return 4; 
    case TK_LT:    case TK_GT:   case TK_LE: case TK_GE: return 6;
    case TK_NEQ:   case TK_EQ:   return 7;
    case TK_AND:   return 11;
    case TK_OR:    return 12;

    default:
      return -1;
  }
}

//type1的运算符优先级是否高于type2
bool higher_order(int type1, int type2)
{
  return order_map(type1) - order_map(type2) < 0;
}

//函数的主体从文档中复制过来
word_t eval(int p, int q) {
  if (p > q) {
    /* Bad expression */
    printf("Bad Expression!\n");
    assert(0);
    return 0;
  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
    assert(p>=0 && p<nr_token);
    if(tokens[p].type == TK_NUM)
      return strtol(tokens[p].str, NULL, 10);
    else if (tokens[p].type == TK_HEX){
      word_t num;
      sscanf(tokens[p].str, "" FMT_WORD_HEX "", &num);
      return num;
    }
    else{
      assert(0);
    }
  }
  else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1);
  }
  else {

    int op = -1; //op = the position of 主运算符 in the token expression;
    int lp_num = 0; //没配对的左括号的数量
    for(int i=p; i<=q; i++)
    {
      switch (tokens[i].type)
      {
        case TK_LP: 
        lp_num++;
        while(lp_num != 0 && i<=q){
          if(tokens[++i].type == TK_LP)
            lp_num++;
          else if(tokens[i].type == TK_RP)
            lp_num--;
        }
        
        case TK_NUM:  break;

        case TK_PLUS: case TK_MINUS: case TK_MUL:  case TK_DIV: 
        case TK_OR:   case TK_AND:   case TK_NOT:  case TK_EQ:
        case TK_NEQ:  case TK_LE:    case TK_GE:   case TK_LT:
        case TK_GT:   case TK_PNT:
          if(op < 0){
            op = i;
            break;
          }
          if(higher_order(tokens[op].type,tokens[i].type))
            op = i; 
          break;
      default:
        break;
      }
    }

    word_t val1 = 0, val2;
    
    assert(op>=0 && op<nr_token);

    //如果表达式只有右值的话，就不用计算val1
    if( tokens[op].type != TK_PNT){   
      val1 = eval(p, op - 1);
    }
    val2 = eval(op + 1, q);

  
    switch (tokens[op].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': return (val2 != 0 ? (val1 / val2) : 0);
      case TK_EQ:  return (val1 == val2);
      case TK_AND: return (val1 && val2);
      case TK_OR:  return (val1 || val2);
      case TK_NOT: return (!val2);
      case TK_NEQ: return (val1 != val2);
      case TK_LE:  return (val1 <= val2);
      case TK_GE:  return (val1 >= val2);
      case TK_LT:  return (val1 < val2);
      case TK_GT:  return (val1 > val2);
      case TK_PNT: 
        return vaddr_read(val2, 1);
      default: assert(0);
    }
  }
}

void tokens_clear()
{
  for(int i=0; i<sizeof(tokens)/sizeof(tokens[0]); i++)
  {
    tokens[i].str[0] = '\0';
    tokens[i].type = 0;
  }
}


word_t expr(char *e, bool *success) {
  tokens_clear();
  
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  
  

  /* TODO: Insert codes to evaluate the expression. */


  //指针解引用判断
  for (int i = 0; i < nr_token; i ++) {
    if (tokens[i].type == TK_MUL && 
        (i == 0 || tokens[i - 1].type == TK_LP || tokens[i-1].type == TK_EQ   ||
         tokens[i - 1].type == TK_PLUS || tokens[i - 1].type == TK_MINUS ||
         tokens[i - 1].type == TK_DIV  || tokens[i - 1].type == TK_AND   ||
         tokens[i - 1].type == TK_NOT  || tokens[i - 1].type == TK_OR )) {
      tokens[i].type = TK_PNT;
    }
  }

  //寄存器取值
  for (int i = 0; i < nr_token; i++){
    if(tokens[i].type == TK_REG){
      bool succ = false;
      word_t value = isa_reg_str2val(tokens[i].str, &succ);
      if(!succ)
        printf("Can not get value of: %s.  Default set to ZERO!\n", tokens[i].str);
      sprintf(tokens[i].str, "" FMT_WORD_HEX "", value);
      tokens[i].type = TK_HEX;  //可以把寄存器取值后，当作十六进制来处理
    }
  }

  *success = true;
 // print_tokens();
  
  return  eval(0,nr_token-1);
}
