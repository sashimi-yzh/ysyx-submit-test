# ===== 顶层网表仿真Makefile =====
# 目录配置
BUILD_DIR    := build
NETLIST_BUILD := $(BUILD_DIR)/netlist_sim

SYNTH_DIR    := synth
LIB_DIR      := lib/nangate45/sim
SIM_DIR      := sim

# 顶层Testbench
TOP_TB       := testbench

# 网表仿真源文件
NETLIST_SRCS := \
	$(SYNTH_DIR)/ysyx_24100006.netlist.syn.v \
	$(SIM_DIR)/ysyx_24100006_mem.v \
	$(SIM_DIR)/ysyx_24100006_uart.v \
	$(SIM_DIR)/testbench.v \
	$(LIB_DIR)/cells.v

# 预处理宏
DEFINES := -D__ICARUS__ -DNPC -DNETLIST_SIM

# RISC-V 工具链配置
OBJCOPY  ?= riscv64-unknown-elf-objcopy
NM       ?= riscv64-unknown-elf-nm
VMA_BASE ?= 0x80000000

# 程序配置
mainargs ?=

# 波形配置
WAVE ?= 0
WAVE_FILE ?= wave.vcd

# 仿真器输出
NETLIST_VVP := $(NETLIST_BUILD)/netlist_sim.vvp

.PHONY: all netlist-run netlist-build clean help

# 默认目标
all: help

# 显示帮助信息
help:
	@echo "================================================"
	@echo "          网表仿真系统 - 使用说明"
	@echo "================================================"
	@echo ""
	@echo "基本用法:"
	@echo "  make netlist-run ELF=<程序路径> [mainargs=<参数>] [WAVE=1]"
	@echo ""
	@echo "具体命令:"
	@echo "  make netlist-build              # 编译网表仿真器"
	@echo "  make netlist-run ELF=path/to/program.elf"
	@echo "  make netlist-run ELF=path/to/program.elf mainargs=t"
	@echo "  make netlist-run ELF=path/to/program.elf WAVE=1    # 生成波形"
	@echo "  make netlist-run ELF=path/to/program.elf WAVE=1 WAVE_FILE=custom.vcd"
	@echo "  make clean                      # 清理构建文件"
	@echo ""
	@echo "波形选项:"
	@echo "  WAVE=1          启用波形生成（默认：0）"
	@echo "  WAVE_FILE=name  指定波形文件名（默认：wave.vcd）"
	@echo ""
	@echo "示例:"
	@echo "  make netlist-run ELF=ELF/cpu-test/dummy-riscv32e-npc.elf"
	@echo "  make netlist-run ELF=ELF/cpu-test/dummy-riscv32e-npc.elf mainargs=t WAVE=1"
	@echo "================================================"

# 创建构建目录
$(BUILD_DIR) $(NETLIST_BUILD):
	@mkdir -p $@

# 编译网表仿真器
netlist-build: $(NETLIST_VVP)

$(NETLIST_VVP): $(NETLIST_SRCS) | $(NETLIST_BUILD)
	@echo "[IVERILOG] 编译网表仿真器 -> $(NETLIST_VVP)"
	iverilog -g2012 $(DEFINES) -o $@ -s $(TOP_TB) $(NETLIST_SRCS)
	@echo "[SUCCESS] 网表仿真器编译完成"

