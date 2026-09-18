#include <npc.h>
#include <common.h>
#include <sdb.h>

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  char str[32];
  uint32_t last_result;
  struct watchpoint *next;

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void empty(WP* wp) {
  wp->str[0] = '\0';
  wp->last_result = 0;
}

WP* new_wp(char* s) {
  WP* wp;

  //delete wp in free_
  wp = free_;
  free_ = free_->next;
  
  //add to head
  for (WP* q = head; q; q = q->next) {
    if (q->next == NULL) {
      q->next = wp;
      strcpy(wp->str, s);
      wp->next = NULL;
      return wp;
    }
  }

  //head is NULL
  head = wp;
  strcpy(wp->str, s);
  wp->next = NULL;
  return wp;
}

int free_wp(WP *wp) {
  //delete wp in head
  if (head == wp) {
    head = head->next;
    printf("check: d wp at head\n");
    empty(wp);
  } else {
    for (WP* q = head; q; q = q->next) {
      if (wp->NO == q->next->NO) {
        q->next = wp->next;
        empty(wp);
        printf("check: d wp at middle\n");
        break;
      }
    }
  }

  //wp in the free_
  for (WP* p = free_; p; p = p->next) {

    //wp is the biggest
    if (p->next == NULL && p->NO < wp->NO) { 
      p->next = wp;
      printf("check: free wp at last\n");
      return 0;
    }

   //wp is the middle
    else if (p->NO <  wp->NO && wp->NO < p->next->NO) {
      wp->next = p->next;
      p->next = wp;
      printf("check: free wp at middle\n");
      return 0;
    }
  }

  //wp is the frist one or free_ is NULL
  wp->next = free_;
  free_ = wp;
  //printf("check: free wp at frist -free: %d next: %d\n", free_->NO, free_->next->NO);
  return 0;
}

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].str[0] = '\0';
    wp_pool[i].last_result = 0;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

WP* wp_head() {
  return head;
}

void check_watchpoints() {
  for (WP* q = wp_head(); q; q = q->next) {
    bool success;
    uint32_t new_result = expr(q->str, &success);

    if (!success) printf("Error: evaluation of failure\n");
    if (new_result != q->last_result) {
      printf("watchpoint[%d] is triggered\n", q->NO);
      printf("The old data: 0x%08X\n", q->last_result);
      printf("The new data: 0x%08X\n", new_result);

      q->last_result = new_result;
      if (npc_state.state != NPC_END) npc_state.state = NPC_STOP;
    }
  }

}

int c_print() {
  bool success;
  if (head) {
    for (WP* q = head; q; q = q->next) {
      printf("Num: %d  What: %s   0x%08X\n", q->NO, q->str, expr(q->str, &success));
      assert(success);
    }
  } else printf("You should set a watchpoint frist.\n");
  return 0;
}

int c_w(char *args) {
  if (args == NULL) return 0;
  WP* p = new_wp(args);

  printf("Set a watchpoint[%d]: %s\n", p->NO, p->str);
  return 0;
}

int c_d(char *args) {
  int i = atoi(args);
  for (WP* q = wp_head(); q; q = q->next) {
    if (q->NO == i) {
      printf("Delete a watchpoint[%d]: %s\n", i, q->str);
      assert(free_wp(q) == 0);
      return 0;
    }
  }
  printf("Error: can not find this watchpoint\n");
  return 0;
}
