#include <stdio.h>
#include <stdlib.h>

void margeSort(int *array, int currentSize);
void merge(int *array, int *left, int leftsize, int *right, int rightsize);

int main(void){

    int numTerm = 0;
    int currentTerm = 0;
    int vetPar[40];
    int vetImpar[40];
    int indexPar = 0;
    int indexImpar = 0;

    scanf("%d", &numTerm);  //efetuando a leitura da quantidade de termos a serem inseridos.

    for (int index = 0; index < numTerm; index++){
        
        scanf("%d", &currentTerm); //leitura do termo atual

        if (!(currentTerm % 2)){ //caso o termo seja par, será salvo no vetor que contém os num pares.
            vetPar [indexPar] = currentTerm;
            indexPar++;
        }
        else { //se não, será salvo no vetor dos num ímpares.
            vetImpar[indexImpar] = currentTerm;
            indexImpar++;
        }
    }

    //após a leitura dos termos, e tais termos estarem salvos em seus respectivos arrays, será feita a ordenação de tais vetores.

    margeSort(vetPar, indexPar);
    margeSort(vetImpar, indexImpar);

    //após a ordenação, será efetuado o print de todos os termos dos vetores.

    for (int i=0; i < indexPar; i++)
        printf("%d\n", vetPar[i]);

    for (int i = indexImpar; i >= 0; i--)
        printf("%d\n", vetImpar[i]);

    return 0;
}

void margeSort(int *array, int currentSize){

    if (current < 2) //verifica se o vetor ainda pode ser dividido.
        return;

    int mid = currentSize/2;

    //como o vetor original será dividido em dois, precisaremos criar dois novos vetores de inteiros.

    int left[mid]; //o primeiro vetor irá conter os termos do desde o termo 0 até o termo do meio, pelo qual o vetor foi dividido.
    int right[currentSize - mid]; //o segundo vetor irá conter os termos do desde o termo mid até o último termo.

    //agora passaremos o conteúdo do vetor original para os 2 novos vetores.
    for (int i = 0; i < mid; i++) {
        left[i] = array[i];
    }

    for (int i = mid; i < arrSize; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, currentSize - mid);
    merge(array, left, mid, right, currentSize - mid);
}

void merge(int *array, int *left, int leftsize, int *right, int rightsize){

    int i, j, k;
    i = 0; j = 0; k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] < right[j]) {
            array[k++] = left[i++];
        }
        else {
            array[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        array[k++] = left[i++];
    }

    while (j < rightSize) {
        array[k++] = right[j++];
    }

}