
ifeq ($(CONFIG_ITRACE),)
CSRCS-BLACKLIST-y += $(NPC_HOME)/csrc/utils/disasm.c
else
LIBCAPSTONE = $(NEMU_HOME)/tools/capstone/repo/libcapstone.so.5
CXXFLAGS += -I$(NEMU_HOME)/tools/capstone/repo/include
$(NPC_HOME)/csrc/utils/disasm.c: $(LIBCAPSTONE)
$(LIBCAPSTONE):
	$(MAKE) -C $(NEMU_HOME)/tools/capstone
endif
