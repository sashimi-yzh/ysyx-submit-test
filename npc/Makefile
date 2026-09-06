# 公共配置
NPC_HOME ?= $(CURDIR)
VERILATOR = verilator
VERILATOR_FLAGS = --trace --prof-exec --cc --MMD --exe --build --autoflush 
YSYXSOC_HOME ?= $(YSYX_HOME)/ysyxSoC
SOCPATH = $(YSYXSOC_HOME)
SOC_FULL_V = $(SOCPATH)/build/ysyxSoCFull.v
MK_SOC_SCRIPT = $(abspath ./scripts/mk_soc.py)
INCLUDE_PATH = $(abspath ./include/)
VERILATOR_INCLUDE_PATH = $(abspath ./vsrc/include/)

VSRC = $(shell find $(abspath ./vsrc/) -name "*.v")
CSRC = $(shell find $(abspath ./csrc/) -name "*.cpp")
HEADFILE = $(shell find $(INCLUDE_PATH) -name "*.h")
LLVMFLAGS = $(subst -D__STDC_FORMAT_MACROS,,$(shell llvm-config --cxxflags))

BASE_CFLAGS = $(patsubst %, --CFLAGS "-I%", $(INCLUDE_PATH)) \
              $(patsubst %, --CFLAGS "%", $(LLVMFLAGS)) \
              $(patsubst %, --LDFLAGS "%", $(shell llvm-config --libs))

VERILATOR_FLAGS += --timescale "1ns/1ns" --no-timing

# 目标配置
# BUILD_MODE: npc / ysyxsoc / ysyxsoc_nvboard
# 默认第三种：ysyxsoc + nvboard
BUILD_MODE ?= ysyxsoc_nvboard

-include $(NVBOARD_HOME)/scripts/nvboard.mk

# 检查 BUILD_MODE 合法性
VALID_BUILD_MODES := npc ysyxsoc ysyxsoc_nvboard release
ifeq ($(filter $(BUILD_MODE),$(VALID_BUILD_MODES)),)
	$(error Invalid BUILD_MODE '$(BUILD_MODE)'. \
	Valid values: npc, ysyxsoc, ysyxsoc_nvboard. \
	Usage: make BUILD_MODE=npc run  or  make BUILD_MODE=ysyxsoc run  or  make BUILD_MODE=ysyxsoc_nvboard run)
endif

ifeq ($(BUILD_MODE),npc)
  TOPNAME = npc
  NVBOARD_ENABLE = 0
	VERILATOR_FLAGS += -D__NPC__
	BASE_CFLAGS += --CFLAGS -D__NPC__
	VSRC += ./vsrc-extra/npc.v
endif

ifeq ($(BUILD_MODE),ysyxsoc)
  TOPNAME = ysyxSoCFull
  NVBOARD_ENABLE = 0

	VERILATOR_FLAGS += -D__YSYXSOC__ -D__UART_TO_CONSOLE__
	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/uart16550/rtl
	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/spi/rtl
	VSRC += $(shell find $(SOCPATH)/perip -name "*.v")
	VSRC += $(SOCPATH)/build/ysyxSoCFull.v
endif

# nvboard 部分
NXDC_FILES = $(NPC_HOME)/constr/ysyxSoCFull.nxdc
SRC_AUTO_BIND = $(NPC_HOME)/constr/auto_bind.cpp

ifeq ($(BUILD_MODE),ysyxsoc_nvboard)
  TOPNAME = ysyxSoCFull
  NVBOARD_ENABLE = 1

	VERILATOR_FLAGS += -D__YSYXSOC__
  	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/uart16550/rtl
	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/spi/rtl
	VSRC += $(shell find $(SOCPATH)/perip -name "*.v")
	VSRC += $(SOCPATH)/build/ysyxSoCFull.v

	CSRC += $(SRC_AUTO_BIND)
	BASE_CFLAGS += --CFLAGS -D__NVBOARD__
	BASE_CFLAGS += $(patsubst %, --CFLAGS "-I%", $(INC_PATH))
	LDFLAGS += -lSDL2 -lSDL2_image -lSDL2_ttf
endif

ifeq ($(BUILD_MODE),release)
  TOPNAME = ysyxSoCFull 
  NVBOARD_ENABLE = 1

	VERILATOR_FLAGS += -D__YSYXSOC__
  	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/uart16550/rtl
	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/spi/rtl
	VSRC = ./build/ysyx_24100007.v
	VSRC += $(shell find $(SOCPATH)/perip -name "*.v")
	VSRC += $(SOCPATH)/build/ysyxSoCFull.v

	CSRC += $(SRC_AUTO_BIND)
	BASE_CFLAGS += --CFLAGS -D__NVBOARD__
	BASE_CFLAGS += $(patsubst %, --CFLAGS "-I%", $(INC_PATH))
	LDFLAGS += -lSDL2 -lSDL2_image -lSDL2_ttf
endif

