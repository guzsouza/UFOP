#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char name[21];
    int validity;
}Carnes;

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
        }else if(vL[i].validity < vR[j].validity){
            v[k] = vL[i++];
        }else{
            v[k] = vR[j++];
        }
    }
    free(vL); 
    free(vR);
}

void ordena(Carnes *v, int l, int r){
    if(l<r){
        int m = (l+r)/2;
        ordena(v, l, m);
        ordena(v, m+1, r);
        intercala(v, l, m, r);
    }
}

int main(){

    int n;

    Carnes *carnes = malloc(sizeof(Carnes) * 0);

    while(scanf("%d", &n) != EOF){

        carnes = realloc(carnes, sizeof(Carnes)*n);

        for(int i =0; i<n; i++){
            scanf("%s %d", carnes[i].name, &carnes[i].validity);
        }

        ordena(carnes, 0, n - 1);

        for(int i =0; i<n; i++){
            if (i != n-1)
                printf("%s ", carnes[i].name);
            else 
                printf("%s", carnes[i].name);
        }
        printf("\n");
    }

    free(carnes);
    return 0;
}

