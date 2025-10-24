.PHONY: clean verilog run sim-iverilog sim-iverilog-netlist

STUID := ysyx_24080032
STUNAME = 杨鹏城

YSYXSOC ?= n
NPC ?= n
ifeq ($(ARCH), riscv32e-ysyxsoc)
YSYXSOC = y
NPC = n
else ifeq ($(ARCH), riscv32e-npc)
YSYXSOC = n
NPC = y
else
$(WARNING: ====================)
$(WARNING: ====UNKNOWN ARCH====)
$(WARNING: ====================)
endif

NVBOARD ?= n
ifeq ($(YSYXSOC), y)
NVBOARD = y
else
NVBOARD = n
endif


























# __     _______ ____  ___ _     ___   ____
# \ \   / / ____|  _ \|_ _| |   / _ \ / ___|
#  \ \ / /|  _| | |_) || || |  | | | | |  _
#   \ V / | |___|  _ < | || |__| |_| | |_| |
#    \_/  |_____|_| \_\___|_____\___/ \____|
# make -C $(NPC_HOME) verilog将会在$(NPC_HOME)/build文件夹下产生一个用于接入soc的npc(ysyx_24080032.sv),
# 复位是0x30000000

VERILOG_BUILD_DIR = $(NPC_HOME)/build
TEMP_VERILOG_DIR = $(VERILOG_BUILD_DIR)/verilog_obj
FIRTOOL_DIR = $(NPC_HOME)/
PRJ = playground
MILLFLAG = --target-dir $(TEMP_VERILOG_DIR)

OUTPUT_VERILOG_FILE = $(VERILOG_BUILD_DIR)/$(STUID).sv
INPUT_VERILOG_FILE = \
	ysyx_24080032.sv \
	ysyx_24080032_Core.sv \
	ysyx_24080032_Xbar.sv \
	ysyx_24080032_Clint.sv \
	ysyx_24080032_IFU.sv \
	ysyx_24080032_IDU.sv \
	ysyx_24080032_ISU.sv \
	ysyx_24080032_EXU.sv \
	ysyx_24080032_WBU.sv \
	ysyx_24080032_gpr_16x32.sv \
	ysyx_24080032_CSR.sv \
	ysyx_24080032_ALU.sv \
	ysyx_24080032_LSU.sv \
	ysyx_24080032_iCache.sv \
	ysyx_24080032_Ebreak.sv

verilog:
	echo "正在生成 Verilog 文件..."; \
	mkdir -p $(VERILOG_BUILD_DIR) $(TEMP_VERILOG_DIR); \
	mill -i $(PRJ).runMain Elaborate $(MILLFLAG); \
	cat $(addprefix $(TEMP_VERILOG_DIR)/, $(INPUT_VERILOG_FILE)) > $(OUTPUT_VERILOG_FILE); \




























# __     _______ ____  ___ _        _  _____ ___  ____
# \ \   / / ____|  _ \|_ _| |      / \|_   _/ _ \|  _ \
#  \ \ / /|  _| | |_) || || |     / _ \ | || | | | |_) |
#   \ V / | |___|  _ < | || |___ / ___ \| || |_| |  _ <
#    \_/  |_____|_| \_\___|_____/_/   \_\_| \___/|_| \_\
# 在am目录下的各个测试中执行make ARCH=??? run 将会跳转到这里执行verilator的仿真,
# 支持make ARCH=riscv32e-ysyxsoc run(将会接入ysyxSoC并执行verilator仿真) 顶层是ysyxSoCUFull,
# 支持make ARCH=riscv32e-npc run(将会直接对npc进行verilator仿真) 顶层是NPC.
# 注意如果debug要开启lightsss, 请关闭nvboard显示, 并打开ysyxsoc中串口的打印函数, 因为nvboard对于多子线程会产生显示出错问题

ifeq ($(YSYXSOC), y)
TOPNAME = ysyxSoCFull
CFLAGS += -DNPCCONFIG_TOP_IS_YSYXSOC
else ifeq ($(NPC), y)
TOPNAME = NPC
CFLAGS += -DNPCCONFIG_TOP_IS_NPC
endif

VERILATOR_BUILD_DIR = $(NPC_HOME)/build
TEMP_VERILATOR_DIR = $(VERILATOR_BUILD_DIR)/verilator_obj
BIN = $(VERILATOR_BUILD_DIR)/$(TOPNAME)

SOC_DIR = $(NPC_HOME)/../ysyxSoC

