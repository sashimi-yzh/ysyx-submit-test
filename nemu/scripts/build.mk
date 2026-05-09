.DEFAULT_GOAL = app

# Add necessary options if the target is a shared library
ifeq ($(SHARE),1)
SO = -so
CFLAGS  += -fPIC -fvisibility=hidden
LDFLAGS += -shared -fPIC
endif

WORK_DIR  = $(shell pwd)
BUILD_DIR = $(WORK_DIR)/build

BUILD_DIR_GDB = $(WORK_DIR)/build_gdb

BUILD_DIR_HDEF = $(WORK_DIR)/build_Hdef

INC_PATH := $(WORK_DIR)/include $(INC_PATH)
OBJ_DIR  = $(BUILD_DIR)/obj-$(NAME)$(SO)
BINARY   = $(BUILD_DIR)/$(NAME)$(SO)

OBJ_DIR_GDB  = $(BUILD_DIR_GDB)/obj-$(NAME)$(SO)
BINARY_GDB   = $(BUILD_DIR_GDB)/$(NAME)$(SO)

OBJ_DIR_HDEF  = $(BUILD_DIR_HDEF)/obj-$(NAME)$(SO)
BINARY_HDEF   = $(BUILD_DIR_HDEF)/$(NAME)$(SO)

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

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o) $(CXXSRC:%.cc=$(OBJ_DIR)/%.o) #将 SRCS 中所有 .c 文件替换为 $(OBJ_DIR)/%.o

OBJS_GDB = $(SRCS:%.c=$(OBJ_DIR_GDB)/%.o) $(CXXSRC:%.cc=$(OBJ_DIR_GDB)/%.o)

OBJS_HDEF = $(SRCS:%.c=$(OBJ_DIR_HDEF)/%.i) $(CXXSRC:%.cc=$(OBJ_DIR_HDEF)/%.i)

# Compilation patterns
$(OBJ_DIR)/%.o: %.c
	@echo + CC $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $< 
	$(call call_fixdep, $(@:.o=.d), $@)

$(OBJ_DIR)/%.o: %.cc
	@echo + CXX $<
	@mkdir -p $(dir $@)
	@$(CXX) $(CFLAGS) $(CXXFLAGS) -c -o $@ $<
	$(call call_fixdep, $(@:.o=.d), $@)

$(OBJ_DIR_GDB)/%.o: %.c
	@echo + CC $<
	@mkdir -p $(dir $@)
	@$(CC) -fsanitize=address -g $(CFLAGS) -c -o $@ $<
	$(call call_fixdep, $(@:.o=.d), $@)

$(OBJ_DIR_HDEF)/%.o: %.c
	@echo + CC $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -E -o $@ $<
	$(call call_fixdep, $(@:.o=.d), $@)


# Depencies
-include $(OBJS:.o=.d)

# Some convenient rules

.PHONY: app clean

app: $(BINARY)

$(BINARY):: $(OBJS) $(ARCHIVES)
	@echo + LD $@
	@$(LD) -o $@ $(OBJS) $(LDFLAGS) $(ARCHIVES) $(LIBS)

$(BINARY_GDB):: $(OBJS_GDB) $(ARCHIVES)
	@echo + LD $@
	@$(LD) -o $@ $(OBJS_GDB) $(LDFLAGS) $(ARCHIVES) $(LIBS)


clean:
	-rm -rf $(BUILD_DIR)