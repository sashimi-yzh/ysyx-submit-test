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

#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  word_t oldValue;
  char express[1 << 10];
} WP;
word_t expr(char *e, bool *success);
void checkWatchPoint();
void infoWatchPoint();
void free_wpByNO(int NO, bool *success);
WP *new_wp();

extern bool debug_eval; 
#endif
