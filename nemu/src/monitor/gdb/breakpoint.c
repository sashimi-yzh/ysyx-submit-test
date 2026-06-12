#include "breakpoint.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define NR_BP 32

static BP bp_pool[NR_BP] = {};
static BP *head = NULL, *free_ = NULL;

void init_bp_pool(void) {
  int i;
  for (i = 0; i < NR_BP; i ++) {
    bp_pool[i].NO = i;
    bp_pool[i].next = (i == NR_BP - 1 ? NULL : &bp_pool[i + 1]);
  }

  head = NULL;
  free_ = bp_pool;
}

static BP *prev_bp(BP *bp, BP *bp_head) {
  BP *p = bp_head;
  for (; p; p = p->next) {
    if (p->next == bp)
      return p;
  }
  return NULL;
}

static void delete_bp(BP *bp, BP **bp_head){
  if (bp == *bp_head) {
    *bp_head = bp->next;
  } else {
    BP *prev = prev_bp(bp, *bp_head);
    Assert(prev, "can't find prev");
    prev->next = bp->next;
  }
  bp->next = NULL;
}

static void insert_bp(BP *bp, BP **bp_head) {
  bp->next = *bp_head;
  *bp_head = bp;
}

bool new_bp(word_t addr) {
  BP *p;
  for (p = head; p; p = p->next) {
    if (addr == p->addr) {
      return true;
    }
  }
  if (free_ == NULL) {
    return false;
  }
  BP *bp = free_;
  bp->addr = addr;
  delete_bp(bp, &free_);
  insert_bp(bp, &head);
  return true;
}

void free_bp(word_t addr) {
  BP *p;
  for (p = head; p; p = p->next) {
    if (addr == p->addr) {
      delete_bp(p, &head);
      insert_bp(p, &free_);
      return;
    }
  }
}

int find_bp(word_t addr) {
  BP *p;
  for (p = head; p; p = p->next) {
    if (addr == p->addr) {
      return p->NO;
    }
  }
  return -1;
}
