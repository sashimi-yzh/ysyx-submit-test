#pragma once

#include "../sim.hpp"
#include "mregion.hpp"

#ifdef SIM_ARCH_JYD
bool jyd_is_good_trap();
#else
inline bool jyd_is_good_trap() {
	return false;
}
#endif

