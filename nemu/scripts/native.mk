#***************************************************************************************
# Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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

# Some convenient rules

override ARGS ?= --log=$(BUILD_DIR)/nemu-log.txt
override ARGS += $(ARGS_DIFF)

# override ARGS += -g 10000

# Command to execute NEMU
IMG ?=
NEMU_EXEC := $(BINARY) $(ARGS) $(IMG)

run-env: $(BINARY) $(DIFF_REF_SO)

run: run-env
	$(call git_commit, "run NEMU")
	$(NEMU_EXEC)

gdb: run-env
	$(call git_commit, "gdb NEMU")
	gdb -s $(BINARY) --args $(NEMU_EXEC)

PERF_DIR = $(BUILD_DIR)/profile
PERF_DATA = $(PERF_DIR)/perf.data

perf: run-env
	@mkdir -p $(PERF_DIR)
	perf record -g -F 999 --call-graph dwarf -o $(PERF_DATA) $(BINARY) -b $(ARGS) $(IMG)

perf-report: $(PERF_DATA)
	perf report -i ./build/profile/perf.data --stdio --sort=overhead > ./build/profile/perf_res
	perf report -i $(PERF_DATA)

clean-tools = $(dir $(shell find ./tools -maxdepth 2 -mindepth 2 -name "Makefile"))
$(clean-tools):
	$(MAKE) -s -C $@ clean
clean-tools: $(clean-tools)
clean-all: clean distclean clean-tools

.PHONY: run gdb run-env perf perf-report clean-tools clean-all $(clean-tools)
