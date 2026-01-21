#=======================================================================================
# SoC & Verilator 配置模块 (soc.mk)
#=======================================================================================

#--- 工具与库 ---
VERILATOR := verilator
CAPSTONE_PATH := $(NPC_HOME)/tools/capstone
LIBCAPSTONE   := $(CAPSTONE_PATH)/repo/libcapstone.so.5

$(LIBCAPSTONE):
	$(MAKE) -C $(CAPSTONE_PATH)

#--- SoC 核心变量 ---
SOC_TOP   = ysyxSoCFull
SOC_BIN = $(OBJ_DIR)/V$(SOC_TOP)
SOC_VSRC  = $(NPC_VSRC) $(shell find ../ysyxSoC/perip -type f -name "*.v") ../ysyxSoC/build/ysyxSoCFull.v
SOC_CSRC += $(abspath $(shell find csrc -type f \( -name "*.c" -o -name "*.cpp" \)))
SOC_INC   = $(addprefix -I, ../ysyxSoC/perip/uart16550/rtl ../ysyxSoC/perip/spi/rtl)

# C/C++ 选项
SOC_CPATHS = $(abspath ../include ../include/generated $(CAPSTONE_PATH)/repo/include)
CFLAGS += $(addprefix -I, $(SOC_CPATHS))
LDFLAGS += -lreadline
ifdef CONFIG_CC_ASAN
  CFLAGS += -fsanitize=address
  LDFLAGS += -fsanitize=address
endif

# 宏定义
SOC_VERDEFINE += +define+TOP_NAME=\"V$(SOC_TOP)\" +define+YSYXSOC
SOC_VERDEFINE +=$(if $(CONFIG_EVENT_COUNTER), +define+EVENT_COUNTER)

# 依赖文件
SOC_DEPEMD += $(LIBCAPSTONE) $(SOC_VSRC) $(SOC_CSRC) include/generated/autoconf.h

#--- NVBoard 集成 ---
ifdef CONFIG_TARGET_NVBOARD
NXDC_FILES = constr/top.nxdc
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)

$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

-include $(NVBOARD_HOME)/scripts/nvboard.mk
CFLAGS += $(addprefix -I, $(INC_PATH))
SOC_CSRC += $(SRC_AUTO_BIND)
VERFLAGS += $(NVBOARD_ARCHIVE)
SOC_DEPEMD += $(SRC_AUTO_BIND) $(NVBOARD_ARCHIVE)
endif

#--- Verilator 编译选项 ---
# 警告抑制
# Verilator警告抑制选项
# PINCONNECTEMPTY: 实例化时有端口未连接, .accept_o(),
# DECLFILENAME: 模块名与其文件名不一致
# UNUSEDSIGNAL: 模块定义了未被使用的信号
# ASSIGNDLY: 模块中存在 #1 这类延时语句, 同时又约定了--no-timing忽略延时语句加速仿真
# UNUSEDPARAM: 模块定义了未被使用的参数
# SYNCASYNCNET: 一个复位信号既被用于同步复位, 又被用于异步复位. 目前该报错发生于uart_reg的复位是异步复位, 暂时忽略日后修改
# PROCASSINIT: 在always块中使用了阻塞赋值语句进行初始赋值
VERWNO := $(addprefix -Wno-, PINCONNECTEMPTY DECLFILENAME UNUSEDSIGNAL ASSIGNDLY UNUSEDPARAM SYNCASYNCNET PROCASSINIT)

VERFLAGS += --noassert -O3 -MMD --cc --exe --build 
VERFLAGS += --x-assign fast --x-initial fast --timescale "1ns/1ns" --no-timing --autoflush
VERFLAGS += --Mdir $(OBJ_DIR) --top-module $(SOC_TOP)
VERFLAGS += $(if $(CONFIG_FST), --trace-fst)
VERFLAGS += $(if $(CONFIG_WALL), -Wall $(VERWNO))
VERFLAGS += $(SOC_VERDEFINE) $(SOC_INC)
VERFLAGS += -CFLAGS "$(CFLAGS)" -LDFLAGS "$(LDFLAGS)"
VERFLAGS += $(SOC_VSRC) $(SOC_CSRC)

#--- 构建规则 ---
$(SOC_BIN): $(SOC_DEPEMD)
	$(call git_commit, "sim RTL")
	$(VERILATOR) $(VERFLAGS)

#--- 运行与测试 ---
override ARGS ?= -d $(NPC_HOME)/../nemu/build/riscv32-nemu-interpreter-so \
				 -l $(NPC_HOME)/build/log/log.txt \
				 -i $(NPC_HOME)/sim/verilator/fib.bin
# 				 -i $(NPC_HOME)/sim/verilator/train.bin
# 				 -i $(NPC_HOME)/sim/verilator/test.bin

run: $(SOC_BIN)
	@$< $(ARGS)

gdb: $(SOC_BIN)
	@gdb --args $< $(ARGS)

wave: run
	@gtkwave $(WAVE_DIR)/waveform.fst

perf: $(SOC_DEPEMD)
	$(call git_commit, "make perf")
	$(VERILATOR) $(SOC_VERFLAGS) -LDFLAGS "$(SOC_LDFLAGS)" -CFLAGS "$(SOC_CFLAGS)"
	@$(SOC_BIN) $(ARGS)
	@echo "Simulation done. Press any key to run Static Timing Analysis..." && read a
	$(MAKE) -C /home/yunhai/ysyx-workbench/yosys-sta sta \
           DESIGN=ysyx_25050136 CLK_FREQ_MHZ=1500 CLK_PORT_NAME=clock RTL_FILES="$(NPC_VSRC)"

.PHONY: run gdb wave perf