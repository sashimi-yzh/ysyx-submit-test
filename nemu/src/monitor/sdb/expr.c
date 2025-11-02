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
#include <memory/paddr.h>
// <isa.h> => <isa_def.h> => <common.h> => <debug.h> => define TODO()

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, TK_EQ,
  TK_NEQ, TK_AND, TK_OR,
  TK_MINUS, TK_DEREF,
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
  {"a", 'a'},{"A", 'A'},
  {"b", 'b'},{"B", 'B'},
  {"c", 'c'},{"C", 'C'},
  {"d", 'd'},{"D", 'D'},
  {"e", 'e'},{"E", 'E'},
  {"f", 'f'},{"F", 'F'},
  {"g", 'g'},{"p", 'p'},{"r", 'r'},{"s", 's'},{"t", 't'}, //reg name
  {"x", 'x'},{"X", 'X'}, //hex
  {"\\$", '$'},
  {"0", '0'},
  {"1", '1'},
  {"2", '2'},
  {"3", '3'},
  {"4", '4'},
  {"5", '5'},
  {"6", '6'},
  {"7", '7'},
  {"8", '8'},
  {"9", '9'},
  {"\\+", '+'},         // plus
  {"\\-", '-'},			//minus
  {"\\-", TK_MINUS},    //MINUS
  {"\\*", '*'},			//mutiply
  {"\\*", TK_DEREF},    //DEREF
  {"\\/", '/'},			//divide
  {"\\(", '('},			//left_bracket
  {"\\)", ')'},			//right_bracket
  {"==", TK_EQ},        //equal
  {"!=", TK_NEQ},		//not equal
  {"&&", TK_AND}, 		//logical and
  {"\\|\\|", TK_OR}			//logical or
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

