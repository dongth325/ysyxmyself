
#include "difftest_loader.h"
#include <iostream>
#include <fstream> 
 
#include "isa.h" // 包含 CPU_state 的定义
#include "VysyxSoCFull.h" 
#include "svdpi.h"
difftest_memcpy_t difftest_memcpy = nullptr;
difftest_regcpy_t difftest_regcpy = nullptr;
difftest_exec_t difftest_exec = nullptr;










// PC跟踪记录的文件流
static std::ofstream pc_trace_file;    //追踪pc用于cachesim
static bool pc_trace_enabled = false;

// 初始化PC跟踪
extern "C" void init_pc_trace(const char* filename) {
    pc_trace_file.open(filename);
    if (!pc_trace_file.is_open()) {
        std::cerr << "Failed to open PC trace file: " << filename << std::endl;
        return;
    }
    pc_trace_enabled = true;
    std::cout << "PC trace logging enabled to: " << filename << std::endl;
}

// 关闭PC跟踪
extern "C" void close_pc_trace() {
    if (pc_trace_enabled && pc_trace_file.is_open()) {
        pc_trace_file.close();
        pc_trace_enabled = false;
        std::cout << "PC trace logging completed" << std::endl;
    }
}







extern "C" int get_reg_value(int reg_index);
extern "C" int get_csr_reg_value(int csr_reg_index);
extern "C" int get_pc_value();
//extern NpcState npc_state;

// 跳过控制变量
static bool is_skip_ref = false;//add difftest skip........
static int skip_dut_nr_inst = 0;//add difftest skip........

//  difftest_skip_ref 
extern "C" void difftest_skip_ref() {//add difftest skip........
    is_skip_ref = true;
    skip_dut_nr_inst = 0;
}

//  difftest_skip_dut 
extern "C" void difftest_skip_dut(int nr_ref, int nr_dut) {//add difftest skip........
    skip_dut_nr_inst += nr_dut;

    while (nr_ref-- > 0) {
        difftest_exec(1);
    }
}





