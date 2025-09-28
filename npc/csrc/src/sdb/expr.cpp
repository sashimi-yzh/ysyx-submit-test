#include "common.h"
#include "cpu.h"
#include "mem.h"

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <cstring>
#include <regex.h>

enum {
  PRI_UNARY = 0,
  PRI_MUL,
  PRI_ADD,
  PRI_SH,
  PRI_REL,
  PRI_EQ,
  PRI_BAND,
  PRI_BXOR,
  PRI_BOR,
  PRI_LAND,
  PRI_LOR
};

enum {
  TK_NOTYPE = 256,

  TK_NEG, TK_DEREF,

  TK_SHL, TK_SHR,
  TK_LE, TK_GE,
  TK_EQ, TK_NE,
  TK_LAND, TK_LOR,

  TK_NUM
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {" +", TK_NOTYPE},    // spaces

  {"\\$[a-z0-9]+", TK_NUM}, // register
  {"0x[0-9a-fA-F]+", TK_NUM}, // hexadecimal number
  {"0b[01]+", TK_NUM}, // binary number
  {"[0-9]+", TK_NUM}, // decimal number

  {"<<", TK_SHL},       // shift left
  {">>", TK_SHR},       // shift right
  {"<=", TK_LE},        // less or equal
  {">=", TK_GE},        // greater or equal
  {"==", TK_EQ},        // equal
  {"!=", TK_NE},        // not equal
  {"&&", TK_LAND},      // logic and
  {"\\|\\|", TK_LOR},   // logic or

  {"!", '!'},           // logic not
  {"~", '~'},           // bitwise not
  {"\\*", '*'},         // multiply (derefer)
  {"\\/", '/'},         // divide
  {"\\+", '+'},         // plus
  {"-", '-'},           // minus (negative)
  {">", '>'},           // greater
  {"<", '<'},           // less
  {"&", '&'},           // bitwise and
  {"\\^", '^'},         // bitwise xor
  {"\\|", '|'},         // bitwise or

  {"\\(", '('},         // left parentheses
  {"\\)", ')'},         // right parentheses
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

static Token tokens[128] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;

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

        /*Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);*/

        position += substr_len;

