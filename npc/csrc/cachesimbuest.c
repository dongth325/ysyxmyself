#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// 缓存配置
#define WORD_SIZE 4        // 每个字4字节（32位）
#define WORDS_PER_BLOCK 4  // 每个缓存块包含4个字（突发传输）
#define BLOCK_SIZE (WORD_SIZE * WORDS_PER_BLOCK)  // 每个缓存块16字节
#define NUM_BLOCKS 16      // 共16个缓存块
#define CACHE_SIZE (BLOCK_SIZE * NUM_BLOCKS)  // 总缓存大小为256字节

// 缓存块结构
typedef struct {
    bool valid;         // 有效位
    uint32_t tag;       // 标记
    uint32_t data[WORDS_PER_BLOCK];  // 块数据，存储4个32位字
} CacheBlock;

// 缓存模拟器
typedef struct {
    CacheBlock blocks[NUM_BLOCKS];
    int accesses;       // 总内存访问次数
    int burst_accesses; // 突发传输次数
    int hits;           // 缓存命中次数
    int misses;         // 缓存缺失次数
} CacheSim;

// 初始化缓存
void init_cache(CacheSim *cache) {
    memset(cache, 0, sizeof(CacheSim));
    for (int i = 0; i < NUM_BLOCKS; i++) {
        cache->blocks[i].valid = false;
    }
}

// 访问缓存（突发传输）
bool access_cache_burst(CacheSim *cache, uint32_t address, uint32_t *data) {
    cache->accesses++;
    
    // 计算块对齐地址（16字节对齐）
    uint32_t block_address = address & ~(BLOCK_SIZE - 1);
    
    // 提取索引和标记
    uint32_t index = (block_address / BLOCK_SIZE) % NUM_BLOCKS;
    uint32_t tag = block_address / (BLOCK_SIZE * NUM_BLOCKS);
    
    // 计算块内偏移（哪个字）
    uint32_t word_offset = (address % BLOCK_SIZE) / WORD_SIZE;
    
    // 检查是否命中
    if (cache->blocks[index].valid && cache->blocks[index].tag == tag) {
        cache->hits++;
        
        // 返回请求的数据（从命中的块中）
        if (data != NULL) {
            *data = cache->blocks[index].data[word_offset];
        }
        
        return true;  // 命中
    }
    
    // 缺失，需要更新缓存
    cache->misses++;
    cache->burst_accesses++;
    
    cache->blocks[index].valid = true;
    cache->blocks[index].tag = tag;
    
    // 模拟从内存读取整个块（4个字）
    // 在实际系统中，这里会从内存读取数据
    // 在这个模拟中，我们只是记录这次突发传输
    for (int i = 0; i < WORDS_PER_BLOCK; i++) {
        // 模拟数据，实际中应从内存读取
        cache->blocks[index].data[i] = block_address + i * WORD_SIZE;
    }
    
    // 返回请求的数据（从新加载的块中）
    if (data != NULL) {
        *data = cache->blocks[index].data[word_offset];
    }
    
    return false;  // 缺失
}

// 获取缓存块中的所有数据（4个字）
void get_cache_block(CacheSim *cache, uint32_t address, uint32_t data[WORDS_PER_BLOCK]) {
    // 计算块对齐地址
    uint32_t block_address = address & ~(BLOCK_SIZE - 1);
    
    // 提取索引
    uint32_t index = (block_address / BLOCK_SIZE) % NUM_BLOCKS;
    
    // 访问缓存，确保块被加载
    uint32_t dummy;
    access_cache_burst(cache, block_address, &dummy);
    
    // 复制整个块的数据
    for (int i = 0; i < WORDS_PER_BLOCK; i++) {
        data[i] = cache->blocks[index].data[i];
    }
}

// 打印缓存统计信息
void print_cache_stats(CacheSim *cache) {
    printf("缓存统计信息:\n");
    printf("总内存访问次数: %d\n", cache->accesses);
    printf("突发传输次数: %d\n", cache->burst_accesses);
    printf("缓存命中次数: %d\n", cache->hits);
    printf("缓存缺失次数: %d\n", cache->misses);
    printf("命中率: %.2f%%\n", (float)cache->hits / cache->accesses * 100);
    printf("每次突发传输获取的平均字数: %.2f\n", 
           cache->burst_accesses > 0 ? (float)WORDS_PER_BLOCK : 0);
    printf("每次访问的平均内存带宽利用率: %.2f%%\n",
           cache->accesses > 0 ? (float)(cache->burst_accesses * WORDS_PER_BLOCK) / cache->accesses * 100 : 0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("用法: %s <trace_file>\n", argv[0]);
        return 1;
    }
    
    CacheSim cache;
    init_cache(&cache);
    
    FILE *trace_file = fopen(argv[1], "r");
    if (!trace_file) {
        printf("错误: 无法打开跟踪文件 %s\n", argv[1]);
        return 1;
    }
    
    char line[50];
    uint32_t address;
    
    // 从跟踪文件中读取每个PC地址
    while (fgets(line, sizeof(line), trace_file)) {
        if (sscanf(line, "0x%x", &address) == 1) {
            // 访问缓存（使用突发传输）
            uint32_t data;
            access_cache_burst(&cache, address, &data);
            
            // 演示如何获取整个块
            if (cache.accesses % 100 == 0) {  // 每100次访问打印一次示例
                uint32_t block_data[WORDS_PER_BLOCK];
                get_cache_block(&cache, address, block_data);
                
                printf("\n访问地址: 0x%08x\n", address);
                printf("块对齐地址: 0x%08x\n", address & ~(BLOCK_SIZE - 1));
                printf("块内数据:\n");
                for (int i = 0; i < WORDS_PER_BLOCK; i++) {
                    printf("  字%d (0x%08x): 0x%08x\n", 
                           i, (address & ~(BLOCK_SIZE - 1)) + i * WORD_SIZE, block_data[i]);
                }
            }
        }
    }
    
    fclose(trace_file);
    print_cache_stats(&cache);
    
    return 0;
}