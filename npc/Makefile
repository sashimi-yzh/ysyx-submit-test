PLATFORM ?= npc
ifeq ($(PLATFORM),ysyxsoc)
	TOP_NAME = ysyxSoCFull
else 
	TOP_NAME = ysyx_25020042
endif
# IMG ?= $(YSYX_HOME)/npc/demo/tests/char-test.bin
IMG ?= 
ELF ?= $(IMG:.bin=.elf)
NEMU_SO := $(NEMU_HOME)/build/riscv32-nemu-interpreter-so

WORK_DIR = $(shell pwd)
BUILD_DIR = $(WORK_DIR)/build
TEST ?=
TEST_OBJ = $(shell find $(VPATH) -name $(TEST).v)
VPATH = $(WORK_DIR)/vsrc
CPATH = $(WORK_DIR)/csrc
SOC_HOME = $(YSYX_HOME)/ysyxSoC
INC_PATH := $(WORK_DIR)/include 


VSRCS := $(shell find $(VPATH) -name *.v)
ALL_CSRCS := $(wildcard $(CPATH)/*.cpp)
ALL_CSRCS += $(shell find $(CPATH) -name *.c)

EXCLUDE_DIR := $(CPATH)/device

ifeq ($(PLATFORM),ysyxsoc)
include $(NVBOARD_HOME)/scripts/nvboard.mk

NXDC_FILES ?= $(WORK_DIR)/constr/ysyxSoCFull.nxdc
# auto_bind.cpp
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@
endif

INCLUDES = $(addprefix -I, $(INC_PATH))
CFLAGS :=  
CFLAGS += $(INCLUDES)  -Wno-deprecated
CFLAGS +=  -fpermissive -DTOP_NAME="\"V$(TOP_NAME)\""
VFLAGS :=  --cc --exe --build -j 0 --trace-fst  --autoflush
VFLAGS += --top-module $(TOP_NAME) 
VFLAGS += --Mdir $(BUILD_DIR)/obj_dir -Wno-TIMESCALEMOD
NVBOARD_FLAGS :=  -MMD -O3
# NVBOARD_FLAGS :=  -MMD -O3 --x-assign fast --x-initial fast --noassert
LDFLAGS += -lreadline -ltinfo -lSDL2
# LDFLAGS := -LDFLAGS "-lreadline -ltinfo -lSDL2"
# LDFLAGS += -LDFLAGS -lSDL2
BATCH ?= 1


ifeq ($(PLATFORM),ysyxsoc)
	CFLAGS += -DPLATFORM_YSYXSOC
	VFLAGS += -DPLATFORM_YSYXSOC
	CSRCS += $(filter-out $(EXCLUDE_DIR)/%, $(ALL_CSRCS))
	VFLAGS += $(NVBOARD_FLAGS)
	VFLAGS += -I$(VPATH) -I$(SOC_HOME)/perip/uart16550/rtl -I$(SOC_HOME)/perip/spi/rtl
	VFLAGS += --timescale "1ns/1ns" --no-timing
	CSRCS += $(SRC_AUTO_BIND)
	VSRCS += $(shell find $(SOC_HOME)/perip -name *.v)
	VSRCS += $(SOC_HOME)/build/ysyxSoCFull.v
endif

ifeq ($(PLATFORM),npc)
	CFLAGS += -DPLATFORM_NPC
	VFLAGS += -DPLATFORM_NPC
	CSRCS += $(ALL_CSRCS)
endif

VERILATOR = verilator
ARGS ?=  
ARGS += -l $(BUILD_DIR)/npc.log # 启用日志

CONFIG_FTRACE        := $(shell grep -m1 '^#define CONFIG_FTRACE' include/generated/autoconf.h | awk '{print $$3}')
CONFIG_DIFFTEST      := $(shell grep -m1 '^#define CONFIG_DIFFTEST' include/generated/autoconf.h | awk '{print $$3}')
CONFIG_WAVE          := $(shell grep -m1 '^#define CONFIG_WAVE' include/generated/autoconf.h | awk '{print $$3}')
CONFIG_ITRACE         := $(shell grep -m1 '^#define CONFIG_ITRACE' include/generated/autoconf.h | awk '{print $$3}')


ifneq ($(IMG),)
	ARGS += -i $(IMG)
endif

ifeq ($(IMG),)
	ifneq ($(OBJ),)
		# ARGS += -i $(NEW_OBJ_DIR)/new.bin
	endif
endif


ifeq ($(MAKECMDGOALS),gdb)
	CFLAGS += -g
endif

ifeq ($(CONFIG_FTRACE),1)
	ARGS += -e $(ELF)
endif

ifeq ($(CONFIG_DIFFTEST),1)
	LDFLAGS += -LDFLAGS -L$(dir $(NEMU_SO))
	LDFLAGS += -LDFLAGS -l:$(notdir $(NEMU_SO))
	LDFLAGS += -LDFLAGS "-Wl,-rpath,$(dir $(NEMU_SO))"
	ARGS += -d $(NEMU_SO)
endif

ifeq ($(BATCH),1)
	ARGS += -b 
endif

ifeq ($(CONFIG_ITRACE),1)
	CSRCS += $(WORK_DIR)/tools/disasm.c
	LIBCAPSTONE = $(NEMU_HOME)/tools/capstone/repo/libcapstone.so.5
	CFLAGS += -I$(NEMU_HOME)/tools/capstone/repo/include
src/utils/disasm.c: $(LIBCAPSTONE)
$(LIBCAPSTONE):
	$(MAKE) -C $(NEMU_HOME)/tools/capstone
endif


$(shell mkdir -p $(BUILD_DIR))

include $(WORK_DIR)/scripts/iverilog.mk
include $(WORK_DIR)/scripts/summary.mk

BIN = $(BUILD_DIR)/$(TOP_NAME)

all:run wave

ifeq ($(PLATFORM),ysyxsoc)
$(BIN):$(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VFLAGS) $^ $(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		-o $(abspath $(BIN))
else
$(BIN):$(VSRCS) $(CSRCS)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VFLAGS) $^ $(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		-o $(abspath $(BIN))
endif

verilog:sum

sim:$(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	
run: sim
	$(BIN) $(ARGS)
	
	
include ../Makefile

wave: $(BUILD_DIR)/wave.fst
	
	gtkwave $(BUILD_DIR)/wave.fst

PHONY: clean test adapt cleanwave perf sum verilog


adapt: sim
	$(MAKE) -C $(CPU_TEST_HOME) ARCH=minirv-npc ALL=$(OBJ)
	bash $(GEN) $(CPU_TEST_HOME)/$(OBJ)-minirv-npc.elf

gdb:sim
	@echo "Start gdb"
	gdb --args $(BIN) $(ARGS)

test:
	$(VERILATOR) --lint-only -Wall $(TEST_OBJ)
	$(VERILATOR) --cc -Wall --Mdir $(BUILD_DIR)/obj_dir $(TEST_OBJ)
	@echo PASS

perf:
	gedit ./performance/perf.md

clean:
	-rm -rf  $(BUILD_DIR)


cleanwave:
	-rm $(BUILD_DIR)/wave.fst


