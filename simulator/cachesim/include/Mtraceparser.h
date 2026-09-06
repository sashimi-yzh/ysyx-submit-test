// Mtraceparser.h
#include <fstream>
#include <string>
#include <cstdint>
#include <functional>
#include <optional>

namespace cachesim {

class MtraceParser {
public:
    // 回调函数类型：处理每个内存访问
    // 参数：is_write (true=write, false=read), address, value
    using Callback = std::function<void(bool is_write, uint32_t address)>;
    
    explicit MtraceParser(const std::string& filename);
    ~MtraceParser() = default;
    
    // 禁止拷贝，允许移动
    MtraceParser(const MtraceParser&) = delete;
    MtraceParser& operator=(const MtraceParser&) = delete;
    MtraceParser(MtraceParser&&) noexcept = default;
    MtraceParser& operator=(MtraceParser&&) noexcept = default;
    
    // 解析文件，对每条记录调用回调函数
    void parse(Callback callback);
    
    // 解析单条记录（用于手动控制）
    struct MemoryAccess {
        bool is_write;
        uint32_t address;
        uint32_t value;
    };
    [[nodiscard]] std::optional<MemoryAccess> parse_next() noexcept;
    
    // 检查文件是否打开成功
    [[nodiscard]] bool is_open() const noexcept { return file_.is_open(); }
    
    // 重置文件指针到开头
    void reset();

private:
    std::ifstream file_;
    
    // 解析一行：提取内存访问信息
    [[nodiscard]] static std::optional<MemoryAccess> parse_line(const std::string& line) noexcept;
};

}
