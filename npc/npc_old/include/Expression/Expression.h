#pragma once
#include "DUT.h"
#include "Mem.h"
#include "Setup.h"
#include "Simulate.h"
#include "my_utils.h"
#include <Expression/ExpressionToken.h>
#include <SDL2/SDL_stdinc.h>
#include <cctype>
#include <cmath>
#include <cstdint>

#include <optional>
#include <fmt/format.h>
#include <stack>
#include <string>
#include <string_view>
#include <vector>
namespace Expr {

struct Expression {
  std::vector<Token> nodes;
  std::string display;
  static Result<Expression> create_expression(std::string_view expr_str);
  Result<uint32_t> last_value;
  Result<uint32_t> eval() const;

private:
  Expression() = default;
};

inline Result<std::vector<Token>>
build_expr_tree(const std::vector<Token> &vtk) {
  std::vector<Token> ret;
  ret.reserve(vtk.size());
  std::stack<Token> stk_node;
  for (const Token &tk : vtk) {
    const auto tt_cur = token_types[tk.type];
    if (tt_cur.id == '(') {
      stk_node.push(tk);
    } else if (tt_cur.id == ')') {
      while (!stk_node.empty() && token_types[stk_node.top().type].id != '(') {
        ret.push_back(stk_node.top());
        stk_node.pop();
      }
      if (stk_node.empty()) {
        return Err("Invalid expression : unpaired bracket");
      } else {
        // paired bracket
        stk_node.pop();
      }
    } else {
      switch (tk.cata) {
      case Catagory::OPERAND:
        ret.push_back(tk);
        break;
      case Catagory::OPERATOR_2: {
        while (!stk_node.empty() &&
               (stk_node.top().cata == Catagory::OPERATOR_1 ||
                token_types[stk_node.top().type].priority >= tt_cur.priority)) {
          ret.push_back(stk_node.top());
          stk_node.pop();
        }
        stk_node.push(tk);
        break;
      }
      case Catagory::OPERATOR_1:
        stk_node.push(tk);
        break;
      }
    }
  }
  while (!stk_node.empty()) {
    if (token_types[stk_node.top().type].id == '(')
      return Err("Invalid expression : unclosed bracket");
    ret.push_back(stk_node.top());
    stk_node.pop();
  }

  return ret;
}

inline Result<Expression>
Expression::create_expression(std::string_view expr_str) {
  bool prev_is_operator = true;
  int cur_pos = 0;
  Expression ret;
  std::vector<Token> token_seq;
  while (cur_pos < expr_str.length()) {
    while (std::isspace(expr_str[cur_pos])) {
      cur_pos++;
      continue;
    }
    std::string_view cur_substr = expr_str.substr(cur_pos);
    int which = 0;
    std::string_view result;
    for (; which < NR_TOKEN_TYPES; which++) {
      const auto &tt = token_types[which];
      result = tt.tokenizor(cur_substr);

      if (result.length() > 0)
        break;
    }
    if (which == NR_TOKEN_TYPES) {
      return Err(
          fmt::format("Unknown token at pos {} : {}", cur_pos, cur_substr));
    }
    const auto &tt = token_types[which];

    Token cur_token = {which, token_types[which].cata, 0};
    if (tt.id == TK_NUM) {
      auto parse_num = to_number<uint32_t>(result);
      if (!parse_num.has_value())
        return Err(fmt::format("Invalid number : {}", result));
      cur_token.data = parse_num.value();
    } else if (tt.id == TK_REG) {
      if (result == "$0")
        cur_token.data = 0;
      else if (result == "$pc") {
        cur_token.data = 32;
      } else {
        std::string_view reg_name = result.substr(1);
        bool found = false;
        for (int i = 1; i < 32; i++) {
          if (reg_name == gpr_names[i]) {
            cur_token.data = i;
            found = true;
            break;
          }
        }
        if (!found) {
          return Err(fmt::format("Invalid gpr name : {}", result));
        }
      }
    }

    if ((tt.id == '-' || tt.id == '+' || tt.id == '*') && prev_is_operator) {
      cur_token.cata = Catagory::OPERATOR_1;
    }
    if ((prev_is_operator && cur_token.cata == Catagory::OPERATOR_2) ||
        (!prev_is_operator && cur_token.cata == Catagory::OPERAND)) {
      return Err(
          fmt::format("Invalid token '{}' at pos {}", result, cur_pos));
    }
    prev_is_operator = (cur_token.cata != Catagory::OPERAND);
    if (tt.id == '(')
      prev_is_operator = true;
    else if (tt.id == ')')
      prev_is_operator = false;

    ret.display += result;
    token_seq.push_back(cur_token);
    cur_pos += result.length();
  }
  auto suf = build_expr_tree(token_seq);
  if (!suf) {
    return Err(suf.error());
  }

  ret.nodes = std::move(suf.value());
  auto val = ret.eval();
  if (!val) {
    return Err(val.error());
  }
  ret.last_value = val;
  return ret;
}
inline Result<uint32_t> Expression::eval() const {
  std::stack<uint32_t> stk_calc;
  for (const Token &tk : nodes) {
    const auto &tt = token_types[tk.type];
    switch (tk.cata) {
    case Catagory::OPERAND:
      switch (tt.id) {
      case TK_NUM:
        stk_calc.push(tk.data);
        break;
      case TK_REG:
        if (tk.data == 32)
          stk_calc.push(dut->getPC());
        else
          stk_calc.push(dut->getGPR(tk.data));
        break;
      default:
        return Err("Unknown unary operator");
      }
      break;
    case Catagory::OPERATOR_2: {
      if (stk_calc.size() < 2)
        return Err("Invalid expression : insufficient operands");
      uint32_t rhs = stk_calc.top();
      stk_calc.pop();
      uint32_t lhs = stk_calc.top();
      stk_calc.pop();
      switch (tt.id) {
      case '+':
        stk_calc.push(lhs + rhs);
        break;
      case '-':
        stk_calc.push(lhs - rhs);
        break;
      case '*':
        stk_calc.push(lhs * rhs);
        break;
      case '/':
        if (rhs == 0)
          return Err("Evaluation error : division by zero");
        stk_calc.push(lhs / rhs);
        break;
      case '%':
        if (rhs == 0)
          return Err("Evaluation error : division by zero");
        stk_calc.push(lhs % rhs);
        break;
      case '&':
        stk_calc.push(lhs & rhs);
        break;
      case '|':
        stk_calc.push(lhs | rhs);
        break;
      case '^':
        stk_calc.push(lhs ^ rhs);
        break;
      case TK_BOOL_AND:
        stk_calc.push(lhs != 0 && rhs != 0);
        break;
      case TK_BOOL_OR:
        stk_calc.push(lhs != 0 || rhs != 0);
        break;
      case '>':
        stk_calc.push(lhs > rhs);
        break;
      case '<':
        stk_calc.push(lhs < rhs);
        break;
      case TK_GE:
        stk_calc.push(lhs >= rhs);
        break;
      case TK_LE:
        stk_calc.push(lhs <= rhs);
        break;
      case TK_EQ:
        stk_calc.push(lhs == rhs);
        break;
      case TK_NEQ:
        stk_calc.push(lhs != rhs);
        break;
      default:
        return Err("Unknown operator");
      }
      break;
    }
    case Catagory::OPERATOR_1:
      if (stk_calc.empty())
        return Err("Invalid expression : insufficient operands");
      uint32_t lhs = stk_calc.top();
      stk_calc.pop();
      switch (tt.id) {
      case '+':
        stk_calc.push(lhs);
        break;
      case '-':
        stk_calc.push(-lhs);
        break;
      case '~':
        stk_calc.push(~lhs);
        break;
      case '!':
        stk_calc.push(lhs == 0);
        break;
      case '*':
        if (lhs >= config.base_memory &&
            lhs < config.base_memory + config.mem_size) {
          stk_calc.push(mem[(lhs - config.base_memory) >> 2]);
        } else {
          return Err(
              "Evaluation error : memory address {:#010x} is out of range");
        }
        break;
      }
      break;
    }
  }
  if (stk_calc.size() > 1)
    return Err("Invalid expression : insufficient operators");
  if (stk_calc.empty())
    return Err("Invalid expression : empty expression");
  return stk_calc.top();
}

} // namespace Expr
