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

#define NR_WP 32

typedef struct watchpoint
{
	int NO;
	struct watchpoint *next;
	char regex[512];
	word_t value_before;
	/* TODO: Add more members if necessary */

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool()
{
	int i;
	for (i = 0; i < NR_WP; i++)
	{
		wp_pool[i].NO = i;
		wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
	}

	head = NULL;
	free_ = wp_pool;
}
void print_wp()
{
	WP *temp_head = head;
	while (temp_head != NULL)
	{
		printf("id %d regex %s val oct:%010u hex:0x%08x\n", temp_head->NO, temp_head->regex, temp_head->value_before, temp_head->value_before);
		temp_head = temp_head->next;
	}
}
WP *new_wp(char *regex);
void new_wp_nonreturn(char *regex)
{
	new_wp(regex);
}

WP *new_wp(char *regex)
{

	if (free_ != NULL)
	{
		bool success;
		word_t value = expr(regex, &success);
		if (!success)
		{
			printf("bad expression\n");
			return NULL;
		}
		WP *temp = free_;
		free_ = free_->next;
		strcpy(temp->regex, regex);
		temp->value_before = value;
		temp->next = head;
		head = temp;
		return temp;
	}
	printf("not rnough points\n");
	return NULL;
}

bool check_watchpoint()
{
	bool flag = false;
	WP *temp = head;
	while (temp != NULL)
	{
		bool success;
		word_t newval = expr(temp->regex, &success);
		if (newval != temp->value_before)
		{
			printf("update:id %d regex %s preval oct:%010u hex:0x%08x newval oct:%010u hex:0x%08x\n", temp->NO, temp->regex, temp->value_before, temp->value_before, newval, newval);
			temp->value_before = newval;
			flag = true;
		}
		temp = temp->next;
	}
	return flag;
}
void free_wp_id(int id)
{
	if (head == NULL)
		return;
	WP *temp_head = head;
	WP *pre = NULL;

	while (temp_head != NULL)
	{
		if (temp_head->NO == id)
		{
			WP *next = temp_head->next;
			temp_head->next = free_;
			free_ = temp_head;
			if (pre != NULL)
			{
				pre->next = next;
			}
			if (temp_head == head)
			{
				head = next;
			}
			return;
		}
		pre = temp_head;
		temp_head = temp_head->next;
	}
	printf("id not exist\n");
}

void free_wp(WP *wp)
{
	if (head == NULL || wp == NULL)
		return;
	WP *temp_head = head;
	WP *pre = NULL;

	while (temp_head != NULL)
	{
		if (temp_head == wp)
		{
			WP *next = temp_head->next;
			wp->next = free_;
			free_ = wp;
			if (pre != NULL)
			{
				pre->next = next;
			}
			if (temp_head == head)
			{
				head = next;
			}
		}
		pre = temp_head;
		temp_head = temp_head->next;
	}
}
