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

#include <string.h>
#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  word_t result;
  char* expr;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;
WP* new_wp();
void free_wp(WP *wp);
void set_point(char* expr,word_t result);
void remove_point(int no);
void point_difftest();

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
WP* new_wp(){

  // there is no free point
  if(free_ == NULL){
    assert(0);
  }

  WP* new_node = free_;
  free_ = free_->next;
  new_node->next = head;
  head = new_node;

  return new_node;
}


void free_wp(WP *wp){
  bool flag = false;
  if(wp == head){
    head = head->next;
    flag = true;
  }else{
    WP* temp = head->next;
    WP* pre = head;
    
    while(temp != NULL){
      if(temp == wp){
        pre->next = temp->next;
        flag = true;
        break;
      }
      pre = temp;
      temp = temp->next;
    }
  }

  if(flag){
    // 释放给监视点的表达式申请的空间
    free(wp->expr);
    wp->next = free_;
    free_ = wp;
  }
}

void set_point(char* expr,word_t result){
  WP* wp = new_wp();
  wp->expr = (char*)malloc(strlen(expr) * sizeof(char) + 1);
  strcpy(wp->expr, expr);
  wp->result = result;
  printf("Watchpoint %d:%s\n",wp->NO,wp->expr);
}

void remove_point(int no){
  if(no < 0 || no >= NR_WP){
    printf("N is not in right\n");
    assert(0);
  }
  WP* wp = &wp_pool[no];
  char *expr = (char*)malloc(sizeof(wp->expr)+1);
  strcpy(expr,wp->expr);
  free_wp(wp);
  printf("Delete watchpoint %d:%s\n",no,expr);
  free(expr);
}

void point_difftest(){
  WP *wp = head;
  while(wp!=NULL){
    bool success = false;
    word_t new_value = expr(wp->expr,&success);
    if(wp->result != new_value){
      printf("watchpoint %d:%s has changed,old value is " FMT_WORD ",new value is " FMT_WORD "\n",wp->NO,wp->expr,wp->result,new_value);
      wp->result = new_value;
      nemu_state.state = NEMU_STOP;
    }
    wp = wp->next;
  }
}

void point_display(){
  WP* cur = head;
  printf("NO\t\t\tExpr\t\t\t\t\tValue\n");
  while(cur != NULL){
    printf("%d\t\t\t%s\t\t\t\t\t%d\n",cur->NO,cur->expr,cur->result);
    cur = cur->next;
  }
}