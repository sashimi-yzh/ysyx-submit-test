TOPNAME = ysyxSoCFull
VSRCS = $(shell find $(abspath ./vsrc/riscv32e-multi) -name "*.v") $(shell find $(abspath $(YSYX_HOME)/ysyxSoC/perip) -name "*.v") $(YSYX_HOME)/ysyxSoC/build/ysyxSoCFull.v
CPPSRC = $(shell find $(abspath ./csrc/riscv32e-multi) -name "*.cpp")
VFLAGS = -cc -exe --build -j 0 --trace-fst --top-module $(TOPNAME) -O3 --x-initial fast --autoflush -Ivsrc/riscv32e-multi -I$(YSYX_HOME)/ysyxSoC/perip/uart16550/rtl -I$(YSYX_HOME)/ysyxSoC/perip/spi/rtl --timescale "1ns/1ns" --no-timing +define+debug=1
IMG ?= resource/mem.bin
ELF ?= 
OBJ_DIR = obj_dir

LIBCAPSTONE = $(NEMU_HOME)/tools/capstone/repo/libcapstone.so.5
$(LIBCAPSTONE):
	make -C $(NEMU_HOME)/tools/capstone

LIBNEMU-DIFF = $(NEMU_HOME)/build/riscv32-nemu-interpreter-so
# -DCONFIG_WAVEFORM
CFLAGS = $(patsubst %, -CFLAGS %, -I$(NEMU_HOME)/tools/capstone/repo/include -I$(abspath ./csrc/riscv32e-multi/include) )
LDFLAGS = $(patsubst %, -LDFLAGS %, -lreadline -ldl)
all:
	@echo "Write this Makefile by your self."

NPCARGS = --diff=$(LIBNEMU-DIFF) --elf=$(ELF) $(IMG)

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
