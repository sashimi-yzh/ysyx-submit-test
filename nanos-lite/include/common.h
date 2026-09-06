#ifndef __COMMON_H__
#define __COMMON_H__

/* Uncomment these macros to enable corresponding functionality. */
#define HAS_CTE
#define HAS_VME
// #define MULTIPROGRAM
// #define TIME_SHARING

#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <debug.h>
#include <sys/time.h>

// ramdisk.c
size_t ramdisk_read(void *buf, size_t offset, size_t len);
size_t ramdisk_write(const void *buf, size_t offset, size_t len);

// syscall.c
bool do_syscall(Context *c);

// device.c
size_t serial_write(const void *buf, size_t len, size_t offset);
int get_time(struct timeval *tv, struct timezone *tz);
size_t events_read(void *buf, size_t offset, size_t len);
size_t dispinfo_read(void *buf, size_t offset, size_t len);
size_t fb_write(const void *buf, size_t offset, size_t len);

#endif
