ifdef CONFIG_DIFFTEST
DIFF_REF_SO = $(NEMU_HOME)/build/riscv32-nemu-interpreter-so
ARGS_DIFF = --diff=$(DIFF_REF_SO)

$(DIFF_REF_SO):
	$(MAKE) -C $(NEMU_HOME) SHARE=1
endif
