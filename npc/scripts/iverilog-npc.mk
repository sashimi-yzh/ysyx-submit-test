# Chisel 生成 verilog 配置
CHISEL_IVERILOG_CONFIG=ICACHE_SIZE_BITS=1
CHISEL_IVERILOG_CONFIG+=ICACHE_BLOCK_BITS=0
CHISEL_IVERILOG_CONFIG+=ICACHE_ENABLE_BURST=false
CHISEL_IVERILOG_CONFIG+=ENABLE_SOC=false
CHISEL_IVERILOG_CONFIG+=NPC_ENABLE_DEBUG=false
CHISEL_IVERILOG_CONFIG+=NPC_ENABLE_IVERILOG=true

IVERILOG_MAIN_FILE := $(NPC_HOME)/iverilog_scripts/iverilog_main.v
NETLIST_MAIN_FILE := $(NPC_HOME)/iverilog_scripts/iverilog_netlist_main.v

NETLIST_FILES := $(NPC_HOME)/build/IverilogTop.sv $(NPC_HOME)/build/IverilogAXI4LiteMem.v  $(NPC_HOME)/build/TopAXI4LiteSlave.sv $(NPC_HOME)/build/Top_mask_expander.v
# NETLIST_FILES := $(NPC_HOME)/svsrc_iverilog_netlist/*.sv $(NPC_HOME)/svsrc_iverilog_netlist/*.v
# NETLIST_FILES := $(NPC_HOME)/svsrc_iverilog/*.sv $(NPC_HOME)/svsrc_iverilog/*.v

verilog-iverilog: 
	@echo CHISEL_IVERILOG_CONFIG $(CHISEL_IVERILOG_CONFIG) 
	$(MAKE) -C ../npc-chisel $(CHISEL_IVERILOG_CONFIG) verilog-iverilog

verilog-netlist:
	@echo CHISEL_IVERILOG_CONFIG $(CHISEL_IVERILOG_CONFIG) 
	$(MAKE) -C ../npc-chisel $(CHISEL_IVERILOG_CONFIG) verilog-netlist

iverilog-config:
	$(MAKE) -C $(NPC_HOME) riscv32e-iverilog_defconfig

iverilog-prepare:
	mkdir -p $(BUILD_DIR)/iverilog
	cp $(NPC_HOME)/build/ysyx_24100012.v $(NPC_HOME)/build/Iverilog_ysyx_24100012.v
# 	sed -i 's/pc_reg[[:space:]]*<=[[:space:]]*32'\''h[0-9a-fA-F]\{8\}/pc_reg <= 32'\''h${START_ADDR}/g'  $(NPC_HOME)/build/Iverilog_ysyx_24100012.v  


iverilog-build:  $(SVSOURCES) $(IVERILOG_MAIN_FILE) 
	iverilog $(VINCLUDES) -o $(BUILD_DIR)/iverilog/main.vvp  $(IVERILOG_MAIN_FILE) $(SVSOURCES) -g2012 -Wall 

netlist-build: $(NETLIST_MAIN_FILE) $(NETLIST_FILES) 
	mkdir -p $(BUILD_DIR)/netlist
	@echo iverilog  $(NETLIST_MAIN_FILE) $(NETLIST_FILES)  $(CELLS) $(NETLIST) 
	iverilog $(VINCLUDES) -o $(BUILD_DIR)/netlist/main.vvp   $(NETLIST_MAIN_FILE)  $(CELLS) $(NETLIST)  $(NETLIST_FILES) -g2012 
	@echo iverilog finished

iverilog-run:iverilog-build
	@echo python translating $(IMG)
	@python $(NPC_HOME)/iverilog_scripts/bin2hex.py $(IMG) $(IMG).hex
	@echo python translating $(IMG) done
	vvp $(BUILD_DIR)/iverilog/main.vvp  +image=$(IMG).hex

netlist-run:
	@python $(NPC_HOME)/iverilog_scripts/bin2hex.py $(IMG) $(IMG).hex
	@echo python translating $(IMG) done
	vvp $(BUILD_DIR)/netlist/main.vvp  +image=$(IMG).hex


sim-iverilog: 
	@echo $(ARGS) $(IMG)
	$(MAKE) -C $(NPC_HOME) verilog
	$(MAKE) -C $(NPC_HOME) iverilog-config
	$(MAKE) -C $(NPC_HOME) iverilog-prepare
	$(MAKE) -C $(NPC_HOME) iverilog-run IMG=$(IMG)

sim-iverilog-netlist: 
	$(MAKE) -C $(NPC_HOME) verilog
	$(MAKE) -C $(NPC_HOME) iverilog-config
	$(MAKE) -C $(NPC_HOME) netlist-build CELLS=$(CELLS) NETLIST=$(NETLIST)
	$(MAKE) -C $(NPC_HOME) netlist-run IMG=$(IMG) 

sim-iverilog-raw: iverilog-build
	vvp $(BUILD_DIR)/iverilog/main.vvp

sim-iverilog-netlist-raw: netlist-build
	vvp $(BUILD_DIR)/netlist/main.vvp  