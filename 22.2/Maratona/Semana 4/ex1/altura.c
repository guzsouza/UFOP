#include <stdio.h>
#include <stdlib.h>

int *alocaVet(int size);
void ordena(int *vetor, int size);

int main(void){
    int LinhaNum = 0;
    int TermLinha = 0;
    int* Vet;
    scanf("%d", &LinhaNum);

    for (int linhas = 0; linhas < LinhaNum; linhas++){

        scanf("%d", &TermLinha);
        Vet = alocaVet(TermLinha);

        for (int index_linha = 0; index_linha < TermLinha; index_linha++)
            scanf("%d", &Vet[index_linha]);
        
        ordena(Vet, TermLinha);

        for (int index_linha = 0; index_linha < TermLinha - 1; index_linha++)
            printf("%d ", Vet[index_linha]);

        printf("%d", Vet[TermLinha-1]);
        printf("\n");
        free(Vet);
    }

    return 0;
}

int *alocaVet(int size){
    int *vetor = (int*) malloc(size * sizeof(int));
    return vetor;
}

void ordena(int *vetor, int size){

    int h = 1;
    int j;

	for (h ; h < size; h = (h*3)+1);

    do{
        h = (h-1) / 3;
        for (int i = h; i < size; i++){
            int Aux;
            Aux = vetor[i]; 
            j = i;
            while (vetor[j-h] > Aux){
                vetor[j] = vetor[j-h];
                j = j - h;
                if (j<h)
                    break;
            }
            vetor[j] = Aux;
        }
    }while(h != 1);
}

