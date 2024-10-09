#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  panic("Not implemented");
}

char *strcpy(char *dst, const char *src) {
  panic("Not implemented");
}

char *strncpy(char *dst, const char *src, size_t n) {
  panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
  panic("Not implemented");
}

int strcmp(const char *s1, const char *s2) {
  panic("Not implemented");
}

int strncmp(const char *s1, const char *s2, size_t n) {
  panic("Not implemented");
}

void *memset(void *s, int c, size_t n) {
  panic("Not implemented");
}

void *memmove(void *dst, const void *src, size_t n) {
  panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n) {
      // 将in指向的内存区域复制到out指向的内存区域，共n个字节
      printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");//dddddddddddddddddddddddddddddd
    unsigned char *d = (unsigned char *)out;
    const unsigned char *s = (const unsigned char *)in;

    // 遍历并逐字节复制
    for (size_t i = 0; i < n; i++) {

        d[i] = s[i];
    }
    printf("rrrrrrrrrrrrrrrrrrrrrrrr\n");//dddddddddddddddddddddddddddddd

    return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  panic("Not implemented");
}

#endif
