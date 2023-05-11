#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 200

int main(void){

    char Line[MAX_TAM];

    while (1){

        int index = 0;
        int correto = 0;
        float sum = 0;
        scanf(" %[^\n]s", Line);
        int size = strlen(Line);

        if (Line[0] == '*')
            break;

        while (index < size){
            if(Line[index] == '/'){
                if (sum == 1)
                    correto++;
                
                sum=0;
            }
            else{
                if (Line[index] == 'W')
                    sum += 1;
                if (Line[index] == 'H')
                    sum += 1.0/2.0;
                if (Line[index] == 'Q')
                    sum += 1.0/4;
                if (Line[index] == 'E')
                    sum += 1.0/8;
                if (Line[index] == 'S')
                    sum += 1.0/16;
                if (Line[index] == 'T')
                    sum += 1.0/32;
                if (Line[index] == 'X')
                    sum += 1.0/64;
            }
            index ++;   
        }
        printf("%d\n", correto);
    } 
    return 0;
}