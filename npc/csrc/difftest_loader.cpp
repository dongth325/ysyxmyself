#include "difftest_loader.h"
#include <iostream>

difftest_memcpy_t difftest_memcpy = nullptr;
difftest_regcpy_t difftest_regcpy = nullptr;
difftest_exec_t difftest_exec = nullptr;

void load_difftest_library() {
    void *handle = dlopen("/path/to/riscv32-nemu-interpreter-so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Failed to load NEMU shared library: " << dlerror() << std::endl;
        exit(1);
    }

    difftest_memcpy = (difftest_memcpy_t)dlsym(handle, "difftest_memcpy");
    difftest_regcpy = (difftest_regcpy_t)dlsym(handle, "difftest_regcpy");
    difftest_exec = (difftest_exec_t)dlsym(handle, "difftest_exec");

    if (!difftest_memcpy || !difftest_regcpy || !difftest_exec) {
        std::cerr << "Failed to load DiffTest functions: " << dlerror() << std::endl;
        exit(1);
    }
}
