TOPNAME=ALU
NXDC_FILES=./top.nxdc
include $(NVBOARD_HOME)/scripts/nvboard.mk
VERILATOR_FLAGS=--cc --exe --build --trace --top-module $(TOPNAME) -Wall
INC_PATH ?=
SRC_AUTO_BIND = $(abspath ./obj_dir/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	mkdir ./obj_dir
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@
SIM_C = csrc/*.cpp
SIM_C += ./obj_dir/auto_bind.cpp
SIM_V=vsrc/*.v
all:
	@echo "Write this Makefile by your self."

INCFLAGS=$(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
sim: $(SRC_AUTO_BIND) $(SIM_C) $(SIM_V) $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator $(VERILATOR_FLAGS) -Wall --top-module $(TOPNAME) $^ $(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS))
	./obj_dir/V$(TOPNAME)
	@echo "Write this Makefile by your self."
wave:
	gtkwave wave.vcd
clean:
	rm -rf obj_dir wave.vcd wave.fst
include ../Makefile
