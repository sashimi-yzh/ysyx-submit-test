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

#include "memory/paddr.h"
#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
	TK_DEC = 'd',
	TK_HEX = 'h',

	TK_REG = 'r',

	TK_DEREF = 255,

  TK_NOTYPE = 256,
  TK_EQ,
  TK_NEQ,
  TK_AND,


  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {"[ \r\n]+", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"\\-", '-'},         // minus
  {"\\*", '*'},         // multiply
  {"/", '/'},           // divide
  {"\\(", '('},         // left parenthesis
  {"\\)", ')'},         // right parenthesis
						
  {"==", TK_EQ},        // equal
  {"!=", TK_NEQ},      // not equal
  {"&&", TK_AND},       // and

  {"\\$[a-zA-Z]+[0-9]*", TK_REG}, // register
  {"0[xX][0-9a-fA-F]+", TK_HEX}, // hexadecimal

  {"[0-9]+", TK_DEC},   // decimal
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

#define MAX_TOKEN_NUM 3000

static Token tokens[MAX_TOKEN_NUM] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

bool type_expect_nxt_is_expr(int type) {
	switch(type) {
		case '+':
		case '-':
		case '*':
		case '/':
		case TK_EQ:
		case TK_NEQ:
		case TK_AND:
		case '(':
			return true;
		default:
			return false;
	}
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
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

		assert(nr_token < MAX_TOKEN_NUM);

		tokens[nr_token].type = rules[i].token_type;

        switch (rules[i].token_type) {
			case TK_NOTYPE: break;
			case TK_REG:
			case TK_HEX:
			case TK_DEC:{
				assert(substr_len < 32);
				strncpy(tokens[nr_token].str, substr_start, substr_len);
				tokens[nr_token].str[substr_len] = '\0';
				nr_token++;
				break;
			}
			case '*': {
				if(nr_token == 0 
					|| type_expect_nxt_is_expr(tokens[nr_token - 1].type)) {
					tokens[nr_token].type = TK_DEREF;
				}
				nr_token++;
				break;
			}
			default:{
				nr_token++;
				break;
			}
        }

        break;
      }
    }

    if (i == NR_REGEX) {
		printf("char(%d)", e[position]);
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

bool check_parentheses(int p, int q) {
	if(tokens[p].type != '(' || tokens[q].type != ')') {
		return false;
	}
	int cnt = 0;
	for(int i = p + 1; i <= q - 1; i++) {
		if(tokens[i].type == '(') cnt++;
		else if(tokens[i].type == ')') {
			if(cnt == 0) {
				return false;
			}
			else cnt--;
		}
	}
	return cnt == 0;
}

int op_priority(int op) {
	switch(op) {
		case TK_DEREF: return 15;
		case '+':
		case '-': return 12;
		case '*':
		case '/': return 13;
		case TK_AND: return 5;
		case TK_NEQ: return 9;
		case TK_EQ: return 9;
		default: assert(0);
	}
}
bool is_operator(int type) {
	switch(type) {
		case '+':
		case '-':
		case '*':
		case '/':
		case TK_EQ:
		case TK_NEQ:
		case TK_AND:
		case TK_DEREF:
			return true;
		default:
			return false;
	}
}
int find_main_op(int p, int q) {
	int main_op = -1;
	int min_priority = 0x114514;
	int cnt = 0; // parentheses counter for(int i = p; i <= q; i++) {
	for(int i = p; i <= q; i++) {
		if(tokens[i].type == '(') {
			cnt++;
		}
		else if(tokens[i].type == ')') {
			cnt--;
		}
		else if(cnt == 0) { // only consider operators outside parentheses
			if(!is_operator(tokens[i].type)) continue;
			int priority = op_priority(tokens[i].type);
			if(priority <= min_priority) { // right associative
				min_priority = priority;
				main_op = i;
			}
		}
	}
	assert(main_op != -1);
	return main_op;
}

word_t eval(int p, int q, bool *success) {
	*success = true;
  if (p > q) {
	*success = false;
	return 0;
  }
  else if (p == q) {
	/* Single token.
	 * For now this token should be a number.
	 * Return the value of the number.
	 */
	if(tokens[p].type == TK_DEC) {
		return atoi(tokens[p].str);
	}
	else if(tokens[p].type == TK_HEX) {
		unsigned int val;
		sscanf(tokens[p].str, "%x", &val);
		return val;
	}
	else if(tokens[p].type == TK_REG) {
		 //printf("Evaluating register %s\n", tokens[p].str);
		 word_t v = isa_reg_str2val(tokens[p].str + 1, success);
		 if(!(*success)) {
			 printf("Error: unknown register %s\n", tokens[p].str);
			 return 0;
		 }
		 return v;
	}
	else {
		*success = false;
		return 0;
	}
  }
  else if (check_parentheses(p, q) == true) {
	/* The expression is surrounded by a matched pair of parentheses.
	 * If that is the case, just throw away the parentheses.
	 */
	return eval(p + 1, q - 1, success);
  }
  else {
	  int op = find_main_op(p, q);
	  word_t val1 = 0;
	  if(tokens[op].type != TK_DEREF){
		  val1 = eval(p, op - 1, success);
		  if(!(*success)) return 0;
	  }
	  word_t val2 = eval(op + 1, q, success);
	  if(!(*success)) return 0;
	  switch(tokens[op].type) {
		  case '+': return val1 + val2;
		  case '-': return val1 - val2;
		  case '*': return val1 * val2;
		  case '/': {
				//assert(val2 != 0);
				if(val2 == 0) {
					*success = false;
					printf("Error: division by zero\n");
					return 0;
				}
				return val1 / val2;
		  }
		  case TK_EQ: return val1 == val2;
		  case TK_NEQ: return val1 != val2;
		  case TK_AND: return val1 && val2;
		  case TK_DEREF: {
				return paddr_read(val2, 4);
				break;
		  }
  		  default: assert(0);
	  }
  }
  *success = false;
  return 0;
}

word_t expr(char *e, bool *success) {
	assert(e != NULL);
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  return eval(0, nr_token - 1, success);
}
