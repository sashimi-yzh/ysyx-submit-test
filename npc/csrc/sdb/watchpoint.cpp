#include "common.h"
#include <cstdio>
#include <cstdlib>
#include <string.h>

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  char *expr;
  int val;
} WP;

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

void new_wp(char *exp) {
  // move a wp from free_ to head
  bool success = true;
  int val = expr(exp, &success);
  if (success == false) {
    printf("can not solve the express:%s\n", exp);
    return;
  }
  WP *tmp = free_;
  if (tmp == NULL) {
    printf("the num of breakpoint has reached upper limit\n");
    return;
  }
  WP *head_tmp = head;
  free_ = tmp->next;
  if (head == NULL) {
    head = tmp;
    tmp->next = NULL;
  } else {
    while (head_tmp->next != NULL) {
      if (head_tmp->next->NO > tmp->NO) {
        tmp->next = head_tmp->next;
        head_tmp->next = tmp;
        return;
      }
    }
    head_tmp->next = tmp;
    tmp->next = NULL;
  }
  tmp->expr = (char *)malloc(sizeof(char) * strlen(exp));
  strcpy(tmp->expr, exp);
  tmp->val = val;
  printf("create a watchpoint[%d] expr:%s val:%d\n", tmp->NO, tmp->expr,
         tmp->val);
  return;
}

void free_wp(int wp_num) {
  // move a wp from head to free_
  if (head == NULL) {
    printf("there is not any watchpoint\n");
    return;
  }
  WP *finder = head;
  if (finder->NO == wp_num) {
    free(finder->expr);
    finder->expr = NULL;
    head = finder->next;
    finder->next = free_;
    free_ = finder;
  } else {
    while (finder->next != NULL) {
      if (finder->next->NO == wp_num) {
        WP *tmp = finder->next;
        finder->next = tmp->next;
        tmp->next = free_;
        free_ = tmp;
        free(tmp->expr);
        tmp->expr = NULL;
        return;
      }
      finder = finder->next;
    }
    printf("can not find that watchpoint\n");
  }
  return;
}

void info_wp() {
  if (head == NULL) {
    printf("there is no any watchpoint\n");
    return;
  }
  WP *tmp = head;
  while (tmp != NULL) {
    printf("watchpoint[%d] expr:%s currut val: %d\n", tmp->NO, tmp->expr,
           tmp->val);
    tmp = tmp->next;
  }
  return;
}

bool exe_wp_inner() {
  if (head == NULL) {
    return false;
  }
  WP *tmp = head;
  while (tmp != NULL) {
    bool success = true;
    int res = expr(tmp->expr, &success);
    if (success == false) {
      printf("encounter error when eval watchpoint[%d]: %s\n", tmp->NO,
             tmp->expr);
    } else {
      if (res != tmp->val) {
        printf("hit the watchpoint[%d], val changed from %d to %d\n", tmp->NO,
               tmp->val, res);
        return 1;
        tmp->val = res;
      }
    }
    tmp = tmp->next;
  }
  return false;
}

void exe_wp() {
  bool hit = exe_wp_inner();
  if (hit) {
    set_npc_stop();
  }
}
