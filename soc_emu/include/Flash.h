#pragma once
#include <cstdint>
#include <print>
#include <vector>

extern std::vector<uint32_t> flash_content;

void init_flash(std::string_view image_path);