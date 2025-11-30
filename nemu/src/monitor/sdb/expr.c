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

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <math.h>

enum {
  TK_NOTYPE = 256, TK_EQ, NUM, UNEQ, LEQ, OR, AND, REG, HEX

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
  {"==", TK_EQ},        // equal
	{"\\-", '-'},         // sub
	{"\\(", '('},					// lift parenthesis
	{"\\)", ')'},					// right parenthesis
	{"\\*", '*'},					// multiply
	{"\\/", '/'},					// divisioin
	{"!=", UNEQ},					// uneq
	{"<=", LEQ},			//less or equal
	{"\\|\\|", OR},				// or
	{"\\&\\&", AND},			// and
	{"\\!", '!'},					// !
	{"\\$[a-zA-Z]*[0-9]*", REG},		//reg_name
	{"\\0[xX][0-9a-fA-F]+", HEX},		//hexadecimal-number
	{"[0-9]*", NUM},
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

/***类型转换函数***/
void int2char(int x, char str[]) {
    int tmp_index = 0;
    int tmp_x = x;
    int x_size = 0;
    int flag = 1;
    while(tmp_x) {
        tmp_x /= 10;
        x_size++;
        flag *= 10;
    }
    if (x_size == 0) {
        str[tmp_index++] = '0';
    }
    flag = x_size > 0 ? pow(10, x_size - 1) : 1;
    while(strchr(str, '\0') == NULL) {
        int a = x / flag; 
        x %= flag;
        flag /= 10;
        str[tmp_index++] = a + '0';
    }
    str[tmp_index] = '\0';
}
int char2int(char s[]){
  int s_size = strlen(s);
  int res = 0 ;
  for(int i = 0 ; i < s_size ; i ++) {
		res = res * 10 + (s[i] - '0');
  }
  return res;
}
void uint2char(uint32_t num, char str[]) {
    uint32_t tmp = num;
    int index = 0;
    int isLeadingZero = 1;
    if (num == 0) {
        str[index++] = '0';
        str[index] = '\0';
        return;
    }
    while (tmp > 0) {
        int digit = tmp % 10;
        if (isLeadingZero && digit == 0) {
        } else {
            str[index++] = '0' + digit;
            isLeadingZero = 0;
        }
        tmp /= 10;
    }
    str[index] = '\0';
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
/******/
typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[65536] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;
	size_t elen = strlen(e);
  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
			if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;
/***
        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);			***/
        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
					case TK_NOTYPE:
						break;
          default:
						Assert(nr_token < 65536, "The tokens array has insufficient storage space.");
						Assert(substr_len < 32, "The token is too long");
						tokens[nr_token].type = rules[i].token_type;
						strncpy(tokens[nr_token].str, substr_start, substr_len);
						tokens[nr_token].str[substr_len] = '\0';
						nr_token++;
						break;
        }
				break;
			}
		}
		if(nr_token == (elen+1)) {
			printf("no match at position %d\n%s\n%*.s^\n", position, e, position,"");
			return false;
		}
	}

											/***test tokens***
	for(int j = 0; j < nr_token; j++) {
		printf("%d:%s ", tokens[j].type, tokens[j].str);
	}
	printf("\n");
										 ******/

  return true;
}

bool check_parentheses(int p, int q);
int max(int a, int b);
uint32_t eval(int p, int  q);

