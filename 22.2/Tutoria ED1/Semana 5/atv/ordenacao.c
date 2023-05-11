#include "ordenacao.h"
#include <stdio.h>
#include <string.h>


void rebuildHeap(Aluno *alunos, int l, int r){

    int i = l;
    int aux = i * 2 + 1;

    Aluno vetAux = alunos[i];
    while(aux <= r){
        if ((aux < r)&&(!compare(alunos[aux], alunos[aux+1])))
            aux = aux + 1;
    
        if(compare(vetAux, alunos[aux]))
            break;
        
        alunos[i] = alunos[aux];
        i = aux;
        aux = i * 2 + 1;
    }

    alunos[i] = vetAux;
}

void buildHeap(Aluno *alunos, int n){
    int l = (n / 2) - 1;

    while (l >= 0){
        rebuildHeap(alunos, l, n - 1);
        l--;
    }
}

void heapSort(Aluno* alunos, int n){

    buildHeap(alunos, n);

    while(n > 1){
        Aluno aux = alunos[n-1];
        alunos[n-1] = alunos[0];
        alunos[0] = aux;
        n = n - 1;
        rebuildHeap(alunos, 0, n -1);
    }
}

int compare(Aluno vet1, Aluno vet2){

    if ((strcmp(vet1.cor, vet2.cor) < 0) || (((strcmp(vet1.cor, vet2.cor) == 0) && (vet1.tam > vet2.tam))) || ((strcmp(vet1.cor, vet2.cor) == 0) && ((vet1.tam == vet2.tam) && ((strcmp(vet1.nome, vet2.nome) < 0)))))
        return 0;
    
    return 1;
}