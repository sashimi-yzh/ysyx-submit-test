#ifndef __UTILS_H__
#define __UTILS_H__
#include <cassert>
#include <autoconf.h>
void close_tfp();
static void my_assert(bool cond){
#ifdef CONFIG_ENABLE_FST_TRACE
    close_tfp();

#endif
    assert(0);
}

#endif