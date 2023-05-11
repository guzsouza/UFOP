#include <stdio.h>
#include <stdlib.h>


//Manter como especificado
int *alocaVetor(int *vetor, int n){
    vetor = (int*) malloc (n * sizeof(int));
    return vetor;
}

//Manter como especificado
int *desalocaVetor(int *vetor){
    free(vetor);
    return vetor;
}

void ordenacao(int *vetor, int n, int *movimentos){
    
    int indexMenor = 0;
    int auxFor = 0, aux = 0;
    int ForMenor;

    for (int index = 0; index < n; index++){
        ForMenor = auxFor;
        int MenorAtual = vetor[ForMenor];
        indexMenor = ForMenor;
    
        for (ForMenor ; ForMenor < n; ForMenor++){
            if (MenorAtual > vetor[ForMenor]){
                MenorAtual = vetor[ForMenor];
                indexMenor = ForMenor;
            }
        }
        auxFor++;
        if (indexMenor != index){
            aux = vetor[index];
            vetor[index] = MenorAtual;
            vetor[indexMenor] = aux;
            MenorAtual = 0;
            *movimentos += 1;
        }
    }
}

int main ()
{

	int *vetor;
	int movimentos;
    int Lines = 0;


    scanf("%d", &Lines);
	
    for (int index = 0; index < Lines; index++){
        
        int termLines = 0;
        scanf("%d", &termLines);
        movimentos = 0;

        //alocar o vetor
        vetor = alocaVetor(vetor, termLines);
            
        //preencher o vetor
        for (int i = 0; i < termLines; i++)
            scanf("%d", &vetor[i]);

        //ordenar o vetor e determinar o número de movimentos
        ordenacao(vetor, termLines, &movimentos);

        //imprimir o resultado
        printf("%d\n", movimentos);

        //desalocar o vetor
        desalocaVetor(vetor);
    }
	return 0;
}
