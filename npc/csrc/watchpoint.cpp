#include "watchpoint.h"
#include "expr.h"
#include "stdio.h"
#include "string.h"

#define NR_WP 32

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].used = false;
  }

  head = NULL;
  free_ = wp_pool;
}

WP *new_wp() {
  if (free_ == NULL) {
    ASSERT_IN_RUNTIME(0, "There are no free watchpoints");
  }

  WP *result = free_;
  free_ = free_->next;
  result->next = NULL;
  result->used = true;
  if (head == NULL) {
    head = result;
  } else {
    WP *tmp = head;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }

    tmp->next = result;
  }

  return result;
}

void free_wp(uint64_t order) {
  if (order >= NR_WP) {
    printf("Can not free wp %ld\n", order);
  }
  WP *wp = &wp_pool[order];
  if (!wp->used) {
    printf("The watchpoint needn't to free\n");
    return;
  }
  wp->used = false;
  if (wp == head) {
    head = head->next;
  } else {
    for (WP *pre = head, *tmp = head->next; tmp != NULL;
         pre = pre->next, tmp = tmp->next) {
      if (tmp == wp) {
        pre->next = tmp->next;
        break;
      }
    }
  }
  if (free_ == NULL) {
    free_ = wp;
  } else {
    WP *tmp = free_;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = wp;
  }
  wp->next = NULL;
}

bool check_wp() {
  if (head == NULL) {
    return false;
  }
  bool change = false;
  for (WP *wp = head; wp != NULL; wp = wp->next) {
    bool success = true;
    word_t result = expr(wp->expr, &success);
    ASSERT_IN_RUNTIME(success, "eval failed when checking wp");
    if (result != wp->val) {
      change = true;
      printf("{%s} old value = " FMT_WORD_D ", new value = " FMT_WORD_D "\n",
             wp->expr, wp->val, result);
      printf("watch point has been triggered\n");
      wp->val = result;
    }
  }
  return change;
}

void print_wp() {
  for (WP *wp = head; wp != NULL; wp = wp->next) {
    printf("watchpoint's index:\t%d\n", wp->NO);
    printf("watchpoint's expr:\t%s\n", wp->expr);
    printf("watchpoint's current value:\t" FMT_WORD_D "\n", wp->val);
  }
}