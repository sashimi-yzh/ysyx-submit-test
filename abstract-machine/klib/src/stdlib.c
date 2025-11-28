#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static char *hbrk = NULL;
static unsigned long int next = 1;

int rand(void) {
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed) {
  next = seed;
}

int abs(int x) {
  return (x < 0 ? -x : x);
}

int atoi(const char* nptr) {
  int x = 0;
  while (*nptr == ' ') { nptr ++; }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr ++;
  }
  return x;
}

void reverse(char s[]){
  int n = strlen(s);
  int i,j,c;
  for (i=0,j=n-1;i<j;i++,j--){
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa_dec(int n , char s[]){
  if (n ==INT32_MIN ){
    char *res = "-2147483648";
    memcpy(s,res,12);
    return;
  }
  int i=0,sign=0;
  n = ((sign=n)<0)?-n:n;
  do{
    s[i++] = n%10+'0';
  }while ((n/=10)>0);
  if (sign<0){
    s[i++]='-';
  }
  s[i] = '\0';
  reverse(s);
}

void itoa_hex(unsigned n, char s[]){
  int i=0; 
  do{
    s[i++] = (n%16>=10)?n%16+'a'-10:n%16+'0';
  }while ((n/=16)>0);
  // HEX_PREFIX
  s[i] = '\0';
  reverse(s);
}

void klib_itoa(int n , char s[], int type){
  switch (type){
  case ITOA_DEC: itoa_dec(n,s); break;
  case ITOA_HEX: itoa_hex((unsigned)n,s); break;
  default:break;
  }
  return;
}

void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
  if (!hbrk) hbrk = (void *)ROUNDUP(heap.start, 8);

  size  = (size_t)ROUNDUP(size, 8);
  char *old = hbrk;
  hbrk += size;
  assert((uintptr_t)heap.start <= (uintptr_t)hbrk && (uintptr_t)hbrk < (uintptr_t)heap.end);
  for (uint64_t *p = (uint64_t *)old; p != (uint64_t *)hbrk; p ++) {
    *p = 0;
  }
  return old;
  // #if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
    // panic("Not implemented!\n");
  // #endif
  // return malloc(size);  

}

void free(void *ptr) {
}

#endif
