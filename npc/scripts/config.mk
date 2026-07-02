COLOR_RED := $(shell echo "\033[1;31m")
COLOR_END := $(shell echo "\033[0m")

ifeq ($(wildcard $(NPC_HOME)/.config),)
$(warning $(COLOR_RED)Warning: .config does not exist!$(COLOR_END))
$(warning $(COLOR_RED)Defaulting to 'make npc_defconfig'.$(COLOR_END))
endif

Q            := @
KCONFIG_PATH := $(NPC_HOME)/tools/kconfig
FIXDEP_PATH  := $(NPC_HOME)/tools/fixdep
Kconfig      := $(NPC_HOME)/Kconfig
rm-distclean += $(NPC_HOME)/include/generated $(NPC_HOME)/include/config $(NPC_HOME)/.config $(NPC_HOME)/.config.old
silent := -s

CONF   := $(KCONFIG_PATH)/build/conf
MCONF  := $(KCONFIG_PATH)/build/mconf
FIXDEP := $(FIXDEP_PATH)/build/fixdep

$(CONF):
	$(Q)$(MAKE) $(silent) -C $(KCONFIG_PATH) NAME=conf

$(MCONF):
	$(Q)$(MAKE) $(silent) -C $(KCONFIG_PATH) NAME=mconf

$(FIXDEP):
	$(Q)$(MAKE) $(silent) -C $(FIXDEP_PATH)

$(NPC_HOME)/.config: $(CONF)
	$(Q)$< $(silent) --defconfig=./configs/npc_defconfig $(Kconfig)

$(NPC_HOME)/include/config/auto.conf $(NPC_HOME)/include/generated/autoconf.h: $(NPC_HOME)/.config $(CONF) $(FIXDEP) $(Kconfig)
	$(Q)$(CONF) $(silent) --syncconfig $(Kconfig)

menuconfig: $(MCONF) $(CONF) $(FIXDEP)
	$(Q)$(MCONF) $(Kconfig)
	$(Q)$(CONF) $(silent) --syncconfig $(Kconfig)

savedefconfig: $(CONF)
	$(Q)$< $(silent) --$@=./configs/npc_defconfig $(Kconfig)

%defconfig: $(CONF) $(FIXDEP)
	$(Q)$< $(silent) --defconfig=./configs/$@ $(Kconfig)
	$(Q)$< $(silent) --syncconfig $(Kconfig)

.PHONY: menuconfig savedefconfig defconfig

# Help text used by make help
help:
	@echo  '  menuconfig	  - Update current config utilising a menu based program'
	@echo  '  npc_defconfig  - Configure default NPC options'
	@echo  '  savedefconfig   - Save current config as configs/npc_defconfig (minimal config)'

distclean: clean
	-@rm -rf $(rm-distclean)

.PHONY: help distclean

define call_fixdep
	@$(FIXDEP) $(1) $(2) unused > $(1).tmp
	@mv $(1).tmp $(1)
endef
