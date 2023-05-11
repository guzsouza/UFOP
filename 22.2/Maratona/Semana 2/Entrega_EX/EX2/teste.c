#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 32

typedef struct{
    char arvore[MAX_NOME];
    int tamstr;
    int qtdIguais;
}Arvore;


void trocaPosicao(Arvore* arvores, int * i, int * j){
    Arvore aux;

    aux = arvores[*i];
    arvores[*i] = arvores[*j];
    arvores[*j] = aux;
    *i += 1;
    *j -= 1;

}


void quicksort(Arvore * Arvores, int inicio, int fim){
    int i, j;
    Arvore pivo; 

    i = inicio;
    j = fim;
    pivo = Arvores[(inicio + fim) / 2];

    while (i <= j){
        while (strcmp(Arvores[i].arvore, pivo.arvore) < 0 && i < fim)
            i++;
        
        while (strcmp(Arvores[j].arvore, pivo.arvore) > 0 && j > inicio)
            j--;

        if (i <= j)
            trocaPosicao(Arvores, &i, &j);
    }

    if (j > inicio)
        quicksort(Arvores, inicio, j);

    if (i < fim)
        quicksort(Arvores, i, fim);
}

int main(){

    int n;
    int rep;
    scanf("%d", &n);
    
    
    getchar();
    getchar();
    

    for(int cont = 0; cont < n; cont++){
        
        Arvore * arvores = malloc(1000000 * sizeof(Arvore));
        int narvores = -1;
        char aux[MAX_NOME];

        
        do{
            aux[0] = '\0'; 
            fgets(aux, MAX_NOME, stdin);
            int tamstr = strlen(aux);

            if(aux[tamstr - 1] == '\n'){
                aux[tamstr - 1] = '\0';
                tamstr--;
            }

            narvores++;
            arvores[narvores].tamstr = tamstr;
            strcpy(arvores[narvores].arvore, aux);

        }while(aux[0] != '\0');

        
        quicksort(arvores, 0, narvores-1);

        for(int i = 0; i<narvores; i++){
            rep = 1;

            int j;
            for(j = i + 1; j<narvores && strcmp(arvores[i].arvore, arvores[j].arvore) == 0 ;j++)
                rep++;

            printf("%s %.4lf\n", arvores[i].arvore, ((double) rep/narvores) * 100.0000 );

            i = j-1;
        }
      
        if(cont != n-1)
            printf("\n");

        free(arvores);

    }
    
    return 0;
}