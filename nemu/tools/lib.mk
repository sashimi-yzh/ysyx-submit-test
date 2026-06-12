TOOLS_DIR = $(NEMU_HOME)/tools

_STATIC_LIBS = libgdbstub.a
STATIC_LIBS = $(addprefix $(BUILD_DIR)/,$(_STATIC_LIBS))
STATIC_INC = $(TOOLS_DIR)/mini-gdbstub/include


mini-gdbstub:
	$(MAKE) -C $(TOOLS_DIR)/mini-gdbstub all O=$(BUILD_DIR)/mini-gdbstub LIBGDBSTUB=$(BUILD_DIR)/libgdbstub.a ARCH=rv32

$(STATIC_LIBS): mini-gdbstub

.PHONY: mini-gdbstub
