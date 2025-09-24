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
#include <assert.h>

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  word_t val;
  char e[256];
} WP;

// new to address
#define NEW(wp) \
  do { \
    wp = new; \
    free_ = free_->next; \
    new->next = NULL; \
  } while (0)

// free address
#define FREE(wp) \
  do { \
    if (free_ == NULL) { \
      free_ = match; \
      match->next = NULL; \
    } \
    else { \
      wp = match->next; \
      WP *tail; \
      for (tail = free_; tail->next; tail = tail->next); \
      tail->next = match; \
      match->next = NULL; \
      memset(match->e, '\0', 256); \
    } \
  } while (0) \

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    memset(wp_pool[i].e, '\0', 256); \
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
static WP *new_wp() {
  WP *new  = free_;
  if (head == NULL) {
    NEW(head);
  } else {
    WP *tail;
    for (tail = head; tail->next; tail = tail->next);
    NEW(tail->next);
  }
  return new;
}

static void free_wp(int n) {
  WP *match;
  WP *prev = head;
  for (match = head; match != NULL; prev = match, match = match->next) {
    if (match->NO == n) {
      if (match == head) {
        FREE(head);
      } else {
        FREE(prev->next);
      }
      break;
    }
  }
  if (match == NULL) 
    printf("No matching watchpoint %d can be deleted\n", n);
}

void add_wp(word_t val, char *e) {
  if (free_ == NULL) assert(0);

  WP *new = new_wp();
  new->val = val;
  strcpy(new->e, e);
}

void delete_wp(int n) {
  free_wp(n);
}

void info_wp() {
  WP *wp;
  if (head == NULL)
    printf("No using watchpoint\n");
  else {
    printf("%-8s %s\n", "Num", "What");
    for (wp = head; wp; wp = wp->next) {
      printf("%-8d %s\n", wp->NO, wp->e);
    }
  }
}

int scan_wp() {
  WP *wp;
  bool success = true;
  int change = 0;
  for (wp = head; wp; wp = wp->next) {
    word_t val = expr(wp->e, &success);
    if (wp->val != val) {
      change = -1;
      printf("Watchpoint %d: %s\n\n", wp->NO, wp->e);
      printf("Old value = 0x%.8x  %u\n", wp->val, wp->val);
      printf("New value = 0x%.8x  %u\n", val, val);
    }
  }
  return change;
}
