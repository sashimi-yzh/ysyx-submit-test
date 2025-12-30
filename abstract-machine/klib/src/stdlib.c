#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
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




//extern void *_heap_start; 
extern char _heap_start;
//static bool malloc_flag = true;
void *malloc(size_t size) {
	static void *ptr = NULL;
	if(ptr == NULL){
		//putch('I'); putch('N'); putch('I'); putch('T'); //putch(':');
        //put_pointer(_heap_start);
        //putch('\n');
		//
		ptr = (void*)&_heap_start;
    //   volatile void *temp = (void*)0x80000008;  // 使用volatile
    //     ptr = (void*)temp;
		//malloc_flag = false;
	}

	void *ret = ptr;
	ptr =(void *)ROUNDUP((char *)ptr+ size,8);
	return ret;
}


void free(void *ptr) {
}

#endif