ifeq ($(YSYXSOC), y)
VSRC = $(OUTPUT_VERILOG_FILE)
VSRC += $(shell find $(abspath $(SOC_DIR)/build) -name "*.sv" -or -name "*.v")
VSRC += $(shell find $(abspath $(SOC_DIR)/perip) -name "*.sv" -or -name "*.v")
else ifeq ($(NPC), y)
# 如果是npc的verilator仿真, 那么复位值改成0x80000000
$(shell cp $(OUTPUT_VERILOG_FILE) $(NPC_HOME)/src/npc/)
$(shell sed -i "s/reg_pc <= 32'h30000000/reg_pc <= 32'h80000000/" \
	$(NPC_HOME)/src/npc/$(STUID).sv)
VSRC := $(shell find $(abspath $(NPC_HOME)/src/npc) -name "*.sv" -or -name "*.v")
endif
CSRC = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

VERIARG = --cc -MMD --build --trace-threads 2 --public-flat-rw -top $(TOPNAME) --trace-fst --no-timing --timescale "1ns/1ns" -I$(SOC_DIR)/perip/uart16550/rtl -I$(SOC_DIR)/perip/spi/rtl -O3 -j 16 --autoflush
LDFLAGS += -lSDL2 -lSDL2_image $(shell llvm-config --libs) -lreadline -ldl -pie
INC_PATH = $(abspath ./include)
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""



# CFLAGS += -DNPCCONFIG_PERF

# CFLAGS += -DNPCCONFIG_ITRACE
# CFLAGS += -DNPCCONFIG_FTRACE
# CFLAGS += -DNPCCONFIG_MTRACE
# CFLAGS += -DNPCCONFIG_WATCHPOINT

# CFLAGS += -DNPCCONFIG_DUMPWAVE
# CFLAGS += -DNPCCONFIG_LIGHTSSS

# 开启difftest需要打开chisel设计文件的val DIFFTEST = true, 注意开启了difftest将取消定义ci
# CFLAGS += -DNPCCONFIG_DIFFTEST





ifneq ($(findstring -DNPCCONFIG_DIFFTEST,$(CFLAGS)), -DNPCCONFIG_DIFFTEST)
CFLAGS += -DNPCCONFIG_CI
endif

ifneq ($(findstring -DNPCCONFIG_DUMPWAVE,$(CFLAGS)),)
ifneq ($(findstring -DNPCCONFIG_LIGHTSSS,$(CFLAGS)),)
$(error "不能同时定义 -DNPCCONFIG_DUMPWAVE 和 -DNPCCONFIG_LIGHTSSS")
endif
endif





#################
#####NVBOARD#####
#################
NVBOARD_DIR = $(NPC_HOME)/../nvboard

INC_PATH ?=

include $(NVBOARD_DIR)/scripts/nvboard.mk

NXDC_FILES = $(NPC_HOME)/nvboard/constr/$(TOPNAME).nxdc

SRC_AUTO_BIND = $(abspath $(NVBOARD_DIR)/scripts/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_DIR)/scripts/auto_pin_bind.py $^ $@

ifeq ($(NVBOARD), y)
CSRC += $(SRC_AUTO_BIND)
CFLAGS += -DNV_BOARD $(addprefix -I, $(INC_PATH))
endif


$(BIN): $(CSRC) $(VSRC) $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	rm -rf $(TEMP_VERILATOR_DIR)
	rm -rf $(BIN)
	verilator $(VERIARG) \
		$^ \
		$(addprefix -LDFLAGS , $(LDFLAGS)) \
		$(addprefix -CFLAGS , $(CFLAGS)) \
		--Mdir $(TEMP_VERILATOR_DIR) --exe -o $(abspath $(BIN))

run: clean $(BIN)
	@$(BIN) $(ARGS) $(IMG)


































# _____     _______ ____  ___ _     ___   ____
#|_ _\ \   / / ____|  _ \|_ _| |   / _ \ / ___|
# | | \ \ / /|  _| | |_) || || |  | | | | |  _
# | |  \ V / | |___|  _ < | || |__| |_| | |_| |
#|___|  \_/  |_____|_| \_\___|_____\___/ \____|

IVERILOG_DIR = $(NPC_HOME)/iverilog

IVERILOG_BUILD_DIR = $(IVERILOG_DIR)/build

