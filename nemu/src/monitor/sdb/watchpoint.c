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
  bool flag;//是否被使用
  char expr[100];
  int new_val;
  int old_val;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;//head用于组织使用中的监视点结构, free_用于组织空闲的监视点结构

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
  for(WP* p = free_ ; p -> next != NULL ; p = p -> next){
    if( p -> flag == false){
      p -> flag = true;
      if(head == NULL){
        head = p;
      }
      return p;
    }
  }
  printf("No unuse point.\n");
  assert(0);
  return NULL;
}

void free_wp(WP *wp){
  if(head -> NO == wp -> NO){
    head -> flag = false;
    head = NULL;
    printf("Delete watchpoint  success.\n");
    return ;
  }
  for(WP* p = head ; p -> next != NULL ; p = p -> next){
    if(p -> next -> NO  == wp -> NO)
    {
      p -> next = p -> next -> next;
      p -> next -> flag = false; // 没有被使用
      printf("free succes.\n");
      return ;
    }
  }
}

void delete_watchpoint(int no){
  for(int i = 0 ; i < NR_WP ; i ++){
    if(wp_pool[i].NO == no){
      free_wp(&wp_pool[i]);
      break;
    }  
  }
}

void create_watchpoint(char* args){
  WP* p =  new_wp();
  strcpy(p -> expr, args);
  bool success = false;
  int tmp = expr(p -> expr,&success);
  if(success){
    p -> old_val = tmp;
    p -> new_val = tmp;
  } 
  else{
    printf("expr wrong\n");
  } 
  printf("Create watchpoint No.%d success.\n", p -> NO);
}

void sdb_watchpoint_display(){
  bool flag = true;
  for(int i = 0 ; i < NR_WP ; i ++){
    if(wp_pool[i].flag){
      printf("Watchpoint.No: %d, expr = \"%s\", old_value = %d, new_value = %d\n",
             wp_pool[i].NO, wp_pool[i].expr,wp_pool[i].old_val, wp_pool[i].new_val);
      flag = false;
    }
  }
  if(flag){
    printf("No watchpoint now.\n");
  } 
}

bool watchpoint_diff(int i){

  if(wp_pool[i].flag)
  {
    bool success = false;
    int tmp = expr(wp_pool[i].expr,&success);
    // printf("%x\n",tmp);
    if(success){
      if(tmp != wp_pool[i].old_val)
      {
        wp_pool[i].new_val = tmp;
        return true;
      }
      else
      {
        return false;
      }
    }
    else{
      printf("watchpoint %d expr error.\n", i);
      assert(0);
      return false;
    }
  }
  else{
    return false;
  }
}
  
void print_watchpoint(int i){

  if(wp_pool[i].flag){
    printf("Watchpoint.No: %d, expr = \"%s\", old_value = %x, new_value = %x\n",
          wp_pool[i].NO, wp_pool[i].expr,wp_pool[i].old_val, wp_pool[i].new_val);
  }
  else{
    printf("The watchpoint is not used\n");
  }
}

void wp_init(int i){
  if(wp_pool[i].flag){
    wp_pool[i].old_val = wp_pool[i].new_val;
  }
}
