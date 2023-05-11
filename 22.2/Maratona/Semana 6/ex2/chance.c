#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void merge(char *arr, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    char *L = (char*) malloc(n1 * sizeof(char));
    char *R = (char*) malloc(n2 * sizeof(char));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(char *arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int verify(char *arr1, char *arr2, int n){
    int verifier = 0;
    int wrong = 0;

    for (int index = 0; index < n; index++){
        if (arr1[index] != arr2[index])
            wrong++;

        if (wrong > 2)
            break;
    }

    return wrong;
}

int main(void){
    
    int NumTerm = 0;

    scanf("%d", &NumTerm);

    //repetição de entradas
    for (int repeat = 0; repeat < NumTerm; repeat++){

        bool error = false;
        int StringSize = 0;

        scanf("%d", &StringSize);

        char *String = (char*) malloc((StringSize + 1) *sizeof(char));
        char *AuxString = (char*) malloc((StringSize + 1) *sizeof(char));


        for (int scan = 0; scan < StringSize; scan++)
            scanf(" %c", &String[scan]);
        
        strcpy(AuxString, String);
        
        mergeSort(String, 0, StringSize - 1);

        if (verify(String, AuxString, StringSize) > 2)
            error = true;


        if (error == false)
            printf("There are the chance.\n");
        else if (error == true)
            printf("There aren't the chance.\n");

        free(String);
        free(AuxString);
    }
    return 0;
}

