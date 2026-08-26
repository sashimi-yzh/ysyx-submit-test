TOPNAME=top
VERILATOR_FLAGS=--cc --exe --build --trace --top-module $(TOPNAME) 
LD_PRELOAD ?=
LD_PRELOAD += $(gcc -print-file-name=libasan.so)
INC_PATH ?=
INC_PATH += csrc/
INC_PATH += csrc/include
INC_PATH += tools/capstone/repo/include
INC_PATH := $(abspath $(INC_PATH))

SIM_C := $(wildcard csrc/*.c* csrc/monitor/*.c* csrc/devices/*.c* csrc/utils/*.c*)
SIM_V := $(wildcard vsrc/*.v)

LIBCAPSTONE = tools/capstone/repo/libcapstone.so.5
DIFF_REF_PATH = $(NEMU_HOME)
DIFF_REF_SO = $(DIFF_REF_PATH)/riscv32-nemu-interpreter-so
ARGS_DIFF = --diff=$(DIFF_REF_SO)

INCFLAGS=$(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\"" -g
LDFLAGS += -lreadline

override ARGS ?=
override ARGS += $(ARGS_DIFF)
IMG ?=
ELF ?=

all:
#	@echo "Write this Makefile by your self."

sim: $(SIM_C) $(SIM_V) 
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator $(VERILATOR_FLAGS) --top-module $(TOPNAME) $^ $(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS))
	@echo "ARGS = $(ARGS)"
	@echo "ARGS_DIFF = $(ARGS_DIFF)"
	LD_PRELOAD="$(shell gcc -print-file-name=libasan.so)" ./obj_dir/V$(TOPNAME) $(ARGS) $(IMG) $(ELF)
#	@echo "Write this Makefile by your self."
wave:
	gtkwave wave.vcd

csrc/utils/disasm.c: $(LIBCAPSTONE)
$(LIBCAPSTONE):
	$(MAKE) -C tools/capstone

clean:
	rm -rf obj_dir wave.vcd wave.fst
include ~/ysyx-workbench/Makefile
