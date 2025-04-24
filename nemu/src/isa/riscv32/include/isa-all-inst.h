#include <cpu/decode.h>
#include "../local-include/rtl.h"

#define INST_RVI(f) \
  f(lui) f(auipc) f(jal) \
  f(add) f(sll) f(srl) f(slt) f(sltu) f(xor) f(or) f(sub) f(sra) f(and) \
  f(addi) f(slli) f(srli) f(slti) f(sltiu) f(xori) f(ori) f(srai) f(andi) \
  f(lw) f(lh) f(lb) f(lhu) f(lbu) f(sw) f(sh) f(sb) \
  f(lw_mmu) f(lh_mmu) f(lb_mmu) f(lhu_mmu) f(lbu_mmu) \
  f(sw_mmu) f(sh_mmu) f(sb_mmu) \
  f(jalr) f(beq) f(bne) f(blt) f(bge) f(bltu) f(bgeu) \
  IFDEF(CONFIG_RV64, f(ld) f(lwu) f(sd) f(ld_mmu) f(lwu_mmu) f(sd_mmu) \
  f(addw) f(sllw) f(srlw) f(subw) f(sraw) \
  f(addiw) f(slliw) f(srliw) f(sraiw)) \
  f(fence_i) f(fence) \

#define INST_RVM(f) \
  f(mul) f(mulh) f(mulhu) f(mulhsu) f(div) f(divu) f(rem) f(remu) \
  IFDEF(CONFIG_RV64, f(mulw) f(divw) f(divuw) f(remw) f(remuw)) \

#define INST_RVF(f) \
  f(flw) f(fsw) f(flw_mmu) f(fsw_mmu) \
  f(fadds) f(fsubs) f(fmuls) f(fdivs) f(fmins) f(fmaxs) \
  f(fsqrts) f(fles) f(flts) f(feqs) \
  f(fmadds) f(fmsubs) f(fnmsubs) f(fnmadds) \
  f(fsgnjs) f(fsgnjns) f(fsgnjxs) \
  f(fcvt_s_w) f(fcvt_s_wu) f(fcvt_s_l) f(fcvt_s_lu) \
  f(fcvt_w_s) f(fcvt_wu_s) f(fcvt_l_s) f(fcvt_lu_s) \
  f(fmv_x_w) f(fmv_w_x) \
  f(fcvt_s_w_rm) \
  f(fcvt_w_s_rm) f(fcvt_l_s_rm) f(fcvt_lu_s_rm) \

#define INST_RVD(f) \
  f(fld) f(fsd) f(fld_mmu) f(fsd_mmu) \
  f(faddd) f(fsubd) f(fmuld) f(fdivd) f(fmind) f(fmaxd) \
  f(fsqrtd) f(fled) f(fltd) f(feqd) \
  f(fmaddd) f(fmsubd) f(fnmsubd) f(fnmaddd) \
  f(fsgnjd) f(fsgnjnd) f(fsgnjxd) \
  f(fcvt_d_w) f(fcvt_d_wu) f(fcvt_d_l) f(fcvt_d_lu) \
  f(fcvt_w_d) f(fcvt_wu_d) f(fcvt_l_d) f(fcvt_lu_d) \
  f(fcvt_d_w_rm) f(fcvt_d_wu_rm) f(fcvt_d_l_rm) \
  f(fcvt_w_d_rm) f(fcvt_wu_d_rm) f(fcvt_l_d_rm) f(fcvt_lu_d_rm) \
  f(fcvt_d_s_rm) f(fcvt_s_d_rm) \
  f(fmv_x_d) f(fmv_d_x) \
  f(fcvt_d_s) f(fcvt_s_d) \
  f(fclassd)

#define INST_RVC(f) \
  f(c_li) f(c_addi) f(c_slli) f(c_srli) f(c_srai) f(c_andi) IFDEF(CONFIG_RV64, f(c_addiw)) \
  f(c_add) f(c_and) f(c_or) f(c_xor) f(c_sub) f(c_mv) IFDEF(CONFIG_RV64, f(c_addw) f(c_subw)) \
  f(c_j) f(p_jal) f(c_jr) f(c_jalr) \
  f(c_beqz) f(c_bnez) \
  f(p_blez) f(p_bgez) f(p_bltz) f(p_bgtz) \
  f(p_li_0) f(p_li_1) f(p_inc) f(p_dec) f(p_mv_src1) \
  f(p_ret) IFDEF(CONFIG_RV64, f(p_sext_w)) \

#define INST_SPECIAL(f) f(inv) f(rt_inv) f(ebreak) \

#define INST_LIST(f) f(atomic) f(system) \
  INST_RVI(f) \
  INST_RVM(f) \
  IFDEF(CONFIG_RVFD, INST_RVF(f) INST_RVD(f)) \
  INST_RVC(f) \
  INST_SPECIAL(f) \

def_all_EXEC_ID();
