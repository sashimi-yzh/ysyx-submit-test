TOPNAME = ysyxSoCFull
VSRCS = $(shell find $(abspath ./build) -name "*.v") $(shell find $(abspath $(YSYX_HOME)/ysyxSoC/perip) -name "*.v") $(YSYX_HOME)/ysyxSoC/build/ysyxSoCFull.v
CPPSRC = $(shell find $(abspath ./csrc/riscv32e-pipeline) -name "*.cpp")
VFLAGS = -cc -exe --build --trace-fst --top-module $(TOPNAME) -O3 --x-initial fast --autoflush -Ibuild -I$(YSYX_HOME)/ysyxSoC/perip/uart16550/rtl -I$(YSYX_HOME)/ysyxSoC/perip/spi/rtl --timescale "1ns/1ns" --no-timing +define+ysyx_26010007_debug=1 
IMG ?= resource/mem.bin
ELF ?= 
OBJ_DIR = ./build

LDFLAGS = $(patsubst %, -LDFLAGS %, -lreadline -ldl)
all:
	@echo "Write this Makefile by your self."
################ 含TRACE工具 ###############################
# LIBCAPSTONE = $(NEMU_HOME)/tools/capstone/repo/libcapstone.so.5
# $(LIBCAPSTONE):
# 	make -C $(NEMU_HOME)/tools/capstone
# LIBNEMU-DIFF = $(NEMU_HOME)/build/riscv32-nemu-interpreter-so
# CFLAGS = $(patsubst %, -CFLAGS %, -I$(NEMU_HOME)/tools/capstone/repo/include -I$(abspath ./csrc/riscv32e-pipeline/include) -DCONFIG_WAVEFORM)
# NPCARGS = -b --diff=$(LIBNEMU-DIFF) --elf=$(ELF) $(IMG)
# sim: $(LIBCAPSTONE)
# 	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
# 	@echo "Write this Makefile by your self."
# 	@mkdir -p waveform
# 	make -C $(NEMU_HOME)
# 	verilator --Mdir $(OBJ_DIR) $(VFLAGS) $(CFLAGS) $(LDFLAGS) $(CPPSRC) $(VSRCS)
# 	$(OBJ_DIR)/V$(TOPNAME) $(NPCARGS)
############################################################

############### 不含trace工具 ###############################
CFLAGS = $(patsubst %, -CFLAGS %, -I$(abspath ./csrc/riscv32e-pipeline/include))
NPCARGS = -b --elf=$(ELF) $(IMG)
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	verilator --Mdir $(OBJ_DIR) $(VFLAGS) $(CFLAGS) $(LDFLAGS) $(CPPSRC) $(VSRCS)
	$(OBJ_DIR)/V$(TOPNAME) $(NPCARGS)
############################################################

clean:
	rm -rf $(OBJ_DIR)

wave:
	gtkwave waveform/$(TOPNAME)_waveform.fst
include ../Makefile
