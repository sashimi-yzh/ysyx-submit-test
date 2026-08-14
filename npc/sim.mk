TOPNAME = minirv_top
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CPPSRC = csrc/$(TOPNAME)_sim_main.cpp
VFLAGS = -cc -exe --build -j 0 --trace-fst --top-module $(TOPNAME) -Ivsrc/minirv

OBJ_DIR = obj_dir

all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	@mkdir -p waveform
	verilator $(VFLAGS) $(CPPSRC) $(VSRCS)
	$(OBJ_DIR)/V$(TOPNAME)

clean:
	rm -rf $(OBJ_DIR)

wave:
	gtkwave waveform/$(TOPNAME)_waveform.fst
include ../Makefile
