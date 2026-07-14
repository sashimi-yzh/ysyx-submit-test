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

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint
{
  int NO;
  struct watchpoint *next;
  

  /* TODO: Add more members if necessary */
  char expr[256];
  word_t last_value;

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool()
{
  int i;
  for (i = 0; i < NR_WP; i++)
  {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

WP *new_wp()
{
  Assert(free_ != NULL, "No free watchpoint available");

  WP *temp = free_;
  free_ = free_->next;
  temp->next = head;
  head = temp;
  return temp;
}

void free_wp(WP *wp)
{
  Assert(wp != NULL, "Cannot free a NULL watchpoint");

  if (head == wp)
  {
    head = head->next;
  }
  else
  {
    WP *prev = head;
    while (prev&&prev->next != wp)
    {
      prev = prev->next;
    }
    Assert(prev != NULL, "Watchpoint not found in the active list");
    prev->next = wp->next;
  }

  wp->next = free_;
  free_ = wp;
}

void delete_wp(int no)
{
  WP *wp = head;
  while (wp != NULL && wp->NO != no)
  {
    wp = wp->next;
  }
  Assert(wp != NULL, "Watchpoint %d not found", no);
  free_wp(wp);
} 

int cmd_w(char *args)
{
  if(args == NULL)
  {
    printf("Usage: w EXPR\n");
    return 0;
  }
  bool success = true;
  word_t result = expr(args, &success);
  if(!success)
  {
    printf("Failed to evaluate expression: %s\n", args);  
  }
  else
  {
    WP *wp = new_wp();
    strcpy(wp->expr, args);
    wp->last_value = result;
    printf("Watchpoint %d set on expression: %s\n", wp->NO, wp->expr);
  }

  return 0;
}

int cmd_d(char *args)
{
  char *wp_no_str = strtok(NULL, " ");
  if(wp_no_str == NULL)
  {
    printf("Usage: d N\n");
    return 0;
  }
  int wp_no = atoi(wp_no_str);

  delete_wp(wp_no);
  printf("Watchpoint %d deleted\n", wp_no);
  return 0;
  
}

void check_watchpoints()
{
  WP *wp = head;
  while (wp != NULL)
  {
    bool success = true;
    word_t current_value = expr(wp->expr, &success);
    if (!success)
    {
      printf("Failed to evaluate watchpoint expression: %s\n", wp->expr);
      wp = wp->next;
      continue;
    }

    if (current_value != wp->last_value)
    {
      printf("Watchpoint %d triggered: %s\n", wp->NO, wp->expr);
      printf("Old value = " FMT_WORD ", New value = " FMT_WORD "\n", wp->last_value, current_value);
      wp->last_value = current_value;
      nemu_state.state= NEMU_STOP;
    }

    wp = wp->next;
  }
}

void wp_display()
{
  WP *wp = head;
  if (wp == NULL)
  {
    printf("No active watchpoints.\n");
    return;
  }

  printf("Active watchpoints:\n");
  printf("NO\tWhat\tLast Value\n");
  while (wp != NULL)
  {
    printf("%d\t%s\t" FMT_WORD "\n", wp->NO, wp->expr, wp->last_value);
    wp = wp->next;
  }
}