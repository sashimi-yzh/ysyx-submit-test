# 通用配置和变量定义
WORK_DIR  = $(shell pwd)
BUILD_DIR_BASE = $(WORK_DIR)/build
PERF_DIR  = $(WORK_DIR)/perf

COMMIT_ID = $(shell git rev-parse --short HEAD)
SOC_COMMIT_ID = $(shell git -C $(SOC_HOME) rev-parse --short HEAD)
DATE_ID = $(shell date +%Y%m%d-%H%M%S)

# 包含配置文件(包括 menuconfig生成的配置)

include $(NPC_HOME)/.config
include $(NPC_HOME)/scripts/config.mk
include $(NPC_HOME)/tools/difftest.mk

GUEST_ISA ?= riscv32
FILELIST_MK = $(shell find -L ./csrc -name "filelist.mk")
include $(FILELIST_MK)


# 参数设置
override ARGS ?= --log=$(BUILD_DIR_BASE)/npc-log.txt
override ARGS += $(ARGS_DIFF)
# 编译器和链接器设置

# CFLAGS+= -g
CFLAGS+= -O3

# nvboard.a should be linked before include nvboard.mk
# because nvboard.a need LDFLAGS in nvboard.mk
LDFLAGS += "-L$(NVBOARD_HOME)/build -l:nvboard.a"
ifdef CONFIG_TRACE
	LDFLAGS += -lreadline 
endif

# verilog generate
include $(NVBOARD_HOME)/scripts/nvboard.mk
include $(NPC_HOME)/scripts/verilog-npc.mk
include $(NPC_HOME)/scripts/verilog-soc.mk
include $(NPC_HOME)/scripts/iverilog-npc.mk




INC_PATH := $(WORK_DIR)/include $(INC_PATH)
INCLUDES = $(addprefix -CFLAGS -I, $(INC_PATH))
VCFLAGS := -CFLAGS $(CFLAGS) $(INCLUDES) 
VCFLAGS += $(addprefix -CFLAGS , $(CXXFLAGS))


# 源文件定义
DIRS-BLACKLIST-y += $(DIRS-BLACKLIST)
SRCS-BLACKLIST-y += $(SRCS-BLACKLIST) $(shell find -L $(DIRS-BLACKLIST-y) -name "*.c")
SRCS-y += $(shell find -L $(DIRS-y) -name "*.c")
SRCS = $(filter-out $(SRCS-BLACKLIST-y), $(SRCS-y))
SOURCES += $(addprefix ${NPC_HOME}/, $(SRCS))


# Verilator基础配置
VERILATOR_BASE_FLAGS := --cc --exe --build -j 8 --vpi --timescale "1ns/1ns" --no-timing --autoflush
VERILATOR_BASE_FLAGS += $(VCFLAGS)
VERILATOR_BASE_FLAGS += $(addprefix -LDFLAGS , $(LDFLAGS))
VERILATOR_BASE_FLAGS += $(VINCLUDES)

ifdef CONFIG_WAVETRACE_FST
	VERILATOR_BASE_FLAGS += --trace-fst
endif

# 根据CHISEL标志选择编译路径
ifdef CONFIG_NPC_CHISEL
	include $(NPC_HOME)/scripts/npc-chisel.mk
else
    include $(NPC_HOME)/scripts/npc.mk
endif

ifdef IMG
	IMG_NAME ?= $(notdir $(IMG))
else 
	IMG_NAME ?= npc_default
endif

PERF_FILE_PATH = $(PERF_DIR)/$(IMG_NAME)_$(DATE_ID)_$(COMMIT_ID)_$(SOC_COMMIT_ID).txt
PERF_ARGS ?= $(ARGS)
PERF_ARGS += --perf=$(PERF_FILE_PATH)
# 通用规则
run: build 
	@echo $(ARGS) $(IMG) $(ISA)
	$(NPC_EXEC) 

clean:
	rm -rf $(BUILD_DIR_BASE)

sim:
	$(call git_commit, "sim RTL")
	@echo "Write this Makefile by your self."

perf: build
	@echo PERF_ARGS: $(PERF_ARGS) IMG: $(IMG)
	@mkdir -p $(PERF_DIR)
	$(NPC_PERF)
	@cat $(PERF_FILE_PATH)

verilog: verilog-npc verilog-soc verilog-iverilog
	@echo "Build verilog done"


.PHONY: run build clean sim verilog iverilog-run iverilog-build sim-iverilog sim-iverilog-netlist

# 包含上级Makefile（保持原有依赖）
include ../Makefile
