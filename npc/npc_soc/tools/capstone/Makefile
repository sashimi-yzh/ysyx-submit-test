#***************************************************************************************
# Copyright (c) 2014-2024 Zihao Yu, Nanjing University
#
# NEMU is licensed under Mulan PSL v2.
# You can use this software according to the terms and conditions of the Mulan PSL v2.
# You may obtain a copy of Mulan PSL v2 at:
#          http://license.coscl.org.cn/MulanPSL2
#
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
# EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
# MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
#
# See the Mulan PSL v2 for more details.
#**************************************************************************************/

REPO_PATH = repo
ifeq ($(wildcard repo/include/capstone/capstone.h),)
  $(shell git clone https://github.com/capstone-engine/capstone.git $(REPO_PATH))
endif

CAPSTONE = libcapstone.so.6
$(CAPSTONE):
	cd $(REPO_PATH) && CAPSTONE_ARCHS="riscv" bash make.sh

clean:
	$(MAKE) -C $(REPO_PATH) clean

all: $(CAPSTONE)
.DEFAULT_GOAL = all

.PHONY: all clean
