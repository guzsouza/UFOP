#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 11


typedef struct{
    char permutacoes[MAX_TAM];
}Palavras;

int fatorial(int n){
    if(n==0){
        return 1;
    }else{
        return n * fatorial(n-1);
    }
}

void troca_char(char leitura[], int p1, int p2){
  char aux;
  aux = leitura[p1]; 
  leitura[p1] = leitura[p2]; 
  leitura[p2] = aux;
}

void permutacaoRecursiva(Palavras *palavras, int *k, char leitura[], int n){
    int i, tamanho;
    tamanho = strlen(leitura);
    if (n==tamanho){
        strcpy(palavras[*k].permutacoes, leitura);
        (*k)++;
    }
    else{
        for(i= n; i< tamanho; i++){
            troca_char(leitura, n, i);
            permutacaoRecursiva(palavras, k, leitura, n + 1);
            troca_char(leitura, i, n);
        }
    }
}
Palavras *copy(Palavras *palavras, int tamanho, int n){
    Palavras *aux = malloc(sizeof(Palavras) * tamanho);
    for (int i = 0; i < tamanho; i++){ 
        aux[i] = palavras[i+n]; 
    }
    return aux;
}

void intercala(Palavras *palavras, int l, int m, int r){

    int tam_l = m - l + 1, tam_r = r - m, i = 0, j = 0, k;

    Palavras *vl = copy(palavras, tam_l, l);
    Palavras *vr = copy(palavras, tam_r, m+1);

    for(k=l; k <= r; k++){
        if(i==tam_l)
            palavras[k]=vr[j++];

        else if(j==tam_r)
            palavras[k]=vl[i++];

        else if(strcmp(vl[i].permutacoes, vr[j].permutacoes) < 0)
            palavras[k]=vl[i++];

        else
            palavras[k]=vr[j++];
        
    }
    free(vr);
    free(vl);
}

void ordena(Palavras *palavras, int l, int r){

    if(l<r){
        int m = (l+r)/2;
        ordena(palavras, l, m);
        ordena(palavras, m+1, r);
        intercala(palavras, l, m, r);
    }
}

int main(){

    int , k, qtdletras;
    char leitura[MAX_TAM];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){

        k = 0;
        scanf("%s", leitura);
        qtdletras = strlen(leitura);

        int qtdpermutacao = fatorial(qtdletras);

        Palavras * palavras = malloc(sizeof(Palavras)* qtdpermutacao);

        permutacaoRecursiva(palavras, &k, leitura, 0);
        ordena(palavras, 0, qtdpermutacao - 1);

        Palavras anterior = palavras[0];

        for (int i = 0; i < qtdpermutacao; i++){
            if(!strcmp(anterior.permutacoes, palavras[i].permutacoes)){
                continue;
            }else{
                printf("%s\n", anterior.permutacoes);
                anterior = palavras[i];
            }
        }
        printf("%s\n\n", anterior.permutacoes);
        free(palavras);
    }
}