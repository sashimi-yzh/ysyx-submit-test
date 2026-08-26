TOPNAME=ysyxSoCFull

include $(NVBOARD_HOME)/scripts/nvboard.mk

LD_PRELOAD ?=
LD_PRELOAD += $(gcc -print-file-name=libasan.so)
C_INC_PATH ?=
C_INC_PATH += csrc/
C_INC_PATH += csrc/include
# C_INC_PATH += tools/capstone/repo/include
C_INC_PATH += tools/capstone/include
C_INC_PATH := $(abspath $(C_INC_PATH))
C_INC_PATH += $(NVBOARD_USR_INC)

V_INC_PATH ?=
V_INC_PATH += $(NPC_HOME)/../ysyxSoC/perip/uart16550/rtl/
V_INC_PATH += $(NPC_HOME)/../ysyxSoC/perip/spi/rtl/
V_INC_PATH += $(NPC_HOME)/vsrc/
V_INC_PATH := $(abspath $(V_INC_PATH))



SIM_C := $(wildcard csrc/*.c* csrc/monitor/*.c* csrc/devices/*.c* csrc/utils/*.c*)
# SIM_V := $(shell find vsrc/ -type f \( -name "*.v" -o -name "*.sv" \))
SIM_V_TOP := build/ysyx_26010011.v
SIM_V := $(SIM_V_TOP)
SIM_V += $(shell find $(NPC_HOME)/../ysyxSoC/perip/ -type f  -name "*.v" )
SIM_V += $(NPC_HOME)/../ysyxSoC/build/ysyxSoCFull.v

SRC_V := vsrc/csr_defines.v
SRC_V += vsrc/IFU.v
SRC_V += vsrc/IDU.v
SRC_V += vsrc/EXU.v
SRC_V += vsrc/LSU.v
SRC_V += vsrc/WBU.v
SRC_V += vsrc/pipeline.v
SRC_V += vsrc/REG.v
SRC_V += vsrc/CPU.v
SRC_V += vsrc/RAW.v
SRC_V += vsrc/AXI4Arbiter.v
SRC_V += vsrc/CLINT.v
SRC_V += vsrc/BRIDGE.v

LIBCAPSTONE = tools/capstone/libcapstone.so.5
DIFF_REF_PATH = $(NEMU_HOME)
DIFF_REF_SO = $(DIFF_REF_PATH)/riscv32-nemu-interpreter-so-ysyxsoc
ARGS_DIFF = --diff=$(DIFF_REF_SO)

C_INCFLAGS=$(addprefix -I, $(C_INC_PATH))
CXXFLAGS += $(C_INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\"" -g
LDFLAGS += -lreadline

V_INCFLAGS=$(addprefix -I, $(V_INC_PATH))
VERILATOR_FLAGS=--cc --Mdir build --autoflush --exe --build -O3 --trace-fst --timescale "1ns/1ns" --no-timing $(V_INCFLAGS) --top-module $(TOPNAME) +define+USE_VERILATOR=1

override ARGS ?=
override ARGS += $(ARGS_DIFF)
IMG ?=
ELF ?=



all:

$(SIM_V_TOP): concat
# 	$(MAKE) concat

concat: $(SRC_V)
	@mkdir -p build
	cat  $(SRC_V) > build/ysyx_26010011.v
	sed -i 's#`include#//`include#' build/ysyx_26010011.v

sim: $(SIM_C) $(SIM_V) $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator $(VERILATOR_FLAGS) --top-module $(TOPNAME) $^ $(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS))
	@echo "ARGS = $(ARGS)"
	@echo "ARGS_DIFF = $(ARGS_DIFF)"
	env ASAN_OPTIONS=new_delete_type_mismatch=0:detect_leaks=0 LD_PRELOAD="$(shell gcc -print-file-name=libasan.so)" ./build/V$(TOPNAME) $(ARGS) $(IMG) $(ELF)
#	@echo "Write this Makefile by your self."
wave:
	gtkwave wave.vcd

csrc/utils/disasm.c: $(LIBCAPSTONE)
# $(LIBCAPSTONE):
# 	$(MAKE) -C tools/capstone

perf:
	@echo "[perf] start: $$(date '+%F %T')"; \
	start=$$(date +%s); \
	$(MAKE) -C $(NPC_HOME)/../am-kernels/benchmarks/microbench/ run ARCH=riscv32e-ysyxsoc mainargs=train; \
	end=$$(date +%s); \
	echo "[perf] 用时: $$((end - start)) 秒"
	@echo "ysyx git commit: $(shell git log -1 --format="%H")"
	@echo "soc git commit: $(shell cd $(NPC_HOME)/../ysyxSoC && git log -1 --format="%H")"

perf-test:
	@echo "[perf] start: $$(date '+%F %T')"; \
	start=$$(date +%s); \
	$(MAKE) -C $(NPC_HOME)/../am-kernels/benchmarks/microbench/ run ARCH=riscv32e-ysyxsoc mainargs=test; \
	end=$$(date +%s); \
	echo "[perf] 用时: $$((end - start)) 秒"
	@echo "ysyx git commit: $(shell git log -1 --format="%H")"
	@echo "soc git commit: $(shell cd $(NPC_HOME)/../ysyxSoC && git log -1 --format="%H")"

clean:
	rm -rf npc-waveform.vcd wave.fst build



iv-netlist: concat
	iverilog -Wall -g2012 -o myCPU_iv_netlist -s CPUTop_tb vsrc/ysyx_26010011_tb.v vsrc/ysyx_26010011_netlist_wrap.v $(NETLIST) $(NETLIST_CELLS)
	vvp myCPU_iv_netlist

iv: concat
	iverilog -Wall -g2012 -o myCPU_iv -s CPUTop_tb vsrc/ysyx_26010011_tb.v vsrc/ysyx_26010011_dut.v vsrc/ysyx_26010011.v
	vvp myCPU_iv

verilog: concat

IV_SRC = vsrc/ysyx_26010011_tb.v vsrc/ysyx_26010011_dut.v
IV_NET_SRC = vsrc/ysyx_26010011_tb.v vsrc/ysyx_26010011_dut.v
NETLIST ?= $(NPC_HOME)/../yosys-sta/result/ysyx_26010011-800MHz/ysyx_26010011.v
CELLS ?= $(NPC_HOME)/../yosys-sta/pdk/nangate45/sim/cells.v

bin-to-text: $(IMG)
	@echo "Converting binary image to text format..."
	@xxd -p -c 4 $(IMG) | sed -E 's/(..)(..)(..)(..)/\4\3\2\1/' > $(IMG).txt
	@echo "Conversion complete. Output file: $(IMG).txt"

sim-iverilog: $(IMG) $(IV_SRC) $(SIM_V_TOP)
	$(MAKE) bin-to-text
	mkdir -p build
	iverilog -g2012 -Wall -o build/myCPU_sim-iverilog -s CPUTop_tb $(IV_SRC) $(SIM_V_TOP) -DIMG_PATH=\"$(IMG).txt\"
	vvp build/myCPU_sim-iverilog

sim-iverilog-netlist: $(IMG) $(NETLIST) $(CELLS) 
	$(MAKE) bin-to-text
	mkdir -p build
	iverilog -g2012 -Wall -o build/myCPU_sim-iverilog-netlist -s CPUTop_tb $(IV_NET_SRC) $(NETLIST) $(CELLS) -DIMG_PATH=\"$(IMG).txt\"
	vvp build/myCPU_sim-iverilog-netlist

include $(NPC_HOME)/../Makefile

.PHONY: all sim wave perf perf-test clean iv iv-netlist concat verilog sim-iverilog bin-to-text sim-iverilog-netlist