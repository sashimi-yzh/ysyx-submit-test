#include "common.h"
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <regex.h>

enum {
  TK_NOTYPE = 256,
  TK_EQ,

  /* TODO: Add more token types */
  NUM,
  HEX_NUM,
  LEFT_PARENTAHESE,
  RIGHT_PARENTHESE,
  TK_MUL,
  TK_DIV,
  TK_SUB,
  TK_ADD,
  REG,
  DEPOINT,
  TK_AND,
  TK_UNEQ,
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

    /* TODO: Add more rules.
     * Pay attention to the precedence level of different rules.
     */

    {" +", TK_NOTYPE},         // spaces
    {"\\+", TK_ADD},           // plus
    {"==", TK_EQ},             // equal
    {"\\(", LEFT_PARENTAHESE}, // left_ph
    {"\\)", RIGHT_PARENTHESE}, // right_ph
    {"\\*", TK_MUL},
    {"/", TK_DIV},
    {"-", TK_SUB},
    {"0x[0-9|a-f]{1,8}", HEX_NUM},
    {"[0-9]{1,32}", NUM},
    {"\\$[a-z|0-9|\\$]{2,3}", REG},
    {"!=", TK_UNEQ},
    {"&&", TK_AND},
};

#define NR_REGEX sizeof(rules) / sizeof(rule)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i++) {
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

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 &&
          pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s", i,
        //   rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        switch (rules[i].token_type) {
        case TK_NOTYPE:
          break;
        case TK_SUB:
          if ((nr_token == 0) ||
              (tokens[nr_token - 1].type != NUM &&
               tokens[nr_token - 1].type != RIGHT_PARENTHESE)) {
            // if not num - expr or ) - expr
            //  - is neg signal tansform it to -1*
            tokens[nr_token].type = NUM;
            strcpy(tokens[nr_token++].str, "-1");
            tokens[nr_token].type = TK_MUL;
            strcpy(tokens[nr_token++].str, "*");
            break;
          }
        case TK_MUL:
          if ((nr_token == 0) ||
              (tokens[nr_token - 1].type != NUM &&
               tokens[nr_token - 1].type != RIGHT_PARENTHESE)) {
            // if not num * expr or ) * expr
            // * is depointer
            tokens[nr_token].type = DEPOINT;
            strcpy(tokens[nr_token].str, "*");
            nr_token++;
            break;
          }
        default:
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].str[substr_len] = '\0';
          tokens[nr_token].type = rules[i].token_type;
          nr_token++;
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  /* used for test
  for (int i = 0; i < nr_token; i++)
    printf("%s ", tokens[i].str);
   printf("\n");
  */

  return true;
}

bool check_parenthese(int p, int q, int mod) {
  // mod 0: check the parenthese match
  // mod 1: check BNF rule "(<expr>)"
  assert(p <= q);
  assert(mod == 0 || mod == 1);
  if (mod == 1) {
    if (tokens[p].type != LEFT_PARENTAHESE ||
        tokens[q].type != RIGHT_PARENTHESE)
      return false;
    p++;
    q--;
  }
  int record = 0;
  while (p <= q) {
    if (tokens[p].type == LEFT_PARENTAHESE)
      record++;
    else if (tokens[p].type == RIGHT_PARENTHESE)
      record--;

    if (record < 0)
      return false;

    p++;
  }
  if (record != 0)
    return false;
  return true;
}

int find_operator(int p, int q, bool *success) {
  int pos = -1;
  int level = 0;
  int parenthese_deep = 0;
  while (p <= q) {
    if (tokens[p].type == TK_EQ && level <= 3 && parenthese_deep == 0) {
      pos = p;
      level = 3;
    }
    if (tokens[p].type == TK_UNEQ && level <= 3 && parenthese_deep == 0) {
      pos = p;
      level = 3;
    }
    if (tokens[p].type == TK_AND && level <= 4 && parenthese_deep == 0) {
      pos = p;
      level = 4;
    }
    if ((tokens[p].type == TK_MUL || tokens[p].type == TK_DIV) && level <= 1 &&
        parenthese_deep == 0) {
      level = 1;
      pos = p;
    }
    if ((tokens[p].type == TK_ADD || tokens[p].type == TK_SUB) &&
        parenthese_deep == 0 && level <= 2) {
      level = 2;
      pos = p;
    }
    if (tokens[p].type == DEPOINT && level == 0 && parenthese_deep == 0) {
      pos = p;
    }
    if (tokens[p].type == LEFT_PARENTAHESE)
      parenthese_deep++;
    if (tokens[p].type == RIGHT_PARENTHESE)
      parenthese_deep--;
    p++;
  }
  if (pos == -1)
    *success = false;
  return pos;
}

int eval(int p, int q, bool *success) {
  if (*success == false)
    return 0;

  if (p > q) {
    printf("invalid expression\n");
    *success = false;
    return 0;
  } else if (p == q) {
    // signal expression
    // assume every input is dec integer
    if (tokens[p].type == NUM)
      return atoi(tokens[p].str);
    if (tokens[p].type == REG) {
      uint32_t ret = npc_reg_str2val(tokens[p].str, success);
      if (*success == false) {
        printf("failed to read the given reg %s\n", tokens[p].str);
        return 0;
      }
      return (int)ret;
    }
    if (tokens[p].type == HEX_NUM) {
      int res;
      sscanf(tokens[p].str, "%x", &res);
      return res;
    }
    *success = false;
    printf("invalid expression\n");
    return 0;
  } else if (check_parenthese(p, q, 1)) {
    return eval(p + 1, q - 1, success);
  } else {
    // need to find the main operator
    int pos = find_operator(p, q, success);
    int dividend = 0;
    uint32_t addr;
    switch (tokens[pos].type) {
    case TK_ADD:
      return eval(p, pos - 1, success) + eval(pos + 1, q, success);
      break;
    case TK_SUB:
      return eval(p, pos - 1, success) - eval(pos + 1, q, success);
      break;
    case TK_MUL:
      return eval(p, pos - 1, success) * eval(pos + 1, q, success);
      break;
    case TK_DIV:
      dividend = eval(pos + 1, q, success);
      if (dividend == 0) {
        *success = false;
        printf("0 can be used as dividend\n");
        return 0;
      }
      return eval(p, pos - 1, success) / dividend;
      break;
    case TK_EQ:
      return eval(p, pos - 1, success) == eval(pos + 1, q, success);
      break;
    case TK_UNEQ:
      return eval(p, pos - 1, success) != eval(pos + 1, q, success);
      break;
    case TK_AND:
      return eval(p, pos - 1, success) && eval(pos + 1, q, success);
      break;
    case DEPOINT:
      addr = (uint32_t)eval(p + 1, q, success);
      return (int)paddr_read(addr, 4);
      break;
    default:
      printf("meet a unhanded %d:\"%s\"", tokens[p].type, tokens[p].str);
      assert(0);
      break;
    }
    return 0;
  }
}

uint32_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    printf("get invailed tokens\n");
    *success = false;
    return 0;
  }

  if (check_parenthese(0, nr_token - 1, 0) == false) {
    printf("unmatched parenthese\n");
    *success = false;
    return 0;
  }

  int res = eval(0, nr_token - 1, success);
  return (uint32_t)res;
}
