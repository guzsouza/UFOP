#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 32

typedef struct{
    char treeName[max];
    int tamstr;
    int qtdIguais;
} tree;

void switch_(tree* trees, int * i, int * j);
void quick(tree * trees, int inicio, int fim);

int main(void){

    int n;
    int rep;

    scanf("%d", &n);
    
    getchar();
    getchar();

    for(int cont = 0; cont < n; cont++){
        
        tree * trees = malloc(1000000 * sizeof(tree));
        int ntrees = -1;
        char aux[max];

        do{
            aux[0] = '\0'; 
            fgets(aux, max, stdin);
            int tamstr = strlen(aux);

            if(aux[tamstr - 1] == '\n'){
                aux[tamstr - 1] = '\0';
                tamstr--;
            }
            ntrees++;
            trees[ntrees].tamstr = tamstr;
            strcpy(trees[ntrees].treeName, aux);
        }while(aux[0] != '\0');

        quick(trees, 0, ntrees-1);

        for(int i = 0; i<ntrees; i++){
            rep = 1;

            int j;

            for(j = i + 1; j<ntrees && strcmp(trees[i].treeName, trees[j].treeName) == 0 ;j++)
                rep++;

            printf("%s %.4lf\n", trees[i].treeName, ((double) rep/ntrees) * 100.0000 );
            i = j-1;
        }
      
        if(cont != n-1)
            printf("\n");

        free(trees);

    }
    return 0;
}

void switch_(tree* trees, int * i, int * j){

    tree aux;

    aux = trees[*i];
    trees[*i] = trees[*j];
    trees[*j] = aux;
    
    *i += 1;
    *j -= 1;
}

void quick(tree * trees, int inicio, int fim){
    int i, j;
    tree pivo; 

    i = inicio;
    j = fim;
    pivo = trees[(inicio + fim) / 2];

    while (i <= j){
        while (strcmp(trees[i].treeName, pivo.treeName) < 0 && i < fim)
            i++;
        
        while (strcmp(trees[j].treeName, pivo.treeName) > 0 && j > inicio)
            j--;

        if (i <= j)
            switch_(trees, &i, &j);
    }

    if (j > inicio)
        quick(trees, inicio, j);

    if (i < fim)
        quick(trees, i, fim);
}
