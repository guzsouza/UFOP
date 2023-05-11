#include "recursividade.h"

void TLista_FazVazia ( TLista * pLista ) {
    pLista->terms=0;
}

int TLista_Insere ( TLista * pLista , TItem x) {

    if((pLista->terms == MAXTAM))
        return 0;

    pLista->ListaVet[pLista->terms] = x;
    pLista->terms++;
    return 1;
}

int recursividade(TLista* pLista, int posicao){
    if (posicao==0){
        return pLista->ListaVet[0].num;
    }

    return pLista->ListaVet[posicao].num + recursividade(pLista, posicao-1);
}
