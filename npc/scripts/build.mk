.DEFAULT_GOAL = hw_app

TOP_MODULE = ysyxSoCFull
WORK_DIR  = $(shell pwd)
BUILD_DIR = $(WORK_DIR)/build

ifdef CONFIG_NVBOARD
# nvboard configuration files
NXDC_FILES = constr/soctop.nxdc

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@
CPPSRC += $(SRC_AUTO_BIND)
# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk
endif

INC_PATH := $(WORK_DIR)/include $(INC_PATH) $(WORK_DIR)/vsrc

# soc peripheral rtl path
INC_PATH += $(WORK_DIR)/../ysyxSoC/perip/uart16550/rtl
INC_PATH += $(WORK_DIR)/../ysyxSoC/perip/spi/rtl

OBJ_DIR  = $(BUILD_DIR)/obj-$(NAME)$(SO)
SW_BINARY = $(BUILD_DIR)/$(NAME)$(SO)
BINARY = $(BUILD_DIR)/V$(NAME)$(SO)

VERILATOR := verilator

# verilator settings
VERILATOR_FLAGS = -MMD --cc -O2 --x-initial fast --x-assign fast

# only build trace support when waveform dumping is enabled; a traced model
# keeps maintaining activity flags every cycle even if nothing is dumped
ifdef CONFIG_WTRACE
VERILATOR_FLAGS += --trace-fst
endif

# Chisel-generated AsyncQueue index expressions can trigger WIDTH false positives
# on some Verilator versions; keep simulation flow unblocked.
VERILATOR_FLAGS += -Wno-WIDTH

# to support system verilog
VERILATOR_FLAGS += -sv

# soc flags
VERILATOR_FLAGS += --timescale "1ns/1ns" --no-timing --autoflush

# uart output goes through nvboard's uart decoder, so disable the $write
# backdoor in uart_tfifo.v to avoid printing every char twice
ifdef CONFIG_NVBOARD
VERILATOR_FLAGS += -DNVBOARD_UART
endif

# skip SPI timing for flash reads in simulation (spi_top_apb.v FAST_FLASH)
ifdef CONFIG_FAST_FLASH
VERILATOR_FLAGS += -DFAST_FLASH
endif

# simulation-only larger icache (ysyx_24110012.v ICACHE_SIM_LARGE)
ifdef CONFIG_ICACHE_SIM_LARGE
VERILATOR_FLAGS += -DICACHE_SIM_LARGE
endif

# performance counter
ifdef CONFIG_PERF
VERILATOR_FLAGS += -DPERF
endif

# disable hazard forwarding for a no-forward baseline measurement while keeping
# stall detection active for data hazard analysis.
ifdef NO_FORWARD
VERILATOR_FLAGS += -DNO_FORWARD
endif

ifneq ($(or $(CONFIG_NPC_IVERILOG),$(CONFIG_NPC_IVERILOG_NET)),)
IVERILOG_FLAGS += -g2012
endif

ifdef CONFIG_NPC
VERILATOR_FLAGS += -DNPC
IVERILOG_FLAGS += -DNPC
endif

ifdef CONFIG_DIFFTEST
VERILATOR_FLAGS += -DDIFF_TEST
endif

ifeq ($(CC),clang)
CXX := clang++
else
CXX := g++
endif
LD := $(CXX)
INCLUDES = $(addprefix -I, $(INC_PATH))
CFLAGS  := -O2 -g -MMD -Wall -Werror $(INCLUDES) $(CFLAGS)
CXXFLAGS  += -O2 -g -MMD -Wall $(INCLUDES) -rdynamic
ifdef CONFIG_NVBOARD
CXXFLAGS += -DTOP_NAME="\"V$(TOP_MODULE)\"" $(shell sdl2-config --cflags)
endif
LDFLAGS := -O2 $(LDFLAGS) $(LIBS) -rdynamic


CPPSRC := $(abspath $(CPPSRC))
CXXSRC := $(abspath $(CXXSRC))

C_OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Compilation patterns
$(OBJ_DIR)/%.o: %.c
	@echo + CC $<
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(OBJ_DIR) -c -o $@ $<
	$(call call_fixdep, $(@:.o=.d), $@)

# Depencies
-include $(OBJS:.o=.d)

# Some convenient rules

.PHONY: hw_app app clean

app: $(SW_BINARY)
$(SW_BINARY):: $(C_OBJS) $(ARCHIVES)
	@echo + LD $@
	@$(LD) -o $@ $(C_OBJS) $(LDFLAGS) $(ARCHIVES) $(LIBS)

hw_app: $(BINARY)

ifdef CONFIG_NPC_IVERILOG_NET
# Regenerate the post-synthesis netlist when the RTL changes
$(NETLIST_SIM): $(NETLIST_RTL) $(YOSYS_STA_HOME)/scripts/yosys.tcl
	$(MAKE) -C $(YOSYS_STA_HOME) clean
	$(MAKE) -C $(YOSYS_STA_HOME) syn
	cp $(YOSYS_STA_HOME)/result/*/ysyx_24110012.netlist.v.sim $@
endif

# Link all files to generate the final binary
ifdef CONFIG_NVBOARD
$(BINARY):: $(C_OBJS) $(CPPSRC) $(CXXSRC) $(NVBOARD_ARCHIVE)
else ifdef CONFIG_NPC
ifeq ($(or $(CONFIG_NPC_IVERILOG),$(CONFIG_NPC_IVERILOG_NET)),)
$(BINARY):: $(C_OBJS) $(CPPSRC) $(CXXSRC)
else
# FORCE keeps the old "always re-run iverilog" behaviour,
# $(VSRCS) makes sure generated sources (e.g. the netlist) are built first
$(BINARY):: $(VSRCS)
endif
else
# SOC: verilator build
$(BINARY):: $(C_OBJS) $(CPPSRC) $(CXXSRC)
endif
ifneq ($(or $(CONFIG_NPC_IVERILOG),$(CONFIG_NPC_IVERILOG_NET)),)
	@ echo + IVERILOG working 100MHz
	@ mkdir -p build
	iverilog $(IVERILOG_FLAGS) $(VSRCS) -o $(BINARY)
else
	@ echo + VERILATOR working
	mkdir -p $(dir $@)
	$(VERILATOR) --build --exe $(VSRCS) \
	-Mdir $(OBJ_DIR) \
	$(VERILATOR_FLAGS) \
	$(INCLUDES) \
	--top-module $(TOP_MODULE) -o $@ $^ \
	$(addprefix -CFLAGS , $(CXXFLAGS)) \
	$(addprefix -LDFLAGS , $(LDFLAGS))
endif

clean:
	-rm -rf $(BUILD_DIR)

### Debug Purpose #####
#$(info INCLUDES = $(INCLUDES))
#$(info VSRCS = $(VSRCS))
#$(info VERILATOR_FLAGS = $(VERILATOR_FLAGS))
#$(info TOP_MODULE = $(TOP_MODULE))
#$(info CXXSRC=$(CXXSRC))
#$(info CPPSRC=$(CPPSRC))
#$(info C_OBJS=$(C_OBJS))
#$(info LDFLAGS=$(LDFLAGS))
#$(info CXXFLAGS=$(CXXFLAGS))
#$(info CFLAGS=$(CFLAGS))
#$(info BINARY=$(BINARY))
