# 编译器设置
CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -Iinclude
LDFLAGS = 
TRACE_FILE = itrace/add.txt

# 目录设置
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)/bin

# 目标可执行文件
TARGET = $(BIN_DIR)/tb_cache

# 自动查找所有.cpp文件
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
DEPS = $(OBJECTS:.o=.d)

# 默认目标
all: $(TARGET)

# 链接可执行文件
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# 编译源文件到目标文件
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# 创建必要的目录
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# 运行单次测试（默认配置）
run: $(TARGET)
	./$(TARGET) $(TRACE_FILE)

# 运行所有配置测试
run-all: $(TARGET)
	./$(TARGET) $(TRACE_FILE) --all

# 清理生成的文件
clean:
	rm -rf $(BUILD_DIR)

# 清理并重新编译
rebuild: clean all

# 包含自动生成的依赖关系文件
-include $(DEPS)

# 伪目标
.PHONY: all run run-all clean rebuild