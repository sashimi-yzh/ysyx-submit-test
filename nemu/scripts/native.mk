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

-include $(NEMU_HOME)/../Makefile
include $(NEMU_HOME)/scripts/build.mk

include $(NEMU_HOME)/tools/difftest.mk

compile_git:
	$(call git_commit, "compile NEMU")
$(BINARY):: compile_git
$(BINARY_GDB):: compile_git

# Some convenient rules

override ARGS ?= --log=$(BUILD_DIR)/nemu-log.txt
override ARGS += $(ARGS_DIFF)

override ARGS_GDB ?= --log=$(BUILD_DIR_GDB)/nemu-log.txt
override ARGS_GDB += $(ARGS_DIFF)
# Command to execute NEMU
IMG ?=
NEMU_EXEC := $(BINARY) $(ARGS) $(IMG)
NEMU_EXEC_GDB := $(BINARY_GDB) $(ARGS_GDB) $(IMG)

run-env: $(BINARY) $(DIFF_REF_SO)
run-envgdb: $(BINARY_GDB) $(DIFF_REF_SO)

run: run-env
	$(call git_commit, "run NEMU")
	$(NEMU_EXEC)

gdb: run-envgdb
	$(call git_commit, "gdb NEMU")
	gdb -s $(BINARY_GDB) --args $(NEMU_EXEC_GDB)

hdef: 

count: 
	cloc $(NEMU_HOME) --include-lang="C,C/C++ Header"

clean-tools = $(dir $(shell find ./tools -maxdepth 2 -mindepth 2 -name "Makefile"))
$(clean-tools):
	-@$(MAKE) -s -C $@ clean
clean-tools: $(clean-tools)
clean-all: clean distclean clean-tools

name: 
	echo $(NEMU_EXEC)

.PHONY: run gdb run-env clean-tools clean-all $(clean-tools)