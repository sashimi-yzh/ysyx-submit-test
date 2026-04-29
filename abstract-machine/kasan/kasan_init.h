#ifndef __KASAN_INIT_H__
#define __KASAN_INIT_H__

#include <klib.h>

#ifdef KASAN_ENABLED
void kasan_init();
#else
#define kasan_init() do{}while(0)
#endif

#endif // __KASAN_INIT_H__
