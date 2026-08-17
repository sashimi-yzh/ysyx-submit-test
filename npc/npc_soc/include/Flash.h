#pragma once
#include <cstdint>
#include <fmt/format.h>
#include <vector>

extern std::vector<uint32_t> flash_content;

void init_flash(std::string_view image_path);