#pragma once
#include "spdlog/spdlog.h"
#include <cctype>
#include <charconv>
#include <concepts>
#include <cstdint>
#include <variant>
#include <fmt/format.h>
#include <limits>
#include <optional>
#include <ostream>
#include <fmt/format.h>
#include <stdexcept>
#include <string_view>
#include <utility>
using std::optional;
using fmt::println, fmt::print;

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

// --- C++20-compatible Result<T> (replaces std::expected<T, std::string>) ---
struct UnexpectedError {
  std::string msg;
};

template <typename T>
class Result {
  std::variant<T, std::string> data_;

public:
  Result() = default;
  Result(T val) : data_(std::move(val)) {}
  Result(UnexpectedError err) : data_(std::move(err.msg)) {}

  explicit operator bool() const noexcept { return data_.index() == 0; }
  bool has_value() const noexcept { return data_.index() == 0; }

  T &value() {
    if (!has_value())
      throw std::logic_error("bad Result access: no value");
    return std::get<0>(data_);
  }
  const T &value() const {
    if (!has_value())
      throw std::logic_error("bad Result access: no value");
    return std::get<0>(data_);
  }

  std::string &error() {
    if (has_value())
      throw std::logic_error("bad Result access: no error");
    return std::get<1>(data_);
  }
  const std::string &error() const {
    if (has_value())
      throw std::logic_error("bad Result access: no error");
    return std::get<1>(data_);
  }

  bool operator==(const T &val) const {
    return has_value() && value() == val;
  }

  T *operator->() { return &value(); }
  const T *operator->() const { return &value(); }
  T &operator*() { return value(); }
  const T &operator*() const { return value(); }
};

inline UnexpectedError Err(std::string msg) { return {std::move(msg)}; }
constexpr std::array<uint32_t, 16> lookup_mask32 = {
    0x00000000, 0x000000FF, 0x0000FF00, 0x0000FFFF, 0x00FF0000, 0x00FF00FF,
    0x00FFFF00, 0x00FFFFFF, 0xFF000000, 0xFF0000FF, 0xFF00FF00, 0xFF00FFFF,
    0xFFFF0000, 0xFFFF00FF, 0xFFFFFF00, 0xFFFFFFFF};

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

[[noreturn]] inline void todo(std::string_view part) {
  auto err_msg = fmt::format("{} is not implemented", part);
  spdlog::error(err_msg);
  throw std::logic_error(err_msg);
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
                "High > Low && High < bitwidth && Low >= 0");
  if constexpr (High == std::numeric_limits<T>::digits - 1)
    return raw >> Low;
  else {
    uint64_t high_mask = (1ull << (High + 1)) - 1;
    return (raw & high_mask) >> Low;
  }
}

inline void write_mask(uint32_t &dst, uint32_t mask32, uint32_t wdata) {
  dst = (dst & ~mask32) | (wdata & mask32);
}

inline void write_mask(std::atomic<uint32_t> &dst, uint32_t mask32,
                       uint32_t wdata) {
  uint32_t t = dst.load(), new_value;
  do {
    new_value = (t & ~mask32) | (wdata & mask32);
  } while (!dst.compare_exchange_weak(t, new_value));
}
