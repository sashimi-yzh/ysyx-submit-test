# cachesim —— 指令 cache 元数据模拟器
#
# 自带完整评估流程: 构建 -> 导出 PC 序列 -> 并行探索 -> 打印报告.
# 只依赖标准库与仓库内其它子项目; 全部产物落在本目录 build/ 下, 不污染 npc/.
#
# 常用入口:
#   make            构建 cachesim
#   make run        单组评估 (默认对齐当前 RTL: sets=16 ways=1 block=4)
#   make eval       一键: 导 trace + 并行探索 + 打印报告
#   make sweep      只做并行探索并打印全表
#   make report     只按已有 CSV 重打印报告
#   make clean      清理本目录 build/

# ---------- 路径 ----------
CACHESIM_DIR   := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
NPC_DIR        := $(abspath $(CACHESIM_DIR)/..)
WORKBENCH      := $(abspath $(CACHESIM_DIR)/../..)
NEMU_HOME      ?= $(WORKBENCH)/nemu
MICROBENCH_DIR ?= $(WORKBENCH)/am-kernels/benchmarks/microbench

# ---------- 构建 ----------
CXX      ?= g++
CXXFLAGS ?= -O2 -std=c++17 -Wall -Wextra
BUILD_DIR := $(CACHESIM_DIR)/build
TARGET    := $(BUILD_DIR)/cachesim

# ---------- 评估参数 ----------
TRACE          ?= $(BUILD_DIR)/microbench-train.pc
NEMU_LOG       := $(BUILD_DIR)/cachesim-nemu.log
NEMU_BIN       ?= $(NEMU_HOME)/build/riscv32-nemu-interpreter-ysyxsoc
MICROBENCH_BIN ?= $(MICROBENCH_DIR)/build/microbench-riscv32e-ysyxsoc.bin

CSETS   ?= 16
CWAYS   ?= 1
CBLOCK  ?= 4
C_BURST ?= 0
PENALTY ?= 30
# 缺失代价来源：默认用突发模型（讲义 B4 §8.4），PENALTY_GIVEN=1 时退回常数 PENALTY
PENALTY_GIVEN ?= 0
PENALTY_ARG := $(if $(filter 1,$(PENALTY_GIVEN)),--miss-penalty $(PENALTY),)
BUS_BYTES   ?= 4
# 缺失代价模型参数（CPU 周期），默认值由 F=51 下 4B/8B/16B 三组实测标定
FIXED_COST  ?= 28
BEAT_COST   ?= 5

SWEEP_BLOCKS ?= 4 8 16 32
SWEEP_WAYS   ?= 1 2 4
SWEEP_SETS   ?= 4 8 16 32
SWEEP_BURST  ?= 0 1
SWEEP_DIR    := $(BUILD_DIR)/sweep

JOBS ?= $(shell nproc 2>/dev/null || echo 4)

# NEMU 的 kconfig 产物: 导出 trace 前备份, 结束后无条件还原, 不留副作用
NEMU_CFG_FILES := .config .config.old include/config include/generated
CFG_BAK        := $(BUILD_DIR)/.nemu-cfg-bak

# NPC 的性能日志: 仅用于报告里的参考对照, 允许缺失
PERF_LOG ?= $(NPC_DIR)/build/perf-microbench.log

# ---------- 构建 ----------
all: $(TARGET)

$(TARGET): $(CACHESIM_DIR)/cachesim.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

# ---------- microbench 镜像 ----------
$(MICROBENCH_BIN):
	@mkdir -p $(BUILD_DIR)
	@echo "[cachesim] 编译 microbench (mainargs=train) ..."
	@$(MAKE) --no-print-directory -C $(MICROBENCH_DIR) \
	  AM_HOME=$(WORKBENCH)/abstract-machine \
	  ARCH=riscv32e-ysyxsoc mainargs=train insert-arg > /dev/null

