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
#define NR_WP 32 // 控制监视点的数量
#include "watchpoint.h"
/*
typedef struct watchpoint {
    int NO;
    struct watchpoint *next;

    //  TODO: Add more members if necessary 

    bool flag; // use / unuse
    char expr[100];
    int new_value;
    int old_value;

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;
*/
WP wp_pool[NR_WP] = {};
void init_wp_pool() 
{
    int i;
    for (i = 0; i < NR_WP; i ++) {
	wp_pool[i].NO = i;
	wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
	wp_pool[i].flag = false;
    }

    head = NULL;
    free_ = wp_pool;
}

/*
 * head 在这里并没有使用，直接使用 WP 结构体中的flag标志来进行区分不同的状态
 * */

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
    printf("No unuse watchpoint.\n");
    
    return NULL;

}


void free_wp(WP *wp){
    if(head -> NO == wp -> NO){
    	head -> flag = false;
    	if(head -> next!=NULL){
    	head = head->next;}
    	else{
	head = NULL;
	}
	 
	return ;
    }
    for(WP* p = head ; p -> next != NULL ; p = p -> next){
	if(p -> next-> NO  == wp -> NO)
	{
	    p ->next-> flag = false;
	    p -> next = p -> next -> next;
	    
	     
	    return; 
	}
    }

}


void sdb_watchpoint_display(){
    bool flag = true;
    for(int i = 0 ; i < NR_WP ; i ++){
	if(wp_pool[i].flag){
	    printf("Watchpoint.No: %d, expr = \"%s\", old_value = %u ,new_value = %u \n", 
		    wp_pool[i].NO, wp_pool[i].expr,wp_pool[i].old_value,wp_pool[i].new_value);
		flag = false;
	}
    }
    if(flag) printf("No watchpoint now.\n");
}
 

void delete_watchpoint(int num) {
    if (num >= 32 || num < 0) {
        printf("out of range.\n");
        return;
    }

    for (int i = 0; i < NR_WP; i++) {
        if (wp_pool[i].NO == num) {
            if (!wp_pool[i].flag) {
                printf("No watchpoint No.%d now.\n", num);
                return;
            }
             
            free_wp(&wp_pool[i]);
            printf("Delete watchpoint N0.%d success.\n",num);
            return; 
        }
    }

    printf("Watchpoint No.%d not found.\n", num);
}

void create_watchpoint(char* args){
     
    bool success = false;
    bool division_by_zero = false;
     
    int tmp = expr(args, &success, &division_by_zero);
   if(success) {
   	WP* p =  new_wp();
   	if (!p) return;
    	strcpy(p -> expr, args);
    	p -> old_value = tmp;
    	printf("Create watchpoint No.%d success.\n", p -> NO);
    }
   else {printf("worng!\n");}
     
}

