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

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
	bool flag;
	char expr[32];
	int value;

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
		wp_pool[i].flag = false;
  }

  head = NULL;		//已用
  free_ = wp_pool;		//未用
}

/* TODO: Implement the functionality of watchpoint */
WP* new_wp() {
	if (free_ == NULL) {
		printf("No unused watchpoint available.\n");
		return NULL;
  }
	WP *p = free_;
	free_ = free_->next;
	p -> flag = true;
	p -> next = head;
	head = p; //
	return p;
}
void free_wp(WP *wp) {
	if (wp == NULL) {
		printf("watchpoint NO.%d dosen't exist.", wp -> NO);
		return;
	}
	if(head == wp) {
		head -> flag = false;
		head = wp -> next;
		wp ->next = free_; //
		free_ = wp; //
		printf("free watchpoint NO.%d success.\n", wp -> NO);
		return;
	}
	else {
		WP *p = head;
		while(p != NULL && p -> next != wp) {
			p = p -> next;
		}
		if (p != NULL) {
			p -> next = wp -> next;
		}
	}
		wp -> flag = false;
		wp -> next = free_;
		free_ = wp;
		printf("free NO.%d success.\n", wp -> NO);
}

void sdb_watchpoint_display() {
  bool flag = true;
  for (int i = 0; i < NR_WP; i++) {
		if(wp_pool[i].flag) {
			bool success = false;
			word_t tmp = expr(wp_pool[i].expr,&success);
      printf("watchpoint NO:%d, expr=%s, old_value=%u, new_value=%u\n", wp_pool[i].NO, wp_pool[i].expr, wp_pool[i].value, tmp);
      flag = false;
		}
	}
	if(flag) {
		printf("NO watchpoint now.\n");
  }
}

void create_watchpoint(char* args) {
	WP* p = new_wp();
  strncpy(p -> expr, args, sizeof(p -> expr) - 1);
	p->expr[sizeof(p->expr) - 1] = '\0';
  bool success = false;
  word_t tmp = expr(p -> expr, &success);
  if(success) {
    p -> value = tmp;
    printf("watchpoint NO.%d: %s\n", p -> NO, p-> expr);
  }
  else {
		printf("Create watchpoint failure.\n");
		free_wp(p);
	}
}

void delete_watchpoint(int no) {
  for(int i = 0; i < NR_WP; i++)
		if(wp_pool[i].NO == no){
			free_wp(&wp_pool[i]);
			return ;
	}
	printf("watchpoint NO.%d not found.\n", no);
}

void checkWatchPoint() {
	for(int i = 0; i < NR_WP; i++){
		if(wp_pool[i].flag) {
			bool success = false;
			word_t tmp = expr(wp_pool[i].expr,&success);
			if(success){
				if(tmp != wp_pool[i].value) {
					printf("watchpoint NO.%d:%s\toldvalue=0x%08x\tnewvalue=0x%08x\n\t\t[NPC_STOP]\n", wp_pool[i].NO, wp_pool[i].expr, wp_pool[i].value, tmp);
					extern bool RUNNING;
					RUNNING = false;
					return ;
      }
    }
			else {
      printf("Expression error in watchpoint NO.%d.\n", wp_pool[i].NO);
      assert(0);
			}
		}
	}
}
