# 用法:
#   make check                  # 只解析/elaborate 整个层次 (最快, 先验证可综合)
#   make synth                  # 综合出网表 + 面积报告
#   make sta                    # 综合 + 时序/功耗分析 (结束后更新 ../config/f_cpu)
#   make update-f               # 从最近时序报告更新 ../config/f_cpu
#   make report                 # 从上次结果中提取面积/频率/违例摘要
#   make all                    # sta + report
#
# 参数覆盖 (任意目标均可):
#   make sta CLK_FREQ_MHZ=800         # 换时钟约束
#   make sta PDK=nangate45            # 换工艺库
#   make sta RTL_FILES="..."          # 换 RTL 文件集
#   make sta SDC_FILE=/path/design.sdc
#
# 结果写入 result/NPCSynth-<频率>MHz/ ; 建议提交前记录 report 的输出。

PROJ_PATH := $(abspath $(CURDIR))
SHELL := /bin/bash

YOSYS_STA_HOME ?= $(HOME)/yosys-sta
YOSYS_BIN ?= $(YOSYS_STA_HOME)/oss-cad-suite/bin/yosys
IEDA_BIN ?= $(YOSYS_STA_HOME)/bin/iEDA

# 当前核 RTL 源目录 (npc/vsrc); 本评估项目不修改源 RTL
NPC_VSRC ?= $(PROJ_PATH)/../vsrc

DESIGN := NPCSynth
PDK ?= icsprout55
CLK_FREQ_MHZ ?= 1200
CLK_PORT_NAME ?= clk
# SYNTHESIS: 走 top.v 的合成用存储模型, 排除全部 DPI-C
DEFINES ?= SYNTHESIS

# 综合范围 = CPU + 总线仲裁 (PMEM.v 是仿真 DPI-C 内存模型, SYNTHESIS 下不被
# 实例化; ysyx_26020070.v 是 SOC_MODE 专用的 SoC 顶层, 均不纳入)
RTL_FILES := $(PROJ_PATH)/NPCSynth.v \
             $(NPC_VSRC)/top.v \
             $(NPC_VSRC)/Core.v \
             $(NPC_VSRC)/ICache.v \
             $(NPC_VSRC)/LSU.v \
             $(NPC_VSRC)/Arbiter.v \
             $(NPC_VSRC)/CSR.v \
             $(NPC_VSRC)/RegisterFile.v \
			 $(NPC_VSRC)/CLINT.v 

SDC_FILE ?= $(YOSYS_STA_HOME)/scripts/default.sdc

RESULT_DIR := $(PROJ_PATH)/result/$(DESIGN)-$(CLK_FREQ_MHZ)MHz
NETLIST := $(RESULT_DIR)/$(DESIGN).netlist.v
TIMING_RPT := $(RESULT_DIR)/$(DESIGN).rpt
AREA_RPT := $(RESULT_DIR)/synth_stat.txt

# 评估完成后回写到 npc/config/f_cpu（单位 10MHz）
F_CONFIG ?= $(abspath $(PROJ_PATH)/../config/f_cpu)

# yosys.tcl / sta.tcl 从环境变量读取时钟与宏定义
export CLK_FREQ_MHZ CLK_PORT_NAME DEFINES

# 解析 + elaborate 整个层次, 不映射
check:
	$(YOSYS_BIN) -p 'read_verilog -sv $(addprefix -D,$(DEFINES)) $(RTL_FILES); hierarchy -check -top $(DESIGN); check'

synth: $(NETLIST)

$(NETLIST): $(RTL_FILES) $(YOSYS_STA_HOME)/scripts/yosys.tcl
	@mkdir -p $(RESULT_DIR)
	echo tcl $(YOSYS_STA_HOME)/scripts/yosys.tcl $(DESIGN) $(PDK) \"$(RTL_FILES)\" $@ | \
	  $(YOSYS_BIN) -g -l $(RESULT_DIR)/yosys.log -s -
	@if grep -q 'multiple conflicting drivers' $(RESULT_DIR)/yosys.log; then \
	  echo "Error: multiple conflicting drivers detected; see $(RESULT_DIR)/yosys.log"; \
	  exit 1; \
	fi

sta: synth
	@cd $(RESULT_DIR) && set -o pipefail && \
	  $(IEDA_BIN) -script \
	  $(YOSYS_STA_HOME)/scripts/sta.tcl \
	  $(SDC_FILE) $(NETLIST) $(DESIGN) $(PDK) 2>&1 | tee sta.log
	@$(MAKE) --no-print-directory update-f

