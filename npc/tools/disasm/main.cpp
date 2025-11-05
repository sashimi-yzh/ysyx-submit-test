#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include "disasm.h"

#define BUF_SIZE 50

void replace_all(std::string& str, const std::string& old_substr, const std::string& new_substr) {
    size_t pos = 0;
    while ((pos = str.find(old_substr, pos)) != std::string::npos) {
        str.replace(pos, old_substr.length(), new_substr);
        pos += new_substr.length(); // 移动到新替换位置
    }
}


int main(){
	char buf[BUF_SIZE];
	init_disasm("riscv32");
    std::string line;
    std::string str_out;
    while(std::getline(std::cin,line)){
        uint32_t inst_code = 0;
        try {
            inst_code = static_cast<uint32_t>(std::stoul(line, nullptr, 16));
            disassemble(buf, BUF_SIZE, 0, (uint8_t*)&inst_code, 4);
        } catch (const std::invalid_argument& e) {
            strcpy(buf,line.c_str());
        } catch (const std::out_of_range& e) {
            strcpy(buf,line.c_str());
        }
        str_out = buf;
        str_out.erase(std::remove_if(str_out.begin(), str_out.end(), [](unsigned char c) {return c == ' '; }), str_out.end());
        replace_all(str_out, "\t", " ");
        std::cout<<str_out<<std::endl;
        fflush(stdout);
    }

	return 0;
}
