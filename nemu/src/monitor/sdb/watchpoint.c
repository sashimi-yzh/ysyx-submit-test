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

WP *head = NULL, *free_ = NULL;
WP wp_pool[NR_WP] = {

};

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
        if( p -> is_used == false){
            p -> is_used = true;
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
        head -> is_used = false;
        head = NULL;
        printf("Delete watchpoint  success.\n");
        return ;
    }
    for(WP* p = head ; p -> next != NULL ; p = p -> next){
        if(p -> next -> NO  == wp -> NO)
        {
            p -> next = p -> next -> next;
            p -> next -> is_used = false; // 没有被使用
            printf("free succes.\n");
            return ;
        }
    }
}

void sdb_watchpoint_display(){
    bool flag = true;
    for(int i = 0 ; i < NR_WP ; i ++){
        if(wp_pool[i].is_used){
            printf("Watchpoint.No: %d, expr = \"%s\", old_value = %d, new_value = %d\n",
                    wp_pool[i].NO, wp_pool[i].expr,wp_pool[i].old_value, wp_pool[i].new_value);
                flag = false;
        }
    }
    if(flag)
		printf("No watchpoint now.\n");
}

void delete_watchpoint(int no){
    for(int i = 0 ; i < NR_WP ; i ++)
        if(wp_pool[i].NO == no){
            free_wp(&wp_pool[i]);
            return ;
        }
}

void create_watchpoint(char* args){
    WP* p =  new_wp();

    args = strtok(args, " ");
    char *op = strtok(NULL, " ");
    char *break_num = strtok(NULL, " ");

    if(op != NULL) {
        strcpy(p -> op, op);
    }

    if(break_num != NULL) {
        if(break_num[0] == '0' && (break_num[1] == 'x' || break_num[1] == 'X'))
            sscanf(break_num, "%x", &p -> break_value);
        else
            sscanf(break_num, "%d", &p -> break_value);
    }

    printf("args is %s\nop is %s\nbreak_num is %s\n", args, op, break_num);

    strcpy(p -> expr, args);
    bool success = false;
    int tmp = expr(p -> expr,&success);
  	if(success)
		p -> old_value = tmp;
    else
		printf("创建watchpoint的时候expr求值出现问题\n");
    printf("Create watchpoint No.%d success.\n", p -> NO);
}

