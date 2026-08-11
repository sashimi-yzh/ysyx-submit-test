#ifndef __UTILS_IRINGBUF_H__
#define __UTILS_IRINGBUF_H__

void iringbuf_init(void);
void iringbuf_push(const char *logline);
void iringbuf_dump(bool goodtrap);

#endif