#pragma once
#include <cctype>
#include <charconv>
#include <concepts>
#include <cstdint>
#include <fmt/format.h>
#include <limits>
#include <optional>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <stdexcept>
#include <string_view>
#include <utility>
using std::optional;
using fmt::println, fmt::print;

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

template <class T> inline std::optional<T> to_number(std::string_view p) {
  int base = 10, offset = 0;
  if (p.size() >= 2 && p[0] == '0' && std::tolower(p[1]) == 'x') {
    base = 16;
    offset = 2;
  } else if (p.size() > 1 && p[0] == '0') {
    base = 8;
    offset = 1;
  }
  T ret = -1;
  auto [ptr, ec] = std::from_chars(p.begin() + offset, p.end(), ret, base);
  if (ec == std::errc::result_out_of_range) {
    println("Argument is too large : {}", p);
    return std::nullopt;
  } else if (ptr != p.end() || ec != std::errc()) {
    println("Invalid argument : {}", p);
    return std::nullopt;
  }
  return ret;
}

class EvaluationError : public std::logic_error {
public:
  explicit EvaluationError(const std::string &msg) : std::logic_error(msg) {}
};

template <class ExceptionType, typename... Args>
[[noreturn]] void log_and_throw(fmt::format_string<Args...> fmt,
                                Args &&...args) {
  auto err_msg = fmt::format(fmt, std::forward<Args>(args)...);
  spdlog::error(err_msg);
  throw ExceptionType(err_msg);
}

template <uint64_t Len, class T = uint32_t>
  requires std::unsigned_integral<T>
constexpr T sign_ext(T raw) {
  static_assert(Len > 0 && Len <= std::numeric_limits<T>::digits,
                "Len > 0 && Len <= bitwidth");
  struct {
    int64_t x : Len;
  } v = {.x = raw};
  return v.x;
}

template <uint64_t High, uint64_t Low = High, class T = uint32_t>
  requires std::unsigned_integral<T>
constexpr T bits(T raw) {

  static_assert(High >= Low && High < std::numeric_limits<T>::digits &&
                    Low >= 0,
                "High >= Low && High < bitwidth && Low >= 0");
  if constexpr (High == std::numeric_limits<T>::digits - 1)
    return raw >> Low;
  else {
    uint64_t high_mask = (1ull << (High + 1)) - 1;
    return (raw & high_mask) >> Low;
  }
}