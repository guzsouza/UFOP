#include "ordenacao.h"
#include <stdio.h>
#include <string.h>



void heap_constroi(Aluno *alunos, int n){
    int esq = (n / 2) - 1;
    while (esq >= 0)
    {
        heap_refaz(alunos, esq, n - 1);
        esq--;
    }
}

void heap_refaz(Aluno *alunos, int esq, int dir){
    int i = esq;
    int j = i * 2   + 1;
    Aluno aux = alunos[i];
    while(j <= dir)
    {
        if ((j < dir)&&(!compara(alunos[j], alunos[j+1])))
        {
            j = j + 1;
        }
        if(compara(aux, alunos[j]))
        {
            break;
        }
        alunos[i] = alunos[j];
        i = j;
        j = i * 2 + 1;
    }
    alunos[i] = aux;
}

void heap_sort(Aluno* alunos, int n){
    heap_constroi(alunos, n);
    while(n > 1)
    {
        Aluno aux = alunos[n-1];
        alunos[n-1] = alunos[0];
        alunos[0] = aux;
        n = n - 1;
        heap_refaz(alunos, 0, n -1);
    }
}

int compara(Aluno p1, Aluno p2){
    if((strcmp(p1.cor, p2.cor) < 0) || (((strcmp(p1.cor, p2.cor) == 0) && (p1.tam > p2.tam))) || ((strcmp(p1.cor, p2.cor) == 0) && ((p1.tam == p2.tam) && ((strcmp(p1.nome, p2.nome) < 0)))))
    {
        return 0;
    }
    return 1;
}