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
#include <assert.h>
#include <string.h>

#define NR_WP 32

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool(void) {
  for (int i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].expr[0] = '\0';
    wp_pool[i].last_val = 0;
    wp_pool[i].inited = false;
  }

  head = NULL;
  free_ = wp_pool;
}

WP *new_wp(void) {
  assert(free_ != NULL);

  WP *wp = free_;
  free_ = free_->next;

  // insert into head list
  wp->next = head;
  head = wp;

  // init fields
  wp->expr[0] = '\0';
  wp->last_val = 0;
  wp->inited = false;

  return wp;
}

void free_wp(WP *wp) {
  assert(wp != NULL);

  // remove from head list
  WP **pp = &head;
  while (*pp != NULL && *pp != wp) {
    pp = &((*pp)->next);
  }
  assert(*pp == wp);

  *pp = wp->next;

  // push back to free list
  wp->next = free_;
  free_ = wp;
}

WP *get_head_wp(void) {
  return head;
}

bool check_watchpoints(void) {
  bool triggered = false;

  for (WP *wp = head; wp != NULL; wp = wp->next) {
    bool success = true;
    word_t new_val = expr(wp->expr, &success);
    if (!success) {
      // 表达式如果求值失败，你也可以选择直接忽略或提示
      // 这里选择提示一次并继续
      printf("Watchpoint %d: bad expression: %s\n", wp->NO, wp->expr);
      continue;
    }

    if (!wp->inited) {
      wp->last_val = new_val;
      wp->inited = true;
      continue;
    }

    if (new_val != wp->last_val) {
      printf("\nWatchpoint %d triggered: %s\n", wp->NO, wp->expr);
      printf("Old value = 0x%08x (%u)\n", (uint32_t)wp->last_val, (uint32_t)wp->last_val);
      printf("New value = 0x%08x (%u)\n", (uint32_t)new_val, (uint32_t)new_val);

      wp->last_val = new_val;
      triggered = true;

      // 如果你希望“同一条指令只报第一个触发”，可以 break;
      // break;
    }
  }

  return triggered;
}
