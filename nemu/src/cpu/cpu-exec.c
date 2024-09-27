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

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include "../monitor/sdb/sdb.h"//ddddddddddddddddddddddddddddddddddddddddddd
#include "../utils/iringbuf.h"

RingBuffer rb;

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void device_update();

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
  //Log("Current cpu.pc 11111111= " FMT_WORD "\n", cpu.pc);//ddddddddddddddddddddddddddddddddddddddd
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); 
  //Log("Current cpu.pc 22222222= " FMT_WORD "\n", cpu.pc);//dddddddddddddddddddddddddddddddddddddddddd
}
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); 
  //Log("Current cpu.pc 333333333= " FMT_WORD "\n", cpu.pc);//dddddddddddddddddddddddddddddddddddddddddddddddddd

  }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
//Log("Current cpu.pc 4444444444= " FMT_WORD "\n", cpu.pc);//dddddddddddddddddddddddddddddddddddddddddddd

//#ifdef CONFIG_WATCHPOINT//ddddddddddddddddddddd
//Log("1111111111111111111");//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
  check_watchpoints();//dddddddddddddddddddddddddddddd
//#endif //dddddddddddddddddddddddddddddddddd
}

static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  //Log("Current cpu.pc -2-2-2-2-2-2-2-2-2-2-2= " FMT_WORD "\n", cpu.pc);//dddddddddddddddddddddddddddddddddddddddddd
  isa_exec_once(s);
  cpu.pc = s->dnpc;//在这里更新了cpu.pc地址
  //Log("Current cpu.pc -1-1-1-1-1-1-1-1-1-1-1= " FMT_WORD "\n", cpu.pc);//dddddddddddddddddddddddddddddddddddddddddd
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  for (i = ilen - 1; i >= 0; i --) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

#ifndef CONFIG_ISA_loongarch32r
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
#else
  p[0] = '\0'; // the upstream llvm does not support loongarch32r
#endif
#endif
}

static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  isa_reg_display();
  statistic();
   // 当断言失败时，打印最近的指令踪迹
   printf("Assertion failed! Printing recent instruction trace:\n");

  // 调用 get_trace 打印指令踪迹
  get_trace(&rb);  // 假设环形缓冲区是全局的 rb 变量
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

 case NEMU_STOP://ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
        // 处理 NEMU_STOP 状态，退出执行或进行其他处理
        printf("Execution stopped. Current pc = " FMT_WORD "\n", cpu.pc);
        return;  // 直接退出函数，停止执行ddddddddddddddddddddddddddddddddddddddddddddddddddddd





    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);

          // 当程序异常终止时，打印最近的指令踪迹
        printf("Assertion failed! Printing recent instruction trace:\n");

  // 调用 get_trace 打印指令踪迹
  //get_trace(&rb);  // 假设环形缓冲区是全局的 rb 变量


      // fall through
    case NEMU_QUIT: statistic();
  }
}
