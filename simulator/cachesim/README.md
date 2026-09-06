# CacheSim - Cache 功能模拟器

## 项目简介

CacheSim 是一个轻量级的 cache 功能模拟器，用于在 cache 设计空间探索（Design Space Exploration, DSE）过程中快速统计 cache 缺失次数，从而估算总缺失时间（Total Miss Time, TMT），以评估不同 cache 参数配置对 IPC 的影响趋势。

本项目采用现代 C++（C++17/20）实现，旨在学习和实践现代 C++ 的最佳实践和特性。

## 背景与动机

### 设计空间探索的挑战

在给定的资源约束下，选择合适的 cache 参数（如容量、关联度、块大小等）以达到较好的性能表现，属于 cache 的设计空间探索问题。我们关心的性能指标包括：

- **IPC** (Instructions Per Cycle)
- **主频** (可通过 yosys-sta 项目快速评估)
- **面积** (可通过 yosys-sta 项目快速评估)

对于 IPC，通常需要在校准过访存延迟的 ysyxSoC 环境中运行完整程序后才能获得。但不同参数之间的组合情况太多，如果针对每一种参数组合都要花费小时级别的时间才能得到其 IPC，设计空间探索的效率将会十分低下。

### 解决方案：TMT 作为 IPC 的代理指标

由于数据精度和仿真效率是权衡关系，为了提升设计空间探索的效率，我们可以牺牲 IPC 的统计精度，通过较低的开销来统计一个能体现 IPC 变化趋势的指标。

当我们调整 cache 的各种参数时，直接影响的是 **AMAT** (Average Memory Access Time)。根据 AMAT 的定义，调整上述参数并不影响 cache 的访问时间（可看作常数），因此我们真正需要关注的，只有程序在发生 cache 缺失时需要等待的总时间，我们将其称为 **总缺失时间（Total Miss Time, TMT）**。

**TMT 可以代表 IPC 的变化趋势**：TMT 越小，每条指令访存所需的周期数也越小，从而 IPC 越大。

## 设计思路

### 缺失次数的统计

为了低开销地统计 TMT，我们从"缺失次数 × 缺失代价"这个角度考虑：

1. **指令流是固定的**：对于给定的程序，cache 的访问次数是固定的。只要获得程序运行的 itrace，将其输入到 icache 中，就可以模拟 icache 工作的过程，从而统计 icache 的缺失次数。

2. **不需要完整仿真**：NPC 执行程序时，需要通过当前指令的执行结果来得知下一条需要执行的指令。但 itrace 已经包含了完整的指令流，因此在统计 TMT 时，我们只需要指令流的 PC 值，而不需要指令本身。

3. **只需要元数据**：icache 的数据部分是用来作为指令回复给 NPC 的 IFU 的，但由于统计 TMT 并不需要 NPC，因此 icache 的数据部分也不需要，只需要保留元数据部分即可。对于给定的访存地址序列，cache 的缺失次数与访存内容无关，通过维护元数据即可统计出正确的缺失次数。

因此，为了统计 icache 的缺失次数，我们完全没有必要每次都把程序完整运行一遍。我们真正需要的是一个简单的 cache 功能模拟器——**CacheSim**。

### 缺失代价的估算

由于 CacheSim 不包含 ysyxSoC 中的访存细节，因此原则上我们也无法准确地获取缺失代价。但根据讨论，只有块大小这个参数会影响缺失代价，因此我们可以在 ysyxSoC 中统计出一个平均缺失代价，并将其作为一个常数来估算 TMT。

## 工作流程

1. **生成指令流**：通过 NEMU 快速生成指令流的 PC 序列（简化版的 itrace）
2. **模拟 cache 行为**：CacheSim 接收 PC 序列，通过维护 cache 元数据来统计缺失次数
3. **计算 TMT**：TMT = 缺失次数 × 平均缺失代价（常数）
4. **评估性能趋势**：TMT 越小，IPC 越大

## 优势

- **高效**：不需要运行完整的 ysyxSoC 仿真，只需要处理指令流
- **轻量**：只需要维护 cache 元数据，不需要实际的数据存储
- **快速**：可以快速评估大量参数组合的性能趋势
- **准确**：对于缺失次数的统计是准确的，缺失代价可以通过校准获得

## 项目架构

### 目录结构
cachesim/
├── include/
│ ├── cache/
│ │ ├── cache.h # Cache 主类
│ │ ├── cache_config.h # Cache 配置结构
│ │ ├── cache_line.h # Cache Line 元数据
│ │ ├── replacement_policy.h # 替换策略接口
│ │ └── replacement_policies/ # 具体替换策略实现
│ │ ├── lru.h
│ │ ├── fifo.h
│ │ └── random.h
│ ├── parser/
│ │ └── itrace_parser.h # Itrace 文件解析器
│ ├── statistics/
│ │ └── cache_stats.h # 统计信息收集
│ └── utils/
│ ├── logger.h # 日志系统
│ └── exception.h # 异常类
├── src/
│ ├── cache/
│ │ ├── cache.cpp
│ │ ├── cache_line.cpp
│ │ └── replacement_policies/
│ │ ├── lru.cpp
│ │ ├── fifo.cpp
│ │ └── random.cpp
│ ├── parser/
│ │ └── itrace_parser.cpp
│ ├── statistics/
│ │ └── cache_stats.cpp
│ └── main.cpp
├── tests/
│ ├── test_cache.cpp
│ └── test_parser.cpp
├── CMakeLists.txt # 现代 CMake 构建
├── README.md
└── .clang-format # 代码格式化配置


