#include <am.h>
#include <klib.h>
#include <klib-macros.h>
// #include <unistd.h>

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

// 内存
// 堆管理
static uint8_t *heap_start = NULL;
static uint8_t *heap_end = NULL;
static uint8_t *heap_brk = NULL;

// 初始化堆
void init_heap() {
    // 确保堆起始地址正确对齐
    extern char _end;
    heap_start = (uint8_t *)(((uintptr_t)&_end + 4095) & ~4095);
    heap_end = heap_start + 32 * 1024 * 1024; // 32MB
    heap_brk = heap_start;
}

// sbrk 实现
void *sbrk(intptr_t increment) {
    if (heap_start == NULL) {
        init_heap();
    }
    
    uint8_t *old_brk = heap_brk;
    
    if (increment > 0) {
        // 检查是否有足够空间
        if (heap_brk + increment > heap_end) {
            return (void *)-1; // 内存不足
        }
        heap_brk += increment;
    } else if (increment < 0) {
        // 减少堆大小
        heap_brk += increment; // increment 为负数
    }
    
    return old_brk;
}

// 内存块结构
typedef struct mem_block {
    size_t size;            // 块大小（不包括头部）
    struct mem_block *next; // 指向下一个空闲块
    int free;               // 空闲标志 (1=空闲, 0=已分配)
} mem_block_t;

// 空闲链表头
static mem_block_t *free_list = NULL;

// 对齐要求 (8字节对齐)
#define ALIGNMENT 8
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~(ALIGNMENT-1))
#define BLOCK_SIZE sizeof(mem_block_t)

// 最小块大小（防止产生过小碎片）
#define MIN_BLOCK_SIZE 16

void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
    if (size == 0) return NULL;
    
    // 初始化堆（如果尚未初始化）
    if (heap_start == NULL) {
        init_heap();
    }
    
    // 对齐大小
    size = ALIGN(size);
    
    // 首次调用初始化空闲链表
    if (free_list == NULL) {
        // 分配初始堆空间
        size_t init_size = 1024 * 1024; // 1MB
        void *mem = sbrk(init_size);
        if (mem == (void *)-1) return NULL;
        
        free_list = (mem_block_t *)mem;
        free_list->size = init_size - BLOCK_SIZE;
        free_list->next = NULL;
        free_list->free = 1;
    }
    
    mem_block_t *current = free_list;
    mem_block_t *prev = NULL;
    mem_block_t *best_fit = NULL;
    mem_block_t *best_fit_prev = NULL;
    size_t best_fit_size = SIZE_MAX; // 初始化为最大值

    // 使用最佳适应算法搜索空闲链表
    while (current != NULL) {
        if (current->free && current->size >= size) {
            // 检查是否比当前最佳选择更好
            if (current->size < best_fit_size) {
                best_fit = current;
                best_fit_prev = prev;
                best_fit_size = current->size;
            }
        }
        prev = current;
        current = current->next;
    }

    // 没有找到合适的块，扩展堆
    if (best_fit == NULL) {
        // 分配新空间（至少为请求大小的2倍）
        size_t new_size = size * 2 + BLOCK_SIZE;
        void *new_mem = sbrk(new_size);
        if (new_mem == (void *)-1) return NULL;
        
        // 将新分配的内存作为一个空闲块
        mem_block_t *new_block = (mem_block_t *)new_mem;
        new_block->size = new_size - BLOCK_SIZE;
        new_block->free = 1;
        new_block->next = free_list;
        free_list = new_block;

        // 再次调用malloc，这次应该能分配成功
        return malloc(size);
    }

    // 检查是否可以分割块
    if (best_fit->size >= size + BLOCK_SIZE + MIN_BLOCK_SIZE) {
        // 计算新块的位置（考虑头部大小）
        mem_block_t *new_block = (mem_block_t *)((uint8_t *)best_fit + BLOCK_SIZE + size);
        
        // 设置新块的属性
        new_block->size = best_fit->size - size - BLOCK_SIZE;
        new_block->free = 1;
        new_block->next = best_fit->next;
        
        // 更新当前块
        best_fit->size = size;
        best_fit->next = new_block;
    }

    // 从空闲链表中移除当前块
    if (best_fit_prev == NULL) {
        free_list = best_fit->next;
    } else {
        best_fit_prev->next = best_fit->next;
    }

    // 标记为已分配
    best_fit->free = 0;
    best_fit->next = NULL; // 已分配块不在空闲链表中

    // 返回用户可用空间的指针（跳过头部）
    return (void *)(best_fit + 1);
#endif
    return NULL;
}

void free(void *ptr) {
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
    if (ptr == NULL) return;
    
    // 获取内存块头部
    mem_block_t *block = (mem_block_t *)ptr - 1;
    
    // 标记为空闲
    block->free = 1;
    
    // 添加到空闲链表头部（简单高效）
    block->next = free_list;
    free_list = block;
    
    // 合并相邻空闲块
    mem_block_t *current = free_list;
    while (current && current->next) {
        // 计算当前块的结束地址
        uint8_t *current_end = (uint8_t *)(current + 1) + current->size;
        
        // 检查下一个块是否相邻
        if ((uint8_t *)current->next == current_end) {
            // 合并块
            current->size += BLOCK_SIZE + current->next->size;
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
#endif
}


#endif
