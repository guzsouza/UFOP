#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void lerQuantidade(int *n, int *t) { 
    scanf("%d %d", n, t);
}

Ponto* alocaPontos(int n, int t) { 
    
    Ponto *pontos = malloc(sizeof(Ponto) * n);

    for(int i = 0; i < n; i++)
        pontos[i].coordenadas = malloc(sizeof(Coordenada) * t);

    return pontos;
}

void desalocaPontos(Ponto* pontos, int n) {
    for(int i = 0; i < n; i++)
        free(pontos[i].coordenadas);
        
    free(pontos);
}
void lerPontos(Ponto* pontos, int n, int t) {
    for(int i = 0; i < n; i++) {
        scanf("%s", pontos[i].nome);
        for(int j = 0; j < t; j++)
            scanf("%d %d", &pontos[i].coordenadas[j].x, &pontos[i].coordenadas[j].y);
        pontos[i].distancia = 0.0;
        pontos[i].deslocamento = 0.0;
    }
}

float distanciaEntrePontos(Coordenada i, Coordenada j) {
    return sqrt(pow((j.x - i.x), 2) + pow((j.y - i.y), 2));
}

void calcularDistancia(Ponto* pontos, int n, int t) {
    for(int i = 0; i < n; i++) {
        pontos[i].distancia = 0.0;
        for(int j = 1; j < t; j++)
            pontos[i].distancia += distanciaEntrePontos(pontos[i].coordenadas[j-1], pontos[i].coordenadas[j]);
    }
}

void calcularDeslocamento(Ponto* pontos, int n, int t) {
    for(int i = 0; i < n; i++)
        pontos[i].deslocamento = distanciaEntrePontos(pontos[i].coordenadas[t-1], pontos[i].coordenadas[0]);
}

void mergeSort(Ponto *pontos, int l, int r, int qntPontos){


    if(l<r){
        int m=(l+r)/2;
        mergeSort(pontos, l, m, qntPontos);
        mergeSort(pontos, m+1, r, qntPontos);
        merge(pontos, l, m, r, qntPontos);
    }
}

void merge(Ponto *pontos, int l, int m, int r, int qntPontos){
    int i = 0, j = 0;
    int size_l = (m-l+1);
    int size_r = (r - m);

    Ponto* pontos_l = alocaPontos(size_l, qntPontos);
    Ponto* pontos_r = alocaPontos(size_r, qntPontos);

    for(i=0; i< size_l; i++)
        pontos_l[i] = pontos[i+l];

    for(j=0; j< size_l; j++)
        pontos_r[j] = pontos[m+j+1];
    
    i = 0;
    j = 0;

    for(int k = l; k <= r; k++) {

        if (i == size_l)
            pontos[k] = pontos_r[j++];

        else if(j == size_r)
            pontos[k] = pontos_l[i++];

        else if((round(pontos_l[i].distancia * 100)/100) > (round(pontos_r[j].distancia * 100)/100))
            pontos[k] = pontos_l[i++];

        else if ((round(pontos_l[i].distancia * 100)/100) < (round(pontos_r[j].distancia * 100)/100))
            pontos[k] = pontos_r[j++];
        
        else{
            if ( (round(pontos_l[i].deslocamento * 100)/100) < (round(pontos_r[j].deslocamento * 100)/100) ){
                pontos[k] = pontos_l[i++];
            }
            else if ( (round(pontos_l[i].deslocamento * 100)/100) > (round(pontos_r[j].deslocamento * 100)/100) ){
                pontos[k] = pontos_r[j++];
            }
            else {
                if ((strcmp(pontos_l[i].nome, pontos_r[j].nome)) < 0)
                    pontos[k] = pontos_l[i++];
                else
                    pontos[k] = pontos_r[j++];
            }
        }
    }

    free(pontos_l);
    free(pontos_r);
}


void imprime(Ponto* pontos, int qntObjetos){
    for(int i = 0; i < qntObjetos; i++)
        printf("%s %.2lf %.2lf\n", pontos[i].nome, pontos[i].distancia, pontos[i].deslocamento);
}