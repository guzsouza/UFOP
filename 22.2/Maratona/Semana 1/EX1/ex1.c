#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 10000
#define correct printf("correct\n");
#define incorrect printf("incorrect\n");

int main(){
    char Total_Str[MAX_TAM];
    int String_Len;
    int index = 0;
    int account_open = 0;
    int account_close = 0;
    int verify_incorrect =0;
    int Total_Index;

    while (((fgets(Total_Str, MAX_TAM, stdin)) != NULL) && (index < (MAX_TAM+1))){  

        //recebe a string por linha, logo após, calcula o tamanho da mesma.
        String_Len= (strlen(Total_Str));

        //nesse ponto do código é feita a verificação de caractere por caractere da string.
        if(Total_Str != NULL){
            account_close=0;
            account_open=0;
            verify_incorrect=0;
            index=0;
            while((index != String_Len)){

                if ((Total_Str[index] == 41) && (account_open==0)){
                    incorrect
                    verify_incorrect++;
                    break;
                }

                if (Total_Str[index] == 40){
                    account_open++;
                }                        
                
                if (Total_Str[index]== 41){
                    account_close++;
                } 

                if (account_close == account_open){
                    account_open = 0; 
                    account_close = 0;
                }     
                index++;
            }

            Total_Index+=index;

            if ((account_open != account_close) && (verify_incorrect < 1))
                incorrect
            if ((account_open == account_close) && (verify_incorrect < 1))
                correct  
        }
    }
}
