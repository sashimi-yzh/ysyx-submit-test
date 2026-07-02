.DEFAULT_GOAL = app

WORK_DIR  = $(NPC_HOME)
BUILD_DIR = $(WORK_DIR)/build/$(SIM_MODE)
OBJ_DIR   = $(BUILD_DIR)/obj-$(NAME)
BINARY    = $(BUILD_DIR)/$(NAME)

VERILATOR ?= verilator
OBJCACHE ?=
export OBJCACHE

CAPSTONE_HOME = $(NPC_HOME)/tools/capstone
CAPSTONE_SO = $(CAPSTONE_HOME)/repo/libcapstone.so.5
comma := ,

INC_PATH := $(WORK_DIR)/include $(INC_PATH)
LDFLAGS := $(LDFLAGS) -lreadline -ldl

VERILATOR_SRCS = $(abspath $(filter %.cpp %.cc,$(SRCS)))
HOST_SRCS = $(filter-out %.cpp %.cc,$(SRCS))

CSRC = $(filter %.c,$(HOST_SRCS))
OBJS = $(CSRC:%.c=$(OBJ_DIR)/%.o)

VERILOG_BUILD_DIR = $(WORK_DIR)/build
CPU_VERILOG = $(abspath $(VERILOG_BUILD_DIR)/ysyx_26030082.v)
CPU_VSRCS = $(sort $(shell find $(abspath $(NPC_HOME)/vsrc/core) -name "*.v"))
VSRCS_NPC = $(sort $(shell find $(abspath $(NPC_HOME)/vsrc/npc) -name "*.v"))
VHDRS_BASE = $(shell find $(abspath $(NPC_HOME)/vsrc) -name "*.vh" -o -name "*.svh")
HEADER_DEPS = $(shell find $(NPC_HOME)/include $(NPC_HOME)/src -type f \( -name "*.h" -o -name "*.hpp" \))

ifeq ($(SIM_MODE),npc)
TOPNAME = top
VSRCS = $(CPU_VERILOG) $(VSRCS_NPC)
INC_PATH += $(abspath $(NPC_HOME)/vsrc) $(abspath $(NPC_HOME)/vsrc/core) $(abspath $(NPC_HOME)/vsrc/npc)
else
TOPNAME = ysyxSoCFull
VSRCS = $(CPU_VERILOG) $(shell find $(YSYX_SOC_HOME)/perip -name "*.v") $(YSYX_SOC_HOME)/build/ysyxSoCFull.v
NXDC_FILES = $(abspath $(NPC_HOME)/constr/ysyxSoCFull.nxdc)
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
SRCS += $(SRC_AUTO_BIND)
MODE_EXTRA_INPUTS = $(NVBOARD_ARCHIVE)
MODE_EXTRA_DEPS = $(NVBOARD_ARCHIVE)
INC_PATH += $(abspath $(NPC_HOME)/vsrc) $(abspath $(NPC_HOME)/vsrc/core) $(YSYX_SOC_HOME)/perip/uart16550/rtl $(YSYX_SOC_HOME)/perip/spi/rtl
include $(NVBOARD_HOME)/scripts/nvboard.mk
endif

INCLUDES = $(addprefix -I, $(INC_PATH))
CFLAGS := -MMD -Wall -Werror $(INCLUDES) $(CFLAGS)
CFLAGS += -fmacro-prefix-map=$(abspath $(NPC_HOME))/=
CFLAGS += -DTOP_NAME=\"V$(TOPNAME)\"
CFLAGS += $(if $(filter npc,$(SIM_MODE)),-DNPC_BUILD_PLATFORM_NPC=1,-DNPC_BUILD_PLATFORM_YSYXSOC=1)
CFLAGS += $(if $(CONFIG_ITRACE),-I$(CAPSTONE_HOME)/repo/include,)
LDFLAGS += $(if $(CONFIG_ITRACE),-Wl$(comma)-rpath$(comma)$(CAPSTONE_HOME)/repo $(CAPSTONE_SO),)

