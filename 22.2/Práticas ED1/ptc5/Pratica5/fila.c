#include "fila.h"
#include "pilha.h"
#include <stdio.h>

bool FilaInicia(Fila* pFila) {
    return ListaInicia(pFila);
}

bool FilaEnfileira(Fila* pFila, Item item) {
    return ListaInsereFinal(pFila, item);
}

bool FilaDesinfeleira(Fila* pFila, Item* pItem) {
    return ListaRetiraPrimeiro(pFila, pItem);
}

bool FilaEhVazia(Fila* pFila) {
    return ListaEhVazia(pFila);
}

void FilaLibera(Fila* pFila) {
    ListaLibera(pFila);
}

bool FilaInverte(Fila* pFila) {

    Pilha pPilha;
    if(!PilhaInicia(&pPilha))
        return false;

    Item pItem;

    //desinfileirando a fila, ou seja, retirando todas as células e passando para pilha.
    while(!FilaEhVazia(pFila)){
        FilaDesinfeleira(pFila, &pItem);
        PilhaPush(&pPilha, pItem);
    }

    //esse while faz o pop da pilha e passa o item obtido pra a fila.
    while(!PilhaEhVazia(&pPilha)){
        PilhaPop(&pPilha, &pItem);
        FilaEnfileira(pFila, pItem);
    }

    PilhaLibera(&pPilha);

    return true;
}
