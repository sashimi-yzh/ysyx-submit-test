#include "sdb.h"

#include <isa.h>

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

word_t vaddr_read(word_t address, int length);

enum {
  TOKEN_END = 256,
  TOKEN_NUMBER,
  TOKEN_REGISTER,
  TOKEN_EQ,
  TOKEN_NE,
  TOKEN_LE,
  TOKEN_GE,
  TOKEN_LOGICAL_AND,
  TOKEN_LOGICAL_OR,
  TOKEN_SHIFT_LEFT,
  TOKEN_SHIFT_RIGHT,
  TOKEN_INVALID,
};

typedef struct {
  int kind;
  word_t number;
  char text[32];
} Token;

typedef struct {
  const char *cursor;
  Token token;
  bool valid;
} Parser;

static bool starts_with(const char *text, const char *prefix) {
  return strncmp(text, prefix, strlen(prefix)) == 0;
}

static void next_token(Parser *parser) {
  while (isspace((unsigned char)*parser->cursor)) parser->cursor++;

  const char *start = parser->cursor;
  if (*start == '\0') {
    parser->token.kind = TOKEN_END;
    return;
  }

  if (isdigit((unsigned char)*start)) {
    int base = starts_with(start, "0x") || starts_with(start, "0X") ? 16 : 10;
    char *end = NULL;
    parser->token.number = strtoul(start, &end, base);
    parser->token.kind = end == start ? TOKEN_INVALID : TOKEN_NUMBER;
    parser->cursor = end;
    return;
  }

  if (*start == '$') {
    const char *end = start + 1;
    while (isalnum((unsigned char)*end) || *end == '$') end++;
    size_t length = end - start;
    if (length >= sizeof(parser->token.text)) {
      parser->token.kind = TOKEN_INVALID;
      parser->valid = false;
      return;
    }
    memcpy(parser->token.text, start, length);
    parser->token.text[length] = '\0';
    parser->token.kind = TOKEN_REGISTER;
    parser->cursor = end;
    return;
  }

  static const struct {
    const char *text;
    int kind;
  } pairs[] = {
    {"==", TOKEN_EQ}, {"!=", TOKEN_NE}, {"<=", TOKEN_LE},
    {">=", TOKEN_GE}, {"&&", TOKEN_LOGICAL_AND},
    {"||", TOKEN_LOGICAL_OR}, {"<<", TOKEN_SHIFT_LEFT},
    {">>", TOKEN_SHIFT_RIGHT},
  };

  for (size_t i = 0; i < ARRLEN(pairs); i++) {
    if (starts_with(start, pairs[i].text)) {
      parser->token.kind = pairs[i].kind;
      parser->cursor += 2;
      return;
    }
  }

  if (strchr("+-*/%()<>!&|^~", *start) != NULL) {
    parser->token.kind = *start;
    parser->cursor++;
    return;
  }

  parser->token.kind = TOKEN_INVALID;
  parser->valid = false;
}

static int precedence(int kind) {
  switch (kind) {
    case TOKEN_LOGICAL_OR: return 1;
    case TOKEN_LOGICAL_AND: return 2;
    case '|': return 3;
    case '^': return 4;
    case '&': return 5;
    case TOKEN_EQ: case TOKEN_NE: return 6;
    case '<': case '>': case TOKEN_LE: case TOKEN_GE: return 7;
    case TOKEN_SHIFT_LEFT: case TOKEN_SHIFT_RIGHT: return 8;
    case '+': case '-': return 9;
    case '*': case '/': case '%': return 10;
    default: return 0;
  }
}

static word_t parse_binary(Parser *parser, int minimum_precedence, bool evaluate);

static word_t parse_primary(Parser *parser, bool evaluate) {
  if (parser->token.kind == TOKEN_NUMBER) {
    word_t value = parser->token.number;
    next_token(parser);
    return value;
  }

  if (parser->token.kind == TOKEN_REGISTER) {
    bool success = true;
    word_t value = evaluate ? isa_reg_str2val(parser->token.text, &success) : 0;
    parser->valid = parser->valid && success;
    next_token(parser);
    return value;
  }

  if (parser->token.kind == '(') {
    next_token(parser);
    word_t value = parse_binary(parser, 1, evaluate);
    if (parser->token.kind != ')') parser->valid = false;
    else next_token(parser);
    return value;
  }

  parser->valid = false;
  return 0;
}

static word_t parse_unary(Parser *parser, bool evaluate) {
  int operation = parser->token.kind;
  if (operation != '-' && operation != '*' && operation != '!' && operation != '~') {
    return parse_primary(parser, evaluate);
  }

  next_token(parser);
  word_t value = parse_unary(parser, evaluate);
  if (!evaluate || !parser->valid) return 0;

  switch (operation) {
    case '-': return 0u - value;
    case '*': return vaddr_read(value, 4);
    case '!': return !value;
    case '~': return ~value;
    default: return 0;
  }
}

static word_t apply_binary(Parser *parser, int operation, word_t left, word_t right) {
  switch (operation) {
    case '+': return left + right;
    case '-': return left - right;
    case '*': return left * right;
    case '/': case '%':
      if (right == 0) {
        parser->valid = false;
        return 0;
      }
      return operation == '/' ? left / right : left % right;
    case TOKEN_SHIFT_LEFT: return left << right;
    case TOKEN_SHIFT_RIGHT: return left >> right;
    case '<': return left < right;
    case '>': return left > right;
    case TOKEN_LE: return left <= right;
    case TOKEN_GE: return left >= right;
    case TOKEN_EQ: return left == right;
    case TOKEN_NE: return left != right;
    case '&': return left & right;
    case '^': return left ^ right;
    case '|': return left | right;
    case TOKEN_LOGICAL_AND: return left && right;
    case TOKEN_LOGICAL_OR: return left || right;
    default:
      parser->valid = false;
      return 0;
  }
}

static word_t parse_binary(Parser *parser, int minimum_precedence, bool evaluate) {
  word_t left = parse_unary(parser, evaluate);

  while (parser->valid) {
    int operation = parser->token.kind;
    int current_precedence = precedence(operation);
    if (current_precedence < minimum_precedence) break;

    next_token(parser);
    bool evaluate_right = evaluate;
    if (operation == TOKEN_LOGICAL_AND && left == 0) evaluate_right = false;
    if (operation == TOKEN_LOGICAL_OR && left != 0) evaluate_right = false;

    word_t right = parse_binary(parser, current_precedence + 1, evaluate_right);
    if (evaluate) left = apply_binary(parser, operation, left, right);
  }
  return left;
}

void init_regex(void) {
  /* Kept as a compatibility hook for init_sdb(); no regex setup is needed. */
}

word_t expr(char *input, bool *success) {
  Parser parser = {.cursor = input, .valid = input != NULL};
  if (parser.valid) next_token(&parser);

  word_t value = parser.valid ? parse_binary(&parser, 1, true) : 0;
  parser.valid = parser.valid && parser.token.kind == TOKEN_END;
  *success = parser.valid;
  return parser.valid ? value : 0;
}
