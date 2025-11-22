# 项目模块名称
ARCH = riscv32e-npc
ifeq ($(ARCH), riscv32e-ysyxsoc)
TOP_MODULE = ysyxSoCFull
YOSYS_TOP = ysyx_25010030
CXXFLAGS += -DYSYXSOC
NXDC_FILES = ./constr/ysyxSoCFull.nxdc
else ifeq ($(ARCH), riscv32e-npc)
TOP_MODULE = ysyx_25010030_npc
CXXFLAGS += -DNPC
YOSYS_TOP = ysyx_25010030
else
$(error 不支持的架构：$(ARCH).支持的架构: riscv32e-ysyxsoc, riscv32e-npc)
endif

nvboard ?= 1
diff ?= 0
# 源文件路径和定义
# NPC_HOME = /home/furina/ysyx-workbench/npc
# NVBOARD_HOME = /home/furina/ysyx-workbench/nvboard
# SOC_HOME = /home/furina/ysyx-workbench/ysyxSoC
ifeq ($(ARCH), riscv32e-ysyxsoc)
CSRCS = $(shell find $(abspath ./pipeline-soc-csrc) -name "*.cpp")  #可修改
VSRCS = $(shell find $(abspath ./pipeline-soc-vsrc) -name "*.v")
VSRCS += $(shell find $(abspath ../ysyxSoC/perip) -name "*.v")
VSRCS += ../ysyxSoC/build/ysyxSoCFull.v 

else
ifeq ($(ARCH), riscv32e-npc)
CSRCS = $(shell find $(abspath ./pipeline-soc-csrc) -name "*.cpp") #可修改
VSRCS = $(shell find $(abspath ./pipeline-soc-vsrc) -name "*.v")   
# VSRCS = $(shell find $(abspath ./build) -name "*.v")
VSRCS += $(shell find $(abspath ./simple-SoC) -name "*.v")
endif
endif

VVP = vvp
VERILATOR = verilator
VERILATOR_FLAGS += -cc --exe
VERILATOR_FLAGS += -MMD
VERILATOR_FLAGS += --trace
VERILATOR_FLAGS += -Wno-STMTDLY -Wno-MODDUP -Wno-fatal

BUILD_DIR = ./build
IVERILOG = iverilog
IVERILOG_DIR = $(BUILD_DIR)/iverilog
WAVEFORM = $(IVERILOG_DIR)/waveform.fst
WAVEFORM_NETLIST = $(IVERILOG_DIR)/waveform_netlist.fst
MEM_INIT = $(IVERILOG_DIR)/mem_init.hex

IMG ?=
# IMG ?= ../am-kernels/benchmarks/microbench/build/microbench-riscv32e-npc.bin

CELLS ?= ../yosys-sta/nangate45/sim/cells.v
NETLIST ?= ../yosys-sta/result/ysyx_25010030-250MHz/ysyx_25010030.netlist.fixed.v
IVERILOG_BIN = $(IVERILOG_DIR)/sim
IVERILOG_BIN_NETLIST = $(IVERILOG_DIR)/sim_netlist
IVERILOG_FLAGS += -Wall -g2012 -s sim_top -o $(IVERILOG_BIN) \
    -I./pipeline-soc-vsrc \
	-DNPC \
    -DWAVE=$(WAVE) \
    -DMEM_INIT_PATH=\"$(MEM_INIT)\" \
    -DWAVEFORM_PATH=\"$(WAVEFORM)\"

IVERILOG_NETLIST_FLAGS += -Wall -g2012 -s sim_top -o $(IVERILOG_BIN) \
    -I./pipeline-soc-vsrc \
	-DNPC \
    -DWAVE=$(WAVE) \
    -DMEM_INIT_PATH=\"$(MEM_INIT)\" \
    -DWAVEFORM_PATH=\"$(WAVEFORM_NETLIST)\"
	
WAVE ?= 0
ifeq ($(WAVE), 1)
IVERILOG_VVP_FLAGS = -lxt2  # 生成波形文件
else
IVERILOG_VVP_FLAGS =        # 不生成波形文件
endif

