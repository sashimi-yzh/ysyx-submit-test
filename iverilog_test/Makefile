# ===== 基本配置 =====
VERILOG_DIR := verilog
BUILD       := build
TOP_TB      := testbench

# 源码与 include 目录
VSRCS  := $(shell find $(VERILOG_DIR) -type f \( -name "*.v" -o -name "*.sv" \))
INCDIR := $(shell find $(VERILOG_DIR) -type d)
INCS   := $(addprefix -I, $(INCDIR))

# 预处理宏
NPC ?= 1
DEFINES :=
ifeq ($(NPC),1)
  DEFINES += -DNPC -DVERILATOR_SIM
endif

# RISC-V 工具
OBJCOPY  ?= riscv64-unknown-elf-objcopy
NM       ?= riscv64-unknown-elf-nm
VMA_BASE ?= 0x80000000

# mainargs 参数（可选，默认为空）
mainargs ?=

# iverilog 输出
VVP := $(BUILD)/sim.vvp

.PHONY: run run-all list build-sim clean help

help:
	@echo "用法："
	@echo "  make run DIR=out/                    # 运行最新程序（兼容模式）"
	@echo "  make run ELF=out/foo.elf             # 指定 ELF 运行"
	@echo "  make run ELF=out/foo.elf mainargs=t  # 带参数运行（支持参数的程序）"
	@echo "  make run-all DIR=out/                # 批量运行"
	@echo "  make list DIR=out/                   # 列出 ELF 文件"
	@echo "  make clean                           # 清理"
	@echo ""
	@echo "mainargs 选项（仅适用于支持参数的程序）："
	@echo "  t: real-time clock test"
	@echo "  h: hello"
	@echo "  H: help message"
	@echo "  i: interrupt/yield test"
	@echo "  d: scan devices"
	@echo "  m: multiprocessor test"
	@echo "  k: readkey test"
	@echo "  v: display test"
	@echo "  a: audio test"
	@echo "  p: x86 virtual memory test"
	@echo "  r: reada"

list:
	@if [ -z "$(DIR)" ]; then echo "[ERR] 请指定 DIR，例如：make list DIR=out/"; exit 1; fi; \
	if [ ! -d "$(DIR)" ]; then echo "[ERR] 目录不存在: $(DIR)"; exit 1; fi; \
	echo "[INFO] 在目录中搜索 ELF：$(DIR)"; \
	find "$(DIR)" -type f -name '*.elf' 2>/dev/null | xargs -r ls -lht 2>/dev/null || true

# 编译仿真
build-sim: $(VVP)

$(VVP): $(VSRCS) | $(BUILD)
	@echo "[CC ] iverilog -> $(VVP)"
	iverilog -g2012 $(DEFINES) -o $@ -s $(TOP_TB) $(INCS) $(VSRCS)

$(BUILD):
	@mkdir -p $@

# 单个运行：兼容模式 + 可选参数支持
run: build-sim
	@set -e; \
	if [ -n "$(ELF)" ]; then target="$(ELF)"; \
	else \
	  if [ -z "$(DIR)" ]; then echo "[ERR] 请指定 DIR=... 或 ELF=..."; exit 1; fi; \
	  if [ ! -d "$(DIR)" ]; then echo "[ERR] 目录不存在: $(DIR)"; exit 1; fi; \
	  target="$$(find "$(DIR)" -type f -name '*.elf' -print0 | xargs -0 ls -t 2>/dev/null | head -n 1)"; \
	fi; \
	if [ -z "$$target" ]; then echo "[ERR] 未找到 .elf"; exit 1; fi; \
	base="$$(basename "$$target" .elf)"; \
	hex="$(BUILD)/$$base.hex"; \
	echo "[HEX] $$target -> $$hex"; \
	# 使用与原来相同的 objcopy 命令 \
	$(OBJCOPY) -O verilog \
		--set-section-flags .bss=alloc,load,contents \
		--adjust-vma -$(VMA_BASE) \
		"$$target" "$$hex"; \
	# 检查生成的 hex 文件大小 \
	hex_size=$$(wc -c < "$$hex"); \
	echo "[INFO] Generated hex file size: $$hex_size bytes"; \
	\
	# 如果有指定 mainargs，则尝试提取符号地址 \
	if [ -n "$(mainargs)" ]; then \
	  symfile="$(BUILD)/$$base.sym"; \
	  echo "[SYM] Extracting mainargs address from $$target"; \
	  $(NM) "$$target" | grep -w mainargs > "$$symfile" 2>/dev/null || true; \
	  if [ -s "$$symfile" ]; then \
	    mainargs_addr=$$(awk '{print "0x"$$1}' "$$symfile"); \
	    echo "[INFO] Found mainargs at $$mainargs_addr, using parameter '$(mainargs)'"; \
	    echo "[RUN] $$base with parameter '$(mainargs)'"; \
	    ( cd $(BUILD) && vvp sim.vvp +img="$$base.hex" +mainargs="$(mainargs)" +mainargs_addr="$$mainargs_addr" ); \
	  else \
	    echo "[WARN] mainargs symbol not found in $$base, running in compatibility mode"; \
	    echo "[RUN] $$base (compatibility mode)"; \
	    ( cd $(BUILD) && vvp sim.vvp +img="$$base.hex" ); \
	  fi; \
	else \
	  # 没有指定 mainargs，使用兼容模式 \
	  echo "[RUN] $$base (compatibility mode)"; \
	  ( cd $(BUILD) && vvp sim.vvp +img="$$base.hex" ); \
	fi; \
	\
	if [ -f "$(BUILD)/wave.vcd" ]; then \
	  echo "[WAVE] $(BUILD)/wave.vcd 已生成"; \
	else \
	  echo "[WARN] 未发现 wave.vcd"; \
	fi

# 批量运行：保持原有兼容性
run-all: build-sim
	@if [ -z "$(DIR)" ]; then echo "[ERR] 请指定 DIR，例如：make run-all DIR=out/"; exit 1; fi; \
	if [ ! -d "$(DIR)" ]; then echo "[ERR] 目录不存在: $(DIR)"; exit 1; fi; \
	set -e; \
	elves="$$(find "$(DIR)" -type f -name '*.elf' | sort)"; \
	if [ -z "$$elves" ]; then echo "[ERR] 未在 $(DIR) 找到 .elf"; exit 1; fi; \
	for elf in $$elves; do \
	  base="$$(basename "$$elf" .elf)"; \
	  hex="$(BUILD)/$$base.hex"; \
	  echo ""; \
	  echo "[HEX] $$elf -> $$hex"; \
	  $(OBJCOPY) -O verilog --adjust-vma -$(VMA_BASE) "$$elf" "$$hex"; \
	  echo "[RUN] $$base (compatibility mode)"; \
	  ( cd $(BUILD) && vvp sim.vvp +img="$$base.hex" ); \
	  if [ -f "$(BUILD)/wave.vcd" ]; then \
	    echo "[WAVE] $(BUILD)/wave.vcd 已生成/覆盖"; \
	  else \
	    echo "[WARN] 未发现 wave.vcd"; \
	  fi; \
	done

clean:
	rm -rf $(BUILD) wave.vcd
	@echo "[CLEAN] done"