#define INST_RS3(s) BITS(s->isa.inst, 31, 27)
#define INST_FP_RM(s) BITS(s->isa.inst, 14, 12)

#include "../inst/pseudo.h"
#include "../inst/rvi.h"
#include "../inst/rvc.h"
#include "../inst/rvm.h"
#ifdef CONFIG_RVFD
#include "../inst/rvf.h"
#include "../inst/rvd.h"
#endif
#include "../inst/rva.h"
#include "../inst/priv.h"
#include "../inst/special.h"
