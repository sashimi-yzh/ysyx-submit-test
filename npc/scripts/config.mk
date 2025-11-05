

KCONFIG = $(NPC_HOME)/Kconfig
CONFIG = $(NPC_HOME)/.config
AUTOCONF_H = $(NPC_HOME)/csrc/include/autoconf.h


menuconfig:
	@python3 $(NPC_HOME)/scripts/menuconfig.py $(KCONFIG)
	@python3 $(NPC_HOME)/scripts/genconfig.py $(KCONFIG) --header-path $(AUTOCONF_H)
	@python3 $(NPC_HOME)/scripts/config2json.py $(NPC_HOME)/.config $(NPC_HOME)/.config.json
	@echo "Configuration updated and saved to NPC_HOME/.config, NPC_HOME/csrc/include/autoconf.h and NPC_HOME/.config.json"


include $(CONFIG)

# 判断优化级别
ifeq ($(CONFIG_CC_O2),y)
CXXFLAGS += $(CONFIG_CC_OPT)
endif

ifeq ($(CONFIG_DIFFTEST),y)
#CFLAGS += -I$(CONFIG_LIBRARY_PATH)
ifeq ($(CONFIG_DIFFTEST_REF_NEMU),y)
ifeq ($(USE_SOC),y)
	LDFLAGS += -L$(NPC_HOME)/difftest/riscv32e-nemu-ysyxsoc-so
else
	LDFLAGS += -L$(NPC_HOME)/difftest/riscv32e-nemu-npc-so
endif
endif
endif

