#***************************************************************************************
# NPC 仿真工程 Makefile
# 功能: 支持Verilator的SoC仿真, 支持Iverilog的NPC仿真 
#***************************************************************************************/

#================ 第一步: 环境检查与配置加载 ====================
# 检查NPC_HOME环境变量是否设置正确
ifeq ($(wildcard $(NPC_HOME)/vsrc/cpu.v),)
 $(error NPC_HOME=$(NPC_HOME) is not a NPC repo)
endif

defualt: soc_run

# 加载自动生成的配置
-include $(NPC_HOME)/include/config/auto.conf
-include $(NPC_HOME)/include/config/auto.conf.cmd

#================ 第二步: 第三方工具配置 ========================
# Capstone 配置（用于itrace）
CAPSTONE_PATH := $(NPC_HOME)/tools/capstone
LIBCAPSTONE   := tools/capstone/repo/libcapstone.so.5
$(LIBCAPSTONE):
	$(MAKE) -C $(CAPSTONE_PATH)

#================ 第三步: 通用配置 =============================
# 目录配置
BUILD_DIR = $(NPC_HOME)/build
WAVE_DIR = $(NPC_HOME)/wave
OBJ_DIR = $(BUILD_DIR)/obj_dir
LOG_DIR = $(BUILD_DIR)/log
IVER_DIR = $(BUILD_DIR)/iverilog
$(shell mkdir -p $(LOG_DIR) $(WAVE_DIR) $(IVER_DIR))

