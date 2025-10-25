#include "npc.h"
#include "tpdef.h"

#include <cstddef>
#include <stdio.h>
#include <string.h>

#define WP_SIZE 32

typedef struct watchpoint 
{
  int NO;
  uint32_t value;
  char* what;
  struct watchpoint *next;

} WP;

static WP wp_pool[WP_SIZE] = {};
static WP *head = NULL, *free_ = NULL;


// initialize watch point pool
void init_wp_pool()
{
  int i;
  for (i = 0; i < WP_SIZE; i ++) 
  {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == WP_SIZE - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].value = 0;
    wp_pool[i].what = NULL;
  }

  head = NULL;
  free_ = wp_pool;
}


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
  if (num < 0 || num >= WP_SIZE) return;

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
    if (!success) 
    {
      printf(ANSI_FMT("check wp: Unexpectedly error\n", ANSI_BG_RED));
      finalize(0);
    }

    if (ret != tmp->value)
    {
      printf("wp: %d  what: [%s]  ago: 0x%08x  now: 0x%08x\n", tmp->NO, tmp->what, tmp->value, ret);
      tmp->value = ret; // update
      npc_stat = NPC_STOP;
    }

    tmp = tmp->next;
  }
}


// print watch point
void print_wp()
{
  WP* tmp = head;
  while (tmp != NULL)
  {
    printf("wp: %d  what: [%s]  now: %u\n", tmp->NO, tmp->what, tmp->value);
    tmp = tmp->next;
  }
}


void free_wp_pool()
{
  for (int i = 0; i < WP_SIZE; i++)
  {
    if (wp_pool[i].what != NULL)
    {
      DFREE(wp_pool[i].what);
      wp_pool[i].what = NULL;
    }
  }
}