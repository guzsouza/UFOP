#include "duende.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { NAO=0, SIM } ESCALADO;

struct duende {
    char nome[20];
    int idade;
    ESCALADO escalado;
};

// Manter como especificado
void lerQuantidade(int *qtd) { 
    scanf("%d", qtd);
}

// Manter como especificado
Duende *alocaDuendes(int n) { 
    Duende *duendes = (Duende*) malloc (n*sizeof(Duende));
    return duendes;
}

// Manter como especificado
Duende *copiaDuende(Duende *duendes, int i) {
    Duende *novoduende= (Duende*) malloc(sizeof(Duende));
    *novoduende = duendes[i];
    return novoduende;
}

// Manter como especificado
void desalocaDuendes(Duende **duendes){
    free(*duendes);
}

// Manter como especificado
void lerDuendes(Duende *duendes, int n) {
    /* Lê os dados de n de Duendes */
    for (int i=0 ; i<n; i++){
        scanf(" %s", duendes[i].nome);
        scanf("%d", &duendes[i].idade);
        duendes[i].escalado=NAO;
    }
    /* PREENCHER AQUI */ 
}

// Manter como especificado
int proximoMaisVelho(Duende *duendes, int n) {
    /* Pega o próximo duende mais velho que ainda nao foi escalado */
    int index = 0;
    int oldest = 0;
    
    for (int i = 0; i < n; i++){
        if (duendes[i].escalado == NAO && oldest < duendes[i].idade){
            oldest = duendes[i].idade;
            index = i;
          }
    }
    return index;
    /* PREENCHER AQUI */ 
}

// Manter como especificado
void escalarDuende(Duende *duendes, int index) {
    /* Dado um vetor de duendes, "seta" como escalado um duende */
    duendes[index].escalado=SIM;
    /* PREENCHER AQUI */ 
}

// Manter como especificado
void printDuende(Duende *duende) {
    /* Imprime os dados de um duende e um \n no final */
    printf("%s ", duende->nome);
    printf("%d", duende->idade);
    printf("\n"); 
    /* PREENCHER AQUI */
}