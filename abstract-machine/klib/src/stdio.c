#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  char buffer[256];
  va_list ap;
  va_start(ap, fmt);
  int len = vsprintf(buffer, fmt, ap);
  va_end(ap);
  
  // 逐字符输出到终端
  for (int i = 0; i < len; i++) {
    putch(buffer[i]);
  }
  
  return len;  // 返回输出的字符数
}
static int itoa(int n, char *s) {
  int i = 0, sign = n;
  if (sign < 0) n = -n;
  
  // 反向生成数字字符
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  
  if (sign < 0) s[i++] = '-';
  s[i] = '\0';

  // 反转字符串
  for (int j = 0; j < i / 2; j++) {
    char temp = s[j];
    s[j] = s[i - j - 1];
    s[i - j - 1] = temp;
  }
  
  return i;  // 返回字符串长度
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  char *buffer = out;
  
  while (*fmt) {
    if (*fmt == '%') {
      fmt++;
      if (*fmt == 'd') {  // 处理 %d
        int value = va_arg(ap, int);
        char temp[32];
        int len = itoa(value, temp);
        for (int i = 0; i < len; i++) *buffer++ = temp[i];
      } 
      else if (*fmt == 's') {  // 处理 %s
        char *str = va_arg(ap, char*);
        while (*str) *buffer++ = *str++;
      }
    } 
    else {
      *buffer++ = *fmt;
    }
    fmt++;
  }
  
  *buffer = '\0';
  return buffer - out;  // 返回写入的字符数
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int result = vsprintf(out, fmt, ap);
  va_end(ap);
  return result;
}
int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif