static void ebreak(long arg0, long arg1) {
  asm volatile("addi a0, x0, %0;"
               "addi a1, x0, %1;"
               "ebreak" : : "i"(arg0), "i"(arg1));
}
static void putch(char ch) { ebreak(256, ch); }
static void halt(int code) { ebreak(code, 0); while (1); }

void _start() {
  putch('H'); putch('e'); putch('l'); putch('l'); putch('o'); putch(','); putch(' ');
  putch('R'); putch('I'); putch('S'); putch('C'); putch('-'); putch('V'); putch('!');
  putch('\n');
  halt(0);
}
