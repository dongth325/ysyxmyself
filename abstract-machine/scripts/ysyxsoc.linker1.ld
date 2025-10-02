/*用于ysyxsoc运行rtt，里面有原本rtt的extra.ld内容，同时rtt中的extra文件应该为空，也就是使用extra2.ld*/

ENTRY(_start)
PHDRS {  fsbl PT_LOAD; text PT_LOAD; data PT_LOAD;rodata PT_LOAD; bss PT_LOAD; }

MEMORY {
  flash : ORIGIN = 0x30000000, LENGTH = 16M  /* Flash 16MB */
  mrom : ORIGIN = 0x20000000, LENGTH = 4K  /* mrom 4KB */
  sram : ORIGIN = 0x0f000000, LENGTH = 8K  /* SRAM 8KB */
  sdram : ORIGIN = 0xa0000000, LENGTH = 64M  /* SDRAM 64MB (0xa0000000~0xa3ffffff) */
  psram : ORIGIN = 0x80000000, LENGTH = 4M 
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
  } >sdram : text





 _text_lma = _bootloader_lma + SIZEOF(.bootloader) + 4;



  .text : AT(_text_lma) {   /*要把memtest全部加再到sram中，这里是包括trm init等在内的所有代码部分，不能全拷贝，只能拷贝main函数，因为前面的已经执行过了*/
     . = ALIGN(4);
      _text_vma_start = . ;
    *(entry)
    *(.text*)

   PROVIDE(_execute_main = execute_main);
     

      . = ALIGN(4);
     _text_vma_end = ABSOLUTE(_text_vma_start + SIZEOF(.text));
  } >sdram : text
  


  

 










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
  } >sdram : rodata
  
  . = ALIGN(4);


/* 在ysyxsoc.linker.ld中 */
PROVIDE(_rodata_end_lma = _rodata_lma + SIZEOF(.rodata));

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
  } >sdram : data
  








/* 添加 .data.extra 段，放在 .data 段后面 */
  _data_extra_lma = _data_lma + SIZEOF(.data);
 
  .data.extra : AT(_data_extra_lma) {
        /*由8字节改成四字对齐，因为必须要保证大段的vma和定义的_data_extra_vma_start完全相同，同时lma和定义的lma也必须完全相同，注意是大段*/
    . = ALIGN(4);
    _data_extra_vma_start = .;    /*手动添加data extra开始地址*/

. = ALIGN(8);
    /* section information for finsh shell */
    __fsymtab_start = .;
    KEEP(*(FSymTab))
    __fsymtab_end = .;
    . = ALIGN(8);
    __vsymtab_start = .;
    KEEP(*(VSymTab))
    __vsymtab_end = .;
    . = ALIGN(8);

    /* section information for initial. */
    . = ALIGN(8);
    __rt_init_start = .;
    KEEP(*(SORT(.rti_fn*)))
    __rt_init_end = .;
    . = ALIGN(8);

    __rt_utest_tc_tab_start = .;
    KEEP(*(UtestTcTab))
    __rt_utest_tc_tab_end = .;

    . = ALIGN(8);
    __am_apps_data_start = .;
    *(__am_apps.data*)
    *(__am_apps.sdata*)
    __am_apps_data_end = .;
    . = ALIGN(8);

    _data_extra_vma_end = ABSOLUTE(_data_extra_vma_start + SIZEOF(.data.extra));   /*手动添加data extra结束地址*/
  } >sdram : data






  _bss_extra_lma = _data_extra_lma + SIZEOF(.data.extra);

  .bss.extra : AT(_bss_extra_lma){
     . = ALIGN(4);
     _bss_extra_vma_start = .;
    . = ALIGN(8);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(8);
    _bss_extra_vma_end = ABSOLUTE(_bss_extra_vma_start + SIZEOF(.bss.extra));
  } >sdram : bss







_bss_lma = _bss_extra_lma + SIZEOF(.bss.extra);

  /* BSS段  */

  .bss  : AT(_bss_lma) {
     . = ALIGN(4);
   
   _bss_vma_start = .;
   
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
   _bss_vma_end = .;

 } >sdram
  








  /* 记录数据和BSS段结束后的位置 */
  _prog_end = .;

 
  /* 堆区起始地址，大小设置为4m，不能太大，太大了rtt会一直写入太影响时间，最好是4m因为psram是4m，能运行rtt，sdram用4m肯定没事 */
  /*但是切换psram的时候记得修改大小，具体就是 . = ORIGIN(sdram) + LENGTH(sdram) - 64K;_heap_end = .;*/
  
  _heap_start = ALIGN(0x1000);
   _heap_end = _heap_start + 4M; 
 
  
  /* 栈区大小可调整 - 这里设为2KB */
  . = ORIGIN(sram) + LENGTH(sram) - 4K;  /* 留出4KB给栈 */
  _stack_top = .;
  
  /* SRAM结束地址 */
  . = ORIGIN(sram) + LENGTH(sram);
  _stack_pointer = ALIGN(4);  /* 四字节对齐并留出一个字 */
  
  
  

}