# ---------- 导出 PC 序列 ----------
trace: $(MICROBENCH_BIN)
	@if [ -f "$(TRACE)" ] && [ "$(FORCE)" != "1" ]; then \
	  echo "[cachesim] 复用已有 PC 序列: $(TRACE)  (FORCE=1 可强制重建)"; \
	else \
	  set -e; \
	  mkdir -p "$(BUILD_DIR)"; \
	  B="$(CFG_BAK)"; \
	  rm -rf "$$B"; mkdir -p "$$B"; \
	  for f in $(NEMU_CFG_FILES); do \
	    if [ -e "$(NEMU_HOME)/$$f" ]; then cp -a "$(NEMU_HOME)/$$f" "$$B/$$(echo $$f | tr / _)"; fi; \
	  done; \
	  restore() { \
	    [ -d "$$B" ] || return 0; \
	    for f in $(NEMU_CFG_FILES); do \
	      rm -rf "$(NEMU_HOME)/$$f"; \
	      b="$$B/$$(echo $$f | tr / _)"; \
	      if [ -e "$$b" ]; then cp -a "$$b" "$(NEMU_HOME)/$$f"; fi; \
	    done; \
	    rm -rf "$$B"; \
	    echo "[cachesim] NEMU 配置已恢复"; \
	  }; \
	  trap 'restore; exit 130' INT TERM; \
	  trap restore EXIT; \
	  echo "[cachesim] 切换 NEMU 到 riscv32-ysyxsoc_defconfig ..."; \
	  $(MAKE) --no-print-directory -C $(NEMU_HOME) riscv32-ysyxsoc_defconfig > /dev/null; \
	  $(MAKE) --no-print-directory -C $(NEMU_HOME) YSYXSOC_REF=1 \
	    NAME=riscv32-nemu-interpreter-ysyxsoc -j > /dev/null; \
	  echo "[cachesim] 导出 PC 序列 -> $(TRACE)"; \
	  $(NEMU_BIN) -b -c $(TRACE) $(MICROBENCH_BIN) > $(NEMU_LOG) 2>&1; \
	  echo "[cachesim] trace 大小: $$(du -h $(TRACE) | cut -f1)  (NEMU 日志: $(NEMU_LOG))"; \
	fi

# ---------- 单组评估 ----------
run: $(TARGET) trace
	@echo "=== cachesim 评估 [sets=$(CSETS) ways=$(CWAYS) block=$(CBLOCK)B bus=$(BUS_BYTES)B burst=$(C_BURST)] ==="
	@$(TARGET) --trace $(TRACE) --sets $(CSETS) --ways $(CWAYS) \
	  --block $(CBLOCK) --bus-bytes $(BUS_BYTES) --burst $(C_BURST) \
	  --fixed $(FIXED_COST) --beat $(BEAT_COST) $(PENALTY_ARG)

