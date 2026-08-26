#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;
extern char _heap_start;
char * addr=(char *)(&_heap_start);
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

char *itoa(int value, char* str, int base) {
  char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  unsigned int unum;
  int i=0,j,k;
  if(base<2 || base >36) panic("ERROR BASE(itoa)");
  unum=abs(value);
  if(value<0 && base == 10){
    *str='-';
    i++;
  }
  while(unum>0){
    *(str+i)=index[unum%base];
    unum/=base;
    i++;
  }
  *(str+i)='\0';
  char temp;
  for(j=(value>=0)?0:1,k=i-1;j<k;j++,k--){
    temp=*(str+j);
    *(str+j)=*(str+k);
    *(str+k)=temp;
  }
  return str;
}

char *ltoa(long int value, char* str, int base) {
  char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  unsigned long int unum;
  int i=0,j,k;
  if(base<2 || base >36) panic("ERROR BASE(itoa)");
  unum=(value<0 && base == 10)?-value:value;
  if(value<0 && base == 10){
    *str='-';
    i++;
  }
  while(unum>0){
    *(str+i)=index[unum%base];
    unum/=base;
    i++;
  }
  *(str+i)='\0';
  char temp;
  for(j=(value>=0)?0:1,k=i-1;j<k;j++,k--){
    temp=*(str+j);
    *(str+j)=*(str+k);
    *(str+k)=temp;
  }
  return str;
}

char *lltoa(long long int value, char* str, int base) {
  char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  unsigned long long int unum;
  int i=0,j,k;
  if(base<2 || base >36) panic("ERROR BASE(itoa)");
  unum=(value<0 && base == 10)?-value:value;
  if(value<0 && base == 10){
    *str='-';
    i++;
  }
  while(unum>0){
    *(str+i)=index[unum%base];
    unum/=base;
    i++;
  }
  *(str+i)='\0';
  char temp;
  for(j=(value>=0)?0:1,k=i-1;j<k;j++,k--){
    temp=*(str+j);
    *(str+j)=*(str+k);
    *(str+k)=temp;
  }
  return str;
}

char *utoa(unsigned int value, char* str, int base) {
  char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int i=0,j,k;
  if(base<2 || base >36) panic("ERROR BASE(utoa)");
  while(value>0){
    *(str+i)=index[value%base];
    value/=base;
    i++;
  }
  *(str+i)='\0';
  char temp;
  for(j=(value>=0)?0:1,k=i-1;j<k;j++,k--){
    temp=*(str+j);
    *(str+j)=*(str+k);
    *(str+k)=temp;
  }
  return str;
}

char *ultoa(unsigned long int value, char* str, int base) {
  char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int i=0,j,k;
  if(base<2 || base >36) panic("ERROR BASE(utoa)");
  while(value>0){
    *(str+i)=index[value%base];
    value/=base;
    i++;
  }
  *(str+i)='\0';
  char temp;
  for(j=(value>=0)?0:1,k=i-1;j<k;j++,k--){
    temp=*(str+j);
    *(str+j)=*(str+k);
    *(str+k)=temp;
  }
  return str;
}

char *ulltoa(unsigned long long int value, char* str, int base) {
  char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int i=0,j,k;
  if(base<2 || base >36) panic("ERROR BASE(utoa)");
  while(value>0){
    *(str+i)=index[value%base];
    value/=base;
    i++;
  }
  *(str+i)='\0';
  char temp;
  for(j=(value>=0)?0:1,k=i-1;j<k;j++,k--){
    temp=*(str+j);
    *(str+j)=*(str+k);
    *(str+k)=temp;
  }
  return str;
}

void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
  //panic("Not implemented");
#endif
  
  if(size==0) return (addr++);
  addr+=size;
  return addr-size;
}

void free(void *ptr) {
}

#endif
