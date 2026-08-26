
#include <regex.h>
#include <errno.h>
#include "sdb.h"
#include "common.h"
#include "mem.h"
#include "cpu.h"

enum {
  TK_NOTYPE = 256, TK_EQ, TK_NEQ, TK_NUM_10 , TK_DEREF, TK_AND, TK_REG, TK_NUM_16
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {"\\${1,2}\\w+", TK_REG},        // $reg
  {"\\(", '('},         // (
  {"\\)", ')'},         // )
  {" +", TK_NOTYPE},    // spaces
  {"\\*", '*'},         // times
  {"\\/", '/'},         // div
  {"\\+", '+'},         // plus
  {"\\-", '-'},         // minus
  {"\\=\\=", TK_EQ},        // equal
  {"\\!\\=", TK_NEQ},        // not equal
  {"\\&\\&", TK_AND},        // and
  //{"\\*", DEREF},        // dereference
  {"0[xX][AaBbCcDdEeFf0123456789]+", TK_NUM_16},// number16
  {"[0-9]+", TK_NUM_10}// number10
  
};

#define NR_REGEX ARRLEN(rules)
uint32_t eval(int p, int q, bool *success);
int parse_uint32(const char *str, uint32_t *result);
bool check_parentheses(int p, int q,bool* success);
static regex_t re[NR_REGEX] = {};


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
  bool success=true;
  nr_token = 0;
  while (e[position] != '\0') {
    
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;
        position += substr_len;
        
        if(rules[i].token_type!=TK_NOTYPE){
          tokens[nr_token].type=rules[i].token_type;
          strncpy(tokens[nr_token].str,substr_start,substr_len);
          tokens[nr_token].str[substr_len]='\0';
          nr_token++;
        }
        if(nr_token!=0){
          switch (tokens[nr_token-1].type) {
            case '-':
              if(nr_token!=1){
                if(
                  ! (tokens[nr_token-2].type==')' 
                  || tokens[nr_token-2].type==TK_NUM_10
                  || tokens[nr_token-2].type=='(')
                ){
                  printf("Error expression '-'\n");
                  return false;
                }
              }
              break;
            case '+':
              //
              break;
            case '*':

              break;
            case '/':

              break;
            case TK_NUM_10:
              if(nr_token==2){
                if(tokens[0].type=='-'){
                  tokens[0].type=TK_NUM_10;
                  strncpy(tokens[0].str+1,substr_start,substr_len);
                  tokens[0].str[0]='-';
                  tokens[0].str[1+substr_len]='\0';
                  nr_token--;
                }
              }else if(nr_token>2){
                if(tokens[nr_token-2].type==')'){
                  printf("Error expression 'num'\n");
                  return false;
                }
                if(tokens[nr_token-2].type=='-' && tokens[nr_token-3].type=='('){
                  tokens[nr_token-2].type=TK_NUM_10;
                  strncpy(tokens[nr_token-2].str+1,substr_start,substr_len);
                  tokens[nr_token-2].str[0]='-';
                  tokens[nr_token-2].str[1+substr_len]='\0';
                  nr_token--;
                }
              }
              break;
            case TK_NUM_16:
              tokens[nr_token-1].type=TK_NUM_10;
              char *endptr;
              char tmp[32];
              memset(tmp,0,sizeof(tmp));
              sprintf(tmp,"%u",(uint32_t)strtoul(tokens[nr_token-1].str, &endptr, 16));
              memset(tokens[nr_token-1].str,0,sizeof(tokens[nr_token-1].str));
              strcpy(tokens[nr_token-1].str,tmp);
              break;
            case TK_REG:
              tokens[nr_token-1].type=TK_NUM_10;
              uint32_t v = reg_str2val(tokens[nr_token-1].str,&success);
              memset(tokens[nr_token-1].str,0,sizeof(tokens[nr_token-1].str));
              sprintf(tokens[nr_token-1].str,"%u",v);
              if(success==false){
                printf("Error expression '%s'\n",tokens[nr_token-1].str);
                return false;
              }
              break;
          }
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


uint32_t expr(char *e, bool *success) {
  if(false==*success) return 0;
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  for (int i = 0; i < nr_token; i ++) {
    if (tokens[i].type == '*' && (i == 0 || (tokens[i - 1].type != TK_NUM_10 && tokens[i - 1].type != ')')) ) {
      tokens[i].type = TK_DEREF;
    }
  }
  return eval(0,nr_token-1,success);
}

int get_op_rank(int op){
  switch (tokens[op].type)
  {
    case 0: return 0;
    case '+':return 4;
    case '-':return 4;
    case '*':return 3;
    case '/':return 3;
    case TK_EQ:return 7;
    case TK_NEQ:return 7;
    case TK_AND:return 11;
    case TK_DEREF:return 2;
    default:  return -1;
  }

}

uint32_t eval(int p, int q, bool *success) {
  if(false==*success) return 0;
  if (p > q) {
    /* Bad expression */
    printf("Bad expression\n");
    *success=false;
    return 0;
    //assert(0);
  }
  else if (p == q) {
    //printf("CALC:%s>>>%d",tokens[p].str,atoi(tokens[p].str));
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
    uint32_t val;
    if(parse_uint32(tokens[p].str,&val)==0){
    }else{
      printf("ERROR number:%s\n",tokens[p].str);
      assert(0);
    }
    return val;
  }
  else if (check_parentheses(p, q,success) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1,success);
  }
  else {
    if(false==*success) return 0;
    int count=0;
    int op=0;
    uint32_t val1,val2;
    for(int i=p;i<=q;i++){
      if(tokens[i].type=='(') count++;
      else if(tokens[i].type==')') count--;
      else if(count==0 && get_op_rank(op)<=get_op_rank(i)){op=i;}
    }
    if(tokens[op].type==TK_DEREF){
      val1 = eval(op + 1, q,success);
      return pmem_read((uint32_t)val1);
    }else{
      val1 = eval(p, op - 1,success);
      val2 = eval(op + 1, q,success);
      switch (tokens[op].type) {

        case '+':     return (uint32_t)val1 + (uint32_t)val2;
        case '-':     return (uint32_t)val1 - (uint32_t)val2;
        case '*':     return (uint32_t)val1 * (uint32_t)val2;
        case '/':     return (uint32_t)val1 / (uint32_t)val2;
        case TK_AND:  return (uint32_t)val1 && (uint32_t)val2;
        case TK_EQ:   return (uint32_t)val1 == (uint32_t)val2;
        case TK_NEQ:  return (uint32_t)val1 != (uint32_t)val2;
        case TK_DEREF:return (uint32_t)val1 != (uint32_t)val2;
        case TK_REG:  
        default: printf("Error OP: %d %s\n",tokens[op].type,tokens[op].str);*success=false;//assert(0);
      }
    }
    
  }
  printf("NULL address!\n");
  *success=false;
  return 0;
}

bool check_parentheses(int p, int q,bool* success){
  if(false==*success) return 0;
  int count=0,flag=0;
  if(tokens[p].type=='(' && tokens[q].type==')'){
    count=0;
    for(int i=p+1;i<=q-1;i++){
      if(tokens[i].type=='(') count++;
      if(tokens[i].type==')') count--;
      if(count<0) break;
    }
    if(count==0&&flag==0) return true;
  }
  count=0;
  for(int i=p;i<=q;i++){
    if(tokens[i].type=='(') count++;
    if(tokens[i].type==')') count--;
    if(count<0){
      *success=false;
      printf("()ERROR!()\n");
      return false;
    }
  }
  if(count==0) return false;
  else{
    *success=false;
    printf("()ERROR3()\n");
    return false;
    //assert(0);
  }
  return false;
}

int parse_uint32(const char *str, uint32_t *result) {
    char *endptr;
    // 检查是否为负号（无符号数不应有负号）
    if (*str == '-') {
        return -1;  // 错误：负数
    }
    // 检查是否有正号（可选）
    if (*str == '+') {
        str++;
    }
    // 使用strtoul转换
    errno = 0;  // 清除错误标志
    unsigned long value = strtoul(str, &endptr, 10);  // 基数10表示十进制
    // 检查是否没有数字被转换
    if (endptr == str) {
        return -2;  // 错误：没有数字
    }
    // 检查转换过程中是否发生溢出
    if (errno == ERANGE) {
        return -4;  // 错误：超出范围
    }
    // 检查是否在uint32_t范围内
    if (value > UINT32_MAX) {
        return -5;  // 错误：超出uint32_t范围
    }
    *result = (uint32_t)value;
    return 0;  // 成功
}