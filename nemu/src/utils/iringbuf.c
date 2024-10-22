#include "iringbuf.h"
#include <string.h>
#include <stdio.h>

void init_ringbuf(RingBuffer *rb) {
    rb->head = 0;
    rb->tail = 0;
    rb->full = 0;
}

void push_ringbuf(RingBuffer *rb, uint64_t pc, uint32_t instruction, const char *disasm) {
    rb->buffer[rb->head].pc = pc;
    rb->buffer[rb->head].instruction = instruction;
    strncpy(rb->buffer[rb->head].disasm, disasm, sizeof(rb->buffer[rb->head].disasm) - 1);
    rb->buffer[rb->head].disasm[sizeof(rb->buffer[rb->head].disasm) - 1] = '\0';

    if (rb->full) {
        rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    }
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    rb->full = (rb->head == rb->tail);
}

void get_trace(RingBuffer *rb) {
    printf("Printing recent instruction trace:\n");

    // 从tail到head遍历并打印缓冲区中的指令
    int index = rb->tail;
    while (index != rb->head || rb->full) {
        TraceEntry *entry = &rb->buffer[index];
        printf("PC: 0x%08lx, Instruction: 0x%x, Disasm: %s\n",
               entry->pc, entry->instruction, entry->disasm);

        // 更新索引到下一条指令
        index = (index + 1) % BUFFER_SIZE;

        // 缓冲区已满时，循环遍历到head时结束
        if (!rb->full && index == rb->head) {
            break;
        }
    }

    // 当环形缓冲区满时，最后一次打印head指针所在位置的指令
    if (rb->full) {
        TraceEntry *entry = &rb->buffer[rb->head];
        printf("PC: 0x%08lx, Instruction: 0x%x, Disasm: %s\n",
               entry->pc, entry->instruction, entry->disasm);
    }

    printf("End of trace111111111111111\n");
}

int is_empty(RingBuffer *rb) {
    return (!rb->full && (rb->head == rb->tail));
}
