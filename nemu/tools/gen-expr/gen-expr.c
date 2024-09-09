
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <limits.h>  

static char buf[200] = {};  
static char code_buf[512] = {}; 
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

char *buf_ptr = buf;
int char_num;

#define MAX_LENGTH 200  
#define MAX_DEPTH 7  

uint32_t choose(uint32_t n) {
    return rand() % n;
}

int getDigitCount(uint32_t number) {
    if (number == 0) {
        return 1;
    }
    return (int)log10(number) + 1;
}


void gen_num() {
    if (char_num >= MAX_LENGTH) return; 

    int lower = 1;
    int upper = 100;
    uint32_t randomNumber = (rand() % (upper - lower + 1)) + lower;  
    int len = getDigitCount(randomNumber);

    if (char_num + len >= MAX_LENGTH) return;  

    sprintf(buf_ptr, "%d", randomNumber);
    buf_ptr += len;
    char_num += len;
}

void gen(const char c) {
    if (char_num >= MAX_LENGTH - 1) return;  

    *(buf_ptr++) = c;
    char_num += 1;
}

void gen_rand_op() {
    if (char_num >= MAX_LENGTH - 1) return;  

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
    int result;

   do {
    
    saved_buf_ptr = buf_ptr;
    saved_char_num = char_num;
    
    
    gen_rand_expr(depth);  

    
    if (char_num > MAX_LENGTH) {
        buf_ptr = saved_buf_ptr;
        char_num = saved_char_num;
        continue;
    }

    
    char expr_buf[200];
    strncpy(expr_buf, saved_buf_ptr, buf_ptr - saved_buf_ptr);
    expr_buf[buf_ptr - saved_buf_ptr] = '\0';

    
    if (strlen(expr_buf) >= sizeof(expr_buf) - 64) {
        buf_ptr = saved_buf_ptr;  
        char_num = saved_char_num; 
        continue;
    }

    
    char code_buf[512];
    snprintf(code_buf, sizeof(code_buf),
             "echo '#include <stdio.h>\\nint main(){ printf(\"%%d\", %s); }' | gcc -xc - -o /tmp/.non_zero_expr && /tmp/.non_zero_expr", expr_buf);

    FILE *fp = popen(code_buf, "r");
    if (fp == NULL) {
        perror("popen failed");
        exit(1);
    }

    
    int ret = fscanf(fp, "%d", &result);
    if (ret != 1 || result == 0) {
        
        buf_ptr = saved_buf_ptr;
        char_num = saved_char_num;
        result = 0;
    }
    pclose(fp);

} while (result == 0);  

}

void gen_rand_expr(int depth) {
    if (char_num >= MAX_LENGTH - 1 || depth >= MAX_DEPTH) {
        gen_num();
        return;
    }

    switch (choose(3)) {
        case 0:
            gen_num();  // 生成数字
            break;
        case 1:
            gen('(');  // 生成括号中的表达式
            gen_rand_expr(depth + 1);
            gen(')');
            break;
        case 2:
            gen_rand_expr(depth + 1);  // 左表达式
            gen_rand_op();  // 运算符
            
            if (*(buf_ptr - 1) == '/') {
                gen_rand_non_zero_expr(depth + 1);  // 确保除数不为 0
            } else {
                gen_rand_expr(depth + 1);  // 其他运算符可以使用任意表达式
            }
            break;
        default:
            gen_num();  // 生成数字，作为默认情况
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

        gen_rand_expr(0);  // 生成随机表达式

        if (char_num >= MAX_LENGTH - 1) {
            continue;
        }

        sprintf(code_buf, code_format, buf);

        FILE *fp = fopen("/tmp/.code.c", "w");
        assert(fp != NULL);
        fputs(code_buf, fp);
        fclose(fp);

        // 编译生成的代码
        fp = popen("gcc /tmp/.code.c -o /tmp/.expr 2>&1", "r");
        assert(fp != NULL);

        char buffer[128];
        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            pclose(fp);
            continue;
        }
        pclose(fp);

        // 执行生成的可执行文件
        fp = popen("/tmp/.expr", "r");
        assert(fp != NULL);

        int result;
        int ret = fscanf(fp, "%d", &result);
        if (ret != 1) {
            pclose(fp);
            continue;
        }
        pclose(fp);

        // 限制输出值的范围，确保是合法的 int
        if (result > INT_MAX || result < INT_MIN) {
            continue;  // 跳过超出范围的值
        }

        // 将结果和表达式输出到终端或文件
        printf("%u %s\n", result, buf);  // 输出格式：<结果> <表达式>
    }
    return 0;
}