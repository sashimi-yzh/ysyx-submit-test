TOP=tb

BUILD_DIR=./build
OBJ_DIR = ./build/obj
VSRC_DIR = ./vsrc
INC_FLAGS = +incdir+$(VSRC_DIR)


PLATFORM=LINUX64

VCS_LOG=./build/vcs.log
SIM_LOG=./build/sim.log
FILE_LIST_F=./build/file.list.f
VCS_CSRC_DIR=./build/vcs/csrc
BIN=./build/simv
CFLAGS = 
VCS_FLAGS = -full64 -notice -kdb -lca -debug_acc+all \
		+dmptf +warn=all +libext+.v+v2k+acc -sverilog -timescale=1ns/1ns
#-R +fsdb+autoflush

ifeq ($(NETLIST),1)
CFLAGS += -DNETLIST
endif


ifeq ($(NETLIST),1)
VCS_VSRCS = $(shell find $(abspath ./build/netlist) -name "*.netlist.syn.v") # ysyx_23060246.netlist.v
VCS_VSRCS += $(shell find $(abspath ./build/nangate45) -name "*.v") # cells.v
else
VCS_VSRCS = $(shell find $(abspath ./build/verilog) -name "*.sv") # ysyx_23060246
endif
VCS_VSRCS += $(shell find $(abspath ./build/verilog) -name "*.v") # YsyxSoCFull.v
VCS_VSRCS += $(shell find $(abspath ./build/perip) -name "*.v"  -or -name "*.sv")
VCS_VSRCS += $(shell find $(abspath ./vsrc) -name "*.v")
VCS_VSRCS += $(shell find $(abspath ./vcs/vsrc) -name "*.v")
VCS_CSRCS = $(shell find $(abspath ./vcs/csrc) -name "*.c")
INC_FLAGS += +incdir+./vcs/csrc
INC_FLAGS += +incdir+./build/perip/perip/spi/rtl/
INC_FLAGS += +incdir+./build/perip/perip/uart16550/rtl

default: $(BIN)


$(FILE_LIST_F): $(VCS_VSRCS)
	$(shell mkdir -p $(BUILD_DIR))

	$(shell printf '%s\n' $(VCS_VSRCS) > $(FILE_LIST_F))


	

$(BIN): $(FILE_LIST_F)
	vcs	$(INC_FLAGS) -l $(VCS_LOG) $(VCS_FLAGS)\
		-P $(VERDI_HOME)/share/PLI/VCS/$(PLATFORM)/novas.tab\
		$(VERDI_HOME)/share/PLI/VCS/$(PLATFORM)/pli.a\
		-f $(FILE_LIST_F) $(VCS_CSRCS)\
		-cflags "$(CFLAGS)" \
		-Mdir=$(OBJ_DIR) -o $(BIN) -top $(TOP)

sim: $(BIN)
	cd $(BUILD_DIR) && ./$(shell basename $^)\
		 -l $(abspath $(SIM_LOG))

all: default


clean:
	-rm -rf $(BUILD_DIR) 
