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
    
    TADupa maior;

    for(int verifyGO = 0; verifyGO < n - 1; verifyGO++){

        maior.Emergencia = -1;
        int coordenada = 0;

        for(int index = verifyGO; index < n; index++){
            
            if(upas[index].Emergencia > maior.Emergencia){
                maior = upas[index];
                coordenada = index;
            }
            else if (upas[index].Emergencia == maior.Emergencia){
                if (maior.Urgencia < upas[index].Urgencia){
                    maior = upas[index];
                    coordenada = index;
                }
                else if ((maior.Urgencia == upas[index].Urgencia) && (maior.semUrgencia < upas[index].semUrgencia)){
                    maior = upas[index];
                    coordenada = index;
                }
                else if ((maior.Urgencia == upas[index].Urgencia) && (maior.semUrgencia == upas[index].semUrgencia) && (maior.Medicos > upas[index].Medicos)){
                    maior = upas[index];
                    coordenada = index;
                }
                /*else if ((maior.Urgencia == upas[index].Urgencia) && (maior.semUrgencia == upas[index].semUrgencia) && (maior.Medicos == upas[index].Medicos)){
                    maior = upas[index];
                    coordenada = index;
                }*/
            }
        }

        //implementar parte que passa o valor do maior para o indice de inicio, ou seja, para o indice verifyGO.

        TADupa aux;
        aux = maior;
        upas[coordenada] = upas[verifyGO];
        upas[verifyGO] = aux;    
    } 
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
