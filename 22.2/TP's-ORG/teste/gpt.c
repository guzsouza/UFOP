#include <stdio.h>
#include <stdlib.h>

#define MAX_CACHE_SIZE 5

typedef struct CacheNode {
    int key;
    int value;
    struct CacheNode *prev;
    struct CacheNode *next;
} CacheNode;

typedef struct LRUCache {
    int size;
    CacheNode *head;
    CacheNode *tail;
    CacheNode *cache[MAX_CACHE_SIZE];
} LRUCache;

LRUCache *createCache() {
    LRUCache *cache = (LRUCache *)malloc(sizeof(LRUCache));
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    int i;
    for (i = 0; i < MAX_CACHE_SIZE; i++) {
        cache->cache[i] = NULL;
    }
    return cache;
}

void addToHead(LRUCache *cache, CacheNode *node) {
    node->next = cache->head;
    node->prev = NULL;
    if (cache->head) {
        cache->head->prev = node;
    }
    cache->head = node;
    if (!cache->tail) {
        cache->tail = node;
    }
}

void removeFromList(LRUCache *cache, CacheNode *node) {
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        cache->head = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        cache->tail = node->prev;
    }
}

void moveToHead(LRUCache *cache, CacheNode *node) {
    removeFromList(cache, node);
    addToHead(cache, node);
}

int getFromCache(LRUCache *cache, int key) {
    int index = key % MAX_CACHE_SIZE;
    CacheNode *node = cache->cache[index];
    if (!node) {
        return -1;
    }
    while (node) {
        if (node->key == key) {
            moveToHead(cache, node);
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

void putInCache(LRUCache *cache, int key, int value) {
    int index = key % MAX_CACHE_SIZE;
    CacheNode *node = cache->cache[index];
    if (!node) {
        node = (CacheNode *)malloc(sizeof(CacheNode));
        node->key = key;
        node->value = value;
        node->prev = node->next = NULL;
        cache->cache[index] = node;
        addToHead(cache, node);
        cache->size++;
        if (cache->size > MAX_CACHE_SIZE) {
            cache->size--;
            cache->tail = cache->tail->prev;
            cache->tail->next = NULL;
            free(node);
        }
        } else {
        while (node) {
            if (node->key == key) {
                node->value = value;
                moveToHead(cache, node);
                return;
            }
            node = node->next;
        }
        node = (CacheNode *)malloc(sizeof(CacheNode));
        node->key = key;
        node->value = value;
        node->prev = node->next = NULL;
        cache->cache[index] = node;
        addToHead(cache, node);
        cache->size++;
        if (cache->size > MAX_CACHE_SIZE) {
            cache->size--;
            cache->tail = cache->tail->prev;
            cache->tail->next = NULL;
            free(node);
        }
    }
}

int main() {
    LRUCache *cache = createCache();
    putInCache(cache, 1, 10);
    putInCache(cache, 2, 20);
    putInCache(cache, 3, 30);
    putInCache(cache, 4, 40);
    printf("%d\n", getFromCache(cache, 1));
    printf("%d\n", getFromCache(cache, 2));
    printf("%d\n", getFromCache(cache, 3));
    printf("%d\n", getFromCache(cache, 4));
    return 0;
}