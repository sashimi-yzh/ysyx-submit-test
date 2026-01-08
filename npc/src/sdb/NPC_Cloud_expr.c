#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "npc.h"
#include "sdb.h"

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>


enum {
	TK_NOTYPE = 256, 
	TK_EQ = 257, TK_NEQ = 258, TK_AND = 259, 
	TK_OR = 260, TK_LT = 261, TK_GT =262, TK_LE =263, TK_GE = 264,
	TK_NUMBER = 265, TK_REG = 266,
	DEREF = 267
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

	{"==", TK_EQ},
	{"!=", TK_NEQ},
	{"<=", TK_LE},  
	{">=", TK_GE},  
	{"&&", TK_AND},
	{"\\|\\|", TK_OR},
	{"<", TK_LT},
	{">", TK_GT},

	{"(0x[0-9a-fA-F]+|[0-9]+)", TK_NUMBER},
	{"\\$[0-9]+", TK_REG},   
	{"\\$[a-zA-Z_][a-zA-Z0-9_]*", TK_REG},	
	
	{"\\+", '+'},         // plus
	{"\\-", '-'},       
	{"\\*", '*'},   
	{"/", '/'},
	{"\\^", '^'},
	{"\\(", '('},
	{"\\)", ')'},
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
			Assert(0,"regex compilation failed: %s\n%s", error_msg, rules[i].regex);
		}
	}
}

typedef struct token {
	int type;
	char str[32];
} Token;

static Token tokens[65536];
static int nr_token;

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

				//Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
				// 		i, rules[i].regex, position, substr_len, substr_len, substr_start);

				position += substr_len;
				/* TODO: Now a new token is recognized with rules[i]. Add codes
				 * to record the token in the array `tokens'. For certain types
				 * of tokens, some extra actions should be performed.
				 */
				if (nr_token >= sizeof(tokens) / sizeof(tokens[0]) ) {
					printf("Too many tokens! Maximum is %ld.\n", sizeof(tokens) / sizeof(tokens[0]) );
					return false;
				}
				//bool minus = false;
				if(rules[i].token_type == TK_NOTYPE) break;
				//负数处理
				if ( ( (nr_token == 1) ||
					((nr_token > 1) && (tokens[nr_token-2].type != ')') &&(tokens[nr_token-2].type != TK_NUMBER))) 
					&& (tokens[nr_token-1].type == '-') && (rules[i].token_type == TK_NUMBER) )
				{
						tokens[nr_token-1].type = TK_NUMBER;
						strncpy(tokens[nr_token-1].str + 1, substr_start, substr_len);
						break;
				}
				//指针处理
				if ( ( (nr_token == 0) ||
					((nr_token > 0) && (tokens[nr_token-1].type != ')') &&(tokens[nr_token-1].type != TK_NUMBER))) 
					&& (rules[i].token_type == '*') )
				{
						tokens[nr_token].type = DEREF;
						strncpy(tokens[nr_token].str + 1, substr_start, substr_len);
						nr_token++;
						break;
				}
				//非负数OR指针，常规处理
				tokens[nr_token].type = rules[i].token_type;
				strncpy(tokens[nr_token].str, substr_start, substr_len);
				///Log("match rules[%d] = \"%s\"(%d) at position %d with len %d: %.*s\n", i, rules[i].regex, tokens[nr_token].type, nr_token, substr_len, substr_len, tokens[nr_token].str);
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

//void word_t eval(int p, int q, bool *success) ;

bool check_parentheses(int p, int q){
	if( (tokens[p].type == '(') && (tokens[q].type == ')') ){
		int check = 0;
		for(int i = p + 1; i <= q - 1; i++){			
			if(tokens[i].type == '('){check++;} 
			else if(tokens[i].type == ')'){
				check--;
				if(check < 0) {
					return false;
				}
			}
		}
		if(check == 0) return true;
	}
	return false;
}

