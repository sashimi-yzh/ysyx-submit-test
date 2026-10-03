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

#include "common.h"
#include "sdb.h"

#define NR_WP 32

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;
WP* new_wp(char * args,word_t result);
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
WP* new_wp(char *args,word_t result){
    if(free_==NULL){
        assert(0);
    }
    WP* wptr=free_;
    free_=free_->next;
    wptr->next=head;
    head=wptr;
    wptr->times=0;
    wptr->result=result;
    strncpy(wptr->args,args,NR_WP_ARGS);
    wptr->args[NR_WP_ARGS-1]='\0';
    printf("watchpoint %d:%s\n",wptr->NO,wptr->args);
    return wptr;
}
void free_wp(int i){
    WP* wp=wp_pool+i;
    if(head==NULL)
        return ;
    WP * tmp=head;
    if(wp==tmp){
        head=head->next;
        wp->next=free_;
        free_=wp;
    }else 
        while(tmp->next){
            if(tmp->next==wp){
                tmp->next=wp->next;
                wp->next=free_;
                free_=wp;
                return ;
            }
        }
    return ;
}
int Scan_WP(){
    WP *wptr;bool success;word_t ret;
    wptr=head;
    int flag=0;
    while(wptr!=NULL){
        ret=wptr->result;
        wptr->result=expr(wptr->args,&success);
        if(ret!=wptr->result){
            wptr->times=wptr->times+1;
            printf("watchpoint %d:%s\n",wptr->NO,wptr->args);
            printf("Old value: %u\n",ret);
            printf("New value: %u\n",wptr->result);
            flag=1;
        }
        wptr=wptr->next;
    }
    if(flag==1)
        return 1;
    return 0;
}
void show_WP(){
    printf("%-8s %-16s %-5s %-4s %-10s %-s\n","Num","Type","Disp","Enb","Address","What");
    WP*wptr=head;
    while(wptr!=NULL){
        printf("%-8d %-16s %-5s %-4s %-10s %-s\n",wptr->NO,"watchpoint","keep","y","",wptr->args);
        if(wptr->times!=0){
            printf("%8s breakpoint already hit %d time\n","",wptr->times);
        }
        wptr=wptr->next;
    }
}
