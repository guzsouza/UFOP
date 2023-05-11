#include "hash.h"
#include <stdbool.h>

#ifndef HASH_ABERTO
#define HASH_ABERTO

/* Os cabeçalhos de todas as funções e os TADs podem ser alterados */

#define VAZIO " !!!!!!!!!!!!!!!!!!!!\0 "

typedef struct{
    int CasaTabela;
    int CasaLista;
} Coordenada;

typedef struct {
    int n; // numero de documentos
    Chave chave;
    NomeDocumento documentos[ND];
} Item;


typedef struct cel {
    Item item;
    struct cel* prox;    
} Celula;

typedef struct {
    Celula* cabeca;
    Celula* ultimo;
    bool aponta;
    bool sofreuColisao;
} Lista;


typedef Lista IndiceInvertido[M];
    
/* Funções */

bool inicia(IndiceInvertido);
bool insereDocumento(IndiceInvertido, Chave, NomeDocumento);
int busca(IndiceInvertido, Chave, Coordenada*);
int consulta(IndiceInvertido, Chave*, int, NomeDocumento*);
void imprime(IndiceInvertido);
void sort(NomeDocumento*, int);
int contador(IndiceInvertido tabela);
bool ListaEhVazia(Lista* pLista);

#endif // !HASH_ABERTO
