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

#include <common.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();
word_t expr(char *e, bool *success);
void audio_callback(void* userdata, uint8_t *stream, int len);

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
/***gen-expr test***
FILE *file;
char line[65536 + 128];
char exprbuf[65536];
uint32_t result;
file = fopen("/home/xi/ysyx-workbench/nemu/tools/gen-expr/build/input", "r");	//打开文件
assert(file != NULL);	//assert0
int count = 1;
while (fgets(line, 65536 + 128, file) != NULL)	//fgets读取file文件x-1位字符串到line
{
  int i = 0;
  int j = 0;
  int cnt = sscanf(line, "%u", &result);	//sscanf字符串格式为化"%u"无符号整型数据,sscanf成功返回1
  assert(cnt == 1);
  while (line[i] != ' ') {
    i++;
  }		//result result + j = i
  while (line[i] != '\n' && i < 65536) {
    exprbuf[j] = line[i];
    j++;
    i++;
  }
  exprbuf[j] = '\0';		//将line中的表达式读入exprbuf
  bool success = true;
  word_t ans = expr(exprbuf, &success);	//exprbuf式输入expr函数计算结果ans
	printf("no.%d genexpr result = %u\n", count, ans);
  if (success == false && result - ans != 0)		//如success=false或result对比ans不同，失败
  {
    printf("- origin line: %s- success: %d\n- exprbuf: %s\n- result:%u\n- ans: %u\n", line, success, exprbuf, result, ans);		//输出数据比较
    return 0;
  }
	count++;
}
//return 0;		// 返回/继续进行
***/
  /* Start engine. */
	engine_start();

  return is_exit_status_bad();
}