### 核心模块设计

#### 1. CacheConfig（配置类）
- 使用 `struct` + 默认参数
- 支持初始化列表和结构化绑定
- 包含容量、块大小、关联度、替换策略等配置

#### 2. Cache 类
- RAII 管理资源
- 移动语义优化性能
- `constexpr` 和 `const` 正确性
- 使用 `std::unique_ptr` 管理替换策略

#### 3. CacheLine（元数据）
- 使用 `std::bitset` 或位操作
- 时间戳使用计数器
- 包含 tag、valid、dirty 等标志

#### 4. 替换策略
- 策略模式 + 接口抽象
- 支持 LRU、FIFO、Random 等策略
- 使用 `std::unique_ptr` 实现多态

#### 5. Itrace 解析器
- 使用 `std::filesystem` 处理文件
- 支持迭代器接口（C++17 ranges 风格）
- 使用 `std::optional` 处理错误

## 现代 C++ 特性应用

本项目旨在学习和实践现代 C++ 的最佳实践，以下是计划使用的特性：

### C++11 特性

| 特性 | 应用场景 | 学习价值 |
|------|---------|---------|
| `auto` / `decltype` | 类型推导，简化代码 | 减少冗余类型声明 |
| `range-based for` | 遍历容器和范围 | 现代循环语法 |
| `nullptr` | 空指针表示 | 类型安全的空指针 |
| `override` / `final` | 虚函数重写 | 明确意图，防止错误 |
| `= default` / `= delete` | 特殊成员函数控制 | 精确控制对象行为 |
| `std::unique_ptr` / `shared_ptr` | 智能指针 | 自动内存管理 |
| `std::move` / `std::forward` | 移动语义 | 性能优化 |
| `lambda` | 回调函数和算法 | 函数式编程风格 |
| `std::function` | 函数对象存储 | 可调用对象抽象 |

### C++14 特性

| 特性 | 应用场景 | 学习价值 |
|------|---------|---------|
| `std::make_unique` | 智能指针创建 | 便利函数 |
| 泛型 lambda | 模板 lambda | 更灵活的 lambda |
| 变量模板 | 模板元编程 | 高级模板技术 |

### C++17 特性

| 特性 | 应用场景 | 学习价值 |
|------|---------|---------|
| `std::optional` | 可选值处理 | 现代错误处理 |
| `std::variant` | 类型联合 | 类型安全的联合体 |
| `std::filesystem` | 文件操作 | 现代文件系统 API |
| `if constexpr` | 编译期分支 | 模板元编程优化 |
| 结构化绑定 | 多返回值处理 | 语法糖，简化代码 |
| `[[nodiscard]]` | 属性标记 | 防止忽略返回值 |
| `std::string_view` | 字符串视图 | 零开销字符串处理 |

### C++20 特性（计划）

| 特性 | 应用场景 | 学习价值 |
|------|---------|---------|
| `concepts` | 模板约束 | 类型约束和错误提示 |
| `ranges` | 范围库 | 函数式编程风格 |
| `std::format` | 格式化输出 | 现代格式化 API |
| `coroutines` | 协程（如需要） | 异步编程 |

### 代码风格规范

- **命名空间**：使用 `cachesim` 作为主命名空间
- **属性**：使用 `[[nodiscard]]` 标记不应忽略的返回值
- **异常安全**：使用 `noexcept` 标记不抛异常的函数
- **常量性**：优先使用 `const` 和 `constexpr`
- **内存管理**：使用智能指针，避免原始指针
- **错误处理**：使用异常或 `std::optional` 进行错误处理
- **RAII**：所有资源管理遵循 RAII 原则

## 实现计划（分阶段）

### 阶段 1：基础框架（C++11/14）
- [ ] CacheConfig 结构体设计
- [ ] CacheLine 元数据类实现
- [ ] 基础 Cache 类（直接映射）
- [ ] 简单的 Itrace 解析器
- [ ] 基础统计功能

### 阶段 2：高级特性（C++17）
- [ ] 替换策略抽象（LRU, FIFO）
- [ ] 使用 `std::optional` 处理错误
- [ ] 使用 `std::filesystem` 处理文件
- [ ] 结构化绑定优化代码
- [ ] 完整的统计信息收集

### 阶段 3：现代特性（C++20）
- [ ] 使用 `concepts` 约束模板
- [ ] 使用 `ranges` 简化数据处理
- [ ] 使用 `std::format` 格式化输出
- [ ] 性能分析与优化

### 阶段 4：完善与测试
- [ ] 单元测试（Google Test）
- [ ] 性能基准测试
- [ ] 文档完善
- [ ] 示例程序

## 使用说明

### 编译方法

mkdir build && cd build
cmake ..
make### 运行方法
h
./cachesim -f itrace-log.txt -c 4096 -b 64 -a 4 -p LRU### 输入输出格式

- **输入格式**：NEMU 生成的 itrace 文件
  
