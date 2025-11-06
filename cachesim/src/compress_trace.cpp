// 对于一段连续的PC序列, 我们可以只记录第一个PC和连续执行的指令数量
// 使用上面的方式进行压缩，并且最后输出为二进制格式
#include <fstream>
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

const uint16_t MAX_RUN_LENGTH = 65535;

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input.txt> <output.bin>\n";
        return 1;
    }

    const char* input_file = argv[1];
    const char* output_file = argv[2];

    // 打开输入文件
    std::ifstream in(input_file);
    if (!in) {
        std::cerr << "Error opening input file: " << input_file << std::endl;
        return 1;
    }

    // 打开输出文件 (二进制模式)
    std::ofstream out(output_file, std::ios::binary);
    if (!out) {
        std::cerr << "Error opening output file: " << output_file << std::endl;
        return 1;
    }

    std::string line;
    uint32_t prev_pc = 0;
    uint32_t start_pc = 0;
    uint32_t current_pc = 0;
    uint16_t run_length = 0;
    bool first_line = true;
    size_t line_count = 0;
    size_t compressed_entries = 0;

    auto write_sequence = [&]() {
        if (run_length == 0) return;
        
        out.write(reinterpret_cast<const char*>(&start_pc), sizeof(start_pc));
        out.write(reinterpret_cast<const char*>(&run_length), sizeof(run_length));
        compressed_entries++;
        
        // 重置序列
        run_length = 0;
    };

    while (std::getline(in, line)) {
        line_count++;
        
        // 跳过空行和注释
        if (line.empty() || line[0] == '#' || line[0] == ';') {
            continue;
        }

        try {
            // 转换十六进制字符串为整数
            unsigned long val = std::stoul(line, nullptr, 16);
            current_pc = static_cast<uint32_t>(val);
        } catch (const std::exception& e) {
            std::cerr << "Error parsing line " << line_count << ": " << line << " - " << e.what() << std::endl;
            continue;
        }

        // 跳过 SRAM 区域
        if (current_pc >= 0x0f000000 && current_pc < 0x0fffffff) {
            continue;
        }

        if (first_line) {
            start_pc = current_pc;
            run_length = 1;
            first_line = false;
        } else {
            // 检查是否顺序执行 (当前PC = 前一个PC + 4)
            if (current_pc == prev_pc + 4) {
                if (run_length < MAX_RUN_LENGTH) {
                    run_length++;
                } else {
                    // 达到最大长度，写入当前序列
                    write_sequence();
                    
                    // 开始新序列
                    start_pc = current_pc;
                    run_length = 1;
                }
            } else {
                // 非顺序执行，写入当前序列
                write_sequence();
                
                // 开始新序列
                start_pc = current_pc;
                run_length = 1;
            }
        }
        
        prev_pc = current_pc;
    }

    // 写入最后一个序列
    write_sequence();

    in.close();
    out.close();

    std::cout << "Compression complete!\n";
    std::cout << "Input lines: " << line_count << "\n";
    std::cout << "Compressed entries: " << compressed_entries << "\n";
    std::cout << "Compression ratio: " 
              << (line_count ? (100.0 - (100.0 * compressed_entries / line_count)) : 0)
              << "%\n";

    return 0;
}