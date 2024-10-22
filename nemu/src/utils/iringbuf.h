#ifndef IRINGBUF_H
#define IRINGBUF_H

#include <stdint.h>

#define BUFFER_SIZE 256

typedef struct {
    uint64_t pc;
    uint32_t instruction;
    char disasm[64];
} TraceEntry;

typedef struct {
    TraceEntry buffer[BUFFER_SIZE];
    int head;
    int tail;
    int full;
} RingBuffer;

void init_ringbuf(RingBuffer *rb);
void push_ringbuf(RingBuffer *rb, uint64_t pc, uint32_t instruction, const char *disasm);
void get_trace(RingBuffer *rb);
int is_empty(RingBuffer *rb);

#endif // IRINGBUF_H
