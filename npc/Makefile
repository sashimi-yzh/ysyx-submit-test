#ENABLE_WAVE = 1
YSYXSOC = 1
#NETLIST_SIM = 1
HAS_NVBOARD = 1
#SYNC_FREQ = 1
#RV64 = 1
#MILL_FLAGS += --debug
#GSIM = 1

BUILD_DIR = $(abspath ./build)
$(shell mkdir -p $(BUILD_DIR))
SCALA_FILES = $(shell find src/main/ -name "*.scala")
PRJ = playground
TOP = Top
VFILE_PREFIX = $(BUILD_DIR)/$(TOP)
VFILE-sim = $(VFILE_PREFIX)sim.sv
VFILE-syn = $(VFILE_PREFIX)syn.sv

YOSYS_STA_HOME = ~/ysyx/yosys-sta
CLK_FREQ_MHZ = 2000
STA_RESULT_DIR = $(BUILD_DIR)/sta/$(TOP)-$(CLK_FREQ_MHZ)MHz

ifeq ($(RV64),1)
MILL_FLAGS += --rv64
else
EMU_CFLAGS += -DRVE=1
endif
XLEN = $(if $(RV64),64,32)
EMU_CFLAGS += -DXLEN=$(XLEN)

ifeq ($(NETLIST_SIM),1)
YSYXSOC = 1
VFILE-sim = $(STA_RESULT_DIR)/$(TOP).netlist.fixed.v
VFILE_EXTRA += $(YOSYS_STA_HOME)/pdk/nangate45/sim/cells.v
EMU_CFLAGS += -DNETLIST_SIM=1
$(VFILE-sim): sta
endif

YSYXSOC_HOME = $(abspath ../ysyxSoC)
ifeq ($(YSYXSOC),1)
YSYXSOCFULL_V = $(YSYXSOC_HOME)/build/ysyxSoCFull.v
VFILE_EXTRA += $(shell find $(YSYXSOC_HOME)/perip/ -name "*.v") $(YSYXSOCFULL_V)
EMU_FLAGS += -I$(YSYXSOC_HOME)/perip/uart16550/rtl -I$(YSYXSOC_HOME)/perip/spi/rtl
EMU_FLAGS += --timescale "1ns/1ns" --no-timing --autoflush
EMU_CFLAGS += -DYSYXSOC=1
EMU_TOP = ysyxSoCFull
NPC_MODULE_PATH = $(EMU_TOP)__DOT__asic__DOT__cpu__DOT__cpu__DOT__npc
MILL_FLAGS += --mode ysyxsoc

update-ysyxsoc: $(if $(SYNC_FREQ),$(FREQ_FILE),)
	$(MAKE) -C $(YSYXSOC_HOME) verilog

ifeq ($(HAS_NVBOARD),1)
include $(NVBOARD_HOME)/scripts/nvboard.mk
# constraint file
SRC_AUTO_BIND = $(BUILD_DIR)/auto_bind.cpp
NXDC_FILE = scripts/nvboard.nxdc
$(SRC_AUTO_BIND): $(NXDC_FILE)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

EMU_CFLAGS  += $(CXXFLAGS) -I$(INC_PATH) -DHAS_NVBOARD=1
EMU_LDFLAGS += $(LDFLAGS)
EMU_CSRCS   += $(SRC_AUTO_BIND) $(NVBOARD_ARCHIVE)
endif
else
EMU_TOP = $(TOP)
NPC_MODULE_PATH = $(EMU_TOP)__DOT__npc

update-ysyxsoc:
endif

test:
	mill -i $(PRJ).test

FREQ_FILE = $(BUILD_DIR)/freq.txt
STA_RPT = $(STA_RESULT_DIR)/$(TOP).rpt
$(STA_RPT): sta
$(FREQ_FILE): $(STA_RPT)
	grep -A2 "Freq(MHz)" $^ | tail -n 1 | sed -e 's/.*| *\([0-9\.]*\) *|$$/\1/' > $@
	touch $(YSYXSOC_HOME)/src/Top.scala

ifeq ($(SYNC_FREQ),1)
$(VFILE-sim): $(SCALA_FILES) $(FREQ_FILE)
endif

$(VFILE_PREFIX)%.sv: $(SCALA_FILES)
	$(call git_commit, "generate verilog")
	mill -i $(PRJ).runMain Elaborate --target-dir $(BUILD_DIR) --mode $* $(MILL_FLAGS) --freq-file $(FREQ_FILE)
	mv $(VFILE_PREFIX).sv $@
	sed -i -e 's/_\(aw\|ar\|w\|r\|b\)_\(\|bits_\)/_\1/g' $@
	sed -i '/firrtl_black_box_resource_files.f/, $$d' $@
	verilator --lint-only -Wall -Wno-DECLFILENAME -Wno-UNUSED -Wno-SYNCASYNCNET $@

help:
	mill -i $(PRJ).runMain Elaborate --help

reformat:
	mill -i __.reformat

checkformat:
	mill -i __.checkFormat

clean:
	-rm -rf $(BUILD_DIR)

.PHONY: test help reformat checkformat clean

ifeq ($(ENABLE_WAVE),1)
EMU_FLAGS += --trace-fst
EMU_CFLAGS += -DWAVEFORM=1
endif

