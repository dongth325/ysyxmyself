#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// Calculate the length of a string
size_t strlen(const char *s) {
  const char *p = s;
  while (*p) ++p;
  return p - s;
}

// Copy a string from src to dst
char *strcpy(char *dst, const char *src) {
  char *ret = dst;
  while ((*dst++ = *src++));
  return ret;
}

// Copy up to n characters from src to dst
char *strncpy(char *dst, const char *src, size_t n) {
  char *ret = dst;
  while (n && (*dst++ = *src++)) n--;
  if (n) while (--n) *dst++ = '\0';
  return ret;
}

// Concatenate src to the end of dst
char *strcat(char *dst, const char *src) {
  char *ret = dst;
  while (*dst) dst++;
  while ((*dst++ = *src++));
  return ret;
}

// Compare two strings
int strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) s1++, s2++;
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}

// Compare up to n characters of two strings
int strncmp(const char *s1, const char *s2, size_t n) {
  while (n && *s1 && (*s1 == *s2)) n--, s1++, s2++;
  return n ? *(unsigned char *)s1 - *(unsigned char *)s2 : 0;
}

// Set n bytes of s to the specified character c
void *memset(void *s, int c, size_t n) {
  unsigned char *p = s;
  while (n--) *p++ = (unsigned char)c;
  return s;
}

// Move n bytes from src to dst (handles overlap)
void *memmove(void *dst, const void *src, size_t n) {
  char *d = dst;
  const char *s = src;
  if (d < s) {
    while (n--) *d++ = *s++;
  } else {
    d += n;
    s += n;
    while (n--) *(--d) = *(--s);
  }
  return dst;
}

// Copy n bytes from in to out
void *memcpy(void *out, const void *in, size_t n) {
  char *d = out;
  const char *s = in;
  while (n--) *d++ = *s++;
  return out;
}

// Compare n bytes of two memory areas
int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *p1 = s1;
  const unsigned char *p2 = s2;
  while (n--) {
    if (*p1 != *p2) return *p1 - *p2;
    p1++;
    p2++;
  }
  return 0;
}

#endif
