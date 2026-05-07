TOPNAME = ysyxSoCFull
NXDC_FILES = constr/top.nxdc
INC_PATH ?=

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR = ./obj_dir
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

NPC_HOME := $(shell pwd) 
YSYX_DIR := $(shell cd .. && pwd)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
VSRCS += $(shell find $(abspath ../ysyxSoC/perip) -name "*.v")
VSRCS += $(shell find $(abspath ../ysyxSoC/build) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""


DIFFTEST := ${NEMU_HOME}/build/riscv32-nemu-interpreter-so#	

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		+define+VERILATOR_SIM \
		+incdir+$(YSYX_DIR)/ysyxSoC/perip/uart16550/rtl \
		+incdir+$(YSYX_DIR)/ysyxSoC/perip/spi/rtl \
		--timescale "1ns/1ns" --no-timing \
		-CFLAGS "-mcmodel=medium" -LDFLAGS "-lreadline" \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN)) 
	
all:
	@echo "Write this Makefile by your self."

sim: $(VSRCS) $(CSRCS) 
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR) $(VERILATOR_CFLAGS)  --trace-fst --exe -Wno-DECLFILENAME --top-module $(TOPNAME) \
		+define+VERILATOR_SIM \
		+incdir+$(YSYX_DIR)/ysyxSoC/perip/uart16550/rtl \
		+incdir+$(YSYX_DIR)/ysyxSoC/perip/spi/rtl \
		--timescale "1ns/1ns" --no-timing --autoflush\
		-CFLAGS "-mcmodel=medium" -LDFLAGS "-lreadline" \
		$(VSRCS) $(CSRCS)
	./obj_dir/V$(TOPNAME) --diff=${DIFFTEST} $(IMG) 
#./obj_dir/V$(TOPNAME) --diff=${DIFFTEST} char-test2.bin
# ./obj_dir/V$(TOPNAME) --diff=${DIFFTEST} $(IMG)

verilog:
	mkdir -p build
	cp vsrc/ysyx_25050137.v build/ysyx_25050137.v


sim-iverilog: verilog
	mkdir -p build
	python3 -c "data=open('$(IMG)','rb').read(); f=open('build/mem.hex','w'); [f.write('@%08x %02x\n'%(i,data[i])) for i in range(len(data))]"
	iverilog -o build/sim_out -g2012 build/ysyx_25050137.v sim_top.v
	cd build && vvp sim_out

sim-iverilog-netlist:
	mkdir -p build
	python3 -c "data=open('$(IMG)','rb').read(); f=open('build/mem.hex','w'); [f.write('@%08x %02x\n'%(i,data[i])) for i in range(len(data))]"
	iverilog -o build/sim_out -g2012 $(NETLIST) $(CELLS) sim_top.v
	cd build && vvp sim_out

include ../Makefile

run: $(BIN)
	@$^ $(IMG)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run verilog sim-iverilog sim-iverilog-netlist
