#pragma once
#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Npc.h"
#define NR_REGEX 13
extern "C" uint32_t paddr_read(uint32_t addr, int len, int is_fetch, int is_avail);
enum Type
{
	TK_EQ,
	TK_NUM,
	TK_HEX,
	TK_NEQ,
	TK_AND,
	TK_REG,
	DEREF,

	TK_NOTYPE = 256
	/* TODO: Add more token types */

};
typedef struct token
{
	int type;
	char str[32];
} Token;

struct rule
{
	const char *regex;
	int token_type;
};
class Expr
{
public:
	Expr()
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
				// panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
				printf("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
				assert(0);
			}
		}
		memset(table, 0, sizeof(table));
		table[TK_EQ] = 4;
		table[TK_NEQ] = 4;
		table[TK_AND] = 5;
		table['+'] = 3;
		table['-'] = 3;
		table['*'] = 2;
		table['/'] = 2;
		table[DEREF] = 1;
	}

private:
	Token tokens[1024] = {};
	int nr_token = 0;
	char table[256];
	regex_t re[NR_REGEX] = {};
	rule rules[NR_REGEX] = {

		{" +", TK_NOTYPE}, // spaces
		{"==", TK_EQ},	   // equal
		{"!=", TK_NEQ},	   // unequal
		{"&&", TK_AND},	   // and

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
	bool make_token(char *e)
	{
		int position = 0;
		int i;
		regmatch_t pmatch;

		nr_token = 0;
		while (e[position] != '\0')
		{
			/* Try all rules one by one. */
			for (i = 0; i < NR_REGEX; i++)
			{
				if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0)
				{

					int substr_len = pmatch.rm_eo;
					position += substr_len;
					if (nr_token > 1023)
					{
						printf("too much tokens");
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
							printf("too long number");
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
	int exprr(int beg, int end, bool *success)
	{
		if (!*success)
			return 0;

		if (beg >= end)
		{
			// Log("beg is larger than end");
			printf("beg is larger than end");
			*success = false;
			return 0;
		}
		if (beg == end - 1)
		{
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
				num = 0;

				num = Npc::get_reg(name, success);
				if (!*success)
				{
					printf("invalid reg name");
					return 0;
				}
				break;
			default:
				// Log("syntax error");
				printf("syntax error");
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
					return paddr_read(exprr(beg + 1, end, success), 4, 1, 1);
				}
				else
				{
					// Log("failed to handle");
					printf("failed to handle");
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
				// Log("div 0");
				printf("div 0");
				*success = false;
				return 0;
			}
			res = val1 / val2;
			break;
		default:
			// Log("unknown op");
			printf("unknown op");
			*success = false;
			return 0;
			break;
		}
		// printf("beg %d end %d res %d\n", beg, end, res);
		return res;
	}
	bool check_parent(int beg, int end)
	{
		printf("beg %d end %d\n", beg, end);
		if (tokens[beg].type == '(')
			if (tokens[end - 1].type == ')')
				return true;
		return false;
	}
	int find_main(int beg, int end, bool *success)
	{
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
		if (tokens[pos].type != '+' && tokens[pos].type != '-' && tokens[pos].type != '/' && tokens[pos].type != '*' && tokens[pos].type != TK_EQ && tokens[pos].type != TK_AND && tokens[pos].type != TK_NEQ)
		{
			*success = false;
			return 0;
		}
		return pos;
	}

public:
	uint32_t expr(char *e, bool *success)
	{
		// printf("expr %s\n", e);
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
		uint32_t res = exprr(0, nr_token, success);
		memset(tokens, 0, sizeof(tokens));
		return res;
	}
};
