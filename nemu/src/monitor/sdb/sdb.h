/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>

word_t expr(char *e, bool *success);
void info_wp();

void new_wp(char *exp);
void free_wp(int wp_num);

int check_wp_hit();

int snap_load(const char *filename);
int snap_store(const char *filename);

typedef enum { INVALID, AUTOMATIC, PROBE_ONLY, DBG_QUIT } dbg_mode_t;

bool dbg_is_on();
void set_dbg_port(int port);
int get_dbg_mode();
void set_dbg_mode(dbg_mode_t mode);
bool dbg_init_and_wait_connection(void);
bool dbg_process_one_command(char *cmd_line, char *replay, size_t replay_size);
void dbg_listen(void);
void dbg_mark_ready_pending(void);

int add_memguard(vaddr_t addr);
void info_memguard();
void del_memguard(int idx);
#endif
