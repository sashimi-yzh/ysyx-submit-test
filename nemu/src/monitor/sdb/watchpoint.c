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

#include "sdb.h"
/*
#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
	bool is_watchpoint;
	bool is_used;
	uint32_t prev_value;
	uint32_t cur_value;
	char expr [100];

} WP;
*/
WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
		wp_pool[i].is_used = false;
		wp_pool[i].is_watchpoint = false;
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

WP* new_wp() {	
	if (free_ == NULL) {
		printf("NO free watchpoints available!\n");
		return NULL;
	 }
	WP* wp = free_;
	free_ = free_->next;// 下一个空闲的监视点

	wp->is_used = true;
	wp->next = head;// 从头部插入
	head = wp;
	return wp;
} 

void free_wp(WP* wp) {
	// 判断是否指针是否合法
	if (head == NULL || wp == NULL) {
		printf("No watchpoint to free\n.");
		return;
 	}

	// 检查要清除监视点是否已清除
	if (wp->is_used == false){
		printf("The watchpoint has been freed in advance\n");
		return;
 	}

	if (wp->is_watchpoint) wp->is_watchpoint = false;
	
	WP* p = head;
	// 如果要清除的监视点是第一个
	if (p == wp) {
		head = p->next;
		p->is_used = false;
		p->next = free_;
		free_ = p;
		return;
 	}
	// 要清除的监视点不是第一个
	else {
		while (p != NULL && p->next != wp){
			p = p->next;
 		}
 		if (p == NULL || p->next == NULL){
			printf("No such watchpoint\n");
			return;
		}
		
		WP* p_to_free = p->next;// 获得要释放的监视点
														//
		p_to_free->is_used = false;// 设置为未使用
		p->next = p->next->next;// 使用列表中去除该监视点
														//
		p_to_free->next = free_;//将释放的监视点插入free_链表
		free_ = p_to_free;
 	}
	return;	

}

void sdb_watchpoint_display (){
	WP* p = head;
	if (p == NULL) {
		printf("NO watchpoint is running.\n");
		return;
	}
	char status[10] = "Running";
	printf("以下是监视点(断点)信息:\n");
	//printf("NO\tType\tStatus\texpression");
	while (p != NULL){
		if (p->is_used){
			printf("\n-------------------------\n\n");

			if (p->is_watchpoint){
				printf("watchpoint NO:%d \nexpr:%s \nstatus:%s \nprev_value:0x%x \ncur_value:0x%x\n", p->NO, p->expr, status, p->prev_value, p->cur_value);
			}
			else{
				printf("breakpoint NO:%d \nexpr:%s \nstatus:%s \nprev_value:0x%x \ncur_value:0x%x\n", p->NO, p->expr, status, p->prev_value, p->cur_value);
			}
		p = p->next;
		}
	}
			printf("\n-------------------------\n");
}

void create_watchpoint (char* args) {
	WP* p = new_wp();
	strcpy(p->expr, args);
	if (args[1] == 'p' && args[2] == 'c'){
		p->is_used = true;
		bool success = false;
		p->cur_value = expr(p->expr, &success);
		p->prev_value = p->cur_value;
		printf("Create breakpoint success.\nwatchpoint NO:%d\n", p->NO);
	}
	else {
		p->is_used = true;
		p->is_watchpoint = true;
		printf("Create watchpoint success.\nwatchpoint NO:%d\n", p->NO);
	}
}

void delete_watchpoint (int NO) {
	WP* p = head;
	if (p == NULL){
		printf("No watchpoint is runnig.\n");
		return;
 	}
	while (p->NO != NO) {
		p = p->next;
 	}
	// 检测该监视点状态
	if (p->is_used == false) {
		printf("Cannot delete a free watchpoint\n");
		return;
 	}

	free_wp(p);
	if (p->is_used == false){
	printf("Delete watchpoint success.\nwatchpoint NO:%d\n", p->NO);
 	}
}
/*
void check_watchpoint () {
	WP* p = head;
	if (p == NULL) return;
	while (p != NULL) {
		p->cur_value = eval(p->expr);
		if (p->prev_value != p->cur_value) {
			printf("Watchpoint %d: %s changed\n  Old value: 0x%x\n  New value: 0x%x\n",
					p->NO, p->expr, p->prev_value, p->cur_value);
			p->prev_value = p->cur_value;
			nemu_state.state = NEMU_STOP;
		}
		p = p->next;
	}

}
*/
