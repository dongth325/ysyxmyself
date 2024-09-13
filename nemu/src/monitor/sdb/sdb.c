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

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include "memory/paddr.h" //ok
#include "watchpoint.h"   //ddd

static int is_batch_mode = false;

void init_regex();   // dddddd
void init_wp_pool(); // ddddd
void check_watchpoints() {
    for (int i = 0; i < NR_WP; i++) {
        // 如果当前监视点被使用（flag 为 true）
        if (wp_pool[i].flag) {
            bool success = true;

            // 计算表达式的当前值
            int current_value = expr(wp_pool[i].expr, &success);
            //Log("Watchpoint %d evaluated expression -6-6-6-6-6-6result: %d\n", wp_pool[i].NO, current_value);//ddddddddddddddddddddddddddddddd


            if (!success) {
                assert(0);  // 如果表达式求值失败，触发断言
            }
              //Log("old value-7-7-7-7-7-7-7-7-7=: %d\n",wp_pool[i].old_value);

            // 如果新值与旧值不同，说明监视点被触发
            if (current_value != wp_pool[i].old_value) {
                printf("Watchpoint %d triggered: %s\n", wp_pool[i].NO, wp_pool[i].expr);
                printf("Old value = %d, New value = %d\n", wp_pool[i].old_value, current_value);

                // 更新旧值为新值
                wp_pool[i].old_value = current_value;

                // 设置 NEMU 状态为停止
                nemu_state.state = NEMU_STOP;
            }
        }
    }
}



void sdb_watchpoint_display()
{

    bool flag = true;
    for (int i = 0; i < NR_WP; i++)
    {
        if (wp_pool[i].flag)
        {
            printf("Watchpoint.No: %d, expr = \"%s\", old_value = %d, new_value = %d\n",
                   wp_pool[i].NO, wp_pool[i].expr, wp_pool[i].old_value, wp_pool[i].new_value);

            flag = false;
        }
    }
    if (flag)
        printf("No watchpoint now.\n");
}
void delete_watchpoint(int no)
{
    for (int i = 0; i < NR_WP; i++)
        if (wp_pool[i].NO == no)
        {
            free_wp(&wp_pool[i]);
            return;
        }
}

void create_watchpoint(char *args)
{
    WP *p = new_wp();
    strcpy(p->expr, args);
    bool success = false;
    int tmp = expr(p->expr, &success);
    if (success)
    {
        p->old_value = tmp;
        printf("Create watchpoint No.%d success.\n", p->NO);
    }
    else
    {
        printf("创建watchpoint的时候expr求值出现问题\n");
    }
}

static char *rl_gets()
{ //
    static char *line_read = NULL;

    if (line_read)
    {                    // 是否已经指向了某个内存位置
        free(line_read); // 释放内存
        line_read = NULL;
    }

    line_read = readline("(nemu) "); // 用于从标准输入读取一行文本。它会显示一个提示符（在这里是 "(nemu) "），然后等待用户输入

    if (line_read && *line_read)
    { // 这个条件判断检查 line_read 是否为非 NULL，并且输入的第一字符是否为非空字符（即用户输入了某些内容，而不仅仅是按下回车）。
        // 如果条件为真，add_history(line_read) 会将该行输入添加到 Readline 的历史记录中。这样，用户可以使用箭头键来回滚查看之前输入的命令。
        add_history(line_read);
    }

    return line_read;
}

static int cmd_c(char *args)
{
    cpu_exec(-1);
    return 0;
}
// CMD_INFO
static int cmd_info(char *args)
{
    if (args == NULL)
        printf("No args.\n");
    else if (strcmp(args, "r") == 0)
        isa_reg_display();
    else if (strcmp(args, "w") == 0)
        sdb_watchpoint_display();
    return 0;
}

static int cmd_d(char *args)
{
    if (args == NULL)
        printf("No args.\n");
    else
    {
        delete_watchpoint(atoi(args));
    }
    return 0;
}

