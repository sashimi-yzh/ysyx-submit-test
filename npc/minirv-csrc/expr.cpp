
#include <regex.h>
#include <ctype.h>
// #include<isa.h>
#include "../include/paddr.h"
#include "../include/common.h"
#include "../include/debug.h"
#include "../include/reg.h"

/********extern functions or variables********/
extern "C" void     pmem_write(paddr_t waddr,word_t wdata,int len);
extern "C" word_t   pmem_read(paddr_t raddr,int len);
/*********************************************/

enum {
  TK_NOTYPE = 256, TK_EQ,
  TK_NUM,TK_NEQ,TK_NEG,TK_PO,TK_AND,TK_0x,TK_$,
  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {"\\(", '('},         // 左括号
  {"\\)",')'},          // 右括号
  {"\\*", '*'},         // 乘法
  {"\\*", TK_PO},       //指针解引用
  {"/", '/'},           // 除法
  {"-", '-'},           // 减法
  {"-", TK_NEG},        //负号，处理多元减号
  {"0x[0-9a-fA-F]+",TK_0x},
  {"[0-9]+", TK_NUM},   // 数字
  {"!=",TK_NEQ},        //不等号
  {"&&",TK_AND},
  {"\\$",TK_$},

  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"==", TK_EQ},        // equal
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */

//性能优化:编译后的正则表达式可以在后续的匹配操作中更快地工作。如果每次使用时都重新解析正则表达式的字符串形式，将会浪费大量的时间和资源。通过提前编译，可以显著提高效率，尤其是在多次重复使用同一个正则表达式的情况下。
//错误检测:在初始化阶段，即调用regcomp时，任何语法错误都会被捕获并报告。这有助于开发者在程序运行之前发现和修复问题，而不是等到实际匹配时才遇到异常。
//内存管理:编译后的正则表达式会被存储在一个结构体中（如regex_t），这使得我们可以更好地管理和释放与之相关的资源。当不再需要某个正则表达式时，可以通过regfree函数释放其占用的内存。
//准备就绪的状态:一旦正则表达式被成功编译，它就处于一种“准备就绪”的状态，可以直接用于文本匹配，而不需要额外的处理步骤。
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

static Token tokens[1000] __attribute__((used)) = {};//tokens原来长度是32容易发生越界从而发生断言错误
static int nr_token __attribute__((used))  = 0;

