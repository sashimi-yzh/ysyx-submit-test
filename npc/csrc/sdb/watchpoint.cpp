/***************************************************************************************
* NPC Simple Debugger (sdb)
* 监视点管理模块
***************************************************************************************/

#include "sdb.h"
#include <cassert>

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  char expr[256];
  word_t old_value;
  bool enabled;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

static WP* new_wp() {
  if (free_ == NULL) {
    printf("Error: No free watchpoint available!\n");
    assert(0);
  }
  
  WP *wp = free_;
  free_ = free_->next;
  
  wp->next = head;
  head = wp;
  
  return wp;
}

static void free_wp(WP *wp) {
  if (head == wp) {
    head = head->next;
  } else {
    WP *prev = head;
    while (prev != NULL && prev->next != wp) {
      prev = prev->next;
    }
    
    if (prev == NULL) {
      printf("Error: Watchpoint not found in list!\n");
      return;
    }
    
    prev->next = wp->next;
  }
  
  wp->enabled = false;
  wp->expr[0] = '\0';
  wp->old_value = 0;
  
  wp->next = free_;
  free_ = wp;
}

WP* create_watchpoint(char *expr_str) {
  bool success = false;
  word_t value = expr(expr_str, &success);
  
  if (!success) {
    printf("Error: Invalid expression\n");
    return NULL;
  }
  
  WP *wp = new_wp();
  strncpy(wp->expr, expr_str, sizeof(wp->expr) - 1);
  wp->expr[sizeof(wp->expr) - 1] = '\0';
  wp->old_value = value;
  wp->enabled = true;
  
  printf("Watchpoint %d: %s\n", wp->NO, wp->expr);
  
  return wp;
}

bool delete_watchpoint(int no) {
  for (WP *wp = head; wp != NULL; wp = wp->next) {
    if (wp->NO == no) {
      free_wp(wp);
      return true;
    }
  }
  
  return false;
}

void display_watchpoints() {
  if (head == NULL) {
    printf("No watchpoints.\n");
    return;
  }
  
  printf("Num     Enabled  Expression                       Value\n");
  printf("-----------------------------------------------------------\n");
  
  for (WP *wp = head; wp != NULL; wp = wp->next) {
    printf("%-7d %-8s %-32s 0x%08x\n",
           wp->NO,
           wp->enabled ? "y" : "n",
           wp->expr,
           wp->old_value);
  }
}

bool check_watchpoints() {
  bool triggered = false;
  
  if (head == NULL) {
    return false;
  }
  
  for (WP *wp = head; wp != NULL; wp = wp->next) {
    if (!wp->enabled) {
      continue;
    }
    
    bool success = false;
    word_t new_value = expr(wp->expr, &success);
    
    if (!success) {
      printf("Error: Failed to evaluate watchpoint %d: %s\n", 
             wp->NO, wp->expr);
      continue;
    }
    
    if (new_value != wp->old_value) {
      printf("\n");
      printf("Watchpoint %d: %s\n", wp->NO, wp->expr);
      printf("Old value = 0x%08x\n", wp->old_value);
      printf("New value = 0x%08x\n", new_value);
      printf("\n");
      
      wp->old_value = new_value;
      triggered = true;
    }
  }
  
  return triggered;
}
