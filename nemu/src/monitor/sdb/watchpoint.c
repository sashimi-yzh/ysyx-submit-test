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
#include <cpu/cpu.h>

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

	char expr[512];
	word_t last_value;
	
  /* TODO: Add more members if necessary */

} WP;
void init_wp_pool();
WP* new_wp();

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

WP* new_wp() {
  if (free_ == NULL) {
		assert(0);	
		return NULL;
  }

  WP* wp = free_;
  free_ = free_->next;

  wp->next = head;
  head = wp;

  return wp;
}

void free_wp(WP* wp) {
  if (wp == NULL) return;

  if (head == wp) {
		head = head->next;
  } else {
		WP* prev = head;
		while (prev != NULL && prev->next != wp) {
			prev = prev->next;
		}
		if (prev != NULL) {
			prev->next = wp->next;
		}
  }

  wp->next = free_;
  free_ = wp;
}

void add_wp(const char* sexpr) {
	WP* wp = new_wp();
	if (wp == NULL) return;
	assert(sexpr != NULL);
	strncpy(wp->expr, sexpr, sizeof(wp->expr) - 1);
	wp->expr[sizeof(wp->expr) - 1] = '\0'; // Ensure null-termination
	bool success;
	wp->last_value = expr(wp->expr, &success);
	if (!success) {
		printf("Invalid expression '%s'\n", wp->expr);
		free_wp(wp);
		return;
	}
	printf("Watchpoint %d: %s\n", wp->NO, wp->expr);
}
void delete_wp(int no) {
	WP* wp = head;
	while (wp != NULL) {
		if (wp->NO == no) {
			free_wp(wp);
			printf("Watchpoint %d deleted\n", no);
			return;
		}
		wp = wp->next;
	}
	printf("No watchpoint number %d\n", no);
}

void info_wp() {
	WP* wp = head;
	if (wp == NULL) {
		printf("No watchpoints\n");
		return;
	}
	printf("Num\tLast Value\tWhat\n");
	while (wp != NULL) {
		printf("%d\t0x%08x\t%s\n", wp->NO, wp->last_value, wp->expr);
		wp = wp->next;
	}
}

void check_wp() {
	WP* wp = head;
	while (wp != NULL) {
		bool success;
		word_t new_value = expr(wp->expr, &success);
		if (!success) {
			printf("Invalid expression '%s'\n", wp->expr);
			wp = wp->next;
			continue;
		}
		if (new_value != wp->last_value) {
			printf("Watchpoint %d: %s\n", wp->NO, wp->expr);
			printf("Old value = 0x%08x\n", wp->last_value);
			printf("New value = 0x%08x\n", new_value);
			wp->last_value = new_value;
			set_nemu_state(NEMU_STOP,0,0);
		}
		wp = wp->next;
	}
}
