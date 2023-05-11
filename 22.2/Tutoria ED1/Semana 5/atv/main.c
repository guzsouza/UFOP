//IMPLEMENTE UTILIZANDO HEAPSORT
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ordenacao.h"

int main(void){
    int TermNum, verify = 0, x = 0;
    x = scanf("%d\n", &TermNum);
    while(x != EOF && TermNum){
        Aluno *alunos = (Aluno*) malloc(TermNum * sizeof(Aluno));

        if(verify>0){
            printf("\n");
        }
        
        for(int index = 0; index < TermNum; index++){
            fgets(alunos[index].nome, 65, stdin);
            int tam = strlen(alunos[index].nome);
            alunos[index].nome[tam - 1] = '\0';
            scanf("%s %c\n", alunos[index].cor,  &alunos[index].tam);
        }
        
        heapSort(alunos, TermNum);
        
        for(int i = 0; i < TermNum; i++)
            printf("%s %c %s\n", alunos[i].cor, alunos[i].tam, alunos[i].nome);
        
        free(alunos);
        verify = 1;
        x = scanf("%d\n", &TermNum);
    }
    return 0;
}