#ifndef NPC_SIM_TOP_H
#define NPC_SIM_TOP_H

#include <npc/platform.h>

#if defined(NPC_BUILD_PLATFORM_YSYXSOC)
#include "VysyxSoCFull.h"
#elif defined(NPC_BUILD_PLATFORM_NPC)
#include "Vnpc_top.h"
#else
#error "unknown NPC platform"
#endif

#endif
