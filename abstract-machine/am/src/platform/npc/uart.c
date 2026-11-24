#include <am.h>
#include <npc.h>

void putch(char ch) { outb(SERIAL_PORT, ch); }

// npc serial is output-only: always report "no data" (same as nemu/soc)
char getch(void) { return 0xff; }
