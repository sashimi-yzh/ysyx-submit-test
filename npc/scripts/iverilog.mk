
IVERILOG := iverilog
TARGET = $(WORK_DIR)/simulation/build/iverilog-npc
TARGET_NET = $(WORK_DIR)/simulation/build/iverilog-npc-net
TB_FILE ?= $(WORK_DIR)/simulation/npc_tb.v
OBJCOPY := riscv64-linux-gnu-objcopy
AM_HOME ?= $(YSYX_HOME)/abstract-machine
CPU_TEST_PATH := $(YSYX_HOME)/am-kernels/tests/cpu-tests/build/
IMAGE ?= movsx
# IMG ?= $(CPU_TEST_PATH)$(IMAGE)-riscv32e-npc.bin ## cputest
# IMG ?= $(YSYX_HOME)/am-kernels/tests/am-tests/build/amtest-riscv32e-npc.bin
IMG ?= $(YSYX_HOME)/am-kernels/benchmarks/microbench/build/microbench-riscv32e-npc.bin ## microbench
# IMG ?= /home/long/clone/rt-thread-am/bsp/abstract-machine/build/rtthread-riscv32e-npc.bin ## RTT 
SIM_BIN_TMP := $(WORK_DIR)/simulation/build/iverilog_bin.tmp
SIM_HEX := $(WORK_DIR)/simulation/build/iverilog_npc.hex
EXCLUDE_FILES := \
    $(WORK_DIR)/vsrc/device/uart.v \
    $(WORK_DIR)/vsrc/crossbar.v \
    $(WORK_DIR)/vsrc/IFU/ysyx_25020042_PC.v
SIM_VSRCS := $(WORK_DIR)/vsrc/device/ysyx_25020042_mem.v \
	$(WORK_DIR)/build/ysyx_25020042.v

NETLIST ?= /home/long/clone/yosys-sta/result/ysyx_25020042-500MHz/ysyx_25020042.netlist.fixed.v
CELLS ?= /home/long/clone/yosys-sta/nangate45/sim/cells.v

SIM_VSRCS_NET :=  $(NETLIST) \
    $(CELLS) \
    $(WORK_DIR)/vsrc/device/ysyx_25020042_mem.v


IVERILOG_PRE_FLAGS ?= -Wall -g2012 
IVERILOG_PRE_FLAGS += -DHEX_FILE=\"$(SIM_HEX)\"
IVERILOG_OUT_FLAG = -o $(TARGET)

iwave: $(WORK_DIR)/simulation/build/npc_wave.vcd
	gtkwave $(WORK_DIR)/simulation/build/npc_wave.vcd

# $(WORK_DIR)/simulation/build/npc_wave.vcd: iverilog

sim-iverilog: $(SIM_HEX) $(TARGET)
	vvp $(TARGET)

sim-iverilog-netlist: $(SIM_HEX) $(TARGET_NET)
	@echo + RUN yosys-sta...
	vvp $(TARGET_NET)

$(TARGET): $(TB_FILE) $(SIM_VSRCS)
	@mkdir -p $(WORK_DIR)/simulation/build
	$(IVERILOG) $(IVERILOG_PRE_FLAGS) $^ $(IVERILOG_OUT_FLAG)

$(TARGET_NET): $(TB_FILE) $(SIM_VSRCS_NET)
	@mkdir -p $(WORK_DIR)/simulation/build
	$(IVERILOG) $(IVERILOG_PRE_FLAGS) $^ -o $(TARGET_NET)

$(SIM_HEX): $(IMG)
	@mkdir -p $(WORK_DIR)/simulation/build
	@echo + COPY $(IMG) "->" $(SIM_BIN_TMP)
	@cp $(IMG) $(SIM_BIN_TMP)
	@echo + OBJCOPY "->" $(SIM_HEX) "(verilog hex)"
	@$(OBJCOPY) -I binary -O verilog $(SIM_BIN_TMP) $(SIM_HEX)
	@rm -f $(SIM_BIN_TMP)

cleaniverilog:
	rm $(WORK_DIR)/simulation/build/*

.PHONY: iverilog netlist cleaniverilog

