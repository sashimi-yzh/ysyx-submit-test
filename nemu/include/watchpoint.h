#ifndef __WATCHPOINT_H__
#define __WATCHPOINT_H__


#include<stdint.h>

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  char expr[256];
  uint32_t value;

} WP;

extern WP *head;


#endif