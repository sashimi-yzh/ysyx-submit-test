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

WP* new_wp(){
  if(free_ == NULL){
    assert(0);
  }
  else{
    WP* wp = free_;
    free_ = free_->next;
    wp->next = head;
    head = wp;
    return wp;
  }
}

void free_wp(WP *wp){
  if (wp == NULL) {
    printf("the wp you want to free is NULL\n");
    return;
  }

  if (head == NULL) {
    printf("No watchpoints are currently in use\n");
    return;
  }
  
  if (head == wp) {
    head = wp->next;
  } 
  else {
    WP* find = head;
    while(find->next != NULL){
      if(find->next == wp){
        find->next = wp->next;
        break;
      }
      else{
        find = find->next;
      }
    }
  }
  wp->next = free_;
  wp->value = 0;
  wp->expr[0] = '\0';
  free_=wp;
}

void update_wp_value(){
  WP* wp = head;
  while(wp != NULL){
    bool success = false;
    uint32_t update_value = expr(wp -> expr,&success);
    if (success == false){
      printf("expr function false while updating wp, how can you trigger this?\n");
      assert(0);
    }
    else{
      if(wp->value != update_value){
        printf("trigger wp, expr:%s, oldvalue:%u(DEC) 0x%08x(HEX), new_value:%u(DEC) 0x%08x(HEX)\n",wp->expr, wp->value, wp->value, update_value, update_value);
        if(nemu_state.state == NEMU_END){
          printf("the wp triggered is the end of the programe\n");
        }
        else{
          nemu_state.state = NEMU_STOP;
        }
        wp->value = update_value;
      }
    }
    wp = wp -> next;
  }
}

void delet_wp(int N){
  WP* wp = head;
  while(wp != NULL){
    if(wp -> NO == N){
      free_wp(wp);
      printf("delete NO.%d wp success\n",N);
      return;
    }
    wp = wp -> next;
  }
  printf("can not find NO.%d wp or it is free\n",N);
}

void wp_display(){
  WP* wp;
  printf("Used WP:\n");
  wp = head;
  while(wp != NULL){
    printf("NO.%d, expr:%s, value: %u(DEC) 0x%08x(HEX)\n",wp->NO, wp->expr, wp->value, wp->value);
    wp = wp -> next;
  }
  printf("Free WP:\n");
  wp = free_;
  while(wp != NULL){
    printf("NO.%d, expr:%s, value: %u(DEC) 0x%08x(HEX)\n",wp->NO, wp->expr, wp->value, wp->value);
    wp = wp -> next;
  }
}
