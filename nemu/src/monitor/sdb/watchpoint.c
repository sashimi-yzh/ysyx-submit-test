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
  char expression[320];
  bool enable;
  int result;
  struct watchpoint *next;


} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].enable = true;		//开启监视点
  }

  head = NULL;
  free_ = wp_pool;
}

void new_wp(char *e, bool *success) {
  if(*success){
   // printf("enter success><\n");
    init_wp_pool();
    *success = 0;
  }
  if(free_ == NULL){
    printf("free_ is empty\n");
    assert(0);
  }
  WP *new = free_;
  free_ = free_->next;
  strcpy(new->expression, e);
  //printf("%s\n", new->expression);
  //printf("arrive here4\n");
  new->result = expr(e,success);
  if(!*success) {
    printf("calculate error\n");
    return;
  }
  *success = false;
  new->next = NULL;
  if(head == NULL){
    //printf("head is empty\n");
    head = new;
  }
  else {
    //printf("head is not empty\n");
    new->next = head;
    head = new;
  }
  printf("已添加监视点%s\t0x%08x\n", e, new->result);
}

void free_wp(int NO) {
  WP *p = head;
  if (head == NULL) {
    printf("watchpoint link is empty\n");
    return;
  }
  else if (p->NO == NO) {
    //printf("!p->NO=%d\n", p->NO);
    head = head->next;
    memset(p->expression, '\0', sizeof(p->expression));
    p->next = free_;
    free_ = p;
    printf("watchpoint %d had been deleted\n", NO);
  }
  else {
    WP *q = head;
    p = p->next;
    while(p!=NULL) {
      printf("p->NO=%d\t%d\n", p->NO, NO);
      if(p->NO == NO) {
        q->next = p->next;
        memset(p->expression, '\0', sizeof(p->expression));
        p->next = free_;
        free_ = p;
        printf("watchpoint %d had been deleted\n", NO);
        break;
      }
      else {
        q = p;
        p = p->next;
      }
    }
    if (p == NULL)
      printf("watchpoint %d was not found\n", NO);
  }
}

void watchpoint_printf() {
  WP *p = head;
  if(p == NULL) {
    printf("watchpoint link is empty\n");
  }
  else {
    while(p!=NULL) {
     printf("%d\t%s\t\t0x%08x\n", p->NO, p->expression, p->result);
     p = p->next;
    }
  }
}

int watchpoint_exec(int *sign) {
  for(int i = 0; i < NR_WP; i++) {
    if(wp_pool[i].enable) {
      bool success = true;
      //printf("%s\n", wp_pool[i].expression);
      int temp = 0;
      if(strcmp(wp_pool[i].expression, "\0") == 0) {
        *sign = 3;
        return 0;
      }
      else {
        temp = expr(wp_pool[i].expression, &success);
      }
      if(success) {
        //printf("参加了判断\n");
        //printf("%d  %d\n", temp, wp_pool[i].result);
        if(temp!=wp_pool[i].result) {
          *sign = 1;
          return i;
        }
      }
      else {
        *sign = 2;
        return i;
      }
    }
  }
  return 0;
}


/* TODO: Implement the functionality of watchpoint */

