#include <ansi_col.h>
#include <tracers.hpp>

#include <assert.h>
#include <capstone/capstone.h>
#include <dlfcn.h>
#include <string.h>

#define _gv(n) n##_dl
#define _gt(n) n##_func_t

#define _def(st, ret, n, ...)                                                  \
  typedef ret (*_gt(n))(__VA_ARGS__);                                          \
  st _gt(n) _gv(n) = NULL;

#define _open(n)                                                               \
  _gv(n) = (_gt(n))dlsym(dl_handle, #n);                                       \
  assert(_gv(n));

_def(static, size_t, cs_disasm, csh handle, const uint8_t *code,
     size_t code_size, uint64_t address, size_t count, cs_insn **insn);
_def(static, void, cs_free, cs_insn *insn, size_t count);

static csh handle;

static void init_disasm() {
  void *dl_handle;
  char buf[512];
  buf[0] = 0;
  const char *am_home_env = getenv("AM_HOME");
  assert(am_home_env);
  strcpy(buf, am_home_env);
  strcat(buf, "/../sdb/tools/capstone/repo/libcapstone.so.5");
  dl_handle = dlopen(buf, RTLD_LAZY);
  assert(dl_handle);

  _def(, cs_err, cs_open, cs_arch arch, cs_mode mode, csh * handle);
  _open(cs_open);
  _open(cs_disasm);
  _open(cs_free);

  cs_arch arch = CS_ARCH_RISCV;
  cs_mode mode = CS_MODE_RISCV32;

  int ret = cs_open_dl(arch, mode, &handle);
  assert(ret == CS_ERR_OK);
}
static void disassemble(char *str, int size, uint64_t pc, uint8_t *code,
                        int nbyte) {
  cs_insn *insn;
  size_t count = cs_disasm_dl(handle, code, nbyte, pc, 0, &insn);
  // assert(count == 1);
  if (count != 1) {
    snprintf(str, size, "(invalid)");
    return;
  }
  int ret = snprintf(str, size, "%s", insn->mnemonic);
  if (insn->op_str[0] != '\0') {
    snprintf(str + ret, size - ret, "\t%s", insn->op_str);
  }
  cs_free_dl(insn, count);
}
using namespace sdb;
using namespace std;

string sdb::default_inst_disasm(paddr_t pc, vlen_inst_view inst) {
  static bool has_init = false;
  if (!has_init) {
    init_disasm();
    has_init = true;
  }
  char buf[256];
  if (inst.size() == 4) {
    uint32_t code = *(uint32_t *)inst.data();
    if (code == 0) {
      return "(null)";
    }
  }
  disassemble(buf, sizeof(buf), pc, (uint8_t *)inst.data(), inst.size());
  return buf;
}

string sdb::_impl::expand_tabs(std::string_view in, int tabsize) {
  string out;
  out.reserve(in.size() * tabsize);
  int col = 0;
  for (char c : in) {
    if (c == '\t') {
      int spaces = tabsize - (col % tabsize);
      out.append(spaces, ' ');
      col += spaces;
    } else {
      out.push_back(c);
      col++;
    }
  }
  return out;
}

string sdb::disasm_trace_handler::_dump_inst(disasm_trace_handler::_ctx_ref ctx,
                                             bool highlight_disasm) {
#define ANSI_FG_LIGHTGRAY "\e[38;2;149;164;192m"
  string res;
  auto as_u32code = *(uint32_t *)ctx.inst.data();
  res += format(ANSI_FG_LIGHTGRAY"{:08x}" ANSI_FG_GRAY ": {:08x} {}{:25}", ctx.pc,
                as_u32code, highlight_disasm ? ANSI_FG_RED : ANSI_NONE,
                _impl::expand_tabs(_disasm(ctx.pc, ctx.inst)));
  // for(size_t j=0;j<ctx.inst.size();j++){
  // 	if(j) res+=format(" ");
  //   res+=format("{:02X}",ctx.inst[j]);
  // }
  // res+=format("`{:08X}",as_u32code);
  // res+="" ANSI_NONE ;
  return res;
}
