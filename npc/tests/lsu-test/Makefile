TOPNAME = ysyx_25040129_LSU
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

ROOT_DIR = ~/ysyx-workbench/npc
THIS_DIR := ~/ysyx-workbench/npc/tests/lsu-test
BUILD_DIR =${THIS_DIR}/build
OBJ_DIR = $(THIS_DIR)/build/obj_dir
BIN = $(OBJ_DIR)/V$(TOPNAME)

override ARGS ?= 
override ARGS += --log=$(BUILD_DIR)/npc-log.txt
override ARGS_FTRACE ?= --elf=$(IMG:.bin=.elf)
override ARGS += $(ARGS_FTRACE)
override ARGS += $(ARGS_DIFF)

# Command to execute NEMU
IMG ?=
BIN := $(BIN) $(ARGS) $(IMG)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# project source
VSRCS = $(ROOT_DIR)/vsrc/xconfig.v $(ROOT_DIR)/vsrc/ysyx_25040129_LSU.v --top-module $(TOPNAME)
CSRCS = $(THIS_DIR)/main.cpp

run:
	verilator --cc --exe --build -j  0 -O3 -Wall -Wwarn-LATCH --trace --Mdir build/obj_dir $(VSRCS) $(CSRCS)  --LDFLAGS "-lreadline" --CFLAGS "-I ~/ysyx-workbench/nemu/tools/capstone/repo/include"
		${BIN}

clean:
	rm -rf $(BUILD_DIR)
