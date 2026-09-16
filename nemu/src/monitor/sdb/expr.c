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

#include <isa.h>
#include <assert.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

word_t paddr_read(paddr_t addr, int len);

enum {
  TK_NOTYPE = 256, TK_EQ,

  /* TODO: Add more token types */
	TK_SUB,TK_MULTIPLY,// 保留类型供判断
	TK_DIVIDE, TK_NUM,
	TK_L, TK_R,
	TK_NEQ, TK_AND, TK_HEX,
	TK_REG,TK_EXPLAIN,
	TK_ADDR,TK_PC
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
 	{"\\*", '*'},      //有两种可能 MULTIPLY EXPLAIN 
	{"-", TK_SUB},				// 减法
	{"/", TK_DIVIDE},					// 除法
	{"0[xX][0-9a-fA-F]+", TK_HEX},// 十六进制
	{"[0-9]+", TK_NUM},// 十进制
	{"\\(", TK_L},// 左括号
	{"\\)", TK_R},// 右括号
	{"!=", TK_NEQ},// 不等于
	{"&&", TK_AND},// and
	{"\\$pc", TK_PC},// pc
	{"[pP][cC]0[xX][0-9a-fA-F]+", TK_ADDR},
	{"^\\$0|^\\$(ra|sp|gp|tp|t[0-6]|s[0-9]|s1[0-1]|a[0-7])", TK_REG}// 寄存器
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
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);// 0 表示成功
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

