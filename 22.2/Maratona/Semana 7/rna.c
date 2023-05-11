#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main() {

    char *line = (char*) malloc(35 * sizeof(char));
    char *auxline = (char*) malloc(35 * sizeof(char));

    while (scanf(" %s", line) != EOF){
        
        int conections = 0;
        bool moviment = true;
        int tamanho = strlen(line);
        int mid = tamanho / 2;

        while(conections <= mid && moviment){

            printf("valor do tamanho: %d\n", tamanho);
            int position = mid;
            moviment = false;

            printf("mid: %d\n", mid);
            printf("line na postion: %c\n", line[position]);

            if (line[position] == 'S'){
                if (line[position - 1] == 'B'){
                    line[position] = 'x';
                    line[position - 1] = 'x';
                    conections++;
                    moviment = true;
                }
                else if (line[position + 1] == 'B'){
                    line[position] = 'x';
                    line[position + 1] = 'x';
                    conections++;
                    moviment = true;
                }
            } else if (line[position] == 'B'){
                if (line[position - 1] == 'S'){
                    line[position] = 'x';
                    line[position - 1] = 'x';
                    conections++;
                    moviment = true;
                }
                else if (line[position + 1] == 'S'){
                    line[position] = 'x';
                    line[position + 1] = 'x';
                    conections++;
                    moviment = true;
                }
            } else if (line[position] == 'C'){
                if (line[position - 1] == 'F'){
                    line[position] = 'x';
                    line[position - 1] = 'x';
                    conections++;
                    moviment = true;
                }
                else if (line[position + 1] == 'F'){
                    line[position] = 'x';
                    line[position + 1] = 'x';
                    conections++;
                    moviment = true;
                }
            } else if (line[position] == 'F'){
                if (line[position - 1] == 'C'){
                    line[position] = 'x';
                    line[position - 1] = 'x';
                    conections++;
                    moviment = true;
                }
                else if (line[position + 1] == 'C'){
                    line[position] = 'x';
                    line[position + 1] = 'x';
                    conections++;
                    moviment = true;
                }
            }

            printf("line: %s\n", line);

            for (int index = 0; index < tamanho; index++){
                if (line[index] != 'x'){
                    auxline[index] = line[index];
                    printf("passando a linha no índice %d: %c\n", index, auxline[index]);
                }
            }

            printf("aux line: %s\n", auxline);
            strcpy(line, auxline);
            tamanho = strlen(line);
        }
     
        printf("%d\n", conections);
        printf("----------\n\n\n");
    }

    free(line);
    free(auxline);
    return 0;
}