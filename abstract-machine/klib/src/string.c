#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)


//pass arguments without reference, hence the original 
//variables outside these functions won't be changed
//
//value in, value won't be changed
//pointer in, address won't be changed (but value could be)



size_t strlen(const char *s) {
  assert(s);
  size_t i = 0;
  while(s[i] != '\0') ++i;
  return i;
}


//note the '\0' at end
char *strcpy(char *dst, const char *src) {
  if(NULL == dst || NULL == src)
	return NULL;
  int i = 0;
  while(src[i] != '\0'){
  	dst[i] = src[i];
	++i;
  }
  dst[i] = '\0';
  return dst;
}


char *strncpy(char *dst, const char *src, size_t n) {
  if(NULL == dst || NULL == src || n < 0)
	return NULL;
  int i = 0;
  while(i < n){
  	dst[i] = src[i];
	++i;
  }
  dst[i] = '\0';
  return dst;
}



/* a bad example of strcat, returning the temporary address */
/*char *strcat(char *dst, const char *src) {
  if(NULL == dst || NULL == src)
	return NULL;
  char tmp[strlen(dst) + strlen(src) + 1] = {};
  strcpy(tmp,dst);
  strcpy(tmp+strlen(dst),src);
  return tmp;
}*/



char *strcat(char *dst, const char *src){
	if(NULL == dst || NULL == src)
		return NULL;
	strcpy(dst+strlen(dst),src);
	return dst;
}




//return the substract of ascii
int strcmp(const char *s1, const char *s2) {
  assert(s1); assert(s2);
  int i = 0;
  while(s1[i] == s2[i] && s1[i] != '\0') i++;
  return s1[i] - s2[i];
}



int strncmp(const char *s1, const char *s2, size_t n) {
  assert(s1); assert(s2); assert(n > 0);
  int i = 0;
  while(s1[i] == s2[i] && s1[i] != '\0' && i < n) i++;
  return (i == n) ? 0 : s1[i] - s2[i] ;
}



//memory set in byte
void *memset(void *s, int c, size_t n) {
  int i = 0;
  while(i < n)
  	((char*)s)[i++] = (char)c;
  return s;
}


//memory move in bytes, considering overlapping
void *memmove(void *dst, const void *src, size_t n) {
  if(dst == NULL || src == NULL)
    return NULL;

  char* dst_tmp = (char*)dst;
  char* src_tmp = (char*)src;
  if(dst_tmp > src_tmp && dst_tmp < src_tmp + n){
    dst_tmp = dst_tmp + n - 1;
    src_tmp = src_tmp + n - 1;
    while(n--){
        *dst_tmp = *src_tmp;
        dst_tmp --; src_tmp --;
    }
  }
  else{
    while(n--){
        *dst_tmp = *src_tmp;
        dst_tmp ++; src_tmp ++;
    }
  }
  return dst;//not reference
}


//memory copy in bytes, ignoring overlapping
void *memcpy(void *dst, const void *src, size_t n) {
  if(dst == NULL || src == NULL)
	return NULL;

  char* dst_tmp = (char*)dst;
  char* src_tmp = (char*)src;
  /*if(dst_tmp > src_tmp && dst_tmp < src_tmp + n){
  	dst_tmp = dst_tmp + n - 1;
	src_tmp = src_tmp + n - 1;
	while(n--){
		*dst_tmp = *src_tmp;
		dst_tmp --; src_tmp --;
	}
  }*/
  //else{
  	while(n--){
		*dst_tmp = *src_tmp;
		dst_tmp ++; src_tmp ++;
	}
  //}
  return dst;
}



int memcmp(const void *s1, const void *s2, size_t n) {
  assert(s1); assert(s2); assert(n > 0);
  int i = 0;
  while(((char*)s1)[i] == ((char*)s2)[i] && i < n) i++;
  return (i == n) ? 0 : ((char*)s1)[i] - ((char*)s2)[i];
}

#endif
