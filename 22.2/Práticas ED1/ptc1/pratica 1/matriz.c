#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

void lerOrdem(int *ordem) {
    scanf("%d", ordem);
}

//manter como especificado
double **alocaMatriz(int ordem) {
    double **M = (double**) malloc(ordem*sizeof(double *));
    for (int i=0; i < ordem; i++){
        M[i]= (double*) malloc(ordem*sizeof(double));
    }
return M;
}

//manter como especificado
void desalocaMatriz(double ***M, int ordem) {
  for (int i = 0; i < ordem; i++)
       free((*M)[i]);    
  free(*M);
}

//manter como especificado
void lerOperacao(char *operacao) {
    scanf(" %c", operacao);
}

void lerMatriz(double **M, int ordem) {
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            scanf("%lf", &M[i][j]);
        }    
    }
}

double somaMatriz(double **M, int ordem) {
    int i=0;
    double soma=0;
  
    for(;i<(ordem/2);i++){
         for(int j=i+1; j<ordem-(i+1);j++){
            soma+=M[i][j];
         }  
    }
return soma;
}

double media(double resultado, int ordem) {
    int i=0, contador=0;
    for(;i<(ordem/2);i++){
         for(int j=i+1; j<ordem-(i+1);j++){
            contador++;
         }  
    }
return resultado/contador;
}

void printResultado(double resultado) {
    printf("%.1f\n", resultado);
}
