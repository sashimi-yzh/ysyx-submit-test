# ==============================================================================
# 全局配置
# ==============================================================================
TOPNAME = ysyxSoCFull
CORENAME = ysyx_26010036
BUILD_DIR = ./build
YSYXSOC_DIR = $(abspath ../ysyxSoC)

YOSYS_STA_DIR ?= $(abspath ./yosys-sta)
CLK_FREQ_MHZ ?= 800
CLK_PORT_NAME ?= clock
SDC_FILE ?= $(YOSYS_STA_DIR)/scripts/default.sdc

# C源码 (两者通用的基础C代码)
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -o -name "*.cc" -o -name "*.cpp")
CHDRS = $(shell find $(abspath ./csrc) -name "*.h")

.SECONDARY:
-include ../Makefile

# ==============================================================================
# 目录与生成物定义 (隔离各目标的构建环境)
# ==============================================================================
NPC_SIM_DIR = $(BUILD_DIR)/sim_npc
SOC_SIM_DIR = $(BUILD_DIR)/sim_ysyxsoc
SYN_DIR     = $(BUILD_DIR)/syn

# 各自专属的 Verilog 目标文件
NPC_SV = $(NPC_SIM_DIR)/$(TOPNAME).sv
SOC_SV = $(SOC_SIM_DIR)/$(CORENAME).sv
SYN_SV = $(BUILD_DIR)/$(CORENAME).sv


# 各自专属的 Verilator 编译产物
NPC_BIN = $(NPC_SIM_DIR)/$(TOPNAME)
SOC_BIN = $(SOC_SIM_DIR)/$(TOPNAME)

# Verilator 基础通用参数
VERILATOR_BASE_FLAGS = --cc --exe --build \
                       --timescale "1ns/1ns" \
                       --no-timing --trace-fst --autoflush \
                       -j $(shell nproc) -O3 --output-split 20000
LDFLAGS += -lreadline

# ==============================================================================
# NVBoard 专属配置 (无条件链接到 SoC 环境中)
# ==============================================================================
ifeq ($(NVBOARD_HOME),)
    $(error NVBOARD_HOME未设置，请先 export NVBOARD_HOME=<nvboard项目路径>)
endif
include $(NVBOARD_HOME)/scripts/nvboard.mk

NXDC_FILES ?= $(abspath ./constr/$(TOPNAME).nxdc)
SRC_AUTO_BIND = $(SOC_SIM_DIR)/auto_bind.cpp

# 自动生成引脚绑定文件（放入SOC专属目录）
$(SRC_AUTO_BIND): $(NXDC_FILES)
	@mkdir -p $(dir $@)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

SOC_EXTRA_CSRCS = $(SRC_AUTO_BIND)
SOC_EXTRA_LIBS  = $(NVBOARD_ARCHIVE)
SOC_EXTRA_VFLAGS = -I$(INC_PATH)

# ==============================================================================
# 1. Chisel 构建规则 (各自生成专属的 .sv)
# ==============================================================================

SCALA_SRCS = $(shell find ./src -name "*.scala")

# [纯 NPC 环境] ElaborateFull
$(NPC_SV): $(SCALA_SRCS)
	@echo "--- Generating Verilog for Pure NPC ---"
	@mkdir -p $(NPC_SIM_DIR)
	USE_YSYXSOC=1 ENABLE_DPIC=1 mill -i runMain ElaborateFull --target-dir $(NPC_SIM_DIR)
	@sh -c 'cat $(NPC_SIM_DIR)/*.v $(NPC_SIM_DIR)/*.sv > $@.tmp 2>/dev/null || true'
	@sh -c 'rm -f $(NPC_SIM_DIR)/*.v $(NPC_SIM_DIR)/*.sv'
	@mv $@.tmp $@

# [SoC 环境] ElaborateCore
$(SOC_SV): $(SCALA_SRCS)
	@echo "--- Generating Verilog for ysyxSoC ---"
	@mkdir -p $(SOC_SIM_DIR)
	USE_YSYXSOC=1 ENABLE_DPIC=1 mill -i runMain ElaborateCore --target-dir $(SOC_SIM_DIR)
	@sh -c 'cat $(SOC_SIM_DIR)/*.v $(SOC_SIM_DIR)/*.sv > $@.tmp 2>/dev/null || true'
	@sh -c 'rm -f $(SOC_SIM_DIR)/*.v $(SOC_SIM_DIR)/*.sv'
	@mv $@.tmp $@




# [Syn 综合环境] ElaborateCore, 无DPIC
$(SYN_SV): $(SCALA_SRCS)
	@echo "--- Generating Verilog for Synthesis ---"
	@mkdir -p $(SYN_DIR)
	USE_YSYXSOC=1 ENABLE_DPIC=0 mill -i runMain ElaborateCore --target-dir $(SYN_DIR)
	@sh -c 'cat $(SYN_DIR)/*.v $(SYN_DIR)/*.sv > $@.tmp 2>/dev/null || true'
	@sh -c 'rm -f $(SYN_DIR)/*.v $(SYN_DIR)/*.sv'
	@mv $@.tmp $@

verilog: $(SYN_SV)

.PHONY: verilog


# ==============================================================================
# 2. Verilator 编译规则 (生成 .out 文件)
# ==============================================================================

