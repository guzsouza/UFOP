#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 1000

int main(void){

    int NumLines = 0;
    char Line [MAX_TAM];
    scanf("%d", &NumLines);

    for (int index1 = 0; index1 < NumLines; index1++){


        Line[0] = '\0';
        int diamante = 0;
        int chave_aberta = 0;
        int chave_fechada = 0;

        scanf(" %s", Line);
        int size = strlen(Line);

        printf("%d -", size);
        printf("%s\n", Line);

        if (size>1){
            for (int index = 0; index < size; index++){
                    
                if (Line[index] == '<')
                    chave_aberta++;
                else if (Line[index] == '>')
                    chave_fechada++; 
                } 

                if (chave_aberta == chave_fechada)
                    diamante = chave_aberta;

                else if (chave_aberta < chave_fechada)
                    diamante = chave_aberta;

                else if (chave_aberta > chave_fechada)
                    diamante = chave_fechada;
        }

        printf("%d\n", diamante);
    }
    return 0;
}