# 从时序报告解析最高可达频率，向下取整到 10MHz 后写入 npc/config/f_cpu
update-f:
	@if [ ! -f "$(TIMING_RPT)" ]; then \
	  echo "[F] $(TIMING_RPT) not found; keep $(F_CONFIG)"; \
	  exit 0; \
	fi; \
	freq=$$(awk -F'|' ' \
	  /core_clock/ && /\| max / { \
	    gsub(/ /,"",$$5); gsub(/ /,"",$$8); gsub(/ /,"",$$9); \
	    if ($$9 ~ /^[0-9.]+$$/ && (min=="" || $$9+0<min)) min=$$9+0; \
	  } \
	  END { if (min=="") exit 1; printf "%.3f", min }' "$(TIMING_RPT)" 2>/dev/null); \
	if [ -z "$$freq" ]; then \
	  echo "[F] cannot parse max frequency from $(TIMING_RPT); keep $(F_CONFIG)"; \
	  exit 0; \
	fi; \
	new_f=$$(awk -v f="$$freq" 'BEGIN { if (f <= 0) exit 1; printf "%d", f / 10 }') || { \
	  echo "[F] invalid frequency '$$freq'; keep $(F_CONFIG)"; exit 0; \
	}; \
	mkdir -p "$$(dirname "$(F_CONFIG)")"; \
	old=$$(cat "$(F_CONFIG)" 2>/dev/null || true); \
	printf '%s\n' "$$new_f" > "$(F_CONFIG)"; \
	if [ "$$old" = "$$new_f" ]; then \
	  echo "[F] $(F_CONFIG) = $$new_f (unchanged, from $$freq MHz)"; \
	else \
	  echo "[F] $(F_CONFIG): $${old:-<empty>} -> $$new_f (from $$freq MHz)"; \
	fi

# 从最近一次结果提取关键指标: 面积 / 可达频率 / WNS / 关键路径端点
report:
	@echo "========== NPCSynth 评估摘要 (PDK=$(PDK), 约束=$(CLK_FREQ_MHZ)MHz) =========="
	@if [ -f "$(AREA_RPT)" ]; then \
	  echo "[面积]"; \
	  grep -E "Chip area for module|used for sequential elements" "$(AREA_RPT)" | sed 's/^[[:space:]]*/  /'; \
	  grep -E "^ +[0-9]+ +[0-9.E+-]+ +cells$$" "$(AREA_RPT)" | awk '{printf "  标准单元: %s 个, 单元面积合计 %s\n", $$1, $$2}'; \
	else \
	  echo "[面积] 未找到 $(AREA_RPT), 请先运行 make synth"; \
	fi
	@if [ -f "$(TIMING_RPT)" ]; then \
	  echo "[时序] 约束周期预算: $$(awk "BEGIN{printf \"%.4f\", 1000/$(CLK_FREQ_MHZ)}") ns"; \
	  awk -F'|' ' \
	    /core_clock/ && /\| max / { \
	      gsub(/ /,"",$$5); gsub(/ /,"",$$8); gsub(/ /,"",$$9); \
	      if ($$9 ~ /^[0-9.]+$$/ && (min=="" || $$9+0<min)) { min=$$9+0; wns=$$8; ep=$$2 } \
	    } \
	    END { \
	      if (min=="") { print "  未解析到 max 路径" } \
	      else { gsub(/^ +| +$$/,"",ep); printf "  最高可达频率: %.3f MHz\n", min; printf "  WNS(最差 slack): %s (等效周期 %.4f ns)\n", wns, 1000/min; printf "  关键路径终点: %s\n", ep } \
	    }' "$(TIMING_RPT)"; \
	  echo "  (完整时序表: $(TIMING_RPT))"; \
	else \
	  echo "[时序] 未找到 $(TIMING_RPT), 请先运行 make sta"; \
	fi
	@if [ -f "$(RESULT_DIR)/$(DESIGN).pwr" ]; then \
	  echo "[功耗]"; grep -E "Total|total" "$(RESULT_DIR)/$(DESIGN).pwr" | grep -iE "power|mW" | sed 's/^/  /'; \
	fi
	@echo "[F] config: $(F_CONFIG) = $$(cat "$(F_CONFIG)" 2>/dev/null || echo '<unset>')"
	@echo "=========================================================="

all: sta report

clean:
	-rm -rf $(PROJ_PATH)/result

.PHONY: check synth sta update-f report all clean
