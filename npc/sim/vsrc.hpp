#pragma once

#define _STR2(x) #x
#define _STR(x) _STR2(x)
#define _CONCAT2(a, b) a##b
#define _CONCAT(a, b) _CONCAT2(a, b)

#include _STR(TOP_NAME.h)
#include _STR(_CONCAT(TOP_NAME, __Dpi.h))

#include _STR(_CONCAT(TOP_NAME, __Syms.h))


constexpr bool is_soc() { 
#ifdef SIM_SOC
		return true;
#else
		return false;
#endif
}
