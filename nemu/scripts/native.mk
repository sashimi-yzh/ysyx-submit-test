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

include $(NEMU_HOME)/tools/difftest.mk
include $(NEMU_HOME)/tools/lib.mk
ARCHIVES += $(STATIC_LIBS)
INC_PATH += $(STATIC_INC)

include $(NEMU_HOME)/scripts/build.mk

# Some convenient rules

override ARGS ?= --log=$(BUILD_DIR)/nemu-log.txt
override ARGS += $(ARGS_DIFF)
GDB_SOCKET = $(BUILD_DIR)/gdb-socket
override ARGS += --gdb-socket=$(GDB_SOCKET)
override ARGS += $(ADD_ARGS)
ifeq ($(CONFIG_TAKE_RUN_AS_RUNBATCH),y)
override ARGS += -b
endif

$(info NEMU BUILD_DIR $(BUILD_DIR))

# Command to execute NEMU
IMG ?=
# NEMU_EXEC := numactl -m 0 -C 0,2,4,6 -- $(BINARY) $(ARGS) $(IMG)
_NEMU_EXEC_RAW = $(BINARY) $(ARGS) $(IMG)
_NEMU_EXEC = set -o pipefail; \
						 (stdbuf -oL $(_NEMU_EXEC_RAW) 2>&1 | \
						 tee $(BUILD_DIR)/std-output$(if $(TASK_NAME),-$(TASK_NAME),).txt; \
						 exit $$?)
ifeq ($(CONFIG_DEBUGER_GDB),y)
$(info GDB_SOCKET $(GDB_SOCKET))
ifneq ($(GDB_ELF),)
GDB_FLAGS += -ex "file $(GDB_ELF)"
endif
# CROSS_GDB = riscv64-unknown-linux-gnu-gdb
CROSS_GDB = riscv64-unknown-elf-gdb
GDB_FLAGS += -ex "set can-use-hw-watchpoints 0" \
						 -ex "source $(NEMU_HOME)/tools/gdb-scripts/smart-connect.py" \
						 -ex "smart-connect $(GDB_SOCKET)"
						 # -ex "target remote $(GDB_SOCKET)"
GDB_FLAGS += $(AM_GDB_FLAGS)
NEMU_EXEC = $(_NEMU_EXEC) & \
		NEMU_PID=$$!; \
    $(CROSS_GDB) $(GDB_FLAGS); \
    wait $$NEMU_PID; \
    NEMU_RET=$$?; \
    exit $$NEMU_RET
else
NEMU_EXEC = $(_NEMU_EXEC)
endif

run-env: $(BINARY) $(DIFF_REF_SO)

run: SHELL := /bin/bash
run: run-env
	-@mkdir -p $(BUILD_DIR)/profile/
	$(call git_commit, "run NEMU")
	$(NEMU_EXEC)

gdb: SHELL := /bin/bash
gdb: run-env
	-@mkdir -p $(BUILD_DIR)/profile/
	$(call git_commit, "gdb NEMU")
	gdb -s $(BINARY) --args $(_NEMU_EXEC_RAW)

clean-tools = $(dir $(shell find ./tools -maxdepth 2 -mindepth 2 -name "Makefile"))
$(clean-tools):
	-@$(MAKE) -s -C $@ clean
clean-tools: $(clean-tools)
clean-all: clean distclean clean-tools

.PHONY: run gdb run-env clean-tools clean-all $(clean-tools)