// static int hex_char_to_decimal(char c) {
//   if(c>='0' && c<='9') return c-'0';
//   if(c>='A' && c<='F') return c-'A'+10;
//   if(c>='a' && c<='f') return c-'a'+10;
//   return -1;
// }
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

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        switch (rules[i].token_type) {
          case TK_NUM:
          case '+':
          case '/':
          case '(':
          case ')':
          case TK_NEQ:
          case TK_EQ:
          case TK_AND:
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            tokens[nr_token].type = rules[i].token_type;
            nr_token++;
            break;
          case '-': // 处理一元和多元减法
            if (nr_token == 0 || tokens[nr_token-1].type == '(' ||
                tokens[nr_token-1].type == '+' || tokens[nr_token-1].type == '-' ||
                tokens[nr_token-1].type == '*' || tokens[nr_token-1].type == '/' ||
                tokens[nr_token-1].type == TK_AND || tokens[nr_token-1].type == TK_EQ || tokens[nr_token-1].type ==TK_NEQ ||
                tokens[nr_token-1].type == TK_NEG) { 
              tokens[nr_token].type = TK_NEG; 
            } else {
              tokens[nr_token].type = '-'; 
            }
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            break;
          case '*':
            if (nr_token == 0 || tokens[nr_token - 1].type == '(' ||
                tokens[nr_token-1].type == '+' || tokens[nr_token-1].type == '-' ||
                tokens[nr_token-1].type == TK_AND || tokens[nr_token-1].type == TK_EQ || tokens[nr_token-1].type ==TK_NEQ ||
                tokens[nr_token-1].type == '*' || tokens[nr_token-1].type == '/') { 
              tokens[nr_token].type = TK_PO; 
            } else {
              tokens[nr_token].type = '*'; 
            }
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            break;
          case TK_0x: {
            const char *hex_start = substr_start + 2;
            long decimal_val = strtol(hex_start, NULL, 16); //strtol用于将字符串转换为长整型数,灵活的转进制能力。转换基数为0时候则根据前缀
            if (decimal_val >= 0) {
              snprintf(tokens[nr_token].str, sizeof(tokens[nr_token].str), "%ld", decimal_val);
              tokens[nr_token].type = TK_NUM;
              nr_token++;
            }
            break;
          }
          case TK_$: {
            int name_num = 0;
            char reg_name[5]; 
            while (isalnum(e[position]) || e[position] == '$') { // 继续读取直到遇到非字母数字
              if (name_num < 4) {
                reg_name[name_num++] = e[position++];
              } else {
                printf("Reg name too long\n");
                return false;
              }
              if (e[position] == '\0') break;
            }
            reg_name[name_num] = '\0';
            long reg_val = single_reg_display(reg_name);
            if (reg_val < 0) {
              printf("Unknow reg name: %s\n", reg_name);
              return false;
            }
            // 将寄存器值转换为十进制字符串并存储到 tokens 中
            snprintf(tokens[nr_token].str, sizeof(tokens[nr_token].str), "%ld", reg_val);
            tokens[nr_token].type = TK_NUM;
            nr_token++;
            break;
          }
          default: break;//TODO();
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

static bool check_parentheses(int p,int q){
  int cnt=0;
  if(tokens[p].type!='(' || tokens[q].type!=')') return false;
  for(int i=p;i<=q;i++){
    if(tokens[i].type=='(') cnt++;
    if(tokens[i].type==')') cnt--;
    if(cnt==0&&i<q) return false;
  }
  if(cnt!=0) return false;
  else return true;
}

static int operator_level(int op_type){
  switch(tokens[op_type].type){
    case TK_NEG: return 5;
    // case TK_PO: return 5;
    case '+': return 4;
    case '-': return 4;
    case '*': return 3;
    case '/': return 3;
    case TK_EQ:return 2;
    case TK_NEQ:return 2;
    case TK_AND:return 1;
    default:  
      //printf("Undefine oprator\n");
      // assert(0);
      return -1;
  }
}

static int find_main_operator(int p,int q){
  int high_operator_level=-1;
  int main_operator=-1;
  int cnt=0;
  for(int i=p;i<=q;i++){
    if (tokens[i].type == '(') {
      cnt++;
    } else if (tokens[i].type == ')') {
      cnt--;
      if(cnt==0) continue;
      if (cnt < 0) {
        printf("Unmatched right parenthesis at position %d\n", i);
        return -1;
      }
    }
    if (cnt>0) continue;
    if(tokens[i].type!=TK_NUM && tokens[i].type!=TK_NOTYPE){//排除非运算符
      if(high_operator_level<=operator_level(i)){
        high_operator_level=operator_level(i);
        main_operator=i;
      }
    }
  }
  return main_operator;
}

word_t eval(int p,int q){
  int op;
  if(p>q){
    return 0;
  }else if(p==q){
    if(tokens[p].type!=TK_NUM){
      return -1;
    }
    return atoi(tokens[p].str);
  }else if(check_parentheses(p,q)==true){//查找两端的括号并丢弃
    return eval(p+1,q-1);
  }else{
    op=find_main_operator(p,q);
    if(op==-1 || op<p || op>q){
      return -1;
    }
    if (tokens[op].type == TK_NEG) {
      int neg_count = 0;//计算连续的一元减号数量
      for (int j=op;j<=q && tokens[j].type == TK_NEG;j++,neg_count++);
      word_t val=eval(op+neg_count,q); //跳过所有的一元减号
      return (neg_count%2 == 0) ? val : -val; //根据奇偶性决定最终是加还是减
    }
    if (tokens[op].type == TK_PO) {//解指针操作，假设后面跟着的是一个有效的内存地址
      if (op+1<=q && (tokens[op+1].type==TK_NUM || tokens[op+1].type=='(')) {
        if(tokens[op+1].type==TK_NUM){
          word_t addr=atoi(tokens[op+1].str); //将字符串转换为整数作为地址
          word_t val=pmem_read(addr,sizeof(word_t)); //取地址处的值
          return val;
        }else if(tokens[op+1].type=='('){
          word_t addr0=eval(op+1,q);
          word_t val0=pmem_read(addr0,sizeof(word_t));
          return val0;
        }
      } else {
        printf("Invalid operation\n");
        return -1;
      }
    }
    word_t val1=eval(p,op-1);
    word_t val2=eval(op+1,q);
      switch(tokens[op].type){
        case '+':return val1+val2;
        case '-':return val1-val2;
        case '*':return val1*val2;
        case '/':
          if(val2==0){
            printf("The denominator can't be zero!\n");
            return 0;
          }
          return val1/val2;
        case TK_NEQ:return val1 != val2?1:0;
        case TK_EQ:return val1 == val2?1:0;
        case TK_AND:return val1 && val2?1:0;
        default:return 0;
    }
  }
}

word_t expr(char *e) {//分治递归算法
  if (!make_token(e)) {
    return -1;
  }
  /* TODO: Insert codes to evaluate the expression. */
  word_t result=eval(0,nr_token-1);
  //TODO();

  return result;
}
