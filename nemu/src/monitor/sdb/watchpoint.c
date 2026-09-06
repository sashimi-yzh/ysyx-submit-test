/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include "cpu/cpu.h"
#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  char *expr;
  int val;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

void new_wp(char *exp) {
  // move a wp from free_ to head
  size_t expr_len = 0;
  if (exp == NULL || *exp == '\0') {
    printf("empty expression for watchpoint\n");
    return;
  }
  bool success = true;
  int val = expr(exp, &success);
  if (success == false) {
    printf("can not solve the express:%s\n", exp);
    return;
  }
  WP *tmp = free_;
  if (tmp == NULL) {
    printf("[Error] the num of breakpoint has reached upper limit\n");
    return;
  }
  WP *head_tmp = head;
  free_ = tmp->next;
  if (head == NULL) {
    head = tmp;
    tmp->next = NULL;
  } else {
    while (head_tmp->next != NULL) {
      if (head_tmp->next->NO > tmp->NO) {
        tmp->next = head_tmp->next;
        head_tmp->next = tmp;
        goto wp_init;
      }
      head_tmp = head_tmp->next;
    }
    head_tmp->next = tmp;
    tmp->next = NULL;
  }

wp_init:
  expr_len = strlen(exp);
  tmp->expr = (char *)malloc(expr_len + 1);
  if (tmp->expr == NULL) {
    printf("[Error] failed to allocate memory for watchpoint expr\n");
    tmp->next = free_;
    free_ = tmp;
    return;
  }
  strcpy(tmp->expr, exp);
  tmp->val = val;
  printf("create a watchpoint[%d] expr:%s val:%d\n", tmp->NO, tmp->expr,
         tmp->val);
  return;
}

void free_wp(int wp_num) {
  // move a wp from head to free_
  if (head == NULL) {
    printf("there is not any watchpoint\n");
    return;
  }
  WP *finder = head;
  if (finder->NO == wp_num) {
    free(finder->expr);
    finder->expr = NULL;
    head = finder->next;
    finder->next = free_;
    free_ = finder;
  } else {
    while (finder->next != NULL) {
      if (finder->next->NO == wp_num) {
        WP *tmp = finder->next;
        finder->next = tmp->next;
        tmp->next = free_;
        free_ = tmp;
        free(tmp->expr);
        tmp->expr = NULL;
        return;
      }
      finder = finder->next;
    }
    printf("[Error] can not find that watchpoint\n");
  }
  return;
}

void info_wp() {
  if (head == NULL) {
    printf("[Error] there is no any watchpoint\n");
    return;
  }
  WP *tmp = head;
  while (tmp != NULL) {
    printf("watchpoint[%d] expr:%s currut val: %d\n", tmp->NO, tmp->expr,
           tmp->val);
    tmp = tmp->next;
  }
  return;
}

static int singal = 0;
int check_wp_hit() { return singal; }

void exe_wp() {
  if (head == NULL) {
    return;
  }
  WP *tmp = head;
  while (tmp != NULL) {
    bool success = true;
    int res = expr(tmp->expr, &success);
    if (success == false) {
      printf("encounter error when eval watchpoint[%d]: %s\n", tmp->NO,
             tmp->expr);
    } else {
      if (res != tmp->val) {
        printf("hit the watchpoint[%d], val changed from %d to %d\n", tmp->NO,
               tmp->val, res);
        singal = 1;
        set_state_stop();
        tmp->val = res;
      } else {
        singal = 0;
      }
    }
    tmp = tmp->next;
  }
}
