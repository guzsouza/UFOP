#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int habilidade;
}SOLDIER;

void merge (SOLDIER *v, int l, int m, int r){
    int tamL = (m-l+1);
    int tamR = (r-m);

    SOLDIER *vetL = malloc(tamL * sizeof(SOLDIER));
    SOLDIER *vetR = malloc(tamR * sizeof(SOLDIER));
    int i, j;

    for ( i = 0; i < tamL; i++)
        vetL[i] = v[i + l];

    for(j = 0; j < tamR; j++)
        vetR[j] = v[m + j + 1];
    
    i = 0;
    j = 0;

    for (int k = l; k <= r; k++){
        if(i == tamL)
            v[k] = vetR[j++];

        else if(j == tamR)
            v[k] = vetL[i++];

        else if(vetL[i].habilidade > vetR[j].habilidade)
            v[k] = vetL[i++];

        else
            v[k] = vetR[j++];
    }
    
    free(vetL);
    free(vetR);
}

void mergeSort(SOLDIER *v, int l, int r){
    int m;
    
    if(l<r){
        m = (l+r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}
int main() {

    int s, i, j, battles = 0;
    scanf("%d", &s);
    SOLDIER *quad = (SOLDIER*) malloc (s * sizeof(SOLDIER));
    SOLDIER *nog = (SOLDIER*) malloc (s * sizeof(SOLDIER));;


    for (i = 0; i < s; i++) {
        scanf("%d ", &quad[i].habilidade);
    }

    for (i = 0; i < s; i++) {
        scanf("%d ", &nog[i].habilidade);
    }

    // Ordena as habilidades de combate dos soldados de cada exército em ordem decrescente
    mergeSort(nog, 0, s-1);
    mergeSort(quad, 0, s-1);

    // Compara a habilidade de combate dos soldados de cada exército
    int numVitorias = 0;
    int x = 0;
   
    for(int j = 0; j < s; j++){
        if(nog[x].habilidade > quad[j].habilidade){
            numVitorias++;
            x++;
        }
    }

    printf("%d\n", numVitorias);


    free(quad);
    free(nog);
    return 0;
}
