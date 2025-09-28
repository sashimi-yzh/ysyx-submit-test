ENABLE_YSYXSOC ?= 1
ARGS ?= --log=$(BUILD_DIR)/log.txt

ifeq ($(ENABLE_YSYXSOC), 1)
TOPNAME = ysyxSoCFull
VSRCS += $(shell find $(abspath ../ysyxSoC/perip) -name "*.v")
VSRCS += $(abspath ../ysyxSoC/build/ysyxSoCFull.v)
INCDIR += "$(abspath ../ysyxSoC/perip/uart16550/rtl)"
INCDIR += "$(abspath ../ysyxSoC/perip/spi/rtl)"
CXXFLAGS += -DYSYXSOC=1
VERILATOR_FLAGS += -DYSYXSOC=1
override ARGS += --diff=$(NEMU_HOME)/build/riscv32-nemu-interpreter-so-ysyxsoc
else
TOPNAME = ysyx_23060203
VERILATOR_FLAGS += -DUSE_DPIC_RAM=1
override ARGS += --diff=$(NEMU_HOME)/build/riscv32-nemu-interpreter-so
endif

NXDC_FILES = constr/top.nxdc
INC_PATH = $(abspath ./csrc/include)

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc --trace \
					-O3 --x-assign fast --x-initial fast --noassert
VERILATOR_FLAGS += -DNPC_DEBUG=1 --timescale "1ns/1ns" --no-timing --autoflush

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

$(shell mkdir -p $(BUILD_DIR))

# project source
VSRCS_LOCAL = $(shell find $(abspath ./vsrc) -name "*.sv")
VSRCS += $(VSRCS_LOCAL)
CSRCS += $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
INCDIR += "$(abspath ./vsrc)"

# rules for verilator
INCFLAGS = $(addprefix -I , $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -Wall -Werror \
					  -DTOP_NAME="\"V$(TOPNAME)\"" \
						-fmacro-prefix-map=/home/cmdblock/ysyx/ysyx-workbench/npc/csrc=

# ---------- c++ testbench function switch ----------

ENABLE_SDB ?= 0
ifeq ($(ENABLE_SDB), 1)
LDFLAGS += -lreadline
CXXFLAGS += -DSDB=1
endif

ENABLE_ITRACE ?= 0
ifeq ($(ENABLE_ITRACE), 1)
CXXFLAGS += $(shell llvm-config --cxxflags) -fPIE -DITRACE=1
LDFLAGS += $(shell llvm-config --libs)
endif

# ---------- nvboard ----------

ENABLE_NVBOARD ?= 0
ifeq ($(ENABLE_NVBOARD), 1)
include $(NVBOARD_HOME)/scripts/nvboard.mk
# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@
CSRCS += $(SRC_AUTO_BIND)
CXXFLAGS += -DNVBOARD=1
endif

# ---------- verilator compile ----------

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE) $(shell find $(abspath ./csrc) -name "*.h")
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) \
		$(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE) \
		$(addprefix -y , $(INCDIR)) \
		$(addprefix -CFLAGS , $(CXXFLAGS)) \
		$(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN)) \
		$(VERILATOR_FLAGS)

default: $(BIN)

all: default

clean:
	rm -rf $(BUILD_DIR)

# ---------- verilator bin run ----------

# override ARGS += --wave=$(BUILD_DIR)/wave.vcd
override ARGS += --pctrace=$(BUILD_DIR)/pctrace
IMG ?=
ifdef ELF
override ARGS += --elf=$(ELF)
endif

sim: $(BIN)
	$(call git_commit, "sim RTL")
	$(BIN) $(ARGS) $(IMG)

run: $(BIN)
	$(call git_commit, "sim RTL")
	@git rev-parse HEAD
	$(BIN) $(ARGS) $(IMG)

# ---------- synthesis ----------

SV2V = tools/sv2v
VAIO = $(BUILD_DIR)/$(STUID).v
$(VAIO): $(VSRCS_LOCAL)
	$(SV2V) --top=$(STUID) -DYSYXSOC=1 $(VSRCS_LOCAL) > $(VAIO)

verilog: $(VAIO)

sta: $(VAIO)
	make -C ../yosys-sta sta DESIGN=$(STUID) CLK_FREQ_MHZ=500 \
		CLK_PORT_NAME=clock RTL_FILES=$(abspath $(VAIO))

# ---------- iverilog simulation ----------

iverilog-hex:
	xxd -c1 -p $(IMG) $(BUILD_DIR)/img.hex

IVERILOG_TB = test/iverilog_tb.sv
IVERILOG_VVP = $(BUILD_DIR)/iverilog_vvp
$(IVERILOG_VVP): $(VAIO) $(IVERILOG_TB)
	iverilog -g2012 -o $(IVERILOG_VVP) $(IVERILOG_TB) $(VAIO)

sim-iverilog: $(IVERILOG_VVP) iverilog-hex
	vvp $(IVERILOG_VVP)

IVERILOG_NETLIST_VVP = $(BUILD_DIR)/iverilog_netlist_vvp
$(IVERILOG_NETLIST_VVP): $(IVERILOG_TB)
	iverilog -g2012 -o $(IVERILOG_NETLIST_VVP) $(CELLS) $(IVERILOG_TB) $(NETLIST)

sim-iverilog-netlist: $(IVERILOG_NETLIST_VVP) iverilog-hex
	vvp $(IVERILOG_NETLIST_VVP)

.PHONY: default all clean sim run verilog sta\
		iverilog-hex sim-iverilog

include ../Makefile
