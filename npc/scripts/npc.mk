
NPC_OBJ_DIR = $(BUILD_DIR)/obj_dir_npc
NPC_BIN = $(BUILD_DIR)/npc_sim

npc: $(NPC_BIN)

$(NPC_BIN): $(KCONFIG_INCLUDE) $(CORE) $(PERF_NAMES_H) $(NPC_VSRCS) $(CSRCS)
	@rm -rf $(NPC_OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) -DNPC --top-module $(TOPNAME) \
		$(CORE) $(NPC_VSRCS) $(CSRCS) \
		-CFLAGS "$(CXXFLAGS) -DNPC" -LDFLAGS "$(LDFLAGS)" \
		--Mdir $(NPC_OBJ_DIR) --exe -o $(CURDIR)/$(NPC_BIN) \
		-Iresources/include

npc-run: npc
	$(NPC_BIN) $(if $(IMG),-i $(IMG)) $(if $(ELF),-e $(ELF)) $(if $(DIFF_REF),-d $(DIFF_REF))
