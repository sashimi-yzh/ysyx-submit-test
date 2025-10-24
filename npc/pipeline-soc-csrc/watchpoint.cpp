#include "../include/watchpoint.h"

#define NR_WP 32

// typedef struct watchpoint {
//   int NO;
//   struct watchpoint *next;

//   /* TODO: Add more members if necessary */
//   struct watchpoint *prev;//设置双向链表，更容易维护
//   char *expr;
//   word_t old_val;
// } WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);//初始化构建监视点池链表
    wp_pool[i].prev=(i==0?NULL:&wp_pool[i-1]);
  }

  head = NULL;
  free_ = wp_pool;
}

WP *get_wp_head(){
  return head;
}

void update_all_watchpoint_NOs(){
  WP *wp=head;
  int n0=1;
  while(wp!=NULL){
    wp->NO=n0++;
    wp=wp->next;
  }
}

WP *new_wp(){
  WP *wp=NULL;
  if(free_==NULL){
    printf("No more free watchpoints available\n");
    //assert(0);
    return 0;
  }else{
    wp=free_;
    free_=free_->next;
    if(free_!=NULL){
      free_->prev=NULL; //更新free_的prev 指针
    }
    wp->next=head;
    wp->prev=NULL; //新加入的监视点没有前驱(链表过程看笔记)
    if (head){
      head->prev=wp; //更新原来头部的 prev 指针
    }
    head=wp;
    update_all_watchpoint_NOs();
  }
  return wp;
}

void free_wp(WP *wp){
  if(wp != NULL){
    if(wp->prev){
      wp->prev->next=wp->next; //更新前驱的next指针
    }else{
      head=wp->next; //如果是头结点更新head
    }
    if(wp->next){//如果不是在末尾
      wp->next->prev=wp->prev; //更新后继的prev指针
    }
    wp->next=free_;
    wp->prev=NULL; //free_链表中的新节点没有前驱
    if(free_!=NULL){
      free_->prev=wp; //更新新的 free_的prev 指针
    }
    free_=wp;
    update_all_watchpoint_NOs();
  }
}

/* TODO: Implement the functionality of watchpoint */