# [纯 NPC 编译]
$(NPC_BIN): $(NPC_SV) $(CSRCS) $(CHDRS)
	@echo "--- Building NPC with Verilator ---"
	@mkdir -p $(NPC_SIM_DIR)/obj_dir
	verilator $(VERILATOR_BASE_FLAGS) \
		--Mdir $(NPC_SIM_DIR)/obj_dir \
		-o $(abspath $@) \
		--top-module $(TOPNAME) \
		-I$(abspath $(NPC_SIM_DIR)) \
		$(NPC_SV) $(CSRCS) \
		-CFLAGS "$(CXXFLAGS) -I$(abspath ./csrc) -DUSE_YSYXSOC=0" \
		-LDFLAGS "$(LDFLAGS)"

# [SoC 编译] - 包含外设等额外依赖，以及动态引入的 NVBoard
SOC_VSRCS = $(SOC_SV) \
            $(shell find $(YSYXSOC_DIR)/perip -name "*.v") \
            $(YSYXSOC_DIR)/build/ysyxSoCFull.v

$(SOC_BIN): $(SOC_VSRCS) $(CSRCS) $(CHDRS) $(SRC_AUTO_BIND) $(SOC_EXTRA_LIBS)
	@echo "--- Building ysyxSoC with Verilator ---"
	@mkdir -p $(SOC_SIM_DIR)/obj_dir
	verilator $(VERILATOR_BASE_FLAGS) \
		--Mdir $(SOC_SIM_DIR)/obj_dir \
		-o $(abspath $@) \
		--top-module $(TOPNAME) \
		-I$(abspath $(BUILD_DIR)/verification) \
		-I$(YSYXSOC_DIR)/perip/uart16550/rtl \
		-I$(YSYXSOC_DIR)/perip/spi/rtl \
		$(SOC_VSRCS) $(CSRCS) $(SOC_EXTRA_CSRCS) $(SOC_EXTRA_LIBS) \
		-CFLAGS "$(CXXFLAGS) -I$(abspath ./csrc) -DUSE_YSYXSOC=1 $(SOC_EXTRA_VFLAGS)" \
		-LDFLAGS "$(LDFLAGS)"

# ==============================================================================
# 3. 运行伪目标与综合流程 (对外暴露的命令)
# ==============================================================================

# RTL仿真 (纯NPC)
sim: $(NPC_BIN)
	$(call git_commit, "sim RTL - NPC")
	@echo "--- Running Simulation (NPC) ---"
	$(NPC_BIN) IMG=$(IMG) BUILD=$(BUILD_DIR)

# RTL仿真 (SoC) 
sim-ysyxsoc: $(SOC_BIN)
	$(call git_commit, "sim RTL - ysyxSoC")
	@echo "--- Running Simulation (ysyxSoC) ---"
	$(SOC_BIN) IMG=$(IMG) BUILD=$(BUILD_DIR)


# Yosys 综合
syn: $(SYN_SV)
	$(call git_commit, "run yosys synthesis")
	@mkdir -p $(YOSYS_STA_DIR)/result
	@if $(MAKE) -C $(YOSYS_STA_DIR) syn \
		DESIGN=$(CORENAME) \
		RTL_FILES="$(abspath $(SYN_SV))" \
		CLK_FREQ_MHZ=$(CLK_FREQ_MHZ) \
		CLK_PORT_NAME=$(CLK_PORT_NAME) \
		SDC_FILE=$(abspath $(SDC_FILE)); then \
		echo "=> Synthesis Success."; \
	else \
		echo "=> Synthesis Failed!"; \
		exit 1; \
	fi

sta:
	$(call git_commit, "run yosys sta")
	$(MAKE) -C $(YOSYS_STA_DIR) sta \
		DESIGN=$(CORENAME) \
		RTL_FILES="$(abspath $(SYN_SV))" \
		CLK_FREQ_MHZ=$(CLK_FREQ_MHZ) \
		CLK_PORT_NAME=$(CLK_PORT_NAME) \
		SDC_FILE=$(abspath $(SDC_FILE))

clean:
	-rm -rf $(BUILD_DIR)

.PHONY: sim sim-ysyxsoc syn sta rt perf mi clean


-include ./resource/iverilog/iverilog.mk

#快捷命令
rt:
	$(MAKE) -C $(NPC_HOME)/../rt-thread-am/bsp/abstract-machine run ARCH=riscv32e-npc

rt-soc:
	$(MAKE) -C $(NPC_HOME)/../rt-thread-am/bsp/abstract-machine run ARCH=riscv32e-ysyxsoc

mi:
	$(MAKE) -C $(NPC_HOME)/../am-kernels/benchmarks/microbench run ARCH=riscv32e-npc

WORKBENCH_DIR := $(abspath ..)

env:
	@echo "正在一键导出环境变量到 ~/.bashrc..."
	@# 先清理 ~/.bashrc 中可能已经存在的旧路径，防止重复添加
	@sed -i '/export NPC_HOME=/d' ~/.bashrc
	@sed -i '/export NEMU_HOME=/d' ~/.bashrc
	@sed -i '/export AM_HOME=/d' ~/.bashrc
	@sed -i '/export NVBOARD_HOME=/d' ~/.bashrc
	@# 写入新的基于当前位置的绝对路径
	@echo 'export NPC_HOME=$(WORKBENCH_DIR)/npc' >> ~/.bashrc
	@echo 'export NEMU_HOME=$(WORKBENCH_DIR)/nemu' >> ~/.bashrc
	@echo 'export AM_HOME=$(WORKBENCH_DIR)/abstract-machine' >> ~/.bashrc
	@echo 'export NVBOARD_HOME=$(WORKBENCH_DIR)/nvboard' >> ~/.bashrc
	@echo "写入成功！"
	@echo "========================================================="
	@echo "请在终端执行以下命令使环境变量立即生效："
	@echo "source ~/.bashrc"
	@echo "========================================================="

.PHONY: rt rt-soc mi env