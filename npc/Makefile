BUILD_DIR = ./build
TOP = ysyxSoCFull
VSRCS = ./../ysyxSoC/build/ysyxSoCFull.v
VSRCS += ./vsrc/ysyx_24110017.v
VSRCS += $(shell find ./../ysyxSoC/perip -name "*.v")
CSRCS += $(shell find ./csrc -name "*.c" -or -name "*.cc" -or -name "*.cpp")
INC_COM_PATH = ./csrc/include
INC_UART_PATH = ./../ysyxSoC/perip/uart16550/rtl
INC_SPI_PATH = ./../ysyxSoC/perip/spi/rtl

#verilator
VERILATOR = verilator
VERILATOR_FLAGS += -MMD -x-assign fast --trace --cc --build
#fast
VERILATOR_FLAGS += -O3 --x-initial fast
VERILATOR_FLAGS += -CFLAGS "-O3" -LDFLAGS "-O3"

VERILATOR_FLAGS += -CFLAGS -I$(INC_PATH) -I$(INC_COM_PATH) -I$(INC_UART_PATH) -I$(INC_SPI_PATH)
VERILATOR_FLAGS += -CFLAGS $(CXXFLAGS)
VERILATOR_FLAGS += -CFLAGS -g
VERILATOR_FLAGS += -LDFLAGS "$(LDFLAGS) $(LIBS)"
VERILATOR_FLAGS += -LDFLAGS -lreadline
VERILATOR_FLAGS += --top-module $(TOP)
VERILATOR_FLAGS += --timescale "1ns/1ns" --no-timing
VERILATOR_FLAGS += --autoflush
#静态检查
#VERILATOR_FLAGS += --lint-only -Wall
#VERILATOR_FLAGS += -Wno-DECLFILENAME -Wno-UNUSED

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

#nvboard
NXDC_FILES = ./constr/top.nxdc
INC_NVBOARD_PATH = ./../nvboard/usr/include
SRC_AUTO_BIND = $(BUILD_DIR)/auto_bind.cpp
$(SRC_AUTO_BIND): $(NXDC_FILES) | $(BUILD_DIR)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@
CSRCS += $(SRC_AUTO_BIND)
include $(NVBOARD_HOME)/scripts/nvboard.mk

#gtkwave
GTKWAVE = gtkwave

#iverilog
IVERILOG = iverilog
VVP = vvp
OBJCOPY = objcopy
IVERILOG_FLAGS = -g2012 -Wall
IVSRC = ./vsrc/ysyx_24110017_itestbench.v
IVSRC += ./vsrc/ysyx_24110017.v
NETLIST_VSRC = ./ysyx_24110017_testbench.v
NETLIST ?= ./ysyx_24110017.netlist.fixed.v
NETLIST_VSRC += $(NETLIST)
CELLS ?= cells.v
NETLIST_VSRC += $(CELLS)
ICOMPILED = $(BUILD_DIR)/ysyx_24110017_iverilog.vpp
ICOMPILED-NETLIST = $(BUILD_DIR)/ysyx_24110017_iverilog_netlist.vpp
MEMORY_HEX = $(BUILD_DIR)/memory_iverilog.hex
VMA_ADJUST ?= 0x0
#LLVM
LDFLAGS += $(shell llvm-config --ldflags) -fPIE
LDFLAGS += -fsanitize=address#ASan
LIBS += $(shell llvm-config --libs)
LDLIBS := -lasan $(LDLIBS)

#传入参数
LOG ?= $(BUILD_DIR)/npc-log.txt
IMG ?= ../am-kernels/tests/cpu-tests/build/dummy-riscv32e-npc.bin
ELF ?= ../am-kernels/tests/cpu-tests/build/dummy-riscv32e-npc.elf
REF_SO ?= ../nemu/build/riscv32-nemu-interpreter-so
ARGS += --log=$(LOG)
ARGS += --img=$(IMG)
ARGS += --elf=$(ELF)
ARGS += --diff=$(REF_SO)
ARGS += -b

run: $(BUILD_DIR) compile
	ASAN_OPTIONS=new_delete_type_mismatch=0 $(BUILD_DIR)/V$(TOP) $(ARGS)

compile: $(CSRCS) $(VSRCS) $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	@$(VERILATOR)  $(VERILATOR_FLAGS) --Mdir $(BUILD_DIR) --exe $^

perf:
	make -C ../am-kernels/benchmarks/microbench ARCH=riscv32e-ysyxsoc mainargs=test run
	
sim-iverilog: $(MEMORY_HEX) $(ICOMPILED) run_sim_iverilog

sim-iverilog-netlist: $(MEMORY_HEX) $(ICOMPILED-NETLIST) run_sim_iverilog_netlist

$(MEMORY_HEX): $(IMG) | $(BUILD_DIR)
	$(OBJCOPY) -I binary -O verilog --adjust-vma=$(VMA_ADJUST) $(IMG) $(MEMORY_HEX)

$(ICOMPILED): $(IVSRC) | $(BUILD_DIR)
	$(IVERILOG) $(IVERILOG_FLAGS) -o $@ $^

$(ICOMPILED-NETLIST): $(NETLIST_VSRC) | $(BUILD_DIR)
	$(IVERILOG) $(IVERILOG_FLAGS) -o $@ $^

run_sim_iverilog: $(ICOMPILED)
	$(VVP) $(ICOMPILED)

run_sim_iverilog_netlist: $(ICOMPILED-NETLIST)
	$(VVP) $(ICOMPILED-NETLIST)

wave:
	$(GTKWAVE) $(BUILD_DIR)/wave.vcd

clean:
	rm -rf $(BUILD_DIR)

verilog: $(BUILD_DIR)
	iverilog -E -Dysyx_24110017_YOSYS_STA vsrc/ysyx_24110017.v -o $(BUILD_DIR)/ysyx_24110017.v

.PHONY: clean run wave $(MEMORY_HEX) wave.vcd compile icompile compile-netlist run_sim_iverilog sim-iverilog sim-iverilog-netlist verilog

include ../Makefile
