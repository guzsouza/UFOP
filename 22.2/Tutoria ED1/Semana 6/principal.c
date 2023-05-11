#include "busca.h"


int main(){

    int * arr = malloc(sizeof(int) * 1000);
    int key = 0, index;

    for(int i = 0; i < 1000; i++){
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, 999);
    scanf("%d", &key);
    index = binarySearch(arr, 0, 999, key);
    printf("chave %d na posicao %d\n", key, index);
    free(arr);

    return 0;
}