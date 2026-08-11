# Shared compiler rules for the small Kconfig helpers.

.DEFAULT_GOAL := app

TOOL_BASE := $(abspath $(CURDIR))
TOOL_CACHE := $(TOOL_BASE)/build
TOOL_OBJECT_DIR := $(TOOL_CACHE)/obj-$(NAME)
TOOL_PROGRAM := $(TOOL_CACHE)/$(NAME)

TOOL_CXX := $(if $(filter clang,$(CC)),clang++,g++)
TOOL_LINK := $(TOOL_CXX)
TOOL_HEADERS := $(addprefix -I,$(TOOL_BASE)/include $(TOOL_INCLUDE))
CFLAGS := -O2 -MMD -Wall -Werror $(TOOL_HEADERS) $(CFLAGS)
LDFLAGS := -O2 $(LDFLAGS)

TOOL_C_UNITS := $(filter %.c,$(SRCS))
TOOL_CPP_UNITS := $(sort $(filter %.cc %.cpp,$(SRCS) $(CXXSRC)))
TOOL_OBJECTS := $(patsubst %.c,$(TOOL_OBJECT_DIR)/%.o,$(TOOL_C_UNITS)) \
	$(patsubst %.cc,$(TOOL_OBJECT_DIR)/%.o,$(filter %.cc,$(TOOL_CPP_UNITS))) \
	$(patsubst %.cpp,$(TOOL_OBJECT_DIR)/%.o,$(filter %.cpp,$(TOOL_CPP_UNITS)))

$(TOOL_OBJECT_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf '[tool] cc  %s\n' '$<'
	@$(CC) $(CFLAGS) -c $< -o $@

$(TOOL_OBJECT_DIR)/%.o: %.cc
	@mkdir -p $(dir $@)
	@printf '[tool] cxx %s\n' '$<'
	@$(TOOL_CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

$(TOOL_OBJECT_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@printf '[tool] cxx %s\n' '$<'
	@$(TOOL_CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

-include $(TOOL_OBJECTS:.o=.d)

app: $(TOOL_PROGRAM)

$(TOOL_PROGRAM): $(TOOL_OBJECTS) $(ARCHIVES)
	@mkdir -p $(dir $@)
	@printf '[tool] link %s\n' '$@'
	@$(TOOL_LINK) -o $@ $(TOOL_OBJECTS) $(LDFLAGS) $(ARCHIVES) $(LIBS)

clean:
	@rm -rf $(TOOL_CACHE)

.PHONY: app clean