VERILOG_MERGED = $(BUILD_DIR)/ysyx_25010030.v
$(VERILOG_MERGED): $(wildcard ./pipeline-soc-vsrc/*.v) $(wildcard ./pipeline-soc-vsrc/*.vh)
	@echo "Merging core Verilog files into $@..."
# 	@echo "// Merged Verilog file with PC reset value 0x30000000" > $@
# 	@echo \`define RESET_VAL 0 >> $@
	@echo \`define __ICARUS__ 0 >> $@
	@echo "" >> $@
	
	@for file in $(wildcard ./pipeline-soc-vsrc/*.vh); do \
		echo "// Included from $$file" >> $@; \
		cat $$file >> $@; \
		echo "" >> $@; \
	done
	
	@for file in $(wildcard ./pipeline-soc-vsrc/*.v); do \
		echo "// Included from $$file" >> $@; \
		cat $$file | sed -e '/`include "ysyx_25010030_define.vh"/d' >> $@; \
		echo "" >> $@; \
	done

$(IVERILOG_BIN): ARCH=riscv32e-npc
$(IVERILOG_BIN): TOPNAME=ysyx_25010030_npc
$(IVERILOG_BIN): $(VERILOG_MERGED) \
                 $(wildcard ./simple-SoC/*.v) \
                 ./sim_top.v
	@echo "Building iverilog simulation for NPC architecture..."
	$(IVERILOG) $(IVERILOG_FLAGS) $^

$(IVERILOG_BIN_NETLIST): ARCH=riscv32e-npc
$(IVERILOG_BIN_NETLIST): TOPNAME=ysyx_25010030_npc
$(IVERILOG_BIN_NETLIST): $(NETLIST) \
                         $(CELLS) \
                 		 $(wildcard ./simple-SoC/*.v) \
                         ./sim_top.v
	@echo "Building iverilog netlist simulation (NETLIST=$(NETLIST), CELLS=$(CELLS))..."
	$(IVERILOG) $(IVERILOG_NETLIST_FLAGS) \
		-DWAVEFORM_PATH=\"$(WAVEFORM_NETLIST)\" \
		-o $@ $^

$(MEM_INIT): $(IMG)
	@echo "Generating memory init from BIN..."
	riscv64-linux-gnu-objcopy -I binary -O verilog --adjust-vma=-0x00000000 $^ $@

ifeq ($(ARCH), riscv32e-ysyxsoc)
VERILATOR_FLAGS += +incdir+../ysyxSoC/perip/uart16550/rtl +incdir+../ysyxSoC/perip/spi/rtl 
VERILATOR_FLAGS += --timescale "1ns/1ns" --no-timing
VERILATOR_FLAGS += -DYSYXSOC
else
VERILATOR_FLAGS += -DNPC
endif
VERILATOR_FLAGS += --build -Mdir $(OBJ_DIR)
VERILATOR_FLAGS += -I$(NPC_HOME)/pipeline-soc-vsrc #可修改

dcache ?= 0
fpu ?= 0
ifeq ($(dcache), 1)
VERILATOR_FLAGS += -DDCACHE
endif
ifeq ($(fpu), 1)
VERILATOR_FLAGS += -DFPU
CXXFLAGS += -DFPU
endif

ifeq ($(diff), 1)
VERILATOR_FLAGS += -DDIFFTEST
CXXFLAGS += -DCONFIG_DIFFTEST
endif

OBJ_DIR = ./obj_dir
BIN = $(OBJ_DIR)/V$(TOP_MODULE)

INC_PATH = $(NPC_HOME)/include/
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOP_MODULE)\""
CXXFLAGS += -g

# 链接的库
LIBS = -lreadline  # 链接 readline 库, 命令行交互库
LIBS += -ldl       # 链接 dlfcn 库, 动态链接库
LIBS += -lSDL2     # 添加 SDL2 库链接, 图形显示库
LIBS += -lSDL2_image
LDFLAGS += $(LIBS)

ifeq ($(diff), 1)
DIFF_REF_PATH = $(NEMU_HOME)/build
DIFF_REF_SO = $(DIFF_REF_PATH)/riscv32-nemu-interpreter-so
ARGS_DIFF = --diff=$(DIFF_REF_SO)
endif

$(DIFF_REF_SO):
	$(MAKE) -s -C $(DIFF_REF_PATH)

# 参数设置

override ARGS ?= --log=$(OBJ_DIR)/npc-log.txt
override ARGS += $(ARGS_DIFF)
NPC_EXEC = $(BIN) $(ARGS) $(IMG)

ifdef mainargs
ASFLAGS += -DBIN_PATH=\"$(mainargs)\"
# @echo "### Get mainargs ###"
endif

default: $(BIN)
$(shell mkdir -p $(OBJ_DIR) $(BUILD_DIR) $(IVERILOG_DIR))

ifeq ($(ARCH), riscv32e-ysyxsoc)
ifeq ($(nvboard), 1)
CXXFLAGS += -DNVBOARD
SRC_AUTO_BIND = $(abspath $(OBJ_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	@echo "### 生成NVBoard引脚绑定代码 ###"
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@
include $(NVBOARD_HOME)/scripts/nvboard.mk
CSRCS += $(SRC_AUTO_BIND)
endif
endif

.PHONY: sim-iverilog sim-iverilog-netlist
sim-iverilog: $(MEM_INIT) $(IVERILOG_BIN)
	@echo "Running iverilog simulation $(IMG) (WAVE=$(WAVE))..."
	$(VVP) -n $(IVERILOG_BIN) $(IVERILOG_VVP_FLAGS)
	@if [ $(WAVE) -eq 1 ] && [ -f $(WAVEFORM) ]; then \
		echo "Waveform: $(WAVEFORM)"; \
	fi

sim-iverilog-netlist: $(MEM_INIT) $(IVERILOG_BIN_NETLIST)
	@echo "Running iverilog netlist simulation (WAVE=$(WAVE))..."
	$(VVP) -n $(IVERILOG_BIN_NETLIST) $(IVERILOG_VVP_FLAGS)
	@if [ $(WAVE) -eq 1 ] && [ -f $(WAVEFORM_NETLIST) ]; then \
		echo "Netlist Simulation Waveform: $(WAVEFORM_NETLIST)"; \
	fi

# 伪目标：仿真
.PHONY: sim
sim: wave.vcd

# 伪目标：查看波形
.PHONY: waves
waves: wave.vcd
	@echo
	@echo "### WAVES ###"
	gtkwave wave.vcd

#生成波形文件
.PHONY: wave.vcd
wave.vcd: $(BIN)
	@echo
	@echo "### SIMULATING ###"
	@$(BIN) #+verilator+rand+reset+2

yosys:
ifeq ($(ARCH), riscv32e-ysyxsoc)
	cd $(NPC_HOME)/../yosys-sta && make sta DESIGN=$(YOSYS_TOP) \
											SDC_FILE=$(NPC_HOME)/npc.sdc \
											RTL_FILES="$(shell find $(NPC_HOME)/pipeline-soc-vsrc -name "*.v")" \
											CLK_FREQ_MHZ=200 \
											INCLUDE_PATH=$(NPC_HOME)/pipeline-soc-vsrc
else
	cd $(NPC_HOME)/../yosys-sta && make sta DESIGN=$(YOSYS_TOP) \
											SDC_FILE=$(NPC_HOME)/npc.sdc \
											RTL_FILES="$(shell find $(NPC_HOME)/build -name "ysyx_25010030.v")" \
											CLK_FREQ_MHZ=250 
endif
	cd $(NPC_HOME)

yosys-clean:
	cd $(NPC_HOME)/../yosys-sta && make clean
	cd $(NPC_HOME)

# 伪目标：运行环境准备
.PHONY: run-env
run-env: $(BIN) $(DIFF_REF_SO)

# 伪目标：运行仿真
.PHONY: run
run: run-env
	$(NPC_EXEC)

.PHONY: verilog
verilog: $(VERILOG_MERGED)
	@echo "Generated merged Verilog file: $(VERILOG_MERGED)"

# 伪目标：调试
.PHONY: gdb
gdb: run-env
	gdb -s $(BIN) --args $(NPC_EXEC)

# 伪目标：构建
.PHONY: build
build: $(BIN)

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE) $(SRC_AUTO_BIND)
# 	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module $(TOP_MODULE) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))


# 伪目标：Lint 检查
.PHONY: lint
lint: 
	verilator --lint-only -Wall $(shell find $(abspath ./pipeline-soc-vsrc) -name "*.v") \
			-I$(NPC_HOME)/pipeline-soc-vsrc

# 伪目标：清理
.PHONY: clean
clean:
	rm -rf .stamp.*
	rm -rf $(OBJ_DIR)
	rm -rf $(BUILD_DIR)
	rm -rf wave.vcd
	rm -rf ./log/*
	rm -rf mtrace.log

.PHONY: wave
wave:
	gtkwave wave.vcd