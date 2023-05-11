#include <stdio.h>
#include "memory.h"

void startMemoriaExterna(int size) {
    FILE *arquivo = fopen("memoria_externa.in", "ab+");

    for(int i = 0; i < size; i++)
        fwrite(rand() % 100, sizeof(int), 1, arquivo);
}

void startRAM(RAM* ram, int size) {
    ram->blocks = (MemoryBlock*) malloc(sizeof(MemoryBlock) * size);
    ram->size = size;
}

void stopRAM(RAM *ram) {
    free(ram->blocks);
}


void startCache(Cache* cache, int size) {
    cache->lines = (Line*) malloc(sizeof(Line) * size);
    cache->size = size;

    for (int i=0;i<size;i++)
        cache->lines[i].tag = INVALID_ADD;
}

void stopCache(Cache *cache) {
    free(cache->lines);
}