        switch (rules[i].token_type) {
          case TK_NOTYPE: break;
          case TK_NUM:
            if (substr_len >= 32) {
              printf("number too long at position %d\n%s\n%*.s^\n", \
                     position, e, position, "");
              return false;
            }
            tokens[nr_token].type = rules[i].token_type;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            ++nr_token;
            break;
          default: tokens[nr_token++].type = rules[i].token_type; break;
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

static bool eval_err;
static int stack[32];

static word_t eval(int l, int r) {
  // printf("eval: %d %d\n", l, r);
  if (l > r) { /* Bad expr */
    eval_err = true;
    // Log("Bad expr: %d %d\n", l, r);
    return -1;
  }
  if (l == r) { /* single token, should be a number */
    word_t val = 0;
    if (tokens[l].type != TK_NUM) {
      eval_err = true;
      return -1;
    }
    if (tokens[l].str[0] == '$') { // register
      bool success = true;
      val = reg_str2val(tokens[l].str + 1, &success);
      if (success) return val;
      eval_err = true;
      // Log("Bad number: %d %d\n", l, r);
      return -1;
    }
    switch (tokens[l].str[1]) { // literal
      case 'x': // 0x hex
        for (char *p = tokens[l].str + 2; *p != '\0'; ++p) {
          val <<= 4;
          if (*p <= '9') val += *p - '0';
          else if (*p <= 'F') val += *p - 'A' + 10;
          else val += *p - 'a' + 10;
        }
        return val;
      case 'b': // 0b otc
        for (char *p = tokens[l].str + 2; *p != '\0'; ++p) {
          val = (val << 1) + (*p - '0');
        }
        return val;
      default: // dec
        for (char *p = tokens[l].str; *p != '\0'; ++p) {
          val = val * 10 + (*p - '0');
        }
        return val;
    }
  }
  if (tokens[l].type == '(' && tokens[r].type == ')') {
    int top = 0;
    for (int i = l; i < r; ++i) {
      if (tokens[i].type == '(') stack[top++] = i;
      else if (tokens[i].type == ')') {
        if (top == 0) { eval_err = true; return -1; }
        --top;
      }
    }
    if (top == 1 && stack[0] == l) return eval(l + 1, r - 1);
  }

  int op = -1, dep = 0, pri = -1;
  for (int i = l; i <= r; ++i) {
    if (tokens[i].type == '(') ++dep;
    else if (tokens[i].type == ')') --dep;
    if (dep != 0) continue;
    switch (tokens[i].type) {
      case TK_NEG:
      case TK_DEREF:
      case '!':
      case '~':
        if (PRI_UNARY <= pri) break;
        op = i; pri = PRI_UNARY; break;
      case '*':
      case '/':
        if (PRI_MUL < pri) break;
        op = i; pri = PRI_MUL; break;
      case '+':
      case '-':
        if (PRI_ADD < pri) break;
        op = i; pri = PRI_ADD; break;
      case TK_SHL:
      case TK_SHR:
        if (PRI_SH < pri) break;
        op = i; pri = PRI_SH; break;
      case '<':
      case '>':
      case TK_GE:
      case TK_LE:
        if (PRI_REL < pri) break;
        op = i; pri = PRI_REL; break;
      case TK_EQ:
      case TK_NE:
        if (PRI_EQ < pri) break;
        op = i; pri = PRI_EQ; break;
      case '&':
        if (PRI_BAND < pri) break;
        op = i; pri = PRI_BAND; break;
      case '^':
        if (PRI_BXOR < pri) break;
        op = i; pri = PRI_BXOR; break;
      case '|':
        if (PRI_BOR < pri) break;
        op = i; pri = PRI_BOR; break;
      case TK_LAND:
        if (PRI_LAND < pri) break;
        op = i; pri = PRI_LAND; break;
      case TK_LOR:
        if (PRI_LOR < pri) break;
        op = i; pri = PRI_LOR; break;
    }
  }
  /* dep == 0 is just a sufficient condition of bad parentheses */
  if (op == -1 || dep != 0) {
    eval_err = true;
    // Log("No op: %d %d\n", l, r);
    return -1;
  }
  
  if (op == l) { /* unary operator */
    switch (tokens[l].type) {
      case TK_NEG: return -eval(l + 1, r);
      case TK_DEREF: return addr_read(eval(l + 1, r), 4);
      case '!': return !eval(l + 1, r);
      case '~': return ~eval(l + 1, r);
      default: eval_err = true; return -1;
    }
  }
  word_t val1 = eval(l, op - 1);
  if (eval_err) return -1;
  word_t val2 = eval(op + 1, r);
  if (eval_err) return -1;

  switch (tokens[op].type) {
    case '*':     return val1 * val2;
    case '/':     return val1 / val2;
    case '+':     return val1 + val2;
    case '-':     return val1 - val2;
    case TK_SHL:  return val1 << val2;
    case TK_SHR:  return val1 >> val2;
    case '>':     return val1 > val2;
    case '<':     return val1 < val2;
    case TK_GE:   return val1 >= val2;
    case TK_LE:   return val1 <= val2;
    case TK_EQ:   return val1 == val2;
    case TK_NE:   return val1 != val2;
    case '&':     return val1 & val2;
    case '^':     return val1 ^ val2;
    case '|':     return val1 | val2;
    case TK_LAND: return val1 && val2;
    case TK_LOR:  return val1 || val2;
    default: assert(0);
  }
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  for (int i = 0; i < nr_token; ++i) {
    if (i == 0 || (tokens[i - 1].type != TK_NUM && tokens[i - 1].type != ')')) {
      switch (tokens[i].type) {
        case '-': tokens[i].type = TK_NEG; break;
        case '*': tokens[i].type = TK_DEREF; break;
      }
    }
  }

  eval_err = false;
  word_t val = eval(0, nr_token - 1);
  *success = !eval_err;
  return val;
}
