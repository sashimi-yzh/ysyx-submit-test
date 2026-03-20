# include $(YSYX_HOME)/init-deps/always-install-llvm.mk

# sdb
INC_PATH += $(abspath ../sdb/include)
LDFLAGS += $(SAN_FLAGS) -L$(abspath ../sdb/build) -lsdb
ARCHIVES += $(NVBOARD_ARCHIVE) $(abspath ../sdb/build/libsdb.a)

SDB_BUILD_LIB = $(abspath ../sdb/build/libsdb.a)
$(SDB_BUILD_LIB):
	$(YSYX_HOME)/init-deps/check-and-install-buildtools.sh
	@mkdir -p $(dir $@)
	@flock $@.lock -c '\
		if [ ! -f $(SDB_BUILD_LIB) ]; then \
			$(MAKE) -C ../sdb; \
		fi'

DEPS_DIR = ./deps

# spdlog
SPDLOG_PATH ?= $(DEPS_DIR)/spdlog
SPDLOG_LIBPATH ?= $(SPDLOG_PATH)/build
INC_PATH += $(abspath $(SPDLOG_PATH)/include)
LDFLAGS += -L$(abspath $(SPDLOG_LIBPATH)) -lspdlog
CXXFLAGS += -DSPDLOG_COMPILED_LIB

# gdbstub
GDBSTUB_PATH ?= $(DEPS_DIR)/mini-gdbstub
GDBSTUB_LIBPATH ?= $(GDBSTUB_PATH)/build
INC_PATH += $(abspath $(GDBSTUB_PATH)/include)
LDFLAGS += -L$(abspath $(GDBSTUB_LIBPATH)) -lgdbstub

# tabulate
TABULATE_PATH ?= $(DEPS_DIR)/tabulate
INC_PATH += $(abspath $(TABULATE_PATH)/include)

# json
JSON_PATH ?= $(DEPS_DIR)/json
INC_PATH += $(abspath $(JSON_PATH)/include)

SIM_DEP_LIBS_CLONE_DONE = $(DEPS_DIR)/clone.done
$(SIM_DEP_LIBS_CLONE_DONE):
	@mkdir -p $(DEPS_DIR)
	@./scripts/dev-init/clone_deps.sh $(DEPS_DIR)
	@touch $@

SIM_DEP_LIBS_BUILD_DONE = $(DEPS_DIR)/build.done
$(SIM_DEP_LIBS_BUILD_DONE): $(SDB_BUILD_LIB) $(SIM_DEP_LIBS_CLONE_DONE) 
	@+./scripts/dev-init/build_deps.sh $(DEPS_DIR)
	@touch $@

sim-bin-deps: $(SIM_DEP_LIBS_CLONE_DONE) $(SIM_DEP_LIBS_BUILD_DONE)


