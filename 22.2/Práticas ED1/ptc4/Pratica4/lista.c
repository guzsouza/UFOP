#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) {
    pLista->TL_Head= (TCelula*) malloc (sizeof(TCelula));
    pLista->TL_Last=NULL;
    pLista->TL_Head->Prox_Cel = NULL;
}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {
    if(pLista == NULL)
        return 1;
    if(pLista->TL_Head->Prox_Cel == NULL)
        return 1;
    return 0;
}

//Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {

    TCelula* Novo = (TCelula*) malloc (sizeof(TCelula));  //alocação de uma nova célula da lista.
    if(Novo==NULL)  //verificação se a alocação foi bem sucedida.
        return 0;

    Novo->Prox_Cel=NULL;

    if (TLista_EhVazia(pLista)){  //caso a lista for vazia, a última célula da lista também vai ser a primeira.
        pLista->TL_Last=Novo;
        pLista->TL_Head->Prox_Cel=Novo;
        strcpy(Novo->Item_Cel.nome,x.nome);
    } 
    else{
        pLista->TL_Last->Prox_Cel=Novo;
        pLista->TL_Last=Novo;
        strcpy(Novo->Item_Cel.nome,x.nome);
    }
    return 1;
}

//Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista) {
    if(TLista_EhVazia(pLista))
        return 0;

    TCelula* Del_Cel1 = pLista->TL_Head->Prox_Cel;
    pLista->TL_Head->Prox_Cel = pLista->TL_Head->Prox_Cel->Prox_Cel;

    free(Del_Cel1);
    return 1;
}

//Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {

    if(TLista_EhVazia(pLista))
        return;

    TCelula* Celula_Atual = pLista->TL_Head->Prox_Cel;

    while(Celula_Atual != NULL){ 
        printf("%s ", Celula_Atual->Item_Cel.nome);
        Celula_Atual = Celula_Atual->Prox_Cel;
    }    
    free(Celula_Atual);
}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {

    if(TLista_EhVazia(pLista)){
        free(pLista->TL_Head);
        free(pLista);
        return;
    }

    TCelula* Future_Cel = pLista->TL_Head->Prox_Cel;
    TCelula* Aux=Future_Cel;

    while(Future_Cel){ 
        Aux= Future_Cel->Prox_Cel;
        free(Future_Cel);
        Future_Cel=Aux;  
    }

    free(Future_Cel);
    free(pLista->TL_Head);
    free(pLista);
}

//Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2){

    if (TLista_EhVazia(pLista2))
        return;

    TCelula* Cel_Atual = pLista2->TL_Head->Prox_Cel;

    while(Cel_Atual != NULL){ 
        TLista_InsereFinal(pLista1, Cel_Atual->Item_Cel);
        Cel_Atual = Cel_Atual->Prox_Cel;
        TLista_RetiraPrimeiro(pLista2);
    }    
    TLista_Esvazia(pLista2);
}

//Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str){
    
    TLista* Lista_Aux = (TLista*) malloc (sizeof(TLista));
    if(Lista_Aux==NULL)
        return;
    TLista_Inicia(Lista_Aux);

    if (TLista_EhVazia(pLista2))
        return;
        
    //copia os nomes antes do str para uma lista auxiliar.
    TCelula* Cel_Atual = pLista1->TL_Head->Prox_Cel;

    while(Cel_Atual != NULL){ 
        if((strcmp(Cel_Atual->Item_Cel.nome,str)==0))
            break;
        TLista_InsereFinal(Lista_Aux, Cel_Atual->Item_Cel);
        Cel_Atual = Cel_Atual->Prox_Cel;
        TLista_RetiraPrimeiro(pLista1);
    }

    //copia os nomes da nova lista de amigos pra lista auxiliar.
    Cel_Atual=pLista2->TL_Head->Prox_Cel;
    while(Cel_Atual != NULL){ 
        TLista_InsereFinal(Lista_Aux, Cel_Atual->Item_Cel);
        Cel_Atual = Cel_Atual->Prox_Cel;
        TLista_RetiraPrimeiro(pLista2);
    }

    //após copiar os nomes da lista 1 antes do str, e também, todos os nomes da lista 2, agora vamos passar os nomes após o str.
    Cel_Atual = pLista1->TL_Head->Prox_Cel;
    while(Cel_Atual != NULL){ 
        TLista_InsereFinal(Lista_Aux, Cel_Atual->Item_Cel);
        Cel_Atual = Cel_Atual->Prox_Cel;
        TLista_RetiraPrimeiro(pLista1);
    }

    //passando dados da lista auxiliar, para a lista 1.
    Cel_Atual = Lista_Aux->TL_Head->Prox_Cel;
    while(Cel_Atual != NULL){ 
        TLista_InsereFinal(pLista1, Cel_Atual->Item_Cel);
        Cel_Atual = Cel_Atual->Prox_Cel;
        TLista_RetiraPrimeiro(Lista_Aux);
    }

    free(Cel_Atual);
    TLista_Esvazia(pLista2);
    TLista_Esvazia(Lista_Aux);
}
