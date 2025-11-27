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

#include "utils.h"
#include "sdb.h"
#include <assert.h>
#include "debug.h"

#define NR_WP 32

typedef struct watchpoint 
{
  int NO;
  uint32_t value;
  char* what;
  struct watchpoint *next;

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() 
{
  int i;
  for (i = 0; i < NR_WP; i ++) 
  {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].value = 0;
    wp_pool[i].what = NULL;
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

// new watch point
bool new_wp(const char* what, uint32_t value)
{
  if (free_ == NULL) 
    return false;

  WP* ret = free_;
  free_ = free_->next;
  ret->next = NULL;

  if (head == NULL)
    head = ret;
  else
  {
    ret->next = head;
    head = ret;
  }  

  ret->what = strdup(what);
  ret->value = value;
  return true;
}


// free watch point
void free_wp(int num)
{
  if (num < 0 || num >= NR_WP) return;

  WP* wp = &wp_pool[num];

  if (wp->what == NULL || head == NULL) return;
  
  WP* tmp = head;
  WP* font = NULL;
  while (tmp != NULL)
  {
    if (tmp == wp)
    {
      if (font == NULL)
        head = tmp->next;
      else
        font->next = tmp->next;
      break;
    }

    font = tmp;
    tmp = tmp->next;
  }

  if (wp->what != NULL)
    DFREE((void*)wp->what);
  wp->what = NULL;

  wp->next = free_;
  free_ = wp;
}


// check and update watch point
void check_wp()
{
  word_t expr(char *e, bool *success);

  WP* tmp = head;
  while (tmp != NULL)
  {
    bool success = false;
    word_t ret = expr(tmp->what, &success);
    assert(success);

    if (ret != tmp->value)
    {
      printf("wp: %d  what: [%s]  ago: %08x  now: %08x\n", tmp->NO, tmp->what, tmp->value, ret);
      tmp->value = ret; // update
      nemu_state.state = NEMU_STOP;
    }

    tmp = tmp->next;
  }
}


void print_wp()
{
  WP* tmp = head;
  while (tmp != NULL)
  {
    printf("wp: %d  what: [%s]  now: %u\n", tmp->NO, tmp->what, tmp->value);
    tmp = tmp->next;
  }
}