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

#define LINE_MAX 1000

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

  /* Start engine. */
  engine_start();	

  return is_exit_status_bad();
  //int read_line(char *path);
  //read_line("input6");
  //it is pa2

}
int read_line(char *path)
{
	FILE *fp;
	int line_num = 0; // 文件行数
	int line_len = 0; // 文件每行的长度
	char buf[LINE_MAX] = {0}; // 行数据缓存

	fp = fopen(path, "r");
	if (NULL == fp) {
		printf("open %s failed.\n", path);
		return -1;
	}

	while(fgets(buf, LINE_MAX, fp)) {
		line_num++;
		line_len = strlen(buf);
		// 排除换行符
		if ('\n' == buf[line_len - 1]) {
			buf[line_len - 1] = '\0';
			line_len--;
			if (0 == line_len) {
				//空行
				continue;
			}
		}
		// windos文本排除回车符
		if ('\r' == buf[line_len - 1]) {
			buf[line_len - 1] = '\0';
			line_len--;
			if (0 == line_len) {
				//空行
				continue;
			}
		}
		//printf("%s\n", buf);
		/** 对每行数据(buf)进行处理 **/
    word_t expr(char *e, bool *success);
    uint32_t result_raw;
    char arg[300] = {0};
    sscanf(buf,"%u %s",&result_raw,arg);
    //printf("%d - %s\n",result_raw,arg);
    bool success;
    bool *ptr_success = &success;
    uint32_t result;
    result=expr(arg,ptr_success);
    if(result!=result_raw) {
      printf("%u %u %d\n",result,result_raw,line_num);
    }
	else {
		printf("True!%d\n",line_num);
	}
    
	}

	
	fclose(fp);

	return line_num;
}
