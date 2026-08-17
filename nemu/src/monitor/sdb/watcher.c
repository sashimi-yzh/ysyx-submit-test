/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include "watcher.h"
#include "ST.h"
#include "common.h"
#include "debug.h"
#include "sdb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static Token token_buffer[TOKEN_MAX_COUNT];

WP *new_wp(char *expression, long long value, bool is_hex) {
  if (free_ == NULL)
    return NULL;
  WP *ret = free_;
  free_ = free_->next;
  ret->next = head;
  head = ret;
  int token_cnt;

  if (!make_token(expression, token_buffer, &token_cnt)) {
    return NULL;
  }
  if (token_cnt == 0) {
    printf("There is no expression.\n");
    return NULL;
  }
  ret->parentheses_buffer = malloc(sizeof(int) * token_cnt);
  if (!check_parentheses_legal(token_buffer, ret->parentheses_buffer)) {
    printf("Expression has illegal parentheses.\n");
    free(ret->parentheses_buffer);
    return NULL;
  }

  ret->tokens = malloc(sizeof(Token) * token_cnt);
  memcpy(ret->tokens, token_buffer, sizeof(Token) * token_cnt);
  init_ST(&(ret->st), token_cnt, ret->tokens);
  eval_error_flag = NULL;
  long long result =
      eval(0, token_cnt - 1, &(ret->st), ret->parentheses_buffer);
  if (eval_error_flag) {
    puts(eval_error_flag);
    clear_ST(&(ret->st));
    free(ret->tokens);
    return NULL;
  }
  if (is_hex)
    printf("It is now 0x%08x\n", (word_t)result);
  else
    printf("It is now %lld\n", result);

  ret->old_value = value;
  ret->is_hex = is_hex;
  return ret;
}
void free_wp(WP *wp) {
  clear_ST(&(wp->st));
  free(wp->tokens);
  free(wp->parentheses_buffer);
  if (head == wp)
    head = wp->next;
  else {
    for (WP *iter = head; iter != NULL; iter = iter->next) {
      if (iter->next == wp) {
        iter->next = wp->next;
        break;
      }
    }
  }
  wp->next = free_;
  free_ = wp;
}

bool exam_watchers(void) {
  bool ret = false;
  for (WP *iter = head; iter != NULL; iter = iter->next) {
    bool success = true;
    long long now_value =
        eval(0, iter->st.n - 1, &(iter->st), iter->parentheses_buffer);
    Assert(success, "Expression evaluation failed while examing watcher #%d",
           iter->NO);
    if (now_value != iter->old_value) {
      printf("Watcher changed : #%d = ", iter->NO);
      show_expr(iter->tokens, iter->st.n);
      if (iter->is_hex)
        printf("\nfrom : 0x%08x\nto   : 0x%08x\n", (word_t)iter->old_value,
               (word_t)now_value);
      else
        printf("\nfrom : %lld\nto   : %lld\n", iter->old_value, now_value);
      iter->old_value = now_value;
      ret = true;
    }
  }
  return ret;
}

void list_watchers(void) {
  int cnt_used = 0;
  if (head != NULL) {
    puts("---------------------------------------------------");
    puts("ID  |               value|expr");
    puts("---------------------------------------------------");
    for (WP *iter = head; iter != NULL; iter = iter->next) {
      ++cnt_used;
      if (iter->is_hex) {
        printf("%4d|          0x%08x|", iter->NO, (word_t)iter->old_value);
        show_expr(iter->tokens, iter->st.n);
        putchar('\n');
      } else {
        printf("%4d|%20lld|", iter->NO, iter->old_value);
        show_expr(iter->tokens, iter->st.n);
        putchar('\n');
      }
    }
    puts("---------------------------------------------------");
  }
  printf("%d active watcher(s), %d free watcher(s).\n", cnt_used,
         NR_WP - cnt_used);
}
