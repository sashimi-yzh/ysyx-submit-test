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

#include <common.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();
int test_expr_from_file(char *argv);

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

#ifdef CONFIG_EXPERSSION_TEST
  if (argc == 2) {
    test_expr_from_file("tools/gen-expr/input");
    return 0;
  }
#endif
  /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}

#include <stdio.h>  
#include <stdlib.h> 
#include <stdint.h> 
#include <string.h> 
#include <stdbool.h> 

extern word_t expr(char *e, bool *success);

void trim_newline(char *str) {
    int len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[--len] = '\0';
    }
}

int test_expr_from_file(char *argv) {

    FILE *fp = fopen(argv, "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    char line[1024];
    int total_tests = 0;
    int passed_tests = 0;

    printf("Starting test...\n\n");

    while (fgets(line, sizeof(line), fp)) {
        // 去除换行符
        trim_newline(line);

        // 跳过空行
        if (strlen(line) == 0) continue;
        // --- 解析部分 ---
        char *ptr = line;
        char *endptr = NULL;
        
        unsigned long expected_val_long = strtoul(ptr, &endptr, 10);
        
        if (endptr == ptr) {
            continue;
        }
        ptr = endptr;
        while (*ptr == ' ' || *ptr == '\t') {
            ptr++;
        }

        if (*ptr == '\0') {
            continue;
        }
        char *expression = ptr;
        
        bool success = false;
        printf("testing: %s\n",expression);
        word_t result = expr(expression, &success);
        word_t expected_val = (word_t)expected_val_long;

        total_tests++;

        if (success && result == expected_val) {
            passed_tests++;
        } else {
            printf("[FAIL] Line: \"%s\"\n", line);
            printf("       Expression: \"%s\"\n", expression);
            printf("       Expected: %u, Got: %u (Success: %s)\n", 
                   expected_val, result, success ? "true" : "false");
        }
    }

    fclose(fp);

    printf("\nTest finished.\n");
    printf("Total: %d, Passed: %d, Failed: %d\n", 
           total_tests, passed_tests, total_tests - passed_tests);

    return 0;
}
