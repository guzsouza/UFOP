#include "lista.h"
#include <stdlib.h>

bool ListaInicia(Lista* pLista) {
    pLista->cabeca = (Celula*) malloc(sizeof(Celula));
    if (pLista->cabeca == NULL)
        return false;
    pLista->ultimo = pLista->cabeca;
    return true;
}

bool ListaEhVazia(Lista* pLista) {
    if(pLista == NULL)
        return true;
    if(pLista->cabeca == pLista->ultimo)
        return true;
    if(pLista->cabeca->prox == NULL)
        return true;
    return false;
}

bool ListaInsereFinal(Lista* pLista, Item item) {
    
    Celula* Novo = ( Celula*) malloc (sizeof( Celula));  //alocação de uma nova célula da lista.
    
    if(Novo==NULL)  //verificação se a alocação foi bem sucedida.
        return false;

    Novo->prox= NULL;

    if (ListaEhVazia(pLista)){  //caso a lista for vazia, a última célula da lista também vai ser a primeira.
        pLista->ultimo = Novo;
        pLista->cabeca->prox = Novo;
        Novo->item = item;
    } 
    else{
        pLista->ultimo->prox = Novo;
        pLista->ultimo = Novo;
        Novo->item = item;
    }
    return true;
}

bool ListaInsereInicio(Lista* pLista, Item item) {
    
    Celula* Novo = ( Celula*) malloc (sizeof( Celula));  //alocação de uma nova célula da lista.
    
    if(Novo == NULL)  //verificação se a alocação foi bem sucedida.
        return false;


    if (ListaEhVazia(pLista)){  //caso a lista for vazia, a última célula da lista também vai ser a primeira.
        Novo->prox= NULL;
        pLista->ultimo = Novo;
        pLista->cabeca->prox = Novo;
        Novo->item = item;
    } 
    else{
        Novo->prox = pLista->cabeca->prox;
        pLista->cabeca->prox = Novo;
        Novo->item = item;
    }
    return true;
}

bool ListaRetiraPrimeiro(Lista* pLista, Item* pItem) {
    
    if(ListaEhVazia(pLista))
        return false;

    Celula* Del_Cel1 = pLista->cabeca->prox;
    *pItem = Del_Cel1->item;
    pLista->cabeca->prox = Del_Cel1->prox;

    free(Del_Cel1);
    return true;
}

void ListaLibera(Lista* pLista) {
    
    if(ListaEhVazia(pLista)){
        free(pLista->cabeca);
        return;
    }

    Celula* Future_Cel = pLista->cabeca->prox;
    Celula* Aux=Future_Cel;

    while(Future_Cel){ 
        Aux= Future_Cel->prox;
        free(Future_Cel);
        Future_Cel = Aux;  
    }

    free(pLista->cabeca);
}