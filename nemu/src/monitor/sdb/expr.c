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
#include <cpu/cpu.h>

#define MAX_TOKENS 64 

enum {
  TK_NOTYPE = 256, 
  PLUS      = 0,
  TK_EQ     = 1,
  MINUS     = 2,
  MULTI     = 3,
  DIV       = 4,
  LEFT      = 5,
  RIGHT     = 6,
  NUM       = 7,
  LEQ       = 8,
  NOTEQ     = 9,
  REQ       = 10,
  REG       = 11,
  OR        = 12,
  AND       = 13,
  PC        = 14,
  HEX       = 15,

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
  {"\\+", PLUS},         // plus，匹配后返回ASCII码值
  {"==", TK_EQ},        // equal
  {"\\-", MINUS},         // minus
  {"\\*", MULTI},         // multi
  {"\\/", DIV},         // div
  {"\\(", LEFT},
  {"\\)", RIGHT},
  {"[A-FXa-fx0-9]+", NUM},
  {"\\<\\=", LEQ},
  {"\\!\\=", NOTEQ},
  {"\\>\\=", REQ},
  {"\\$\\$0|\\$ra|\\$sp|\\$gp|\\$tp|\\$t[0-6]|\\$s[0-9]|\\$s1[0-1]|\\$a[0-7]", REG},
  {"\\|\\|", OR},
  {"\\&\\&", AND},
  {"\\p\\c",PC},
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {//编译正则表达式
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

static Token tokens[64] __attribute__((used)) = {};//即使某个变量或函数没有被显式使用，也不要优化掉它。
static int nr_token __attribute__((used))  = 0;

int char2int(char s[]){
    int s_size = strlen(s);
    int res = 0 ;
    for(int i = 0 ; i < s_size ; i ++)
    {
	    res += s[i] - '0';
      res *= 10;
    }
    res /= 10;
    return res;
}

void int2char(int x, char str[]) {
    int tmp_index = 0;
    int tmp_x = x;
    int x_size = 0, flag = 1;

    if (x < 0) {
        str[tmp_index++] = '-';
        x = -x;
    }

    tmp_x = x;
    while (tmp_x) {
        tmp_x /= 10;
        x_size++;
        flag *= 10;
    }
    flag /= 10;


    if (x == 0) {
        str[tmp_index++] = '0';
    }

    while (x) {
        int a = x / flag;
        x %= flag;
        flag /= 10;
        str[tmp_index++] = a + '0';
    }

    str[tmp_index] = '\0';
}

static void remove_first_char(char *str) {
  if (str == NULL || *str == '\0') {
      return;
  }

  size_t len = strlen(str);
  
  if (len == 0) {
      return; 
  }

  memmove(str, str + 1, len); 
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
        // char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //     i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        // printf("%d %d\n", i, rules[i].token_type);

        switch (rules[i].token_type) {

          case(TK_NOTYPE): 
              break;

          case(PLUS): 
              tokens[nr_token].type = PLUS;
              strcpy(tokens[nr_token].str, "+");
              nr_token ++;
              break;

          case(TK_EQ):
              tokens[nr_token].type = TK_EQ;
              strcpy(tokens[nr_token].str, "==");
              nr_token ++;
              break;

          case(MINUS):
              tokens[nr_token].type = MINUS;
              strcpy(tokens[nr_token].str, "-");
              nr_token ++;
              break;

          case(MULTI):
              tokens[nr_token].type = MULTI;
              strcpy(tokens[nr_token].str, "*");
              nr_token ++;
              break;

          case(DIV): 
              tokens[nr_token].type = DIV;
              strcpy(tokens[nr_token].str, "/");
              nr_token ++;
              break;

          case(LEFT): 
              tokens[nr_token].type = LEFT;
              strcpy(tokens[nr_token].str, "(");
              nr_token ++;
              break;

          case(RIGHT): 
              tokens[nr_token].type = RIGHT;
              strcpy(tokens[nr_token].str, ")");
              nr_token ++;
              break;

          case(NUM): 
              tokens[nr_token].type = NUM;
              strncpy(tokens[nr_token].str, &e[position - substr_len], substr_len);
              nr_token++;
              break;

          case(REG): 
              tokens[nr_token].type = REG;
              strncpy(tokens[nr_token].str, &e[position - substr_len], substr_len);
              nr_token ++;
              break;

          case(LEQ):
              tokens[nr_token].type = LEQ;
              strcpy(tokens[nr_token].str, "<=");
              nr_token ++;
              break;

          case(REQ):
              tokens[nr_token].type = REQ;
              strcpy(tokens[nr_token].str, ">=");
              nr_token ++;
              break;

          case(NOTEQ):
              tokens[nr_token].type = NOTEQ;
              strcpy(tokens[nr_token].str, "!=");
              nr_token ++;
              break;

          case(OR):
              tokens[nr_token].type = OR;
              strcpy(tokens[nr_token].str, "||");
              nr_token ++;
              break;

          case(AND):
              tokens[nr_token].type = AND;
              strcpy(tokens[nr_token].str, "&&");
              nr_token ++;
              break;
          
          case(PC):
              tokens[nr_token].type = PC;
              strcpy(tokens[nr_token].str, "PC");
              nr_token ++;
              break;

          default: 
              printf("no match\n");
              break;
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

static void token_special(){

  /*reg*/
  for(int i = 0; i < nr_token; i ++)
  {
	  if(tokens[i].type == REG)
	  {
	    bool flag = true;

      remove_first_char(tokens[i].str);
	    int tmp = isa_reg_str2val(tokens[i].str, &flag);
      
      // printf("316 %d\n", flag);
	    if(flag){
		    int2char(tmp, tokens[i].str);
        tokens[i].type = NUM;
      }
      else{
		    printf("Transfrom error. \n");
		    assert(0);
	    }
    }
  }

  /*
  * TODO
  * PC
  * */
  for(int i = 0; i < nr_token; i ++)
  {
	  if(tokens[i].type == PC)
	  {

      vaddr_t pc = cpu_state();
      snprintf(tokens[i].str, 11, "0x%08X", pc);
      tokens[i].type = HEX;
    }
  }
  
  //内存
 
  for(int i = 0 ; i < nr_token ; i ++)
  {
    if((tokens[i].type == MULTI && i > 0 && tokens[i-1].type != NUM && tokens[i-1].type != RIGHT && tokens[i-1].type != REG && tokens[i+1].type == NUM)
	    ||(tokens[i].type == MULTI && i == 0))
	  {
      tokens[i].type = TK_NOTYPE;

      paddr_t addr = 0;
      sscanf(tokens[i+1].str,"%x", &addr);
      // printf("%d\n",addr);
      word_t value = paddr_read(addr,4);
      snprintf(tokens[i+1].str, 11, "0x%08X", value);
      // printf("mark\n");
      // printf("%s\n",tokens[i+1].str);
      // for(int j = 0 ; j < nr_token ; j ++){
      //   if(tokens[j].type == TK_NOTYPE){
      for(int k = i + 1 ; k < nr_token ; k ++){
        tokens[k - 1] = tokens[k];
      }
      nr_token -- ;
      tokens[i].type = HEX;
    }    	    
  }

  /*
   * NUM
  */
  for(int i = 0 ; i < nr_token ; i ++)
  {
    if(tokens[i].type == NUM)
    {
      if(tokens[i].str[0] == '0' && (tokens[i].str[1] == 'x'|| tokens[i].str[1] == 'X'))// Hex num
      {
        tokens[i].type = HEX;
      }
      // else
    }
  }

  /*
   * 负数
   */

  for(int i = 0 ; i < nr_token ; i ++)
  {
	  if((tokens[i].type == MINUS && i > 0 && tokens[i-1].type != NUM && tokens[i-1].type != RIGHT && tokens[i+1].type == NUM)
      ||(tokens[i].type == MINUS && i == 0))
	  {
	    //printf("%s\n", tokens[i+1].str);
	    tokens[i].type = TK_NOTYPE;
	    //tokens[i].str = tmp;
	    for(int j = 31 ; j > 0 ; j --)
      {
		    tokens[i+1].str[j] = tokens[i+1].str[j-1];
	    }
	    tokens[i+1].str[0] = '-';
	    // printf("%s\n", tokens[i+1].str);
	    for(int j = 0 ; j < nr_token ; j ++){
		    if(tokens[j].type == TK_NOTYPE)
		    {
		      for(int k = j + 1; k < nr_token; k ++){
			      tokens[k - 1] = tokens[k];
		      }
		      nr_token -- ;
		    }
	    }
	  }
  }
}

static bool check_parentheses(int p, int q)// 0,12
{
  if(tokens[p].type != LEFT  || tokens[q].type != RIGHT){
    return false;
  }
  int match = 0;
  for (int i = p + 1; i < q; i++){
    if(tokens[i].type == LEFT){
      match++;
    }
    else if(tokens[i].type == RIGHT){
      match = match - 1;
    }
    if(match < 0){
      return false;
    }
  }
  if(match == 0){
    return true;
  } 
  else{
    return false;
  }
}


static bool is_division0 = false;

uint32_t eval(int p, int q) {
  if (p > q) {
    /* Bad expression */
    // printf("%d %d %d\n", nr_token, p, q);
    printf("Bad expression\n");
    assert(0);
    return -1;
  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
    if(tokens[p].type == HEX){
      int tmp = strtol(tokens[p].str, NULL, 16);
      return (uint32_t)tmp;
    }
    else {
      return atoi(tokens[p].str);
    }
  }
  else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    // printf("%d %d\n", p, q);
    return eval(p + 1, q - 1);
  }
  else {
    int op = -1;//the position of 主运算符 in the token expression;
    bool flag = false;//判断是否是加减号
    // int index;//特殊情况

    //搜索主运算符的位置
    for(int i = p; i < q; i++){
      if(tokens[i].type == LEFT)//括号内最后算
        {
          int a = i;

          while(check_parentheses(a,i) != true){
            i++;
          }
        }
      if(!flag && tokens[i].type == LEQ)
        {
          flag = true;
          op = (op > i) ? op : i;
        }
      if(!flag && tokens[i].type == REQ)
        {
          flag = true;
          op = (op > i) ? op : i;
        }
      if(!flag && tokens[i].type == TK_EQ)
        {
          flag = true;
          op = (op > i) ? op : i;
        }
      if(!flag && tokens[i].type == NOTEQ)
        {
          flag = true;
          op = (op > i) ? op : i;
        }
      if(!flag && tokens[i].type == OR)
        {
          flag = true;
          op = (op > i) ? op : i;
        }
      if(!flag && tokens[i].type == AND)
        {
          flag = true;
          op = (op > i) ? op : i;
        }
      if(!flag && tokens[i].type == NOTEQ)
        {
          flag = true;
          op = (op > i) ? op : i;
        }

      if(((tokens[i].type == PLUS) || (tokens[i].type == MINUS))){
        flag = true;
        // op = i;
        op = (op > i) ? op : i;
      }
      if(!flag && ((tokens[i].type == MULTI) || (tokens[i].type == DIV))){
        // op = i;
        op = (op > i) ? op : i;
      }
    }
    // printf("511 %d\n",q);
    int op_type =  tokens[op].type;
    // printf("513 %d %d\n",p, op - 1);
    uint32_t val1 = eval(p, op - 1);
    // printf("515 %d %d\n",op + 1, q);
    uint32_t val2 = eval(op + 1, q);

    switch (op_type) {
      case PLUS: 
        return val1 + val2;
      case MINUS: 
        return val1 - val2;
      case MULTI: 
        return val1 * val2;
      case DIV: 
        if (val2 == 0){
          printf("division can't be 0\n");
          is_division0 = true;
          return -1;
        }
        else{
          // printf("%d\n",(0 - val1));
          return (int32_t)val1 / (int32_t)val2;
        }
      case TK_EQ:
        return val1 == val2;
      case LEQ:
        return val1 <= val2;
      case REQ:
        return val1 >= val2;
      case AND:
        return val1 && val2;
      case OR:
        return val1 || val2;
      case NOTEQ:
        return val1 != val2;
      default: assert(0);
    }
  }
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  is_division0 = false;

  token_special();//特殊情况
  word_t result = 0;
  // printf("%d\n", nr_token);
  // for (int i = 0; i < nr_token; i++){
  //   printf("%d %s\n",tokens[i].type, tokens[i].str);
  // }

  if(check_parentheses(0, nr_token - 1) == false){
    printf("wrong parentheses used\n");
    return -1;
  }

  // /* TODO: Insert codes to evaluate the expression. */
  result = eval(0, nr_token - 1);
  *success = true;
  for (int i = 0; i < nr_token; i++){
    tokens[i].type = 0;
    memset(tokens[i].str, '\0', sizeof(tokens[i].str));
  }
  return result;
  
}

bool division(){
  return is_division0;
}


static int index_buf = 0;
static char buf[100] __attribute__((used)) = {};
static int token_count = 0;
static int depth = 0; 

static int choose(int n)
{
	return rand() % n;
}

static void gen(char c)
{
  // if(token_count >= MAX_TOKENS - 1){
  //   return;
  // }
	buf[index_buf] = c;
  index_buf++;
  token_count ++;
}

static void gen_num()
{
  // if(token_count >= MAX_TOKENS - 1){
  //   return;
  // }
	int num = rand() % 100;
  if(num < 10){
    char c = num + '0';
    buf[index_buf] = c;
    index_buf ++;
  }
  else {
    int tmp1 = num % 10;
    int a = num / 10;
    int tmp2 = a % 10;
    char c1 = tmp1 + '0';//gewei
    char c2 = tmp2 + '0';//shiwei
    buf[index_buf] = c2;
    index_buf ++;
    buf[index_buf] = c1;
    index_buf ++;
  }
  token_count ++;
}

static void gen_rand_op()
{
	char op[3] = {'+', '-', '*'};
	int pos = rand() % 3;
	buf[index_buf++] = op[pos];
  token_count ++;
}

void gen_rand_expr() {
  int a = 0;
  if(token_count < 20 && depth < 5){
    a = choose(5);
  }
  else{
    a = 0;
  }
  if(a == 0 || a == 1){
    gen_num();
    return; 
  }
  else if(a == 2){
    depth ++;
    gen('(');
    gen_rand_expr(); 
    gen(')');
    return;
  }
  else{
    gen_rand_expr(); 
    gen_rand_op();
    gen_rand_expr();
    return; 
  }
}

char* get_expr()
{ 
  buf[index_buf] = '(';
  index_buf ++;
  token_count ++;
  gen_rand_expr();
  buf[index_buf ++] = ')';
  buf[index_buf ++] = '\0';
  return buf;
}

void clean(){
  for(int i = 0; i < index_buf; i++){
    buf[i] = '\0'; 
  }
  index_buf = 0;
  token_count = 0;
  depth = 0;
}

