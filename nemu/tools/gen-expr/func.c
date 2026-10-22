#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>

#define MAX_EXPR_LENGTH 512
#define MAX_TOKENS 100

static char buf[65536] = {};
static char code_buf[65536 + 128] = {};
static char *code_format =
"#include <stdio.h>\n"
"#include <stdint.h>\n"
"int main() { "
"  int32_t result = %s; "
"  printf(\"%%d\", result); "
"  return 0; "
"}";

uint32_t choose(uint32_t n) {
    return rand() % n;
}

void gen_num(int* signal, int allow_zero) {
    if (*signal == 1) return;
    int32_t num;
    if (allow_zero) {
        num = rand() % (100);
    } else {
        num = rand() % 99 + 1;
    }
    char str[12];
    snprintf(str, sizeof(str), "%d", num);
    strncat(buf, str, sizeof(buf) - strlen(buf));
    *signal = 0;
}

void gen(char* str, int* signal) {
    if (strcmp(str, ")") == 0) *signal = 1;
    strncat(buf, str, sizeof(buf) - strlen(buf));
}

char* gen_rand_op() {
    char *op;
    switch (choose(4)) {
        case 0: op = "+"; break;
        case 1: op = "-"; break;
        case 2: op = "*"; break;
        case 3: op = "/"; break;
        default: op = "+"; break;
    }
    strncat(buf, op, sizeof(buf) - strlen(buf));
    return op;
}

static void gen_rand_expr(int* token_count) {
    int signal = 0;
    switch (choose(3)) {
        case 0:
            gen_num(&signal, 1);
            (*token_count)++;
            break;
        case 1:
            gen("(", &signal);
            (*token_count)++;
            gen_rand_expr(token_count);
            gen(")", &signal);
            (*token_count)++;
            break;
        default:
            gen_rand_expr(token_count);
            const char *op = gen_rand_op();
            (*token_count)++;
            if (strcmp(op, "/") == 0) {
                int right_signal = 0;
                gen_num(&right_signal, 0);
                (*token_count)++;
            } else {
                gen_rand_expr(token_count);
            }
            break;
    }
}

int main(int argc, char *argv[]) {
    int seed = time(0);
    srand(seed);
    int loop = 1;
    if (argc > 1) sscanf(argv[1], "%d", &loop);
    for (int i = 0; i < loop; i++) {
        buf[0] = '\0';
        int token_count = 0;
        do {
            gen_rand_expr(&token_count);
        } while (token_count > MAX_TOKENS);

        sprintf(code_buf, code_format, buf);
        FILE *fp = fopen("/tmp/.code.c", "w");
        assert(fp != NULL);
        fputs(code_buf, fp);
        fclose(fp);

        int ret = system("gcc /tmp/.code.c -o /tmp/.expr -Wno-overflow -Werror -Wall 2> /dev/null");
        if (ret != 0) continue;

        fp = popen("/tmp/.expr", "r");
        assert(fp != NULL);

        int result;
        if (fscanf(fp, "%d", &result) != 1) result = -1;
        pclose(fp);

        if (result < 0) continue;

        printf("%u %s\n", (uint32_t)result, buf);
    }
    return 0;
}
