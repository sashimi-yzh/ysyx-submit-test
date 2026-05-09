TOPNAME = ysyx_25040102
NXDC_FILES = constr/top.nxdc
INC_PATH ?=
 
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert
 
BUILD_DIR = $(NPC_HOME)/build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)
YSYX_FILE = $(NPC_HOME)/build/$(TOPNAME).v

# EXCLUDE_FILE = ./vsrc/cpu_top.v

HEX_PATH = $(BUILD_DIR)/hex_file

default: $(BIN)
 
$(shell mkdir -p $(BUILD_DIR))
 
# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@


AM_HOME = $(YSYX_HOME)/abstract-machine
 
# project source
VSIM = $(shell find $(abspath ./sim_file/sim_npc) -name "*.v")
VSIM_NETLIST = $(shell find $(abspath ./sim_file/sim_npc_netlist) -name "*.v")
# VSRCS = $(shell find $(abspath ./vsrc) -name "*.v" -or -name "*.vh" )
NPC_TOP = ./sim_file/sim_npc/npc_top.v
VIVERILOG = /home/dengzibin/ysyx-workbench/npc/build/cpu/ysyx_25040102.v
VNETLIST = $(shell find $(abspath ./build/netlist) -name "*.v" -or -name "*.vh" )
VHFILE = $(shell find $(abspath ./vsrc) -name "*.vh")
VHSRCS = $(NPC_HOME)/vsrc
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
VSRCS_NPC = $(shell find $(abspath ./vsrc_npc) -name "*.v" )
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCSS = $(shell find $(abspath ./csrc/src) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)
 
# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk
 
# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

NPC_DEFINE = -Dysyx_25040102_SIM
# NPC_DEFINE += -Dysyx_25040102_DIFFTEST
NPC_DEFINE += -Dysyx_25040102_NPC=32\'h80000000

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default

$(YSYX_FILE): $(VHFILE) $(VSRCS)
	cat $^ > $@
	sed -i '/`include "npc_config.vh"/d' $@

verilog: $(YSYX_FILE)

run:
	verilator -Wno-fatal --cc $(VSRCS) $(NPC_TOP) $(VSRCS_NPC) -I$(VHSRCS) $(NPC_DEFINE) $ --exe $(CSRCSS) -LDFLAGS -lreadline -CFLAGS "-I/home/dengzibin/ysyx-workbench/npc/csrc/include"\
		--top-module npc_top --trace-fst --autoflush
	make -C ./obj_dir -f Vnpc_top.mk Vnpc_top
	./obj_dir/Vnpc_top $(ARGS) $(IMG)

sim-iverilog: $(YSYX_FILE)
	mkdir -p $(HEX_PATH) 
	python3 $(AM_HOME)/tools/bin2hex.py $(IMG) $(HEX_PATH)/$(basename $(notdir $(IMG))).hex 4
	iverilog -g2012 -o $(BUILD_DIR)/iverilog_sim $(VSIM) $(YSYX_FILE) $(VSRCS_NPC) -Dysyx_25040102_NPC=32\'h80000000
	vvp $(BUILD_DIR)/iverilog_sim -fst +HEX_FILE=$(HEX_PATH)/$(basename $(notdir $(IMG))).hex

sim-iverilog-netlist: 
	mkdir -p $(HEX_PATH)
	python3 $(AM_HOME)/tools/bin2hex.py $(IMG) $(HEX_PATH)/$(basename $(notdir $(IMG))).hex 4
	iverilog -g2012 -o $(BUILD_DIR)/iverilog_sim_netlist $(VSIM_NETLIST) $(NETLIST) $(CELLS) $(VSRCS_NPC) -Dysyx_25040102_NPC=32\'h80000000
	vvp $(BUILD_DIR)/iverilog_sim_netlist -fst +HEX_FILE=$(HEX_PATH)/$(basename $(notdir $(IMG))).hex

run_nv: $(BIN)
	@$^

cat: 
	cat $(VHSRCS) $(VSRCS) > ./build/cpu/ysyx_25040102.v
	sed -i '/`include "npc_config.vh"/d' ./build/cpu/ysyx_25040102.v
	cp ./build/cpu/ysyx_25040102.v $(YSYXSOC_HOME)/build/cpu
# 	cp ./build/cpu/ysyx_25040102.v ./vsrc_npc/
	sed -i 's/`define ysyx_25040102_NPC 32'"'"'h80000000/`define ysyx_25040102_NPC 32'"'"'h30000000/g' $(YSYXSOC_HOME)/build/cpu/ysyx_25040102.v

clean:
	rm -rf $(BUILD_DIR)
 
.PHONY2: default all clean run

debug:
	@echo "All files found:"
	@echo "\nFiles after exclusion:"
	@echo $(VSRCS)