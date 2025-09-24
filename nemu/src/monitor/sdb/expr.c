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

#include <assert.h>
#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <errno.h>
#include <memory/paddr.h>

enum {
	TK_NOTYPE = 256, 
	TK_H_NUM, TK_NUM, TK_REG, 
	TK_PARENS_L, TK_PARENS_R,
	TK_PLUS, TK_DASH, TK_MUL, TK_DIV,  
	TK_EQ, TK_NEQ, TK_LOGIC_AND,
	TK_MINUS, TK_DEREF,
	TK_U,

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
												//
	{"0x[0-9a-f]+", TK_H_NUM},
	{"[0-9]+", TK_NUM},
	{"\\$[\\$0-9a-z]+", TK_REG},

	{"\\(", TK_PARENS_L},
	{"\\)", TK_PARENS_R},

  {"\\+", TK_PLUS},         // plus
	{"-", TK_DASH},
	{"\\*", TK_MUL},
	{"/", TK_DIV},

  {"==", TK_EQ},        // equal
	{"!=", TK_NEQ},
	{"&&", TK_LOGIC_AND},

	{"u", TK_U},
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

static Token tokens[2500] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e, int *q) {

  int position = 0;
  int i;
	int count = 0;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        int substr_len = pmatch.rm_eo;

				//printf("e = %s\n", e+position);
        //char *substr_start = e + position;
        //Log("match rules[%d] =  %-7s at position %d with len %d: %.*s\n",
        //    i, rules[i].regex, position, substr_len, substr_len, substr_start);


        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
					case TK_U:
					case TK_NOTYPE: break;
          default: 
						Assert(substr_len < 32, "Token str buffer is overflowed.\n");
						tokens[count].type = rules[i].token_type;
						if (tokens[count].type == TK_REG) {
							memcpy(tokens[count].str, &e[position + 1], substr_len - 1);
						}
						else {
							memcpy(tokens[count].str, &e[position], substr_len);
						}
						count++;
						break;
        }

        position += substr_len;
				//printf("match token = \"%s\", tokens[%d].type = %d, tokens[%d].str= \"%s\"\n", 
				//				rules[i].regex, count-1, tokens[count-1].type, count-1, tokens[count-1].str);

        break;
      }
    }

    if (i == NR_REGEX) {
      panic("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

	nr_token = count;
	*q = nr_token - 1;

  return true;
}



static bool check_parentheses(int p, int q) {
	
	bool checkp = true;
	int countl = 0, countr = 0;

	if (tokens[p].type == TK_PARENS_L&& tokens[q].type == TK_PARENS_R) {
		for (int i = p + 1; i < q; i++) {
			if (tokens[i].type == TK_PARENS_L) {
				countl++;
			}
			if (tokens[i].type == TK_PARENS_R) {
				countr++;
			}
			if (countl < countr) {
				checkp = false;
			}
		}
		if (countl != countr) {
			panic("Invalid Expression [check_parentheses].\n");
		}
	}
	else {
		checkp = false;
	}

	return checkp;
}

static int check_op(int p, int q) {

	int op = 0;
	int token_position[2000] = {};
	int count_p = 0;
	int nr_token_position = 0;
	int count_as = 0;
	int count_md = 0;
	int count_logic = 0;
  int count_eq = 0;

	/* 思路：
	 * 1、逐个token扫描，遇到 "(" 计数加一，遇到 ")" 计数减一，
	 * 如果遇到运算符时，计数不等于0，则不可能是主运算符，
	 * 等于0则把位置放到候补数组里。
	 * 2、候补数组逐个扫描，按结合律，op总是等于同优先级的下一个运算符，
	 * 用count_as表示是否有"+"或"-"，如果有，"*""/"舍弃，count_md表示是否有"*"或"/"，
	 * 如果两者都等于0，取op为"=="或"!="或"&&"
	 * 3、扫描结束，即得op
	 */
	for (int i = p; i <= q; i++) {
		switch (tokens[i].type) {
			case TK_PARENS_L: 
				count_p++; 
				break;
			case TK_PARENS_R:
				count_p--;
				break;
			case TK_PLUS:
			case TK_DASH:
			case TK_MUL:
			case TK_DIV:
			case TK_EQ:
			case TK_NEQ:
			case TK_LOGIC_AND:
			case TK_MINUS:
			case TK_DEREF:
				if (count_p == 0) {
					token_position[nr_token_position] = i;
					nr_token_position++;
				}
				break;
		}
	}

	for (int j = nr_token_position - 1; j >= 0; j--) {
		switch ( tokens[ token_position[j] ].type ) {
			case TK_LOGIC_AND:
				op = token_position[j];
				count_logic++;
				break;
			case TK_EQ:
			case TK_NEQ:
				if (count_logic == 0) {
					op = token_position[j];
				}
        count_eq++;
				break;
			case TK_PLUS:
			case TK_DASH:
        if (count_logic == 0 && count_eq == 0) {
          op = token_position[j];
        }
        count_as++;
				break;
			case TK_MUL:
			case TK_DIV:
				if (count_logic == 0 && count_eq == 0 && count_as == 0) {
					op = token_position[j];
				}
				count_md++;
				break;
			case TK_MINUS:
			case TK_DEREF:
				if (count_as == 0 && count_md == 0 && count_logic == 0 && count_eq == 0) {
					op = token_position[j];
				}
				break;
		}
	}

	return op;
}

static word_t eval(int p, int q) {

	word_t val;

	if (p > q) {
		panic("Expresstion p = %d and q = %d position wrong.", p, q);
 	}
 	else if (p == q) {
 	  /* Single token.
 	   * For now this token should be a number.
 	   * Return the value of the number.
 	   */
		switch (tokens[p].type) {
			case TK_NUM: val = strtoul(tokens[p].str, NULL, 0);	break;
			case TK_H_NUM: val = strtoul(tokens[p].str, NULL, 0); break;
			default: //TK_REG
				bool s = false; 
				val = isa_reg_str2val(tokens[p].str, &s); 
				if (s == false) {
				printf(ANSI_FG_RED "no reg \"$%s\", value invalid.\n" 
							 ANSI_NONE, tokens[p].str);
				}
				break;
		}
		memset(tokens[p].str, 0, sizeof(tokens[p].str));

		return val;
 	}
 	else if (check_parentheses(p, q) == true) {
 	  /* The expression is surrounded by a matched pair of parentheses.
 	   * If that is the case, just throw away the parentheses.
 	   */
 	  return eval(p + 1, q - 1);
 	}
 	else {
		word_t val1;
		word_t val2;
		int op;

		//废弃：自己想的不成熟算法
		//不考虑带括号的负数，那么负数仅出现在子表达式长度为2时
		//if (tokens[p].type == TK_DASH && (q - p) == 1) {
		//	val = strtoul(tokens[q].str, NULL, 10);	
		//	memset(tokens[p].str, 0, sizeof(tokens[p].str));
		//	memset(tokens[q].str, 0, sizeof(tokens[p].str));
		//	return -val;
		//}

 	  op = check_op(p, q);

		if (tokens[op].type == TK_MINUS) {
			val = -eval(p + 1, q);
		}else if (tokens[op].type == TK_DEREF) {
			memcpy(&val, guest_to_host(eval(p + 1, q)), sizeof(word_t));
		}
		else {

			val1 = eval(p, op - 1);
 	  	val2 = eval(op + 1, q);

 	  	switch (tokens[op].type) {
				case TK_PLUS: val = val1 + val2; break;
 	  		case TK_DASH: val = val1 - val2; break;
 	  		case TK_MUL: val = val1 * val2; break;
 	  		case TK_DIV: val = val1 / val2; break;
				case TK_EQ: val = val1 == val2; break;
				case TK_NEQ: val = val1 != val2; break;
				case TK_LOGIC_AND: val = val1 && val2; break;
 	  		default: panic("Operator symbol \"%s\"is correct.", tokens[op].str);
 	  	}
		}
 	}

	return val;
}

word_t expr(char *e, bool *success) {

	int p = 0;
	int q = 0;
	word_t val;
	
  if (!make_token(e, &q)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */

	//identify minus and pointer.
	for (int i = 0; i < nr_token; i++) {
		if (tokens[i].type == TK_MUL || tokens[i].type == TK_DASH) {
			if (i == 0) tokens[i].type = (tokens[i].type == TK_MUL) ? TK_DEREF : TK_MINUS;
			else if (tokens[i-1].type == TK_NUM || tokens[i-1].type == TK_H_NUM ||
							 tokens[i-1].type == TK_REG || tokens[i-1].type == TK_PARENS_R) {
			}
			else {
				tokens[i].type = (tokens[i].type == TK_MUL) ? TK_DEREF : TK_MINUS;
			}
		}
	}

	val = eval(p, q);

	//printf(ANSI_FG_YELLOW "The result = " ANSI_NONE "%u\n", val);

  return val;
}

void p() {

  uint32_t val = 0;
  bool success = true;
	int scan;

  char *e = malloc(4096*sizeof(char) + 1);
  printf("请输入表达式：");
  scan = scanf("%[^\n]", e);
	if (scan <= 0) {
		panic("scanf failed, return value = %d\n.", scan);
	}
  printf("e = %s\n", e);
  if (strcmp(e, "q") == 0) return;
  
  val = expr(e, &success);
  if (!success) {
    printf("val invalid.\n");
  }

  printf("表达式的值为：%u\n", val);
  free(e);
}

//test expr function
void test () {

  int incorrect = 0;
  int count = 0;
  char line[4096 + 32] = {};

  FILE *file;
  file = fopen("/home/xhf/ysyx-workbench/nemu/tools/gen-expr/input.txt", "r");

  if (file == NULL) {
    printf("file open failed.\n");
    printf("Error %d \n", errno);
    return;
  }

  while(fgets(line, sizeof(line)/sizeof(char)-1, file) != NULL) {
    count++;
    bool success = true;
    word_t val;
    word_t result;
    char *e = malloc(5000*sizeof(char));

    sscanf(line, "%u %[^\n]", &result, e);

    //printf("result = %u, e = %s\n", result, e);

    val = expr(e, &success);
    if (!success) {
      printf("val invalid in line %d.\n", count);
      continue;
    }

    if (result != val) {
      printf(ANSI_FG_RED "val != result  in line %d.\n" ANSI_NONE, count);
      incorrect++;
      //printf("e = %s\nresult = %u, val = %u\n", e, result, val);
      continue;
    }
    else {
      printf("success line %d\n", count);
    }

    free(e);
  }

  printf("number of incorrect = %d\n", incorrect);

  fclose(file);
}

