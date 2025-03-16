ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
  mrom : ORIGIN = 0x20000000, LENGTH = 4K  /* mrom 4KB */
  sram : ORIGIN = 0x0f000000, LENGTH = 8K  /* SRAM 8KB */
}



SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset; /*在ysyxsoc.mk中定义了pmem start地址和mrom一样，在此直接用mrom起始地址，都一样*/
  
  
  /* 代码段放在MROM */
  . = ORIGIN(mrom);
  .text : {
    *(entry)
    *(.text*)
  } >mrom : text
  
  etext = .;
  _etext = .;
  


  /* 只读数据段放在MROM */
  .rodata : {
   . = ALIGN(4);
    *(.rodata*)
    *(.srodata*)  /* 添加.srodata*段  这里原linker文件并未设置srodata，可能是新定义了两个memory和vma，lma导致原本的默认配置被打破 */
    *(.sdata.rodata*)  /* 添加其他可能的只读数据段  这里原linker文件并未设置srodata，可能是新定义了两个memory和vma，lma导致原本的默认配置被打破*/
  } >mrom : text
  
  . = ALIGN(4);

  /* 记录数据段在MROM中的位置 */
  _data_lma = .;
  
  /* 切换到SRAM */
  . = ORIGIN(sram);

  /* 数据段 - 需要从MROM复制到SRAM */
  .data : AT(_data_lma) {  /* 关键修改：显式指定LMA */
    . = ALIGN(8);
    _data_vma_start = .;
    *(.data)
    *(.data.*)
    *(.sdata)      /* 添加小数据段 */
    *(.sdata.*)    /* 添加小数据段 */
    . = ALIGN(8);
    _data_vma_end = .;
  } >sram : data
  
  /* BSS段 - 只需在SRAM中分配空间并清零 */

  .bss (NOLOAD) : {
    . = ALIGN(4);
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
    _bss_end = .;

 } >sram
  
  /* 记录数据和BSS段结束后的位置 */
  _prog_end = .;

 
  /* 堆区起始地址 */
  _heap_start = ALIGN(0x1000);
  
  /* 栈区大小可调整 - 这里设为2KB */
  . = ORIGIN(sram) + LENGTH(sram) - 2K;  /* 留出2KB给栈 */
  _stack_top = .;
  
  /* SRAM结束地址 */
  . = ORIGIN(sram) + LENGTH(sram);
  _stack_pointer = ALIGN(4) - 4;  /* 四字节对齐并留出一个字 */
  
  /* 堆区结束地址设置为栈区起始地址 */
  _heap_end = _stack_top;
  
  /* 添加检查，确保程序不会溢出 */
  ASSERT(_prog_end <= _heap_start, "Error: 程序数据段太大，超出了对齐边界！")
  ASSERT(_heap_start < _stack_top, "Error: 没有足够空间分配堆区！")
}