#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Manter como especificado */
void inicia(No** ppRaiz) {
    *ppRaiz = (AVL) malloc(sizeof(AVL));
    (*ppRaiz)->pDir = NULL;
    (*ppRaiz)->pEsq = NULL;
    (*ppRaiz)->cont = 0;
    *ppRaiz = NULL;
}

/* Manter como especificado */
void libera(No** ppRaiz) {
    if((*ppRaiz)->pEsq == NULL)
        libera(&(*ppRaiz)->pEsq);
    if((*ppRaiz)->pDir == NULL)
        libera(&(*ppRaiz)->pDir);
    
    free((*ppRaiz));
}

/* Manter como especificado */
bool insere(No** ppRaiz, Item x) {

    if(*ppRaiz == NULL){
        *ppRaiz = criaNo(x);
        return true;
    }

    else if(compara((*ppRaiz)->item, x) == MAIOR){
        if(insere(&(*ppRaiz)->pEsq, x)){
            if(Balanceamento(ppRaiz))
                return false;
               
            else 
                return true;
               
        }
        else
            return false;
        
    }
    else if(compara((*ppRaiz)->item, x) == MENOR){
        if(insere(&(*ppRaiz)->pDir, x)){

            if(Balanceamento(ppRaiz))
                return false;
            
            else 
                return true;
            
        }
        else
            return false;
            
    }
    else{
        (*ppRaiz)->cont += 1;
        return false;
    }
}

/* Manter como especificado */
No *criaNo(Item x) {
    No* no = malloc(sizeof(No));
    no->cont = 1;
    no->item = x;
    no->pDir = NULL;
    no->pEsq = NULL;
    
    return no;
}

/* Manter como especificado */
void caminhamento(No *pNo) {
    if (pNo == NULL) return;
    caminhamento(pNo->pEsq);
    printf ("%s %d\n", pNo->item.chave, pNo->cont);
    caminhamento(pNo->pDir);
}

/* Manter como especificado */
RELACAO compara(const Item item1, const Item item2) {
    int response = strcmp(item1.chave, item2.chave);
    if (response < 0)
        return MENOR;
    else if (response > 0)
        return MAIOR;
    return IGUAL;
}

/* Manter como especificado */
int FB(No *pRaiz) {

    if (pRaiz == NULL)
        return 0;

    return altura(pRaiz->pEsq) - altura(pRaiz->pDir);
}

/* Manter como especificado */
int altura(No *pRaiz) {

    int left = 0;
    int right = 0;

    if (pRaiz != NULL){

        left = altura(pRaiz->pEsq);
        right = altura(pRaiz->pDir);

        if (left > right)
            return left + 1;
        
        else 
            return right + 1;
    }

    return 0;
}

/* Manter como especificado */
void RSE(No **ppRaiz) {

    No *NoAux;
    NoAux = (*ppRaiz)->pDir;

    (*ppRaiz)->pDir = NoAux->pEsq;
    NoAux->pEsq = (*ppRaiz);
    (*ppRaiz) = NoAux;
}

/* Manter como especificado */
void RSD(No **ppRaiz) {

    No *NoAux;
    NoAux = (*ppRaiz)->pEsq;

    (*ppRaiz)->pEsq = NoAux->pDir;
    NoAux->pDir = (*ppRaiz);
    (*ppRaiz) = NoAux;
}

/* Manter como especificado */
int BalancaEsquerda(No **ppRaiz) {
    int fbe = FB((*ppRaiz)->pEsq);
    if (fbe >= 0){
        RSD (ppRaiz);
        return 1;
    } else {
        RSE( &((*ppRaiz)->pEsq) );
        RSD(ppRaiz) ;
        return 1;
    }
    return 0;
}

/* Manter como especificado */
int BalancaDireita(No **ppRaiz) {
    int fbd = FB((*ppRaiz)->pDir);
    if (fbd <= 0){
        RSE (ppRaiz);
        return 1;
    } else {
        RSD( &((*ppRaiz)->pDir) );
        RSE(ppRaiz) ;
        return 1;
    }
    return 0;
}

/* Manter como especificado */
int Balanceamento(No **ppRaiz) {
    
    int fb = FB(*ppRaiz);

    if (fb > 1)
        return BalancaEsquerda(ppRaiz);
    else if (fb < -1)
        return BalancaDireita(ppRaiz);
    else
        return 0;
}
