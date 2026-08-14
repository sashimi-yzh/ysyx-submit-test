TOPNAME = riscv32e_top
VSRCS = $(shell find $(abspath ./vsrc/riscv32e-single) -name "*.v")
CPPSRC = $(shell find $(abspath ./csrc/riscv32e-single) -name "*.cpp")
VFLAGS = -cc -exe --build -j 0 --trace-fst --top-module $(TOPNAME) -O3 --x-initial fast --autoflush -Ivsrc/riscv32e-single --timescale "1ns/1ns" --no-timing
IMG ?= resource/mem.bin
ELF ?= 
OBJ_DIR = obj_dir

LIBCAPSTONE = $(NEMU_HOME)/tools/capstone/repo/libcapstone.so.5
$(LIBCAPSTONE):
	make -C $(NEMU_HOME)/tools/capstone

LIBNEMU-DIFF = $(NEMU_HOME)/build/riscv32-nemu-interpreter-so
# -DCONFIG_WAVEFORM
CFLAGS = $(patsubst %, -CFLAGS %, -I$(NEMU_HOME)/tools/capstone/repo/include -I$(abspath ./csrc/riscv32e-single/include) )
LDFLAGS = $(patsubst %, -LDFLAGS %, -lreadline -ldl)
all:
	@echo "Write this Makefile by your self."

NPCARGS = --diff=$(LIBNEMU-DIFF) -b --elf=$(ELF) $(IMG)

sim: $(LIBCAPSTONE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	@mkdir -p waveform
	make -C $(NEMU_HOME)
	verilator $(VFLAGS) $(CFLAGS) $(LDFLAGS) $(CPPSRC) $(VSRCS)
	echo $(NPCARGS)
	$(OBJ_DIR)/V$(TOPNAME) $(NPCARGS)

clean:
	rm -rf $(OBJ_DIR)

wave:
	gtkwave waveform/$(TOPNAME)_waveform.fst
include ../Makefile
