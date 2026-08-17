#pragma once
#include <cstdint>
#include <ctre/ctre.hpp>
#include <functional>
#include <string_view>
namespace Expr {
using namespace ctre::literals;
using TokenizorType = std::function<std::string_view(std::string_view)>;
template <ctll::fixed_string re> TokenizorType make_lexer() {
  return [](std::string_view str) -> std::string_view {
    auto m = ctre::search<re>(str);
    if (m)
      return m.to_view();
    else
      return "";
  };
}

enum TokenID : uint8_t {
  TK_NUM = 128,
  TK_EQ,
  TK_NEQ,
  TK_BOOL_AND,
  TK_BOOL_OR,
  TK_GE,
  TK_LE,
  TK_REG
};
enum class Catagory { OPERATOR_2, OPERATOR_1, OPERAND };
struct Token {
  int type;
  Catagory cata;
  uint32_t data;
};
const struct {
  TokenizorType tokenizor;
  int id;
  int priority = -1;
  Catagory cata = Catagory::OPERATOR_2;
} token_types[] = {
    {make_lexer<R"(^(?:0[xX][a-fA-F0-9]*|0[0-7]+|[1-9][0-9]*|0))">(), TK_NUM,
     -1, Catagory::OPERAND},
    {make_lexer<R"(^\$[a-z]{0,2}[0-9]?)">(), TK_REG, -1, Catagory::OPERAND},
    {make_lexer<R"(^\+)">(), '+', 40},
    {make_lexer<R"(^-)">(), '-', 40},
    {make_lexer<R"(^\*)">(), '*', 100},
    {make_lexer<R"(^/)">(), '/', 100},
    {make_lexer<R"(^%)">(), '%', 100},
    {make_lexer<R"(^==)">(), TK_EQ, 20},
    {make_lexer<R"(^!=)">(), TK_NEQ, 20},
    {make_lexer<R"(^>=)">(), TK_GE, 30},
    {make_lexer<R"(^<=)">(), TK_LE, 30},
    {make_lexer<R"(^>)">(), '>', 30},
    {make_lexer<R"(^<)">(), '<', 30},
    {make_lexer<R"(^!)">(), '!', -1, Catagory::OPERATOR_1},
    {make_lexer<R"(^&&)">(), TK_BOOL_AND, 4},
    {make_lexer<R"(^\|\|)">(), TK_BOOL_OR, 3},
    {make_lexer<R"(^~)">(), '~', -1, Catagory::OPERATOR_1},
    {make_lexer<R"(^&)">(), '&', 7},
    {make_lexer<R"(^\|)">(), '|', 5},
    {make_lexer<R"(^\^)">(), '^', 6},
    {make_lexer<R"(^\()">(), '(', -1, Catagory::OPERAND},
    {make_lexer<R"(^\))">(), ')', -1, Catagory::OPERATOR_1}};
constexpr size_t NR_TOKEN_TYPES = sizeof(token_types) / sizeof(token_types[0]);
} // namespace Expr