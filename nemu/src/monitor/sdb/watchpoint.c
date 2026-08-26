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
static WP *head = NULL, *free_ = NULL, *tail = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);

  }

  head = NULL;
  free_ = wp_pool;
}

int new_wp(char *arg,uint32_t val){
  if(free_==NULL){
    return -1;
  }
  if(head==NULL){
    head=free_;
    free_=free_->next;
    head->next=NULL;
  }else{
    WP* tmp;
    tmp=free_;
    free_=free_->next;
    tmp->next=head;
    head=tmp;
  }
  head->val=val;
  memset(head->expr,0,sizeof(head->expr));
  strcpy(head->expr,arg);
  return head->NO;
}
void free_wp(WP *wp){
  WP *i=head;
  if(head==wp){
    WP* tmp;
    tmp=head;
    head=head->next;
    tmp->next=free_;
    free_=tmp;
    return;
  }

  while(i->next!=wp){
    i=i->next;
    if(i==tail){
      printf("No watchpoint!\n");
      return;
    }
  }
  i->next=wp->next;
  wp->next=free_;
  free_=wp;
}

WP *find_wp(int n){
  WP *i=head;
  if(i==NULL) return NULL;
  while(i->NO!=n){
    
    i=i->next;
    if(i==NULL) return NULL;
  }
  return i;
}

void print_wp(){
  printf("Used:\n");
  WP *wp=head;
  bool success=true;
  printf("id\tvalue\texp\n");
  while(1){
    if(wp==NULL)  break;
    uint32_t val=expr(wp->expr,&success);
    if(success==false) printf("Error experiment!\n");
    printf("%d\t%u\t\t%s\n",wp->NO,val,wp->expr);
    wp=wp->next;
  }
  wp=free_;
  printf("Unused:\n");
  while(1){
    if(wp==NULL)  break;
    printf("%d  ",wp->NO);
    wp=wp->next;
  }
  printf("\n");
}

int diff_wp(int n){
  bool success=true;
  WP *wp=find_wp(n);
  if(wp!=NULL){
    if(expr(wp->expr,&success)!=wp->val){
      return 1;
    }
    return 0;
  }else{
    return -1;
  }

}
/* TODO: Implement the functionality of watchpoint */

