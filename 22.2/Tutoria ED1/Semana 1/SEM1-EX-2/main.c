#include "recursividade.h"
#include <string.h>

int main(){
    char Total_Str[MAXTAM];
    TItem termsum;
    int index=0;
    TLista* SUM_list = (TLista*) malloc (sizeof(TLista));
    scanf(" %[^\n]s", Total_Str);
    int String_Len = strlen(Total_Str); 

    while (index < String_Len){
        if (Total_Str[index] == 32 )
            Total_Str[index] = '_';
        index++;
    }
    char *token = strtok (Total_Str,"_");
    TLista_FazVazia(SUM_list);

    while ((token != NULL)) {

        termsum.num = atoi(token);
        if((TLista_Insere(SUM_list, termsum)==0))
            return 0;

        token = strtok(NULL, "_");
    }

    printf("%d\n",recursividade(SUM_list, SUM_list->terms));
    free(SUM_list);

    return 0;
}