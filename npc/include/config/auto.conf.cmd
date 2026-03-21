deps_config := \
	csrc/memory/Kconfig \
	/home/hhh/Public/ysyx/ysyx-workbench/npc/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
