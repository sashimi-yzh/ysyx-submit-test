#=======================================================================================
# NPC 仿真工程主 Makefile
#=======================================================================================

#---------------- 1. 环境检查 ----------------
ifeq ($(wildcard $(NPC_HOME)/vsrc/cpu.v),)
  $(error [ERROR] NPC_HOME=$(NPC_HOME) is not a valid NPC repo)
endif

#---------------- 2. 共有目录与全局配置 ----------------
BUILD_DIR  = $(NPC_HOME)/build
LOG_DIR    = $(BUILD_DIR)/log
WAVE_DIR   = $(LOG_DIR)
OBJ_DIR    = $(BUILD_DIR)/obj_dir
IVER_DIR   = $(BUILD_DIR)/iverilog

# 这里的 shell mkdir 放在此处确保所有子模块都能找到目录
$(shell mkdir -p $(LOG_DIR) $(WAVE_DIR) $(IVER_DIR) $(OBJ_DIR))

# 加载自动生成的配置
-include $(NPC_HOME)/include/config/auto.conf
-include $(NPC_HOME)/include/config/auto.conf.cmd

#---------------- 3. 共有源文件处理 ----------------
# 合并后的单 Verilog 文件，供 SoC 综合及 NPC 仿真使用
NPC_VSRC    := $(BUILD_DIR)/ysyx_25050136.v
COMMON_VSRC := vsrc/config.v $(filter-out vsrc/config.v, $(wildcard vsrc/*.v))

$(NPC_VSRC): $(COMMON_VSRC)
	@echo "合成verilog文件 $@"
	@cat $^ > $@

verilog: $(NPC_VSRC)

#---------------- 4. 引入子模块 ----------------
include scripts/soc.mk
include scripts/npc.mk
include scripts/config.mk
#---------------- 5. 共有辅助目标 ----------------
.DEFAULT_GOAL := help

help:
	@echo "NPC 仿真工程使用指南:"
	@echo "  make menuconfig            配置 NPC 仿真选项"
	@echo "  make run                   使用 Verilator 运行 SoC 仿真 (默认)"
	@echo "  make wave                  运行 SoC 仿真并打开波形 (FST)"
	@echo "  make gdb                   使用 Verilator 运行 SoC 仿真并启动 GDB 调试"
	@echo "  make sim-iverilog          使用 Iverilog 运行 NPC 行为级仿真"
	@echo "  make sim-iverilog-netlist  使用 Iverilog 运行 NPC 门级仿真"
	@echo "  make perf                  运行性能测试并启动 yosys-sta 分析"
	@echo "  make verilog               生成合并后的 ysyx_xxxx.v 文件"
	@echo "  make clean                 清理 build 目录"
	@echo "  make help                  显示此帮助信息"

clean:
	rm -rf $(BUILD_DIR)
	@echo "Cleaned build artifacts."

.PHONY: help clean verilog