EMU_CSRCS += $(abspath $(shell find src/emu -name "*.cpp"))
EMU_DIR = $(BUILD_DIR)/emu-src
EMU_NAME = emu
EMU_PATH = $(BUILD_DIR)/$(EMU_NAME)
IMG ?= ~/projectn/am-kernels/tests/cpu-tests/build/dummy-riscv32e-npc.bin

define escape_quote
  $(subst \",\\\",$(1))
endef

DIFFTEST_REF_SO_FILE = $(NEMU_HOME)/build/riscv$(XLEN)-nemu-interpreter-so
EMU_CFLAGS += -DREF_SO_FILE=\"$(DIFFTEST_REF_SO_FILE)\" -O3
VERI_EMU_CFLAGS = -DEMU_TOP=V$(EMU_TOP) -DEMU_TOP_H=\"V$(EMU_TOP).h\" -DEMU_TOP_024ROOT_H=\"V$(EMU_TOP)___024root.h\"
EMU_CFLAGS += -DNPC_MODULE_PATH=$(NPC_MODULE_PATH)
EMU_LDFLAGS += -O3
EMU_FLAGS  += -O3 --Mdir $(EMU_DIR) -CFLAGS "$(call escape_quote, $(EMU_CFLAGS) $(VERI_EMU_CFLAGS))" -LDFLAGS "$(EMU_LDFLAGS)"

verilog: $(VFILE-syn)
	cp $^ $(BUILD_DIR)/ysyx_88888888.sv
	sed -i -e 's/module $(TOP)/module ysyx_88888888/' $(BUILD_DIR)/ysyx_88888888.sv

emu-dep: update-ysyxsoc $(EMU_PATH)

$(EMU_PATH): $(EMU_CSRCS) $(VFILE-sim) $(VFILE_EXTRA)
	verilator --cc --exe --top-module $(EMU_TOP) -o $(EMU_NAME) $^ $(EMU_FLAGS)
	$(MAKE) -C $(EMU_DIR) -f V$(EMU_TOP).mk
	ln -sf $(EMU_DIR)/$(EMU_NAME) $@


GSIM_BIN ?= ~/software/gsim/build/gsim/gsim
CXX = clang++  # only support clang++14 or above

GSIM_EMU_TARGET    = $(abspath $(BUILD_DIR)/gsim)
GSIM_EMU_BUILD_DIR = $(abspath $(BUILD_DIR)/gsim-compile)

##############################################
### Running GSIM to generate cpp model
##############################################

GSIM_GEN_CSRC_DIR = $(GSIM_EMU_BUILD_DIR)/model
GSIM_FLAGS = --supernode-max-size=35

$(BUILD_DIR)/$(TOP).fir: $(VFILE-sim)

$(GSIM_GEN_CSRC_DIR)/$(TOP)0.cpp: $(BUILD_DIR)/$(TOP).fir
	@mkdir -p $(@D)
	$(GSIM_BIN) $(GSIM_FLAGS) --dir $(@D) $< | tee $(GSIM_EMU_BUILD_DIR)/gsim-gen-cpp.log

gsim-gen-cpp: $(GSIM_GEN_CSRC_DIR)/$(TOP)0.cpp

GSIM_EMU_CFLAGS += $(EMU_CFLAGS) -I$(GSIM_GEN_CSRC_DIR)
GSIM_EMU_CFLAGS += -DGSIM -DEMU_TOP=S$(EMU_TOP) -DEMU_TOP_H=\"$(EMU_TOP).h\"

# $(1): object file
# $(2): source file
# $(3): compile flags
# $(4): object file list
# $(5): extra dependency
define CXX_TEMPLATE =
$(1): $(2) $(THIS_MAKEFILE) $(5)
	@mkdir -p $$(@D) && echo + CXX $$<
	@$(CXX) $$< $(3) -c -o $$@
$(4) += $(1)
endef

# $(1): object file
# $(2): source file
# $(3): ld flags
define LD_TEMPLATE =
$(1): $(2)
	@mkdir -p $$(@D) && echo + LD $$@
	@$(CXX) $$^ $(3) -o $$@
endef

$(foreach x, $(wildcard $(GSIM_GEN_CSRC_DIR)/$(TOP)*.cpp) $(EMU_CSRCS), $(eval \
  $(call CXX_TEMPLATE, $(GSIM_EMU_BUILD_DIR)/$(basename $(notdir $(x))).o, $(x), $(GSIM_EMU_CFLAGS), GSIM_EMU_OBJS, )))

$(eval $(call LD_TEMPLATE, $(GSIM_EMU_TARGET), $(GSIM_EMU_OBJS), $(CXXFLAGS)))

gsim-run: $(GSIM_EMU_TARGET)
	taskset 0x1 $< $(IMG)

ifeq ($(GSIM),1)
sim:
	$(MAKE) gsim-gen-cpp
	$(MAKE) gsim-run
else
sim: emu-dep
	$(EMU_PATH) $(IMG)
endif

.NOTPARALLEL: emu-dep
.PHONY: verilog emu-dep sim update-ysyxsoc

sta: verilog
	$(MAKE) -C $(YOSYS_STA_HOME) sta O=$(dir $(STA_RESULT_DIR)) \
		DESIGN=$(TOP) RTL_FILES=$(VFILE-syn) \
		CLK_FREQ_MHZ=$(CLK_FREQ_MHZ) CLK_PORT_NAME=clock

.PHONY: sta

-include ../Makefile
