NPC_RESET_VECTOR ?= 0x30000000

ifneq ($(filter sim-iverilog sim-iverilog-netlist bear-npc npc-run npc-gdb npc,$(MAKECMDGOALS)),)
  NPC_RESET_VECTOR := 0x80000000
endif
ifneq ($(filter itrace,$(MAKECMDGOALS)),)
  NPC_RESET_VECTOR := 0x30000000
endif
ifneq ($(filter btrace,$(MAKECMDGOALS)),)
  NPC_RESET_VECTOR := 0x30000000
endif
ifneq ($(filter verilog,$(MAKECMDGOALS)),)
  NPC_DEBUG_MODE := false
endif
ifneq ($(filter ysyxsoc-run,$(MAKECMDGOALS)),)
  NPC_ICACHE_WORD_OFF_BITS        := 3
  NPC_ICACHE_BLOCK_BITS           := 6
  NPC_BRANCH_PREDICTOR_INDEX_WIDTH := 6
endif

NPC_CONFIG_VARS := NPC_RESET_VECTOR NPC_DEBUG_MODE NPC_ICACHE_WORD_OFF_BITS NPC_ICACHE_BLOCK_BITS NPC_BRANCH_PREDICTOR_INDEX_WIDTH
NPC_CONFIG_VALS := $(foreach v,$(NPC_CONFIG_VARS),$($(v)))
NPC_CONFIG_ENV  := $(foreach v,$(NPC_CONFIG_VARS),$(v)=$($(v)))
