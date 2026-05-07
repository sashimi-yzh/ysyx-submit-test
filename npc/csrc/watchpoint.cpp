#include "common.h"
#include "debug.h"
#include "macro.h"
#include "utils.h"
#include "include.h"



#define NR_WP 32

static WP wp_pool[NR_WP] = {};//pool
WP *head = NULL,*free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    strcpy(wp_pool[i].tokens,"\0\0\0\0\0\0\0\0\0\0\0\0");
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

WP* new_wp(char * arg, uint32_t value){
  WP* tmp=NULL;
  if(free_ == NULL) {
    assert(0);
  }
  else {
    
    if(head==NULL) {
      head = free_;
      free_ = free_->next;
      head->next=NULL;
    }
    else {
      tmp = free_;
      free_ = free_->next;
      tmp->next = head;
      head = tmp;
    }

    strcpy(head->tokens,arg);
    printf("%s",head->tokens);
    head->value = value;

    
  }
  return head;

}



void free_wp(int num){
  WP *p,*q;
  p = head;
  int flag=0;
  if(head == NULL) {
    assert(0);
  }
  else {
    if(p->NO == num){
      head = head->next;
      p->next = free_;
      free_ = p;
      //printf("wp==head\n\r");
    }
    else {
      p=head;
      q=head->next;

      while(q!=NULL) { 
        if(q->NO==num){
          p->next = q->next;
          q->next=free_;
          free_ = q;
          flag=1;
          break;
        }
        p=p->next;
        q=q->next;
      }
      if(flag==0) printf("no watchpoint numbered %d\n\r",num);

    }
    
  }
  return;

}

void print_wp(){
  WP *p;
  p = head;
  if(p==NULL) {
    printf("no watchpoint!\n\r");
  }
  else {
    while(p!=NULL) {
      printf("watchpoint NO.%d %s 0x%x\n\r",p->NO,p->tokens,p->value);
      p = p->next;
    }
    
  }
}