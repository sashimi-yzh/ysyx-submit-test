#pragma once
#include <sdb.hpp>
#include <string>

namespace sdb {
using inst_disasmsembler =
    std::function<std::string(paddr_t pc, vlen_inst_view)>;

namespace _impl {
std::string expand_tabs(std::string_view in, int tabsize = 8);
}

std::string default_inst_disasm(paddr_t pc, vlen_inst_view inst);

// disasm trace

class disasm_trace_handler : public trace_handler {
private:
  size_t _threshold;
  inst_disasmsembler _disasm;

protected:
  std::string _dump_inst(_ctx_ref ctx, bool highlight_disasm = false);

public:
  disasm_trace_handler(inst_disasmsembler d = default_inst_disasm,
                       size_t th = 16)
      : _threshold(th), _disasm(d) {}
  virtual void handle(_ctx_ref ctx) override { _log("{}\n", _dump_inst(ctx)); }
  virtual bool no_call_when_batch(size_t n) override { return n > _threshold; }
};
inline trace_handler_ptr
make_disasm_trace_handler(inst_disasmsembler disasm = default_inst_disasm,
                          size_t n_show_threshold = 16) {
  return std::make_shared<disasm_trace_handler>(disasm, n_show_threshold);
}

// iringbuf

class iringbuf_trace_handler;
trace_handler_ptr
make_iringbuf_trace_handler(inst_disasmsembler = default_inst_disasm,
                            size_t n_records = 32);

// difftest

class difftest_trace_handler : public trace_handler {
private:
  struct difftest_imp;
  struct _imp_deleter {
    void operator()(difftest_imp *p);
  };
  std::unique_ptr<difftest_imp, _imp_deleter> _imp;

public:
  difftest_trace_handler(std::string_view ref_so_file, int port);
  virtual void handle(_ctx_ref) override; // step ref
  virtual void init(_ctx_ref, std::span<uint8_t> img_data,
                    paddr_t img_base_addr) override;
  void memcpy_to_ref(std::span<uint8_t> data, paddr_t addr);
  void skip_ref();
};
using difftest_trace_handler_ptr = std::shared_ptr<difftest_trace_handler>;
inline difftest_trace_handler_ptr
make_difftest_trace_handler(std::string_view ref_so_file, int port) {
  return std::make_shared<difftest_trace_handler>(ref_so_file, port);
}

// ftrace

class ftrace_handler;
enum class jump_type { normal, call, ret };

using jump_recognizer = std::function<jump_type(vlen_inst_view)>;
jump_type default_riscv_jump_recognizer(vlen_inst_view inst);

trace_handler_ptr
make_ftrace_handler(std::string_view elf_file,
                    jump_recognizer recog_jmp = default_riscv_jump_recognizer);

// etrace

enum class exception_type { none, ecall, eret };
using exception_recognizer = std::function<exception_type(vlen_inst_view)>;
exception_type default_riscv_exception_recognizer(vlen_inst_view inst);
trace_handler_ptr make_etrace_handler(
    exception_recognizer recog_exc = default_riscv_exception_recognizer);

// self-loop

class self_loop_trace_handler : public trace_handler {
public:
  std::function<word_t()> get_halt_ret;
  self_loop_trace_handler(std::function<word_t()> get_halt_ret = nullptr)
      : trace_handler("self-loop-detector"), get_halt_ret(get_halt_ret) {}
  virtual void handle(_ctx_ref ctx) override;
};
inline trace_handler_ptr make_self_loop_trace_handler(std::function<word_t()> get_halt_ret = nullptr) {
  return std::make_shared<self_loop_trace_handler>(get_halt_ret);
}

// watchpoint

class watchpoint_tracer : public trace_handler {
  uint64_t _last_val;
  expr_t _expr;

public:
  watchpoint_tracer(auto e) : trace_handler("watchpoint` " + e.raw), _expr(e) {
    _require_call_after_inst_exec = true;
  }
  virtual void init(_ctx_ref ctx, std::span<uint8_t>, paddr_t) override {
    _last_val = ctx.eval(_expr);
  }
  virtual void handle(_ctx_ref ctx) override {
    auto val = ctx.eval(_expr);
    if (_last_val != val) {
      _log("watchpoint : {} : old value {:08X}, new {:08X}\n", _expr.raw,
           _last_val, val);
      _req_stop();
    }
    _last_val = val;
  }
};

} // namespace sdb
