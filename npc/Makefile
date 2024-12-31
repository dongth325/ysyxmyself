# 定义 Verilog 文件和生成的可执行文件
VSRCS = vsrc/NPC.v vsrc/ifu.v vsrc/idu.v vsrc/registerfile.v vsrc/exu.v vsrc/csr.v
CSRC = csrc/main.cpp csrc/difftest_loader.cpp

TOP = ysyx_24090012_NPC
EXE = V$(TOP)
# NEMU 根目录
NEMU_HOME = /home/dongtaiheng/desktopp/ffuck/ysyx-workbench/nemu
# 包含路径
INCLUDE_PATHS = -I$(NEMU_HOME)/include \
                -I$(NEMU_HOME)/src/isa/$(GUEST_ISA)/include \
                -I$(NEMU_HOME)/build/generated

# 定义 GUEST_ISA，确保与 NEMU 的配置一致
GUEST_ISA = riscv32
# 编译器选项，添加宏定义
CFLAGS += -D__GUEST_ISA__=$(GUEST_ISA)
CXXFLAGS += -D__GUEST_ISA__=$(GUEST_ISA)#原本在nemu的makefile中定义guest_isa




# Verilator 相关设置
VERILATOR = verilator
VERILATOR_FLAGS = --cc $(VSRCS) --exe $(CSRC) --top-module $(TOP) --trace \
	--sv \
    -CFLAGS "$(INCLUDE_PATHS) -D__GUEST_ISA__=$(GUEST_ISA)" \
	-LDFLAGS "-lreadline -lhistory"  # 直接添加 -lreadline -lhistory 到 LDFLAGS




# 定义 NPC 仿真器的可执行文件路径
NPC_EXEC = ./obj_dir/$(EXE)

# 仿真目标：编译和执行
sim: $(EXE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(NPC_EXEC) 

   # 默认目标
all: sim
# 添加对 readline 和 history 库的链接
LDFLAGS += -lreadline -lhistory

# 生成可执行文件时包含 LDFLAGS
$(EXE):
	$(VERILATOR) $(VERILATOR_FLAGS)
	make -C obj_dir -f V$(TOP).mk LDFLAGS="$(LDFLAGS)" EXTRACXXFLAGS="$(LDFLAGS)"


# 运行仿真并传递镜像
run: $(EXE)
	$(NPC_EXEC) $(IMG) $(ARGS)

# GDB 调试目标
gdb: $(EXE)
	$(NPC_EXEC) --gdb $(IMG) $(ARGS)

# 清理生成的文件
clean:
	rm -rf obj_dir

# 引入其他 Makefile（如有需要）
include ../Makefile

# 声明伪目标
.PHONY: all sim run gdb clean
