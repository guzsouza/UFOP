#include <stdio.h>
#include <string.h>
int main(void){
    int numTerm = 0;
    char strArray[30][30];
    int indexStr = 0;
    char buffer[30];
    int percent = 0;

    scanf("%d", &numTerm);

    for (int index = 0; index < numTerm; index++){
        while (scanf(" %[^\n]s", buffer) != EOF){
            if (buffer[0] == '\0') 
                break; // interrompe o loop quando uma linha em branco é lida

            else
                strcpy(strArray[indexStr], buffer);
                
            indexStr++;
        }

        percent = 100/indexStr;

        
    }

    return 1;
}