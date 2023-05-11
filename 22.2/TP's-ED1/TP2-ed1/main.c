#include <stdio.h>
#include "ponto.h"
#include <stdlib.h>
int main() {
    int qntObjetos, qntPontos;
    Ponto *pontos;
    
    lerQuantidade(&qntObjetos, &qntPontos);
    pontos = alocaPontos(qntObjetos, qntPontos);
    lerPontos(pontos, qntObjetos, qntPontos);
    calcularDistancia(pontos, qntObjetos, qntPontos);
    calcularDeslocamento(pontos, qntObjetos, qntPontos);
    mergeSort(pontos, 0, qntObjetos-1, qntPontos);
    imprime(pontos, qntObjetos);
    
    
    desalocaPontos(pontos, qntObjetos);
    
    
    

   // free(pontos);

    return 0;
}