# ---------- 并行探索 ----------
sweep: $(TARGET) trace
	@mkdir -p $(SWEEP_DIR)
	@rm -f $(SWEEP_DIR)/*.csv
	@echo "[cachesim] 参数扫描 blocks={$(SWEEP_BLOCKS)} ways={$(SWEEP_WAYS)} sets={$(SWEEP_SETS)} burst={$(SWEEP_BURST)} (并行 $(JOBS) 路)"
	@for b in $(SWEEP_BLOCKS); do \
	  for w in $(SWEEP_WAYS); do \
	    for s in $(SWEEP_SETS); do \
	      for t in $(SWEEP_BURST); do echo "$$b $$w $$s $$t"; done; \
	    done; \
	  done; \
	done | xargs -P $(JOBS) -n 4 sh -c '\
	  $(TARGET) --csv --trace $(TRACE) \
	    --block $$0 --ways $$1 --sets $$2 --burst $$3 --bus-bytes $(BUS_BYTES) \
	    --fixed $(FIXED_COST) --beat $(BEAT_COST) $(PENALTY_ARG) \
	    > $(SWEEP_DIR)/$${0}_$${1}_$${2}_$${3}.csv'
	@if [ "$(SWEEP_QUIET)" != "1" ]; then \
	  echo ""; \
	  printf "%-6s %-5s %-5s %-7s %9s %12s %14s\n" block ways sets burst hit-rate miss TMT; \
	  printf "%-6s %-5s %-5s %-7s %9s %12s %14s\n" ------ ----- ----- ------- --------- ------------ --------------; \
	  cat $(SWEEP_DIR)/*.csv | sort -t, -k1,1n -k2,2n -k3,3n -k4,4n | \
	    awk -F, '{ printf "%-6s %-5s %-5s %-7s %8s%% %12s %14s\n", $$1, $$2, $$3, ($$4==1?"burst":"indep"), $$5, $$6, $$7 }'; \
	fi

# ---------- 报告 ----------
# CSV 有两种格式（旧扫描产物 vs 新增 burst 列），这里统一成 7 列再统计：
#   block,ways,sets,burst,hit_rate,miss,tmt
report:
	@set -e; \
	D="$(SWEEP_DIR)"; \
	if [ -z "$$(ls $$D/*.csv 2>/dev/null)" ]; then \
	  echo "未找到扫描结果, 请先运行 make sweep"; exit 1; \
	fi; \
	NORM=$$(mktemp); \
	cat $$D/*.csv | awk -F, 'NF>=6 { if (NF==6) print $$1","$$2","$$3",0,"$$4","$$5","$$6; \
	                                  else      print $$1","$$2","$$3","$$4","$$5","$$6","$$7 }' \
	                  | sort -t, -k1,1n -k2,2n -k3,3n -k4,4n -u > $$NORM; \
	N=$$(wc -l < $$NORM); \
	BASE_LINE=$$(awk -F, '$$1==4 && $$2==1 && $$3==16 && $$4==0 {print; exit}' $$NORM); \
	BASE=$$(echo "$$BASE_LINE" | cut -d, -f7); \
	BEST=$$(sort -t, -k7,7n $$NORM | head -1); \
	echo ""; \
	echo "================== cachesim 设计空间探索报告 =================="; \
	echo "[环境]"; \
	printf "  trace          : %s (%s)\n" "$(TRACE)" "$$(du -h $(TRACE) 2>/dev/null | cut -f1)"; \
	printf "  参数组合       : %s\n" "$$N"; \
	printf "  并行度         : %s\n" "$(JOBS)"; \
	if [ "$(PENALTY_GIVEN)" = "1" ]; then \
	  printf "  缺失代价       : %s cycles/miss (常数)\n" "$(PENALTY)"; \
	else \
	  printf "  缺失代价       : 突发模型 n=block/%sB, lat=(%s)\n" "$(BUS_BYTES)" "$(LAT)"; \
	fi; \
	echo ""; \
	echo "[基线] 当前 RTL 实现: sets=16 ways=1 block=4B 独立事务"; \
	echo "$$BASE_LINE" | awk -F, '{ printf "  hit-rate=%s%%  miss=%s  TMT=%s cycles\n", $$5, $$6, $$7 }'; \
	echo ""; \
	echo "[完整结果] (共 $$N 组, 按 TMT 升序)"; \
	sort -t, -k7,7n $$NORM | \
	  awk -F, -v base="$$BASE" 'BEGIN { \
	    printf "  %-4s %-6s %-5s %-5s %-7s %9s %12s %14s %9s\n", \
	           "rank", "block", "ways", "sets", "mode", "hit-rate", "miss", "TMT", "vs_base"; \
	    printf "  %-4s %-6s %-5s %-5s %-7s %9s %12s %14s %9s\n", \
	           "----", "------", "-----", "-----", "-------", "---------", "------------", "--------------", "---------"; \
	  } { \
	    speed = ($$7 > 0 && base > 0) ? base / $$7 : 0; \
	    printf "  %-4d %-6s %-5s %-5s %-7s %8s%% %12s %14s %8.1fx\n", \
	           NR, $$1, $$2, $$3, ($$4==1?"burst":"indep"), $$5, $$6, $$7, speed; \
	  }'; \
	echo ""; \
	echo "[最优组合]"; \
	echo "$$BEST" | awk -F, -v base="$$BASE" '{ \
	  printf "  sets=%s ways=%s block=%sB %s\n", $$3, $$2, $$1, ($$4==1?"burst":"indep"); \
	  printf "  hit-rate=%s%%  miss=%s  TMT=%s cycles\n", $$5, $$6, $$7; \
	  if (base > 0 && $$7 > 0) printf "  TMT 相对当前实现降低 %.2f%%\n", (1 - $$7 / base) * 100; \
	}'; \
	echo ""; \
	echo "[突发 vs 独立事务, 同参数对照]"; \
	awk -F, '{ key = $$1","$$2","$$3; \
	           if ($$4 == 0) ind[key] = $$7; else bur[key] = $$7; } \
	  END { printf "  %-6s %-5s %-5s %14s %14s %9s\n", "block", "ways", "sets", "TMT(indep)", "TMT(burst)", "gain"; \
	        for (k in bur) if (k in ind) { \
	          g = (ind[k] > 0) ? (1 - bur[k] / ind[k]) * 100 : 0; \
	          split(k, p, ","); \
	          printf "  %-6s %-5s %-5s %14d %14d %8.1f%%\n", p[1], p[2], p[3], ind[k], bur[k], g; \
	        } }' $$NORM; \
	echo ""; \
	if [ -f "$(PERF_LOG)" ]; then \
	  echo "[与 NPC perf 对照 (仅供参考)]"; \
	  PA=$$(grep -m1 'access / hit / miss' $(PERF_LOG) | awk '{print $$(NF-4)}'); \
	  PM=$$(grep -m1 'access / hit / miss' $(PERF_LOG) | awk '{print $$NF}'); \
	  printf "  perf     : access=%s  miss=%s\n" "$$PA" "$$PM"; \
	  echo "$$BASE_LINE" | awk -F, '{ printf "  cachesim : hit-rate=%s%%  miss=%s  TMT=%s cycles\n", $$5, $$6, $$7 }'; \
	  echo "  说明     : bypass 与 compulsory 与 perf 完全一致, 其余差异来自指令流长度"; \
	else \
	  echo "[与 NPC perf 对照] 未找到 $(PERF_LOG), 跳过 (可先在 npc/ 下 make perf)"; \
	fi; \
	rm -f $$NORM; \
	echo "=============================================================="

# 依赖由 sweep 负责(它会构建 cachesim 并确保 trace 就绪), 这里不再重复声明
eval:
	@$(MAKE) --no-print-directory sweep SWEEP_QUIET=1
	@$(MAKE) --no-print-directory report

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all trace run sweep report eval clean
