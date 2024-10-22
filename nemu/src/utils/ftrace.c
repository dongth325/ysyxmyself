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

    Elf32_Ehdr ehdr;
    if (fread(&ehdr, sizeof(Elf32_Ehdr), 1, fp) != 1) {
        perror("Failed to read ELF header");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // 检查 ELF 文件标识
    if (ehdr.e_ident[EI_MAG0] != ELFMAG0 ||
        ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
        ehdr.e_ident[EI_MAG2] != ELFMAG2 ||
        ehdr.e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "Not a valid ELF file\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    size_t read_count;
    // 读取节头表
    Elf32_Shdr *shdrs = malloc(ehdr.e_shnum * sizeof(Elf32_Shdr));
    fseek(fp, ehdr.e_shoff, SEEK_SET);
    read_count = fread(shdrs, sizeof(Elf32_Shdr), ehdr.e_shnum, fp);
if (read_count != ehdr.e_shnum) {
    perror("Failed to read section headers");
    fclose(fp);
    exit(EXIT_FAILURE);
}

    // 找到符号表和节名称表
    Elf32_Shdr *shstrtab = &shdrs[ehdr.e_shstrndx];
    char *shstrtab_data = malloc(shstrtab->sh_size);
    fseek(fp, shstrtab->sh_offset, SEEK_SET);
    read_count = fread(shstrtab_data, shstrtab->sh_size, 1, fp);
if (read_count != 1) {  // 因为我们读取了一个块
    perror("Failed to read section string table");
    fclose(fp);
    exit(EXIT_FAILURE);
}

    for (int i = 0; i < ehdr.e_shnum; i++) {
    Elf32_Shdr *shdr = &shdrs[i];

    if (shdr->sh_type == SHT_SYMTAB) {
        int num_symbols = shdr->sh_size / sizeof(Elf32_Sym);
        symbols = malloc(num_symbols * sizeof(Symbol));
        symbol_count = num_symbols;

        Elf32_Sym *symtab = malloc(shdr->sh_size);
        fseek(fp, shdr->sh_offset, SEEK_SET);
        if (fread(symtab, shdr->sh_size, 1, fp) != 1) {
            perror("Failed to read symbol table");
            free(shdrs);
            free(shstrtab_data);
            fclose(fp);
            exit(EXIT_FAILURE);
        }

        // 解析符号
        for (int j = 0; j < num_symbols; j++) {
            if (ELF32_ST_TYPE(symtab[j].st_info) == STT_FUNC) {
                char *name = shstrtab_data + symtab[j].st_name;
                strncpy(symbols[j].name, name, sizeof(symbols[j].name));
                symbols[j].addr = symtab[j].st_value; // 函数地址
                symbols[j].size = symtab[j].st_size;  // 函数大小
            }
        }
        free(symtab);
    }
}

free(shdrs);
free(shstrtab_data);
fclose(fp);
}



extern Symbol *symbols;  // 符号表的外部声明
extern int symbol_count; // 符号数量

void trace_function_call(paddr_t addr) {
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
        if (symbols[i].addr == addr) {
            Log("Returning from function: %s at address: %u", symbols[i].name, addr);
            return;
        }
    }
    Log("Returning from unknown function at address: %u", addr);
}