static Token tokens[1024] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        // char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        //Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //    i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now  a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
					case '+':  
						strcpy(tokens[nr_token].str, "+");
						tokens[nr_token].type = '+';
						nr_token++;
						break;
					case TK_L:
						strcpy(tokens[nr_token].str, "(");
						tokens[nr_token].type = TK_L;
						nr_token++;
						break;
					case TK_R:
						strcpy(tokens[nr_token].str, ")");
						tokens[nr_token].type = TK_R;
						nr_token++;
						break;
					case TK_AND:
						strcpy(tokens[nr_token].str, "&&");
						tokens[nr_token].type = TK_AND;
						nr_token++;
						break;
					case TK_NEQ:
						strcpy(tokens[nr_token].str, "!=");
						tokens[nr_token].type = TK_NEQ;
						nr_token++;
						break;
					case TK_NOTYPE:
						break;
					case TK_EQ:
						strcpy(tokens[nr_token].str, "=");
						tokens[nr_token].type = TK_EQ;
						nr_token++;
						break;
					case '*':
						strcpy(tokens[nr_token].str, "*");
						tokens[nr_token].type = '*';
						nr_token++;
						break;
					case TK_SUB:
						strcpy(tokens[nr_token].str, "-");
						tokens[nr_token].type = TK_SUB;
						nr_token++;
						break;
					case TK_DIVIDE:
						strcpy(tokens[nr_token].str, "/");
						tokens[nr_token].type = TK_DIVIDE;
						nr_token++;
						break;
					case TK_PC:{
						uint32_t pc_get = cpu.pc;
						char pc_str[20];
						sprintf(pc_str, "%u", pc_get);
						strcpy(tokens[nr_token].str, pc_str);
						tokens[nr_token].type = TK_PC;
						nr_token++;
						break;
						}
						// 接下来要重点调试
					case TK_NUM:
						{ 
						assert(pmatch.rm_so != -1);// 匹配是否成功
						char match[pmatch.rm_eo - pmatch.rm_so + 1];
						strncpy(match, e + position + pmatch.rm_so - pmatch.rm_eo, pmatch.rm_eo - pmatch.rm_so);// 获得数据
						match[pmatch.rm_eo - pmatch.rm_so] = '\0';// 末尾添加终止符
						assert(sizeof(match) <= 32);
						strcpy(tokens[nr_token].str, match);
						tokens[nr_token].type = TK_NUM;
						nr_token++;
						break;
						}
					case TK_ADDR:
						{
						assert(pmatch.rm_so != -1);// 匹配是否成功

						int match_len = pmatch.rm_eo - pmatch.rm_so;
						assert(match_len > 4); // 确保匹配长度有效（至少包含 "pc0x" 和一位十六进制数）

						char match[pmatch.rm_eo - pmatch.rm_so - 3];
						strncpy(match, e + position + pmatch.rm_so + 4 - pmatch.rm_eo, pmatch.rm_eo - pmatch.rm_so - 4);// 获得pc0x之外的数据
						match[pmatch.rm_eo - pmatch.rm_so - 4] = '\0';
						// 十六进制字符串转换为无符号十进制整数
						char *endptr;
						uint32_t val = strtoul(match, &endptr, 16);
						assert(sizeof(match) <= 32);
						//printf("%u\n",val);
						// 变成字符串类型
						sprintf(tokens[nr_token].str, "%u", val);
						//printf("%s\n",tokens[nr_token].str);
						// strcpy(tokens[nr_token].str, match);
						tokens[nr_token].type = TK_HEX;
						nr_token++;
						break;
						}
					case TK_HEX:
						{ 
						assert(pmatch.rm_so != -1);// 匹配是否成功

						int match_len = pmatch.rm_eo - pmatch.rm_so;
						assert(match_len > 2); // 确保匹配长度有效（至少包含 "0x" 和一位十六进制数）

						char match[pmatch.rm_eo - pmatch.rm_so - 1];
						strncpy(match, e + position + pmatch.rm_so + 2 - pmatch.rm_eo, pmatch.rm_eo - pmatch.rm_so - 2);// 获得0x之外的数据
						match[pmatch.rm_eo - pmatch.rm_so - 2] = '\0';
						// 十六进制字符串转换为无符号十进制整数
						char *endptr;
						uint32_t val = strtoul(match, &endptr, 16);
						assert(sizeof(match) <= 32);
						//printf("%u\n",val);
						// 变成字符串类型
						sprintf(tokens[nr_token].str, "%u", val);
						//printf("%s\n",tokens[nr_token].str);
						// strcpy(tokens[nr_token].str, match);
						tokens[nr_token].type = TK_HEX;
						nr_token++;
						break;
						}
					case TK_REG:
						{ 
						assert(pmatch.rm_so != -1);// 匹配是否成功
						char match[pmatch.rm_eo - pmatch.rm_so];
						strncpy(match, e + position + pmatch.rm_so - pmatch.rm_eo + 1, pmatch.rm_eo - pmatch.rm_so - 1);// 获得数据
						match[pmatch.rm_eo - pmatch.rm_so - 1] = '\0';
						assert(sizeof(match) <= 32);
						
						bool success = true;
						uint32_t val = isa_reg_str2val(match, &success);// 获得寄存器的值
						// 将值转化为字符串
						char str[20];
						snprintf(str, sizeof(str), "%u", val);// val是十进制，以十进制的形式记录数据
						strcpy(tokens[nr_token].str, str);

						tokens[nr_token].type = TK_REG;
						nr_token++;
						break;
						}
          default: TODO(); 
        }
				//printf();
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
	// 判断是否合法
	if(p > q) return false;

	// 检测括号使用是否合法
	int open_count = 0 ,close_count = 0;
	for(int i = p; i <= q; i++){
		if(tokens[i].type == TK_L)  open_count++;// 左括号的数量
		if(tokens[i].type == TK_R)  close_count++;// 有括号的数量
		if(close_count > open_count) return false;// 如果出现如:( a ))的情况返回错误
		if(close_count == open_count && i != q) return false;// 如果出现形如(4 + 3) * (2 - 1)返回错误
	}

	// 检测数量是否成对	
	if(open_count != close_count) return false;// 不成对判断为错

	if(open_count == 0 && close_count == 0) return false;// 如果没有括号直接判断为错
	// 检测是否包围表达式
	if(tokens[p].type != TK_L || tokens[q].type != TK_R) {
		return false;// 如果第一位或者最后一位不是括号判断为错
	}
	return true;
}

int valid_index(int i, int pos_L, int pos_R, int q){

	if ((i < pos_L || pos_L == -1) || (i > pos_R || pos_R == q + 1)){
		return 1;
	}
	else {
		return 0;
	}
}


