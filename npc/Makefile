BUILD_DIR = ./build
# case sensitive
CPU_DESIGN_NAME = ysyx_25100261

SIM_CSRC_DIR = ./sim
VSIM_OPT?= -O3
SIM_BIN_DIR = $(BUILD_DIR)/bin

COMMIT_HASH = $(shell git rev-parse HEAD)
CXXFLAGS += -DGIT_COMMIT_HASH=$(COMMIT_HASH)

ARCH ?= riscv32e-npc

ARCH_PLATFORM = $(lastword $(subst -, ,$(ARCH)))
ARCH_ISA = $(firstword $(subst -, ,$(ARCH)))

CXXFLAGS += -DSIM_ARCH_$(shell echo $(ARCH_PLATFORM) | tr a-z A-Z)

SIM_VSRCS =

VERILATOR_FLAGS ?=
VERILATOR_INCDIRS =

ifeq ($(ARCH), riscv32e-ysyxsoc)
TOP_NAME = ysyxSoCFull
else
TOP_NAME = TestSoC
endif

SIM_BIN = $(SIM_BIN_DIR)/$(TOP_NAME)-$(ARCH_PLATFORM)$(VSIM_OPT)
default: $(SIM_BIN)

CHISEL2V_EMIT_ROOT = $(BUILD_DIR)/gened/verilog

ifeq ($(ARCH), riscv32e-ysyxsoc)
include ./scripts/ysyxsoc.mk
else
include ./scripts/mytestsoc.mk
endif

VERILATOR = verilator

IMG ?= 

SAN_FLAGS?= #-fsanitize=address

# Performance counter need VPI to fetch handshake signals
ENABLE_VPI ?= 1

ifeq ($(ENABLE_VPI), 1)
VERILATOR_FLAGS += --vpi
endif

# Dependencies for sim
include ./scripts/deplibs.mk
include ./scripts/chisel.mk

VERILATOR_FLAGS += --trace-fst --trace-structs

V2CXX_EMIT_DIR = $(BUILD_DIR)/gened/cxx/$(ARCH_PLATFORM)

CORE_VSRCS = $(CHISEL_EMITED_VSRCS)
SYNTH_VSRCS = $(CHISEL_EMITED_VSRCS_SYNTH)

MY_SIM_VSRCS += $(CORE_VSRCS)
MY_SIM_VSRCS += $(CHISEL_EMITED_VSRCS_LAYER)


