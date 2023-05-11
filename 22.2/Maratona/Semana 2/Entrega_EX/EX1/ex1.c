#include <stdio.h>
#include <stdlib.h>

void mergeSort(int*,int);
void merge(int*,int,int,int);
 
int main(){

    int num_lines;
    scanf("%d",&num_lines);

    int *arr_even;
    int *arr_odd;
    int a = 0, b = 0;

    int n;
    arr_even = malloc(num_lines * sizeof(int));
    arr_odd = malloc(num_lines * sizeof(int));

    for(int i = 0; i < num_lines; i++){
        scanf("%d",&n);
        if(n % 2 == 0){
            arr_even[a++] = n;
        }else{
            arr_odd[b++] = n;
        }
    }
    
    mergeSort(arr_even,a);
    mergeSort(arr_odd,b);

    for(int i = 0; i < a; i++){
        printf("%d\n",arr_even[i]);
    }
    for(int j = b - 1; j >= 0; j--){
        printf("%d\n",arr_odd[j]);
    }

    free(arr_even);
    free(arr_odd);
 
    return 0;
}

void mergeSort(int *arr, int length){
    int left, right;
    int aux = 1;
    while(aux < length){
        left = 0;
        while(left + aux < length){
            right = left + 2 * aux;
            if(right > length){
                right = length;
            }
            merge(arr, left, left + aux - 1, right - 1);
            left = left + 2 * aux;
        }
        aux = 2 * aux;
    }
}

void merge(int *arr, int left, int mid, int right){
    int i, j, k;

    int size1 = mid - left + 1;
    int size2 = right - mid;

    int left_arr[size1];
    int right_arr[size2];

    for(i = 0; i < size1; i++){
        left_arr[i] = arr[i + left];
    }
    for(i = 0; i < size2; i++){
        right_arr[i] = arr[i + mid + 1];
    }

    for(i = 0, j = 0, k = left; k <= right; k++){
        if(i == size1){
            arr[k] = right_arr[j++];
        }else if(j == size2){
            arr[k] = left_arr[i++];
        }else if(left_arr[i] < right_arr[j]){
            arr[k] = left_arr[i++];
        }else{
            arr[k] = right_arr[j++];
        }
    }
}


