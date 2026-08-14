# VSRC=$(shell find $(NPC_HOME)/iverilog-test/vsrc/ -name "*.v") /home/haiji/yosys-sta/result/ysyx_26010007-500MHz/ysyx_26010007.netlist.v.sim
# VSRC=$(shell find $(NPC_HOME)/iverilog-test/vsrc/ -name "*.v") $(shell find $(NPC_HOME)/vsrc/riscv32e-pipeline -name "*.v")
VSRC= $(shell find $(NPC_HOME)/iverilog-test/vsrc/ -name "*.v")
OBJ=ysyx_26010007
IMG=$(NPC_HOME)/iverilog-test/prog/microbench-riscv32e-npc.bin
HEX=$(NPC_HOME)/iverilog-test/prog.hex
NETLIST?=$(shell find $(NPC_HOME)/build -name "*.v")
CELLS?=
.PHONY: run


run: $(VSRC) $(IMG)
	hexdump -v -e '1/4 "%08x\n"' $(IMG) > $(HEX)
	iverilog -DHEX_FILE=\"$(HEX)\" -g2012 -o $(OBJ) $(VSRC) $(NETLIST) $(CELLS)
	vvp $(OBJ)

clean: 
	rm -rf $(OBJ)