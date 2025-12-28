TOPNAME = top


VERILATOR = verilator

VERILATOR_FLAGS += -O3 --x-assign fast --x-initial fast 
VERILATOR_FLAGS += -Wall
VERILATOR_FLAGS += --cc 
VERILATOR_FLAGS += --MMD
VERILATOR_FLAGS += --coverage
VERILATOR_FLAGS += --assert
VERILATOR_FLAGS += --build
VERILATOR_FLAGS += --trace
VERILATOR_FLAGS += --Wno-UNUSED
VERILATOR_FLAGS += --Wno-UNDRIVEN
VERILATOR_FLAGS += --Wno-ASSIGNDLY
VERILATOR_FLAGS += --Wno-DECLFILENAME
VERILATOR_FLAGS += --Wno-DEFPARAM
VERILATOR_FLAGS += --Wno-PINCONNECTEMPTY
VERILATOR_FLAGS += --Wno-SYNCASYNCNET
VERILATOR_FLAGS += --Wno-WIDTHEXPAND
VERILATOR_FLAGS += --autoflush
WORK_DIR = $(shell pwd)
BUILD_DIR = $(WORK_DIR)/build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

VS_DIR = $(WORK_DIR)/vsrc
VSRCS = $(shell find $(VS_DIR) -name "*.v")

CXXFLAGS += $(shell llvm-config --cxxflags) -fPIE
CS_DIR = $(WORK_DIR)/csrc
CSRCS = $(shell find $(CS_DIR) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

INC_PATH = $(abspath ./csrc/include)
INC_PATH += $(abspath ./obj_dir)
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += -O2 -MMD -Wall  $(INCFLAGS) -Og -ggdb3 -g

LDFLAGS += $(shell llvm-config --libs) 
LDFLAGS += -O2 -Og -ggdb3 -ldl -pie -lreadline 
VERILATOR_FLAGS += $(addprefix -CFLAGS , $(CFLAGS) $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS))


VERILATOR_OUTFLAGS += --Mdir $(OBJ_DIR) 

# Along with sim_main.cpp wrapper file, so the build will create an executable instead of only a library
VERILATOR_OUTFLAGS += --exe

# Specify the name for the executable built if using --exe. Default to the --prefix if not specified
VERILATOR_OUTFLAGS += -o $(abspath $(BIN))



$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	@$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module $(TOPNAME) $^ \
		$(NVBOARD_FLAGS) \
		$(VERILATOR_OUTFLAGS) 



NPC_FLAGS += $(ARGS)

NPC_FLAGS +=  --log=$(BUILD_DIR)/npc-log.txt

NPC_FLAGS += --diff=$(NEMU_HOME)/build/riscv32-nemu-interpreter-so

# image file from abstract_machine
#make run IMG=~/ysyx-workbench/am-kernels/tests/cpu-tests/build/add-riscv32e-npc.bin

IMG ?=
NPC_FLAGS += $(IMG)


WAVEFLAGS = gtkwave $(BUILD_DIR)/logs/$(TOPNAME).vcd


all : default

wave :  ./build/top
	gtkwave *.vcd



gdb : $(BIN)
	@gdb --args $(BIN) $(NPC_FLAGS) 

run: $(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@$(BIN) $(NPC_FLAGS)
	

clean :
	@rm -rf $(BUILD_DIR)
 
	

