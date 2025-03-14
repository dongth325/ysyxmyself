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
  
   /* 将堆区起始地址放在SRAM开始位置 */
  . = 0x0f000000;
  _heap_start = ALIGN(0x1000);
  
  /* 将栈区放入SRAM末尾 */
  . = 0x0f001000;    /* SRAM末尾减去4KB栈空间 */
  _stack_top = .;
  . = 0x0f001fff;    /* 8KB SRAM结束地址 */
  _stack_pointer = ALIGN(4);  /* 只回退到0x0f001ffc 要不然超过sram的8kb了 栈区必须保证四字节对齐*/
  
  /* 堆区结束地址设置为栈区起始地址 */
  _heap_end = _stack_top;
}