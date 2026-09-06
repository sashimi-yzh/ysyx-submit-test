// Mtraceparser.cpp
#include "Mtraceparser.h"
#include <sstream>
#include <stdexcept>

namespace cachesim {

MtraceParser::MtraceParser(const std::string& filename) 
    : file_(filename) {
    if (!file_.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }
}

void MtraceParser::parse(Callback callback) {
    std::string line;
    while (std::getline(file_, line)) {
        if (auto access = parse_line(line)) {
            callback(access->is_write, access->address);
        }
    }
}

std::optional<MtraceParser::MemoryAccess> MtraceParser::parse_next() noexcept {
    std::string line;
    if (std::getline(file_, line)) {
        return parse_line(line);
    }
    return std::nullopt;
}

void MtraceParser::reset() {
    file_.clear();  // 清除错误状态
    file_.seekg(0, std::ios::beg);  // 回到文件开头
}

std::optional<MtraceParser::MemoryAccess> MtraceParser::parse_line(const std::string& line) noexcept {
    // 格式：[memory read] <value> from <address>
    //       [memory write] <value> to <address>
    
    MemoryAccess access;
    
    // 查找操作类型
    size_t read_pos = line.find("[memory read]");
    size_t write_pos = line.find("[memory write]");
    
    if (read_pos != std::string::npos) {
        access.is_write = false;
    } else if (write_pos != std::string::npos) {
        access.is_write = true;
    } else {
        return std::nullopt;  // 不是有效的内存访问行
    }
    
    // 查找 "from" 或 "to" 关键字
    size_t from_pos = line.find("from");
    size_t to_pos = line.find("to");
    size_t keyword_pos = (access.is_write ? to_pos : from_pos);
    
    if (keyword_pos == std::string::npos) {
        return std::nullopt;
    }
    
    // 提取地址（在 "from " 或 "to " 之后）
    size_t addr_start_pos = keyword_pos + (access.is_write ? 3 : 5);  // "to " 是3个字符，"from " 是5个字符
    if (addr_start_pos >= line.length()) {
        return std::nullopt;
    }
    std::string addr_str = line.substr(addr_start_pos);
    // 移除前导空格
    addr_str.erase(0, addr_str.find_first_not_of(" \t"));
    // 移除尾部空格和换行
    size_t end_pos = addr_str.find_first_of(" \t\n\r");
    if (end_pos != std::string::npos) {
        addr_str = addr_str.substr(0, end_pos);
    }
    
    // 解析十六进制地址
    std::istringstream addr_iss(addr_str);
    if (!(addr_iss >> std::hex >> access.address)) {
        return std::nullopt;
    }
    
    // 提取值（在操作类型和关键字之间）
    size_t op_end_pos = (access.is_write ? write_pos + 14 : read_pos + 13);  // "[memory write]" 是14字符，"[memory read]" 是13字符
    std::string value_str = line.substr(op_end_pos, keyword_pos - op_end_pos);
    // 移除前后空格
    value_str.erase(0, value_str.find_first_not_of(" \t"));
    size_t value_end = value_str.find_last_not_of(" \t");
    if (value_end != std::string::npos) {
        value_str = value_str.substr(0, value_end + 1);
    }
    
    // 解析值（十进制）
    std::istringstream value_iss(value_str);
    if (!(value_iss >> access.value)) {
        return std::nullopt;
    }
    
    return access;
}

}

