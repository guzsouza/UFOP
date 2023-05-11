#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *array, int currentSize);
void merge(int *array, int left, int mid, int right);

int main(void){

    int numTerm = 0;
    int currentTerm = 0;
    int vetPar[100];
    int vetImpar[100];
    int indexPar = 0;
    int indexImpar = 0;

    scanf("%d", &numTerm);  //efetuando a leitura da quantidade de termos a serem inseridos.

    for (int index = 0; index < numTerm; index++){
        
        scanf("%d", &currentTerm); //leitura do termo atual

        if ((currentTerm % 2) == 0) //caso o termo seja par, será salvo no vetor que contém os num pares.
            vetPar [indexPar++] = currentTerm;

        else  //se não, será salvo no vetor dos num ímpares.
            vetImpar [indexImpar++] = currentTerm;
           
    }

    //após a leitura dos termos, e tais termos estarem salvos em seus respectivos arrays, será feita a ordenação de tais vetores.

    mergeSort(vetPar, indexPar);
    mergeSort(vetImpar, indexImpar);

    //após a ordenação, será efetuado o print de todos os termos dos vetores.

    for (int i=0; i < indexPar; i++)
        printf("%d\n", vetPar[i]);

    for (int i = indexImpar-1; i >= 0; i--)
        printf("%d\n", vetImpar[i]);

    return 0;
}

void mergeSort(int *arr,int length){

    int left,right;
    int aux = 1;

    while(aux < length){
        
        left = 0;

        while(left + aux < length){
            right = left + 2 * aux;

            if(right > length)
                right = length;
            
            merge(arr,left,left + aux - 1,right - 1);
            left = left + 2 * aux;
        }
        
        aux = 2 * aux;
    }
}

void merge(int *arr,int left,int mid,int right){

    int i,j,k;

    int size1 = mid - left + 1;
    int size2 = right - mid;

    int vetLeft[size1];
    int vetRight[size2];

    for(i = 0;i < size1;i++)
        vetLeft[i] = arr[i + left];
    
    for(i = 0;i < size2;i++)
        vetRight[i] = arr[i + mid + 1];
    

    for(i = 0,j = 0,k = left;k <= right;k++){

        if(i == size1)
            arr[k] = vetRight[j++];

        else if(j == size2)
            arr[k] = vetLeft[i++];

        else if(vetLeft[i] < vetRight[j])
            arr[k] = vetLeft[i++];

        else
            arr[k] = vetRight[j++];
    }
}