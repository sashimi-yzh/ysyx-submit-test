#include <am.h>
#include <klib.h>
#include <klib-macros.h>
/*
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
static inline size_t align_up(size_t x,size_t a){
  return (x+a-1)&~(a-1);
}
void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
  if(size==0) return NULL;
  extern Area heap;
  static uintptr_t cur=0;
  if(cur==0){
    cur=(uintptr_t)heap.start;
  }
  size=align_up(size,sizeof(uintptr_t));
  uintptr_t next=cur+size;
  if(next>(uintptr_t)heap.end){
    return NULL;
  }
  void *res=(void*)cur;
  cur=next;
  return res;
#else
  return NULL;  
#endif
}
// 没有完全实现free这里只是进行了占位
void free(void *ptr) {
  (void)ptr;
}

#endif
*/
#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static unsigned long int next = 1;

int rand(void) {
  next = next * 1103515245 + 12345;
  return (unsigned int)(next / 65536) % 32768;
}

void srand(unsigned int seed) {
  next = seed;
}

#endif
#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static inline size_t align_up(size_t x, size_t a){
  return (x+a-1)&~(a-1);
}
#define ALIGN (sizeof(uintptr_t))
#define HDR_SIZE (sizeof(size_t))
#define FTR_SIZE (sizeof(size_t))
#define MIN_FREE_PAYLOAD (sizeof(void*)*2)
#define MIN_BLOCK (HDR_SIZE+FTR_SIZE+MIN_FREE_PAYLOAD)
// 打包写入内存块的最终值
#define PACK(sz,alloc) ((sz)|((alloc)?1:0))
// 获取真正的头部数值
#define GET(p) (*(size_t*)(p))
// 给指针赋值
#define PUT(p,val) (*(size_t*)(p)=val)
// 获得整个块的大小（从header到footer）
#define GET_SIZE(p) (GET(p)&~(size_t)0x1)
#define GET_ALLOC(p) (GET(p)&(size_t)0x1)
// 计算当前块的块头地址
#define HDRP(bp) ((char*)(bp)-HDR_SIZE)
// 计算当前块的块尾地址
#define FTRP(bp) ((char*)(bp)+GET_SIZE(HDRP(bp))-HDR_SIZE-FTR_SIZE)
// 计算下一个块的可用区地址
#define NEXT_BLKP(bp) ((char*)(bp)+GET_SIZE(((char*)(bp)-HDR_SIZE)))
// 计算上一个块的块尾地址
#define PREV_FTRP(bp)   ((char *)(bp) - HDR_SIZE - FTR_SIZE)
// 计算上一个块的可用区地址
#define PREV_BLKP(bp)   ((char *)(bp) - GET_SIZE(PREV_FTRP(bp)))
// 定义自由链表的结构
 typedef struct free_node{
  struct free_node *prev;
  struct free_node *next;
 }free_node_t;
 // 初始化堆和自由链表
 static free_node_t *free_list=NULL;
 static int heap_inited=0;
 extern Area heap;
 // 头插法插入一个空闲内存结点
 static void insert_free(void *bp){
  free_node_t *node=(free_node_t*)bp;
  node->prev=NULL;
  node->next=free_list;
  if(free_list) free_list->prev=node;
  free_list=node;
 }
 // 移除一个空闲的内存结点
 static void remove_free(void *bp){
  free_node_t *node=(free_node_t*)bp;
  if(node->prev)  node->prev->next=node->next;
  else  free_list=node->next;
  if(node->next) node->next->prev=node->prev;
 }
 // 合并相邻空闲块
 static void *coalesce(void *bp){
  char *heap_start=(char*)heap.start;
  char *heap_end=(char*)heap.end;
  int prev_alloc=1;
  int next_alloc=1;
  // 判断是否有空余链表
  if((char*)PREV_FTRP(bp)>=heap_start){
    prev_alloc=GET_ALLOC(PREV_FTRP(bp));
  }
  char* next_hdr=HDRP(NEXT_BLKP(bp));
  if(next_hdr+HDR_SIZE<=heap_end){
    next_alloc=GET_ALLOC(next_hdr);
  }
  // 清除相邻链表的数据块
  size_t size=GET_SIZE(HDRP(bp));
  if(!prev_alloc){
    void* prev_bp=PREV_BLKP(bp);
    remove_free(prev_bp);
    size=size+GET_SIZE(HDRP(prev_bp));
    bp=prev_bp;
  }
  if(!next_alloc){
    void* next_bp=NEXT_BLKP(bp);
    remove_free(next_bp);
    size=size+GET_SIZE(HDRP(next_bp));
  }
  // 实现链表的合并
  PUT(HDRP(bp),PACK(size,0));
  PUT(FTRP(bp),PACK(size,0));
  return bp;
 }
