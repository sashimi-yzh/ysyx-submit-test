#include "common.h"
#include "debug.h"
#include "macro.h"
#include "utils.h"
#include "include.h"
#include <regex.h>
#include <stdlib.h>

enum {
  TK_NOTYPE = 256, TK_EQ, TK_NUM, TK_UNEQ, TK_AND, TK_DEREF, TK_HEX, TK_REG

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
  {"\\-", '-'},		// sub
	  {"\\*", '*'},
	  {"\\/", '/'},
	  {"\\(", '('},
	  {"\\)", ')'},
	  {"==", TK_EQ}, // equal
	  {"!=", TK_UNEQ},
	  {"&&", TK_AND},
	  {"0[xX][0-9a-fA-F]+", TK_HEX},
	  {"[0-9]+", TK_NUM},
	  {"\\$+[a-z]*[0-9]*", TK_REG},

	  //{"\\*", TK_POINT},
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
      printf("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[3200] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;
  bool success;
	bool *ptr_success = &success;
  char name[10]={'\0'};

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        //printf("match rules[%d] = \"%s\" at position %d with len %d: %.*s\n",
        //  i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        switch (rules[i].token_type) {
		case TK_NOTYPE:
		       	//printf("notype\n"); 
			break;
		case '+': 
			tokens[nr_token].type='+';
			tokens[nr_token].str[0]='+';
			nr_token++;
			//printf("add\n"); 
			break;
		case '-': 
			tokens[nr_token].type='-';
			tokens[nr_token].str[0]='-';
			nr_token++;
			//printf("sub\n"); 
			break;
		case '*': 
			tokens[nr_token].type='*';
			tokens[nr_token].str[0]='*';
			nr_token++;
			//printf("mult\n"); 
			break;
		case '/': 
			tokens[nr_token].type='/';
			tokens[nr_token].str[0]='/';
			nr_token++;
			//printf("div\n"); 
			break;
		case TK_NUM: 
			tokens[nr_token].type=TK_NUM;
			int mynum;
			sscanf(substr_start,"%d",&mynum);
			sprintf(tokens[nr_token].str,"%d",mynum);
			nr_token++;
			//printf("NUM:%s\n",tokens[nr_token].str); 
			break;
		case '(': 
			tokens[nr_token].type='(';
			tokens[nr_token].str[0]='(';
			nr_token++;
			//printf("kuohao\n"); 
			break;
		case ')': 
			tokens[nr_token].type=')';
			tokens[nr_token].str[0]=')';
			nr_token++;
			//printf("kuohao2\n"); 
			break;
		case TK_EQ: 
			tokens[nr_token].type=TK_EQ;
			tokens[nr_token].str[0]='=';
			tokens[nr_token].str[1]='=';
			nr_token++;
			break;
		case TK_UNEQ: 
			tokens[nr_token].type=TK_UNEQ;
			tokens[nr_token].str[0]='!';
			tokens[nr_token].str[1]='=';
			nr_token++;
			break;
		case TK_AND: 
			tokens[nr_token].type=TK_AND;
			tokens[nr_token].str[0]='&';
			tokens[nr_token].str[1]='&';
			nr_token++;
			break;
		case TK_HEX: 
			tokens[nr_token].type=TK_HEX;
			int mynum2;
			sscanf(substr_start,"%x",&mynum2);
			sprintf(tokens[nr_token].str,"%d",mynum2);
			nr_token++;
			break;
		case TK_REG: 
			tokens[nr_token].type=TK_HEX;
			word_t regValue;
			int i;
			
			for(i=0;i<substr_len-1;i++) {
				name[i]=*(substr_start+i+1);
			}
			success = 1;
			//printf("%s",name);
			regValue = isa_reg_str2val(name, ptr_success);
      //printf("%x",regValue);
			if(!success) {
				assert(0);
			}
			sprintf(tokens[nr_token].str,"%d",regValue);
			nr_token++;
			break;
    default: printf("error!\n");
    }
		tokens[nr_token].type=rules[i].token_type;	
	
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
bool check_parentheses(int p, int q){
	int i,stack=0;

	for(i=p;i<=q;i++) {
		if(tokens[i].type=='(') {
			stack++;
		}
		if(tokens[i].type==')') {
			stack--;
		}
		if(stack<=0){
			break;
		}
	}

	if(i==q) return true;
	else return false;
	

}
uint32_t eval(int p,int q) {
  if (p > q) {
    /* Bad expression */
		printf("%d,%s\n",p,tokens[p].str);
		printf("%d,%s\n",q,tokens[q].str);
	  assert(0);

  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
	  uint32_t num;
	  sscanf(tokens[p].str,"%u",&num);
	  return num;
  }
  else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1);
  }
  else {
	//pointer
	if(tokens[p].type==TK_DEREF && q==p+1) {
		uint32_t num;
	  	sscanf(tokens[q].str,"%u",&num);
		return mem[num];
	}
	//
	else{
		uint32_t val1,val2;
		int i,op=p,flag=0,flagb=0,flagc=0;
		//find the position of 主运算符
		for(i=p;i<=q;i++) {
			//if there are parentheses, skip it
			if(tokens[i].type=='(') {
				flag++;
			}
			if(tokens[i].type==')') {
				flag--;
			}

			//out of parentheses
			if(flag==0) {
				if(tokens[i].type==TK_AND){
					op=i;
					break;
				}
				if(tokens[i].type==TK_EQ || tokens[i].type==TK_UNEQ) {
					op=i;
					flagb=1;
					//continue;
				}
				if((tokens[i].type=='+' || tokens[i].type=='-') && flagb == 0) {
					op=i;
					flagc=1;
					//printf("op%d\n",op);
					//continue;
				}
				if((tokens[i].type=='*' || tokens[i].type=='/') && flagb == 0 && flagc == 0) {
					op=i;
					//printf("op%d\n",op);

				}
			}
		}
		//op = the position of 主运算符 in the token expression;
		//printf("p %d,op %d\n",p,op - 1);
		//printf("op %d,q %d\n",op + 1,q);
		val1 = eval(p, op - 1);
		val2 = eval(op + 1, q);

		switch (tokens[op].type) {
		case '+': return val1 + val2;
		case '-': return val1 - val2;/* ... */
		case '*': return val1 * val2;/* ... */
		case '/': return val1 / val2;/* ... */
		case TK_EQ: return val1 == val2;
		case TK_UNEQ: return val1 != val2;
		case TK_AND: return val1 && val2;
		default: assert(0);
		}
	}
  }
}


word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  //int i;
  
  //for(i=0;i<nr_token;i++) {
  //	  printf("%d,%s\n",tokens[i].type,tokens[i].str);

  //}
 
  int i;

  for (i = 0; i < nr_token; i++) {
	if (tokens[i].type == '*' && (i == 0 || (tokens[i - 1].type != TK_NUM && tokens[i - 1].type != ')')) ) {
		tokens[i].type = TK_DEREF;
		
	}
  }
  //printf("nrtoken:%d\n",nr_token);


  return eval(0,nr_token-1);

}