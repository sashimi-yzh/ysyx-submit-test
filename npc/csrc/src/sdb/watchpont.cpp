#include "common.h"
#include "sdb.h"

#include <cstring>

#define NR_WP 32

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;
static int wp_no = 0;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

WP *new_wp(char *str, word_t val) {
  if (free_ == NULL) return NULL;
  WP *p = free_;
  free_ = p->next;

  p->NO = ++wp_no;
  p->next = head;
  p->val = val;

  p->expr = new char[strlen(str) + 1];
  strcpy(p->expr, str);

  head = p;
  return p;
}

void free_wp(int no) {
  WP *p = NULL, *i;
  if (head->NO == no) {
    p = head;
    head = p->next;
    goto found;
  }
  for (i = head; i->next; i = i->next) {
    if (i->next->NO == no) {
      p = i->next;
      i->next = p->next;
      goto found;
    }
  }
  if (i->NO == no) p = i;
  else return;
  found:
  delete[] p->expr;
  p->next = free_;
  free_ = p;
}

void print_wp(WP *p) {
  printf(
    MUXDEF(RV64, "%-3s %-18s %s\n", "%-3s %-10s %s\n"),
    "No", "Value", "Expr"
  );
  printf(
    MUXDEF(RV64, "%-3d 0x%-16llx %s\n", "%-3d 0x%-8x %s\n"),
    p->NO, p->val, p->expr
  );
}

void wps_display() {
  if (head == NULL) {
    printf("No watchpoints\n");
    return;
  }
  printf(
    MUXDEF(RV64, "%-3s %-18s %s\n", "%-3s %-10s %s\n"),
    "No", "Value", "Expr"
  );
  for (WP *p = head; p; p = p->next) {
    printf(
      MUXDEF(RV64, "%-3d 0x%-16llx %s\n", "%-3d 0x%-8x %s\n"),
      p->NO, p->val, p->expr
    );
  }
}

bool check_wps() {
  bool success = true, stop = false;
  for (WP *p = head; p; p = p->next) {
    word_t val = expr(p->expr, &success);
    Assert(success, "Expr become invalid: %s", p->expr);
    if (p->val != val) {
      stop = true;
      printf("Watchpoint No.%d triggered: %s\n  value: ", p->NO, p->expr);
      printf(
        MUXDEF(RV64, "0x%-16llx -> 0x%-16llx\n", "0x%-8x -> 0x%-8x\n"),
        p->val, val
      );
      p->val = val;
    }
  }
  if (stop) printf("Stopped\n");
  return stop;
}
