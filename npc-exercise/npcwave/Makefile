TOPNAME=top
VERILATOR_FLAGS=--cc --exe --build --trace --top-module $(TOPNAME) 
INC_PATH ?=
SIM_C = csrc/*.cpp
SIM_V=vsrc/*.v
all:
	@echo "Write this Makefile by your self."

INCFLAGS=$(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
sim: $(SIM_C) $(SIM_V) 
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator $(VERILATOR_FLAGS) --top-module $(TOPNAME) $^ $(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS))
	./obj_dir/V$(TOPNAME)
	@echo "Write this Makefile by your self."
wave:
	gtkwave wave.vcd
clean:
	rm -rf obj_dir wave.vcd wave.fst
include ~/ysyx-workbench/Makefile
