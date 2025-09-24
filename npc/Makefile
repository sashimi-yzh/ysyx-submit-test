include ../Makefile

#-----------------------------------------------------------------
# Configuration
#-----------------------------------------------------------------
# CONFIG_ITRACE = 1
# CONFIG_DIFFTEST = 1
ifndef CONFIG_NPC
CONFIG_FAST_SIM = 1
endif

#-----------------------------------------------------------------
# Base Directory
#-----------------------------------------------------------------
WORK_DIR      = $(shell pwd)
NPC_BUILD_DIR = $(NPC_HOME)/build
BUILD_DIR     = $(WORK_DIR)/build
OBJ_DIR       = $(NPC_BUILD_DIR)/obj_dir
SOC_HOME      ?= $(YSYX_HOME)/ysyxSoC

#-----------------------------------------------------------------
# Output files
#-----------------------------------------------------------------
#=== verilator ===================================================
TOPNAME=ysyxSoCFull
VERI_BIN = $(OBJ_DIR)/V$(TOPNAME)

#=== iverilog ====================================================
## npc
IV_TOPNAME = ysyx_23060170_tb_iverilog
IV_BIN =  $(NPC_BUILD_DIR)/$(IV_TOPNAME)

## netlist
NET_TOPNAME = ysyx_23060170_tb_netlist
NET_BIN =$(NPC_BUILD_DIR)/$(NET_TOPNAME)

### gen verilog #################
VERILOG = $(NPC_BUILD_DIR)/ysyx_23060170.v

#-----------------------------------------------------------------
# Flags
#-----------------------------------------------------------------
#=== verilator ===================================================
## include
INC_PATH =  $(abspath csrc/include)
INC_PATH += $(abspath vsrc)
INC_PATH += $(abspath $(SOC_HOME)/perip/uart16550/rtl)
INC_PATH += $(abspath $(SOC_HOME)/perip/spi/rtl)
INC_PATH += $(abspath $(NVBOARD_HOME)/usr/include)
INCFLAGS =  $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS)
# CXXFLAGS += -g -O0

## trace
ifdef CONFIG_ITRACE
CXXFLAGS += $(shell llvm-config --cxxflags) -fPIE
CXXFLAGS := $(filter-out -D__STDC_FORMAT_MACROS,$(CXXFLAGS))
LDFLAGS  += $(shell llvm-config --libs)
endif

## diff
ifdef CONFIG_DIFFTEST
DIFF_REF_SO = $(NEMU_HOME)/build/riscv32-nemu-interpreter-so
ARGS_DIFF   = --diff=$(DIFF_REF_SO)
override ARGS += $(ARGS_DIFF)
endif

## vflah
VERIFLAGS = -MMD --build --Wall -cc --exe -O3 \
				 --x-assign fast --x-initial fast \
				 --noassert --trace --autoflush \
				 --timescale "1ns/1ns" --no-timing \
				 --Wno-PINCONNECTEMPTY --Wno-ASSIGNDLY --Wno-UNDRIVEN \
				 --Wno-PINMISSING --Wno-DEFPARAM \
				 --Wno-SYNCASYNCNET  -Wno-UNUSED\
				 --Mdir $(OBJ_DIR) --Wno-DECLFILENAME
VERIFLAGS += --trace-fst
VERIFLAGS += -Dysyx_23060170_EBREAK
ifndef CONFIG_FAST_SIM
VERIFLAGS += -Dysyx_23060170_VERILATOR
VERIFLAGS += -Dysyx_23060170_SIM_INFO
endif

## readl
LDFLAGS += -lreadline -ldl -pie

## perf
ifdef CONFIG_PERF
CXXFLAGS += -DCONFIG_PERF
endif

## fast sim
ifdef CONFIG_FAST_SIM
CXXFLAGS += -DCONFIG_FAST_SIM
endif

## npc
ifdef CONFIG_NPC
CXXFLAGS  += -Dysyx_23060170_NPC
VERIFLAGS += -Dysyx_23060170_NPC
endif

