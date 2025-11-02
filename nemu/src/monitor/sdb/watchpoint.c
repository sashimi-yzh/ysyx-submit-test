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


int check_usage(int wp_used[NR_WP], char expression_stored[NR_WP][32],\
				word_t result[NR_WP]){
	int i = 0;
	WP* tmp = head;
	if(tmp == NULL)
		return 0;

	while(tmp -> next != NULL){
		strcpy(expression_stored[i], tmp -> expression);
		result[i] = tmp -> result;
		wp_used[i++] = tmp -> NO;
		tmp = tmp -> next;
	}
	strcpy(expression_stored[i], tmp -> expression);
	result[i] = tmp -> result;
    wp_used[i++] = tmp -> NO;

	return i;
}


WP* new_wp(void){
	if(head == NULL){//first allocation
		head = free_;
		free_ = free_ -> next;
		head -> next = NULL;
		return head;
	}

	else if(free_ == NULL){//no watchpoints available
		printf("no watchpoints available\n");
		//assert(0);
		return NULL;
	}

	else{
		WP* tmp = head;
		while(tmp -> next != NULL)
			tmp = tmp -> next;
		tmp -> next = free_;
		free_ = free_ -> next;
		tmp -> next -> next = NULL;
		return tmp -> next;
	}
}



void free_wp(int no){
	if(no < 0||no > 31){
		printf("invalid NO\n");
		return;
	}

	if(head == NULL){//empty list
		printf("no watchpoints created yet\n");
		return;
	}

	if(head -> NO == no){//watchpoint to delete is at head
		if(free_ == NULL){//full list
			free_ = head;
			head = head -> next;
			free_ -> next = NULL;
		}

		else{
			WP* free_tail = free_;
			while(free_tail -> next != NULL)
				free_tail = free_tail -> next;
			free_tail -> next = head;
			head = head -> next;
			free_tail -> next -> next = NULL;
		}
	}


	else{//watchpoint to delete is not at head
		WP* ite = head;
		WP* free_add = NULL;
		while(ite -> next != NULL){
			if(ite -> next -> NO == no){
				free_add = ite -> next;
				ite -> next = ite -> next -> next;
				break;
			}
			ite = ite -> next;
		}
		if(free_add == NULL){
			printf("watchpoint NO.%d not created yet\n", no);
			return;
		}

		if(free_ == NULL){//full list
            free_ = free_add;
            free_ -> next = NULL;
        }

        else{
            WP* free_tail = free_;
            while(free_tail -> next != NULL)
                free_tail = free_tail -> next;
            free_tail -> next = free_add;
            free_tail -> next -> next = NULL;
        }
	
	}

	printf("watchpoint NO.%d successfully deleted\n", no);

}


void update_wp_result(int no, word_t _result){
	if(no >= 0 && no <= 31){
		wp_pool[no].result = _result;
	}
}

