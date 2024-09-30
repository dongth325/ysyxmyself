include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/npc.mk
COMMON_CFLAGS += -march=rv32e_zicsr -mabi=ilp32e  # overwrite
LDFLAGS       += -melf32lriscv                    # overwrite


# 如果需要定义 ISA_H
CFLAGS  += -DISA_H=\"riscv/riscv.h\"

# 确保使用正确的架构标志
COMMON_CFLAGS += -march=rv32em_zicsr -mabi=ilp32e  # overwrite (如果 NPC 支持 rv32em_zicsr)
# 或者
COMMON_CFLAGS += -march=rv32e_zicsr -mabi=ilp32e  # overwrite (根据 NPC 支持情况)

# 覆盖链接器标志
LDFLAGS       += -melf32lriscv                    # overwrite



AM_SRCS += riscv/npc/libgcc/div.S \
           riscv/npc/libgcc/muldi3.S \
           riscv/npc/libgcc/multi3.c \
           riscv/npc/libgcc/ashldi3.c \
           riscv/npc/libgcc/unused.c
