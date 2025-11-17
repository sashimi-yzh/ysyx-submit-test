TOPNAME = ysyxSoCFull
NXDC_FILES = $(YSYX_HOME)/ysyxSoC/constr/ysyxSoCFull.nxdc
# rules for verilator
VERILATOR = verilator
VERILATOR_CFLAGS += -cc --trace 
INCFLAGS = $(addprefix -I, $(INC_PATH))

# constraint file
SRC_AUTO_BIND = $(YSYX_HOME)/ysyxSoC/constr/auto_bind.cpp
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /usr/local/share/verilator

# rules for src
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
VSRCS += $(shell find $(abspath $(YSYX_HOME)/ysyxSoC/perip) -name "*.v")
VSRCS += $(YSYX_HOME)/ysyxSoC/build/ysyxSoCFull.v
CSRCS = $(abspath ./csrc/main.cpp)
CSRCS += $(SRC_AUTO_BIND)
CSRCS_NPC = $(abspath ./csrc/main.cpp)
VSRCS_NPC = $(shell find $(abspath ./vsrc) -name "*.v")
VSRCS_NPC += $(shell find $(abspath ./npc_specific) -name "*.v")

# LOADLIBES += -lreadline
# LDFLAGS += -L$(NEMU_HOME)/build
# LDFLAGS += $(NEMU_HOME)/build/lriscv32-nemu-interpreter

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

npc:$(VSRCS_NPC) $(CSRCS_NPC)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(MAKE) -C $(NEMU_HOME)/tools/capstone
	$(MAKE) -C $(NEMU_HOME)/tools/fixdep
	cp $(NPC_HOME)/tools/nemu-npc.config $(NEMU_HOME)/.config
	$(MAKE) -C $(NEMU_HOME) syncconfig
	$(MAKE) -C $(NEMU_HOME)
	cp $(NPC_HOME)/tools/nemu.config $(NEMU_HOME)/.config
	$(MAKE) -C $(NEMU_HOME) syncconfig
	rm -rf ./obj_dir
	mkdir -p log
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module ysyx_24120011_tb $^ \
		--prefix V$(TOPNAME) \
		--timescale "1ns/1ns" \
		--no-timing \
		--autoflush \
		-CFLAGS "-I $(NEMU_HOME)/tools/capstone/repo/include"\
		-LDFLAGS "-L$(NEMU_HOME)/build -L$(NEMU_HOME)/tools/capstone/repo -lriscv32-nemu-interpreter-npc -lcapstone -lreadline -Wl,-rpath,$(NEMU_HOME)/build"\
		--exe main.cpp
	make -C obj_dir -f V$(TOPNAME).mk V$(TOPNAME)
	./obj_dir/V$(TOPNAME) $(IMG) +IMG="$(IMG)"
	
sim:$(VSRCS) $(CSRCS)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	rm -rf ./obj_dir
	mkdir -p log
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		--timescale "1ns/1ns" \
		--no-timing \
		--autoflush \
		-I$(YSYX_HOME)/ysyxSoC/perip/uart16550/rtl\
		-I$(YSYX_HOME)/ysyxSoC/perip/spi/rtl\
		-LDFLAGS "-lreadline"\
		--exe main.cpp
	make -C obj_dir -f V$(TOPNAME).mk V$(TOPNAME)
	./obj_dir/V$(TOPNAME) $(IMG)

