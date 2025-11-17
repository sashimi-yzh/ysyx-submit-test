BUILD_DIR = ./build/soc
NPC_BUILD_DIR = ./build/npc
IVERILOG_BUILD_DIR = ./build/iverilog
NETLIST_BUILD_DIR = ./build/netlist
PRJ = npc

test:
	mill -i $(PRJ).test

verilog_build:
	$(call git_commit, "generate verilog")
	@echo ICACHE_SIZE_BITS $(ICACHE_SIZE_BITS)
	mkdir -p $(BUILD_DIR)
	mkdir -p $(NPC_HOME)/build/
	mill -i $(PRJ).runMain Elaborate 

verilog_npc_build:
	$(call git_commit, "generate verilog")
	@echo BURST_LENGTH $(BURST_LENGTH)
	mkdir -p $(NPC_HOME)/build/
	mkdir -p $(NPC_BUILD_DIR)
	mkdir -p $(NPC_HOME)/svsrc_no_soc
	mill -i $(PRJ).runMain ElaborateNPC 

verilog_iverilog_build:
	$(call git_commit, "generate verilog")
	mkdir -p $(IVERILOG_BUILD_DIR)
	mkdir -p $(NPC_HOME)/svsrc_iverilog
	mill -i $(PRJ).runMain ElaborateIverilog 

verilog_iverilog_netlist_build:
	$(call git_commit, "generate verilog")
	mkdir -p $(NETLIST_BUILD_DIR)
	mkdir -p $(NPC_HOME)/svsrc_netlist
	mill -i $(PRJ).runMain ElaborateIverilogNetlist 


verilog: verilog_build
	sed -i -e 's/_\(aw\|ar\|w\|r\|b\)_\(\|bits_\)/_\1/g' $(BUILD_DIR)/*.v
	sed -i '/\.v/ s/.*//' $(BUILD_DIR)/*.v
	cp  -r $(wildcard $(BUILD_DIR)/*.sv $(BUILD_DIR)/*.v  ./npc/src/main/resources/*.v) $(NPC_HOME)/build/


verilog-npc: verilog_npc_build
	sed -i -e 's/_\(aw\|ar\|w\|r\|b\)_\(\|bits_\)/_\1/g' $(NPC_BUILD_DIR)/*.v  $(NPC_BUILD_DIR)/*.sv
	sed -i '/\.v/ s/.*//' $(NPC_BUILD_DIR)/*.v
	cp  -r $(wildcard $(NPC_BUILD_DIR)/Top*.sv $(NPC_BUILD_DIR)/Top*.v ./npc/src/main/resources/Top*.v)  $(NPC_HOME)/build/

verilog-iverilog: verilog_iverilog_build
	sed -i -e 's/_\(aw\|ar\|w\|r\|b\)_\(\|bits_\)/_\1/g' $(IVERILOG_BUILD_DIR)/*.v $(IVERILOG_BUILD_DIR)/*.sv
	sed -i '/\.v/ s/.*//' $(IVERILOG_BUILD_DIR)/*.v
	cp  -r $(wildcard $(IVERILOG_BUILD_DIR)/Iverilog*.sv $(IVERILOG_BUILD_DIR)/Iverilog*.v ./npc/src/main/resources/*.v)  $(NPC_HOME)/build/
	cp  -r $(wildcard $(IVERILOG_BUILD_DIR)/*.sv  $(IVERILOG_BUILD_DIR)/*.v ./npc/src/main/resources/*.v)  $(NPC_HOME)/svsrc_iverilog/

verilog-netlist: verilog_iverilog_netlist_build
# 	gsed -i -e 's/_\(aw\|ar\|w\|r\|b\)_\(\|bits_\)/_\1/g' $(BUILD_DIR)/*.sv
	sed -i '/\.v/ s/.*//' $(NETLIST_BUILD_DIR)/*.v
	cp  -r $(wildcard $(NETLIST_BUILD_DIR)/*.sv $(NETLIST_BUILD_DIRs)/*.v ./npc/src/main/resources/*.v)  $(NPC_HOME)/svsrc_netlist/


help:
	mill -i $(PRJ).runMain ElaborateHelp

reformat:
	mill -i __.reformat

checkformat:
	mill -i __.checkFormat

bsp:
	mill -i mill.bsp.BSP/install

idea:
	mill -i mill.idea.GenIdea/idea

clean:
	-rm -rf ./build
	-rm -rf $(NPC_HOME)/build
	-rm -rf $(NPC_HOME)/svsrc_no_soc
	-rm -rf $(NPC_HOME)/svsrc_iverilog
	-rm -rf $(NPC_HOME)/svsrc_netlist

# clean_npc:
# 	-rm -rf $(NPC_BUILD_DIR)
# 	-rm -rf $(NPC_HOME)/svsrc_no_soc

.PHONY: test verilog help reformat checkformat clean build verilog_old

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by yourself."

-include ../Makefile
