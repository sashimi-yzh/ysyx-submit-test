#include "sdb.h"
#include <regex.h>
#include <cassert>
#include <cstdlib>

enum {
  TK_NOTYPE = 256,
  TK_EQ,
  TK_NE,
  TK_AND,
  TK_OR,
  TK_NUM,
  TK_HEX,
  TK_REG,
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {"[ \t]+", TK_NOTYPE},
  {"==", TK_EQ},
  {"!=", TK_NE},
  {"&&", TK_AND},
  {"\\|\\|", TK_OR},
  {"0[xX][0-9a-fA-F]+", TK_HEX},
  {"[0-9]+", TK_NUM},
  {"\\$[a-zA-Z0-9]+", TK_REG},
  {"\\+", '+'},
  {"-", '-'},
  {"\\*", '*'},
  {"/", '/'},
  {"\\(", '('},
  {"\\)", ')'},
  {"!", '!'},
};

#define NR_REGEX (sizeof(rules) / sizeof(rules[0]))

static regex_t re[NR_REGEX] = {};

void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      printf("regex compilation failed: %s\n%s\n", error_msg, rules[i].regex);
      assert(0);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[65536];
static int nr_token = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        position += substr_len;

        switch (rules[i].token_type) {
          case TK_NOTYPE:
            break;

          case TK_NUM:
          case TK_HEX:
          case TK_REG:
            tokens[nr_token].type = rules[i].token_type;
            if (substr_len >= (int)sizeof(tokens[nr_token].str)) {
              printf("Token too long!\n");
              return false;
            }
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token ++;
            break;

          case '+':
          case '-':
          case '*':
          case '/':
          case '(':
          case ')':
          case '!':
          case TK_EQ:
          case TK_NE:
          case TK_AND:
          case TK_OR:
            tokens[nr_token].type = rules[i].token_type;
            nr_token ++;
            break;

          default:
            assert(0);
        }

        if (nr_token >= (int)(sizeof(tokens) / sizeof(tokens[0]))) {
          printf("Too many tokens\n");
          return false;
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

struct Parser {
  int pos;
  bool ok;
};

static word_t parse_or(Parser *p);

static bool accept(Parser *p, int type) {
  if (p->ok && p->pos < nr_token && tokens[p->pos].type == type) {
    p->pos ++;
    return true;
  }
  return false;
}

static word_t parse_primary(Parser *p) {
  if (!p->ok || p->pos >= nr_token) {
    p->ok = false;
    return 0;
  }

  Token *t = &tokens[p->pos];

  switch (t->type) {
    case TK_NUM:
      p->pos ++;
      return (word_t)strtoul(t->str, NULL, 10);

    case TK_HEX:
      p->pos ++;
      return (word_t)strtoul(t->str, NULL, 16);

    case TK_REG: {
      bool success = false;
      word_t val = npc_reg_str2val(t->str, &success);
      if (!success) {
        printf("Unknown register: %s\n", t->str);
        p->ok = false;
        return 0;
      }
      p->pos ++;
      return val;
    }

    case '(': {
      p->pos ++;
      word_t val = parse_or(p);
      if (!accept(p, ')')) {
        printf("Missing ')'\n");
        p->ok = false;
        return 0;
      }
      return val;
    }

    default:
      if (t->type > 0 && t->type < 256) {
        printf("Unexpected token: '%c'\n", (char)t->type);
      } else {
        printf("Unexpected token (type %d)\n", t->type);
      }
      p->ok = false;
      return 0;
  }
}

static word_t parse_unary(Parser *p) {
  if (accept(p, '-')) {
    return (word_t)(0u - parse_unary(p));
  }
  if (accept(p, '!')) {
    return (word_t)(parse_unary(p) == 0);
  }
  if (accept(p, '*')) {
    word_t addr = parse_unary(p);
    if (!p->ok) return 0;

    word_t data = 0;
    if (!npc_mem_read_word(addr, &data)) {
      printf("Invalid or unavailable memory address: 0x%08x\n", addr);
      p->ok = false;
      return 0;
    }
    return data;
  }
  return parse_primary(p);
}

static word_t parse_mul(Parser *p) {
  word_t val = parse_unary(p);

  while (p->ok) {
    if (accept(p, '*')) {
      word_t rhs = parse_unary(p);
      if (!p->ok) return 0;
      val = val * rhs;
    } else if (accept(p, '/')) {
      word_t rhs = parse_unary(p);
      if (!p->ok) return 0;
      if (rhs == 0) {
        printf("Division by zero!\n");
        p->ok = false;
        return 0;
      }
      val = val / rhs;
    } else {
      break;
    }
  }

  return val;
}

static word_t parse_add(Parser *p) {
  word_t val = parse_mul(p);

  while (p->ok) {
    if (accept(p, '+')) {
      word_t rhs = parse_mul(p);
      if (!p->ok) return 0;
      val = val + rhs;
    } else if (accept(p, '-')) {
      word_t rhs = parse_mul(p);
      if (!p->ok) return 0;
      val = val - rhs;
    } else {
      break;
    }
  }

  return val;
}

static word_t parse_equality(Parser *p) {
  word_t val = parse_add(p);

  while (p->ok) {
    if (accept(p, TK_EQ)) {
      word_t rhs = parse_add(p);
      if (!p->ok) return 0;
      val = (val == rhs);
    } else if (accept(p, TK_NE)) {
      word_t rhs = parse_add(p);
      if (!p->ok) return 0;
      val = (val != rhs);
    } else {
      break;
    }
  }

  return val;
}

static word_t parse_and(Parser *p) {
  word_t val = parse_equality(p);

  while (p->ok && accept(p, TK_AND)) {
    word_t rhs = parse_equality(p);
    if (!p->ok) return 0;
    val = (val && rhs);
  }

  return val;
}

static word_t parse_or(Parser *p) {
  word_t val = parse_and(p);

  while (p->ok && accept(p, TK_OR)) {
    word_t rhs = parse_and(p);
    if (!p->ok) return 0;
    val = (val || rhs);
  }

  return val;
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  if (nr_token == 0) {
    *success = false;
    return 0;
  }

  Parser p;
  p.pos = 0;
  p.ok = true;
  word_t result = parse_or(&p);

  if (p.ok && p.pos != nr_token) {
    printf("Unexpected trailing token (type %d)\n", tokens[p.pos].type);
    p.ok = false;
  }

  if (!p.ok) {
    *success = false;
    return 0;
  }

  *success = true;
  return result;
}
