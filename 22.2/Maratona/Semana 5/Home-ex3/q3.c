#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[21];
    int validade;
}Carnes;

void ordena(Carnes *, int, int);
void intercala(Carnes *, int, int, int);

int main(){
    int n;
    Carnes *carnes = malloc(sizeof(Carnes) * 0);
    while(scanf("%d", &n) != EOF){
        carnes = realloc(carnes, sizeof(Carnes)*n);
        for(int i =0; i<n; i++){
            scanf("%s %d", carnes[i].nome, &carnes[i].validade);
        }
        ordena(carnes, 0, n - 1);
        for(int i =0; i<n; i++){
            printf("%s ", carnes[i].nome);
        }printf("\n");
    }
    free(carnes);
    return 0;
}

void ordena(Carnes *v, int l, int r){
    if(l<r){
        int m = (l+r)/2;
        ordena(v, l, m);
        ordena(v, m+1, r);
        intercala(v, l, m, r);
    }
}

void intercala(Carnes *v, int l, int m, int r){
    int i, j, k;
    int size_l= m-l+1;
    int size_r= r-m;
    Carnes *vL = malloc(sizeof(Carnes) * size_l);
    Carnes *vR = malloc(sizeof(Carnes) * size_r);
    for(i=0; i<size_l; i++) vL[i] = v[i+l];
    for(i=0; i<size_r; i++) vR[i] = v[i+1+m];
    for(i = 0, j=0, k=l; k<=r; k++){
        if(i==size_l){
            v[k]=vR[j++];
        }else if(j==size_r){
            v[k]=vL[i++];
        }else if(vL[i].validade < vR[j].validade){
            v[k] = vL[i++];
        }else{
            v[k] = vR[j++];
        }
    }
    free(vL); 
    free(vR);
}
