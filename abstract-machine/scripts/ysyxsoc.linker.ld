ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD;rodata PT_LOAD; }

MEMORY {
  flash : ORIGIN = 0x30000000, LENGTH = 16M  /* Flash 16MB */
  mrom : ORIGIN = 0x20000000, LENGTH = 4K  /* mrom 4KB */
  sram : ORIGIN = 0x0f000000, LENGTH = 8K  /* SRAM 8KB */
}



SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset; /*在ysyxsoc.mk中定义了pmem start地址和rom一样，在此直接用rom起始地址，在ysyxsoc.mk中定义，修改rom起始地址需要先修改*/
  
  

  . = ORIGIN(flash);


  _text_lma = ORIGIN(flash) + 4;

  . = ORIGIN(sram);

  .text : AT(_text_lma) {   /*要把memtest全部加再到sram中，这里是包括trm init等在内的所有代码部分，不能全拷贝，只能拷贝main函数，因为前面的已经执行过了*/
      _text_vma_start = ABSOLUTE(ORIGIN(sram));
    *(entry)
    *(.text*)
      . = ALIGN(4);
     _text_vma_end = ABSOLUTE(ORIGIN(sram) + SIZEOF(.text));
  } >flash : text
  

  _execute_main_lma = _text_lma + SIZEOF(.text) + 4;
 

  .text.execute_main : AT(_execute_main_lma) {
     _execute_main_vma_start = ABSOLUTE(_text_vma_end + 4);
    *(.text.execute_main)
    . = ALIGN(4);
    _execute_main_vma_end = ABSOLUTE(_execute_main_vma_start + SIZEOF(.text.execute_main));
  } >flash : text
  

  etext = .;
  _etext = .;
  
 _rodata_lma = _execute_main_lma  + SIZEOF(.text.execute_main) + 4;

  /* 只读数据段放在MROM */
  .rodata : AT(_rodata_lma) {
   . = ALIGN(4);
    _rodata_vma_start = ABSOLUTE(_execute_main_vma_end + 4); /*防止重叠，虽然一个end和start即使地址一样也不是重叠*/
    *(.rodata*)
    *(.srodata*)  /* 添加.srodata*段  这里原linker文件并未设置srodata，可能是新定义了两个memory和vma，lma导致原本的默认配置被打破 */
    *(.sdata.rodata*)  /* 添加其他可能的只读数据段  这里原linker文件并未设置srodata，可能是新定义了两个memory和vma，lma导致原本的默认配置被打破*/
     . = ALIGN(4);
     _rodata_vma_end = ABSOLUTE(_rodata_vma_start + SIZEOF(.rodata));
  } >sram : rodata
  
  . = ALIGN(4);


  _data_lma = _rodata_lma + SIZEOF(.rodata) + 4;
  



  
  .data : AT(_data_lma) {  /* 关键修改：显式指定LMA */
    . = ALIGN(8);
      _data_vma_start = ABSOLUTE(_rodata_vma_end + 4);
    *(.data)
    *(.data.*)
    *(.sdata)      /* 添加小数据段 */
    *(.sdata.*)    /* 添加小数据段 */
    . = ALIGN(8);
     _data_vma_end = ABSOLUTE(_data_vma_start + SIZEOF(.data));
  } >sram : data
  
  /* BSS段 - 只需在SRAM中分配空间并清零 */

  .bss (NOLOAD) : {
    . = ALIGN(4);
   _bss_start = ABSOLUTE(_data_vma_end + 4);
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
   _bss_end = ABSOLUTE(_bss_start + SIZEOF(.bss));

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