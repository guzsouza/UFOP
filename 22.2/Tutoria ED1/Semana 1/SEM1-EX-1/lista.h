#ifndef lista_h
#define lista_h
#define MAX_TAM 100000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char Letter;
} TItem ;

typedef struct celula {
    struct celula *Prox_Cel;
    TItem Item_Cel;
} TCelula ;

typedef struct {
    TCelula *TL_Head, *TL_Last;
} TLista ;

void TLista_Inicia ( TLista * pLista );
int TLista_EhVazia ( TLista * pLista );
int TLista_Insere_Fim ( TLista * pLista , char x);
int TLista_Insere_Inicio ( TLista * pLista , TLista* , char x);
void TLista_Imprime ( TLista * pLista );
void TLista_Esvazia (TLista * pLista);
int Read_Arq();
void TLista_Esvazia_Parcialmente(TLista* pLista);
void TLista_append(TLista *, TLista *);

#endif