/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include "common.h"
#include "utils.h"

enum {
    TK_NOTYPE = 256,
    TK_EQ,
    TK_NEQ,
    TK_LOG_AND,
    TK_NUM,
    TK_HEX_NUM,
    TK_REG,
};

static struct rule {
    const char *regex;
    int token_type;
} rules[] = {

    /* TODO: Add more rules.
     * Pay attention to the precedence level of different rules.
     */

    {" +", TK_NOTYPE}, // spaces
    {"0x[0-9a-fA-F]+", TK_HEX_NUM},
    {"[0-9]+", TK_NUM},
    {"\\+", '+'}, // plus
    {"-", '-'},   // minus or neg
    {"\\*", '*'}, // mul or deref
    {"/", '/'},
    {"\\(", '('},
    {"\\)", ')'},
    {"==", TK_EQ}, // equal
    {"!=", TK_NEQ},
    {"&&", TK_LOG_AND},
    {"\\$[a-z0-9]+", TK_REG},
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

    for (i = 0; i < NR_REGEX; i++) {
        ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
        if (ret != 0) {
            regerror(ret, &re[i], error_msg, 128);
            printf("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
            assert(0);
        }
    }
}

typedef struct token {
    int type;
    char str[32];
} Token;

static Token tokens[65536] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;

static bool make_token(char *e)
{
    int position = 0;
    int i;
    regmatch_t pmatch;

    nr_token = 0;

    while (e[position] != '\0') {
        /* Try all rules one by one. */
        for (i = 0; i < NR_REGEX; i++) {
            if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
                char *substr_start = e + position;
                int substr_len = pmatch.rm_eo;

                PRINTF_BLUE("match rules[%d] = \"%s\" at position %d with len %d: %.*s\n",
                    i, rules[i].regex, position, substr_len, substr_len, substr_start);

                /* TODO: Now a new token is recognized with rules[i]. Add codes
                 * to record the token in the array `tokens'. For certain types
                 * of tokens, some extra actions should be performed.
                 */

                if (nr_token >= 65536) {
                    printf("Error: Token numbers overflow!\n");
                    return false;
                }

                substr_len = substr_len >= 32 ? 31 : substr_len;

                position += substr_len;

                strncpy(tokens[nr_token].str, substr_start, substr_len);
                tokens[nr_token].str[substr_len] = '\0';

                switch (rules[i].token_type) {
                case TK_NOTYPE:
                    break;
                default:
                    tokens[nr_token].type = rules[i].token_type;
                    nr_token++;
                    break;
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

word_t vaddr_read(vaddr_t raddr);
word_t reg_str2val(const char *s, bool *success);


static word_t eval_top_term(bool *success);
static word_t eval_and_term(bool *success);
static word_t eval_eq_term(bool *success);
static word_t eval_add_term(bool *success);
static word_t eval_mul_term(bool *success);
static word_t eval_factor(bool *success);

static uint32_t token_idx = 0;

static Token *current_token()
{
    if (token_idx >= nr_token)
        return NULL;
    return &tokens[token_idx];
}

static bool match_token(int expected_type)
{
    Token *token = current_token();
    if (token != NULL && token->type == expected_type) {
        token_idx++;
        return true;
    }
    return false;
}

word_t eval_expr(char *e, bool *success)
{
    if (!make_token(e)) {
        *success = false;
        return 0;
    }

    /* TODO: Insert codes to evaluate the expression. */
    token_idx = 0;
    word_t result = eval_top_term(success);
    if (*success && token_idx != nr_token) {
        printf("Error: never complete\n");
        *success = false;
        return 0;
    }

    return result;
}

static word_t eval_top_term(bool *success)
{
    return eval_and_term(success);
}

static word_t eval_and_term(bool *success)
{
    word_t result = eval_eq_term(success);
    if (!*success)
        return 0;

    /* printf("Enter and\n"); */

    while (1) {
        Token *token = current_token();
        if (token == NULL)
            break;

        if (token->type == TK_LOG_AND) {
            token_idx++;
            word_t right = eval_eq_term(success);
            /* printf("opnum: %u, &&, right: %u\n", result, right); */
            if (!*success)
                return 0;
            result = result && right;
        } else
            break;
    }
    /* printf("and result: 0x%08x\n", result); */

    return result;
}
static word_t eval_eq_term(bool *success)
{
    word_t result = eval_add_term(success);
    if (!*success)
        return 0;

    /* printf("Enter eq\n"); */

    while (1) {
        Token *token = current_token();
        if (token == NULL)
            break;

        if (token->type == TK_EQ) {
            token_idx++;
            word_t right = eval_add_term(success);
            /* printf("opnum: %u, ==, right: %u\n", result, right); */
            if (!*success)
                return 0;
            result = result == right;
        } else if (token->type == TK_NEQ) {
            token_idx++;
            word_t right = eval_add_term(success);
            /* printf("opnum: %u, !=, right: %u\n", result, right); */
            if (!*success)
                return 0;
            result = result != right;
        } else
            break;
    }
    /* printf("eq result: 0x%08x\n", result); */

    return result;
}

static word_t eval_add_term(bool *success)
{
    word_t result = eval_mul_term(success);
    if (!*success)
        return 0;

    /* printf("Enter add\n"); */

    while (1) {
        Token *token = current_token();
        if (token == NULL)
            break;

        if (token->type == '+') {
            token_idx++;
            word_t right = eval_mul_term(success);
            /* printf("opnum: %u, +, right: %u\n", result, right); */
            if (!*success)
                return 0;
            result += right;
        } else if (token->type == '-') {
            token_idx++;
            word_t right = eval_mul_term(success);
            /* printf("opnum: %u, -, right: %u\n", result, right); */
            if (!*success)
                return 0;
            result -= right;
        } else
            break;
    }
    /* printf("add result: 0x%08x\n", result); */

    return result;
}

static word_t eval_mul_term(bool *success)
{
    word_t result = eval_factor(success);
    if (!*success)
        return 0;

    /* printf("Enter mul\n"); */

    while (1) {
        Token *token = current_token();
        if (token == NULL)
            break;

        if (token->type == '*') {
            token_idx++;
            word_t right = eval_factor(success);
            if (!*success)
                return 0;
            /* printf("opnum: %u, *, right: %u\n", result, right); */
            result *= right;
        } else if (token->type == '/') {
            token_idx++;
            word_t right = eval_factor(success);
            if (!*success)
                return 0;
            if (right == 0) {
                printf("Error: Divided by zero\n");
                return 0;
            }
            /* printf("opnum: %u, /, right: %u\n", result, right); */
            result /= right;
        } else
            break;
    }

    /* printf("mul result: 0x%08x\n", result); */
    return result;
}

static word_t eval_factor(bool *success)
{
    Token *token = current_token();
    if (token == NULL) {
        printf("Error: expected factor\n");
        *success = false;
        return 0;
    }

    /* printf("Enter factor\n"); */

    word_t result = 0;

    *success = true;

    switch (token->type) {
        case TK_NUM: {
            token_idx++;
            result = (word_t)atoi(token->str);
            break;
        }
        case TK_HEX_NUM: {
            token_idx++;
            result = (word_t)strtoul(token->str, NULL, 16);
            break;
        }
        case TK_REG: {
            token_idx++;
            result = reg_str2val(token->str, success);
            break;
        }
        case '-': {
            token_idx++;
            word_t value = eval_factor(success);
            if (!*success)
                break;
            result = -value;
            break;
        }
        case '*': {
            token_idx++;
            word_t addr = eval_factor(success);
            if (!*success)
                break;
            result = vaddr_read(addr);
            break;
        }
        case '(': {
            token_idx++;
            word_t res_expr = eval_top_term(success);
            if (!*success)
                break;
            if (!match_token(')')) {
                printf("Error: expected right parenthesis\n");
                *success = false;
                break;
            }
            result = res_expr;
            break;
        }
        default: {
            printf("Error: Could not recognize factor: %s\n", token->str);
            *success = false;
            break;
        }
    }

    /* printf("factor result: 0x%08x\n", result); */

    return result;
}
