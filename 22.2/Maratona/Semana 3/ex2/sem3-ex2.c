#include <stdio.h>
#include <stdlib.h>

int *alocaVetor(int *vetor, int n);
int *desalocaVetor(int *vetor);
void ordenacao(int *vetor, int n, int *movimentos);

int main ()
{

	int *vetor;
	int numIn = 0, movimentos;
    int numTerm = 0;

    scanf("%d", &numIn);
	
	while(numIn != 0)
	{	
		movimentos = 0;

        scanf("%d", &numTerm);

		//alocar o vetor
		vetor = alocaVetor(vetor, numTerm + 1);
		
		//preencher o vetor

		for (int i = 0; i < numTerm; i++)
        	scanf("%d", &vetor[i]);

		//ordenar o vetor e determinar o número de movimentos
		ordenacao(vetor, numTerm, &movimentos);

		//imprimir o resultado
		printf("Optimal train swapping takes %d swaps.\n", movimentos);

		//desalocar o vetor
		desalocaVetor(vetor);

        numIn--;
	}
	return 0;
}

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
    
    int current_moviment;
    int index;
    int aux=0;

    do{ 
        current_moviment=0;
        index = 0;
        
        while(index < n-1){
            if(vetor[index] > vetor[index+1]){
                aux = vetor[index+1];
                vetor[index+1] = vetor[index];
                vetor[index] = aux;
                current_moviment++;
            }
            index++;
        }
        *movimentos += current_moviment;
    }while(current_moviment !=0);
}