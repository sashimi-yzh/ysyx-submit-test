#***************************************************************************************
# Copyright (c) 2014-2022 Zihao Yu, Nanjing University
#
# NPC is licensed under Mulan PSL v2.
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

-include $(NPC_HOME)/../Makefile
include $(NPC_HOME)/scripts/build.mk

include $(NPC_HOME)/tools/difftest.mk

compile_git:
	$(call git_commit, "compile NPC")

# Some convenient rules

override ARGS ?= --log=$(BUILD_DIR)/npc-log.txt \
                 --log_m=$(BUILD_DIR)/npc-log-mem.txt \
                 --log_f=$(BUILD_DIR)/npc-log-func.txt
override ARGS += $(ARGS_DIFF)

# Command to execute NPC
IMG ?=
# MEM_FILE ?= $(BUILD_DIR)/mem_iverilog.txt
ifneq ($(or $(CONFIG_NPC_IVERILOG),$(CONFIG_NPC_IVERILOG_NET)),)
NPC_EXEC := vvp $(BINARY) +mem="$(IVER_ARGS)"
else
NPC_EXEC := $(BINARY) $(ARGS) $(IMG)
endif

run-env: $(BINARY) $(DIFF_REF_SO) compile_git

run: run-env
	$(call git_commit, "run NPC")
	echo "running $(NPC_EXEC)"
	$(NPC_EXEC)

gdb: run-env
	$(call git_commit, "gdb NPC")
	cgdb -s $(BINARY) --args $(NPC_EXEC)

clean-tools = $(dir $(shell find ./tools -maxdepth 2 -mindepth 2 -name "Makefile"))
$(clean-tools):
	-@$(MAKE) -s -C $@ clean
clean-tools: $(clean-tools)
clean-all: clean distclean clean-tools

.PHONY: run gdb run-env clean-tools clean-all $(clean-tools) __compile_git
