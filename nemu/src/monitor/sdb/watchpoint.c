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
#include <isa.h>

#define NR_WP 32
#define SIZE_WP 128UL
#define LEN_EXPR (SIZE_WP - sizeof(int) - sizeof(int *) - sizeof(word_t))
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  char expr_str[LEN_EXPR];
  word_t old_val;
  

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;
static uint32_t WP_NO = 0;
void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}
WP* pop_node(WP** list){
  WP* res;
  if(list == NULL) return NULL;
  if(*list == NULL) return NULL;
  if((*list)->next == NULL){
    res = *list;
    *list = NULL;
  }
  else{
    res = *list;
    *list = (*list)->next; 
  }
  res->next = NULL;
  return res;
}
void insert_node(WP* node,WP** list){
  if(node == NULL) return;
  if(list == NULL) return;
  if(*list == NULL){
    *list = node;
    node->next = NULL;
  }else{
    node->next = (*list);
    (*list) = node;
  }
}

bool in_list(WP* node, WP** list){
    if(node == NULL) return false;
    if(list == NULL) return false;  
    if(*list == NULL) return false; 

    WP* current = (*list); 

    while(current){
      if(current == node) return true;
      current = current->next;
    }

    return false; 
}
void remove_node(WP*node,WP**list){
    if(node == NULL) return;
    if(list == NULL) return;  
    if(*list == NULL) return; 

    WP* current = (*list); 
    if(current == node) {
      *list = (*list)->next;
      return;
    }
    while(current->next){
      if(current->next == node){
        current->next = node->next;
        return;
      }
      current = current->next;
    }

    return; 
}

WP* new_wp(){
  WP* res = pop_node(&free_);
  if(res == NULL) return NULL;
  else{
    insert_node(res,&head);
  }
  return res;
}

void free_wp(WP *wp){
  if(wp){
    if(in_list(wp,&head)){
      remove_node(wp,&head);
      insert_node(wp,&free_);
    }
  }
}

bool add_wp(char *expr_str){
  bool success = false;
  if(strlen(expr_str) >= LEN_EXPR){
    printf("error: string is too long\n");
    return false;
  }
  word_t val = expr(expr_str,&success);
  if(!success){
    printf("error: experssion is wrong\n");
    return false;
  }
  WP* wp = new_wp();
  if(wp == NULL){
    printf("error: cannot add watchpoint\n");
    return false;
  }else{
    wp->NO = WP_NO++;
    strcpy(wp->expr_str,expr_str);
    wp->old_val = val;
    printf("set watchpoint %u\n",WP_NO-1);
    return true;
  }
}

bool remove_wp(uint32_t no){
  if(head == NULL){
    printf("NO. %u watchpoint not exists\n",no);
    return false;
  }
  WP* cur = head;
  while(cur){
    if(cur->NO == no)break;
    cur = cur->next;
  }
  if(cur && cur->NO == no){
    free_wp(cur);
    printf("remove NO. %u watchpoint at %s\n",no,cur->expr_str);
    return true;
  }else{
    printf("NO. %u watchpoint not exists\n",no);
    return false;
  }
}

bool check_wp(){
  bool res = false;
  if(head){
    WP* cur = head;
    while(cur){
      bool success;
      word_t val = expr(cur->expr_str,&success);
      if(val != cur->old_val){
        res = true;
        printf("Watchpoint %u: %s\n",cur->NO,cur->expr_str);
        printf("Old value = %x\nNew value = %x\n",cur->old_val,val);
        printf("\n");
        cur->old_val = val;
      }
      cur = cur->next;
    }
  }
  return res;
}

void info_wp(){
  if(head){
    WP* cur = head;
    printf("Num     Value       What\n");
    while(cur){
      printf("%-8u0x%-10x%s\n",cur->NO,cur->old_val,cur->expr_str);
      cur = cur->next;
    }
  }
  return;
}

/* TODO: Implement the functionality of watchpoint */

