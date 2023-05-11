#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

/*struct upa{

};*/

int alocarUpa (TADupa **aux,int n){

    *aux = (TADupa*) malloc(n * sizeof(TADupa));

    if (aux == NULL)
        return 0;

    return 1;
}

void preencheVetor(TADupa *upas, int n){
    
    for(int index = 0; index < n; index++){
        scanf(" %[^ ]s", upas[index].nome);
        scanf("%d", &upas[index].Emergencia);
        scanf("%d", &upas[index].Urgencia);
        scanf("%d", &upas[index].semUrgencia);
        scanf("%d", &upas[index].Medicos);
    }
}

void ordenaUpas(TADupa *upas, int n){
    ordenacaoGeral(TADupa *upas, int n, int 1);
    ordenacaoGeral(TADupa *upas, int n, int 2);
    ordenacaoGeral(TADupa *upas, int n, int 3);
    ordenacaoGeral(TADupa *upas, int n, int 4);
}

void imprimeUpas(TADupa *upas, int n){
    for (int index = 0; index < n; index++){
        printf("%s ", upas[index].nome);
        printf("%d ", upas[index].Emergencia);
        printf("%d ", upas[index].Urgencia);
        printf("%d ", upas[index].semUrgencia);
        printf("%d\n", upas[index].Medicos);
    }
}

void desalocaUpas(TADupa **aux){
    free((*aux));
}

void ordenacaoGeral(TADupa *upas, int n, int modo){

    if (modo == 1){
        int h = 1;
        int j;

        for (h; h<n; h = (h*3)+1);

        do{
            h = (h-1) / 3;
            for (int i = h; i < n; i++){
                int Aux = upas[i].Emergencia;
                j = i;
                while (upas[j-h].Emergencia > Aux){
                    upas[j].Emergencia = upas[j-h].Emergencia;
                    j = j- h;
                    if (j<h)
                        break;
                }
                upas[j].Emergencia = Aux;
            }
        }while(h != 1);
    }
    else if (modo == 2){

    }
    else if (modo == 3){

    }
    else{

    }

}