# 定义 Verilog 文件和生成的可执行文件
VSRCS = vsrc/NPC.v vsrc/ifu.v vsrc/idu.v vsrc/registerfile.v vsrc/exu.v vsrc/csr.v vsrc/arbiter.v vsrc/lsu.v
CSRC = csrc/main.cpp csrc/difftest_loader.cpp

# 添加ysyxSoC/perip下的所有.v文件
VSRCS += $(shell find ../ysyxSoC/perip -name "*.v")
VSRCS += ../ysyxSoC/build/ysyxSoCFull.v

TOP = ysyxSoCFull
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




# Verilator 相关设置 添加soc的perip
VERILATOR = verilator
VERILATOR_FLAGS = --cc  $(VSRCS) --exe $(CSRC) --top-module $(TOP) --trace \
	--sv \
	-I../ysyxSoC/perip/uart16550/rtl \
	-I../ysyxSoC/perip/spi/rtl \
	--timescale "1ns/1ns" \
	--no-timing \
    -CFLAGS "$(INCLUDE_PATHS) -D__GUEST_ISA__=$(GUEST_ISA) -DDEBUG_PRINT_FULL  -g -O0" \
    -LDFLAGS "-lreadline -lhistory" \
	-autoflush

    




# 定义 NPC 仿真器的可执行文件路径
NPC_EXEC = ./obj_dir/$(EXE)



# 定义波形文件路径和最近运行记录
BUILD_DIR = build
WAVE_FILE = $(abspath $(BUILD_DIR)/wave.vcd)
LAST_RUN_FILE = $(BUILD_DIR)/.last_run

# 定义波形文件路径和最近运行记录
BUILD_DIR = build
WAVE_FILE = $(BUILD_DIR)/wave.vcd
LAST_RUN_FILE = $(BUILD_DIR)/.last_run

# 确保 BUILD_DIR 存在
$(shell mkdir -p $(BUILD_DIR))

# 仿真目标
sim: $(EXE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@if [ ! -z "$(IMG)" ]; then \
		echo "$(IMG)" > $(LAST_RUN_FILE); \
	fi
	@if [ -f $(LAST_RUN_FILE) ]; then \
		IMG_PATH=$$(cat $(LAST_RUN_FILE)); \
		echo "Running simulation with $$IMG_PATH"; \
		$(NPC_EXEC) $$IMG_PATH; \
	else \
		echo "Error: No program specified. Please run with IMG=path/to/program.bin first"; \
		exit 1; \
	fi
# 波形查看目标
wave:
	@if [ ! -f $(WAVE_FILE) ]; then \
		if [ -f $(LAST_RUN_FILE) ]; then \
			make sim; \
		else \
			echo "Error: No previous run found. Please run with IMG=path/to/program.bin first"; \
			exit 1; \
		fi \
	fi
	@if [ -f $(WAVE_FILE) ]; then \
		echo "Opening waveform viewer..."; \
		gtkwave $(WAVE_FILE); \
	else \
		echo "Error: Wave file not found at $(WAVE_FILE)"; \
	fi

# 显示最近运行的程序
show-last:
	@if [ -f $(LAST_RUN_FILE) ]; then \
		echo "Last run program: $$(cat $(LAST_RUN_FILE))"; \
	else \
		echo "No previous run recorded"; \
	fi

.PHONY: sim wave show-last
   # 默认目标
all: sim
# 添加对 readline 和 history 库的链接
LDFLAGS += -lreadline -lhistory

# 生成可执行文件时包含 LDFLAGS


$(EXE):
	$(VERILATOR) $(VERILATOR_FLAGS)
	$(MAKE) -C obj_dir -f V$(TOP).mk

# 运行仿真并传递镜像
run: $(EXE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(NPC_EXEC) $(IMG) $(ARGS)

# GDB 调试目标
gdb: $(EXE)
	gdb -s ./obj_dir/$(EXE) --args ./obj_dir/$(EXE) $(IMG) $(ARGS)

# 清理生成的文件
clean:
	rm -rf obj_dir

# 引入其他 Makefile（如有需要）
include ../Makefile

# 声明伪目标
.PHONY: all sim run gdb clean
