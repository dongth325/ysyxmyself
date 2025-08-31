#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// 缓存配置
#define BLOCK_SIZE 4    // 每个缓存块4字节
#define NUM_BLOCKS 16   // 共16个缓存块
#define CACHE_SIZE (BLOCK_SIZE * NUM_BLOCKS)  // 总缓存大小为64字节

// 缓存块结构
typedef struct {
    bool valid;         // 有效位
    uint32_t tag;       // 标记
    uint8_t data[BLOCK_SIZE];  // 块数据（本模拟中不使用）
} CacheBlock;

// 缓存模拟器
typedef struct {
    CacheBlock blocks[NUM_BLOCKS];
    int accesses;       // 总内存访问次数
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

// 访问缓存
bool access_cache(CacheSim *cache, uint32_t address) {
    cache->accesses++;
    
    // 提取索引和标记
    uint32_t index = (address / BLOCK_SIZE) % NUM_BLOCKS;
    uint32_t tag = address / (BLOCK_SIZE * NUM_BLOCKS);
    
    // 检查是否命中
    if (cache->blocks[index].valid && cache->blocks[index].tag == tag) {
        cache->hits++;
        return true;  // 命中
    }
    
    // 缺失，需要更新缓存
    cache->misses++;
    cache->blocks[index].valid = true;
    cache->blocks[index].tag = tag;
    
    return false;  // 缺失
}

// 打印缓存统计信息
void print_cache_stats(CacheSim *cache) {
    printf("缓存统计信息:\n");
    printf("总内存访问次数: %d\n", cache->accesses);
    printf("缓存命中次数: %d\n", cache->hits);
    printf("缓存缺失次数: %d\n", cache->misses);
    printf("命中率: %.2f%%\n", (float)cache->hits / cache->accesses * 100);
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
            access_cache(&cache, address);
        }
    }
    
    fclose(trace_file);
    print_cache_stats(&cache);
    
    return 0;
}