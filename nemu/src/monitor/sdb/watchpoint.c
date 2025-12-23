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
#include <utils.h>

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  char expr[100];
  word_t old;
  /* TODO: Add more members if necessary */

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

static WP* new_wp(){
  assert(free_);
  WP* ret = free_;
  free_ = free_->next;
  ret->next = head; 
  head = ret;
  return ret;
}

static void free_wp(WP *wp) {
  WP* h = head;
  if (h == wp) head = NULL;
  else {
    while (h && h->next != wp) h = h->next;
    assert(h);
    h->next = wp->next;
  }
  wp->next = free_;
  free_ = wp;
}

void wp_display() {
  WP* h = head;
  if (!h) {
    puts("No watchpoints.");
    return;
  }
  printf("%-8s%-8s\n", "Num", "What");
  while (h) {
    printf("%-8d%-8s\n", h->NO, h->expr);
    h = h->next;
  }
}

void wp_set(char *expr, word_t res) {
  WP* wp = new_wp();
  strcpy(wp->expr, expr);
  wp->old = res;
  printf("Watchpoint %d: %s\n", wp->NO, expr);
}

void wp_delete(int no) {
  assert(no < NR_WP);
  WP* wp = &wp_pool[no];
  free_wp(wp);
  printf("Delete watchpoint %d: %s\n", wp->NO, wp->expr);
}

void wp_difftest() {
  WP* h = head;
  while (h) {
    bool _;
    word_t new = expr(h->expr, &_);
    if (h->old != new) {
      nemu_state.state = NEMU_STOP;
      printf("Watchpoint triggered!\n");
      printf("Watchpoint %d: %s\n"
        "Old value = 0x%x\n"
        "New value = 0x%x\n"
        , h->NO, h->expr, h->old, new);
      h->old = new;
    }
    h = h->next;
  }
}


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