BUILDDIR = ./build/$(BUILD_MODE)
OBJDIR = $(BUILDDIR)/obj_dir
BIN = $(BUILDDIR)/$(TOPNAME)
NEEDS_SOC_PATCH := $(or $(findstring soc,$(BUILD_MODE)),$(filter release,$(BUILD_MODE)))

$(shell mkdir -p $(BUILDDIR))

VERILATOR_INCLUDE = $(patsubst %, -I%, $(VERILATOR_INCLUDE_PATH))

.PHONY: mk_soc
mk_soc: $(SOC_FULL_V) $(MK_SOC_SCRIPT)
	python3 $(MK_SOC_SCRIPT) $(SOC_FULL_V)

ifneq ($(NEEDS_SOC_PATCH),)
$(BIN): mk_soc
endif

$(BIN): $(VSRC) $(CSRC) $(HEADFILE) $(if $(filter 1,$(NVBOARD_ENABLE)),$(NVBOARD_ARCHIVE) $(SRC_AUTO_BIND))
	$(VERILATOR) $(VERILATOR_FLAGS) \
		$(VSRC) $(CSRC) \
		$(if $(filter 1,$(NVBOARD_ENABLE)),$(NVBOARD_ARCHIVE)) \
		$(BASE_CFLAGS) \
		$(VERILATOR_INCLUDE) \
		--top-module $(TOPNAME) \
		--Mdir $(OBJDIR) --exe -o $(abspath $(BIN)) \
		$(if $(filter 1,$(NVBOARD_ENABLE)),$(patsubst %, --LDFLAGS %, $(LDFLAGS)))

# 自动生成引脚绑定文件
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

run: $(BIN)
	$(BIN) $(ARGS)

clean:
	rm -rf ./build/$(CLEAN_MODE)

sim:
	@if [ -f ./gtkwave.tcl ]; then \
		gtkwave ./wave.vcd --tcl_init ./gtkwave.tcl & \
	else \
		gtkwave ./wave.vcd & \
	fi

VPI_CC ?= $(CC)
IVERILOG ?= iverilog
IVERILOG_BIN ?= $(shell command -v $(IVERILOG) 2>/dev/null)
IVERILOG_ROOT ?= $(if $(IVERILOG_BIN),$(abspath $(dir $(IVERILOG_BIN))/..))
IVERILOG_INCLUDE ?= $(if $(IVERILOG_ROOT),$(IVERILOG_ROOT)/include/iverilog)
VVP_CMD ?= $(if $(IVERILOG_ROOT),$(IVERILOG_ROOT)/bin/vvp,vvp)
VPI_CFLAGS ?= -fPIC -shared
VVP_SRC = $(NPC_HOME)/csrc-extra/iverilog-npc-rtc.c
VVP = $(NPC_HOME)/build/iverilog-npc-rtc.vpi
VPI_MODULE = $(basename $(notdir $(VVP)))
VPI_IVERILOG_FLAGS = -L$(dir $(VVP)) -m$(VPI_MODULE)
VPI_VVP_FLAGS = -M$(dir $(VVP)) -m$(VPI_MODULE)
VERILOG_OUT = $(NPC_HOME)/build/ysyx_24100007.v
IVG_SIM_BIN = $(NPC_HOME)/build/npc_ivg
IVG_TOP = $(NPC_HOME)/vsrc-extra/ivg_top.v
NPC_WRAPPER_V = $(NPC_HOME)/vsrc-extra/npc.v
BIN_IVG = $(NPC_HOME)/bin.ivg
IVG_BIN_DEFINE = -DBIN_IVG=\"$(BIN_IVG)\"
VERILOG_ORDER = \
	vsrc/ysyx_24100007.v \
	vsrc/exu/ysyx_24100007_alucontrol.v \
	vsrc/exu/ysyx_24100007_alu.v \
	vsrc/exu/ysyx_24100007_brachcontrol.v \
	vsrc/exu/ysyx_24100007_exu.v \
	vsrc/idu/ysyx_24100007_control_unit.v \
	vsrc/idu/ysyx_24100007_decoder.v \
	vsrc/idu/ysyx_24100007_idu.v \
	vsrc/idu/ysyx_24100007_transmit.v \
	vsrc/ifu/ysyx_24100007_icache.v \
	vsrc/ifu/ysyx_24100007_ifu.v \
	vsrc/ifu/ysyx_24100007_pcreg.v \
	vsrc/lsu/ysyx_24100007_ifucfg.v \
	vsrc/lsu/ysyx_24100007_lsu.v \
	vsrc/lsu/ysyx_24100007_memreadlen.v \
	vsrc/lsu/ysyx_24100007_memwritelen.v \
	vsrc/lsu/ysyx_24100007_wbucfg.v \
	vsrc/reg/ysyx_24100007_regheap.v \
	vsrc/reg/ysyx_24100007_registers.v \
	vsrc/tools/sext/ysyx_24100007_sext.v \
	vsrc/tools/ysyx_24100007_arbiter.v \
	vsrc/tools/ysyx_24100007_clint.v \
	vsrc/wbu/ysyx_24100007_wbu.v \
	vsrc/ysyx_24100007_core.v
