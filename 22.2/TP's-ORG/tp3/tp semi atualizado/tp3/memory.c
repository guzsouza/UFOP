#include <stdio.h>
#include "memory.h"

void startHD(HD* hd, int size) {
    // FILE *arquivo = fopen("memoria_externa.in", "ab+");
    FILE *arquivo = fopen("memoria_externa.txt", "w");
    // int* block = (int*) malloc(sizeof(int) * size);

    hd->size = size;

    for(int i = 0; i < size; i++) {
        fprintf(arquivo, "%d", rand() % 100);
        
        for(int j = 1; j < WORDS_SIZE; j++)
            fprintf(arquivo, " %d", rand() % 100);
        
        fputs("\n", arquivo);
    }

    fclose(arquivo);
  //  free(block);
}

void startRAM(RAM* ram, int size) {
    ram->blocks = (RamBlock*) malloc(sizeof(RamBlock) * size);
    ram->size = size;

    for (int i=0;i<size;i++)
        ram->blocks[i].isNull = 1;
    /*
    for (int i=0;i<size;i++) {
        for (int j=0;j<WORDS_SIZE;j++)
            ram->blocks[i].words[j] = rand() % 100;            
    }
    */
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
