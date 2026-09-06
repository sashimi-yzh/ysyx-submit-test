// Itraceparser.cpp
#include "Itraceparser.h"
#include <sstream>

namespace cachesim {

ItraceParser::ItraceParser(const std::string& filename) 
    : file_(filename) {
    if (!file_.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }
}

void ItraceParser::parse(Callback callback) {
    std::string line;
    while (std::getline(file_, line)) {
        if (auto pc = parse_line(line)) {
            callback(pc.value());
        }
    }
}

std::optional<uint32_t> ItraceParser::parse_next() noexcept {
    std::string line;
    if (std::getline(file_, line)) {
        return parse_line(line);
    }
    return std::nullopt;
}

void ItraceParser::reset() {
    file_.clear();  // 清除错误状态
    file_.seekg(0, std::ios::beg);  // 回到文件开头
}

std::optional<uint32_t> ItraceParser::parse_line(const std::string& line) noexcept {
    
    size_t colon_pos = line.find(':');
    if (colon_pos == std::string::npos) {
        return std::nullopt;
    }
    
    std::string addr_str = line.substr(0, colon_pos);
    
    // 移除前导空格
    addr_str.erase(0, addr_str.find_first_not_of(" \t"));
    
    // 解析十六进制地址
    uint32_t pc = 0;
    std::istringstream iss(addr_str);
    if (iss >> std::hex >> pc) {
        return pc;
    }
    
    return std::nullopt;
}

}