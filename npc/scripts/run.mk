include $(NPC_DIR)/scripts/host-build.mk
include $(NPC_DIR)/tools/difftest.mk
-include $(NPC_DIR)/../Makefile

RUN_ARGS := $(or $(strip $(ARGS)),--log=$(MODE_ARTIFACT)/npc-log.txt) $(ARGS_DIFF)
IMG ?=
EXEC_LINE := $(NPC_BIN) $(RUN_ARGS) $(IMG)

run-env: $(NPC_BIN) $(DIFF_REF_SO)

run: run-env
	@printf '[npc][run] mode=%s binary=%s\n' '$(SIM_MODE)' '$(NPC_BIN)'
	@printf '[npc][run] image=%s\n' '$(if $(strip $(IMG)),$(abspath $(IMG)),<none>)'
	@printf '[npc][run] args=%s\n' '$(strip $(RUN_ARGS))'
	$(EXEC_LINE)

sim: run
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

gdb: run-env
	gdb -s $(NPC_BIN) --args $(EXEC_LINE)

verilog: $(RTL_OUT)
	@printf '[npc][verilog] ready output=%s units=%s bytes=%s\n' '$(RTL_OUT)' '$(words $(RTL_CORE))' "$$(wc -c < '$(RTL_OUT)')"

TOOL_CLEAN_DIRS := $(sort $(dir $(shell find $(NPC_DIR)/tools -maxdepth 2 -mindepth 2 -name Makefile)))
$(TOOL_CLEAN_DIRS):
	-@$(MAKE) -s -C $@ clean

clean-tools: $(TOOL_CLEAN_DIRS)
clean-all: clean distclean clean-tools

.PHONY: run run-env sim gdb verilog clean-tools clean-all $(TOOL_CLEAN_DIRS)
