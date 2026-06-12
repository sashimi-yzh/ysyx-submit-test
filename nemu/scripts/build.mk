.DEFAULT_GOAL = app

# Add necessary options if the target is a shared library
ifeq ($(SHARE),1)
SO = -so
CFLAGS  += -fPIC -fvisibility=hidden
LDFLAGS += -shared -fPIC
endif

INC_PATH := $(ADD_INC_PATH) $(CFG_DIR)/include $(NEMU_HOME)/include $(INC_PATH)
INC_PATH := $(abspath $(INC_PATH))
# ifneq ($(CONFIG_NPC),)
# INC_PATH := $(ADD_INC_PATH) $(INC_PATH)
# endif
$(info NEMU INC_PATH $(INC_PATH))
OBJ_DIR  = $(BUILD_DIR)/obj-$(NAME)$(SO)
BINARY   = $(BUILD_DIR)/$(NAME)$(SO)

# Compilation flags
ifeq ($(CC),clang)
CXX := clang++
else
CXX := g++
endif
LD := $(CXX)
INCLUDES = $(addprefix -I, $(INC_PATH))
CFLAGS  := -O2 -MMD -Wall -Werror $(INCLUDES) $(CFLAGS)
LDFLAGS := -O2 $(LDFLAGS)

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o) $(CXXSRC:%.cc=$(OBJ_DIR)/%.o)


# Compilation patterns
$(OBJ_DIR)/%.o: %.c
	@echo + CC $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $(abspath $<)
	$(call call_fixdep, $(@:.o=.d), $@)
	@sed -i 's|include/config|$(abspath $(CFG_DIR)/include/config)|g' $(@:.o=.d)

$(OBJ_DIR)/%.o: %.cc
	@echo + CXX $<
	@mkdir -p $(dir $@)
	@$(CXX) $(CFLAGS) $(CXXFLAGS) -c -o $@ $(abspath $<)
	$(call call_fixdep, $(@:.o=.d), $@)
	@sed -i 's|include/config|$(abspath $(CFG_DIR)/include/config)|g' $(@:.o=.d)

# Depencies
-include $(OBJS:.o=.d)

# Some convenient rules

.PHONY: app clean

app: $(BINARY)

compile_git:
	$(call git_commit, "compile NEMU")

$(info NEMU archives $(ARCHIVES))
$(BINARY): $(OBJS) $(ARCHIVES) $(BINARY_DEPS) | compile_git
	@echo + LD $@
	$(LD) -o $@ $(OBJS) $(LDFLAGS) $(ARCHIVES) $(LIBS)

clean:
	-rm -rf $(BUILD_DIR)
