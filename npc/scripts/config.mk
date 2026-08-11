# Kconfig lifecycle for the NPC host.

Q ?= @
KCFG_SILENT := -s
KCFG_ROOT := $(NPC_DIR)/tools/kconfig
KCFG_SPEC := $(NPC_DIR)/Kconfig
KCFG_DEFAULT := $(NPC_DIR)/configs/npc_set
KCFG_ACTIVE := $(NPC_DIR)/.config

KCFG_CONF := $(KCFG_ROOT)/build/conf
KCFG_MENU := $(KCFG_ROOT)/build/mconf
KCFG_FIXDEP := $(NPC_DIR)/tools/fixdep/build/fixdep
KCFG_OUTPUTS := $(NPC_DIR)/include/config/auto.conf $(NPC_DIR)/include/generated/autoconf.h
KCFG_GARBAGE := $(NPC_DIR)/include/generated $(NPC_DIR)/include/config \
  $(KCFG_ACTIVE) $(NPC_DIR)/.config.old

ifeq ($(wildcard $(KCFG_ACTIVE)),)
$(warning No NPC configuration found; loading npc_set)
endif

$(KCFG_CONF) $(KCFG_MENU):
	$(Q)$(MAKE) $(KCFG_SILENT) -C $(KCFG_ROOT) NAME=$(@F)

$(KCFG_FIXDEP):
	$(Q)$(MAKE) $(KCFG_SILENT) -C $(NPC_DIR)/tools/fixdep

$(KCFG_ACTIVE): $(KCFG_CONF)
	$(Q)$< $(KCFG_SILENT) --defconfig=$(KCFG_DEFAULT) $(KCFG_SPEC)

$(KCFG_OUTPUTS): $(KCFG_ACTIVE) $(KCFG_SPEC) $(KCFG_CONF) $(KCFG_FIXDEP)
	$(Q)$(KCFG_CONF) $(KCFG_SILENT) --syncconfig $(KCFG_SPEC)

menuconfig: $(KCFG_MENU) $(KCFG_CONF) $(KCFG_FIXDEP)
	$(Q)$(KCFG_MENU) $(KCFG_SPEC)
	$(Q)$(KCFG_CONF) $(KCFG_SILENT) --syncconfig $(KCFG_SPEC)

saveconfig: $(KCFG_CONF)
	$(Q)$< $(KCFG_SILENT) --savedefconfig=$(KCFG_DEFAULT) $(KCFG_SPEC)


npc_set: $(KCFG_CONF) $(KCFG_FIXDEP)
	$(Q)$< $(KCFG_SILENT) --defconfig=$(KCFG_DEFAULT) $(KCFG_SPEC)
	$(Q)$< $(KCFG_SILENT) --syncconfig $(KCFG_SPEC)

help:
	@echo '  menuconfig       - Edit the active simulator configuration'
	@echo '  npc_set          - Restore the NPC defaults'
	@echo '  saveconfig       - Store the active settings as NPC defaults'
	@echo '  safety-check     - Validate RTL interfaces and generated SoC inputs'
	@echo '  safety-lint      - Run interface checks and Verilator RTL lint'
	@echo '  safety-check-all - Run all available safety checks'

distclean: clean
	-$(Q)rm -rf $(KCFG_GARBAGE)

.PHONY: menuconfig saveconfig npc_set help distclean

define call_fixdep
	@$(KCFG_FIXDEP) $(1) $(2) unused > $(1).tmp
	@mv $(1).tmp $(1)
endef