nvboard:$(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(MAKE) -C $(NEMU_HOME)/tools/capstone
	$(MAKE) -C $(NEMU_HOME)/tools/fixdep
	cp $(NPC_HOME)/tools/nemu-soc.config $(NEMU_HOME)/.config
	$(MAKE) -C $(NEMU_HOME) syncconfig
	$(MAKE) -C $(NEMU_HOME)
	cp $(NPC_HOME)/tools/nemu.config $(NEMU_HOME)/.config
	$(MAKE) -C $(NEMU_HOME) syncconfig
	rm -rf ./obj_dir
	mkdir -p log
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		--timescale "1ns/1ns" \
		--no-timing \
		--autoflush \
		-CFLAGS "-I $(NEMU_HOME)/tools/capstone/repo/include"\
		-I$(YSYX_HOME)/ysyxSoC/perip/uart16550/rtl\
		-I$(YSYX_HOME)/ysyxSoC/perip/spi/rtl\
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		-LDFLAGS "-L$(NEMU_HOME)/build -L$(NEMU_HOME)/tools/capstone/repo -lriscv32-nemu-interpreter-soc -lcapstone -lreadline -Wl,-rpath,$(NEMU_HOME)/build"\
		--exe main.cpp
	make -C obj_dir -f V$(TOPNAME).mk V$(TOPNAME) CXXFLAGS="-DSOC"
	./obj_dir/V$(TOPNAME) $(IMG)	

perf:
	rm -rf ~/yosys-sta/npc && \
	cp -r ./vsrc ~/yosys-sta/npc && \
	python3 ./tools/remove_dpic.py && \
	rm -rf ~/yosys-sta/result/* && \
	cd ~/yosys-sta && \
	make sta && \
	cd $(YSYX_HOME)/am-kernels/benchmarks/microbench && \
	make ARCH=riscv32e-ysyxsoc run mainargs=test && \
	cd $(YSYX_HOME)/npc && \
	python3 ./tools/perf.py
	
sta:
	rm -rf ~/yosys-sta/npc && \
	cp -r ./vsrc ~/yosys-sta/npc && \
	python3 ./tools/remove_dpic.py && \
	rm -rf ~/yosys-sta/result/* && \
	cd ~/yosys-sta && \
	make sta  && \
	cd $(YSYX_HOME)/npc

oldsta:
	rm -rf ~/yosys-sta/npc && \
	rm -rf ~/yosys-sta-old/npc && \
	cp -r ./vsrc ~/yosys-sta/npc && \
	python3 ./tools/remove_dpic.py && \
	cp -r ~/yosys-sta/npc ~/yosys-sta-old/npc && \
	rm -rf ~/yosys-sta-old/result/* && \
	cd ~/yosys-sta-old && \
	make sta  && \
	python3 area.py && \
	cd $(YSYX_HOME)/npc
	
verilog:
	rm -rf ./vsrc_no_dpic && \
	cp -r ./vsrc/ ./vsrc_no_dpic && \
	rm -rf ./build && \
	mkdir -p ./build && \
	python3 ./tools/verilog.py $(NPC_HOME) && \
	rm -rf ./vsrc_no_dpic

sim-iverilog:verilog
	mkdir -p log
	@if [ -z "$(IMG)" ]; then echo "IMG variable is not set. Please provide an IMG value"; exit 1; fi
	@python $(NPC_HOME)/tools/bin2txt.py $(IMG) $(IMG).txt 16
	iverilog -g2012 $(NPC_HOME)/iverilog/ysyx_24120011_tb.v $(NPC_HOME)/build/ysyx_24120011.v $(NPC_HOME)/npc_specific/ysyx_24120011_SRAMUART.v -o $(NPC_HOME)/log/wave
	vvp -n $(NPC_HOME)/log/wave -lxt2 +IMG=$(IMG).txt

sim-iverilog-netlist:
	mkdir -p log
	@if [ -z "$(IMG)" ]; then echo "IMG variable is not set. Please provide an IMG value"; exit 1; fi
	@if [ -z "$(NETLIST)" ]; then echo "NETLIST variable is not set. Please provide an NETLIST value"; exit 1; fi
	@if [ -z "$(CELLS)" ]; then echo "CELLS variable is not set. Please provide an CELLS value"; exit 1; fi
	@python $(NPC_HOME)/tools/bin2txt.py $(IMG) $(IMG).txt 16
	iverilog -g2012 $(NPC_HOME)/iverilog/ysyx_24120011_tb.v $(NETLIST) $(CELLS) $(NPC_HOME)/npc_specific/ysyx_24120011_SRAMUART.v -o $(NPC_HOME)/log/netlist
	vvp -n $(NPC_HOME)/log/netlist -lxt2 +IMG=$(IMG).txt

clean:
	rm -rf ./build && \
	rm -rf ./log && \
	rm -rf ./obj_dir
	
include ../Makefile
