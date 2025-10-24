/***************************************************************************************
deigned by ypc
***************************************************************************************/

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <mem.h>
#include <macro.h>

enum {
  TK_NOTYPE = 256, TK_EQ = 255,
  TK_NUM = 254,
  TK_REG = 253,
  TK_NEQ = 251,
  TK_AND = 250,
  TK_OR = 249,
  TK_XIAOYU = 247,
  TK_DAYU = 246,
  TK_XIAOYUEQ = 245,
  TK_DAYUEQ = 244,
  /* TODO: Add more token types */
  TK_DEREF = 243,
  TK_POS = 242,
  TK_NEG = 241,
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
  {"-", '-'},
  {"\\*", '*'},
  {"/", '/'},
  {"\\(", '('},
  {"\\)", ')'},
  {"(0[xX][0-9A-Fa-f]+)|([0-9]+)", TK_NUM},
  {"==", TK_EQ},        // equal

  {"(\\$0)|ra|sp|gp|tp|t[0-6]|s[0-9]|s10|s11|a[0-7]", TK_REG}, // Register
  {"!=", TK_NEQ}, // !=
  {"&&", TK_AND}, // &&
  {"\\|\\|", TK_OR}, // &&
  {"<", TK_XIAOYU}, // &&
  {">", TK_DAYU}, // &&
  {"<=", TK_XIAOYUEQ}, // &&
  {">=", TK_DAYUEQ}, // &&

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
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[65535] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  memset(tokens, 0, sizeof(tokens));//have to clear tokens!!!
  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        position += substr_len;

        if(rules[i].token_type == TK_NOTYPE) break;//if recognize blank then break;

        tokens[nr_token].type = rules[i].token_type;//if not blank then store;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case TK_NUM :
          case TK_REG :
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            break;
          case '*' :
          case '-' :
          case '+' :
            if(nr_token == 0 || (tokens[nr_token - 1].type != ')' && tokens[nr_token - 1].type != TK_NUM && tokens[nr_token - 1].type != TK_REG)){
              switch (rules[i].token_type) {
                case '*' : tokens[nr_token].type = TK_DEREF; break;
                case '+' : tokens[nr_token].type = TK_POS; break;
                case '-' : tokens[nr_token].type = TK_NEG; break;
              }
            }
            break;
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

bool check_parentheses(int p, int q){
  if(tokens[p].type == '(' && tokens[q].type == ')'){
    int del = 0;
    for(int i = p; i <= q; i++){
      if(tokens[i].type == '(')
        del++;
      else if(tokens[i].type == ')'){
        if(del > 0)
          del--;
        else
          return false;
      }
      else if(del == 0 && (tokens[i].type == '+' || tokens[i].type == '-' || tokens[i].type == '*' || tokens[i].type == '/'))
        return false;
    }
    if(del == 0)
      return true;
  }
  return false;
}

int find_major(int p, int q){
  int ret = -1;
  int del = 0;
  int last_low_p = 0;
  for(int i = p; i <= q; i++){
    if(tokens[i].type == '(')
      del++;
    else if(tokens[i].type == ')'){
      if(del > 0)
        del--;
      else
        return -1;
    }
    else if(tokens[i].type == TK_NUM || tokens[i].type == TK_REG)
      continue;
    else if(del > 0)
      continue;
    else{
      int low_p = 0;
      switch(tokens[i].type){
        case TK_OR: low_p++;
        case TK_AND: low_p++;
        case TK_EQ: case TK_NEQ: low_p++;
        case TK_XIAOYU: case TK_DAYU: case TK_XIAOYUEQ: case TK_DAYUEQ: low_p++;
        case '+': case '-': low_p++;
        case '*': case '/': low_p++;
        case TK_NEG: case TK_DEREF: case TK_POS: low_p++; break;
        default: return -1;
      }
      if(low_p > last_low_p || ((low_p == last_low_p) && (tokens[i].type != TK_NEG && tokens[i].type != TK_POS && tokens[i].type != TK_DEREF))){
        last_low_p = low_p;
        ret = i;
      }
    }
  }
  if(del != 0) return -1;
  return ret;
}

static word_t deref(paddr_t addr){
  if((addr >= CONFIG_MBASE && addr <= CONFIG_MBASE + CONFIG_MSIZE) || addr == RTC_ADDR || addr == RTC_ADDR + 4 || addr == SERIAL_PORT)
        return *(uint32_t *)guest_to_host(addr);
  return 0;
}

static word_t calculate_unary(int op, word_t val, bool *ok) {
  *ok = true;
  switch (op)
  {
    case TK_NEG: return -val;
    case TK_POS: return val;
    case TK_DEREF: return deref(val);
    default: *ok = false;
  }
  return 0;
}

static word_t calculate_binary(word_t val1, int op, word_t val2, bool *ok) {
  *ok = true;
  switch(op) {
    case '+': return val1 + val2;
    case '-': return val1 - val2;
    case '*': return val1 * val2;
    case '/':
      if (val2 == 0) {
        *ok = false;
        return 0;
      }
      return (sword_t)val1 / (sword_t)val2;
    case TK_AND: return val1 && val2;
    case TK_OR: return val1 || val2;
    case TK_EQ: return val1 == val2;
    case TK_NEQ: return val1 != val2;
    case TK_DAYU: return val1 > val2;
    case TK_XIAOYU: return val1 < val2;
    case TK_DAYUEQ: return val1 >= val2;
    case TK_XIAOYUEQ: return val1 <= val2;
    default: *ok = false; return 0;
  }
}

word_t eval(int p, int q, bool *success) {
  *success = true;
  if (p > q) {
    *success = false;
    return 0;
    /* Bad expression */
  }
  else if (p == q) {
    switch(tokens[p].type){
      case TK_NUM :
        return strtol(tokens[p].str, NULL, 0);
      case TK_REG :
        return isa_reg_str2val(tokens[p].str, success);
      default :
        *success = false;
        return 0;
    }
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
  }
  else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1, success);
  }
  else {
    int op = find_major(p, q);
    if(op < 0){
      *success = false;
      return 0;
    }
    bool success1, success2;
    word_t val1 = eval(p, op - 1, &success1);
    word_t val2 = eval(op + 1, q, &success2);
    // printf("val1 = %u, val2 = %u\n", val1, val2);

    if(!success2){
      *success = false;
      return 0;
    }
    if(success1){
      word_t ret = calculate_binary(val1, tokens[op].type, val2, success);
      return ret;
    }
    else{
      word_t ret = calculate_unary(tokens[op].type, val2, success);
      return ret;
    }
    /* We should do more things here. */
  }
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  for (int i = 0; i < nr_token; i ++) {
    if (tokens[i].type == '*' && (i == 0 || tokens[i - 1].type == TK_REG) ) {
      tokens[i].type = TK_DEREF;
    }
  }


  return eval(0, nr_token-1, success);
}
