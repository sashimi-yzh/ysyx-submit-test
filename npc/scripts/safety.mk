# Fast, read-only checks used by the CI smoke jobs.

CHECK_TAG := [safety]
CHECK_CORE := $(NPC_DIR)/vsrc/cpu/ysyx_26010028.v
CHECK_TOP := $(RTL_TOP_FILE)
CHECK_RTL := $(RTL_OUT)
CHECK_TBS := $(NPC_DIR)/vsrc/testbench/tb_iverilog.v \
  $(NPC_DIR)/vsrc/testbench/tb_iverilog_netlist.v
CHECK_SOC_SCALA := $(YSYX_SOC_HOME)/src/CPU.scala
CHECK_SOC_RTL := $(YSYX_SOC_HOME)/build/ysyxSoCFull.v

safety-files: rtl-bundle
	@for file in "$(CHECK_CORE)" "$(CHECK_TOP)" $(CHECK_TBS) "$(CHECK_SOC_SCALA)" "$(CHECK_RTL)"; do \
		if test ! -f "$$file"; then \
			printf '%s ERROR: missing required file: %s\n' '$(CHECK_TAG)' "$$file"; exit 1; \
		fi; \
	done
	@printf '%s required source files are present\n' '$(CHECK_TAG)'

safety-core-interface: safety-files
	@for signal in \
		io_slave_awready io_slave_awvalid io_slave_awaddr io_slave_awid io_slave_awlen io_slave_awsize io_slave_awburst \
		io_slave_wready io_slave_wvalid io_slave_wdata io_slave_wstrb io_slave_wlast \
		io_slave_bready io_slave_bvalid io_slave_bresp io_slave_bid \
		io_slave_arready io_slave_arvalid io_slave_araddr io_slave_arid io_slave_arlen io_slave_arsize io_slave_arburst \
		io_slave_rready io_slave_rvalid io_slave_rresp io_slave_rdata io_slave_rlast io_slave_rid; do \
		grep -q "$$signal" "$(CHECK_CORE)" || \
			{ printf '%s ERROR: missing AXI Slave signal: %s\n' '$(CHECK_TAG)' "$$signal"; exit 1; }; \
	done
	@modules=$$(grep -hE '^[[:space:]]*module[[:space:]]+ysyx_26010028([[:space:]]|\()' $(CHECK_RTL) | wc -l); \
	if test "$$modules" -ne 1; then \
		printf '%s ERROR: expected one ysyx_26010028 module, found %s\n' '$(CHECK_TAG)' "$$modules"; exit 1; \
	fi
	@for signal in commit_valid_out commit_pc_out commit_inst_out; do \
		grep -q "$$signal" "$(CHECK_CORE)" || { printf '%s ERROR: missing commit signal: %s\n' '$(CHECK_TAG)' "$$signal"; exit 1; }; \
	done
	@printf '%s CPU and npc_top interfaces are consistent\n' '$(CHECK_TAG)'

safety-tb: safety-files
	@if grep -nE 'Core_cpu\.(ex_out_valid|ex_out_pc|ex_out_inst|idu\.reg_bank)' $(CHECK_TBS); then \
		printf '%s ERROR: Icarus TB still uses a removed internal hierarchy\n' '$(CHECK_TAG)'; exit 1; \
	fi
	@for file in $(CHECK_TBS); do \
		grep -q sim_exit_valid "$$file" || { printf '%s ERROR: %s does not monitor sim_exit_valid\n' '$(CHECK_TAG)' "$$file"; exit 1; }; \
	done
	@printf '%s Icarus testbench hierarchy checks passed\n' '$(CHECK_TAG)'

safety-soc-sync: safety-files
	@if test ! -f "$(CHECK_SOC_RTL)"; then \
		printf '%s ERROR: missing %s\n' '$(CHECK_TAG)' '$(CHECK_SOC_RTL)'; exit 1; \
	fi
	@if find "$(YSYX_SOC_HOME)/src" -type f -name '*.scala' -newer "$(CHECK_SOC_RTL)" -print -quit | grep -q .; then \
		printf '%s ERROR: generated SoC is older than Scala sources\n' '$(CHECK_TAG)'; exit 1; \
	fi
	@if ! grep -qE 'val[[:space:]]+io_slave' "$(CHECK_SOC_SCALA)"; then \
		printf '%s ERROR: CPU BlackBox is missing io_slave\n' '$(CHECK_TAG)'; exit 1; \
	fi
	@block=$$(awk '/ysyx_26010028 core[[:space:]]*\(/,/^[[:space:]]*\);/' "$(CHECK_SOC_RTL)"); \
	if test -z "$$block"; then printf '%s ERROR: ysyx_26010028 instance not found\n' '$(CHECK_TAG)'; exit 1; fi; \
	if ! printf '%s\n' "$$block" | grep -q io_slave_; then \
		printf '%s ERROR: generated SoC is missing AXI Slave connections\n' '$(CHECK_TAG)'; exit 1; \
	fi
	@printf '%s ysyxSoC generated interface is current\n' '$(CHECK_TAG)'

safety-check: safety-core-interface safety-tb safety-soc-sync
	@printf '%s all fast checks passed\n' '$(CHECK_TAG)'

safety-lint: safety-check
	@printf '%s running Verilator lint\n' '$(CHECK_TAG)'
	@$(VERILATOR) --lint-only -Wno-fatal -Wno-PINMISSING -Wno-WIDTHEXPAND \
		--timescale 1ns/1ns --no-timing $(VL_DEFS) \
		$(INCLUDE_FLAGS) --top-module npc_top $(RTL_CORE) $(RTL_TOP_FILE)
	@printf '%s Verilator lint passed\n' '$(CHECK_TAG)'

safety-check-all: safety-check safety-lint
	@printf '%s complete safety suite passed\n' '$(CHECK_TAG)'

.PHONY: safety-files safety-core-interface safety-tb safety-soc-sync
.PHONY: safety-check safety-lint safety-check-all
