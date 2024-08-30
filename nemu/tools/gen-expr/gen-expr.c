/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// 缓冲区大小设置
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // 比 buf 稍大一些
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

// 生成随机数字
static void gen_num() {
    int num = rand() % 100;
    char num_str[12];
    sprintf(num_str, "%d", num);
    strcat(buf, num_str);
}

// 生成随机运算符
static void gen_rand_op() {
    int op = rand() % 3; // 只使用 +, *, /
    if (op == 0) strcat(buf, " + ");
    else if (op == 1) strcat(buf, " * ");
    else strcat(buf, " / ");
}

// 随机插入空格
static void insert_random_spaces() {
    char temp_buf[65536] = {};
    int len = strlen(buf);
    int i = 0;
    int j = 0;
    
    while (i < len) {
        temp_buf[j++] = buf[i]; // 复制当前字符
        
        if (buf[i] == ' ' || buf[i] == '+' || buf[i] == '*' || buf[i] == '/') {
            // 随机决定是否插入额外的空格
            if (rand() % 2 == 0) {
                temp_buf[j++] = ' ';
            }
        }
        i++;
    }
    
    temp_buf[j] = '\0'; // 终结字符串
    strcpy(buf, temp_buf);
}

// 生成随机表达式
static void gen_rand_expr() {
    buf[0] = '\0'; // 清空 buf

    // 生成第一个数字
    gen_num();

    // 随机生成1到3个操作符的表达式
    int op_count = rand() % 3 + 1;

    for (int i = 0; i < op_count; i++) {
        gen_rand_op();

        // 如果是除法，确保除数不为0
        if (strstr(buf, " / ") != NULL) {
            int num;
            do {
                num = rand() % 100;
            } while (num == 0);
            char num_str[12];
            sprintf(num_str, "%d", num);
            strcat(buf, num_str);
        } else {
            // 生成下一个随机数
            gen_num();
        }
    }

    // 随机插入空格
    insert_random_spaces();
}

int main(int argc, char *argv[]) {
    int seed = time(0);
    srand(seed);
    int loop = 1;
    if (argc > 1) {
        sscanf(argv[1], "%d", &loop);
    }
    int i;
    for (i = 0; i < loop; i++) {
        gen_rand_expr();  // 生成随机表达式

        sprintf(code_buf, code_format, buf);

        FILE *fp = fopen("/tmp/.code.c", "w");
        assert(fp != NULL);
        fputs(code_buf, fp);
        fclose(fp);

        int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
        if (ret != 0) continue;

        fp = popen("/tmp/.expr", "r");
        assert(fp != NULL);

        unsigned result;
        ret = fscanf(fp, "%u", &result);
        pclose(fp);

        // 输出结果和对应的表达式
        printf("%u %s\n", result, buf);
    }
    return 0;
}

