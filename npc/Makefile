SIM_ENV ?=ysyxsoc
YSYXSOC_HOME := $(abspath ../ysyxSoC)
YOSYS_HOME=$(HOME)/Desktop/yosys-sta
BUILD_DIR =./build
STA_DIR=$(abspath $(BUILD_DIR)/sta)
CELLS ?= $(YOSYS_HOME)/pdk/nangate45/sim/cells.v
NETLIST ?= $(STA_DIR)/ysyx_26040117-500MHz/ysyx_26040117.netlist.v.sim
VSRCS := $(shell find $(abspath ./vsrc/minirv) -name "*.v")
ifeq ($(SIM_ENV),ysyxsoc)
TOPNAME=ysyxSoCFull
VSRCS += $(shell find $(YSYXSOC_HOME)/perip -name "*.v")
VSRCS += $(YSYXSOC_HOME)/build/ysyxSoCFull.v
VERILATOR_FLAGS += -I$(YSYXSOC_HOME)/perip/uart16550/rtl -I$(YSYXSOC_HOME)/perip/spi/rtl
CXXFLAGS +=-DUSE_NVBOARD
else ifeq ($(SIM_ENV),npc)
TOPNAME=ysyx_26040117_SIM
VSRCS += vsrc/riscv32e_npc/ysyx_26040117_SIM.v
CXXFLAGS+=-DRISCV32E_NPC
else ifeq ($(SIM_ENV),iverilog)
TOPNAME=ysyx_26040117_iverilog_tb
VSRCS += vsrc/riscv32e_npc/ysyx_26040117_iverilog.v
VSRCS += vsrc/riscv32e_npc/ysyx_26040117_iverilog_tb.v
else ifeq ($(SIM_ENV),iverilog-netlist)
TOPNAME=ysyx_26040117_iverilog_tb
VSRCS := $(NETLIST) $(CELLS)
VSRCS += vsrc/riscv32e_npc/ysyx_26040117_iverilog.v
VSRCS += vsrc/riscv32e_npc/ysyx_26040117_iverilog_tb.v
endif

INC_PATH +=$(abspath ./csrc)
AUTOCONF_H = $(abspath ./csrc/include/autoconf.h)
IMG ?=
ARGS ?=
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc \
					-O3 --x-assign fast --x-initial fast --noassert
#VERILATOR_FLAGS += --trace-vcd
VERILATOR_FLAGS += -I$(abspath ./vsrc/minirv)
VERILATOR_FLAGS += --timescale "1ns/1ns" --no-timing --autoflush#uart flush

OBJ_DIR = $(BUILD_DIR)/sim/$(SIM_ENV)/obj_dir
BIN = $(BUILD_DIR)/sim/$(SIM_ENV)/$(TOPNAME)
default: $(BIN)

CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
ifeq ($(SIM_ENV),ysyxsoc)
NXDC_FILES=constr/$(TOPNAME).nxdc
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	@mkdir -p $(dir $@)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@
CSRCS += $(SRC_AUTO_BIND)
include $(NVBOARD_HOME)/scripts/nvboard.mk
endif

INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="V$(TOPNAME)" -g -O3 -flto
#CXXFLAGS += -g3 -O0 -fno-omit-frame-pointer
LDFLAGS += -lreadline -flto

#CXXFLAGS += -Wall -Wextra -fsanitize=address,undefined
#LDFLAGS  += -fsanitize=address,undefined

ifneq ($(shell grep '^\s*\#define\s\+CONFIG_DIFFTEST' $(AUTOCONF_H)),)
CXXFLAGS += -DNEMU_HOME_STR=$(NEMU_HOME)
endif
ifneq ($(shell grep '^\s*\#define\s\+CONFIG_ITRACE' $(AUTOCONF_H)),)
LIBCAPSTONE = $(NEMU_HOME)/tools/capstone/repo/libcapstone.so.5
CXXFLAGS += -DNEMU_HOME_STR=$(NEMU_HOME)
CXXFLAGS += -I$(NEMU_HOME)/tools/capstone/repo/include 
CXXFLAGS += -I$(NEMU_HOME)/src/utils
CXXFLAGS += -I$(NEMU_HOME)/include
CXXFLAGS += -fpermissive -DCONFIG_ISA_riscv
CSRCS+=$(NEMU_HOME)/src/utils/disasm.c
$(NEMU_HOME)/src/utils/disasm.c: $(LIBCAPSTONE)
$(LIBCAPSTONE):
	$(MAKE) -C $(NEMU_HOME)/tools/capstone
