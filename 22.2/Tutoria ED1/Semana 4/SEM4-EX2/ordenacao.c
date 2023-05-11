#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ordenacao.h"

int ordenacao(char *vetor, int size){
    
    char string[42];
    strcpy(string, vetor);
    int current_moviment = 0;
    int total_moviment = 0;
    int index = 0;
    char aux;

    do{ 
        current_moviment=0;
        index = 0;
        
        while(index < size-1){
            string[index] = tolower(string[index]);
            string[index+1] = tolower(string[index+1]);
            if(string[index] >= string[index+1]){
                aux = string[index+1];
                string[index+1] = string[index];
                string[index] = aux;
                current_moviment++;
                return 1;
            }
            index++;
        }

    }while(current_moviment != 0);

    return 0;
}
