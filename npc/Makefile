.DEFAULT_GOAL := all

-include $(NPC_HOME)/include/config/auto.conf
-include $(NPC_HOME)/include/config/auto.conf.cmd

MK = $(shell find $(NPC_HOME)/scripts -name "*.mk")
include $(MK)

ci_test = 1

WAVE_ENABLE = 0

# 1: vcd, 2: fst
WAVE_FORMAT = 1

GUEST_ISA = riscv32

ifeq ($(CONFIG_NVBOARD),y)
NXDC_FILES = constr/top.nxdc
# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk
endif

################## TOPNAME #######################
ifeq ($(CONFIG_SOC),y)

TOPNAME = ysyxSoCFull

else

ifeq ($(CONFIG_ICARUS),y)
TOPNAME = ysyx_25110270_top_tb
else
TOPNAME = ysyx_25110270_top
endif

endif
#############################################


################## VERILATOR FLAGS #####################
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc --autoflush\
				-O3 --x-assign fast --x-initial fast -j 8
VERILATOR_CFLAGS += --timescale "1ns/1ns" --no-timing 

ifeq ($(CONFIG_SOC),y)
VERILATOR_CFLAGS += -Dysyx_25110270_SOC=1

ifeq ($(CONFIG_NOBOOTLOADER),y)
VERILATOR_CFLAGS += -Dysyx_25110270_NOBOOTLOADER=1
endif

VERILATOR_CFLAGS += -I$(sort $(dir $(shell find $(abspath ../ysyxSoC/perip/uart16550/rtl) -name "*.v")))
VERILATOR_CFLAGS += -I$(sort $(dir $(shell find $(abspath ../ysyxSoC/perip/spi/rtl) -name "*.v")))
endif

ifeq ($(CONFIG_NPC),y)
VERILATOR_CFLAGS += -Dysyx_25110270_NPC=1
endif

VERILATOR_CFLAGS += -I./vsrc
VERILATOR_CFLAGS += -Wno-WIDTHEXPAND


ifeq ($(WAVE_FORMAT),1)
VERILATOR_CFLAGS += --trace-vcd
else
VERILATOR_CFLAGS += --trace-fst
endif
#############################################

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

$(shell mkdir -p $(BUILD_DIR))

ifeq ($(CONFIG_NVBOARD),y)
# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@
endif

########################## SRCS #######################################

# project source
VSRCS-y ?= $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS-y ?= $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

VSRCS-SYM += $(shell find $(abspath ./vsrc) -name "ysyx_25110270.v")

ifeq ($(CONFIG_SOC),y)
VSRCS-y += $(shell find $(abspath ../ysyxSoC/perip) -name "*.v")
VSRCS-y += $(shell find $(abspath ../ysyxSoC/build) -name "ysyxSoCFull.v")
endif

ifeq ($(CONFIG_NVBOARD),y)
CSRCS-y += $(SRC_AUTO_BIND)
endif

VSRCS-BLACKLIST-y += $(VSRCS-BLACKLIST)
CSRCS-BLACKLIST-y += $(CSRCS-BLACKLIST)
VSRCS := $(filter-out $(VSRCS-BLACKLIST-y),$(VSRCS-y))
CSRCS := $(filter-out $(CSRCS-BLACKLIST-y),$(CSRCS-y))

###########################################################################

####################### C-FLAGS ##################################
INC_PATH += $(sort $(dir $(shell find $(abspath ./csrc) -name "*.h")))
INC_PATH += $(sort $(dir $(shell find $(abspath ./include) -name "*.h")))
# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))

CXXFLAGS += $(INCFLAGS) 
CXXFLAGS += -g -O2 -Wall -Werror -Wno-unused-result -Wno-unused-variable -Wno-unused-function
ifeq ($(CONFIG_NVBOARD),y)
CXXFLAGS += -Wno-sign-compare -Wno-delete-non-virtual-dtor
endif
# CXXFLAGS += -fsanitize=address -fno-omit-frame-pointer
CXXFLAGS += $(if $(CONFIG_CC_ASAN),-fsanitize=address -fno-omit-frame-pointer,)
CXXFLAGS += -mcmodel=medium
CXXFLAGS += -DTOP_NAME="V$(TOPNAME)"
ifeq ($(CONFIG_NVBOARD),y)
CXXFLAGS += -DCONFIG_USE_NVBOARD=1
endif
CXXFLAGS += -DWAVE_ENABLE=$(WAVE_ENABLE)
CXXFLAGS += -DWAVE_FORMAT=$(WAVE_FORMAT)

