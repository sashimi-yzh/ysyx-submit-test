// Itraceparser.h
#include <fstream>
#include <string>
#include <cstdint>
#include <functional>
#include <optional>

namespace cachesim {

class ItraceParser {
public:
    // 回调函数类型：处理每个 PC 地址
    using Callback = std::function<void(uint32_t pc)>;
    
    explicit ItraceParser(const std::string& filename);
    ~ItraceParser() = default;
    
    // 禁止拷贝，允许移动
    ItraceParser(const ItraceParser&) = delete;
    ItraceParser& operator=(const ItraceParser&) = delete;
    ItraceParser(ItraceParser&&) noexcept = default;
    ItraceParser& operator=(ItraceParser&&) noexcept = default;
    
    // 解析文件，对每条记录调用回调函数
    void parse(Callback callback);
    
    // 解析单条记录（用于手动控制）
    [[nodiscard]] std::optional<uint32_t> parse_next() noexcept;
    
    // 检查文件是否打开成功
    [[nodiscard]] bool is_open() const noexcept { return file_.is_open(); }
    
    // 重置文件指针到开头
    void reset();

private:
    std::ifstream file_;
    
    // 解析一行：提取 PC 地址
    [[nodiscard]] static std::optional<uint32_t> parse_line(const std::string& line) noexcept;
};

}