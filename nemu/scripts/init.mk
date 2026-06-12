ifeq ($(wildcard $(NEMU_HOME)/tools/mini-gdbstub/.git),)
$(info Init mini-gdbstub...)
$(shell git submodule update --init $(NEMU_HOME)/tools/mini-gdbstub)
$(shell cd $(NEMU_HOME)/tools/mini-gdbstub; git apply $(NEMU_HOME)/../patch/mini-gdbstub/mini-gdbstub.patch)
endif
