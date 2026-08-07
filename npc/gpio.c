#define GPIO_BASE 0x10002000
#define LED *(volatile unsigned short *)(GPIO_BASE + 0x0)
#define SW *(volatile unsigned short *)(GPIO_BASE + 0x4)
#define SEG *(volatile unsigned *)(GPIO_BASE + 0x8)
unsigned rev4(unsigned data) {
  data = (data & 0xffff0000) >> 16 | (data & 0x0000ffff) << 16;
  data = (data & 0xff00ff00) >> 8 | (data & 0x00ff00ff) << 8;
  data = (data & 0xf0f0f0f0) >> 4 | (data & 0x0f0f0f0f) << 4;
  return data;
}
int main() {
  unsigned seg =
      0 | 1 << 4 | 2 << 8 | 3 << 12 | 4 << 16 | 5 << 20 | 6 << 24 | 7 << 28;
  seg = rev4(seg);
  unsigned int marchid;
  asm volatile("csrr %0, marchid" : "=r"(marchid));
  SEG = marchid % 10 | marchid / 10 % 10 << 4 | marchid / 100 % 10 << 8 |
        marchid / 1000 % 10 << 12 | marchid / 10000 % 10 << 16 |
        marchid / 100000 % 10 << 20 | marchid / 1000000 % 10 << 24 |
        marchid / 10000000 % 10 << 28;
  while (1) {
    unsigned short sw = SW;
    LED = sw;
    if (sw == 0xf)
      break;
  }
  unsigned short led = 1;
  while (1) {
    for (volatile int i = 0; i <= 200; i++)
      ;
    LED = led;
    SEG = seg;
    led = led << 1 | led >> 15;
    seg = seg << 4 | ((seg + 1) & 0xf);
  }
}
