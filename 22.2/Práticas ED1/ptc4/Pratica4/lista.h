# ifndef lista_h
# define lista_h

typedef struct {
    char nome[20]; //nome de cada usuário das listas, esse nome será extraído de alguma das linhas.
} TItem;

typedef struct celula {
    struct celula *Prox_Cel;
    TItem Item_Cel;
} TCelula;

typedef struct {
    TCelula *TL_Head, *TL_Last;
} TLista;

//Inicializa a lista
void TLista_Inicia(TLista *pLista);
//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista);
// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x);
// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista);
// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista);
// Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista);
// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2);
// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str);
# endif
