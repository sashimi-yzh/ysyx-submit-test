#pragma once
#include <bits/stdc++.h>
class Config {
  std::map<std::string, std::string> config;
  Config() {}

public:
  const std::string &filename = config["bin"];
  const std::string &elfFilename = config["elf"];
  const std::string &batch = config["batch"];
  static Config &getInstance() {
    static Config config;
    return config;
  }
  bool load(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
      std::string arg = argv[i];
      if (auto gap = arg.find('='); gap == arg.npos) {
        std::cout << "invalid arg: " << arg << std::endl;
        return 0;
      } else {
        std::string key = arg.substr(0, gap);
        config[key] = arg.substr(gap + 1);
      }
    }
    return 1;
  }
};