# ==============================================================================
# iverilog 四值与网表仿真规则 (由主 Makefile 包含)
# ==============================================================================

# 基础路径配置（相对于主 Makefile 所在根目录）
IVERILOG_SIM_DIR = $(BUILD_DIR)/iverilog_sim
IVERILOG_TOP     = $(abspath ./resource/iverilog/sim_top.v)

# 脚本与中间生成物路径
WRAPPER_SCRIPT   = $(abspath ./tools/gen_wrapper.py)
NETLIST_WRAPPER  = $(IVERILOG_SIM_DIR)/netlist/$(CORENAME)_wrapper.v
MODIFIED_NETLIST = $(IVERILOG_SIM_DIR)/netlist/$(CORENAME)_netlist_copy.v
IVERILOG_STAMP   = $(IVERILOG_SIM_DIR)/.generate.stamp
IVERILOG_OUT     = $(IVERILOG_SIM_DIR)/sim.out
IVERILOG_NET_OUT = $(IVERILOG_SIM_DIR)/sim_netlist.out
IVERILOG_HEX     = $(IVERILOG_SIM_DIR)/image.hex

# 1. 提取默认路径，用于后续判断
DEFAULT_NETLIST  = $(abspath ./yosys-sta/result/$(CORENAME)-$(CLK_FREQ_MHZ)MHz/$(CORENAME).netlist.v)
NETLIST         ?= $(DEFAULT_NETLIST)
CELLS           ?= $(abspath ./yosys-sta/pdk/nangate45/sim/cells.v)

# 2. 判断是否为本地默认网表。
# 如果是，则使用转接层；如果是外部传入的（CI测试），则直接使用传入的网表
ifeq ($(abspath $(NETLIST)),$(DEFAULT_NETLIST))
    ACTUAL_NETLIST_SRCS = $(NETLIST_WRAPPER) $(MODIFIED_NETLIST)
    ACTUAL_NETLIST_DEPS = $(NETLIST_WRAPPER)
else
    ACTUAL_NETLIST_SRCS = $(NETLIST)
    ACTUAL_NETLIST_DEPS = $(NETLIST)
endif

#生成仿真所需verilog，不合并
$(IVERILOG_STAMP): $(SCALA_SRCS)
	@echo "--- Generating standalone Verilog for iverilog ---"
	@mkdir -p $(IVERILOG_SIM_DIR)
	USE_YSYXSOC=0 ENABLE_DPIC=0 mill -i runMain ElaborateFull --target-dir $(IVERILOG_SIM_DIR)
	@touch $@

#生成网表转接层 (只有在ACTUAL_NETLIST_DEPS依赖它时，才会被触发执行)
$(NETLIST_WRAPPER): $(IVERILOG_STAMP) $(NETLIST) $(WRAPPER_SCRIPT)
	@echo "--- Auto-generating Wrapper and Copying Netlist ---"
	@mkdir -p $(dir $@)
	@CORE_RTL=`find $(IVERILOG_SIM_DIR) -maxdepth 1 -name "$(CORENAME).v" -o -name "$(CORENAME).sv" | head -n 1`; \
	if [ -z "$$CORE_RTL" ]; then \
		echo "Error: Cannot find $(CORENAME) RTL file in $(IVERILOG_SIM_DIR)"; exit 1; \
	fi; \
	python3 $(WRAPPER_SCRIPT) $$CORE_RTL $(NETLIST) $(MODIFIED_NETLIST) $@ $(CORENAME)

#提取HEX
$(IVERILOG_HEX): $(IMG)
	@if [ -z "$(IMG)" ]; then echo "Error: IMG is not defined. Use 'make sim-iverilog IMG=xxx.bin'"; exit 1; fi
	@mkdir -p $(IVERILOG_SIM_DIR)
	@echo "--- Converting BIN to HEX for readmemh ---"
	@od -v -t x4 -An $(IMG) | awk '{for(i=1;i<=NF;i++) print $$i}' > $@

#普通仿真
$(IVERILOG_OUT): $(IVERILOG_TOP) $(IVERILOG_STAMP)
	@echo "--- Compiling RTL with iverilog ---"
	@IVERILOG_RTL_SRCS=`find $(IVERILOG_SIM_DIR) -maxdepth 1 -name "*.v" -o -name "*.sv"`; \
	iverilog -g2012 -o $@ $(IVERILOG_TOP) $$IVERILOG_RTL_SRCS

#网表仿真 (替换为条件判断后的依赖和源文件)
$(IVERILOG_NET_OUT): $(IVERILOG_TOP) $(IVERILOG_STAMP) $(ACTUAL_NETLIST_DEPS) $(CELLS)
	@echo "--- Compiling Netlist with iverilog ---"
	@IVERILOG_NET_SRCS=`find $(IVERILOG_SIM_DIR) -maxdepth 1 \( -name "*.v" -o -name "*.sv" \) ! -name "$(CORENAME).v" ! -name "$(CORENAME).sv"`; \
	iverilog -g2012 -o $@ $(IVERILOG_TOP) $$IVERILOG_NET_SRCS $(ACTUAL_NETLIST_SRCS) $(CELLS)

#对外伪目标
sim-iverilog: $(IVERILOG_OUT) $(IVERILOG_HEX)
	$(call git_commit, "sim RTL with iverilog")
	@echo "--- Running iverilog simulation (RTL) ---"
	cd $(IVERILOG_SIM_DIR) && vvp $(notdir $(IVERILOG_OUT)) -fst

sim-iverilog-netlist: $(IVERILOG_NET_OUT) $(IVERILOG_HEX)
	$(call git_commit, "sim Netlist with iverilog")
	@echo "--- Running iverilog simulation (Netlist) ---"
	cd $(IVERILOG_SIM_DIR) && vvp $(notdir $(IVERILOG_NET_OUT)) -fst