#include <stdio.h>
#include "ordenacao.h"

int main(void){
    TADupa *vetUpa;
    int numTerm = 0;

    scanf("%d", &numTerm);

    if (!(alocarUpa(&vetUpa, numTerm)))
        return 0;

    preencheVetor(vetUpa, numTerm);
    ordenaUpas(vetUpa, numTerm);
    imprimeUpas(vetUpa, numTerm);
    desalocaUpas(&vetUpa);
}

