#include "my_utils.h"
#include "spdlog/spdlog.h"
#include <MROM.h>
#include <cstdint>
#include <filesystem>
#include <fmt/format.h>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<uint32_t> mrom_content;

extern "C" void mrom_read(int32_t addr, int32_t *data) {
  *data = mrom_content[(addr & 0x0FFFFFFF) >> 2];
}

void init_mrom(std::string_view image_path) {
  using std::ifstream;
  using std::ios;

  std::filesystem::path program_path = image_path;
  std::ifstream prog_file(program_path, ios::in | ios::binary);
  if (!prog_file.is_open()) {
    log_and_throw<std::runtime_error>("Failed to open image file : {}",
                                      image_path);
  }
  uint32_t size_prog = 0;
  prog_file.seekg(0, ios::end);
  size_prog = prog_file.tellg();
  prog_file.seekg(0, ios::beg);
  spdlog::info("Image size : {} bytes", size_prog);
  mrom_content.resize((size_prog + 3) / 4);
  spdlog::info("Buffer allocated, loading image");
  prog_file.read(reinterpret_cast<char *>(mrom_content.data()), size_prog);
  prog_file.close();
  spdlog::info("Loaded {} bytes to MROM", size_prog);
}