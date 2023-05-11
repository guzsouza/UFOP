#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void ordena(Aluno *alunos, int n) {
    int h = 1;
    int j;

	for (h; h<n; h = (h*3)+1);

    do{
        h = (h-1) / 3;
        for (int i = h; i < n; i++){
            char nameAux[21];
            strcpy(nameAux, alunos[i].nome);
            j = i;
            while (compare(alunos[j-h].nome, nameAux)>0){
                strcpy(alunos[j].nome, alunos[j-h].nome);
                j = j- h;
                if (j<h)
                    break;
            }
            strcpy(alunos[j].nome, nameAux);
        }
    }while(h != 1);
}

// Manter como especificado
int compare(const char* aluno1, const char* aluno2) {
    return strcmp(aluno1, aluno2);
}

/* Manter como especificado */
void imprimeResposta(Aluno* alunos, int n, int k) {
    if (k>n)
        return;
    printf("%s\n", alunos[n-k].nome);
}

/* Manter como especificado */
Aluno* alocaAlunos(int n) {
    Aluno *alunos = (Aluno *) malloc(n*sizeof(Aluno));
    return alunos;
}

/* Manter como especificado */
void liberaAlunos(Aluno** alunos) {
    free((*alunos));
}

/* Manter como especificado */
void leAlunos(Aluno* alunos, int n) {
    for(int index = 0; index < n; index++)
        scanf(" %[^\n]s", alunos[index].nome);
}

/* Manter como especificado */
void leQuantidades(int* n, int* k) {
    scanf("%d %d", n, k);
}

