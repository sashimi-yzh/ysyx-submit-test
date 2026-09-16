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
#include <ctype.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();
word_t expr(char *e, bool *success);// 添加的部分

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
	
	/* 测试模式 */
/*	
    FILE *fp = fopen("/home/long/ysyx-workbench/nemu/tools/gen-expr/input", "r");
    if (!fp) {
      perror("打开测试文件失败\n");
      exit(EXIT_FAILURE);
		}	
    char line[4096];  // 支持超长行
    uint32_t total = 0, passed = 0;
    bool has_failure = false;

    printf("开始批量测试...\n");

    while (fgets(line, sizeof(line), fp)) {
      // 解析输入行
      total++;
      char *saveptr;
      char *expected_str = strtok_r(line, " \t\n", &saveptr);
      char *expression = strtok_r(NULL, "\n", &saveptr);
      
      if (!expected_str || !expression) {
        printf("第%u行格式错误: %s", total, line);
        continue;
      }

      // 转换预期结果 
      uint32_t expected;
      if (expected_str[0] == '0' && tolower(expected_str[1]) == 'x') {
        expected = strtoul(expected_str, NULL, 16);
      } else {
        expected = strtoul(expected_str, NULL, 10);
      }

      // 执行表达式求值
      bool success = false;
      uint32_t actual = expr(expression, &success);

      //
      bool match = false;
      if (success) {
        match = (actual == expected);
      }

      // 输出详细结果 
      if (!success || !match) {
        if (!has_failure) {
          printf("\n测试失败详情:\n");
          has_failure = true;
        }
        
        printf("测试用例 #%u\n", total);
        printf("表达式: %s\n", expression);
        if (!success) {
          printf("错误类型: 表达式解析失败\n");
        } else {
          printf("预期结果: 0x%08x (%u)\n", expected, expected);
          printf("实际结果: 0x%08x (%u)\n", actual, actual);
        }
        printf("----------------------------\n");
      } else {
        passed++;
      }

      // 进度提示
      if (total % 1000 == 0) {
        printf("已处理 %u 个测试用例...\n", total);
      }
    }

    fclose(fp);
    
    // 最终报告
    printf("\n测试结果总结:\n");
    printf("总用例数: %u\n", total);
    printf("通过用例: %u\n", passed);
    printf("失败用例: %u\n", total - passed);
    printf("通过率: %.2f%%\n", (float)passed / total * 100);

    exit(has_failure ? EXIT_FAILURE : EXIT_SUCCESS);
//  */

  /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}
