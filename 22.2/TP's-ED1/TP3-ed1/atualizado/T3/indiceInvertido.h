#include "hash.h"
#include <stdbool.h>

#ifndef HASH_ABERTO
#define HASH_ABERTO

/* Os cabeçalhos de todas as funções e os TADs podem ser alterados */

#define VAZIO " !!!!!!!!!!!!!!!!!!!!\0 "

typedef struct {
    int n; // numero de documentos
    Chave chave;
    NomeDocumento documentos[ND];
    bool sofreuColisao;
} Item;



typedef Item IndiceInvertido[M];
    
/* Funções */

void inicia(IndiceInvertido);
bool insereDocumento(IndiceInvertido, Chave, NomeDocumento);
int busca(IndiceInvertido, Chave);
int consulta(IndiceInvertido, Chave*, int, NomeDocumento*);
void imprime(IndiceInvertido);
void sort(NomeDocumento*, int);
int contador(IndiceInvertido tabela);

#endif // !HASH_ABERTO
