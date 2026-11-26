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

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */

  char expr[256];      // 监视的表达式
  word_t old_value;    // 表达式的旧值
  bool enabled;        // 是否启用

} WP;

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

/* ========== 监视点池管理 ========== */

// 从free_链表中分配一个空闲的监视点
static WP* new_wp() {
  if (free_ == NULL) {
    printf("Error: No free watchpoint available!\n");
    assert(0);
  }
  
  // 从free_链表头部取出一个
  WP *wp = free_;
  free_ = free_->next;
  
  // 插入到head链表头部
  wp->next = head;
  head = wp;
  
  return wp;
}

// 将监视点归还到free_链表
static void free_wp(WP *wp) {
  // 从head链表中移除
  if (head == wp) {
    // 要删除的是头节点
    head = head->next;
  } else {
    // 要删除的不是头节点，需要找到前驱
    WP *prev = head;
    while (prev != NULL && prev->next != wp) {
      prev = prev->next;
    }
    
    if (prev == NULL) {
      printf("Error: Watchpoint not found in list!\n");
      return;
    }
    
    prev->next = wp->next;
  }
  
  // 清空监视点数据
  wp->enabled = false;
  wp->expr[0] = '\0';
  wp->old_value = 0;
  
  // 插入到free_链表头部
  wp->next = free_;
  free_ = wp;
}

/* ========== 监视点用户接口 ========== */

// 创建一个新的监视点
WP* create_watchpoint(char *expr_str) {
  bool success = false;
  word_t value = expr(expr_str, &success);
  
  if (!success) {
    printf("Error: Invalid expression\n");
    return NULL;
  }
  
  WP *wp = new_wp();
  strncpy(wp->expr, expr_str, sizeof(wp->expr) - 1);
  wp->expr[sizeof(wp->expr) - 1] = '\0';
  wp->old_value = value;
  wp->enabled = true;
  
  // 在这里打印
  printf("Watchpoint %d: %s\n", wp->NO, wp->expr);
  
  return wp;
}

// 删除指定序号的监视点
bool delete_watchpoint(int no) {
  // 在head链表中查找
  for (WP *wp = head; wp != NULL; wp = wp->next) {
    if (wp->NO == no) {
      free_wp(wp);
      return true;
    }
  }
  
  return false;
}

// 显示所有监视点
void display_watchpoints() {
  if (head == NULL) {
    printf("No watchpoints.\n");
    return;
  }
  
  printf("Num     Enabled  Expression                       Value\n");
  printf("-----------------------------------------------------------\n");
  
  for (WP *wp = head; wp != NULL; wp = wp->next) {
    printf("%-7d %-8s %-32s " FMT_WORD "\n",
           wp->NO,
           wp->enabled ? "y" : "n",
           wp->expr,
           wp->old_value);
  }
}

// 检查所有监视点，返回是否有监视点被触发
bool check_watchpoints() {
  bool triggered = false;
  
  // 调试：检查是否有监视点
  if (head == NULL) {
    return false;
  }
  
  for (WP *wp = head; wp != NULL; wp = wp->next) {
    if (!wp->enabled) {
      continue;
    }
    
    // 对表达式求值
    bool success = false;
    word_t new_value = expr(wp->expr, &success);
    
    if (!success) {
      printf("Error: Failed to evaluate watchpoint %d: %s\n", 
             wp->NO, wp->expr);
      continue;
    }
    
    // 调试输出
    // printf("[DEBUG] WP %d: expr='%s', old=" FMT_WORD ", new=" FMT_WORD "\n",
    //        wp->NO, wp->expr, wp->old_value, new_value);
    
    // 检查值是否发生变化
    if (new_value != wp->old_value) {
      printf("\n");
      printf("Watchpoint %d: %s\n", wp->NO, wp->expr);
      printf("Old value = " FMT_WORD "\n", wp->old_value);
      printf("New value = " FMT_WORD "\n", new_value);
      printf("\n");
      
      // 更新旧值
      wp->old_value = new_value;
      triggered = true;
    }
  }
  
  return triggered;
}