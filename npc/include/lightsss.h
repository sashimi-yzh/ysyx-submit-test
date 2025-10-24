/***************************************************************************************
* Copyright (c) 2020-2023 Institute of Computing Technology, Chinese Academy of Sciences
* Copyright (c) 2020-2021 Peng Cheng Laboratory
*
* DiffTest is licensed under Mulan PSL v2.
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

#ifndef __LIGHTSSS_H
#define __LIGHTSSS_H

#include "common.h"
#include <deque>
#include <list>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/prctl.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>


#define SLOT_SIZE 3
#define FAIT_EXIT    exit(EXIT_FAILURE);
#define WAIT_INTERVAL 5

typedef struct shinfo {
  bool flag;
  bool notgood;
  bool is_p_dead;
  uint64_t endCycles;
  pid_t oldest;
} shinfo;

class ForkShareMemory {
private:
  key_t key_n;
  int shm_id;

public:
  shinfo *info;

  ForkShareMemory();
  ~ForkShareMemory();

  void shwait();
};

const int FORK_OK = 0;
const int FORK_ERROR = 1;
const int FORK_CHILD = 2;

class LightSSS {
  pid_t pid = -1;
  static pid_t p_pid;
  int slotCnt = 0;
  int waitProcess = 0;
  // front() is the newest. back() is the oldest.
  static std::deque<pid_t> pidSlot;
  static ForkShareMemory forkshm;

public:
  LightSSS() {
    p_pid = getpid();
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGABRT, signal_handler_abort);
  }
  ~LightSSS() {}
  int do_fork();
  int wakeup_child(uint64_t cycles);
  bool is_child();
  int do_clear();
  static void signal_handler(int signum);
  static void signal_handler_abort(int signum);
  uint64_t get_end_cycles() {
    return forkshm.info->endCycles;
  }
  bool get_flag() {
    return forkshm.info->flag;
  }
  bool get_notgood() {
    return forkshm.info->notgood;
  }
  pid_t git_p_pid() {
    return p_pid;
  }
};



#define FORK_PRINTF(format, args...)                       \
  do {                                                     \
    printf("[FORK_INFO pid(%d)] ", getpid()); \
    fflush(stdout);                                        \
  } while (0);

#endif