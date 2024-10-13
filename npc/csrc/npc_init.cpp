#include "npc_init.h"
#include <iostream>
#include <fstream>
#include <cstring>

#define MEM_SIZE (128 * 1024 * 1024)
#define PROGRAM_START_ADDRESS 0x80000000
#define MEM_BASE 0x80000000

void load_memory(const char *program_path, size_t &program_size) {
    // 打开文件
    std::ifstream infile(program_path, std::ios::binary | std::ios::in);
    if (!infile) {
        std::cerr << "Cannot open program file: " << program_path << std::endl;
        exit(1);
    }

    infile.seekg(0, std::ios::end);
    program_size = infile.tellg();
    infile.seekg(0, std::ios::beg);

    if (program_size > MEM_SIZE) {
        std::cerr << "Program size (" << program_size << " bytes) exceeds memory size (" << MEM_SIZE << " bytes)." << std::endl;
        exit(1);
    }

    infile.read(reinterpret_cast<char *>(memory), program_size);
    infile.close();

    std::cout << "Loaded program: " << program_path << ", size: " << program_size << " bytes." << std::endl;
}


