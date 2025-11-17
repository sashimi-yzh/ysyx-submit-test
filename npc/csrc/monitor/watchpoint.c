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
#include <memory/vaddr.h>
#include <isa.h>
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

WP* get_head(){
  return head;
}

/* TODO: Implement the functionality of watchpoint */
// return watchpoint NO
int new_wp(word_t value, char* args,int wp_type){
    if(!free_) {
      assert(0);
    } 
    WP* temp = free_;
    free_ = free_->next;
    temp->next = head;
    head = temp;
    
    temp->value = value;
    temp->wp_type = wp_type;
    if (wp_type==WP_BREAK){
      strncpy(temp->args,"$pc",4);
    } else {
      char* res = strncpy(temp->args,args,32);
      Assert(res!=NULL,"watch point args: %s invalid",args); 
    }
    return head->NO;
}

void free_wp(WP *wp){
    
    if (head == wp){
      head = head->next;
    } else{
      WP* cur = head;
      while(cur->next != NULL && cur->next!=wp){
          cur = cur->next;
      }
      if (cur->next != NULL){
        cur->next = cur->next->next;
      }
    }
    
    wp->next = free_;
    free_ = wp;
    return;
}

void delete_wp(int no){
    WP *wp = &wp_pool[no];
    free_wp(wp);
    return;
}

int head_wp_no(){
  return head->NO;
}

/* return watchpoint change or not*/
bool wps_diff(){
  WP *cur = head;
  bool change=false;
  while(cur !=NULL){
      //TODO: should support different expr
      bool success;
      word_t new_wp = isa_reg_str2val(cur->args,&success);
      if (cur->wp_type == WP_RAW&&new_wp != cur->value){
          printf("Num: %d, Old %x, New: %x\n",cur->NO,cur->value,new_wp);
          cur->value = new_wp;
          change = true;
      } else if (cur->wp_type == WP_BREAK && new_wp==cur->value){
          // arrive break point should stop.
          change = true;
          printf("BreakPoint Num: %d, pc:0x%x,\n",cur->NO,new_wp);
      }
      cur = cur->next;
  }
  return change;
}