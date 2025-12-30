#include <stdio.h>
#include <stdint.h>
#include <assert.h> 
#include <string.h>

#include <dlfcn.h>  // 用于动态加载
/*extern "C" {
#include <../src/cpu/difftest/difftest.h>
}*/

#ifndef __DIFFTEST_H__
#define __DIFFTEST_H__




enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

void init_difftest(char *ref_so_file, long img_size, int port); 
void difftest_step(uint32_t pc, uint32_t npc);


#endif
