SO_PATH_NEMU = $(NEMU_HOME)/build/riscv32-nemu-interpreter-so
V_CXXFLAGS += -CFLAGS "-DSO_PATH_NEMU=$(SO_PATH_NEMU)"

$(SO_PATH_NEMU):
	make -C $(NEMU_HOME)