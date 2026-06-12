#include <isa.h>

#define REG(name, bitsize, type, num) "<reg name=\"" #name "\" bitsize=\"" #bitsize "\" type=\"" #type "\" regnum=\"" #num "\"/>"

#define GDB_TARGET_RV32E \
"<target version=\"1.0\">" \
"<architecture>riscv:rv32</architecture>" \
"<feature name=\"org.gnu.gdb.riscv.cpu\">" \
REG(zero, 32, int, 0) \
REG(ra, 32, code_ptr, 1) \
REG(sp, 32, data_ptr, 2) \
REG(gp, 32, data_ptr, 3) \
REG(tp, 32, data_ptr, 4) \
REG(t0, 32, int, 5) \
REG(t1, 32, int, 6) \
REG(t2, 32, int, 7) \
REG(fp, 32, data_ptr, 8) \
REG(s1, 32, int, 9) \
REG(a0, 32, int, 10) \
REG(a1, 32, int, 11) \
REG(a2, 32, int, 12) \
REG(a3, 32, int, 13) \
REG(a4, 32, int, 14) \
REG(a5, 32, int, 15) \
REG(pc, 32, code_ptr, 32) \
"</feature>" \
"</target>"

#define GDB_TARGET MUXDEF(CONFIG_ISA64, TARGET_RV64, \
    MUXDEF(CONFIG_RVE, GDB_TARGET_RV32E, TARGET_RV32))

// #define GDB_TARGET MUXDEF(CONFIG_ISA64, TARGET_RV64, TARGET_RV32)

arch_info_t arch_info = { .target_desc = (char *)GDB_TARGET,
                          .smp = 1,
                          .reg_num = MUXDEF(CONFIG_RVE, 16, 32)
                        };
