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

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <memory/paddr.h>
extern word_t vaddr_read(vaddr_t addr, int len);
enum Type
{
	TK_EQ,
	TK_NUM,
	TK_HEX,
	TK_NEQ,
	TK_AND,
	TK_REG,
	DEREF,
	TK_GREATER,
	TK_LESS,

	TK_NOTYPE = 256
	/* TODO: Add more token types */

};
char table[256];
static struct rule
{
	const char *regex;
	int token_type;
} rules[] = {

	/* TODO: Add more rules.
	 * Pay attention to the precedence level of different rules.
	 */

	{" +", TK_NOTYPE}, // spaces
	{"==", TK_EQ},	   // equal
	{">", TK_GREATER},
	{"<", TK_LESS},
	{"!=", TK_NEQ}, // unequal
	{"&&", TK_AND}, // and

	{"\\$[a-zA-Z0-9]+", TK_REG},
	{"0x[0-9a-f]+", TK_HEX},
	{"[0-9]+", TK_NUM}, // number

	{"-", '-'},	  // minus
	{"\\+", '+'}, // plus
	{"\\*", '*'}, // multiply
	{"/", '/'},	  // div
	{"\\(", '('},
	{"\\)", ')'},
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex()
{
	int i;
	char error_msg[128];
	int ret;

	for (i = 0; i < NR_REGEX; i++)
	{
		ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
		if (ret != 0)
		{
			regerror(ret, &re[i], error_msg, 128);
			panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
		}
	}
	memset(table, 0, sizeof(table));
	table[TK_EQ] = 4;
	table[TK_NEQ] = 4;
	table[TK_GREATER] = 4;
	table[TK_LESS] = 4;
	table[TK_AND] = 5;
	table['+'] = 3;
	table['-'] = 3;
	table['*'] = 2;
	table['/'] = 2;
	table[DEREF] = 1;
}

typedef struct token
{
	int type;
	char str[32];
} Token;

static Token tokens[1024] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;

static bool make_token(char *e)
{
	int position = 0;
	int i;
	regmatch_t pmatch;

	nr_token = 0;
	// for (int i = 0; i < strlen(e); i++)
	// {
	// 	printf("%u ", e[i]);
	// }"( 55)    (    94  /  63)   73"
	// printf("%s\n", e);
	while (e[position] != '\0')
	{
		/* Try all rules one by one. */
		for (i = 0; i < NR_REGEX; i++)
		{
			if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0)
			{

				int substr_len = pmatch.rm_eo;

				// Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
				// 	i, rules[i].regex, position, substr_len, substr_len, substr_start);

				position += substr_len;

				/* TODO: Now a new token is recognized with rules[i]. Add codes
				 * to record the token in the array `tokens'. For certain types
				 * of tokens, some extra actions should be performed.
				 */
				if (nr_token > 1023)
				{
					Log("too much tokens");
					return false;
				}
				switch (rules[i].token_type)
				{
				case TK_NOTYPE:
					break;
				case TK_REG:
				case TK_HEX:
				case TK_NUM:
					tokens[nr_token].type = rules[i].token_type;
					if (substr_len > 31)
					{
						Log("too long number");
						return false;
					}
					memcpy(tokens[nr_token].str, e + position - substr_len, substr_len);
					tokens[nr_token].str[substr_len] = '\0';
					nr_token++;
					break;
				default:
					tokens[nr_token].type = rules[i].token_type;
					nr_token++;
					break;
				}

				break;
			}
		}

		if (i == NR_REGEX)
		{
			printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
			return false;
		}
	}

	return true;
}
int exprr(int beg, int end, bool *success);
word_t expr(char *e, bool *success)
{
	*success = true;
	if (!make_token(e))
	{
		*success = false;
		return 0;
	}
	for (int i = 0; i < nr_token; i++)
	{
		if (tokens[i].type == '*' && (i == 0 || tokens[i - 1].type == '(' ||
									  tokens[i - 1].type == '+' ||
									  tokens[i - 1].type == '-' ||
									  tokens[i - 1].type == '*' ||
									  tokens[i - 1].type == '/' ||
									  tokens[i - 1].type == '='))
		{
			tokens[i].type = DEREF;
		}
	}
	// x (10+10)*100/5+12-13
	/* TODO: Insert codes to evaluate the expression. */
	word_t res = exprr(0, nr_token, success);
	memset(tokens, 0, sizeof(tokens));
	return res;
}
bool check_parent(int beg, int end)
{
	// printf("beg %d end %d\n", beg, end);
	if (tokens[beg].type == '(')
		if (tokens[end - 1].type == ')')
			// {
			// 	for (int i = beg + 1; i < end - 1; i++)
			// 	{
			// 		int bracket_cnt = 0;
			// 		int max_cnt = 0;
			// 		int cnt = 0;
			// 		while (++i < end)
			// 		{
			// 			if (tokens[i].type == '(')
			// 			{
			// 				cnt++;
			// 				bracket_cnt++;
			// 			}
			// 			if (tokens[i].type == ')')
			// 				bracket_cnt--;
			// 			max_cnt = bracket_cnt > max_cnt ? bracket_cnt : max_cnt;
			// 		}
			// 		if (max_cnt != cnt)
			// 		{
			// 			return false;
			// 		}
			return true;
	return false;
}
int find_main(int beg, int end, bool *success)
{
	// find rightest * /
	int pos = beg;
	for (int i = beg; i < end; i++)
	{

		if (table[tokens[i].type] >= table[tokens[pos].type])
			pos = i;
		if (tokens[i].type == '(')
		{
			int bracket_cnt = 1;
			while (++i < end)
			{
				if (tokens[i].type == '(')
					bracket_cnt++;
				if (tokens[i].type == ')')
					bracket_cnt--;
				if (bracket_cnt == 0)
					break;
			}
			continue;
		}
	}
	if (tokens[pos].type != '+' && tokens[pos].type != '-' && tokens[pos].type != '/' && tokens[pos].type != '*' && tokens[pos].type != TK_EQ && tokens[pos].type != TK_AND && tokens[pos].type != TK_NEQ && tokens[pos].type != TK_GREATER && tokens[pos].type != TK_LESS)
	{
		// Log("did not find pos");
		*success = false;
		return 0;
	}
	// printf("beg %d end %d\n", beg, end);
	// printf("selected pos %d op %c\n", pos, tokens[pos].type);
	return pos;
	// if not find rightest + -
	// error
}
//(     57 / 42!=  8 ==    3) &&      ( 87)  != ( 42)/   49/ (62)  !=(  42-91  - (21))
int exprr(int beg, int end, bool *success)
{
	if (!*success)
		return 0;

	if (beg >= end)
	{
		Log("beg is larger than end");
		*success = false;
		return 0;
	}
	if (beg == end - 1)
	{
		// Log("test");
		if (tokens[beg].type != TK_NUM && tokens[beg].type != TK_HEX)
		{
		}
		// printf("single res %d\n", atoi(tokens[beg].str));
		unsigned num;
		switch (tokens[beg].type)
		{
		case TK_NUM:
			sscanf(tokens[beg].str, "%u", &num);
			break;
		case TK_HEX:
			sscanf(tokens[beg].str, "%x", &num);
			break;
		case TK_REG:
			char name[5];
			sscanf(tokens[beg].str, "$%s", name);
			num = isa_reg_str2val(name, success);
			if (!*success)
			{
				Log("invalid reg name");
				return 0;
			}
			break;
		default:
			Log("syntax error");
			*success = false;
			return 0;
			break;
		}
		return num;
	}
	// Log("test beg %d end %d", beg, end);
	int idx = find_main(beg, end, success);
	if (!*success)
	{
		*success = true;
		if (check_parent(beg, end))
		{
			return exprr(beg + 1, end - 1, success);
		}
		else
		{
			if (tokens[beg].type == DEREF)
			{
				return vaddr_read(exprr(beg + 1, end, success), 4);
			}
			else
			{
				Log("failed to handle");
				*success = false;
				return 0;
			}
		}
	}
	int op = tokens[idx].type;
	// Log("test beg %d end %d", beg, end);
	int val1 = exprr(beg, idx, success);
	// Log("test beg %d end %d", beg, end);
	int val2 = exprr(idx + 1, end, success);
	// Log("test beg %d end %d", beg, end);
	int res;
	switch (op)
	{
	case TK_AND:
		res = val1 && val2;
		break;
	case TK_NEQ:
		res = val1 != val2;
		break;
	case TK_EQ:
		res = val1 == val2;
		break;
	case TK_GREATER:
		res = val1 > val2;
		break;
	case TK_LESS:
		res = val1 < val2;
		break;
	case '+':
		res = val1 + val2;
		break;
	case '-':
		res = val1 - val2;
		break;
	case '*':
		res = val1 * val2;
		break;
	case '/':
		if (val2 == 0)
		{
			Log("div 0");
			*success = false;
			return 0;
		}
		res = val1 / val2;
		break;
	default:
		Log("unknown op");
		*success = false;
		return 0;
		break;
	}
	// printf("beg %d end %d res %d\n", beg, end, res);
	return res;
}
// x (10+10)*100/5+12-13