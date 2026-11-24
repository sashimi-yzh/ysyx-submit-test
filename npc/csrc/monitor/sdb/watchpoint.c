/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NPC is licensed under Mulan PSL v2.
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
  char wp_expr[512];
  uint32_t last_value;

  /* TODO: Add more members if necessary */

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].last_value = 0;
  }

  head = NULL;
  free_ = wp_pool;
}

WP* new_wp(void)
{
  static int cnt = 0;

  if (free_ == NULL) {
    Log("No more watchpoints available!\n");
    return NULL;
  }

  /* Get a free wp */
  WP *wp = free_;
  free_ = free_->next;

  /* update count for wp */
  wp->NO = cnt;
  cnt++;

  /* Insert to used wp */
  wp->next = head;
  head = wp;

  return wp;
}

void free_wp(int num)
{
  WP *cur = head;
  WP *prev = NULL;

  while (cur != NULL) {
    if (cur->NO == num) {

      if (prev == NULL) {
        head = cur->next;
      }
      else {
        prev->next = cur->next;
      }

      cur->last_value = 0;
      cur->NO = 0;
      memset(cur->wp_expr, 0, 512);

      cur->next = free_;
      free_ = cur;
      Log("Freed watchpoint NO: %d\n", num);
      return;
    }
    prev = cur;
    cur = cur->next;
  }
}

void fill_wp(WP *wp, char* arg)
{
  bool status;

  if (!wp)
    return;

  strcpy(wp->wp_expr, arg);
  wp->last_value = expr(wp->wp_expr, &status);
  if(!status)
    Log("Expression calculate failure when init wp\n");

}

void wp_display(void)
{
  WP *cur;

  if(!head)
    return;
  
  cur = head;

  while (cur) {
    printf("No: %-4d expression: %-20s last_value %-10x\n",
           cur->NO, cur->wp_expr, cur->last_value);
    cur = cur->next;
  }
}

bool check_watchpointers(void)
{
  WP *cur;
  bool status;
  uint32_t cur_value;

  if (!head)
    return false;

  cur = head; 
  while (cur) {
    cur_value = expr(cur->wp_expr, &status);
    if (cur->last_value != cur_value) {
      cur->last_value = cur_value;
      return true;
    }
    cur = cur->next;
  }

  return false;
}

/* TODO: Implement the functionality of watchpoint */