SIM_VSRCS += $(MY_SIM_VSRCS)
SIM_CSRCS += $(shell find $(abspath $(SIM_CSRC_DIR)) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

SIM_HEADERS = $(shell find $(abspath $(SIM_CSRC_DIR)) -name "*.h" -or -name "*.hpp")

STA_OUT_DIR = $(abspath $(BUILD_DIR)/sta)

# dirs
$(shell mkdir -p $(BUILD_DIR))
$(shell mkdir -p $(SIM_BIN_DIR))
$(shell mkdir -p $(V2CXX_EMIT_DIR))

# rules for verilator

VERILATOR_FLAGS += -MMD -cc \
										--x-assign fast --x-initial fast \
										--autoflush \
										--compiler clang \
										$(addprefix -I,$(VERILATOR_INCDIRS)) \

VERILATOR_FLAGS += --hierarchical
										# --output-split 20000 

COMMON_VERILOG_DEFINES = ysyx_25100261_InlinePrintfLayer
COMMON_VERILOG_DEFINES += $(CPU_DESIGN_NAME)_ResetPCProvider_RESET_PC=32\'h$(RESET_PC)
ifdef GITHUB_ACTIONS
COMMON_VERILOG_DEFINES += IS_CI_ENV
endif

# need reserved since both verilator and iverilog will use it
COMMON_VERILOG_DEFINES_FLAGS = $(addprefix -D,$(COMMON_VERILOG_DEFINES))

VERILATOR_FLAGS += $(COMMON_VERILOG_DEFINES_FLAGS)


VERILATOR_CONTROL_FILE = verilator.vlt

# --noassert -O3

INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME=V$(TOP_NAME) -DENABLE_VPI=$(ENABLE_VPI)
CXXFLAGS += $(SAN_FLAGS) -std=c++20 -g # -fno-inline

# when use perf tool, frame pointer is needed
# CXXFLAGS += -fno-omit-frame-pointer

# LDFLAGS += -fuse-ld=mold

MOLD_EXISTS := $(shell command -v mold 2> /dev/null)
ifneq ($(MOLD_EXISTS),)
# make link faster
  LDFLAGS += -fuse-ld=mold
endif

NPC_STARTUP_BIN = ./jmpROM/build/jmp.bin
$(NPC_STARTUP_BIN):
	@echo "# Build NPC startup binary"
	@$(MAKE) -C ./jmpROM

$(SIM_BIN): $(SIM_DEP_LIBS_BUILD_DONE) $(CHISEL2V_DONE) $(SIM_VSRCS) $(SIM_CSRCS) $(ARCHIVES) $(SIM_HEADERS) $(VERILATOR_CONTROL_FILE)
ifndef IN_LOCK
	@+flock $(SIM_BIN).lock $(MAKE) $@ IN_LOCK=1
else
	@rm -rf $(V2CXX_EMIT_DIR)
	@echo "=== Gen c++ sources from verilog with verilator ==="
	@$(VERILATOR) $(VERILATOR_FLAGS) \
		$(SIM_CSRCS) $(NVBOARD_ARCHIVE) \
		--top-module $(TOP_NAME) $(VERILATOR_CONTROL_FILE) $(SIM_VSRCS) \
		$(addprefix -CFLAGS , $(CXXFLAGS)) \
		$(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(V2CXX_EMIT_DIR) --exe -o $(abspath $(SIM_BIN))
	@echo "=== Build sim binary with clang++ ==="
	@echo "clang++ version: $(shell clang++ -dumpversion)"
	@$(MAKE) -s -C $(V2CXX_EMIT_DIR) -f V$(TOP_NAME).mk -j$(shell nproc) OPT_FAST=$(VSIM_OPT) CXX=clang++ LINK=clang++ AR="ar -T"
endif

verilog-lint: verilog
	$(info Lint verilog files with verilator)
	@$(VERILATOR) --lint-only $(VERILATOR_FLAGS) -Wall $(SYNTH_VSRCS)

all: default

test:
	$(MILL) -i $(CHISEL_DESIGN).test

SYNTH_VSRCS_ALLINONE = $(BUILD_DIR)/$(CPU_DESIGN_NAME).v
$(SYNTH_VSRCS_ALLINONE): $(CHISEL2V_DONE)
	@echo "# Merge verilog files into one file $(SYNTH_VSRCS_ALLINONE)"
	@cat $(SYNTH_VSRCS) > $(SYNTH_VSRCS_ALLINONE)

verilog: $(SYNTH_VSRCS_ALLINONE)

help:
	$(MILL) -i $(CHISEL_DESIGN).runMain Elaborate --help

reformat:
	$(MILL) -i __.reformat

checkformat:
	$(MILL) -i __.checkFormat

bsp:
	$(MILL) -i mill.bsp.BSP/install

idea:
	$(MILL) -i mill.idea.GenIdea/idea

clean:
	-rm -rf $(BUILD_DIR)

clean-bin:
	-rm -rf $(SIM_BIN_DIR)

.PHONY: test help reformat checkformat clean

ARGS?=
sim: $(SIM_BIN) $(NPC_STARTUP_BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "=== ENV ==="
	@echo "VSIM_OPT=$(VSIM_OPT)"
	@echo "ENABLE_VPI=$(ENABLE_VPI)"
	@echo "=== SIM BEGIN ==="
	@LSAN_OPTIONS=suppressions=asan_suppress.txt $^ $(ARGS) $(IMG)

include ./scripts/sta.mk

IVERILOG_SIM_FILE = $(BUILD_DIR)/iverilog_sim
IVERILOG_TESTBENCH = ./iverilog/testbench.v
IVERILOG = iverilog -g2012 -DENABLE_INITIAL_MEM_ $(COMMON_VERILOG_DEFINES_FLAGS)

IVERILOG_SIM_VSRCS = $(IVERILOG_TESTBENCH) $(SYNTH_VSRCS) $(SOC_SYNTH_VSRCS)

$(IVERILOG_SIM_FILE): verilog $(IVERILOG_SIM_VSRCS)
	@echo "# Process verilog files with iverilog"
	$(IVERILOG) -o $(IVERILOG_SIM_FILE) $(IVERILOG_SIM_VSRCS)

sim-iverilog-img-hex: $(IMG) $(NPC_STARTUP_BIN)
	@echo "# Generate verilog hex file for iverilog sim"
	@echo "IMG = $(IMG)"
	objcopy -O verilog --verilog-data-width=4 -I binary --reverse-bytes=4 $(IMG) $(BUILD_DIR)/npcmem_init.hex

sim-iverilog: $(IVERILOG_SIM_FILE) sim-iverilog-img-hex
	$(info # Run iverilog simulation)
	vvp $(IVERILOG_SIM_FILE) -fst

DEFAULT_NETLIST = $(STA_OUT_DIR)/$(STA_DEST_FULL_NAME)-$(STA_FREQ_MHZ)MHz/$(STA_DEST_FULL_NAME).netlist.fixed.v
$(DEFAULT_NETLIST): sta
	$(info # Netlist generated by STA flow: $@)

# shoud be generated by STA flow
# or passed from outside
NETLIST ?= $(DEFAULT_NETLIST)

# # normally, the STA flow will also generate a sim version of the netlist
# # which collect signals xxx_0_ ... xxx_n_ to [n-1:0] xxx for convenient
# # testbench writing. 
# # If the sim version netlist is not generated, will fail since not support.
# NETLIST_FOR_SIM = $(NETLIST).sim
NETLIST_FOR_SIM = $(NETLIST)

# in CI passed from outside
CELLS ?= $(YOSYS_STA_PATH)/pdk/nangate45/sim/cells.v

# NETLIST_SIM_OTHER_MODULES = NPCDevices AXI4MemUnit AXI4LiteXBar AXI4LiteXBar_1
# NETLIST_SIM_OTHER_VSRCS = $(addsuffix .sv, $(addprefix $(abspath $(CHISEL2V_EMIT_DIR))/$(CPU_DESIGN_NAME)_, $(NETLIST_SIM_OTHER_MODULES)))

NETLIST_SIM_OTHER_VSRCS = $(filter-out %$(STA_DEST_FULL_NAME).sv, $(IVERILOG_SIM_VSRCS))

IVERILOG_NETLIST_SIM_FILE = $(BUILD_DIR)/iverilog_netlist_sim
$(IVERILOG_NETLIST_SIM_FILE): verilog $(NETLIST_FOR_SIM) $(CELLS) $(NETLIST_SIM_OTHER_VSRCS)
	$(info Process netlist verilog files with iverilog for sim)
	$(IVERILOG) -DSIM_NETLIST -o $(IVERILOG_NETLIST_SIM_FILE) $(NETLIST_FOR_SIM) $(CELLS) $(NETLIST_SIM_OTHER_VSRCS)

sim-iverilog-netlist: $(IVERILOG_NETLIST_SIM_FILE) sim-iverilog-img-hex
	$(info Run iverilog simulation with netlist)
	vvp $(IVERILOG_NETLIST_SIM_FILE) -fst

perf: 
	+./scripts/make_perf.sh

-include ../Makefile
