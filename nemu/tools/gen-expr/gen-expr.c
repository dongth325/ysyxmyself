#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>

static char buf[200] = {};  // 设置缓冲区大小为 200
static char code_buf[200 + 128] = {}; // a little larger than buf
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

char *buf_ptr = buf;
int char_num;

#define MAX_LENGTH 200  // 最大长度设置为 200
#define MAX_DEPTH 7  // 增加递归深度

uint32_t choose(uint32_t n)
{
    return rand() % n;
}

int getDigitCount(uint32_t number) {
    if (number == 0) {
        return 1;
    }
    return (int)log10(number) + 1;
}

void gen_num()
{
    if (char_num >= MAX_LENGTH) return;  // 控制总长度

    int lower = 1;
    int upper = 100;
    uint32_t randomNumber = (abs(rand()) % (upper - lower + 1)) + lower;
    int len = getDigitCount(randomNumber);

    if (char_num + len >= MAX_LENGTH) return;  // 确保不会超出最大长度

    sprintf(buf_ptr, "%d", randomNumber);
    buf_ptr += len;
    char_num += len;
}

void gen(const char c)
{
    if (char_num >= MAX_LENGTH - 1) return;  // 控制总长度，留出空位给'\0'

    *(buf_ptr++) = c;
    char_num += 1;
}

void gen_rand_op()
{
    if (char_num >= MAX_LENGTH - 1) return;  // 控制总长度，留出空位给'\0'

    switch (choose(4)) {
        case 0: gen('+'); break;
        case 1: gen('-'); break;
        case 2: gen('*'); break;
        case 3: gen('/'); break;
    }
}

void gen_rand_expr(int depth);

void gen_rand_non_zero_expr(int depth) {
    char *saved_buf_ptr;
    int saved_char_num;
    int result;  // 声明result变量

    do {
        saved_buf_ptr = buf_ptr;  // 保存当前指针位置
        saved_char_num = char_num;  // 保存当前长度
        gen_rand_expr(depth);  // 生成表达式

        // 如果生成的表达式长度超出限制，则恢复之前的状态
        if (char_num > MAX_LENGTH) {
            buf_ptr = saved_buf_ptr;
            char_num = saved_char_num;
            continue;  // 超出长度，继续生成新的表达式
        }

        // 判断生成的表达式是否为 0
        char expr_buf[200];  // 用来存储当前生成的表达式
        strncpy(expr_buf, saved_buf_ptr, buf_ptr - saved_buf_ptr);
        expr_buf[buf_ptr - saved_buf_ptr] = '\0';  // null-terminate

        // 先检查生成的表达式长度，确保不会超出缓冲区
        if (strlen(expr_buf) >= sizeof(expr_buf) - 64) {
            continue;  // 如果表达式太长，跳过本次循环
        }

        // 使用系统调用计算表达式的值
        char code_buf[512];  // 扩大code_buf的大小以容纳更长的命令
        snprintf(code_buf, sizeof(code_buf), 
                 "echo 'int main(){ printf(\"%%d\", %s); }' | gcc -xc - -o /tmp/.non_zero_expr && /tmp/.non_zero_expr", expr_buf);

        FILE *fp = popen(code_buf, "r");
        if (fp == NULL) {
            perror("popen failed");
            exit(1);
        }

        // 读取表达式的结果
        int ret = fscanf(fp, "%d", &result);
        if (ret != 1) {
            result = 0;  // 如果读取失败，默认处理为0
        }
        pclose(fp);

        // 如果结果为 0，就重新生成表达式
    } while (result == 0);
}



void gen_rand_expr(int depth) 
{
    if (char_num >= MAX_LENGTH - 1 || depth >= MAX_DEPTH) {
        gen_num();  // 当达到最大长度或深度时，生成一个数字终止递归
        return;
    }

    switch (choose(5)) {  // 增加表达式生成的可能性
        case 0: 
            gen_num();
            break;
        case 1: 
            gen('(');  
            gen_rand_expr(depth + 1); 
            gen(')'); 
            break;
        case 2: 
            gen_rand_expr(depth + 1); 
            gen_rand_op(); 
            gen_rand_expr(depth + 1); 
            break;
        case 3:
            gen_rand_expr(depth + 1);
            gen_rand_op();
            gen_rand_expr(depth + 1);
            break;
        default: 
            gen_rand_expr(depth + 1); 
            gen_rand_op(); 
            // 确保除号后面的表达式不为零
            if (*(buf_ptr - 1) == '/') {
                gen_rand_non_zero_expr(depth + 1);  // 使用生成非零表达式的函数
            } else {
                gen_rand_expr(depth + 1);
            }
            break;
    }
}

int main(int argc, char *argv[]) {
    int seed = time(0);
    srand(seed);
    int loop = 1;
    if (argc > 1) {
        sscanf(argv[1], "%d", &loop);
    }
    for (int i = 0; i < loop; i++) {
        memset(buf, '\0', sizeof(buf));
        buf_ptr = buf;
        char_num = 0;

        gen_rand_expr(0);  // 初始深度为 0

        // 如果生成的表达式长度超出了缓冲区，跳过该循环
        if (char_num >= MAX_LENGTH - 1) {
            continue;
        }

        sprintf(code_buf, code_format, buf);

        FILE *fp = fopen("/tmp/.code.c", "w");
        assert(fp != NULL);
        fputs(code_buf, fp);
        fclose(fp);

        fp = popen("gcc /tmp/.code.c -o /tmp/.expr 2>&1", "r");
        assert(fp != NULL);

        char buffer[128];
        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            pclose(fp);
            continue;  // 如果编译失败，跳过当前循环
        }
        pclose(fp);

        fp = popen("/tmp/.expr", "r");
        assert(fp != NULL);

        int result;
        int ret = fscanf(fp, "%d", &result);
        if (ret != 1) {
            pclose(fp);
            continue;
        }
        pclose(fp);

        printf("%u %s\n", result, buf);
    }
    return 0;
}
