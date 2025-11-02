/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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

//function of expr
word_t expr(char *e, bool *success, bool *null);

//function of watchpoint
typedef struct watchpoint {
  int NO;
  char expression[64];
  word_t result;
  struct watchpoint *next;
  /* TODO: Add more members if necessary */

} WP;

WP* new_wp(void);
void free_wp(int no);
int check_usage(int wp_used[32], char expression_stored[32][32],\
				word_t result[32]);

#endif
