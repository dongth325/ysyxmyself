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

#include <common.h>
#include "./monitor/sdb/sdb.h"
void process_expressions() {
   FILE *fp = fopen("/home/dongtaiheng/desktopp/ffuck/ysyx-workbench/nemu/tools/gen-expr/input", "r");

    if (fp == NULL) {
        perror("Failed to open input file");
        return;
    }
     int i=1;
     int jisuan;
     bool success;
    char line[256]; // 假设每行表达式不超过255个字符
    while (fgets(line, sizeof(line), fp)) {
        // 移除换行符（如果有）
        
        i++;
        line[strcspn(line, "\n")] = 0;

        // 假设每行是 "result expression" 的格式，我们可以打印并处理
        int result;
        char expression[256];
        if (sscanf(line, "%d %[^\n]", &result, expression) == 2) {
            // 打印结果和表达式
            printf("Result: %d, Expression: %s  nubline:%d\n", result, expression,i);
                  jisuan=expr(expression,&success);
                  if(success==false) assert(0);
                  if(jisuan!=result) assert(0);
                  else{printf("jisuan = %d  result = %d\n",jisuan,result);
                  printf("\n");
                  printf("\n");
                  printf("\n");
                  }
            // 在这里可以添加对表达式的进一步处理
        } else {
            printf("Failed to parse line: %s\n  nubline: %d", line,i);
        }
    }

    fclose(fp); // 关闭文件
}
void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
process_expressions();
  /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}