VERILATOR_CFLAGS += -MMD --build -cc $(call remove_quote,$(CONFIG_VERILATOR_OPT)) --x-assign fast --x-initial fast --noassert \
	-Wno-PINMISSING -Wno-WIDTHEXPAND --timescale "1ns/1ns" --no-timing --autoflush -MAKEFLAGS "VM_DEFAULT_RULES=0"
VERILATOR_CFLAGS += $(if $(CONFIG_WAVE),--trace,)
VERILOG_DEFINES += -DNPC_SIMULATION
VERILOG_DEFINES += $(if $(UART_STDOUT_ENABLED),-DNPC_UART_STDOUT_RTL,)

BUILD_CONFIG = $(BUILD_DIR)/.build_config.mk
BUILD_CONFIG_TEXT := SIM_MODE=$(SIM_MODE) TOPNAME=$(TOPNAME) NAME=$(NAME) CFLAGS=$(CFLAGS) LDFLAGS=$(LDFLAGS) VERILATOR_CFLAGS=$(VERILATOR_CFLAGS) VERILOG_DEFINES=$(VERILOG_DEFINES) SRCS=$(SRCS) VSRCS=$(VSRCS)

.PHONY: FORCE_BUILD_CONFIG
$(BUILD_CONFIG): FORCE_BUILD_CONFIG | $(BUILD_DIR)
	@text="$(BUILD_CONFIG_TEXT)"; \
	if [ ! -f $@ ] || [ "$$(cat $@)" != "$$text" ]; then \
	  rm -rf $(OBJ_DIR); \
	  printf '%s\n' "$$text" > $@; \
	fi

$(OBJ_DIR)/%.o: %.c $(BUILD_CONFIG)
	@echo + CC $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<
	$(call call_fixdep, $(@:.o=.d), $@)

-include $(OBJS:.o=.d)

$(BUILD_DIR) $(VERILOG_BUILD_DIR):
	@mkdir -p $@

$(CPU_VERILOG): $(CPU_VSRCS) | $(VERILOG_BUILD_DIR)
	@echo + CAT "->" $@
	@cat $(CPU_VSRCS) > $@

$(SRC_AUTO_BIND): $(NXDC_FILES) | $(BUILD_DIR)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

$(CAPSTONE_SO):
	$(MAKE) -C $(CAPSTONE_HOME)

ifeq ($(CONFIG_ITRACE),y)
TRACE_DEPS += $(CAPSTONE_SO)
endif

CONFIG_DEPS = $(NPC_HOME)/include/generated/autoconf.h $(NPC_HOME)/include/config/auto.conf
NPC_DEPS = $(VSRCS) $(VHDRS_BASE) $(VERILATOR_SRCS) $(HEADER_DEPS) $(BUILD_CONFIG) $(OBJS) $(MODE_EXTRA_DEPS) $(TRACE_DEPS) $(CONFIG_DEPS)
NPC_DEPS += $(NPC_HOME)/Makefile $(NPC_HOME)/scripts/build.mk $(NPC_HOME)/scripts/native.mk

app build: $(BINARY)

$(BINARY):: $(NPC_DEPS) | $(BUILD_DIR)
	@rm -f $(abspath $(BINARY))
	$(VERILATOR) $(VERILATOR_CFLAGS) $(VERILOG_DEFINES) $(addprefix -I, $(INC_PATH)) \
		--top-module $(TOPNAME) $(VSRCS) $(VERILATOR_SRCS) $(OBJS) $(MODE_EXTRA_INPUTS) \
		$(addprefix -CFLAGS , $(CFLAGS)) \
		$(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR)/verilator --exe -o $(abspath $(BINARY))
	@touch $(abspath $(BINARY))

clean:
	-rm -rf $(WORK_DIR)/build

.PHONY: app build clean