# 用于生成ysyx_25050136.v的Verilog源文件列表
NPC_VSRC := $(BUILD_DIR)/ysyx_25050136.v
COMMON_VSRC = vsrc/config.v $(filter-out vsrc/config.v,$(wildcard vsrc/*.v))
$(shell rm -f $(NPC_NAME))

#================ 第四步: Verilator配置 =========================
# 编译工具
VERILATOR_BIN   := verilator

# Verilator编译选项
VERFLAGS += -MMD --cc -exe --build --x-assign fast --x-initial fast\
				   --timescale "1ns/1ns" --no-timing --autoflush\
				   --Mdir $(OBJ_DIR) 

# FST波形跟踪选项
ifdef CONFIG_FST
VERFLAGS += --trace-fst
endif

# Verilator警告抑制选项
# PINCONNECTEMPTY: 实例化时有端口未连接, .accept_o(),
# DECLFILENAME: 模块名与其文件名不一致
# UNUSEDSIGNAL: 模块定义了未被使用的信号
# ASSIGNDLY: 模块中存在 #1 这类延时语句, 同时又约定了--no-timing忽略延时语句加速仿真
# UNUSEDPARAM: 模块定义了未被使用的参数
# SYNCASYNCNET: 一个复位信号既被用于同步复位, 又被用于异步复位. 目前该报错发生于uart_reg的复位是异步复位, 暂时忽略日后修改
VERWNO := $(addprefix -Wno-, PINCONNECTEMPTY DECLFILENAME UNUSEDSIGNAL ASSIGNDLY UNUSEDPARAM SYNCASYNCNET)

# 警告级别配置
ifdef CONFIG_WALL
VERFLAGS += -Wall $(VERWNO)
endif

# C编译和链接选项
CFLAGS += -I$(CAPSTONE_PATH)/repo/include
LDFLAGS += -lreadline

# 地址调试选项（用于调试）
ifdef CONFIG_CC_ASAN
CFLAGS += -fsanitize=address
LDFLAGS += -fsanitize=address
endif

#================第五步: Verilator 仿真参数配置 ====================
# 默认仿真参数
override ARGS ?= -d $(NPC_HOME)/../nemu/build/riscv32-nemu-interpreter-so \
				 -l $(NPC_HOME)/build/log/log.txt \
				 -i $(NPC_HOME)/sim/microbench-test.bin
# 				 -i $(NPC_HOME)/sim/microbench-train.bin
# 				 -i $(NPC_HOME)/sim/fib.bin 

#================第六步: NVBoard配置 ====================
# NVBoard约束文件配置
NXDC_FILES = constr/top.nxdc          # NVBoard约束文件

# 自动引脚绑定生成
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# NVBoard相关配置
ifdef CONFIG_TARGET_NVBOARD
-include $(NVBOARD_HOME)/scripts/nvboard.mk
SOC_CFLAGS += $(addprefix -I, $(INC_PATH))
SOC_CSRC += $(SRC_AUTO_BIND)
SOC_VERFLAGS += --noassert -O3 $(NVBOARD_ARCHIVE)
SOC_DEPEMD += $(SRC_AUTO_BIND) $(NVBOARD_ARCHIVE)
endif

#================第七步: SOC 专用配置 ====================
# SoC模式源文件
SOC_VSRC = $(NPC_VSRC) $(shell find ../ysyxSoC/perip -type f -name "*.v") ../ysyxSoC/build/ysyxSoCFull.v 
SOC_CSRC += $(abspath $(shell find csrc -type f \( -name "*.c" -o -name "*.cpp" \)))

# SoC的配置
SOC_TOP = ysyxSoCFull 
SOC_INC = $(addprefix -I, ../ysyxSoC/perip/uart16550/rtl ../ysyxSoC/perip/spi/rtl)
SOC_CPATHS = $(abspath ../include ../include/generated)
SOC_CFLAGS += $(CFLAGS) $(addprefix -I, $(SOC_CPATHS))
SOC_LDFLAGS += $(LDFLAGS)

# SoC Verilator宏定义
SOC_VERDEFINE = +TOP_NAME="V$(SOC_TOP)" 

# SoC Verilator编译选项
SOC_VERFLAGS += $(VERFLAGS) --top-module $(SOC_TOP) $(SOC_VSRC) $(SOC_CSRC) \
			    $(SOC_INC) +define$(SOC_VERDEFINE) -DYSYXSOC

ifdef CONFIG_EVENT_COUNTER
SOC_VERFLAGS += -DEVENT_COUNTER
endif

# SoC依赖文件
SOC_DEPEMD += $(LIBCAPSTONE) $(NPC_VSRC)
SOC_BIN = $(OBJ_DIR)/V$(SOC_TOP)
#================第八步: Iverilog 配置 ====================
IMG = $(NPC_HOME)/sim/iverilog_test.bin
NETLIST = $(NPC_HOME)/../yosys-sta/result/ysyx_25050136-1500MHz/ysyx_25050136.v
CELLS = $(NPC_HOME)/../yosys-sta/pdk/nangate45/sim/cells.v
IMG_HEX = $(IVER_DIR)/$(shell basename $(IMG) .bin).hex
$(info $(IMG_HEX))

IVERILOG_BIN := iverilog
VVP_BIN := vvp
IVER_TOP = tb_fullsoc
IVER_VSRC = vsrc/idle/fullsoc.v vsrc/idle/sram.v vsrc/idle/tb_fullsoc.v vsrc/idle/uart.v vsrc/idle/xbar.v
IVER_OUT = $(IVER_DIR)/iverilog_sim.out
IVERFLAGS = -o $(IVER_OUT) -g2012 -s $(IVER_TOP) -Ptb_fullsoc.PROG_FILE='"$(IMG_HEX)"' 
VVPFLAGS = -n $(IVER_OUT) -lxt2
#================第步: 构建目标规则 ====================
-include $(NPC_HOME)/scripts/config.mk

$(NPC_VSRC): $(COMMON_VSRC)  
	@cat $^ > $@

$(IMG_HEX): $(IMG)
	@xxd -c 1 -p $^ > $@

verilog: $(NPC_VSRC)

$(SOC_BIN): $(SOC_DEPEMD)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR_BIN) $(SOC_VERFLAGS) -LDFLAGS "$(SOC_LDFLAGS)" -CFLAGS "$(SOC_CFLAGS)"

soc_run: $(SOC_BIN)
	@$< $(ARGS)	

soc_gdb: $(SOC_BIN)
	@gdb --args @$(SOC_BIN) $(ARGS)

soc_wave: soc_run
	@gtkwave $(WAVE_DIR)/waveform.fst

sim-iverilog: verilog $(IMG_HEX)
	@$(info IMG = $(IMG))
	@$(IVERILOG_BIN) $(IVERFLAGS) $(NPC_VSRC) $(IVER_VSRC)
	@$(VVP_BIN) $(VVPFLAGS)

sim-iverilog-netlist: $(IMG_HEX)
	@$(info IMG = $(IMG) NETLIST = $(NETLIST) CELLS = $(CELLS))
	@$(IVERILOG_BIN) $(IVERFLAGS) $(IVER_VSRC) $(NETLIST) $(CELLS)
	@$(VVP_BIN) $(VVPFLAGS)

clean:
	rm -rf build
	rm -f $(WAVE_DIR)/*.fst

perf_commit:
	$(call git_commit, "性能测试提交-为CI测试准备的CPU版本-详见sim性能测试文件") # DO NOT REMOVE THIS LINE!!!

perf: $(SOC_DEPEMD)
	$(call git_commit, "make perf") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR_BIN) $(SOC_VERFLAGS) -LDFLAGS "$(SOC_LDFLAGS)" -CFLAGS "$(SOC_CFLAGS)"	
	@$(SOC_BIN) $(ARGS)
	@echo "暂停执行，按任意键继续..."
	@read a
	@$(MAKE) -C /home/yunhai/ysyx-workbench/yosys-sta sta \
           DESIGN=ysyx_25050136 \
           CLK_FREQ_MHZ=1500 CLK_PORT_NAME=clock \
           RTL_FILES="$(NPC_VSRC)"


export NPC_VSRC

fuck: $(SOC_DEPEMD)
	@python3 scripts/synthesis.py

fuck_clean:
	@$(MAKE) -C /home/yunhai/ysyx-workbench/yosys-sta clean

synth-single: $(SOC_DEPEMD)
	@python3 scripts/synthesis.py add 2000 clk "$(NPC_VSRC)"

A:
	$(MAKE) -C /home/yunhai/ysyx-workbench/yosys-sta sta \
           DESIGN=real_alu \
           CLK_FREQ_MHZ=1500 CLK_PORT_NAME=clk \
           RTL_FILES="/home/yunhai/ysyx-workbench/npc/sim/a.v"

.PHONY: verilog soc_run soc_gdb soc_wave clean perf_commit perf fuck sim-iverilog synth-single

include ../Makefile