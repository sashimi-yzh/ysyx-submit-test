#include <klib.h>
// avoid when kasan include printf.h
// been hook use klib func result dead
// asan loop
#undef memcpy
#undef memset
#undef malloc
#undef free
