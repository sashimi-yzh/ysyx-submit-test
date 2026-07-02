include $(NPC_HOME)/scripts/build.mk

include $(NPC_HOME)/tools/difftest.mk

-include $(NPC_HOME)/../Makefile

override ARGS ?= --log=$(BUILD_DIR)/npc-log.txt
override ARGS += $(ARGS_DIFF)
IMG ?=
NPC_EXEC := $(BINARY) $(ARGS) $(IMG)

run-env: $(BINARY) $(DIFF_REF_SO)

run: run-env
	$(NPC_EXEC)

sim: run
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

gdb: run-env
	gdb -s $(BINARY) --args $(NPC_EXEC)

verilog: $(CPU_VERILOG)

clean-tools = $(dir $(shell find $(NPC_HOME)/tools -maxdepth 2 -mindepth 2 -name "Makefile"))
$(clean-tools):
	-@$(MAKE) -s -C $@ clean
clean-tools: $(clean-tools)
clean-all: clean distclean clean-tools

.PHONY: run sim gdb run-env verilog clean-tools clean-all $(clean-tools)
