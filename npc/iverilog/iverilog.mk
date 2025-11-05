DUT_IVG_VSRCS += $(NPC_HOME)/build/verilog/ysyx_23060246.sv 
SIM_IVG_VSRCS = $(NPC_HOME)/iverilog/top.v 
SIM_IVG_VSRCS += $(NPC_HOME)/iverilog/debug_iverilog.v 

BIN_IVG = $(BIN)_ivg

IVG_TOP = top


ifneq ($(CONFIG_WAVE_DUMP),)
IVG_FLAGS += -DCONFIG_WAVE_DUMP
endif 

ifeq ($(CONFIG_WAVE_VCD),y)
IVG_FLAGS += -DCONFIG_WAVE_VCD
else ifeq ($(CONFIG_WAVE_FST),y)
IVG_FLAGS += -DCONFIG_WAVE_FST
VVP_FLAGS += -fst
endif 


# ifeq ($(USE_SOC),y)
# IVG_FLAGS += -DUSE_SOC
# endif 


iverilog_build: verilog $(SIM_IVG_VSRCS)
	iverilog  -g2012 -s $(IVG_TOP) -DSMALL_MEM -DIMG_PATH=\"$(IMG).mem\" $(IVG_FLAGS) \
		 $(DUT_IVG_VSRCS) $(SIM_IVG_VSRCS) -o $(BIN_IVG)

iverilog_sim: bin2mem iverilog_build
	stdbuf -o0 -e0 vvp $(BIN_IVG) $(VVP_FLAGS) 


# NETLIST 仿真还不行
#VSRC_NETLIST = $(shell find $(abspath $(YOSYSSTA_PATH)/result/$(NPC_TOPNAME)-$(CLK_FREQ_MHZ)MHz) -name "*.netlist.syn.v")
NETLIST = ?
#VSRC_CELL = $(YOSYSSTA_PATH)/nangate45/sim/cells.v
CELLS = ?

iverilog_build_netlist:
	iverilog -g2012 -s $(IVG_TOP) -DSMALL_MEM -DIMG_PATH=\"$(IMG).mem\" $(IVG_FLAGS)\
		 $(NETLIST) $(CELLS) $(SIM_IVG_VSRCS) -o $(BIN_IVG)

iverilog_sim_netlist: iverilog_build_netlist bin2mem
	stdbuf -o0 -e0 vvp $(BIN_IVG) $(VVP_FLAGS)


sim-iverilog: iverilog_sim

sim-iverilog-netlist: iverilog_sim_netlist


bin2mem:
	xxd -e -g4 -c4 $(IMG) | awk '{print $$2}' > $(IMG).mem