void load_difftest_library() {
    void *handle = dlopen("/home/dongtaiheng/desktopp/ffuck/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so", RTLD_LAZY);
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



void get_dut_cpu_state(VysyxSoCFull *top, CPU_state *dut_cpu_state) {
    // 获取 PC  设置npc模块上下文
  svScope cpu_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu");
    if (cpu_scope == NULL) {
        fprintf(stderr, "Error: Unable to set DPI scope for CPU\n");
        exit(1);
    }
    svSetScope(cpu_scope);
    
    // 获取PC值
    dut_cpu_state->pc = get_pc_value();

//设置普通reg上下文
    svScope scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.regfile");
    if (scope == NULL) {
        fprintf(stderr, "Error: Unable to set DPI scope\n");
        exit(1);
    }
    svSetScope(scope);

for(int i=0;i<32;i++){
int reg_value;
reg_value = get_reg_value(i);
dut_cpu_state->gpr[i]=get_reg_value(i);
//printf("register DUT %d value: 0x%08x from (get_dut_cpu_state)\n", i,dut_cpu_state->gpr[i]);
   }
        // 设置 new CSR 上下文
   svScope csr_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.csr");
if (csr_scope == NULL) {
    fprintf(stderr, "Error: Unable to set DPI scope for CSR\n");
    exit(1);
}
svSetScope(csr_scope);
   int csr1,csr2,csr3,csr4;
   csr1 = get_csr_reg_value(1);
   csr2 = get_csr_reg_value(2);
   csr3 = get_csr_reg_value(3);
   csr4 = get_csr_reg_value(4);
    //printf("mcause = %d",csr1);
    // printf("mtvec = %d",csr2);
     // printf("mepc = %d",csr3);
     //  printf("mstatus = %d",csr4);
    dut_cpu_state->csr.mcause = get_csr_reg_value(1);  
    dut_cpu_state->csr.mtvec = get_csr_reg_value(2);   
    dut_cpu_state->csr.mepc = get_csr_reg_value(3);    
    dut_cpu_state->csr.mstatus = get_csr_reg_value(4); 
  
    for (int i = 0; i < 32; i++) {
      
    }
  
     
}

bool isa_difftest_checkregs(CPU_state *dut, CPU_state *ref) {
    // 比较通用寄存器
  for (int i = 0; i < 16; i++) {
   
   if (dut->gpr[i] != ref->gpr[i]) {
        std::cerr << "Register " << i << " mismatch: "
                  << "DUT = 0x" << std::hex << dut->gpr[i] 
                  << ", REF = 0x" << ref->gpr[i] << std::endl;
        return false;
    }
     if (dut->pc != ref->pc) {
        std::cerr << "PC mismatch: "
                  << "DUT = 0x" << std::hex << dut->pc
                  << ", REF = 0x" << ref->pc << std::dec << std::endl;
        return false;
    }
}
   if (dut->csr.mcause != ref->csr.mcause) {
        std::cerr << "mcause mismatch: "
                  << "DUT = 0x" << std::hex << dut->csr.mcause
                  << ", REF = 0x" << ref->csr.mcause << std::dec << std::endl;
        return false;
   }

    if (dut->csr.mtvec != ref->csr.mtvec) {
        std::cerr << "mtvec mismatch: "
                  << "DUT = 0x" << std::hex << dut->csr.mtvec
                  << ", REF = 0x" << ref->csr.mtvec << std::dec << std::endl;
        return false;
    }

    if (dut->csr.mepc != ref->csr.mepc) {
        std::cerr << "mepc mismatch: "
                  << "DUT = 0x" << std::hex << dut->csr.mepc
                  << ", REF = 0x" << ref->csr.mepc << std::dec << std::endl;
        return false;
    }

    if (dut->csr.mstatus != ref->csr.mstatus) {
        std::cerr << "mstatus mismatch: "
                  << "DUT = 0x" << std::hex << dut->csr.mstatus
                  << ", REF = 0x" << ref->csr.mstatus << std::dec << std::endl;
        return false;
    }

  
    
    return true;
}



// 实现 difftest_step 函数
extern "C" void difftest_step(VysyxSoCFull *top,uint32_t pc, uint32_t npc) {



  // 记录当前PC到跟踪文件用于cachesim
   /* if (pc_trace_enabled && pc_trace_file.is_open()) {
        pc_trace_file << std::hex << "0x" << pc << std::endl;
    }*/

   

    CPU_state ref_cpu_state;

    // 处理需要跳过的 DUT 指令比较
    if (skip_dut_nr_inst > 0) {          //目前只需将npc作为dut nemu作为ref  关于设备skip只需ref skip   dut skip暂时不实现 。。。。
        // 复制 REF 的寄存器状态到 ref_r
        difftest_regcpy(&ref_cpu_state, false);

        // 检查 REF 的 PC 是否已同步到 DUT 的下一个 PC
        if (ref_cpu_state.pc == npc) {
            // 同步完成，重置跳过计数器
            skip_dut_nr_inst = 0;

            // 获取 DUT 的 CPU 状态
            CPU_state dut_cpu_state;
            get_dut_cpu_state(top, &dut_cpu_state);

            // 进行寄存器比较
            if (!isa_difftest_checkregs(&dut_cpu_state, &ref_cpu_state)) {
                std::cerr << "[DiffTest] Difftest failed at PC = 0x" << std::hex << dut_cpu_state.pc << std::dec << std::endl;
                exit(1);
            }
            return;
        }

        // 递减跳过计数器
        skip_dut_nr_inst--;

        // 如果跳过计数器减至 0，且 REF 的 PC 仍未同步，触发错误
        if (skip_dut_nr_inst == 0) {
            std::cerr << "[DiffTest] Error: Cannot catch up with REF at PC = 0x" << std::hex << ref_cpu_state.pc << std::dec << std::endl;
            exit(1);
        }
        return;
    }

    // 处理需要跳过 REF 的当前指令比较
    if (is_skip_ref) {
        // 获取 DUT 的 CPU 状态
        CPU_state dut_cpu_state;
        get_dut_cpu_state(top, &dut_cpu_state);//’s‘  是否定义？？

        // 将 DUT 的寄存器状态复制到 REF 中
        difftest_regcpy(&dut_cpu_state, true);

        // 重置跳过标志
        is_skip_ref = false;
      
        return;
    }

    // 正常执行 DiffTest 步骤
    difftest_exec(1); // 让 REF 执行一条指令
    difftest_regcpy(&ref_cpu_state, false); // 复制 REF 的寄存器状态

    // 获取 DUT 的 CPU 状态
    CPU_state dut_cpu_state;
    get_dut_cpu_state(top, &dut_cpu_state);

    // 比较寄存器状态
    if (!isa_difftest_checkregs(&dut_cpu_state, &ref_cpu_state)) {
        std::cerr << "[DiffTest] Difftest failed at PC = 0x" << std::hex << dut_cpu_state.pc << std::dec << std::endl;
        //exit(1);
Verilated::gotFinish(true);  // 强制终止Verilator
            return;  // 立即返回


    }
}
