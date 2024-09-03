#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

char *buf_ptr = buf;
int char_num;

// 设置最大长度
#define MAX_LENGTH 1000  
#define MAX_DEPTH 10  // 最大递归深度

// 生成随机数
uint32_t choose(uint32_t n)
{
    int lower = 0;
    int upper = n;
    uint32_t randomInRange = (abs(rand()) % (upper - lower)) + lower;
    return randomInRange;
}

// 获取数字的位数
int getDigitCount(uint32_t number) {
    if (number == 0) {
        return 1;
    }
    return (int)log10(number) + 1;
}

// 生成随机数字
void gen_num()
{
    if (char_num >= MAX_LENGTH) return;  // 控制总长度

    int lower = 1;
    int upper = 100;
    uint32_t randomNumber = (abs(rand()) % (upper - lower)+1) + lower;
    sprintf(buf_ptr, "%d", randomNumber);
    buf_ptr += getDigitCount(randomNumber);
    char_num += getDigitCount(randomNumber);
}

// 生成单个字符
void gen(const char c)
{
    if (char_num >= MAX_LENGTH) return;  // 控制总长度

    *(buf_ptr++) = c;
    char_num += 1;
}

// 生成随机操作符
void gen_rand_op()
{
    if (char_num >= MAX_LENGTH) return;  // 控制总长度

    switch (choose(4)) {
        case 0: *(buf_ptr++) = '+'; break;
        case 1: *(buf_ptr++) = '-'; break;
        case 2: *(buf_ptr++) = '*'; break;
        case 3: *(buf_ptr++) = '/'; break;
    }
    char_num += 1;
}

// 递归生成随机表达式，增加深度控制
void gen_rand_expr(int depth) 
{
    if (char_num >= MAX_LENGTH || depth >= MAX_DEPTH) {
        gen_num();  // 当达到最大长度或深度时，生成一个数字终止递归
        return;
    }

    switch (choose(4)) {
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
        default: 
            gen_rand_expr(depth + 1); 
            gen_rand_op(); 
            gen_rand_expr(depth + 1); 
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
        if (char_num >= MAX_LENGTH) {
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
