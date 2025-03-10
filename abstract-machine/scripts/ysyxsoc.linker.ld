ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset;
  
  /* 代码段 */
  .text : {
    *(entry)
    *(.text*)
  } : text
  etext = .;
  _etext = .;
  
  /* 只读数据段 */
  .rodata : {
    *(.rodata*)
  }
  
  /* 已初始化的数据段 */
  .data : {
    *(.data)
  } : data
  edata = .;
  _data = .;
  
  /* 未初始化的数据段 */
  .bss : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  }
  
  /* 将栈区放入SRAM低地址端 */
  . = 0x0f010000;
  _stack_top = ALIGN(0x1000);
  . = _stack_top + 0x8000;
  _stack_pointer = .;
  
  /* 标记程序加载结束位置 */
  end = .;
  _end = .;
  
  /* 将堆区起始地址放在SRAM高地址端 */
  . = 0x0ffe0000;
  _heap_start = ALIGN(0x1000);
}