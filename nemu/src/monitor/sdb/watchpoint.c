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
#include <watchpoint.h>
#include <fmt-def.h>



static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

WP* new_wp();
void free_wp(WP *wp);


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


WP* new_wp()
{
  if (free_ == NULL){
    printf("Ther is no free watchpoint!\n");
    return NULL;
  }

  //static int number = 0;

  WP* tmp = free_;
  free_ = free_->next;  //从空闲链表中取出
  tmp->next = head; 
  head = tmp;           //将添加的监视点添加到在使用的链表中
  
  head->expr[0] = '\0';
  head->value = 0;
  head->value_old = 0;
  //head->NO = number++;

  return head;
}
void free_wp(WP *wp)
{
  if(wp == NULL){
    printf("Ther is no used watchpoint!\n");
    assert(0);
    return;
  }

  WP* tmp = NULL;

  if(head == wp){
    tmp =  free_;
    free_ = head;
    head = head->next;
    free_->next = tmp;
  } else {
    for(WP* p = head; p!=NULL; tmp = p, p = p->next){
      if(p == wp){
        tmp->next = p->next;  //第一次循环，p肯定不等于wp，因为head!=wp, p==head,
                              //故在tmp赋值前必定不会执行这个语句
        p->next = free_;
        free_ = p;
        return;
      }
    }
  }
}




void set_watchpoint(char *e)
{
  WP* wp = new_wp();
  assert(wp != NULL);
  strcpy(wp->expr, e);
  bool succ = true;
  uint64_t result = expr(wp->expr, &succ);
  assert(succ == true);
  wp->value_old = result;
  wp->value =result;
  printf("Set watchpoint: %d: %s\n", wp->NO, wp->expr);
}
void del_watchpoint(int NO)
{
  for (WP* p = head; p!=NULL; p=p->next)
  {
    if(p->NO == NO){
      free_wp(p);      
      return;
    }
  }
  printf("Can not find watchpoint: NO. %d\n",NO);
  
}

void print_watchpoint()
{
  printf("Num\t Value\t\t\t What\n");
  for (WP* p = head; p!=NULL; p=p->next)
  {
    printf("%d\t 0x" FMT_WORD_HEX "\t\t %s\n",p->NO,p->value_old,p->expr);
  }
}
void scan_watchpoint(){
  for(WP* p = head; p!=NULL; p=p->next){
    bool succ=true;
     word_t result = expr(p->expr, &succ);
     assert(succ);
     if(result != p->value_old){
      p->value = result;
      nemu_state.state = NEMU_STOP;
      printf("Watchpoint %d: %s\n", p->NO, p->expr);
      printf("Old value = " FMT_WORD_UINT "  0x" FMT_WORD_HEX_WIDTH "\n", p->value_old,p->value_old);
      printf("New value = " FMT_WORD_UINT "  0x" FMT_WORD_HEX_WIDTH "\n",p->value,p->value);

      p->value_old = p->value;
     }
  }
}