# 网表仿真运行
netlist-run: netlist-build
	@set -e; \
	if [ -z "$(ELF)" ]; then \
		echo "[ERROR] 请指定 ELF=程序路径"; \
		echo "使用示例: make netlist-run ELF=ELF/cpu-test/dummy-riscv32e-npc.elf"; \
		exit 1; \
	fi; \
	if [ ! -f "$(ELF)" ]; then \
		echo "[ERROR] ELF文件不存在: $(ELF)"; \
		exit 1; \
	fi; \
	\
	base="$$(basename "$(ELF)" .elf)"; \
	hex="$(NETLIST_BUILD)/$$base.hex"; \
	echo "[OBJCOPY] 转换ELF文件: $$ELF -> $$hex"; \
	$(OBJCOPY) -O verilog \
		--set-section-flags .bss=alloc,load,contents \
		--adjust-vma -$(VMA_BASE) \
		"$(ELF)" "$$hex"; \
	\
	hex_size=$$(wc -c < "$$hex"); \
	echo "[INFO] 生成的HEX文件大小: $$hex_size 字节"; \
	\
	# 波形文件配置 \
	wave_cmd=""; \
	wave_info=""; \
	if [ "$(WAVE)" = "1" ]; then \
		wave_cmd="+WAVE=1 +WAVE_FILE=$(WAVE_FILE)"; \
		wave_info=" (波形: $(WAVE_FILE))"; \
	fi; \
	\
	# 参数处理 \
	echo "[SIM] 开始网表仿真$$wave_info"; \
	if [ -n "$(mainargs)" ]; then \
		symfile="$(NETLIST_BUILD)/$$base.sym"; \
		echo "[SYMBOL] 从ELF文件提取符号: $(ELF)"; \
		$(NM) "$(ELF)" | grep -w mainargs > "$$symfile" 2>/dev/null || true; \
		if [ -s "$$symfile" ]; then \
			mainargs_addr=$$(awk '{print "0x"$$1}' "$$symfile"); \
			echo "[PARAM] 找到mainargs地址: $$mainargs_addr, 使用参数: '$(mainargs)'"; \
			echo "[RUN] 运行程序: $$base (带参数 '$(mainargs)')"; \
			( cd $(NETLIST_BUILD) && vvp netlist_sim.vvp +img="$$base.hex" +mainargs="$(mainargs)" +mainargs_addr="$$mainargs_addr" $$wave_cmd ); \
		else \
			echo "[WARN] 未找到mainargs符号，运行无参数模式"; \
			echo "[RUN] 运行程序: $$base (无参数)"; \
			( cd $(NETLIST_BUILD) && vvp netlist_sim.vvp +img="$$base.hex" $$wave_cmd ); \
		fi; \
	else \
		echo "[RUN] 运行程序: $$base (无参数)"; \
		( cd $(NETLIST_BUILD) && vvp netlist_sim.vvp +img="$$base.hex" $$wave_cmd ); \
	fi; \
	\
	# 检查波形文件是否生成 \
	if [ "$(WAVE)" = "1" ] && [ -f "$(NETLIST_BUILD)/$(WAVE_FILE)" ]; then \
		echo "[WAVE] 波形文件已生成: $(NETLIST_BUILD)/$(WAVE_FILE)"; \
	fi; \
	echo "[SIM] 仿真完成"

# 检查文件依赖
check-files:
	@echo "[CHECK] 检查网表仿真依赖文件:"; \
	all_exist=1; \
	for file in $(NETLIST_SRCS); do \
		if [ -f "$$file" ]; then \
			echo "  [OK] $$file"; \
		else \
			echo "  [MISSING] $$file"; \
			all_exist=0; \
		fi; \
	done; \
	if [ $$all_exist -eq 1 ]; then \
		echo "[SUCCESS] 所有依赖文件都存在"; \
	else \
		echo "[ERROR] 有文件缺失，请检查上述路径"; \
		exit 1; \
	fi

# 清理构建文件
clean:
	@echo "[CLEAN] 清理构建文件..."
	rm -rf $(BUILD_DIR)
	@echo "[SUCCESS] 清理完成"

# 显示环境信息
info:
	@echo "================================================"
	@echo "            环境信息"
	@echo "================================================"
	@echo "OBJCOPY: $(OBJCOPY)"
	@echo "NM: $(NM)"
	@echo "VMA_BASE: $(VMA_BASE)"
	@echo "WAVE默认: $(WAVE)"
	@echo "WAVE_FILE默认: $(WAVE_FILE)"
	@echo "网表仿真源文件:"
	@for src in $(NETLIST_SRCS); do echo "  $$src"; done
	@echo "================================================"