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
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].expr[0] = '\0';
    wp_pool[i].new_value = 0;
    wp_pool[i].old_value = 0;
    wp_pool[i].hit_count= 0;
  }

  head = NULL;
  free_ = wp_pool;
}


WP *new_wp() {
    if(free_ == NULL) {
        printf("Error: watchpoint pool full\n");
        return NULL;
    }
    WP *wp = free_;
    free_ = free_->next;
    
    wp->next = head;
    head = wp;

    return wp;
}

void free_wp(uint32_t N) {
    WP *index = head;
    WP *wp = NULL;
    WP *prev = head;
    for(; index != NULL; index = index->next) {
        if(index->NO == N) {
            wp = index;
            break;
        } 
        prev = index;
    }

    if(wp == NULL) {
        printf("Error: no this wp!\n");
        return ;
    }

    printf("Successfully del #%d watchpoint\n", N);

    if(wp == head) {
        head = wp->next;
    } else {
        prev->next = wp->next;
    }

    wp->next = free_;
    free_ = wp;
}

void set_watchpoint(char *expr) {
    WP *wp = new_wp();
    if(wp == NULL) {
        printf("Error to set wp\n");
        return ;
    }

    bool success = false;

    strncpy(wp->expr, expr, sizeof(wp->expr)-1);
    wp->old_value = eval_expr(expr, &success);
    if(!success) {
        printf("Error: eval expr error to watch point\n");
        free_wp(wp->NO);
        return ;
    }
    wp->new_value = wp->old_value;
    wp->hit_count = 0;

    printf("Set wp: #%d: %s\n", wp->NO, expr);
    return ;
}

void check_watchpoint() {
    WP *wp = head;
    bool success = false;
    uint32_t times = 0;

    while(wp != NULL) {
        wp->new_value = eval_expr(wp->expr, &success);
        assert(success);
        if(wp->new_value != wp->old_value) {
            printf("Wp #%d ack: %s\n", wp->NO, wp->expr);
            printf("Old: 0x%08x, New: 0x%08x\n", wp->old_value, wp->new_value);
            wp->old_value = wp->new_value;
            wp->hit_count++;
            times++;
        }
        wp = wp->next;
    }
    if(times != 0) {
        if(nemu_state.state == NEMU_RUNNING)
            nemu_state.state = NEMU_STOP;
    }
}

void info_watchpoint() {
    if(head == NULL) {
        printf("No watchpoint!\n");
        return ;
    }

    printf("NUM        EXPR    VALUE          HIT\n");
    WP *index = head;
    while(index != NULL) {
        printf("#%-3d       %.10s     0x%08x      %d\n", index->NO, index->expr, index->new_value, index->hit_count);
        index = index->next;
    }
    return ;
}
