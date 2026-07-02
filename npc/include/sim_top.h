#ifndef __SIM_TOP_H__
#define __SIM_TOP_H__

#include <platform/platform.h>

#if defined(NPC_BUILD_PLATFORM_NPC)
#include "Vtop.h"
#elif defined(NPC_BUILD_PLATFORM_YSYXSOC)
#include "VysyxSoCFull.h"
#else
#error "unknown NPC platform"
#endif

#endif
