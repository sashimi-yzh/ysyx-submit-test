#pragma once
#include <bits/stdc++.h>

namespace format {
// https://en.wikipedia.org/wiki/ANSI_escape_code
inline const std::string red = "\033[31m";
inline const std::string blue = "\033[34m";
inline const std::string clear = "\033[0m";
inline const std::string greenBG = "\033[42m";
inline const std::string clearLine = "\033[2K";

}; // namespace format
template <typename T> std::string hex(T value) {
  static_assert(std::is_integral_v<T>, "hex<T> 只能用于整数类型");
  using U = std::make_unsigned_t<T>;
  std::ostringstream oss;
  for (int i = sizeof(T) - 1; i >= 0; i--) {
    oss << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
        << static_cast<int>((value >> (i * 8) & 0xFF));
    if (i)
      oss << " ";
  }
  return oss.str();
}
template <typename T> std::string bin(T value) {
  static_assert(std::is_integral_v<T>, "bin<T> 只能用于整数类型");
  std::ostringstream oss;
  for (int i = sizeof(T) * 8 - 1; i >= 0; i--) {
    oss << ((value >> i) & 1);
  }
  return oss.str();
}
template <typename T> void print(const T &value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Args>
void print(const T &first, const Args &...rest) {
  std::cout << first << " ";
  print(rest...);
}