uint32_t eval(int p, int q, int *success) {
	if (p > q) {
		*success = false;
		puts("p>q");
		return 0;
  	}
  	else if (p == q) {
		if(tokens[p].type == TK_NUMBER){
			if (strncmp("0x", tokens[p].str, 2) == 0)  // 检查字符串是否以"0x"开头
			    {printf("%s\n",tokens[p].str);
    			return strtol(tokens[p].str, NULL, 16);  // 按十六进制转换
				}
			else 
    			return strtol(tokens[p].str, NULL, 10);  // 按十进制转换
		}
		else if(tokens[p].type == TK_REG){
			return isa_reg_str2val(tokens[p].str, success);  // 按十六进制转换
	
		}
		
		else {
			*success = false;
			puts("not number");
			return 0;
		}
	}
	else if (check_parentheses(p, q) == true) {
	/* The expression is surrounded by a matched pair of parentheses.
	 * If that is the case, just throw away the parentheses. */
		return eval(p + 1, q - 1, success);
  	}
	else {
	/* We should do more things here. */
		int op = p, count=0, op_type_12=0; 

		/*寻找主运算符*/
		for(int i = p; i <= q; i++){
			if(tokens[i].type == TK_NUMBER) {continue;}
			else if(tokens[i].type == '('){count++;}
			else if(tokens[i].type == ')'){
				if(count == 0){*success = false; puts("only ')' \n" ); return 0;}
				count--; 
			}
			else if(count > 0){continue;}
			else{
				int i_type = 0;
     			switch (tokens[i].type) {
					case TK_NUMBER: break;
					case '*': i_type = 1; break;
					case '/': i_type = 1; break;

      				case '+': i_type = 2; break;
					case '-': i_type = 2; break;

					case TK_LT: i_type = 3; break;
					case TK_LE: i_type = 3; break;
      				case TK_GT: i_type = 3; break;
					case TK_GE: i_type = 3; break;

					case TK_EQ: i_type = 4; break;
					case TK_NEQ: i_type = 4; break;

					case '^': i_type = 5; break;
					case TK_AND: i_type = 6; break;
					case TK_OR: i_type = 7; break;
      				//default: assert(0);
      			}
				if(op_type_12 <= i_type){
					op = i;
					op_type_12 = i_type;
					i_type = 0;
				}
			}
		}
		if(count != 0){
			*success = false; 
			puts("bad '(' or ')' \n" ); 
			return 0;
		} //括号不匹配运算错误
		
		/*一元运算符(*指针)的处理(从客户计算机的内存中读出一个uint32_t类型的整数.)*/
		if(tokens[op].type == DEREF){
			//printf ("%d,%s\n",tokens[op+1].type,tokens[op+1].str);
			*success = 16;
			return *paddr_read(eval(op + 1, q, success));
		}



    	uint32_t val1 = eval(p, op - 1, success);
		//printf("val1:%u\n",val1);
    	uint32_t val2 = eval(op + 1, q, success);
		//printf("val2:%u\n",val2);
		
		/*求值计算*/
		int op_type = tokens[op].type;
	    //printf("return %u %c %u\n",val1,tokens[op].type,val2);
    	switch (op_type) {
      	case '+': return val1 + val2;
      	case '-': return val1 - val2;
      	case '*': return val1 * val2;
      	case '/':if(val2 == 0){*success = false; return 0;} 
					else { return val1 / val2;}
		case TK_EQ: return val1 == val2;
		case TK_NEQ: return val1 != val2;
		case TK_AND: return val1 && val2;
		case TK_OR: return val1 || val2;
		case TK_LT: return val1 < val2;
		case TK_GT: return val1 > val2;
		case TK_LE: return val1 <= val2;
		case TK_GE: return val1 <= val2;
		case '^': return val1 ^ val2;
      	default: *success = false; return 0;
  		}
	}
}


uint32_t expr(char *e, int *success) {
	if (!make_token(e)) {
		*success = false;
		return 0;
	}
	*success = true;
	/* TODO: Insert codes to evaluate the expression. */
	//TODO();

	//or(int i = 0;i < nr_token; i++)
	//printf("tokens[%d].type:%-3d \t tokens[%d].str:%s\n", i ,tokens[i].type,i,tokens[i].str);
	
	uint32_t result = eval(0, nr_token-1, success);
	memset(tokens, 0, sizeof(tokens));//将tokens清零，方便下一次计算。
	return result;
}
