#include <npc.h>
#include <common.h>

#include <regex.h>
#define MAX 500

enum {
  TK_NOTYPE = 256,
  TK_EQ = 257, 
  TK_NEQ = 258, 
  TK_NUM = 259, 
  TK_AND = 260, 
  TK_HEX = 261,
  TK_REG = 262,
  DEREF = 263,
  

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  {"0x[0-9a-hA-H]*", TK_HEX},
  {"^\\$\\$?[a-z]*[0-9]*", TK_REG},
  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"-", '-'},
  {"\\*", '*'},
  {"/", '/'},
  {"==", TK_EQ},        // equal
  {"!=", TK_NEQ},
  {"[0-9]+", TK_NUM},
  {"\\(", '('},
  {"\\)", ')'},
  {"&&",TK_AND},

};

int certain_type(int type) {
  if (type == '+' ||
      type == '-' ||
      type == '*' ||
      type == '/' ||
      type == '(' ||
      type == DEREF ||
      type == TK_EQ ||
      type == TK_NEQ ||
      type == TK_AND
     ) return 1;

  else return 0;
}

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

void init_regex() {
  int i;
  char error_msg [128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      Log("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
      assert(0);
    }
  }
}

typedef struct token {
  int type;
  char str[128];
} Token;

static Token tokens[MAX] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;
static int n = 0;

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

        switch (rules[i].token_type) { //开始将匹配的type内容写入每个token中.
          default: if (rules[i].token_type != TK_NOTYPE) {
          	      tokens[n].type = rules[i].token_type;

		      char s[MAX];
		      sprintf(s, "%.*s", substr_len, substr_start);
		      strcpy(tokens[n].str, s);
          	      n++;
        	    }

        position += substr_len;

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


static bool check_parentheses(int p, int q, int *y) { //状态机check
  int state = 0;
  if (tokens[p].type == 40 && tokens[q].type == 41) {
    p++;
    q--;
    for (; p <= q; p++) {
      if (tokens[p].type == '(') state++;
      else if (tokens[p].type == ')') state--;
      else if (state < 0) *y = 1;
    }
    if (state == 0) return true;
    else {
      printf("Error: The parentheses do not match!\n");
      assert(0);
    }
  }
  return false;
}

static int priority(int op) { //优先级排序
    switch (op) {
	case TK_AND: return 1;
	case TK_EQ: case TK_NEQ: return 2;
        case '+': case '-': return 3;
        case '*': case '/': case DEREF:return 4;
        default: return 0;
    }
}

static int m_op(int p, int q) { //主运算符选取
    int pos = -1;
    int op_priority = 4;
    int bracket = 0;

    for (; p != q; p++) {
        if (tokens[p].type == '(') bracket++; //避免选择括号里的
        else if (tokens[p].type == ')') bracket--;
        else if (bracket == 0) {
	    int op = tokens[p].type;
            int i = priority(op);
            if (i > 0 && i <= op_priority) {
                op_priority = i;
                pos = p;
            }
        }
    }

    return pos;
}

uint32_t eval(int p, int q) {
  uint32_t val1;
  uint32_t val2;
  int op;
  int y = 0;

  if (p > q) return 0;

  else if (p == q) {
    uint32_t num = atoi(tokens[p].str);
    return (num);
  }

  else if (check_parentheses(p, q, &y) == true) {
    if (!y) return eval(p + 1, q - 1);
  }
  
  if (true) {
    op = m_op(p, q);
    val1 = eval(p, op - 1);
    val2 = eval(op + 1, q);

    switch (tokens[op].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': if (val2 != 0) return (int32_t)val1 / (int32_t)val2; else assert(0);
      case TK_AND: return val1 && val2;
      case TK_EQ: return val1 == val2;
      case TK_NEQ: return val1 != val2;
      case DEREF: { uint32_t addr = eval(p + 1, q);
	          return pmem_read(addr); }
      default: assert(0);
    }
  }
  assert(0);
  return 0;
}

word_t expr(char *e, bool *success) {
  n = 0;

  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  for (int i = 0; i < n; i ++) {
    if (tokens[i].type == '*' && (i == 0 || certain_type(tokens[i - 1].type)) ) {
      tokens[i].type = DEREF;
    }
  }

  *success = true;
  uint32_t str_len = n;
  
  //首先转换hex和reg
  for (int k = 0; k <= n; k ++) { 
    int thelen = strlen(tokens[k].str);
    char reg0[MAX];

    switch (tokens[k].type) {
      case TK_HEX:uint32_t num;
                  sscanf(tokens[k].str, "%x", &num);
                  sprintf(tokens[k].str, "%u", num);
		  break;

      case TK_REG:for (int b = 0; b < thelen; b ++) reg0[b] = tokens[k].str[b + 1];
                  bool good;
                  sprintf(tokens[k].str, "%u", isa_reg_str2val(reg0, &good));
                  assert(good);
		  break;

      default: break;
    }
  }
 
  uint32_t R = eval(0, str_len - 1);
  
  n = 0;
  return (R);
}
