#include "busca.h"

int binarySearch(int *array, int left, int right, int search_key){
    
    int middle = (left + right) / 2;

    if (array[middle] != search_key && left == right){
        return -1;
    }    
    else if (search_key > array[middle]){
        return binarySearch(array, middle + 1, right, search_key);
    }    
    else if (search_key < array[middle]){
        return binarySearch(array, left, middle - 1, search_key);
    } 
    else{
        return middle;
    }
}

void merge(int *array, int left, int middle, int right){
    int size_left = (middle - left + 1);
    int size_right = (right - middle);

    int *left_array = malloc(size_left * sizeof(int));
    int *right_array = malloc(size_right * sizeof(int));
    int i, j;

    for (i = 0; i < size_left; i++)
        left_array[i] = array[i + left];

    for (j = 0; j < size_right; j++)
        right_array[j] = array[middle + j + 1];

    i = 0;
    j = 0;

    for (int k = left; k <= right; k++)
    {
        if (i == size_left)
            array[k] = right_array[j++];

        else if (j == size_right)
            array[k] = left_array[i++];

        else if (left_array[i] <= right_array[j])
            array[k] = left_array[i++];

        else
            array[k] = right_array[j++];
    }

    free(left_array);
    free(right_array);
}

void mergeSort(int *array, int left, int right){
    int middle;

    if (left < right){
        middle = (left + right) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}
