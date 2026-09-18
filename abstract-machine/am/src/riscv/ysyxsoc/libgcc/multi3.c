//#include "tconfig.h"
//#include "tsystem.h"
//#include "coretypes.h"
//#include "tm.h"
//#include "libgcc_tm.h"
#define LIBGCC2_UNITS_PER_WORD (__riscv_xlen / 8)

#include "libgcc2.h"

#if __riscv_xlen == 32
/* Our RV64 64-bit routines are equivalent to our RV32 32-bit routines.  */
# define __multi3 __muldi3
#endif

DWtype
__multi3 (DWtype u, DWtype v)
{
  const DWunion uu = {.ll = u};
  const DWunion vv = {.ll = v};
  DWunion w;
  UWtype u_low = uu.s.low;
  UWtype v_low = vv.s.low;
  UWtype u_low_msb;
  UWtype w_low = 0;
  UWtype new_w_low;
  UWtype w_high = 0;
  UWtype w_high_tmp = 0;
  UWtype w_high_tmp2x;
  UWtype carry;

  /* Calculate low half part of u and v, and get a UDWtype result just like
     what __umulsidi3 do.  */
  do
    {
      new_w_low = w_low + u_low;
      w_high_tmp2x = w_high_tmp << 1;
      w_high_tmp += w_high;
      if (v_low & 1)
	{
	  carry = new_w_low < w_low;
	  w_low = new_w_low;
	  w_high = carry + w_high_tmp;
	}
      u_low_msb = (u_low >> ((sizeof (UWtype) * 8) - 1));
      v_low >>= 1;
      u_low <<= 1;
      w_high_tmp = u_low_msb | w_high_tmp2x;
    }
  while (v_low);

  w.s.low = w_low;
  w.s.high = w_high;

  if (uu.s.high)
    w.s.high = w.s.high + __muluw3(vv.s.low, uu.s.high);

  if (vv.s.high)
    w.s.high += __muluw3(uu.s.low, vv.s.high);

  return w.ll;
}
