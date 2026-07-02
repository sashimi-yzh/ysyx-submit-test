#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <regex.h>

typedef uint32_t word_t;

#define Log(format, ...) 
#define Assert(cond, format, ...) do { if (!(cond)) exit(1); } while (0)
#define panic(format, ...) exit(1)

#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

#include <regex.h>
#define __ISA_H__

word_t isa_reg_str2val(const char *s, bool *success);
word_t vaddr_read(word_t addr, int len);

#include "../../src/monitor/sdb/expr.c"

word_t isa_reg_str2val(const char *s, bool *success) {
    *success = true;
    return 0x1234; 
}

word_t vaddr_read(word_t addr, int len) {
    return addr; 
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Failed to open input file");
        return 1;
    }

    init_regex();

    char line[65536];
    int passed = 0;
    int failed = 0;

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = 0;
        
        uint32_t expected;
        char expr_buf[65536];
        
        if (sscanf(line, "%u %[^\n]", &expected, expr_buf) == 2) {
            bool success;
            word_t result = expr(expr_buf, &success);
            
            if (success && result == expected) {
                passed++;
            } else {
                failed++;
                printf("FAIL: %s\nExpected: %u, Got: %u (success=%d)\n", expr_buf, expected, result, success);
            }
        }
    }

    printf("Passed: %d, Failed: %d\n", passed, failed);
    fclose(fp);
    return failed == 0 ? 0 : 1;
}
