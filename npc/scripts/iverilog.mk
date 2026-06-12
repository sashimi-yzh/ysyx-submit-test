IVERILOG_HEX = $(BUILD_DIR)/$(notdir $(basename $(IMG)))_iverilog.hex
IVERILOG_VSRCS += $(NPC_HOME)/iverilog/iverilog_top.sv
IVERILOG_VSRCS += $(BUILD_DIR)/iverilog/*.sv

$(IVERILOG_HEX): $(IMG)
	mkdir -p $(dir $@)
	# objcopy -I binary -O verilog $(IMG) $@
	hexdump -v -e '1/4 "%08x" "\n"' $(IMG) > $@

sim-iverilog-base: $(IVERILOG_HEX)
	$(MAKE) -C $(NPC_HOME) verilog ARCH=iverilog
	iverilog -g2012 -s iverilog_top -o $(BUILD_DIR)/iverilog.vvp \
		-D IVERILOG_HEX_PATH="\"$(IVERILOG_HEX)\"" \
		$(IVERILOG_VSRCS)
	vvp -n $(BUILD_DIR)/iverilog.vvp 2>&1

sim-iverilog: IVERILOG_VSRCS += $(NPC_HOME)/build/ysyx_26010008.sv
sim-iverilog: sim-iverilog-base

sim-iverilog-netlist: IVERILOG_VSRCS += $(NETLIST) $(CELLS)
sim-iverilog-netlist: sim-iverilog-base