# CXXFLAGS += -fpermissive

# LDFLAGS += -lreadline -ldl -lm -lstdc++ -lpthread -lz -fsanitize=address -fno-omit-frame-pointer
LDFLAGS += -lreadline -ldl -lm -lstdc++ -lpthread -lz
LDFLAGS += $(if $(CONFIG_CC_ASAN),-fsanitize=address -fno-omit-frame-pointer,)

##################################################################################


###################################### BIN ########################################
ifneq ($(CONFIG_ICARUS),y)

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

else

IVERILOG_FLAGS += -pARRAY_SIZE_LIMIT=33554432
ifeq ($(WAVE_ENABLE),1)
IVERILOG_FLAGS += -Dysyx_25110270_WAVE=1
endif

FORCE:

$(BUILD_DIR)/test.data: $(IMG) FORCE
	riscv64-linux-gnu-objcopy -I binary -O verilog $< $@

$(BIN): $(VSRCS) $(BUILD_DIR)/test.data
	iverilog -s $(TOPNAME) -o $@ $(VSRCS) $(IVERILOG_FLAGS)

endif
########################################################################

############################### CI ##################################
ifeq ($(ci_test),1)

verilog:
	cp ./vsrc/ysyx_25110270.v $(BUILD_DIR)/ysyx_25110270.v

IVERILOG_FLAGS += -pARRAY_SIZE_LIMIT=33554432

IVSRC = ./vsrc/ysyx_25110270.v
SVSRC = $(NETLIST) $(CELLS) $(IVSRC)

ifneq ($(CELLS),)
IVERILOG_FLAGS += -Dysyx_25110270_NETSIM
endif
ifeq ($(WAVE_ENABLE),1)
IVERILOG_FLAGS += -Dysyx_25110270_WAVE=1
endif

sim-iverilog: $(IMG)
	riscv64-linux-gnu-objcopy -I binary -O verilog $< $(BUILD_DIR)/test.data
	iverilog -s ysyx_25110270_top_tb -o $(BUILD_DIR)/top_tb $(IVSRC) $(IVERILOG_FLAGS)
	vvp $(BUILD_DIR)/top_tb

sim-iverilog-netlist: $(IMG)
	riscv64-linux-gnu-objcopy -I binary -O verilog $< $(BUILD_DIR)/test.data
	iverilog -s ysyx_25110270_top_tb -o $(BUILD_DIR)/top_tb $(SVSRC) $(IVERILOG_FLAGS)
	vvp $(BUILD_DIR)/top_tb

endif
##################################################################


########################## SIM ###############################
override ARGS ?= --log=$(abspath $(BUILD_DIR))/npc-log.txt
override ARGS += $(ARGS_DIFF)

ifneq ($(CONFIG_ICARUS),y)

sim: $(BIN) $(IMG)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
ifeq ($(WAVE_ENABLE),1)
	-$(BIN) $(ARGS) $(IMG)
else
	$(BIN) $(ARGS) $(IMG)
endif

else

sim: $(BIN)
	$(call git_commit, "sim RTL with iverilog") # DO NOT REMOVE THIS LINE!!!
	vvp $(BIN)

endif
###############################################################

perf: 
	$(call git_commit, "sim RTL for perf") # DO NOT REMOVE THIS LINE!!!
	make -C $(NPC_HOME)/../am-kernels/benchmarks/microbench ARCH=riscv32e-ysyxsoc run mainargs=train

test: 
	$(call git_commit, "sim RTL for perf") # DO NOT REMOVE THIS LINE!!!
	make -C $(NPC_HOME)/../am-kernels/benchmarks/microbench ARCH=riscv32e-ysyxsoc run mainargs=test


view_wave:
ifeq ($(WAVE_FORMAT),1)
	@gtkwave -o $(NPC_HOME)/build/waveform.vcd
else
	@gtkwave -o $(NPC_HOME)/build/waveform.fst
endif

ifeq ($(WAVE_ENABLE),1)
run: sim view_wave
else
run: sim
endif

all: run

clean: 
	rm -rf $(BUILD_DIR) core.*

include ../Makefile

.PHONY: sim all clean run view_wave