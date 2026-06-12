#include <common.h>

extern bool g_print_step;

#ifdef CONFIG_FTRACE
const char *get_function_name(paddr_t addr);

void ftrace(int rd, int rs1, paddr_t pc, paddr_t dnpc) {
#define FUNC_NAME_MAX 128
#define FRONT_MSG "FTrace: "FMT_PADDR": ", pc
#define RET_MSG "ret  [%s]\n", pc_func_name
#define CALL_MSG "call [%s @ "FMT_PADDR"]\n", dnpc_func_name, dnpc
#define PRINT_MSG(cmd) do { \
  if (is_ret) { \
    cmd(FRONT_MSG); \
    for (i = 0; i < cnt - 1; i++) cmd("| "); \
    cmd(RET_MSG); \
  } \
  if (is_call) { \
    cmd(FRONT_MSG); \
    for (i = 0; i < cnt - 1; i++) cmd("| "); \
    cmd(CALL_MSG); \
  }} while(0) 

  static int cnt = 0;
  static bool last_is_ret = false;
  bool is_call = false;
  bool is_ret = false;
  bool rd_is_addr = rd == 1 || rd == 5;
  bool rs1_is_addr = rs1 == 1 || rs1 == 5;

  if (rd_is_addr) {
    is_call = true;
    if (!last_is_ret) {
      cnt++;
    }
    last_is_ret = false;
  }
  if (rd != rs1 && rs1_is_addr) {
    is_ret = true;
    if (last_is_ret) {
      cnt--;
    }
    last_is_ret = true;
  }

  const char *pc_func_name_raw = get_function_name(pc);
  const char *pc_func_name = (pc_func_name_raw == NULL || *pc_func_name_raw == '\0') ? 
    "???" : pc_func_name_raw;
  const char *dnpc_func_name_raw = get_function_name(dnpc);
  const char *dnpc_func_name = (dnpc_func_name_raw == NULL || *dnpc_func_name_raw == '\0') ? 
    "???" : dnpc_func_name_raw;
  int i;
#ifdef CONFIG_FTRACE_COND
  if (FTRACE_COND) {
    PRINT_MSG(log_write);
  }
#endif 
  if (g_print_step) {
    PRINT_MSG(printf);
  }
}
#endif

#ifdef CONFIG_ETRACE
void etrace(bool is_raise, word_t NO, word_t epc) {
#define ETRACE_RAISE_MSG "ETrace raise:  NO: %d  @" FMT_WORD "\n", NO, epc
#define ETRACE_RAT_MSG "ETrace ret:  to " FMT_WORD "\n", epc

#ifdef CONFIG_ETRACE_COND
  if (ETRACE_COND) {
    if (is_raise) {
      log_write(ETRACE_RAISE_MSG);
    } else {
      log_write(ETRACE_RAT_MSG);
    }
  }
#endif 
  if (g_print_step) {
    if (is_raise) {
      printf(ETRACE_RAISE_MSG);
    } else {
      printf(ETRACE_RAT_MSG);
    }
  }
}
#endif
