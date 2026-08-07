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
#include <stdlib.h>

#define NR_WP 32
static int wp_no = 0;
static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

WP *new_wp() {
  if (free_ == NULL) {
    puts("There is no free monitoring point returned in the free_ linked list");
    return NULL;
  }
  WP *freeWP = free_;
  free_ = free_->next;
  freeWP->next = head;
  freeWP->NO = ++wp_no;
  head = freeWP;
  return freeWP;
}

static void free_wp(WP *wp) {
  if (head == NULL) {
    puts("There is no busy monitoring point free into the head linked list");
    return;
  }
  WP *front = head;
  WP *tail = NULL;
  while (front != NULL) {
    if (front == wp) {
      if (tail != NULL) {
        tail->next = front->next;
      } else {
        head = head->next;
      }
      front->next = free_;
      free_ = front;
      return;
    }
    tail = front;
    front = front->next;
  }
  printf("Warning: wp not found in busy list.\n");
}

void checkWatchPoint() {
  WP *freeWP = head;
  word_t newValue;
  bool success = true;
  while (freeWP != NULL) {
    newValue = expr(freeWP->express, &success);
    if (newValue != freeWP->oldValue) {
      printf("Hardware watchpoint %d: %s\n\n", freeWP->NO, freeWP->express);
      printf("Old value = %u\n", freeWP->oldValue);
      printf("New value = %u\n", newValue);
      nemu_state.state = NEMU_STOP;
      freeWP->oldValue = newValue;
    }
    freeWP = freeWP->next;
  }
}

void infoWatchPoint() {
  WP *cur = head;
  if (cur == NULL) {
    printf("No watchpoints\n");
    return;
  }
  printf("|%-10s|%-10s|%s\n", "Num", "HexValue", "What");
  while (cur != NULL) {
    printf("|%-10d|%-10x|%s\n", cur->NO, cur->oldValue, cur->express);
    cur = cur->next;
  }
}

void free_wpByNO(int NO, bool *success) {
  *success = true;
  WP *freeWP = head;
  while (freeWP != NULL) {
    if (freeWP->NO == NO) {
      break;
    }
    freeWP = freeWP->next;
  }
  if (freeWP == NULL) {
    *success = false;
    return;
  }
  free_wp(freeWP);
}