## constraint file
ifndef CONFIG_NPC
NXDC_FILES = constr/top.nxdc
SRC_AUTO_BIND = $(abspath $(NPC_BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	@mkdir -p $(NPC_BUILD_DIR)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

include $(NVBOARD_HOME)/scripts/nvboard.mk
endif

## gcc flag
VERI_CXXFLAGS := $(addprefix -CFLAGS , $(CXXFLAGS))
VERI_LDFLAGS  := $(addprefix -LDFLAGS , $(LDFLAGS))

#=== iverilog ====================================================
## npc
IVFLAGS += -Dysyx_23060170_NPC
IVFLAGS += -DMEM_FILE=\"$(MEM_FILE)\" \
		   -DLOG_FILE=\"$(LOG_FILE)\" \
		   -DREF_FILE=\"$(REF_FILE)\"

ifdef IMG
IVFLAGS = -Dysyx_23060170_NPC
IV_VBIN = $(IMG:.bin=.vbin)
IVFLAGS += -DMEM_FILE=\"$(IV_VBIN)\"
endif

## netlist
NET_FLAGS += -Dysyx_23060170_NPC -Dysyx_23060170_NETLIST
NET_FLAGS += -DMEM_FILE=\"$(MEM_FILE)\" \
		     -DLOG_FILE=\"$(LOG_FILE)\" \
		     -DREF_FILE=\"$(REF_FILE)\"

ifdef IMG
NET_FLAGS = -Dysyx_23060170_NPC -Dysyx_23060170_NETLIST
NET_VBIN = $(IMG:.bin=.vbin)
NET_FLAGS += -DMEM_FILE=\"$(NET_VBIN)\"
endif

#-----------------------------------------------------------------
# Source files
#-----------------------------------------------------------------
#=== verilator ===================================================
VERI_CSRCS += $(shell find $(abspath $(NPC_HOME)/csrc) -name "*.cpp")
VERI_CSRCS += $(SRC_AUTO_BIND)

ifdef CONFIG_FAST_SIM
VERI_VSRCS += $(VERILOG)
else
VERI_VSRCS += $(shell find $(abspath $(NPC_HOME)/vsrc/core) -name "*.v")
endif

ifdef CONFIG_NPC
VERI_VSRCS += $(shell find $(abspath $(NPC_HOME)/vsrc/sim) -name "*.v")
else
VERI_VSRCS += $(shell find $(abspath $(SOC_HOME)/perip/) -name "*.v")
VERI_VSRCS += $(shell find $(abspath $(NPC_HOME)/vsrc/soc) -name "*.v")
endif

#=== iverilog ====================================================
## npc
IV_SRC += $(shell find $(abspath $(NPC_HOME)/vsrc/sim) -name "*.v")

## netlist
CELLS 	?= $(shell find $(abspath $(NPC_HOME)/yosys-sta/nangate45/sim) -name "*.v")
NETLIST ?= $(shell find $(abspath $(NPC_HOME)/yosys-sta/result) -name "ysyx_23060170.netlist.fixed.v")
NET_SRC += $(shell find $(abspath $(NPC_HOME)/vsrc/sim) -name "*.v")

#=== gen verilog =================================================
GEN_VSRCS += $(shell find $(abspath $(NPC_HOME)/vsrc/core) -name "*.v")

#-----------------------------------------------------------------
# Count lines of code
#-----------------------------------------------------------------	
.PHONY: count
count:
	@echo
	@echo "-- COUNTING -------------------------------"
	@echo "Verilog    $(shell find $(NPC_HOME)/vsrc -name "*.v" | xargs cat | wc -l) lines"
	@echo "C++        $(shell find $(NPC_HOME)/csrc -name "*.cpp" | xargs cat | wc -l) lines"
	@echo

#-----------------------------------------------------------------
# Generate Verilog
#-----------------------------------------------------------------
.PHONY: $(VERILOG)
$(VERILOG): $(GEN_VSRCS)
	@echo
	@echo "-- GEN VERILOG ------------------------------"
	@mkdir -p $(NPC_BUILD_DIR)
	cat $(GEN_VSRCS) > $(VERILOG)
	python3 $(NPC_HOME)/scripts/remove_verilator_public.py --no-backup $(NPC_BUILD_DIR)
	@echo

#-----------------------------------------------------------------
# clean lint
#-----------------------------------------------------------------
.PHONY: lint
lint: $(VERILOG)
	@echo
	@echo "-- LINTING ---------------------------------"
	@mkdir -p build
	verilator --lint-only -Wall $(VERILOG) 2> build/lint.log
	@echo

#-----------------------------------------------------------------
# Verilator
#-----------------------------------------------------------------
.PHONY: $(VERI_BIN)
$(VERI_BIN): $(VERI_CSRCS) $(VERI_VSRCS) $(NVBOARD_ARCHIVE)
	@echo
	@echo "-- VERILATING ------------------------------"
	echo $(VERIFLAGS)
	echo $(VERI_VSRCS)
	echo $(IMG)
	@rm -rf $(OBJ_DIR)
	@mkdir -p $(NPC_BUILD_DIR)
	verilator --top-module $(TOPNAME) $^ $(INCFLAGS) $(VERIFLAGS) $(VERI_CXXFLAGS) $(VERI_LDFLAGS)

.PHONY:wave
wave: $(VERI_BIN)
	@echo
	@echo "-- GTKWAVE ---------------------------------"
	$(VERI_BIN) -b $(ARGS) $(IMG)
	gtkwave waveform.vcd .config.gtkw

.PHONY:sim
sim: $(VERI_BIN)
	@echo
	@echo "-- SIMULATING ------------------------------"
	$(VERI_BIN) $(ARGS) $(IMG)
	@echo
	@echo "Simulation Completed"
	@echo
	@echo "-- GIT TRACE -------------------------------"
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo

#-----------------------------------------------------------------
# iverilog
#-----------------------------------------------------------------
#=== iverilog npc ================================================
.PHONY: $(IV_BIN)
$(IV_BIN): $(IV_SRC) $(VERILOG)
	@echo
	@echo "-- IVERILOGING -----------------------------"
	echo $(IVFLAGS)
	@mkdir -p $(NPC_BUILD_DIR)
	iverilog -g2012 -o $@ $(VERILOG) $(IV_SRC) $(IVFLAGS)

.PHONY: iverilog
iverilog: $(IV_BIN)
	@echo
	@echo "-- IV SIMULATING ---------------------------"
	vvp $(IV_BIN) -fst
	@echo
	@echo "Simulation Completed"
	@echo
	@echo "-- GIT TRACE -------------------------------"
	$(call git_commit, "iverilog sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo

#=== netlist =====================================================
.PHONY: $(NET_BIN)
$(NET_BIN): $(NET_SRC) $(CELLS) $(NETLIST)
	@echo
	@echo "-- NETLISTING -----------------------------"
	echo $(NET_FLAGS)
	@mkdir -p $(NPC_BUILD_DIR)
	iverilog -g2012 -o $@ $(CELLS) $(NETLIST) $(NET_SRC) $(NET_FLAGS)

.PHONY: netlist
netlist: $(NET_BIN)
	@echo
	@echo "-- NET SIMULATING ---------------------------"
	vvp $(NET_BIN) -fst
	@echo
	@echo "Simulation Completed"
	@echo
	@echo "-- GIT TRACE -------------------------------"
	$(call git_commit, "iverilog sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo

#-----------------------------------------------------------------
# CI procedure
#-----------------------------------------------------------------
.PHONY: verilog
verilog: $(VERILOG)

.PHONY: sim-iverilog
sim-iverilog: $(IV_BIN)
	@echo
	@echo "-- IV SIMULATING ---------------------------"
	vvp $(IV_BIN) -fst
	@echo
	@echo "Simulation Completed"
	@echo

.PHONY: sim-iverilog-netlist
sim-iverilog-netlist: $(NET_BIN)	
	@echo
	@echo "-- NET SIMULATING ---------------------------"
	vvp $(NET_BIN) -fst
	@echo
	@echo "Simulation Completed"
	@echo

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) waveform* $(NPC_BUILD_DIR)
