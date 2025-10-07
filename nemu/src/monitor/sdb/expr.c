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
#include <sys/types.h>
#include <regex.h>
#include "memory/paddr.h"


enum {
	NOTYPE = 256, 
	HEX, 
	NUM,
	REG ,
	EQ,
	NOTEQ , 
	AND, 
	OR,
	ADDR,
	NEGATIVE,
	/* TODO: Add more token types */

};

static struct rule {
	char *regex;
	int token_type;
} rules[] = {

	/* TODO: Add more rules.
	 * Pay attention to the precedence level of different rules.
	 */
	{" +",	NOTYPE},				
	{"0x[0-9,a-f]+",HEX},				
	{"[0-9]+",NUM},				
	{"\\$[a-zA-Z0-9]{2,4}",REG},			
	{"\\(",'('},					
	{"\\)",')'},					
	{"\\+", '+'},					
	{"==", EQ},					
	{"\\-",'-'},					
	{"\\*",'*'},					
	{"\\/",'/'},					
	{"!=",NOTEQ},					
	{"&&",AND},					
	{"\\|\\|",OR},					
	{"\\!",'!'},						
	{"\\|",'|'},				
	{"\\&",'&'},				
	{"\\^",'^'},				
	{"\\*0x[0-9,a-f]+",ADDR}	,	
	{"\\-[0-9]+",NEGATIVE}, 	
};

#define NR_REGEX (sizeof(rules) / sizeof(rules[0]) )

static regex_t re[NR_REGEX];

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
	int i;
	char error_msg[128];
	int ret;

	for(i = 0; i < NR_REGEX; i ++) {
		ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
		if(ret != 0) {
			regerror(ret, &re[i], error_msg, 128);
			Assert(ret == 0, "regex compilation failed: %s\n%s", error_msg, rules[i].regex);
		}
	}
}

typedef struct token {
	int type;
	char str[32];
} Token;

Token tokens[1000000];
int nr_token;

static bool make_token(char *e) {
	int position = 0;
	int i;
	regmatch_t pmatch;
	
	nr_token = 0;

	while(e[position] != '\0') {
		/* Try all rules one by one. */
		for(i = 0; i < NR_REGEX; i ++) {
			if(regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
				char *substr_start = e + position;
				int substr_len = pmatch.rm_eo;

				
				position += substr_len;

				/* TODO: Now a new token is recognized with rules[i]. Add codes
				 * to record the token in the array `tokens'. For certain types
				 * of tokens, some extra actions should be performed.
				 */

				switch(rules[i].token_type) {
					case NOTYPE: 
								break;
					default: /*panic("please implement me");*/
					tokens[nr_token].type=rules[i].token_type;
					sprintf(tokens[nr_token].str,"%.*s",substr_len,substr_start);
					nr_token++;
				}
				break;
			}
		}

		if(i == NR_REGEX) {
			printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
			return false;
		}
	}

	return true; 
}
bool matchError;
bool check_parentheses(int p,int q)
{
	int count=0;
	int i;
	if(tokens[p].type!='('||tokens[q].type!=')')
		{return false;}
	else {
		for(i=p ; i<=q ; i++)
		{
			if(count==0&&i!=p&&i!=q)
			{
				return false;}
			if(tokens[i].type=='('){
				count++;
			}
			else if(tokens[i].type==')'){
				count--;}
		}
			if(i<q && count==0)return false;
			}
			if(count!=0)return false;
	matchError=true;
	return true;
}
int Get_priority(int n)
{
	switch(n)
	{
		case EQ: return 0;
		case NOTEQ: return 0;
		case '|':return 3;
		case '&':return 4;
		case '^':return 4;
		case '!': return 2;
		case OR: return 1;
		case AND: return 2;
		case '+': return 4;
		case '-': return 4;
		case '*': return 5;
		case '/': return 5;
		case NEGATIVE: return 8;
		case ADDR: return 9;
		default: return 10;
	}
}
int find_domanite_op(int p,int q)
{
	int i,posit,cnt=0,op1=10;
	posit=p;
	for(i=p;i<=q;i++)
	{
		if(tokens[i].type==')')cnt++;
		else if(tokens[i].type=='(')cnt--;
		if(Get_priority(tokens[i].type)<=op1&&cnt==0)
		{
			op1=Get_priority(tokens[i].type);
			posit=i;
		}
	}
	return posit;
}
bool division_zero=false;
uint32_t eval(int p,int q)
{
	int op; 
	uint32_t val1,val2;
	uint32_t ans=0;
	
	
	bool flag = false;
	if(p>q){
		;
	}
	else if(p==q)
	{
		if(tokens[p].type==NUM){
			sscanf(tokens[p].str,"%d",&ans);
			return ans;
		}
		else if(tokens[p].type==HEX)
		{
			sscanf(tokens[p].str+2,"%x",&ans);
			return ans;
		}
		else if(tokens[p].type==REG)
		{
			
			return isa_reg_str2val(tokens[p].str+1,&flag);
		}
		
	}
	else if(check_parentheses(p,q))
	{
		return eval(p+1,q-1);
	}
	else {
		op=find_domanite_op(p ,q);
	
       		val1=eval(p,op-1);
	   	val2=eval(op+1,q);
	      switch(tokens[op].type)
		  {
	  	
		  case EQ: 		return val1==val2;
		  case NOTEQ: 	return val1!=val2;
		  case '!': 	return !val2;
		  case OR: 		return val1||val2;
		  case AND:		return val1&&val2;
		  case '+': 	return val1+val2;
		  case '-' : 	return val1-val2;
		  case '*': 	return val1*val2;
		  case '/':
		if(val2 == 0){
		    printf("division can't zero;\n");
		    division_zero = true;
		    
		    return -1;
		}	
		return (int)(val1) / (int)(val2);
		  
		  case '|': 	return val1|val2;
		  case '&': 	return val1&val2;
		  case '^':		return val1^val2;
		  case NEGATIVE:        return -val2;
		  case ADDR:             return paddr_read(val2,4);
		  default: assert(0);
	  }
	}
	matchError=true;
	return ans;
}
uint32_t expr(char *e, bool *success, bool *division_by_zero) {
	*success = true;
	if(!make_token(e)) {
		*success = false;
		return 0;
	}
	/* TODO: Insert codes to evaluate the expression. */
	/*panic("please implement me");*/
	
	for(int i=0;i<nr_token;i++)
	{
		if(tokens[i].type=='-' && (i==0||tokens[i-1].type=='('))
		{
			tokens[i].type=NEGATIVE;
		}
		if(tokens[i].type=='*' && ( i==0||tokens[i-1].type=='('))
		{
			tokens[i].type=ADDR;
		}
	}
	uint32_t result=eval(0,nr_token-1);
	if(!division_zero){
	return result;
	}
	else{
	return -1;
	}
}
