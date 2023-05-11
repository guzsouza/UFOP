#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

int main(void){

    int NumLines = 0;
    char word[42];
    int stringSize = 0;

    scanf("%d", &NumLines);

    for (int index = 0; index < NumLines; index++){

        //leitura
        scanf(" %s", word);

        //calcula o tamanho da string
        stringSize = strlen(word) - 1;

        //caso a string tenha só uma letra, ela está em ordem, então a verificação não é efetuada.
        if ((stringSize) == 1){
            printf("%s", word);
            printf(": O\n");
        }
        else if (ordenacao(word, stringSize) > 0){
            printf("%s", word);
            printf(": N\n");
        }
        else printf("%s: O\n", word);
    }

    return 0;
}