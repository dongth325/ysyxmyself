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
    int file_lines;     // 文件中的行数
    int burst_accesses; // 突发传输次数
    int hits;           // 缓存命中次数
    int misses;         // 缓存缺失次数
    int demo_accesses;  // 演示用的额外访问次数
} CacheSim;

// 初始化缓存
void init_cache(CacheSim *cache) {
    memset(cache, 0, sizeof(CacheSim));
    for (int i = 0; i < NUM_BLOCKS; i++) {
        cache->blocks[i].valid = false;
    }
}

// 访问缓存（突发传输）
bool access_cache_burst(CacheSim *cache, uint32_t address, uint32_t *data, bool count_access) {
    if (count_access) {
        cache->accesses++;
    } else {
        cache->demo_accesses++;
    }
    
    // 计算块对齐地址（16字节对齐）
    uint32_t block_address = address & ~(BLOCK_SIZE - 1);
    
    // 提取索引和标记
    uint32_t index = (block_address / BLOCK_SIZE) % NUM_BLOCKS;
    uint32_t tag = block_address / (BLOCK_SIZE * NUM_BLOCKS);
    
    // 计算块内偏移（哪个字）
    uint32_t word_offset = (address % BLOCK_SIZE) / WORD_SIZE;
    
    // 检查是否命中
    if (cache->blocks[index].valid && cache->blocks[index].tag == tag) {
        if (count_access) {
            cache->hits++;
        }
        
        // 返回请求的数据（从命中的块中）
        if (data != NULL) {
            *data = cache->blocks[index].data[word_offset];
        }
        
        return true;  // 命中
    }
    
    // 缺失，需要更新缓存
    if (count_access) {
        cache->misses++;
        cache->burst_accesses++;
    }
    
    cache->blocks[index].valid = true;
    cache->blocks[index].tag = tag;
    
    // 模拟从内存读取整个块（4个字）
    // 在实际系统中，这里会从内存读取数据
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
    
    // 访问缓存，确保块被加载（不计入正常访问次数）
    uint32_t dummy;
    access_cache_burst(cache, block_address, &dummy, false);
    
    // 复制整个块的数据
    for (int i = 0; i < WORDS_PER_BLOCK; i++) {
        data[i] = cache->blocks[index].data[i];
    }
}

// 打印缓存统计信息
// 打印缓存统计信息
void print_cache_stats(CacheSim *cache) {
    printf("\n缓存统计信息:\n");
    printf("文件中的地址数量: %d\n", cache->file_lines);
    printf("总内存访问次数: %d (包含%d次演示访问)\n", 
           cache->accesses + cache->demo_accesses, cache->demo_accesses);
    printf("实际程序访问次数: %d\n", cache->accesses);
    printf("突发传输次数: %d\n", cache->burst_accesses);
    printf("缓存命中次数: %d\n", cache->hits);
    printf("缓存缺失次数: %d\n", cache->misses);
    printf("命中率: %.2f%%\n", (float)cache->hits / cache->accesses * 100);
    
    // 突发传输效率统计
    printf("\n突发传输效率:\n");
    printf("每次突发传输获取的字数: %d\n", WORDS_PER_BLOCK);
    printf("总共获取的字数: %d\n", cache->burst_accesses * WORDS_PER_BLOCK);
    printf("内存带宽利用率: %.2f%%\n",
           (float)(cache->burst_accesses * WORDS_PER_BLOCK) / cache->accesses * 100);
    
    // 计算有效块数量
    int valid_blocks = 0;
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (cache->blocks[i].valid) {
            valid_blocks++;
        }
    }
    
    // 缓存效率分析
    float avg_words_per_access = (float)(cache->burst_accesses * WORDS_PER_BLOCK) / 
                                 (cache->burst_accesses + cache->hits);
    printf("\n缓存效率分析:\n");
    printf("平均每次内存访问获取的字数: %.2f\n", avg_words_per_access);
    printf("缓存空间利用率: %.2f%%\n", (float)valid_blocks / NUM_BLOCKS * 100);
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
    int line_count = 0;
    
    // 从跟踪文件中读取每个PC地址
    while (fgets(line, sizeof(line), trace_file)) {
        line_count++;
        if (sscanf(line, "0x%x", &address) == 1) {
            cache.file_lines++;
            
            // 访问缓存（使用突发传输）
            uint32_t data;
            access_cache_burst(&cache, address, &data, true);
            
            // 演示如何获取整个块（每1000次访问打印一次，减少输出量）
            if (cache.accesses % 1000 == 0) {
                uint32_t block_data[WORDS_PER_BLOCK];
                get_cache_block(&cache, address, block_data);
                
                printf("\n访问 #%d - 地址: 0x%08x\n", cache.accesses, address);
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
    
    // 计算有效缓存块数量
    int valid_blocks = 0;
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (cache.blocks[i].valid) {
            valid_blocks++;
        }
    }
    
    printf("\n文件总行数: %d\n", line_count);
    printf("有效缓存块数量: %d/%d\n", valid_blocks, NUM_BLOCKS);
    
    print_cache_stats(&cache);
    
    return 0;
}