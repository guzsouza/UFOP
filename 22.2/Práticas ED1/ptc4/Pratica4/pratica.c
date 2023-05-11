#include "lista.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//tamanho maximo de uma string
#define MAX_STR 1200
int main()
{
    TLista* original = (TLista*) malloc (sizeof(TLista));
    TLista* nova = (TLista*) malloc (sizeof(TLista));
    char str[MAX_STR], str2[MAX_STR], str3[20];
    char* token;
    int verify=0;
    TItem x;

    //iniciar listas
    TLista_Inicia(original);
    TLista_Inicia(nova);

    //le a primeira linha
    fgets (str, MAX_STR, stdin);
    //remove o \n incluido pelo fgets
    str[strcspn(str, "\n")] = 0;

    //tokenizacao da string original, divide em strings delimitadas por espaco em branco
    token = strtok(str, " ");
  
    while (token != NULL) {
      strcpy(x.nome, token);
      if(TLista_InsereFinal(original, x)==0){
        printf("\nAlocação mal sucedida!!\n");
        return 0;
      } 
      token = strtok(NULL, " ");
    }

    //le a segunda linha
    fgets (str2, MAX_STR, stdin);
    //remove o \n incluido pelo fgets
    str2[strcspn(str2, "\n")] = 0;

    //tokenizacao da string original, divide em strings delimitadas por espaco em branco
    token = strtok(str2, " ");

    while (token != NULL) {
      strcpy(x.nome, token);
      TLista_InsereFinal(nova, x);
      token = strtok(NULL, " ");
    }
    free(token);

    //Leitura da indicação, com scanf.
    scanf(" %s", str3);

    //dependendo se ha indicacao ou nao, manipular as listas de acordo
    TCelula* Cel_NOW = original->TL_Head->Prox_Cel;

    while(Cel_NOW->Prox_Cel != NULL){ 

        if((strcmp(str3, Cel_NOW->Item_Cel.nome))==0){
          TLista_include(original, nova, str3);
          verify++;
          break;
        }
        Cel_NOW = Cel_NOW->Prox_Cel;
    }    

    if(verify==0)
      TLista_append(original,nova);

    //impressão da lista final
    TLista_Imprime(original);

    //ao final as duas listas estarao unificadas, entao basta esvaziar a original
    TLista_Esvazia(original);
    return 0;//nao remova
}
