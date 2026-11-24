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

#include <isa.h>
#include <common.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <memory/paddr.h>

#define MAX_LINE_LENGTH 512
#define MAX_EXPR_LENGTH 256

enum {
  TK_NOTYPE = 256, TK_EQ, TK_NEQ, TK_AND, TK_HEX, TK_NUM, TK_REG, TK_LPAREN, TK_RPAREN, TK_DEREF, TK_NG

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
  {"\\+", '+'},         // plus
  {"-", '-'},           // minus
  {"\\*", '*'},         // multiply
  {"/", '/'},           // divide
  {"%", '%'},           // modulo

  {"==", TK_EQ},        // equal
  {"!=", TK_NEQ},       // not equal
  {"&&", TK_AND},       // logical and

  {"0[xX][0-9a-fA-F]+", TK_HEX},    // integer number
  {"[0-9]+", TK_NUM},    // integer number
  {"\\$[a-zA-Z0-9][a-zA-Z0-9]*", TK_REG},  // identifier

  /* Brackets */
  {"\\(", TK_LPAREN},         // left parenthesis
  {"\\)", TK_RPAREN},         // right parenthesis
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

static Token tokens[512] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      // rm_so == 0 ensures that we start from beginning each time for every token
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

#if 0
        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);
#endif

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
            case TK_NOTYPE:
              break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case ')':
              tokens[nr_token].type = rules[i].token_type;
              nr_token++;
              break;

            case TK_EQ:
              tokens[nr_token].type = TK_EQ;
              strncpy(tokens[nr_token].str, "==", sizeof(tokens[nr_token].str));
              nr_token++;
              break;

            case TK_HEX:
              tokens[nr_token].type = TK_HEX;
              strncpy(tokens[nr_token].str, substr_start, substr_len);
              tokens[nr_token].str[substr_len] = '\0';
              nr_token++;
              break;

            case TK_NUM:
              tokens[nr_token].type = TK_NUM;
              strncpy(tokens[nr_token].str, substr_start, substr_len);
              tokens[nr_token].str[substr_len] = '\0';
              nr_token++;
              break;

            case TK_REG:
              tokens[nr_token].type = TK_REG;
              strncpy(tokens[nr_token].str, substr_start, substr_len);
              tokens[nr_token].str[substr_len] = '\0';
              nr_token++;
              break;

            default:
              tokens[nr_token].type = rules[i].token_type;
              strncpy(tokens[nr_token].str, substr_start, substr_len);
              tokens[nr_token].str[substr_len] = '\0';
              nr_token++;
              break;
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      Log("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

bool check_parentheses(int p, int q) {
    if (tokens[p].type != TK_LPAREN || tokens[q].type != TK_RPAREN) {
        return false;
    }
    int count = 0;
    for (int i = p + 1; i < q; i++) {
        if (tokens[i].type == TK_LPAREN) count++;
        if (tokens[i].type == TK_RPAREN) count--;
        if (count < 0) return false;
    }
    return count == 0;
}

int find_main_operator(int p, int q) {
    int op = -1;
    int level = 0;
    int min_priority = 10;
    int priority = 0;

    for (int i = p; i <= q; i++) {
        if (tokens[i].type == TK_LPAREN) {
            level++;
        } else if (tokens[i].type == TK_RPAREN) {
            level--;
        } else if (level == 0) {
            priority = 0;
            if (tokens[i].type == '*' || tokens[i].type == '/') {
                priority = 4;
            } else if (tokens[i].type == '+' || tokens[i].type == '-') {
                priority = 3;
            } else if (tokens[i].type == TK_EQ || tokens[i].type == TK_NEQ) {
                priority = 2;
            } else if (tokens[i].type == TK_AND) {
                priority = 1;
            }

            if (priority > 0 && priority <= min_priority) {
                min_priority = priority;
                op = i;
            }
        }
    }

    return op;
}

uint32_t eval(int p, int q) {
    if (p > q) {
        Log("Bad expression\n");
        exit(1);
    } else if (p == q) {
        if (tokens[p].type == TK_NUM) {
          return strtoul(tokens[p].str, NULL, 10);
        } else if (tokens[p].type == TK_HEX) {
          return strtoul(tokens[p].str, NULL, 16);
        } else if (tokens[p].type == TK_REG) {
          bool success = false;
          uint32_t val = isa_reg_str2val(tokens[p].str + 1, &success);
          if (success)
            return val;
          Log("Error reg names and use 0 as default value\n");
            return 0;
        } else {
          Log("Error: Single token is not a number.\n");
          exit(1);
        }
    } else if (check_parentheses(p, q)) {
      return eval(p + 1, q - 1);
    } else if(tokens[p].type == TK_DEREF) {
      uint32_t addr = eval(p + 1, q);
      return (uint32_t )*guest_to_host(addr); 
    } else {
        int op = find_main_operator(p, q);

        if (op == -1) {
            Log("Error: No main operator found.\n");
            exit(1);
        }

        uint32_t val1 = eval(p, op - 1);
        uint32_t val2 = eval(op + 1, q);

        switch (tokens[op].type) {
            case '+':
                return val1 + val2;
            case '-':
                return val1 - val2;
            case '*':
                return val1 * val2;
            case '/':
                if (val2 == 0) {
                    Log("Error: Division by zero.\n");
                    exit(1);
                }
                return val1 / val2;
            case TK_EQ:
              return (val1 == val2);
            case TK_NEQ:
              return (val1 != val2);
            case TK_AND:
              return (val1 && val2);
            default:
                Log("Error: Unknown operator.\n");
                exit(1);
        }
    }
}

word_t expr(char *e, bool *success) {
  uint32_t res;
  int i;

  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  // After token analysis, handle the TK_DEREF specially
  for (i = 0; i < nr_token; i ++) {
    if (tokens[i].type == '*' &&
        (i == 0 || tokens[i - 1].type == '+' ||
         tokens[i - 1].type == '-' ||
         tokens[i - 1].type == '*' ||
         tokens[i - 1].type == '/' ||
         tokens[i - 1].type == TK_EQ ||
         tokens[i - 1].type == TK_NEQ ||
         tokens[i - 1].type == TK_AND)) {
      tokens[i].type = TK_DEREF;
    }

  // also handle negative symbol here
  for (i = 0; i < nr_token; i ++) {
    if (tokens[i].type == '-' &&
        (i == 0 || tokens[i - 1].type == TK_LPAREN)) {
      tokens[i].type = TK_NG;
    }
  }
}

  /* TODO: Insert codes to evaluate the expression. */
  res = eval(0, nr_token - 1);

  //Log("res: 0x%x %u\n", res, res);
  *success = true;

  return res;
}

#ifdef CONFIG_EXPR_TEST
int unit_test_expr_once (const char *input)
{
  int expected_value;
  bool status;
  char expr_buf[MAX_EXPR_LENGTH];

  if (sscanf(input, "%u %[^\n]", &expected_value, expr_buf) != 2) {
    Log("Invalid input format\n");
    return -1;
  }

  int actual_value = expr(expr_buf, &status);

  Log("Expected: %u, Actual: %u, Expression: %s\n",
          expected_value, actual_value, expr_buf);

  if (expected_value != actual_value)
    return -1;

  return 0;
}

void unit_test_expr(void)
{
  char line[MAX_LINE_LENGTH];
  int line_cnt = 0;
  int corr_cnt = 0, incorr_cnt = 0, result = 0;

  FILE *file = fopen("./tools/gen-expr/input", "r");
  if (file == NULL) {
    Log("Could not open input file\n");
    return;
  }

  while (fgets(line, sizeof(line), file)) {
    line[strcspn(line, "\n")] = 0;

    result = unit_test_expr_once(line);
    line_cnt++;

    Log("Now at line %d: %s\n", line_cnt, line);

    if (!result) {
      corr_cnt++;
    }
    else if (result == -1) {
      incorr_cnt++;
      Log("Incorrect result at line %d: %s\n", line_cnt, line);
    }
    else {
      Log("Error parsing line %d: %s\n", line_cnt, line);
    }
  }

  Log("Processed %d lines. Correct: %d, Incorrect: %d\n",
          line_cnt, corr_cnt, incorr_cnt);

  fclose(file);
}
#endif