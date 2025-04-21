ENTRY(_start)
PHDRS {  fsbl PT_LOAD; text PT_LOAD; data PT_LOAD;rodata PT_LOAD; }

MEMORY {
  flash : ORIGIN = 0x30000000, LENGTH = 16M  /* Flash 16MB */
  mrom : ORIGIN = 0x20000000, LENGTH = 4K  /* mrom 4KB */
  sram : ORIGIN = 0x0f000000, LENGTH = 8K  /* SRAM 8KB */
}



SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset; /*在ysyxsoc.mk中定义了pmem start地址和rom一样，在此直接用rom起始地址，在ysyxsoc.mk中定义，修改rom起始地址需要先修改*/
  
  

  . = ORIGIN(flash);


  _fsbl_lma = ORIGIN(flash);

  .fsbl : AT(_fsbl_lma) {
    . = ALIGN(4);
    _fsbl_vma_start = .;
    *(.fsbl*)
    . = ALIGN(4);
    _fsbl_vma_end = .;
  } >flash : fsbl




  _bootloader_lma = _fsbl_lma + SIZEOF(.fsbl) + 4;
  
  
  .bootloader : AT(_bootloader_lma) {
     . = ALIGN(4);
    _bootloader_vma_start = .;
    *(.bootloader*)
    . = ALIGN(4);
    _bootloader_vma_end = .;
  } >sram : text





 _text_lma = _bootloader_lma + SIZEOF(.bootloader) + 4;



  .text : AT(_text_lma) {   /*要把memtest全部加再到sram中，这里是包括trm init等在内的所有代码部分，不能全拷贝，只能拷贝main函数，因为前面的已经执行过了*/
     . = ALIGN(4);
      _text_vma_start = . ;
    *(entry)
    *(.text*)

   PROVIDE(_execute_main = execute_main);
     

      . = ALIGN(4);
     _text_vma_end = ABSOLUTE(_text_vma_start + SIZEOF(.text));
  } >sram : text
  


  

 










  etext = .;
  _etext = .;
  


 _rodata_lma = _text_lma + SIZEOF(.text);

  /* 只读数据段放在MROM */
  .rodata : AT(_rodata_lma) {
   . = ALIGN(4);
    _rodata_vma_start = . ; /*防止重叠，虽然一个end和start即使地址一样也不是重叠*/
    *(.rodata*)
    *(.srodata*)  /* 添加.srodata*段  这里原linker文件并未设置srodata，可能是新定义了两个memory和vma，lma导致原本的默认配置被打破 */
    *(.sdata.rodata*)  /* 添加其他可能的只读数据段  这里原linker文件并未设置srodata，可能是新定义了两个memory和vma，lma导致原本的默认配置被打破*/
     . = ALIGN(4);
     _rodata_vma_end = ABSOLUTE(_rodata_vma_start + SIZEOF(.rodata));
  } >sram : rodata
  
  . = ALIGN(4);


  _data_lma = _rodata_lma + SIZEOF(.rodata);
  



  
  .data : AT(_data_lma) {  /* 关键修改：显式指定LMA */
    . = ALIGN(4);
      _data_vma_start = . ;
    *(.data)
    *(.data.*)
    *(.sdata)      /* 添加小数据段 */
    *(.sdata.*)    /* 添加小数据段 */
    . = ALIGN(4);
     _data_vma_end = ABSOLUTE(_data_vma_start + SIZEOF(.data));
  } >sram : data
  
  /* BSS段 - 只需在SRAM中分配空间并清零 */

  .bss : {
     . = ALIGN(4);
    . = ABSOLUTE(_data_vma_end + 4);  /*这一部分用于加载printf的sprintf buf数组，因为链接文件设置的很迷，bss段虽然定义>sram，但是我们的sram是主动在bootloader拷贝进去的，所以只能用计数器来确定在链接文件中最开始规定的立即数符号的地址*/
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
  ASSERT(_heap_start >= _stack_top, "Error: 没有足够空间分配堆区！")
}   