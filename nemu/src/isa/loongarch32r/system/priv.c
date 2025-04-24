#include "../local-include/rtl.h"
#include <rtl/rtl.h>
#include <cpu/cpu.h>

void invtlb();
void tlbsrch();
void tlbwr();

static word_t* csr_decode(uint32_t csr) {
  switch (csr) {
    case 0x0:  return &cpu.crmd.val;
    case 0x1:  return &cpu.prmd.val;
    case 0x5:  return &cpu.estat.val;
    case 0x6:  return &cpu.era;
    case 0xc:  return &cpu.eentry;
    case 0x30: return &cpu.save0;
    case 0x31: return &cpu.save1;
    case 0x10: return &cpu.tlbidx.val;
    case 0x11: return &cpu.tlbehi.val;
    case 0x12: return &cpu.tlbelo0;
    case 0x13: return &cpu.tlbelo1;
    case 0x88: return &cpu.tlbrentry;
    default: panic("unimplemented CSR 0x%x", csr);
  }
  return NULL;
}

void csrrd(word_t *dest, uint32_t csrid) {
  word_t *csr = csr_decode(csrid);
  assert(dest != NULL);
  *dest = *csr;
}

void csrwr(word_t src, uint32_t csrid) {
  word_t *csr = csr_decode(csrid);
  *csr = src;
}

word_t priv_inst(uint32_t op, const word_t *src) {
  switch (op) {
    case PRIV_ERTN:
      cpu.crmd.plv  = cpu.prmd.pplv;
      cpu.crmd.ie = cpu.prmd.pie;
      if (cpu.estat.ecode == 0x3f) { cpu.crmd.pg = 1; }
      return cpu.era;
    case PRIV_INVTLB: invtlb(); break;
    case PRIV_TLBSRCH: tlbsrch(); break;
    case PRIV_TLBWR: tlbwr(); break;
    default: panic("Unsupported privilige operation = %d", op);
  }
  return 0;
}
