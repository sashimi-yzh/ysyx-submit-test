#include "sdb.h"

#define NR_WP 32
#define WP_EXPR_SIZE 128

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  char expr[WP_EXPR_SIZE];
  word_t old_val;
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

int new_wp(char *e) {
  bool success;
  word_t val = expr(e, &success);
  if (!success) {
    return -1;
  }

  if (free_ == NULL) {
    panic("No more watchpoints available");
  }

  WP *wp = free_;
  free_ = free_->next;

  wp->next = head;
  head = wp;

  assert(strlen(e) < WP_EXPR_SIZE);
  strcpy(wp->expr, e);
  wp->old_val = val;
  return wp->NO;
}

bool free_wp(int NO) {
  WP *prev = NULL;
  WP *wp = head;
  while (wp != NULL) {
    if (wp->NO == NO) {
      if (prev == NULL) {
        head = wp->next;
      } else {
        prev->next = wp->next;
      }
      wp->next = free_;
      free_ = wp;
      return true;
    }
    prev = wp;
    wp = wp->next;
  }
  return false;
}

void wp_display() {
  if (head == NULL) {
    printf("No watchpoints.\n");
    return;
  }
  
  printf("%-8s %-16s %s\n", "Num", "Value", "Expression");
  WP *wp = head;
  while (wp != NULL) {
    printf("%-8d " FMT_WORD "       %s\n", wp->NO, wp->old_val, wp->expr);
    wp = wp->next;
  }
}

bool wp_check() {
  bool trigger = false;
  WP *wp = head;
  while (wp != NULL) {
    bool success;
    word_t new_val = expr(wp->expr, &success);
    if (success) {
      if (new_val != wp->old_val) {
        printf("Watchpoint %d: %s\n", wp->NO, wp->expr);
        printf("Old value = [HEX] " FMT_WORD "\t[DEC] %u\n", wp->old_val, wp->old_val);
        printf("New value = [HEX] " FMT_WORD "\t[DEC] %u\n", new_val, new_val);
        wp->old_val = new_val;
        trigger = true;
      }
    } else {
      printf("Error evaluating watchpoint %d: %s\n", wp->NO, wp->expr);
    }
    wp = wp->next;
  }
  return trigger;
}
