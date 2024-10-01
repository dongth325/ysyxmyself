# 定义 Verilog 文件和生成的可执行文件
VSRCS = vsrc/NPC.v vsrc/ifu.v vsrc/idu.v vsrc/registerfile.v vsrc/exu.v
CSRC = csrc/main.cpp
TOP = ysyx_24090012_NPC
EXE = V$(TOP)

# Verilator 相关设置
VERILATOR = verilator
VERILATOR_FLAGS = --cc $(VSRCS) --exe $(CSRC) --top-module $(TOP)

# 定义 NPC 仿真器的可执行文件路径
NPC_EXEC = ./obj_dir/$(EXE)

# 默认目标
all: sim

# 仿真目标：编译和执行
sim: $(EXE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(NPC_EXEC)

# 生成可执行文件
$(EXE):
	$(VERILATOR) $(VERILATOR_FLAGS)
	make -C obj_dir -f V$(TOP).mk

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