// CMD_Q quit the NEMU
static int cmd_q(char *args)
{
    nemu_state.state = NEMU_QUIT;
    return -1;
}

// CMD_X scan virtual memory
static int cmd_x(char *args)
{                                       // dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
    char *n = strtok(args, " ");        // 函数将 args 字符串按空格分割，提取两个部分                        表示要读取的内存块数量
    char *baseaddr = strtok(NULL, " "); // 内存读取的起始地址
    int len = 0;
    paddr_t addr = 0;
    sscanf(n, "%d", &len);         // 转换为整数
    sscanf(baseaddr, "%x", &addr); // 转换为十六进制整数
    for (int i = 0; i < len; i++)
    {
        printf("%x\n", paddr_read(addr, 4)); // addr len用于从指定的物理地址 addr 读取 4 字节的数据。  十六进制
        addr = addr + 4;
    }
    return 0;
}

static int cmd_p(char *args)
{
    bool seccess = true;
    int val;
    if (args == NULL)
        return 0;
    val = expr(args, &seccess);
    if (seccess == false)
    {
        printf("make_token false\n");
        return 0;
    }

    if (val >= 0x80000000)
        printf("%#x\n", val); // 可能是一个负数
    else
        printf("%u\n", val); // 无符号十进制
    return 0;
}

static int cmd_w(char *args)
{
    create_watchpoint(args);
    return 0;
}

static int cmd_si(char *args)
{ // ddddddddddddddddddddddddddddddddddddd
    int step = 0;
    if (args == NULL)
        step = 1;
    else
        sscanf(args, "%d", &step); // 读入 Step
    cpu_exec(step);
    return 0;
}
static int cmd_help(char *args);

static struct
{
    const char *name;
    const char *description;
    int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},
    {"si", "run si program", cmd_si},
    {"info", "Get register info", cmd_info},
    {"x", "Scan the virtual memory", cmd_x},
    {"p", "run expr", cmd_p},
    {"d", "delete watchpoint by NO", cmd_d},
    {"w", "create watchpoint with expr", cmd_w},
    /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args)
{
    /* extract the first argument */
    char *arg = strtok(NULL, " ");
    int i;

    if (arg == NULL)
    {
        /* no argument given */
        for (i = 0; i < NR_CMD; i++)
        {
            printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        }
    }
    else
    {
        for (i = 0; i < NR_CMD; i++)
        {
            if (strcmp(arg, cmd_table[i].name) == 0)
            {
                printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
                return 0;
            }
        }
        printf("Unknown command '%s'\n", arg);
    }
    return 0;
}

void sdb_set_batch_mode()
{
    is_batch_mode = true;
}

void sdb_mainloop()
{
    if (is_batch_mode)
    {
        cmd_c(NULL);
        return;
    }

    for (char *str; (str = rl_gets()) != NULL;)
    {
        char *str_end = str + strlen(str);

        /* extract the first token as the command */
        char *cmd = strtok(str, " ");
        if (cmd == NULL)
        {
            continue;
        }

        /* treat the remaining string as the arguments,
         * which may need further parsing
         */
        char *args = cmd + strlen(cmd) + 1;
        if (args >= str_end)
        {
            args = NULL;
        }

#ifdef CONFIG_DEVICE
        extern void sdl_clear_event_queue();
        sdl_clear_event_queue();
#endif

        int i;
        for (i = 0; i < NR_CMD; i++)
        {
            if (strcmp(cmd, cmd_table[i].name) == 0)
            {
                if (cmd_table[i].handler(args) < 0)
                {
                    return;
                }
                break;
            }
        }

        if (i == NR_CMD)
        {
            printf("Unknown command '%s'\n", cmd);
        }
    }
}

void init_sdb()
{
    /* Compile the regular expressions. */
    init_regex();

    /* Initialize the watchpoint pool. */
    init_wp_pool();
}
