#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[20];
    int price;
}Carne;

void ordena(Carne *vetor, int n);

int main(void){

    int NumLines = 0;

    while (scanf("%d", &NumLines) != EOF){

        //Alocação de memória dos dados a serem manipulados
        Carne *carnes = (Carne*) malloc(NumLines*sizeof(Carne));

        //Lê os dados de cada carne
        for (int index = 0; index < NumLines; index++)
            scanf(" %s %d", carnes[index].name, &carnes[index].price);

        ordena(carnes, NumLines);

        for (int index = 0; index < NumLines; index++)
            printf("%s ", carnes[index].name);

        printf("\n");

        free(carnes);
    }

    return 1;
}

void ordena(Carne *vetor, int n){

    int indexMenor = 0;
    int auxFor = 0;
    Carne aux;
    int ForMenor;

    for (int index = 0; index < n; index++){

        ForMenor = auxFor;
        Carne MenorAtual = vetor[ForMenor];
        indexMenor = ForMenor;
    
        for (ForMenor ; ForMenor < n; ForMenor++){
            if (MenorAtual.price > vetor[ForMenor].price){
                MenorAtual = vetor[ForMenor];
                indexMenor = ForMenor;
            }
        }

        auxFor++;

        if (indexMenor != index){
            aux = vetor[index];
            vetor[index] = MenorAtual;
            vetor[indexMenor] = aux;
            MenorAtual.price = 0;
        }
    }
}
