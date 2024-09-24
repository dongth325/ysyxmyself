#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  char *ptr = out;  // 指向输出缓冲区的指针
  const char *p = fmt;  // 指向格式字符串的指针

  while (*p) {
    if (*p == '%') {
      p++;  // 跳过 '%' 字符
      if (*p == 's') {
        // 处理 %s
        const char *str = va_arg(ap, const char *);
        while (*str) {
          *ptr++ = *str++;  // 复制字符串
        }
      } else if (*p == 'd') {
        // 处理 %d
        int num = va_arg(ap, int);
        char buf[20];  // 用于存储数字的字符缓冲区
        sprintf(buf, "%d", num);

        const char *num_str = buf;
        while (*num_str) {
          *ptr++ = *num_str++;  // 复制数字字符串
        }
      }
    } else {
      // 普通字符直接复制
      *ptr++ = *p;
    }
    p++;
  }

  *ptr = '\0';  // 确保输出以 '\0' 结束
  return ptr - out;  // 返回写入的字符数
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);  // 初始化 va_list
  int len = vsprintf(out, fmt, ap);  // 调用 vsprintf 实现核心逻辑
  va_end(ap);  // 清理 va_list
  return len;  // 返回结果长度
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