// 堆的初始化
 static void heap_init(void) {
  if (heap_inited) return;
  heap_inited = 1;

  uintptr_t start = (uintptr_t)heap.start;
  uintptr_t end   = (uintptr_t)heap.end;

  // 对齐start，实现按字节访问
  start = align_up(start, ALIGN);
  // 计算可用总大小
  size_t total = (end > start) ? (end - start) : 0;
  total = (total / ALIGN) * ALIGN; 
  // 检查是否太小
  if (total < MIN_BLOCK) {
    free_list = NULL;
    return;
  }
  /*
  内存块的结构如下：
   +------------+----------------------------------+-------------+
   |   header   |             payload              |   footer    |
   +------------+----------------------------------+-------------+
  */
  // 真正的初始化整个heap一个大空闲块
  void *bp = (void *)(start + HDR_SIZE); // payload指针，其主要用于初始化bp指针的位置
  PUT((void *)start, PACK(total, 0));    // header指针，内部存储最终打包的数据
  PUT((char *)start + total - FTR_SIZE, PACK(total, 0)); // footer指针，内部存的数据和header是一样的

  free_list = NULL;
  insert_free(bp);
}

// 在空闲块 bp 上分裂并分配 size 字节
static void place(void *bp, size_t asize) {
  size_t csize = GET_SIZE(HDRP(bp));
  remove_free(bp);
  // 实现分配的核心逻辑，也就是把前半块分配，后半空闲继续
  if (csize - asize >= MIN_BLOCK) {
    // 分配当前块的大小
    PUT(HDRP(bp), PACK(asize, 1));
    PUT(FTRP(bp), PACK(asize, 1));
    // 下一个块的 payload = 当前 payload + 当前块大小
    void *nbp = (char *)bp + asize; 
    PUT(HDRP(nbp), PACK(csize - asize, 0));
    PUT(FTRP(nbp), PACK(csize - asize, 0));
    insert_free(nbp);
  } else {
    // 不够分裂，整块分配
    PUT(HDRP(bp), PACK(csize, 1));
    PUT(FTRP(bp), PACK(csize, 1));
  }
}
// 真正的malloc函数实现分配内存
void *malloc(size_t size) {
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
  if (size == 0) return NULL;
  heap_init();
  if (!free_list) return NULL;

  // 计算需要的块总大小
  size_t asize = size + HDR_SIZE + FTR_SIZE;
  asize = align_up(asize, ALIGN);
  if (asize < MIN_BLOCK) asize = MIN_BLOCK;

  // 找到第一个符合大小要求的块
  for (free_node_t *n = free_list; n; n = n->next) {
    void *bp = (void *)n;
    if (GET_SIZE(HDRP(bp)) >= asize) {
      place(bp, asize);
      return bp;
    }
  }
  return NULL;
#else
  return NULL;
#endif
}
// 本身没有要求实现free功能，但是鉴于完整性我还是决定实现这一功能
// 真正的free函数实现释放内存
void free(void *ptr) {
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
  if (!ptr) return;
  // 转变使用标记为空白
  size_t size = GET_SIZE(HDRP(ptr));
  PUT(HDRP(ptr), PACK(size, 0));
  PUT(FTRP(ptr), PACK(size, 0));
  // 合并并加入 free list
  void *bp = coalesce(ptr);
  insert_free(bp);
#else
  (void)ptr;
#endif
}


#endif