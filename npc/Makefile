# 在命令行没有定义的话，后续使用的ARCH就是riscv32e-npc
ARCH ?= riscv32e-npc
TOPNAME ?= ysyxSoCFull

#设置构建文件夹信息
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

# 一些配置信息
REWRITE = $(NPC_HOME)/script/rewrite.mk

#verilator variable
ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
endif

# ARCH logic
ARCHS = $(basename $(notdir $(shell ls $(AM_HOME)/scripts/*.mk)))
ifeq ($(filter $(ARCHS), $(ARCH)), )
  $(error Expected $$ARCH in {$(ARCHS)}, Got "$(ARCH)")
endif
# Print build info message
-include $(NPC_HOME)/script/arch/$(ARCH).mk

# nvboard
# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

#sim
include $(NPC_HOME)/script/sim.mk

#trace
# rules for trace
include $(NPC_HOME)/script/trace.mk

#main makefile in all project
include ../Makefile

COLOR_RED   		= \033[1;31m
COLOR_GREEN 		= \033[1;32m
COLOR_YELLOW 		= \033[33m
COLOR_NONE  		= \033[0m

clean:
	-rm -rf $(BUILD_DIR) tools/performance-trace/*.png tools/performance-trace/*.txt


# CI使用


# 生成经过预处理的Verilog文件，方便静态时序分析工具进行分析
verilog:
	mkdir -p $(BUILD_DIR)
	iverilog -E -D__ICARUS__ vsrc/ysyx_24100006.v -o $(BUILD_DIR)/ysyx_24100006.v


# iverilog仿真相关
IVERILOG = iverilog
VVP = vvp
OBJCOPY = objcopy
IVERILOG_FLAGS = -g2012 -Wall
NPC ?= 1
DEFINES :=
ifeq ($(NPC),1)
  DEFINES += -DNPC -DVERILATOR_SIM
endif

NET_DEFINES ?= -DNET


# 四值仿真源文件
IVSRC = ./vsrc/ysyx_24100006_i_testbench.v
IVSRC += ./vsrc/ysyx_24100006.v
IVSRC += ./vsrc/ysyx_24100006_mem.v
IVSRC += ./vsrc/ysyx_24100006_uart.v

# 网表仿真源文件
NETLIST_VSRC = ./ysyx_24100006_net_testbench.v
NETLIST ?= ./ysyx_24100006.netlist.syn.v
NETLIST_VSRC += $(NETLIST)
NETLIST_VSRC += ./vsrc/ysyx_24100006_mem.v
NETLIST_VSRC += ./vsrc/ysyx_24100006_uart.v
CELLS ?= ./vsrc/cells.v
NETLIST_VSRC += $(CELLS)

# 编译结果存放
ICOMPILED = $(BUILD_DIR)/ysyx_24100006_iverilog.vpp
ICOMPILED-NETLIST = $(BUILD_DIR)/ysyx_24100006_iverilog_netlist.vpp
MEMORY_HEX = $(BUILD_DIR)/memory_iverilog.hex
VMA_ADJUST ?= 0x0


$(MEMORY_HEX): $(IMG)
	@if [ ! -f "$(IMG)" ]; then \
		echo -e "$(COLOR_RED)Error: IMG file not found: $(IMG)$(COLOR_NONE)"; \
		echo "Please make sure the AM application is built first:"; \
		echo "  make -C ~/ysyx-workbench/am-kernels/tests/am-tests ARCH=riscv32e-npc"; \
		exit 1; \
	fi
	mkdir -p $(BUILD_DIR)
	$(OBJCOPY) -I binary -O verilog --adjust-vma=$(VMA_ADJUST) $(IMG) $(MEMORY_HEX)

# 四值仿真的规则
$(ICOMPILED): $(IVSRC)
	$(IVERILOG) $(IVERILOG_FLAGS) $(DEFINES) -o $@ $^

run_sim_iverilog: $(ICOMPILED)
	$(VVP) $(ICOMPILED) +img=$(MEMORY_HEX)

sim-iverilog: $(MEMORY_HEX) $(ICOMPILED) run_sim_iverilog

# 网表仿真结果
$(ICOMPILED-NETLIST): $(NETLIST_VSRC)
	$(IVERILOG) $(IVERILOG_FLAGS) $(NET_DEFINES) -o $@ $^

run_sim_iverilog_netlist: $(ICOMPILED-NETLIST)
	$(VVP) $(ICOMPILED-NETLIST) +img=$(MEMORY_HEX)

sim-iverilog-netlist: $(MEMORY_HEX) $(ICOMPILED-NETLIST) run_sim_iverilog_netlist

.PHONY:clean run $(MEMORY_HEX) run_sim_iverilog sim-iverilog sim-iverilog-netlist verilog 