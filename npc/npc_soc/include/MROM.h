#pragma once

#include <cstdint>
#include <string_view>
#include <vector>
extern std::vector<uint32_t> mrom_content;
void init_mrom(std::string_view image_path);