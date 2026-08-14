BUILD_DIR = ./build
DIFINES_FILE = ./vsrc/riscv32e-pipeline/ysyx_26010007_defines.v
TOP_FILE = ./vsrc/riscv32e-pipeline/ysyx_26010007.v
VSRCS = $(shell find ./vsrc/riscv32e-pipeline -name "*.v")
MERGE_FILE = $(BUILD_DIR)/ysyx_26010007.v
IMG ?=
NETLIST ?=
CELLS ?=
$(shell mkdir -p $(BUILD_DIR))

verilog: $(VSRCS)
	@if [ -f $(DIFINES_FILE) ]; then \
		sed '1c\\' $(DIFINES_FILE) > $(MERGE_FILE); \
	fi

	@if [ -f $(TOP_FILE) ]; then \
		sed '1c\\' $(TOP_FILE) >> $(MERGE_FILE); \
	fi

	@for f in $(VSRCS); do \
		if [ "$$f" != "$(DIFINES_FILE)" ] && [ "$$f" != $(TOP_FILE) ]; then \
			sed '1c\\' "$$f" >> $(MERGE_FILE); \
		fi; \
	done

sim-iverilog: verilog
	@make -C $(NPC_HOME)/iverilog-test run IMG=$(IMG)

sim-iverilog-netlist: verilog
	@make -C $(NPC_HOME)/iverilog-test run IMG=$(IMG) NETLIST=$(NETLIST) CELLS=$(CELLS)

sta:
	$(MAKE) -C $(YOSYS_HOME) sta \
	DESIGN=ysyx_26010007 SDC_FILE=$(YOSYS_HOME)/scripts/default.sdc \
	CLK_FREQ_MHZ=750 CLK_PORT_NAME=clock O=$(NPC_HOME)/sta-result \
	RTL_FILES="$(shell find $(NPC_HOME)/vsrc/riscv32e-pipeline -name '*.v' | tr '\n' ' ')" 
perf: sta
	$(MAKE) -C $(AM_KERNEL_HOME)/benchmarks/microbench  ARCH=riscv32e-ysyxsoc run mainargs=train
clean:
	rm -rf build obj_dir sta-result