static Token tokens[32] __attribute__((used)) = {};//contain 32 valid characters at most
static int novc __attribute__((used)) = 0;// number of valid characters

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  novc = 0;
  if(e == NULL){
  	return true;
  }

  while (e[position] != '\0') {
    //printf("%c\n",e[position]);

    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        //char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        //Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //    i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
		//printf("%d %d\n",rules[i].token_type,j);
        switch (rules[i].token_type) {
		  case TK_NOTYPE: break;//tokens[j].type = TK_NOTYPE; strcpy(tokens[j++].str,"\0"); break;}
		  case '+': {tokens[novc].type = '+'; strcpy(tokens[novc++].str,"+"); break;}
		  case '-': {tokens[novc].type = '-'; strcpy(tokens[novc++].str,"-"); break;}
		  case '*': {tokens[novc].type = '*'; strcpy(tokens[novc++].str,"*"); break;}
		  case '/': {tokens[novc].type = '/'; strcpy(tokens[novc++].str,"/"); break;}
		  case '(': {tokens[novc].type = '('; strcpy(tokens[novc++].str,"("); break;}
		  case ')': {tokens[novc].type = ')'; strcpy(tokens[novc++].str,")"); break;}
		  case TK_EQ: {tokens[novc].type = TK_EQ; strcpy(tokens[novc++].str,"=="); break;}
          default: {tokens[novc].type = rules[i].token_type; strcpy(tokens[novc++].str,rules[i].regex);break;}
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



bool check_parentheses(int start, int end){
	bool flag = true;
	int unmatched_left_bracket = 0;
	for(int i = start; i <= end; ++i){
		if(tokens[i].type == '(')
			unmatched_left_bracket ++;
		else if(tokens[i].type == ')')
			unmatched_left_bracket --;

		//exception such as 2*()
        if(unmatched_left_bracket == 0 && i == start)
            flag = false;

		//exception such as ()*() and ()*2
		if(unmatched_left_bracket == 0 && i != end) 
			flag = false;
		
		//exception such as ())
		if(unmatched_left_bracket < 0){
			flag = false;
			printf("bad expression\n"); assert(0);
		}
	}

	//exception such as (()
	if(unmatched_left_bracket){
		flag = false;
		printf("bad expression\n"); assert(0);
	}

	return flag;
}



int locate_main_operator(int start, int end){
	int position_of_operators[end-start+1];
	int priority[end-start+1];
	int j = 0;
	int unmatched_left_bracket = 0;
	for(int i = start; i <= end; ++i){
		if(tokens[i].type == '(')
			unmatched_left_bracket ++;
		if(tokens[i].type == ')')
			unmatched_left_bracket --;
		if(tokens[i].type == '+'||tokens[i].type == '-'||tokens[i].type == '*'||tokens[i].type == '/'||\
				tokens[i].type == TK_MINUS||tokens[i].type == TK_DEREF||tokens[i].type == TK_EQ||\
				tokens[i].type == TK_NEQ||tokens[i].type == TK_AND||tokens[i].type == TK_OR){
			if(unmatched_left_bracket < 0){
				printf("bad expression\n");assert(0);
			}
			else if(unmatched_left_bracket == 0){
				position_of_operators[j] = i;
				if(tokens[i].type == TK_MINUS||tokens[i].type == TK_DEREF)
					priority[j++] = 1;// most priorized
				else if(tokens[i].type == '*'||tokens[i].type == '/')
					priority[j++] = 2;
				else if(tokens[i].type == '+'||tokens[i].type == '-')
					priority[j++] = 3;
				else if(tokens[i].type == TK_EQ||tokens[i].type == TK_NEQ)
					priority[j++] = 4;
				else
					priority[j++] = 5;//least priorized
			}
		}
	}
	
	if(j == 0){// like 1201 or 0x123 or $pc or 2((+/))3 or 2(36) (bad expression)
		return -1;
	}

	int tmp_max = 0;
	int index = j - 1;
	for(int i = j - 1; i >= 0; --i){
		if(priority[i] > tmp_max){
			tmp_max = priority[i];
			index = i;
		}
	}

	//for +, -, *, /, ||, &&, ==, !=, which calculates from left to right
	if(tmp_max > 1)
		return position_of_operators[index];

	//for TK_MINUS, TK_DEREF, which calculates from right to left
	else{
		return position_of_operators[0];
	}

}


word_t eval(int start, int end){
	if (start > end){
		printf("bad expression\n");
		assert(0);
	}

	else if(start == end){//should be a single number ('0'-'9')
		if(tokens[start].type > '9' || tokens[end].type < '0'){
			printf("bad expression\n");
        	assert(0);
		}
		return (word_t)(tokens[start].type - '0');
	}

	else if(check_parentheses(start, end) == true){
		return eval(start + 1, end - 1);
	}

	else{
		int op = locate_main_operator(start, end);

		if(op == -1){// such as 1201 or 0x123 or 2((+/3 or 2(36) (bad expression) 
			word_t sum = 0;
			//case1: 0x123
			if((end-start > 1) && tokens[start].type == '0' &&\
				(tokens[start+1].type == 'x' || tokens[start+1].type == 'X')){
				for(int k = start+2; k <= end; k++){
					sum *= 16;
					if(tokens[k].type >= '0' && tokens[k].type <= '9')
						sum += tokens[k].type - '0';
					else if(tokens[k].type >= 'a' && tokens[k].type <= 'f')
						sum += tokens[k].type - 'a' + 10;
					else if(tokens[k].type >= 'A' && tokens[k].type <= 'F')
						sum += tokens[k].type - 'A' + 10;
					else{
						printf("bad exprssion!\n");
						assert(0);
					}
				}
			}

			//case2: $pc
			else if(tokens[start].type == '$'){
				char tmp[4] = {};
				if(end - start == 2){//pc, a0, t1 ...
					tmp[0] = tokens[start+1].type; tmp[1] = tokens[start+2].type; tmp[2] = '\0';
				}
				else if(end - start == 3){//s10, s11
					tmp[0] = tokens[start+1].type; tmp[1] = tokens[start+2].type; 
					tmp[2] = tokens[start+2].type; tmp[3] = '\0';
				}
				else{
					printf("bad expression!\n");
                    assert(0);
				}

				bool success;
				word_t ret = isa_reg_str2val(tmp, &success);
				if(success)
					sum = ret;
				else{
					printf("bad expression!\n");
					assert(0);
				}
			}

			//case3: 1201
			else{
				for(int k = start; k <= end; k++){
					if(tokens[k].type < '0' || tokens[k].type > '9'){
						printf("bad expression!\n");
						assert(0);
					}
					sum *= 10;
					sum += tokens[k].type - '0';
				}
			}
			return sum;
		}

		//such as 1+3
		//printf("the op is %d\n",op);
		
		switch(tokens[op].type){
			case '+': {return (word_t)(eval(start, op-1) + eval(op+1, end)); break;}
			case '-': {return (word_t)(eval(start, op-1) - eval(op+1, end)); break;}
			case '*': {return (word_t)(eval(start, op-1) * eval(op+1, end)); break;}
			case '/': {
						if(eval(op+1, end) == 0){
							printf("0 divided!\n"); assert(0);
						}
						else
							return (word_t)(eval(start, op-1) / eval(op+1, end)); 
						break;
					  }
			case TK_MINUS:{return -eval(op + 1, end); break;}
			case TK_DEREF:{return (word_t)paddr_read(eval(op+1, end), 1); break;}
			case TK_EQ: {return eval(start, op-1) == eval(op+1, end); break;}
			case TK_NEQ: {return eval(start, op-1) != eval(op+1, end); break;}
			case TK_AND: {return eval(start, op-1) && eval(op+1, end); break;}
			case TK_OR: {return eval(start, op-1) || eval(op+1, end); break;}

			default: {printf("bad expression"); assert(0);}
		}

	}

}





word_t expr(char *e, bool *success, bool *null) {
// e is a string which doesn't contain space
  *null = false;
  *success = true;
  if (!make_token(e)) {//step1: check for invalid char such as @
    *success = false;
    return 0;
  }

  if(novc == 0){
	*null = true;
	return 0;
  }

  //tell the difference between '-' and TK_MINUS, '*' and TK_DEREF
  for(int i = 0; i < novc; ++i){
  	if(tokens[i].type == '-' && (i == 0||tokens[i-1].type == '+'||\
		tokens[i-1].type == '-'||tokens[i-1].type == TK_MINUS||\
		tokens[i-1].type == '*'||tokens[i-1].type == '/'||\
		tokens[i-1].type == '('))
		tokens[i].type = TK_MINUS;
  }
  for(int i = 0; i < novc; ++i){
    if(tokens[i].type == '*' && (i == 0||tokens[i-1].type == '+'||\
        tokens[i-1].type == '-'||tokens[i-1].type == TK_MINUS||\
        tokens[i-1].type == '*'||tokens[i-1].type == TK_DEREF||\
		tokens[i-1].type == '('||tokens[i-1].type == '/'))
        tokens[i].type = TK_DEREF;
  }

  /* TODO: Insert codes to evaluate the expression. */
  return eval(0, novc - 1);
}


