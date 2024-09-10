#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
    "#include <stdio.h>\n"
    "int main() { "
    "  unsigned result = %s; "
    "  printf(\"%%u\", result); "
    "  return 0; "
    "}";

// Generate a random number and ensure it's not zero if required
static void gen_num(char *dest) {
    char str[32];
    int num;
    num = rand() % 99; // 生成0到98之间的随机数
    sprintf(str, "%d", num);
    strcat(dest, str);
}

// Generate a random operator
static void gen_rand_op(char *dest) {
    char op;
    switch (rand() % 4) {
    case 0:
        op = '+';
        break;
    case 1:
        op = '-';
        break;
    case 2:
        op = '*';
        break;
    case 3:
        op = '/';
        break;
    default:
        return; // Fallback, should not happen
    }

    char str[2];
    str[0] = op;
    str[1] = '\0';
    strcat(dest, str);
}

// Function to evaluate if an expression equals zero using the same logic as main
int is_expr_zero(char *expr) {
    sprintf(code_buf, code_format, expr);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) {
        return 1; // Compilation error, assume the expression is invalid (like division by zero)
    }

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    if (fscanf(fp, "%d", &result) != 1) {
        // 处理错误，例如返回一个错误码或者打印错误信息
        
        result = 0; // 或者其他合适的错误处理
    }
    
    pclose(fp);
    
    printf("%d",result);
    return result;
}

// Generate a random expression, ensuring no division by zero
static void gen_rand_expr(char *dest) {
    int choose = rand() % 3;

    if (strlen(dest) > 20) {
        choose = 0; // Limit the length of the expression
    }

    switch (choose) {
    case 0: {
        // Simple expression num
        gen_num(dest); 
        break;
    }
    case 1:
        strcat(dest, "(");
        gen_rand_expr(dest);
        strcat(dest, ")");
        break;
    default:
        gen_rand_expr(dest);
        gen_rand_op(dest);
        if (dest[strlen(dest) - 1] == '/') {
            // Ensure the expression after '/' does not evaluate to zero
            char temp_expr[65536];
            do {
                temp_expr[0] = '\0'; // Reset temp_expr buffer
                gen_rand_expr(temp_expr); // Generate the expression after '/'
            } while (!is_expr_zero(temp_expr));

            strcat(dest, temp_expr); // Append valid expression back to buf
        } else {
            gen_rand_expr(dest); // Recursively generate the next part of the expression
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
        buf[0] = '\0'; // Reset buffer
        gen_rand_expr(buf);

        sprintf(code_buf, code_format, buf);

        FILE *fp = fopen("/tmp/.code.c", "w");
        assert(fp != NULL);
        fputs(code_buf, fp);
        fclose(fp);

        int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
        if (ret != 0) continue;

        fp = popen("/tmp/.expr", "r");
        assert(fp != NULL);

        int result;
        if (fscanf(fp, "%d", &result) != 1) {
            // 处理错误，例如返回一个默认值
            result = -1; // 或者其他错误处理
        }
        pclose(fp);

        printf("%u %s\n", result, buf);
    }
    return 0;
}
