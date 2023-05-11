#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
int *alocaVetor(int *vetor, int n){
    vetor = (int*) malloc (n * sizeof(int));
    return vetor;
}

//Manter como especificado
int *desalocaVetor(int *vetor){
    free(vetor);
    return vetor;
}

void ordenacao(int *vetor, int n, int *movimentos){
    
    int current_moviment;
    int index;
    int aux=0;

    do{ 
        current_moviment=0;
        index = 0;
        
        while(index < n-1){
            if(vetor[index] > vetor[index+1]){
                aux = vetor[index+1];
                vetor[index+1] = vetor[index];
                vetor[index] = aux;
                current_moviment++;
            }
            index++;
        }
        *movimentos += current_moviment;
    }while(current_moviment !=0);
}
