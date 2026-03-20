#include "common.hpp"

std::string getOutputDir(std::string_view prefix) {
  // get timestamp once
  // later user use the same timestamp
  static auto now = std::chrono::system_clock::now();
  std::string_view git_commit_hash = _STR(GIT_COMMIT_HASH);
  auto shortGitHash = git_commit_hash.substr(0, 8);
  std::string logDir =
      std::format("{}/{}/{:%m%dT%H_%M_%S}", prefix, shortGitHash, now);
  system(("mkdir -p " + logDir).c_str());
  return logDir;
}


bool isCIEnv() {
  const char *ci_env = std::getenv("GITHUB_ACTIONS");
  return ci_env != nullptr && std::string_view(ci_env) == "true";
}
