#ifndef __MYDPI_H__
#define __MYDPI_H__
#include "svdpi.h"
#ifdef RISCV32E_NPC
#include "Vysyx_26040117_SIM__Dpi.h"
#else
#include "VysyxSoCFull__Dpi.cpp"
#endif
#endif
