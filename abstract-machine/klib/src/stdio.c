#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>


#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static char sprint_buf[1024];
/*可变函数在内部实现的过程中是从右向左压入堆栈，从而保证了可变参数的第一个参数始终位于栈顶*/
int printf(const char *fmt, ...)//可以有一个或多个固定参数
{
  va_list args; //用于存放参数列表的数据结构
  int n;
  /*根据最后一个fmt来初始化参数列表，至于为什么是最后一个参数，是与va_start有关。*/
  va_start(args, fmt);
  n = vsprintf(sprint_buf, fmt, args);
  va_end(args);//执行清理参数列表的工作
  putstr(sprint_buf);
  return n;
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

// ... existing code ...

int vsprintf(char *out, const char *fmt, va_list ap) {
  char *buffer = out;
  
  while (*fmt) {
    if (*fmt == '%') {
      fmt++;
      
      // 处理格式标志
      int zero_pad = 0;
      int width = 0;
      
      // 检查0填充
      if (*fmt == '0') {
        zero_pad = 1;
        fmt++;
      }
      
      // 解析宽度
      while (*fmt >= '0' && *fmt <= '9') {
        width = width * 10 + (*fmt - '0');
        fmt++;
      }
      
      if (*fmt == 'd') {  // 处理 %d
        int value = va_arg(ap, int);
        char temp[32];
        int len = itoa(value, temp);
        
        // 处理宽度和填充
        if (width > len && zero_pad) {
          for (int i = 0; i < width - len; i++) *buffer++ = '0';
        }
        
        for (int i = 0; i < len; i++) *buffer++ = temp[i];
      } 
      else if (*fmt == 'x' || *fmt == 'X') {  // 处理 %x 和 %X
        unsigned int value = va_arg(ap, unsigned int);
        char temp[32];
        int i = 0;
        
        // 特殊处理0的情况
        if (value == 0) {
          temp[i++] = '0';
        } else {
          // 转换为16进制
          while (value) {
            int digit = value & 0xf;
            temp[i++] = digit < 10 ? digit + '0' : digit - 10 + (*fmt == 'x' ? 'a' : 'A');
            value >>= 4;
          }
        }
        
        // 反转字符串
        for (int j = 0; j < i / 2; j++) {
          char t = temp[j];
          temp[j] = temp[i - j - 1];
          temp[i - j - 1] = t;
        }
        
        // 处理宽度和零填充
        if (width > i && zero_pad) {
          for (int j = 0; j < width - i; j++) *buffer++ = '0';
        }
        
        // 复制到输出缓冲区
        for (int j = 0; j < i; j++) *buffer++ = temp[j];
      }
      else if (*fmt == 's') {  // 处理 %s
        char *str = va_arg(ap, char*);
        while (*str) *buffer++ = *str++;
      }
      else if (*fmt == 'c') {  // 处理 %c
        char c = (char)va_arg(ap, int);
        *buffer++ = c;
      }
      else if (*fmt == '%') {  // 处理 %%
        *buffer++ = '%';
      }
      else {
        // 未知格式，原样输出
        *buffer++ = '%';
        *buffer++ = *fmt;
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

// ... existing code ...

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