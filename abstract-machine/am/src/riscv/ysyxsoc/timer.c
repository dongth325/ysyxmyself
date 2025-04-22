#include <am.h>
//#define DEVICE_BASE 0xa0000000//暂时不知道这个地址是多少
//#define NPC_RTC_ADDR        (DEVICE_BASE + 0x0000048)//暂时不知道这个地址是多少   //soc中的client，存疑
#define CLINT_BASE 0x02000000
#define CLINT_MTIME_LOW_OFFSET 0x8   // mtime低32位的偏移量
#define CLINT_MTIME_HIGH_OFFSET 0xC  // mtime高32位的偏移量 

// 时钟频率转换因子 - 假设时钟频率为1GHz，需要除以1000转换为微秒
#define CLOCK_TO_US_FACTOR 1000//soc中定义的编译选项 在npc/makefile最后
static inline uint32_t inl(uintptr_t addr) { return *(volatile uint32_t *)addr; }
void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  // uint32_t high=inl(NPC_RTC_ADDR+4);
  //uint32_t low=inl(NPC_RTC_ADDR);
  //uptime->us = (uint64_t)low+(((uint64_t)high)<<32) ;
    uint32_t low = inl(CLINT_BASE + CLINT_MTIME_LOW_OFFSET);
  uint32_t high = inl(CLINT_BASE + CLINT_MTIME_HIGH_OFFSET);
  //uptime->us = (uint64_t)low + (((uint64_t)high) << 32);
    uint64_t cycles = (uint64_t)low + (((uint64_t)high) << 32);
  
 
  uptime->us = cycles / CLOCK_TO_US_FACTOR;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
