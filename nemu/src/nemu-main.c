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
#define MAX_LINE_LENGTH 256
void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();
word_t expr(char *, bool *);

int main(int argc, char *argv[])
{
	// for (int i = 0; i < argc; i++)
	// {
	// 	printf("%s \n", argv[i]);
	// }
	/* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
	am_init_monitor();
#else
	init_monitor(argc, argv);
	// 此函数进行一些初始化工作，比如打开日志
	// 设置内存随机化种子
	// 初始化内存区域
	// 初始化模拟硬件
	// 初始化isa
	// 加载代码段
	// 初始化监视器
	// 加载反汇编库
#endif
	/* Start engine. */
	engine_start();
	// 启动监视引擎
	return is_exit_status_bad();
	// 判断是否正常退出
}
// #include <expr.c>
