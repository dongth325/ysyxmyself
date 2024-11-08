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

// 全局变量用于跟踪分配位置
__attribute__((unused)) static char *hbrk = NULL;

// 初始化堆
__attribute__((unused)) static void heap_reset() {
  hbrk = (void *)ROUNDUP(heap.start, 8);  // 按 8 字节对齐
}

void *malloc(size_t size) {
  // 第一次调用时初始化堆指针
  if (hbrk == NULL) {
    heap_reset();
  }

  // 内存对齐到 8 字节
  size = (size_t)ROUNDUP(size, 8);

  // 检查是否有足够的空间分配
  if ((uintptr_t)hbrk + size > (uintptr_t)heap.end) {
    return NULL;  // 返回 NULL 表示内存不足
  }

  // 分配内存
  char *old_hbrk = hbrk;
  hbrk += size;

  // 返回分配的内存地址
  return old_hbrk;
}
void free(void *ptr) {
}

#endif