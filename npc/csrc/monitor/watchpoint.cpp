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

#include "../../include/common.h"

typedef struct watchpoint {
  int NO;
  char args[1100];
  struct watchpoint *next;

  /* TODO: Add more members if necessary */

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

WP* new_wp() {
  Assert(free_, "监视点已经用完了");
  WP *p = free_;
  free_ = free_->next;
  p->next = NULL;
  return p;
}

void free_wp(WP *wp) {
  WP *p = free_;
  WP *p_pre = NULL;
  while (p)
  {
    if(p->NO == NR_WP-1) break;
    p = p->next;
    /* code */
  }
  if(p) {
    p_pre = p;
    p = p->next;
  }
  else
  {
    p_pre = NULL;
    p = free_;
  }
  while (p)
  {
    if(p->NO > wp->NO)
    {
      wp->next = p_pre->next;
      p_pre->next = wp;
      break;
    }
    p_pre = p;
    p = p->next;      
  }
  if(!p) {
    p_pre->next = wp;
  }
}

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    memset(wp_pool[i].args, 0, sizeof(wp_pool[i].args));
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

void add_watchpoint(char *args) {
  WP *p = new_wp();
  
  strcpy(p->args, args);
  if(!head) {
    head = p;
    return;
  }
  WP *temp = head;
  while (temp->next)
  {
    temp = temp->next;
  }
  temp->next = p;
}

void watchpoint_display() {
  WP *p = head;
  printf("序号\t表达式\t指针\n");
  while (p)
  {
    printf("%d\t%s\t%p\n", p->NO, p->args, p);
    p = p->next;
  }
  WP *n = free_;
  printf("序号\t指针\n");
  while (n)
  {
    printf("%d\t%p\n", n->NO, n);
    n = n->next;
  }
}

void delete_watchpoint(int number) {
  WP *p = head;
  WP *p_pre = NULL;
  while (p)
  {
    if(p->NO == number)
    {
      if(p_pre) 
      {
        p_pre->next = p->next;
      }
      else 
      {
        head = p->next;
      }
      p->next = NULL;
      break;
    }
    p_pre = p;
    p = p->next;
  }
  free_wp(p);
}

void scan_watchpoint() {
  static uint32_t data_pre[NR_WP] = {0};
  static uint32_t data_new[NR_WP] = {0};
  int index[NR_WP] = {0};
  if(!head) return;
  WP *p = head;
  bool success = true;
  while (p)
  {
    *(index + p->NO) = 1;
    *(data_new + (p->NO)) = expr(p->args, &success);
    Assert(success, "表达式计算失败");
    p = p->next;
  }
  for (int i = 0; i < NR_WP; i++)
  {
    if(index[i])
    {
      if(data_new[i] != data_pre[i])
      {
        printf("监视点%d发生了变化\n", i);
        data_pre[i] = data_new[i];
        npcstate.state = NPC_STOP;
        break;
      }
    }
  }
}

/* TODO: Implement the functionality of watchpoint */