word_t paddr_read(paddr_t addr, int len);
uint8_t* guest_to_host(paddr_t paddr);
word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
	*success = true;
	/***reg***/
	for(int i = 0; i < nr_token; i++) {
		if(tokens[i].type == REG) {
			for(int j = 0; j < 31; j++) {
				tokens[i].str[j] = tokens[i].str[j+1];
			}
			bool flag = true;
			uint32_t tmp = isa_reg_str2val(tokens[i].str, &flag);
			if(flag) {
				uint2char(tmp,tokens[i].str);
			}
			else {
				printf("ERROR:read memory.\n");
				return 0;
			}
		}
	}
	/***处理负号***/
	for(int i = 0; i < nr_token; i++) {
		if(tokens[i].type == '-' && (i == 0 || ((tokens[i-1].type != NUM && tokens[i-1].type != HEX) && tokens[i-1].type != ')' ))) {
			printf("The EXPR contains negative signs.\n");
			tokens[i].type = TK_NOTYPE;
			for(int j = 31; j > 0; j--) {
				tokens[i+1].str[j] = tokens[i+1].str[j-1];
			}
			tokens[i+1].str[0] = '-';
			for(int j = 0; j < nr_token; j++) {
				if(tokens[j].type == TK_NOTYPE) {
					for(int k = j+1; k < nr_token; k++) {
						tokens[k-1] = tokens[k];
					}
					nr_token--;
				}
			}
		}
	}
	/***处理取反***/
	for(int i = 0; i < nr_token; i++) {
		if(tokens[i].type == '!') {
			tokens[i].type = TK_NOTYPE;
			int tmp = char2int(tokens[i+1].str);
			if(tmp == 0) {
				memset(tokens[i+1].str, 0, sizeof(tokens[i+1].str));
				tokens[i+1].str[0] = '1';
			}
			else {
				memset(tokens[i+1].str, 0, sizeof(tokens[i+1].str));
			}
			for(int j = 0; j < nr_token; j++) {
				if(tokens[j].type == TK_NOTYPE) {
					for(int k = j + 1; k < nr_token; k++) {
						tokens[k - 1] = tokens[k];
					}
					nr_token--;
				}
			}
		}
	}
	/***处理指针***/
	for (int i = 0; i < nr_token; i ++) {
		if (tokens[i].type == '*' && (i == 0 || ((tokens[i-1].type != NUM && tokens[i-1].type != HEX) && tokens[i-1].type != (int)(')')))) {
			int nrtmp = nr_token;
			bool flag = false;
      word_t tmp = expr(tokens[i+1].str,&flag);
			tokens[i].type = TK_NOTYPE;
			nr_token = nrtmp;
      char s[9];
      if(flag) {
				sprintf(s, "%x", tmp);
				s[8]='\0';
				paddr_t addr = 0;
				sscanf(s, "%x", &addr);
				word_t value = *(uint32_t *)guest_to_host(addr);
				sprintf(tokens[i+1].str, "%u", value);
			}
			else	printf("EXPR Invalid.\n");
			for(int j = 0 ; j < nr_token; j ++) {
				if(tokens[j].type == TK_NOTYPE) {
					for(int k = j +1 ; k < nr_token; k ++) {
					tokens[k - 1] = tokens[k];
					}
					nr_token -- ;
				}
			}
		}
	}
	word_t result = 0;
	int numl = 0,numr = 0;
  for(int i = 0; i < nr_token; i++) {
		if(tokens[i].type == '(')
        numl += 1;
    if(tokens[i].type == ')')
      numr += 1;
		if(numl < numr) {
			printf("ERROR:The brackets don't match.\n");
			return 0;
		}
//			Assert(0, "ERROR:The brackets don't match.\n");
  }
  if(numl != numr) {
		printf("ERROR:The brackets don't match.\n");
		return 0;
//		Assert(0, "ERROR:The brackets don't match.\n");
	}
	result = eval(0, nr_token-1);
	return result;
}

word_t eval(int p, int  q) {
//	printf("p=%d,q=%d\n",p,q);
	if (p > q) {
    /* Bad expression */
//		Assert(0,"ERROR:Bad expression\n");
		printf("ERROR:Bad expression\n");
		return 0;
  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
		return strtol(tokens[p].str, NULL, 0);
  }
  else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1);
  }
  else {
    int op = -1;//the position of 主运算符 in the token expression;
		bool flag = false;
		bool as = false;
		for(int i = p; i <= q; i++) {
			if((tokens[i].type == '(')) {
				int countl = 0, countr = 0;
				for(int j = i; j <= q; j++) {
					if((tokens[j].type == '('))
						countl++;
					if((tokens[j].type == ')'))
						countr++;
					if(countl == countr) {
						i = j;
						break;
					}
				}
			}		//括号优先级
			if(!flag && tokens[i].type == OR) {
				flag = true;
				op = max(op,i);
			}
			if(!flag && tokens[i].type == AND) {
				flag = true;
				op = max(op,i);
			}
			if(!flag && tokens[i].type == UNEQ) {
				flag = true;
				op = max(op,i);
			}
			if(!flag && tokens[i].type == TK_EQ) {
				flag = true;
				op = max(op,i);
			}
			if(!flag && tokens[i].type == LEQ) {
				flag = true;
				op = max(op,i);
			}
      if(!flag && (tokens[i].type == '+' || tokens[i].type == '-')) {
        as = true;
				op = max(op, i);
      }
			if(!flag && (tokens[i].type == '*' || tokens[i].type == '/')) {
				if(as == false) {
					op = max(op, i);
				}
			}
//			printf("%d:%s ", tokens[i].type, tokens[i].str);printf("\n");
//			printf("%d %d %d\n",i,flag,op);
		}

    int val1 = eval(p, op - 1);
    int val2 = eval(op + 1, q);
		int op_type = tokens[op].type;
    switch (op_type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': 
				if(val2 == 0) {
//					Assert(0,"The denominator is zero\n");
					printf("ERROR:The denominator is zero\n");
					return 0;
				}
				else {
					return val1 / val2;
				}
			case TK_EQ: return val1 == val2;
			case UNEQ: return val1 != val2;
			case LEQ: return val1 <= val2;
			case OR: return val1 || val2;
			case AND: return val1 && val2;
      default: 
				//Assert(0,"No op type.\n");
				printf("No op type.\n");
				return 0;
    }
  }
}
//检查一组括号包围
bool check_parentheses(int p, int q) {
  if(tokens[p].type != '(' || tokens[q].type != ')')
    return false;
	else {
		int l = p+1, r = q-1;
		int numl = 0, numr = 0;
		for(int i = l; i <= r; i++) {
			if(tokens[i].type == '(') 
				numl += 1;
			else if(tokens[i].type == ')') 
				numr +=1;
		if(numl < numr)
				return false;
		}
		if(numl != numr)
			return false;
	}
	return true;
}

//algorithm max
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
