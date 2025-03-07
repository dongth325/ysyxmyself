#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <assert.h>
#include <memory/paddr.h>


typedef struct {
    char name[64];
    paddr_t addr; // 函数头地址
    Elf32_Xword size;
} Symbol;

Symbol *symbols = NULL; // 存储符号表
int symbol_count = 0;   // 符号数量

void parse_elf(const char *elf_file) {
    if (elf_file == NULL) return;

    FILE *fp = fopen(elf_file, "rb");
    if (fp == NULL) {
        perror("Failed to open the ELF file");
        exit(EXIT_FAILURE);
    }

    // 读取 ELF 头
    Elf32_Ehdr ehdr;
    if (fread(&ehdr, sizeof(Elf32_Ehdr), 1, fp) != 1) {
        perror("Failed to read ELF header");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // 检查 ELF 魔数
    if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Not a valid ELF file\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // 读取节头表
    Elf32_Shdr *shdrs = malloc(ehdr.e_shnum * sizeof(Elf32_Shdr));
    fseek(fp, ehdr.e_shoff, SEEK_SET);
    if (fread(shdrs, sizeof(Elf32_Shdr), ehdr.e_shnum, fp) != ehdr.e_shnum) {
        perror("Failed to read section headers");
        free(shdrs);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // 读取节头字符串表
    char *shstrtab_data = malloc(shdrs[ehdr.e_shstrndx].sh_size);
    fseek(fp, shdrs[ehdr.e_shstrndx].sh_offset, SEEK_SET);
    if (fread(shstrtab_data, 1, shdrs[ehdr.e_shstrndx].sh_size, fp) != shdrs[ehdr.e_shstrndx].sh_size) {
        perror("Failed to read section header string table");
        free(shdrs);
        free(shstrtab_data);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // 查找符号表和字符串表
    Elf32_Shdr *symtab_hdr = NULL;
    Elf32_Shdr *strtab_hdr = NULL;

    for (int i = 0; i < ehdr.e_shnum; i++) {
        char *section_name = shstrtab_data + shdrs[i].sh_name;
        if (strcmp(section_name, ".symtab") == 0) {
            symtab_hdr = &shdrs[i];
        } else if (strcmp(section_name, ".strtab") == 0) {
            strtab_hdr = &shdrs[i];
        }
    }

    if (!symtab_hdr || !strtab_hdr) {
        fprintf(stderr, "Could not find symbol table or string table\n");
        free(shdrs);
        free(shstrtab_data);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // 读取字符串表
    char *strtab_data = malloc(strtab_hdr->sh_size);
    fseek(fp, strtab_hdr->sh_offset, SEEK_SET);
    if (fread(strtab_data, 1, strtab_hdr->sh_size, fp) != strtab_hdr->sh_size) {
        perror("Failed to read string table");
        free(shdrs);
        free(shstrtab_data);
        free(strtab_data);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // 读取并解析符号表
    int num_symbols = symtab_hdr->sh_size / sizeof(Elf32_Sym);
    Elf32_Sym *symtab = malloc(symtab_hdr->sh_size);
    fseek(fp, symtab_hdr->sh_offset, SEEK_SET);
    if (fread(symtab, 1, symtab_hdr->sh_size, fp) != symtab_hdr->sh_size) {
        perror("Failed to read symbol table");
        free(shdrs);
        free(shstrtab_data);
        free(strtab_data);
        free(symtab);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // 分配并初始化符号数组
    symbols = malloc(num_symbols * sizeof(Symbol));
    symbol_count = 0;

    // 解析函数符号
    for (int i = 0; i < num_symbols; i++) {
        if (ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC && symtab[i].st_size > 0) {
            const char *name = strtab_data + symtab[i].st_name;
            strncpy(symbols[symbol_count].name, name, sizeof(symbols[symbol_count].name) - 1);
            symbols[symbol_count].name[sizeof(symbols[symbol_count].name) - 1] = '\0';
            symbols[symbol_count].addr = symtab[i].st_value;
            symbols[symbol_count].size = symtab[i].st_size;
            symbol_count++;
        }
    }
        // 在解析完成后，打印所有符号信息
    printf("\nParsed ELF symbols:\n");
    printf("Total symbols count: %d\n", symbol_count);
    for (int i = 0; i < symbol_count; i++) {
        if (symbols[i].size > 0) {  // 只打印有效的函数符号
            printf("Symbol[%d]: name='%s', addr=0x%x, size=%d\n",
                   i,
                   symbols[i].name,
                   (unsigned int)symbols[i].addr,
                   (unsigned int)symbols[i].size);
        }
    }
    printf("End of symbol list\n\n");



    // 清理
    free(symtab);
    free(strtab_data);
    free(shstrtab_data);
    free(shdrs);
    fclose(fp);
}

extern Symbol *symbols;  // 符号表的外部声明
extern int symbol_count; // 符号数量

void trace_function_call(paddr_t addr) {
     // printf("Debug: Trying to match call address: 0x%x\n", addr);
    for (int i = 0; i < symbol_count; i++) {
        if (symbols[i].addr == addr) {
            Log("Calling function: %s at address: %u", symbols[i].name, addr);
            return;
        }
    }
    Log("Calling unknown function at address: %u", addr);
}

void trace_function_return(paddr_t addr) {
for (int i = 0; i < symbol_count; i++) {
        // 返回时检查PC是否在函数范围内
        if (addr >= symbols[i].addr && 
            addr < symbols[i].addr + symbols[i].size) {
           Log("Returning from function: %s at address: %u", symbols[i].name, addr);
            return;
        }
    }
    Log("Returning from unknown function at address: %u", addr);
}