verilog: $(VERILOG_OUT)

$(VVP): $(VVP_SRC)
	@test -n "$(strip $(IVERILOG_INCLUDE))" || { echo "Unable to locate Icarus headers; set IVERILOG_INCLUDE" >&2; exit 1; }
	$(VPI_CC) $(VPI_CFLAGS) -I"$(IVERILOG_INCLUDE)" -o "$@" "$<"

vpi: $(VVP)

$(VERILOG_OUT):
	@mkdir -p $(dir $(VERILOG_OUT))
	@echo + Merging vsrc/*.v into $(VERILOG_OUT)
	@( for f in $(VERILOG_ORDER); do cat "$$f"; echo; done ) > $(VERILOG_OUT)

ivg: $(VVP) $(VERILOG_OUT)
	@if [ -n "$(IVG)" ]; then \
		ln -sf "$(IVG)" "$(BIN_IVG)"; \
	fi
	$(IVERILOG) $(VPI_IVERILOG_FLAGS) -D__NPC__ $(IVG_BIN_DEFINE) -o $(IVG_SIM_BIN) -g2012 \
		$(VERILOG_OUT) \
		$(IVG_TOP) \
		$(NPC_WRAPPER_V)
	$(VVP_CMD) $(VPI_VVP_FLAGS) $(IVG_SIM_BIN)

$(BIN_IVG): $(IMG)
	@if [ -z "$(IMG)" ]; then echo "Error: IMG=xxx.bin required"; exit 1; fi
	@echo Converting $(IMG) to readmemh format
	@(echo "@0"; xxd -p -c 0 $(IMG) | sed 's/\(..\)/\1 /g') > $(BIN_IVG)

sim-iverilog: $(IMG) $(BIN_IVG) $(VERILOG_OUT) $(VVP)
	$(IVERILOG) $(VPI_IVERILOG_FLAGS) -D__NPC__ $(IVG_BIN_DEFINE) -o $(IVG_SIM_BIN) -g2012 \
		$(VERILOG_OUT) \
		$(IVG_TOP) \
		$(NPC_WRAPPER_V)
	$(VVP_CMD) $(VPI_VVP_FLAGS) $(IVG_SIM_BIN)

CELLS_V = $(if $(CELLS),$(shell find $(CELLS) -name "*.v" 2>/dev/null),)
sim-iverilog-netlist: $(IMG) $(BIN_IVG) $(NETLIST) $(VVP)
	$(IVERILOG) $(VPI_IVERILOG_FLAGS) $(IVG_BIN_DEFINE) -o $(IVG_SIM_BIN) -g2012 \
		$(CELLS_V) \
		$(NETLIST) \
		$(IVG_TOP) \
		$(NPC_WRAPPER_V)
	$(VVP_CMD) $(VPI_VVP_FLAGS) $(IVG_SIM_BIN)

BUILDDIR_NETLIST = ./build/netlist
OBJDIR_NETLIST = $(BUILDDIR_NETLIST)/obj_dir
BIN_NETLIST = $(BUILDDIR_NETLIST)/npc

$(shell mkdir -p $(BUILDDIR_NETLIST))

sim-verilator-netlist: $(BIN_NETLIST) $(IMG)
	@if [ -z "$(IMG)" ]; then echo "Error: IMG=xxx.bin required"; exit 1; fi
	$(BIN_NETLIST) $(ARGS) -f $(IMG) -e

$(BIN_NETLIST): $(NETLIST) $(CSRC) $(HEADFILE)
	@if [ -z "$(NETLIST)" ]; then echo "Error: NETLIST=path/to/netlist.v required"; exit 1; fi
	rm -rf $(OBJDIR_NETLIST)
	mkdir -p $(OBJDIR_NETLIST)
	$(VERILATOR) $(VERILATOR_FLAGS) -Wno-UNOPTFLAT -fno-inline \
		$(CELLS_V) \
		$(NETLIST) \
		$(NPC_WRAPPER_V) \
		$(CSRC) \
		$(BASE_CFLAGS) \
		$(VERILATOR_INCLUDE) \
		--CFLAGS -D__NPC__ \
		--top-module npc \
		--Mdir $(OBJDIR_NETLIST) --exe -o $(abspath $(BIN_NETLIST))
	

check:
	$(VERILATOR) --lint-only --top-module ysyx_24100007 -Wall -Wno-UNUSEDSIGNAL -Wno-DECLFILENAME $(NPC_HOME)/release/ysyx_24100007.v

perf:
	python3 show-perf-table.py ./performance.txt

.PHONY: run clean sim vpi npc ysyxsocys yxsoc-nvboard check release sim-verilator-netlist sim-iverilog-netlist
