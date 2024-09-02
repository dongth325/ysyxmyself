#ifndef EXPR_H
#define EXPR_H

#include <stdbool.h>

// 假设 word_t 是在你的代码中定义的一个类型
typedef unsigned int word_t;  // 这里假设 word_t 是一个无符号整数类型

// 函数声明
word_t expr(char *e, bool *success);

#endif // EXPR_H