endif

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) $(VERILATOR_FLAGS)\
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

lint:
	$(VERILATOR) --lint-only -Wall -Wno-DECLFILENAME -Wno-UNUSED --top-module ysyx_26040117 vsrc/minirv/ysyx_26040117.v
all: default
run:$(BIN)
	$(BIN) $(ARGS) $(IMG)
sim: $(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "$(BIN) $(ARGS) $(IMG)"
	$(BIN) $(ARGS) $(IMG)

sim_i:
	@mkdir -p $(OBJ_DIR)
	riscv64-linux-gnu-objcopy -I binary -O verilog --verilog-data-width=4 --reverse-bytes=4 $(IMG) build/iverilog.hex
	iverilog -g2012 -s $(TOPNAME) -o build/iverilog.vvp $(VSRCS) 
	vvp build/iverilog.vvp
sim-iverilog:
	$(MAKE) sim_i SIM_ENV=iverilog
sim-iverilog-netlist:
	$(MAKE) sta STA_PDK=nangate45
	$(MAKE) sim_i SIM_ENV=iverilog-netlist
sim-ysyxsoc: 
	$(MAKE) sim SIM_ENV=ysyxsoc
sim-npc: 
	$(MAKE) sim SIM_ENV=npc
gdb: $(BIN)
	gdb --args $(BIN) $(ARGS) $(IMG)
verilog:
	@mkdir -p build
	@cat vsrc/minirv/ysyx_26040117.v \
		vsrc/minirv/ysyx_26040117_IFU.v \
		vsrc/minirv/ysyx_26040117_ICache.v \
		vsrc/minirv/ysyx_26040117_BTB.v \
		vsrc/minirv/ysyx_26040117_IDU.v \
		vsrc/minirv/ysyx_26040117_RegisterFile.v \
		vsrc/minirv/ysyx_26040117_EXU.v \
		vsrc/minirv/ysyx_26040117_LSU.v \
		vsrc/minirv/ysyx_26040117_WBU.v \
		vsrc/minirv/ysyx_26040117_CSR.v \
		vsrc/minirv/ysyx_26040117_arbiter.v \
		vsrc/minirv/ysyx_26040117_Xbar.v \
		vsrc/minirv/ysyx_26040117_CLINT.v \
		> build/ysyx_26040117.v
clean:
	rm -rf $(BUILD_DIR)
include ../Makefile
STA_TOP = ysyx_26040117
STA_FREQ_MHZ ?= 500
STA_VSRCS = $(shell find $(abspath ./vsrc/minirv) -name "*.v")
STA_PDK ?=nangate45
CLK_PORT_NAME=clock
sta:
	@mkdir -p $(STA_DIR)
	$(MAKE) -C $(YOSYS_HOME) sta PDK=$(STA_PDK) DESIGN=$(STA_TOP) \
		RTL_FILES="$(STA_VSRCS)" CLK_FREQ_MHZ=$(STA_FREQ_MHZ) CLK_PORT_NAME=$(CLK_PORT_NAME) O=$(STA_DIR) \
		2>&1 | tee sta.log
syn:
	@mkdir -p $(STA_DIR)
	$(MAKE) -C $(YOSYS_HOME) syn PDK=$(STA_PDK) DESIGN=$(STA_TOP) \
		RTL_FILES="$(STA_VSRCS)" CLK_FREQ_MHZ=$(STA_FREQ_MHZ) CLK_PORT_NAME=$(CLK_PORT_NAME) O=$(STA_DIR)

MICROBENCH_HOME ?= $(abspath ../am-kernels/benchmarks/microbench)
.PHONY: default all sim sim_i sim-ysyxsoc sim-npc lint gdb clean sta syn perf sim-iverilog-netlist sim-iverilog run verilog
perf:
	$(MAKE) -C $(MICROBENCH_HOME) \
		ARCH=riscv32e-ysyxsoc  \
		mainargs=train \
		run