IVERILOG_TB_SRC = $(IVERILOG_DIR)/tb/tb_top.sv
IVERILOG_MEM_SRC =  $(IVERILOG_DIR)/mem/Mem.sv
IVERILOG_V_SRC =  $(IVERILOG_DIR)/src/$(STUID).sv

IVERILOG_BIN_SRC = $(IMG)
IVERILOG_HEX_SRC = $(IVERILOG_DIR)/hex/code.hex
IVERILOG_PY_SRC = $(IVERILOG_DIR)/hex/makehex.py

IVERILOG_OUT = $(IVERILOG_BUILD_DIR)/top.vvp

sim-iverilog:
	@if [ -z "$(IMG)" ]; then \
		echo "ERROR: IMG has to be fed"; \
		exit 1; \
	fi

	@echo "INFO: ========================================"
	@echo "INFO: =======复制CPU代码到iverilog/src下======"
	@echo "INFO: ========================================"
	@cp $(OUTPUT_VERILOG_FILE) $(IVERILOG_V_SRC)

	@echo "INFO: ========================================"
	@echo "INFO: ===========通过bin产生hex文件==========="
	@echo "INFO: ========================================"
	@mkdir -p $(dir $(IVERILOG_HEX_SRC))
	@python $(IVERILOG_PY_SRC) $(IVERILOG_BIN_SRC) 33554432 > $(IVERILOG_HEX_SRC)

	@echo "INFO: ========================================"
	@echo "INFO: =============编译iverilog==============="
	@echo "INFO: ========================================"
	@mkdir -p $(dir $(IVERILOG_OUT))
	@iverilog -g2012 -Wall -D__ICARUS__ -o $(IVERILOG_OUT) \
		$(IVERILOG_TB_SRC) $(IVERILOG_MEM_SRC) $(IVERILOG_V_SRC)

	@echo "INFO: ========================================"
	@echo "INFO: ===========开始仿真iverilog============="
	@echo "INFO: ========================================"
	@vvp $(IVERILOG_OUT)

	@echo "INFO: ========================================"
	@echo "INFO: ===============仿真完成!================"
	@echo "INFO: ========================================"





sim-iverilog-netlist:
	@if [ -z "$(IMG)" ]; then \
		echo "ERROR: IMG has to be fed"; \
		exit 1; \
	fi
	@if [ -z "$(NETLIST)" ]; then \
		echo "ERROR: NETLIST has to be fed"; \
		exit 1; \
	fi
	@if [ -z "$(CELLS)" ]; then \
		echo "ERROR: CELLS has to be fed"; \
		exit 1; \
	fi

	@echo "INFO: ========================================"
	@echo "INFO: ======复制网表代码到iverilog/src下======"
	@echo "INFO: ========================================"
	@cp $(NETLIST) $(IVERILOG_V_SRC)

	@echo "INFO: ========================================"
	@echo "INFO: ===========通过bin产生hex文件==========="
	@echo "INFO: ========================================"
	@mkdir -p $(dir $(IVERILOG_HEX_SRC))
	@python $(IVERILOG_PY_SRC) $(IVERILOG_BIN_SRC) 33554432 > $(IVERILOG_HEX_SRC)

	@echo "INFO: ========================================"
	@echo "INFO: =============编译iverilog==============="
	@echo "INFO: ========================================"
	@mkdir -p $(dir $(IVERILOG_OUT))
	@iverilog -g2012 -Wall -D__ICARUS__ -DNETLIST -o $(IVERILOG_OUT) \
		$(IVERILOG_TB_SRC) $(IVERILOG_MEM_SRC) $(IVERILOG_V_SRC) $(CELLS)

	@echo "INFO: ========================================"
	@echo "INFO: ===========开始仿真iverilog============="
	@echo "INFO: ========================================"
	@vvp $(IVERILOG_OUT)

	@echo "INFO: ========================================"
	@echo "INFO: ===============仿真完成!================"
	@echo "INFO: ========================================"


clean:
	rm -rf $(NPC_HOME)/out $(TEMP_VERILATOR_DIR) $(TEMP_VERILOG_DIR) $(NPC_HOME)/build/NPC $(NPC_HOME)/build/ysyxSoCFull $(NPC_HOME)/build/*.fst




# 提交ci的时候记得./abstract-machine/scripts/isa/riscv.mk的编译工具riscv64-unknown-linux-gnu-     -->     riscv64-linux-gnu-
# 提交ci的时候记得关闭./npc/src/main/common/Config.scala中的DIFFTEST=false
