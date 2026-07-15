include ../Makefile
include $(NVBOARD_HOME)/scripts/nvboard.mk

TOP = ysyxSoCFull
BUILD_DIR = build
OBJCOPY = riscv64-linux-gnu-objcopy
VSRCS = $(shell find $(abspath ../ysyxSoC/perip) $(abspath ../ysyxSoC/build) -name "*.v") ./$(BUILD_DIR)/ysyx_26040125.v
CSRCS = $(shell find $(abspath ./csrc/src) -name "*.cpp")
CONFIG_H = $(abspath ./csrc/include/config.hpp)

#LIBCAPSTONE = ./csrc/capstone/repo/libcapstone.so.5
CFLAGS = -I$(abspath ./csrc/include) #-I$(abspath ./csrc/capstone/repo/include)
LDFLAGS = -lreadline #-lcapstone -L$(abspath ./csrc/capstone/repo)

#=============NVBOARD=============
BIND_FILE = $(abspath ./board/auto_bind.cpp)
LDFLAGS += $(NVBOARD_ARCHIVE) -lSDL2 -lSDL2_image -lSDL2_ttf
CFLAGS += -I$(abspath $(NVBOARD_HOME)/usr/include)
XDC_FILE = $(abspath ./board/myxdc.nxdc)

$(BIND_FILE): $(XDC_FILE)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@
#================================

VERILATOR_FLAGS = --build --trace --cc --exe --Mdir $(BUILD_DIR) --top $(TOP)\
--timescale "1ns/1ns"\
--no-timing\
-I$(abspath ./vsrc)\
-I$(abspath ../ysyxSoC/perip/uart16550/rtl)\
-I$(abspath ../ysyxSoC/perip/spi/rtl)\
$(addprefix -CFLAGS ,$(CFLAGS)) $(addprefix -LDFLAGS ,$(LDFLAGS))

./$(BUILD_DIR)/V$(TOP): $(VSRCS) $(CSRCS) $(CONFIG_H) $(BIND_FILE) $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator $(VERILATOR_FLAGS) $(VSRCS) $(CSRCS) $(BIND_FILE)

# ./csrc/src/disasm.cpp: $(LIBCAPSTONE)

# $(LIBCAPSTONE):
# 	$(MAKE) -C ./csrc/capstone

run: ./$(BUILD_DIR)/V$(TOP)
	$^ $(IMG) $(ELF)

sim-iverilog: ./iverilog-sim/ysyx_26040125.v $(IMG) ./iverilog-sim/RAM.v ./iverilog-sim/tb.v
	mkdir -p $(BUILD_DIR)
	$(OBJCOPY) -I binary -O verilog $(IMG) $(IMG:.bin=.hex)
	iverilog -g2012 -DHEX_PATH=\"$(IMG:.bin=.hex)\" -o ./$(BUILD_DIR)/simv ./iverilog-sim/ysyx_26040125.v ./iverilog-sim/RAM.v ./iverilog-sim/tb.v
	./$(BUILD_DIR)/simv -fst

sim-iverilog-netlist: $(IMG) $(NETLIST) $(CELLS)
	mkdir -p $(BUILD_DIR)
	$(OBJCOPY) -I binary -O verilog $(IMG) $(IMG:.bin=.hex)
	iverilog -g2012 -DHEX_PATH=\"$(IMG:.bin=.hex)\" -o ./$(BUILD_DIR)/simv ./iverilog-sim/RAM.v ./iverilog-sim/tb.v $(NETLIST) $(CELLS)
	./$(BUILD_DIR)/simv -fst

verilog: ./$(BUILD_DIR)/ysyx_26040125.v

./$(BUILD_DIR)/ysyx_26040125.v: ./iverilog-sim/ysyx_26040125.v
	mkdir -p $(BUILD_DIR)
	cp ./iverilog-sim/ysyx_26040125.v ./$(BUILD_DIR)/ysyx_26040125.v
	sed -i "s/PC <= 32'h8000_0000/PC <= 32'h3000_0000/g" ./$(BUILD_DIR)/ysyx_26040125.v

clean:
	rm -rf $(BUILD_DIR)


