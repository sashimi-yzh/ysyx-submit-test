#include "ansi_col.h"
#include "elf_tool.hpp"
#include "sdb.hpp"
#include <tracers.hpp>

using namespace std;
using namespace sdb;

jump_type sdb::default_riscv_jump_recognizer(vlen_inst_view inst) {
  word_t instr = *(word_t *)inst.data();
  uint8_t opcode = instr & 0x7f;
  uint8_t funct3 = (instr >> 12) & 0x7;
  uint8_t rd = (instr >> 7) & 0x1f;
  uint8_t rs1 = (instr >> 15) & 0x1f;
  bool is_jal = opcode == 0x6f;
  bool is_jalr = opcode == 0x67 && funct3 == 0x0;
  bool is_ret = is_jalr && rd == 0 && rs1 == 1;
  bool is_call = (is_jal && rd == 1) || (is_jalr && rd == 1);
  if (is_call)
    return jump_type::call;
  if (is_ret)
    return jump_type::ret;
  return jump_type::normal;
}

word_t get_target_addr_riscv(const sdb::trace_context &ctx) {
  word_t instr = *(word_t *)ctx.inst.data();
  uint8_t opcode = instr & 0x7f;
  if (opcode == 0x6f) { // JAL
    int32_t imm = ((instr >> 21) & 0x3ff) << 1 | ((instr >> 20) & 0x1) << 11 |
                  ((instr >> 12) & 0xff) << 12 |
                  ((instr >> 31) ? 0xfffff000 : 0);
    return ctx.pc + imm;
  } else if (opcode == 0x67) { // JALR
    int32_t imm = ((instr >> 20) & 0xfff) | ((instr >> 31) ? 0xfffff000 : 0);
    uint8_t rs1 = (instr >> 15) & 0x1f;
    word_t base = ctx.regs[rs1];
    return (base + imm) & ~1;
  } else {
    return 0;
  }
}

class sdb::ftrace_handler : public trace_handler {
private:
  elf_handler elf;
  jump_recognizer recog_jmp;
  int func_depth = 0;

public:
  ftrace_handler(string_view elf_file, jump_recognizer r)
      : recog_jmp(r), func_depth(0) {
    fstream fs(string(elf_file), ios::in | ios::binary);
    elf.load(fs);
    _log("Loaded ELF file {}\n", elf_file);
  }
  virtual void handle(_ctx_ref ctx) override {
    auto type = recog_jmp(ctx.inst);
    if (type == jump_type::normal)
      return;
    if (type == jump_type::call)
      func_depth++;

    auto cur_f = elf.get_fun_at(ctx.pc);
    auto cur_fname = cur_f ? cur_f->name : "(unknown)";

    auto target = get_target_addr_riscv(ctx);

    auto tar_f = elf.get_fun_at(target);
    auto tar_fname = tar_f ? tar_f->name : "(unknown)";

    string msg, hint_str;
    word_t show_addr;
#define ANSI_FG_FUN "\e[38;2;220;220;170m"

    if (type == jump_type::call) {
      hint_str = ANSI_FG_YELLOW "call";
      msg =
          format(ANSI_FG_FUN "{}" ANSI_FG_GRAY " from " ANSI_FG_FUN "{}" ANSI_NONE,
                 tar_fname, cur_fname);
      show_addr = tar_f ? tar_f->addr : 0;
    } else {
      hint_str = ANSI_FG_BLUE "ret ";
      msg = format(ANSI_FG_GRAY "from " ANSI_FG_FUN "{}" ANSI_NONE, cur_fname);
      show_addr = cur_f ? cur_f->addr : 0;
    }
		(void)show_addr;

		// " ANSI_FG_GRAY "f`{:08X}
    _log("0x{:08X}: {}" ANSI_NONE "[{}] {}\n", ctx.pc,
         hint_str, func_depth, msg);

    if (type == jump_type::ret) {
      if (func_depth > 0)
        func_depth--;
      else
        _error("ret but func depth is 0");
    }
  }
};

trace_handler_ptr sdb::make_ftrace_handler(string_view elf_file,
                                           jump_recognizer recog_jmp) {
  return std::make_shared<ftrace_handler>(elf_file, recog_jmp);
}
