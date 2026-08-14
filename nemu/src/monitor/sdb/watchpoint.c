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
  char w_expr[65536];
  /* TODO: Add more members if necessary */
  word_t value;
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
void new_wp(bool *success, char *str, word_t value) {
  WP* ret = free_;
  if(ret == NULL) {
    Log("There is not free watchpoint");
    *success = false;
  }
  else {
    free_ = free_->next;
    ret->next = head;
    head = ret;
    int w_expr_len = strlen(str);
    if(w_expr_len > 65536) {
      *success = false;
      Log("expression is too long");
    }
    else {
      strncpy(ret->w_expr, str, 65536);
      ret->w_expr[w_expr_len] = '\0';
      ret->value = value;
    }
  }
}

void free_wp(int NO) {
  WP temp;
  temp.NO = -1;
  temp.next = head;
  WP* ptemp = &temp;
  for(;ptemp->next != NULL;ptemp = ptemp->next) {
    if(ptemp->next->NO == NO) {
      // ptemp->next 加入free_
      WP *ptemp_next = ptemp->next->next;
      ptemp->next->next = free_;
      free_ = ptemp->next;
      // 更新 ptemp->next
      Log("%d", ptemp->NO);
      if(ptemp->next == head) head = ptemp_next;
      else ptemp->next = ptemp_next;
      return ;
    }
  }
  Log("NO %d watchpoint is not found", NO);
}

void display_wp() {
  printf("Num\t\tWhat\n");
  WP* temp = head;
  for(;temp != NULL;temp = temp->next) {
    printf(FMT_WORD"\t%s\n", temp->NO, temp->w_expr);
  }
}

bool difftest_wp(){
  WP* temp = head;
  bool success = true;
  bool flag = true;
  for(;temp != NULL;temp = temp->next) {
    word_t new_value = expr(temp->w_expr, &success);
    if(!success) {
      panic("expr watchpoint new_value failed");
    }
    if(new_value != temp->value) {
      printf("watchpoint %d: %s\n\n", temp->NO, temp->w_expr);
      printf("Old value = "FMT_WORD"\n", temp->value);
      printf("New value = "FMT_WORD"\n", new_value);
      temp->value = new_value;
      flag = false;
    }
  }
  return flag;
}