int eval(int p, int q, bool* signal){
	if (p > q){
		printf("invalid expression: p > q\n");
		return 0;
	}
	else if (p == q){
		if (tokens[p].type == TK_NUM){
		  return atoi(tokens[p].str);
		}
		else {
			//uint32_t value = strtoul(tokens[p].str, NULL, 16);
			uint32_t value = atoi(tokens[p].str);
			return value;
		}

	}
	// 解引用处理
	else if (p + 1 == q && tokens[p].type == TK_EXPLAIN){
		uint32_t addr = 0;

		if (tokens[q].type == TK_NUM) {
			addr = atoi(tokens[q].str);
		}
		else if (tokens[q].type == TK_HEX) {
			//获 得地址	
			char *endptr;
			char* addr_str = tokens[q].str;
			addr = strtoul(addr_str, &endptr, 10);
			if (*endptr != '\0') {			
				printf("十六进制解析错误，停止于: %s\n", endptr);
				*signal = 1;
				return 0;
			} 
		}
		uint32_t mem_val = paddr_read(addr,4);
		return mem_val;
	}
	else if (check_parentheses(p, q) == true){
	
		return eval(p + 1, q - 1, signal);
	}
	else {
		int op = -1;

		int L_count = 0, R_count = 0;

		// 判断加减法
		for (int i = q; i >= p; i --) {
			if (tokens[i].type == TK_L) L_count ++;
			if (tokens[i].type == TK_R) R_count ++;
			if (L_count != R_count)	continue;

			if (tokens[i].type == '+' || tokens[i].type == TK_SUB) {
        op = i;
				break;
			}

	}
		// 如果没有加减法判断乘除法
		if (op == -1){
			L_count = 0, R_count = 0;
			for (int i = q; i >= p; i --) {
				if (tokens[i].type == TK_L) L_count ++;
				if (tokens[i].type == TK_R) R_count ++;
				if (L_count != R_count)	continue;

				if (tokens[i].type == TK_MULTIPLY || tokens[i].type == TK_DIVIDE) {
					op = i;
					break;
				}
			}
		}

// 如果还没有则报错
			if (op == -1) {
				printf("op Error\n");
				return 0;
			}

			int32_t val1 = eval(p, op - 1, signal);
			int32_t val2 = eval(op + 1, q, signal);

		switch (tokens[op].type){
			case '+': 
				return val1 + val2;
			case TK_MULTIPLY:
				return val1 * val2;
			case TK_SUB:
				return val1 - val2;
			case TK_DIVIDE:
				if (val2 == 0){
					printf("除数不能为0\n");
					*signal = false;
					return 0;
				}
				else {
				return val1 / val2;
				}
			default:
			  printf("Unsupported operator: %d\n", tokens[op].type);
				return 0;	
		}
	}
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
		printf("make token Error\n");
    return 0;
  }
	
  /* TODO: Insert codes to evaluate the expression. */
	*success = true;

	int bool_index = -1;
	for (int i = 0; i < nr_token; i ++) {

		if (tokens[i].type == '*' ) {
			if( (i == 0 || tokens[i - 1].type == '+' || tokens[i - 1].type == TK_SUB || tokens[i - 1].type == TK_MULTIPLY || tokens[i - 1].type == TK_DIVIDE || tokens[i - 1].type == TK_L)){
				tokens[i].type = TK_EXPLAIN;
			}
			else {
				tokens[i].type = TK_MULTIPLY;
			}
		}
		// 如果存在逻辑运算符记录索引
		if (tokens[i].type == TK_EQ || tokens[i].type == TK_AND || tokens[i].type == TK_NEQ){
			bool_index = i;
		}
	}

	// 判断是否存在 == 或 &&
	// 实现表达式只存在一个逻辑运算符的情况
	if (bool_index == -1){	
		uint32_t value = eval(0, nr_token - 1, success); 
		//if (signal != 1) printf("Expression: %s\nResult: %u\n",e,value);
		return value;
	}
	// 存在布尔运算符的情况
	else{
		uint32_t value1 = eval(0, bool_index - 1, success);
		uint32_t value2 = eval(bool_index + 1, nr_token - 1, success);
		int res;
		if (tokens[bool_index].type == TK_EQ) { 
			res = value1 == value2;
			//if (signal != 1) printf("Expression: %s\nResult: %u\n",e,res);
			return res;
		}
		if (tokens[bool_index].type == TK_NEQ) { 
			res = value1 != value2;
			//if (signal != 1) printf("Expression: %s\nResult: %u\n",e,res);
			return res;
		}
		if (tokens[bool_index].type == TK_AND) {
			res = value1 && value2;
			//if (signal != 1) printf("Expression: %s\nResult: %u\n",e,res);
			return res;
		} 
	}
  //TODO();

  return 0;
}
